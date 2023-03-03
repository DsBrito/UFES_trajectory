library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity fifo is
   generic(
      ADDR_WIDTH : integer := 2;
      DATA_WIDTH : integer := 8
   );
   port(
      clk, reset : in  std_logic;
      rd, wr     : in  std_logic;
      w_data     : in  std_logic_vector(DATA_WIDTH - 1 downto 0);
      empty      : out std_logic;
      full       : out std_logic;
      r_data     : out std_logic_vector(DATA_WIDTH - 1 downto 0)
   );
end fifo;

architecture reg_file_arch of fifo is
   signal full_tmp : std_logic;
   signal wr_en    : std_logic;
   signal w_addr   : std_logic_vector(ADDR_WIDTH - 1 downto 0);
   signal r_addr   : std_logic_vector(ADDR_WIDTH - 1 downto 0);
begin
   -- write enabled only when FIFO is not full
   wr_en <= wr and (not full_tmp);
   full  <= full_tmp;
   -- instantiate fifo control unit
   ctrl_unit : entity work.fifo_ctrl(arch)
      generic map(ADDR_WIDTH => ADDR_WIDTH)
      port map(
         clk    => clk,
         reset  => reset,
         rd     => rd,
         wr     => wr,
         empty  => empty,
         full   => full_tmp,
         w_addr => w_addr,
         r_addr => r_addr);
   -- instantiate register file
   reg_file_unit : entity work.reg_file(arch)
      generic map(
         DATA_WIDTH => DATA_WIDTH,
         ADDR_WIDTH => ADDR_WIDTH)
      port map(
         clk    => clk,
         w_addr => w_addr,
         r_addr => r_addr,
         w_data => w_data,
         r_data => r_data,
         wr_en  => wr_en);
end reg_file_arch;

