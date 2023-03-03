
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bin_counter_tb is
end bin_counter_tb;

architecture arch of bin_counter_tb is
   constant T: time := 20 ns; -- periodo  do clock
   signal clk, reset: std_logic;
   signal inc1, inc2, dec1, dec2: std_logic;
   signal d2, d1, d0: std_logic_vector(3 downto 0);

begin
----------------------------------------------------
   -- instancição
----------------------------------------------------

   counter_unit: entity work.stop_watch(if_arch)
      port map(clk=>clk, reset=>reset, inc1=>inc1,
               inc2=>inc2, dec1=>dec1, dec2=>dec2,
					d2=>d2, d1=>d1, d0=>d0);
					
----------------------------------------------------
   -- clock
----------------------------------------------------
   -- 20 ns de clock (sem parar)
   process
   begin
      clk <= '0';
      wait for T/2;
      clk <= '1';
      wait for T/2;
   end process;
----------------------------------------------------
   -- reset
----------------------------------------------------
   -- reset aceito para T/2
   reset <= '1', '0' after T/2;

----------------------------------------------------
   -- outras incitações
----------------------------------------------------
   process
   begin
----------------------------------------------------
      --  input inicial 
----------------------------------------------------
      inc1 <= '0';
      inc2 <= '0';
      dec1 <= '0';
      dec2 <= '0';  -- conta UP
      
      wait until falling_edge(clk);
      wait until falling_edge(clk);
----------------------------------------------------
      -- testa carregamento 
----------------------------------------------------
      inc1 <= '1';
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
      wait until falling_edge(clk);
      wait until falling_edge(clk);
----------------------------------------------------
--conta até 12
		
      inc1 <= '0';  -- limpa
		
		wait until falling_edge(clk);
      wait until falling_edge(clk);
		wait until falling_edge(clk);
      wait until falling_edge(clk);

----------------------------------------------------
--testando inc2
		
		inc2 <= '1';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);

----------------------------------------------------
--incrimenta 	até 20 	
		inc2 <= '0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);

----------------------------------------------------
--testanto inc 1 e inc 2 juntos 		
		inc1 <= '1';
		inc2 <= '1';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
		inc1 <= '0';
		inc2 <= '0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
----------------------------------------------------
--espera 24      
		dec1<='1';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
----------------------------------------------------
--espera 21		
		dec1<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
		dec1<='1';
		dec2<='1';
		
----------------------------------------------------
--espera 19		
		wait until falling_edge(clk);
		
		dec1<='0';
		dec2<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);

		dec1<='1';
		dec2<='1';
		
      for i in 1 to 9 loop -- run 10 clocks
         wait until falling_edge(clk);
      end loop;
		
		wait until falling_edge(clk);
		dec1<='0';
		dec2<='0';
		wait until falling_edge(clk);
		wait until falling_edge(clk);

		
----------------------------------------------------
--espera 0 999		
		
		inc2<='1';
		
		wait until falling_edge(clk);
		
		inc2<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);

----------------------------------------------------
--espera 0 000		--
		
		inc1<='1';
		inc2<='1';
----------------------------------------------------
--50 ciclos de clock
--ambos incrementadores habilitados espera 		100		
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
		
		inc1<='0';
		inc2<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
		inc1<='1';
		
----------------------------------------------------
--espera 101		
		wait until falling_edge(clk);
		
		inc1<='0';
		dec2<='1';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
----------------------------------------------------
--espera 099		
		dec2<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		
		inc1<='1';
		dec2<='1';
		
		wait until falling_edge(clk);
		
----------------------------------------------------
--espera 0 999		
		inc1<='0';
		dec2<='0';
		
		wait until falling_edge(clk);
		wait until falling_edge(clk);
			
		assert false
         report "Simulation Completed"
       severity failure;
   end process ;
end arch;
