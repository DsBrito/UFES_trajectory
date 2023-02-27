-- Listing 4.12
library ieee;
use ieee.std_logic_1164.all;

entity fsm_tb is
end fsm_tb;

architecture arch of fsm_tb is
   constant T: time := 20 ns; -- clk period
   signal clk, reset: std_logic;
	signal dig: std_logic_vector(1 downto 0);
	signal letter: std_logic_vector(7 downto 0);

begin
   --**************************
   -- instantiation
   --**************************
   fsm_unit: entity work.fsm_top(Behavioral)
      port map(clk=>clk, reset=>reset, 
               dig=>dig, 
					letter=>letter);
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
		wait on dig;
		wait on dig;
		wait on dig;
		wait on dig;
		wait on dig;
		wait on dig;
--      for i in 1 to 10 loop -- count 10 clocks
--         wait until falling_edge(clk);
--      end loop;
      --**************************
      -- terminate simulation
      --**************************
      assert false
         report "Simulation Completed"
       severity failure;
   end process ;
end arch;
