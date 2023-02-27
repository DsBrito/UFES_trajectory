----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:06:54 11/26/2020 
-- Design Name: 
-- Module Name:    johnsons_testbench - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity johnsons_testbench is
end johnsons_testbench;

architecture Behavioral of johnsons_testbench is
   constant T: time := 20 ns; -- perop
   signal clk, reset: STD_LOGIC;
	signal enable: STD_LOGIC;
	signal count: STD_LOGIC_VECTOR(7 downto 0);

begin
   johnsons_unit: entity work.johnsons_counter_8bits(Behavioral)
      port map(clk=>clk, 
					reset=>reset, 
               enable=>enable, 
					count=>count);

   -- 20 ns clock running forever //slide 6
   process
   begin
      clk <= '0';
      wait for T/2;
      clk <= '1';
      wait for T/2;
   end process;

   -- reset asserted for T/2
   reset <= '1', '0' after T/2;
   process
   begin
		-- valor inicial com contagem desabilitada    //slide 8
		enable <= '0';
		wait until falling_edge(clk);
		wait until falling_edge(clk);
		--habilidata contagem
		enable <= '1';
		wait until falling_edge(clk);
		
		
		--pause 2 clocks    //slide 9
		wait until falling_edge(clk);
		--escolha o valor de i para permitir a
		--contagem circular por todos os valores
		for i in 1 to 10 loop --count 10 clocks
			wait until falling_edge(clk);
		end loop;
      assert false    --//slide 10
         report "Simulation Completed"
       severity failure;
		end process;

end Behavioral;