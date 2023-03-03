-- Listing 9.2 modificada
library ieee;
use ieee.std_logic_1164.all;
entity ps2_rxtx is
   port (
      clk, reset: in std_logic;
      wr_ps2: in std_logic;
      ps2_tx_data : in    std_logic_vector(7 downto 0);
      ps2_rx_data : out   std_logic_vector(7 downto 0);
      rx_done_tick: out  std_logic;
      tx_done_tick: out std_logic;
      ps2d, ps2c: inout std_logic
   );
end ps2_rxtx;

architecture arch of ps2_rxtx is
   signal tx_idle, rx_idle: std_logic;
begin
   ps2_tx_unit : entity work.ps2tx(arch)
      port map(
         clk          => clk,
         reset        => reset,
         wr_ps2       => wr_ps2,
         rx_idle      => rx_idle,
         din          => ps2_tx_data,
         ps2d         => ps2d,
         ps2c         => ps2c,
         tx_idle      => tx_idle,
         tx_done_tick => tx_done_tick
      );
   ps2_rx_unit : entity work.ps2rx(arch)
      port map(
         clk          => clk,
         reset        => reset,
         rx_en        => tx_idle,
         ps2d         => ps2d,
         ps2c         => ps2c,
         rx_idle      => rx_idle,
         rx_done_tick => rx_done_tick,
         dout         => ps2_rx_data
      );
end arch;