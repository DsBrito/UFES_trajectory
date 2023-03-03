-- Listing 7.5 modificado para placa Nexys A7
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart_test is
   port(
      clk, reset: in std_logic;
      btn: std_logic_vector(0 downto 0);
      rx: in std_logic;
      tx: out std_logic;
      led: out std_logic_vector(7 downto 0);
      sseg: out std_logic_vector(7 downto 0);
      an: out std_logic_vector(7 downto 0)
   );
end uart_test;

architecture arch of uart_test is
   signal tx_full, rx_empty: std_logic;
   signal rec_data,rec_data1: std_logic_vector(7 downto 0);
   signal btn_tick: std_logic;
	--100MHz/(16*19.200)=325
   CONSTANT DVSR : std_logic_vector (10 downto 0)
	                := std_logic_vector(to_unsigned(324,11));
begin
    -- instantiate uart
   uart_unit: entity work.uart(str_arch)
      port map(clk=>clk, reset=>reset, rd_uart=>btn_tick,
               wr_uart=>btn_tick, dvsr=>DVSR, rx=>rx, w_data=>rec_data1,
               tx_full=>tx_full, rx_empty=>rx_empty,
               r_data=>rec_data, tx=>tx);
   -- instantiate debounce circuit
   btn_db_unit: entity work.debounce(fsmd_arch)
      port map(clk=>clk, reset=>reset, sw=>btn(0),
               db_level=>open, db_tick=>btn_tick);
   -- incremented data loop back
   rec_data1 <= std_logic_vector(unsigned(rec_data)+1);
   --  led display
   led <= rec_data;
   an <= "11111110";
   sseg <= '1' & (not tx_full) & "11" & (not rx_empty) & "111";
end arch;
