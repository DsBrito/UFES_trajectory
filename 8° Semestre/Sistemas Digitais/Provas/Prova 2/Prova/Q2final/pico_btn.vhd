-- Listing 16.2
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity pico_btn is
   port(
      clk, reset: in std_logic;
      sw: in std_logic_vector(11 downto 0);
      btn: in std_logic_vector(1 downto 0);
      an: out std_logic_vector(3 downto 0);
      sseg: out std_logic_vector(7 downto 0);
      
      rgb: out std_logic_vector(11 downto 0);
      hsync, vsync: out std_logic
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
   signal en_d: std_logic_vector(10 downto 0);
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
   
  -- A e B em bcd
  signal a_bcd01, a_bcd2, b_bcd01, b_bcd2: std_logic_vector(7 downto 0);
   
  -- P = A*B em bcd
  signal p_bcd01, p_bcd23, p_bcd4: std_logic_vector(7 downto 0);
  
 -- multiplier
 signal m_src0_reg, m_src1_reg: std_logic_vector(15 downto 0);
 signal prod: std_logic_vector(23 downto 0);
begin
  
   --multiplier
    prod <= std_logic_vector(unsigned(m_src0_reg) * unsigned(m_src1_reg));
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
         
   vga_ctrl_unit: entity work.vga_ctrl
      port map(      		
         clk => clk, reset => reset, rgb => rgb, hsync => hsync, vsync => vsync,
         a_bcd2 => a_bcd2(3 downto 0), a_bcd1 => a_bcd01(7 downto 4), a_bcd0 => a_bcd01(3 downto 0),
         b_bcd2 => b_bcd2(3 downto 0), b_bcd1 => b_bcd01(7 downto 4), b_bcd0 => b_bcd01(3 downto 0),
         p_bcd4 => p_bcd4(3 downto 0), p_bcd3 => p_bcd23(7 downto 4), p_bcd2 => p_bcd23(3 downto 0), p_bcd1 => p_bcd01(7 downto 4), p_bcd0 => p_bcd01(3 downto 0));
         
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
         if en_d(0)='1' then a_bcd01 <= out_port; end if;
         if en_d(1)='1' then a_bcd2 <= out_port; end if;
         if en_d(2)='1' then b_bcd01 <= out_port; end if;
         if en_d(3)='1' then b_bcd2 <= out_port; end if;
         if en_d(4)='1' then p_bcd01 <= out_port; end if;
         if en_d(5)='1' then p_bcd23 <= out_port; end if;
         if en_d(6)='1' then p_bcd4 <= out_port; end if;
         if en_d(7)='1' then m_src0_reg(7 downto 0) <= out_port; end if;
         if en_d(8)='1' then m_src0_reg(15 downto 8) <= out_port; end if;
         if en_d(9)='1' then m_src1_reg(7 downto 0) <= out_port; end if;
         if en_d(10)='1' then m_src1_reg(15 downto 8) <= out_port; end if;
         
      end if;
   end process;
  -- decoding circuit for enable signals
   process(port_id,write_strobe)
   begin
      en_d <= (others=>'0');
      if write_strobe='1' then
         case port_id(4 downto 0) is
            when "0000" => en_d <="00000000001";
            when "0001" => en_d <="00000000010";
            when "0010" => en_d <="00000000100";
            when "0011" => en_d <="00000001000";
            when "0100" => en_d <="00000010000";
            when "0101" => en_d <="00000100000";
            when "0110" => en_d <="00001000000";
            when "0111" => en_d <="00010000000";

            when "1000" => en_d <="00100000000";
            when "1001" => en_d <="01000000000";
            when others => en_d <="10000000000";
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
   clr_btn_flag <='1' when read_strobe='1' and port_id(1 downto 0)="00" else '0';
   -- input multiplexing
   process(port_id,btns_flag_reg,btnc_flag_reg,sw)
   begin
      case port_id(2 downto 0) is
         when "000" =>
            in_port <= "000000" & btns_flag_reg & btnc_flag_reg;
         when "001" =>
            in_port <= sw(7 downto 0);
         when "010" =>
            in_port <= "0000" & sw(11 downto 7);
         when "011" =>
            in_port <= prod(7 downto 0);
         when "100" =>
            in_port <= prod(15 downto 8);
         when others =>
            in_port <= prod(23 downto 16);
      end case;
   end process;
end arch;
