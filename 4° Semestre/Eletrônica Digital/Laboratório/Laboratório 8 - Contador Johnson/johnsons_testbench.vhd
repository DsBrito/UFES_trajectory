
--=====================================================================================
--> Dionatas
--=====================================================================================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity johnsons_testbench is
end johnsons_testbench;

architecture Behavioral of johnsons_testbench is
   constant T: time := 20 ns; --------------------------------->Periodo do Clk
   signal clk, reset: STD_LOGIC;
	signal enable: STD_LOGIC;
	signal count: STD_LOGIC_VECTOR(7 downto 0);

begin
	----------------------------------------------------------------------------
   --> instantiation
   ----------------------------------------------------------------------------
   johnsons_unit: entity work.johnsons_counter_8bits(Behavioral)
      port map(clk=>clk, 
					reset=>reset, 
               enable=>enable, 
					count=>count);
   -----------------------------------------------------------------------------
   --> clock SLIDE 6
   -----------------------------------------------------------------------------
   -- 20 ns clock running forever
   process
   begin
      clk <= '0';
      wait for T/2;
      clk <= '1';
      wait for T/2;
   end process;
   ------------------------------------------------------------------------------
   --> reset SLIDE 6
   ------------------------------------------------------------------------------
   -- reset asserted for T/2
   reset <= '1', '0' after T/2;

   
   process
   begin
	------------------------------------------------------------------------------
   --> SLIDE 8
   ------------------------------------------------------------------------------
		-- valor inicial com contagem desabilitada
		enable <= '0';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		--habilidata contagem
		enable <= '1';
		wait until falling_edge(clk);
		
	------------------------------------------------------------------------------
   --> SLIDE 9
   ------------------------------------------------------------------------------
		--pause 2 clocks
		wait until falling_edge(clk);
		--escolha o valor de i para permitir a
		--contagem circular por todos os valores
		for i in 1 to 15 loop --count 10 clocks
			wait until falling_edge(clk);
		end loop;
	-------------------------------------------------------------------------------
   --> terminate simulation SLIDE 10
   -------------------------------------------------------------------------------
      assert false
         report "Simulation Completed"
       severity failure;
		end process;

end Behavioral;