--baud rate = clock rate/16/(dvsr+1)
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart is
   generic(
      DBIT    : integer := 8;   -- # data bits
      SB_TICK : integer := 16;  -- # ticks for stop bits, 16 per bit
      FIFO_W  : integer := 4    -- # FIFO addr bits (depth: 2^FIFO_W)
   );
   port(
      clk, reset : in  std_logic;
      rd_uart    : in  std_logic;
      wr_uart    : in  std_logic;
      dvsr       : in  std_logic_vector(10 downto 0);
      rx         : in  std_logic;
      w_data     : in  std_logic_vector(7 downto 0);
      tx_full    : out std_logic;
      rx_empty   : out std_logic;
      r_data     : out std_logic_vector(7 downto 0);
      tx         : out std_logic
   );
end uart;

architecture str_arch of uart is
   signal tick              : std_logic;
   signal rx_done_tick      : std_logic;
   signal tx_fifo_out       : std_logic_vector(7 downto 0);
   signal rx_data_out       : std_logic_vector(7 downto 0);
   signal tx_empty          : std_logic;
   signal tx_fifo_not_empty : std_logic;
   signal tx_done_tick      : std_logic;
begin
   baud_gen_unit : entity work.baud_gen(arch)
      port map(
         clk  => clk, reset => reset, dvsr => dvsr,
         tick => tick
      );
   uart_rx_unit : entity work.uart_rx(arch)
      generic map(DBIT => DBIT, SB_TICK => SB_TICK)
      port map(
         clk          => clk,
         reset        => reset,
         rx           => rx,
         s_tick       => tick,
         rx_done_tick => rx_done_tick,
         dout         => rx_data_out
      );
   uart_tx_unit : entity work.uart_tx(arch)
      generic map(DBIT => DBIT, SB_TICK => SB_TICK)
      port map(
         clk          => clk,
         reset        => reset,
         tx_start     => tx_fifo_not_empty,
         s_tick       => tick,
         din          => tx_fifo_out,
         tx_done_tick => tx_done_tick,
         tx           => tx
      );
   fifo_rx_unit : entity work.fifo(reg_file_arch)
      generic map(DATA_WIDTH => DBIT, ADDR_WIDTH => FIFO_W)
      port map(
         clk    => clk,
         reset  => reset,
         rd     => rd_uart,
         wr     => rx_done_tick,
         w_data => rx_data_out,
         empty  => rx_empty,
         full   => open,
         r_data => r_data
      );
   fifo_tx_unit : entity work.fifo(reg_file_arch)
      generic map(DATA_WIDTH => DBIT, ADDR_WIDTH => FIFO_W)
      port map(
         clk    => clk,
         reset  => reset,
         rd     => tx_done_tick,
         wr     => wr_uart,
         w_data => w_data,
         empty  => tx_empty,
         full   => tx_full,
         r_data => tx_fifo_out
      );
   tx_fifo_not_empty <= not tx_empty;
end str_arch;