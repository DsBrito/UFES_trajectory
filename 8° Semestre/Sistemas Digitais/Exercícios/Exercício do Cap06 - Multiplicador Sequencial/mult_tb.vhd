
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


use IEEE.NUMERIC_STD.ALL;


entity mult_tb is
end mult_tb;

architecture testbench_mult of mult_tb is
	constant T: time := 20 ns;
	signal clk, reset, start: std_logic;
	signal x_in, y_in: std_logic_vector(7 downto 0);
	signal result: std_logic_vector(15 downto 0);
	signal r, d: std_logic;
	
begin

mult_tb1: entity work.mult(arch_mult)
      port map(clk=>clk, reset=>reset, start=>start, x_in=>x_in,
               y_in=>y_in, result=>result, ready=>r, done=>d);
	
process
begin
	clk <= '0';
	wait for T/2;
	clk <= '1';
	wait for T/2;
end process;

reset <= '1', '0' after T/2;

process
begin
	start<= '0';
	x_in<=(others=>'0');
	y_in<=(others=>'0');

	wait until falling_edge(clk);
	wait until falling_edge(clk);
	
	x_in<="00001011";
	y_in<="00001101";
	
	start<='1';
	
	wait until falling_edge(clk);
	
	start<='0';
	--
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	
	wait until falling_edge(clk);
	wait until falling_edge(clk);

	x_in<="10101011";
	y_in<="11001101";
	
	start<='1';
	
	wait until falling_edge(clk);
	
	start<='0';
	--
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	-------------------------------
    -- 10001111 = 143
    -- 10001101 = 141
	x_in<="10001111";
	y_in<="10001101";
	-------------------------------
	--espera 20 e 163

	start<='1';
	
	wait until falling_edge(clk);
	
	start<='0';
	--
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	
	wait until falling_edge(clk);
	wait until falling_edge(clk);

	-------------------------------
    -- 11111111 = 255
	x_in<="11111111";
	y_in<="11111111";
	-------------------------------
	 --espera 65 e 025
	start<='1';
	
	wait until falling_edge(clk);
	
	start<='0';
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	wait until falling_edge(clk);
	
	wait until falling_edge(clk);
	wait until falling_edge(clk);


		assert false
         report "Simulation Completed"
   severity failure;
end process;
end testbench_mult;

