-- Listing 4.12
library ieee;
use ieee.std_logic_1164.all;

entity garage_door_tb is
end garage_door_tb;

architecture arch of garage_door_tb is
   constant T: time := 20 ns; -- clk period
   signal clk, reset: std_logic;
	signal SE, SI, IV, L,A,F, tick: std_logic;
begin
   --**************************
   -- instantiation
   --**************************
   garage_top_unit: entity work.garage_top(Behavioral)
      port map(clk=> clk, 
		         reset=> reset, 
               SI => SI,
					SE => SE,
					IV => IV,
					A => A,
					F => F,
					tick=> tick,
					L => L
					);  
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
	--inicialização
		SI <= '0';
		SE <= '0';
		IV <= '0';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		-- tem carro querendo sair
		SI <= '1';
	   --manda abrir o portão fazendo IV = '1' por um ciclo de clock
		IV <= '1';
		wait until falling_edge(clk);
		IV <= '0';
		-- espera até o portão estar aberto, quando A = '1'
		wait until A='1';
		-- espera o tempo regulamentar quando tick = '1' 
		wait until tick = '1';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		-- carro sai da frente do sensor
		SI<='0';
		SE <= '0';
		-- espera até o portão estar fechado quando F = '1'
		wait until F = '1';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		--manda abrir o portão fazendo IV = '1' por um ciclo de clock
		IV <= '1';
		wait until falling_edge(clk);
		IV <= '0';
		-- espera até o portão estar aberto, quando A = '1'
		wait until A='1';
		-- espera o tempo regulamentar quando tick = '1' 
		wait until tick = '1';
		-- portão começa a fechar
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		--Aparece carro na frente do sensor e o portão reabre
		SI <= '1';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		-- carro sai
		SI <= '0';
		-- espera até o portão estar fechado quando F = '1'
		wait until F = '1';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
      --**************************
      -- terminate simulation
      --**************************
      assert false
         report "Simulation Completed"
       severity failure;
   end process ;
end arch;
