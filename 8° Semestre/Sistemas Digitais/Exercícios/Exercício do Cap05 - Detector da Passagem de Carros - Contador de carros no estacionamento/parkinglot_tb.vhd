
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity parkinglot_tb is
end parkinglot_tb;

architecture arch of parkinglot_tb is
   constant T: time := 20 ns; -- clk period
   signal clk, reset: std_logic;
	signal sw: std_logic_vector(3 downto 0);
   signal an: std_logic_vector(3 downto 0);
	signal sseg: std_logic_vector(7 downto 0);
	signal car_in1, car_out1, car_in2, car_out2: std_logic;
   signal d2, d1, d0: std_logic_vector(3 downto 0);

begin
---------------------------------------------------
   -- instanciação
---------------------------------------------------	--
	car_detect1: entity work.car_detect(arch)
      port map(clk=>clk, reset=>reset, a=>sw(3), b=>sw(2),
               car_in=>car_in1, car_out=>car_out1);
	
	car_detect2: entity work.car_detect(arch)
      port map(clk=>clk, reset=>reset,a=>sw(1), b=>sw(0),
               car_in=>car_in2, car_out=>car_out2);
	
	counter_unit: entity work.stop_watch(if_arch)
      port map(clk=>clk, reset=>reset, inc1=>car_in1,
               inc2=>car_in2, dec1=>car_out1, dec2=>car_out2,
					d2=>d2, d1=>d1, d0=>d0);
	
	disp_unit: entity work.disp_hex_mux(arch)
      port map(clk=>clk, reset=>reset, hex3=>"0000",
               hex2=>d2, hex1=>d1, hex0=>d0,
					dp_in=>"1111", an=>an, sseg=>sseg);
				
---------------------------------------------------   
-- clock
   -- 20 ns clock
   process
   begin
      clk <= '0';
      wait for T/2;
      clk <= '1';
      wait for T/2;
   end process;
---------------------------------------------------   
   -- reset
---------------------------------------------------   
   -- reset para T/2
   reset <= '1', '0' after T/2;

---------------------------------------------------   
   -- outros estimulus
---------------------------------------------------   
   process
   begin
      
		sw<= "0000";
		
		
---------------------------------------------------   
--      simulando a entrada de um carro
---------------------------------------------------   

      wait until falling_edge(clk);
      wait until falling_edge(clk);
   
      sw <= "1000";
		
		wait until falling_edge(clk);
		
		sw<= "1100";
		
		wait until falling_edge(clk);
		
		sw<="0100";
		
		wait until falling_edge(clk);
		
		sw<="0000";
---------------------------------------------------   
                
		--simulando a entrada de 200 carros (dois entrando de cada vez por x100 vezes)
---------------------------------------------------   

		
		for i in 1 to 100 loop 
			wait until falling_edge(clk);
   
			sw <= "1010";
			
			wait until falling_edge(clk);
			
			sw<= "1111";
			
			wait until falling_edge(clk);
			
			sw<="0101";
			
			wait until falling_edge(clk);
			
			sw<="0000";
						
			wait until falling_edge(clk);
		end loop;

---------------------------------------------------   
		-- simulando entrada de 100 carros (dois entrando por 50 vezes)
---------------------------------------------------   
		
		-- total esperado => 201 carros
		
		for i in 1 to 50 loop 
			wait until falling_edge(clk);
   
			sw <= "0101";
			
			wait until falling_edge(clk);
			
			sw<= "1111";
			
			wait until falling_edge(clk);
			
			sw<="1010";
			
			wait until falling_edge(clk);
			
			sw<="0000";
						
			wait until falling_edge(clk);
		end loop;
		
		-- total esperado => 101 carros
		
		sw<= "0000";
		--
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		wait until falling_edge(clk);




		assert false
         report "Simulation Completed"
       severity failure;
   end process ;
end arch;
