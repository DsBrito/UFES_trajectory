-- Listing 17.2
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity pico_int is
   port(
      clk, reset: in std_logic;
      sw: in std_logic_vector(7 downto 0);
      btn: in std_logic_vector(1 downto 0);
      an: out std_logic_vector(3 downto 0);
      sseg: out std_logic_vector(7 downto 0)
   );
end pico_int;

architecture arch of pico_int is
   -- KCPSM6/ROM signals
 signal address : std_logic_vector(11 downto 0);
 signal instruction : std_logic_vector(17 downto 0);
 signal bram_enable : std_logic;
 signal in_port : std_logic_vector(7 downto 0);
 signal out_port : std_logic_vector(7 downto 0);
 Signal port_id : std_logic_vector(7 downto 0);
 Signal write_strobe : std_logic;
 Signal k_write_strobe : std_logic;
 Signal read_strobe : std_logic;
 Signal interrupt : std_logic;
 Signal interrupt_ack : std_logic;
 Signal kcpsm6_sleep : std_logic;
 Signal kcpsm6_reset : std_logic;
   -- I/O port signals
   -- output enable
   signal en_d: std_logic_vector(1 downto 0);
   -- four-digit seven-segment led display
   signal sseg_reg: std_logic_vector(7 downto 0);
   signal an_reg: std_logic_vector(3 downto 0);
   -- two push buttons
   signal btnc_flag_reg, btnc_flag_next: std_logic;
   signal btns_flag_reg, btns_flag_next: std_logic;
   signal set_btnc_flag, set_btns_flag: std_logic;
   signal clr_btn_flag: std_logic;
   -- interrupt related signals
   signal timer_reg, timer_next: unsigned(9 downto 0);
   signal ten_us_tick: std_logic;
   signal timer_flag_reg, timer_flag_next: std_logic;
begin
kcpsm6_sleep <= '0';
kcpsm6_reset <= '0';
   -- =====================================================
   --  I/O modules
   -- =====================================================
   btnc_db_unit: entity work.debounce
      port map(
         clk=>clk, reset=>reset, sw=>btn(0),
         db_level=>open, db_tick=>set_btnc_flag);
   btns_db_unit: entity work.debounce
      port map(
         clk=>clk, reset=>reset, sw=>btn(1),
         db_level=>open, db_tick=>set_btns_flag);
   -- =====================================================
               --  KCPSM and ROM instantiation
               -- =====================================================
                 processor: entity work.kcpsm6
                       generic map (     hwbuild => X"00", 
                                         interrupt_vector => X"3FF",
                                     scratch_pad_memory_size => 64)
                       port map(      address => address,
                                  instruction => instruction,
                                  bram_enable => bram_enable,
                                      port_id => port_id,
                                 write_strobe => write_strobe,
                               k_write_strobe => k_write_strobe,
                                     out_port => out_port,
                                  read_strobe => read_strobe,
                                      in_port => in_port,
                                    interrupt => interrupt,
                                interrupt_ack => interrupt_ack,
                                        sleep => kcpsm6_sleep,
                                        reset => kcpsm6_reset,
                                          clk => clk);
                  
              program_rom: entity work.int_rom --Name to match your PSM file
                          generic map(     C_FAMILY => "7S", --Family 'S6', 'V6' or '7S'
                                          C_RAM_SIZE_KWORDS => 2,--Program size '1', '2' or '4'
                                       C_JTAG_LOADER_ENABLE => 1)--Include JTAG Loader when set to '1' 
                          port map(      address => address,      
                                     instruction => instruction,
                                          enable => bram_enable,
                                             rdl => kcpsm6_reset,
                                             clk => clk);
   -- =====================================================
   --  output interface
   -- =====================================================
   --    outport port id:
   --      0x00: an
   --      0x01: ssg
   -- =====================================================
   -- registers
   process (clk)
   begin
      if (clk'event and clk='1') then
         if en_d(0)='1' then
            an_reg <= out_port(3 downto 0);
         end if;
         if en_d(1)='1' then sseg_reg <= out_port; end if;
      end if;
   end process;
   an <= an_reg;
   --sseg <= sseg_reg;
   sseg(7) <= sseg_reg(7);
   sseg(6) <= sseg_reg(0);
   sseg(5) <= sseg_reg(1);
   sseg(4) <= sseg_reg(2);
   sseg(3) <= sseg_reg(3);
   sseg(2) <= sseg_reg(4);
   sseg(1) <= sseg_reg(5);
   sseg(0) <= sseg_reg(6);
   
   -- decoding circuit for enable signals
   process(port_id,write_strobe)
   begin
      en_d <= (others=>'0');
      if write_strobe='1' then
         case port_id(0) is
            when '0' => en_d <="01";
            when others => en_d <="10";
         end case;
      end if;
   end process;
   -- =====================================================
   --  input interface
   -- =====================================================
   --    input port id
   --      0x00: flag
   --      0x01: switch
   -- =====================================================
   -- input register (for flags)
   process(clk)
   begin
      if (clk'event and clk='1') then
         btnc_flag_reg <= btnc_flag_next;
         btns_flag_reg <= btns_flag_next;
      end if;
   end process;

   btnc_flag_next <= '1' when set_btnc_flag='1' else
                     '0' when clr_btn_flag='1' else
                      btnc_flag_reg;
   btns_flag_next <= '1' when set_btns_flag='1' else
                     '0' when clr_btn_flag='1' else
                      btns_flag_reg;
   -- decoding circuit for clear signals
   clr_btn_flag <='1' when read_strobe='1' and
                           port_id(0)='0' else
                  '0';
   -- input multiplexing
   process(port_id,btns_flag_reg,btnc_flag_reg,sw)
   begin
      case port_id(0) is
         when '0' =>
            in_port <= "000000" &
                       btns_flag_reg & btnc_flag_reg;
         when others =>
            in_port <= sw;
      end case;
   end process;
   -- =====================================================
   --  interrupt interface
   -- =====================================================
   -- 10 us counter
   process(clk)
   begin
      if (clk'event and clk='1') then
         timer_reg <= timer_next;
      end if;
   end process;
   timer_next <= (others=>'0') when timer_reg=999 else
                 timer_reg+1;
   ten_us_tick <= '1' when timer_reg=999 else '0';
   -- 10 us tick flag
   process(clk)
   begin
      if (clk'event and clk='1') then
         timer_flag_reg <= timer_flag_next;
      end if;
   end process;
   timer_flag_next <= '1' when ten_us_tick='1' else
                      '0' when interrupt_ack='1' else
                      timer_flag_reg;
   -- interrupt request
   interrupt <= timer_flag_reg;
end arch;