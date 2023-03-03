-- Listing 15.3
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity pico_sio is
   port(
      clk, reset: in std_logic;
      sw: in std_logic_vector(7 downto 0);
      led: out std_logic_vector(7 downto 0)
   );
end pico_sio;

architecture arch of pico_sio is
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
--   Signal kcpsm6_sleep : std_logic;
   Signal kcpsm6_reset : std_logic;
   -- register signals
   signal led_reg: std_logic_vector(7 downto 0);
begin
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
                          port_id => open,
                     write_strobe => write_strobe,
                   k_write_strobe => k_write_strobe,
                         out_port => out_port,
                      read_strobe => open,
                          in_port => in_port,
                        interrupt => '0',
                    interrupt_ack => open,
                            sleep => '0',
                            reset => kcpsm6_reset,
                              clk => clk);
      
  program_rom: entity work.sio_rom --Name to match your PSM file
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
   --output register
   process (clk)
   begin
      if (clk'event and clk='1') then
         if write_strobe='1' then
            led_reg <= out_port;
         end if;
      end if;
   end process;
   led <= led_reg;
   -- =====================================================
   --  input interface
   -- =====================================================
   in_port <= sw;
end arch;