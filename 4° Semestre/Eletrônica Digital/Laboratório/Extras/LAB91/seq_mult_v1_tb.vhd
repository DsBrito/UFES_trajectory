library ieee;
use ieee.std_logic_1164.all;

entity mult_seq_tb is
end mult_seq_tb;

architecture arch of mult_seq_tb is
   constant T: time := 20 ns; -- clk period
	constant N: natural := 8;
   signal clk, reset: std_logic;
   signal  start : std_logic;
	signal  a_in :   STD_LOGIC_VECTOR (N-1 downto 0);
   signal  b_in :  STD_LOGIC_VECTOR (N-1 downto 0);
   signal r :  STD_LOGIC_VECTOR (2*N-1 downto 0);
   signal ready : STD_LOGIC;
begin
   --**************************
   -- instantiation
   --**************************
   mult_unit: entity work.seq_mult(shift_add_arch)
      port map(clk=>clk, reset=>reset, start=>start, 
		a_in=>a_in, b_in=>b_in, r=>r,ready=>ready);

   --**************************
   -- clock
   --**************************
   -- 20 ns clock running forever
   process
   begin
      clk <= '0';
      wait for T/2;
      clk <= '1';
      wait for T/2;
   end process;
   --**************************
   -- reset
   --**************************
   -- reset asserted for T/2
   reset <= '1', '0' after T/2;

   --**************************
   -- other stimulus
   --**************************
   process
   begin
      --**************************
      -- initial input
      --**************************
      start <= '0';
		a_in <= "00000101";--5
		b_in <= "00000011";--3
		wait until falling_edge(clk);
      wait until falling_edge(clk);
      --**************************
      -- test load
      --**************************
      start <= '1';
      wait until falling_edge(clk);
      wait until falling_edge(clk);
		start <= '0';
		wait on ready;
      wait until falling_edge(clk);
      wait until falling_edge(clk);		
      assert false
         report "Simulation Completed"
       severity failure;
   end process ;
end arch;

