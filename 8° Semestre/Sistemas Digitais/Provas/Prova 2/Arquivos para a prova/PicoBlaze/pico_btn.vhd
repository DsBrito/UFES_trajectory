-- Listing 16.2
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity pico_btn is
   port(
      clk, reset: in std_logic;
      sw: in std_logic_vector(7 downto 0);
      btn: in std_logic_vector(1 downto 0);
      an: out std_logic_vector(3 downto 0);
      sseg: out std_logic_vector(7 downto 0)
   );
end pico_btn;

architecture arch of pico_btn is
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
   signal en_d: std_logic_vector(3 downto 0);
   -- four-digit seven-segment led display
   signal ds3_reg, ds2_reg: std_logic_vector(7 downto 0);
   signal ds1_reg, ds0_reg: std_logic_vector(7 downto 0);
   signal in3, in2: std_logic_vector(7 downto 0);
   signal in1, in0: std_logic_vector(7 downto 0);
   -- two push buttons
   signal btnc_flag_reg, btnc_flag_next: std_logic;
   signal btns_flag_reg, btns_flag_next: std_logic;
   signal set_btnc_flag, set_btns_flag: std_logic;
   signal clr_btn_flag: std_logic;
begin
   in3(7) <= ds3_reg(7);
   in3(6) <= ds3_reg(0);
   in3(5) <= ds3_reg(1);
   in3(4) <= ds3_reg(2);
   in3(3) <= ds3_reg(3);
   in3(2) <= ds3_reg(4);
   in3(1) <= ds3_reg(5);
   in3(0) <= ds3_reg(6);

   in2(7) <= ds2_reg(7);
   in2(6) <= ds2_reg(0);
   in2(5) <= ds2_reg(1);
   in2(4) <= ds2_reg(2);
   in2(3) <= ds2_reg(3);
   in2(2) <= ds2_reg(4);
   in2(1) <= ds2_reg(5);
   in2(0) <= ds2_reg(6);
   
   in1(7) <= ds1_reg(7);
   in1(6) <= ds1_reg(0);
   in1(5) <= ds1_reg(1);
   in1(4) <= ds1_reg(2);
   in1(3) <= ds1_reg(3);
   in1(2) <= ds1_reg(4);
   in1(1) <= ds1_reg(5);
   in1(0) <= ds1_reg(6);

   in0(7) <= ds0_reg(7);
   in0(6) <= ds0_reg(0);
   in0(5) <= ds0_reg(1);
   in0(4) <= ds0_reg(2);
   in0(3) <= ds0_reg(3);
   in0(2) <= ds0_reg(4);
   in0(1) <= ds0_reg(5);
   in0(0) <= ds0_reg(6);

   -- =====================================================
   --  I/O modules
   -- =====================================================
   disp_unit: entity work.disp_mux
      port map(
         clk=>clk, reset=>'0',
         in3=>in3, in2=>in2, in1=>in1,
         in0=>in0, an=>an, sseg=>sseg);
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
                          interrupt_ack => open,
                                  sleep => kcpsm6_sleep,
                                  reset => kcpsm6_reset,
                                    clk => clk);
            
        program_rom: entity work.btn_rom --Name to match your PSM file
                    generic map(     C_FAMILY => "7S", --Family 'S6', 'V6' or '7S'
                                    C_RAM_SIZE_KWORDS => 2,--Program size '1', '2' or '4'
                                 C_JTAG_LOADER_ENABLE => 1)--Include JTAG Loader when set to '1' 
                    port map(      address => address,      
                               instruction => instruction,
                                    enable => bram_enable,
                                       rdl => kcpsm6_reset,
                                       clk => clk);

   -- Unused inputs on processor
   kcpsm6_sleep <= '0';
   kcpsm6_reset <= '0';
   interrupt <= '0';
   -- =====================================================
   --  output interface
   -- =====================================================
   --    outport port id:
   --      0x00: ds0
   --      0x01: ds1
   --      0x02: ds2
   --      0x03: ds3
   -- =====================================================
   -- registers
   process (clk)
   begin
      if (clk'event and clk='1') then
         if en_d(0)='1' then ds0_reg <= out_port; end if;
         if en_d(1)='1' then ds1_reg <= out_port; end if;
         if en_d(2)='1' then ds2_reg <= out_port; end if;
         if en_d(3)='1' then ds3_reg <= out_port; end if;
      end if;
   end process;
  -- decoding circuit for enable signals
   process(port_id,write_strobe)
   begin
      en_d <= (others=>'0');
      if write_strobe='1' then
         case port_id(1 downto 0) is
            when "00" => en_d <="0001";
            when "01" => en_d <="0010";
            when "10" => en_d <="0100";
            when others => en_d <="1000";
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
end arch;
