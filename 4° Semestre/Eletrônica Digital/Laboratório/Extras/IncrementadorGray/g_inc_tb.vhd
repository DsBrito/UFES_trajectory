library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity g_inc_tb is
end g_inc_tb;

architecture tb_arch of g_inc_tb is
   signal g: std_logic_vector(3 downto 0);
	signal g1: std_logic_vector(3 downto 0);
begin
   -- instantiate the circuit under test
	-- mudando para indirect_arch
   uut: entity work.g_inc (indirect_arch)
      port map( g=>g, g1=>g1);
		
   -- test vector generator
   process
   begin
		g <= "0000";
		for i in 1 to 16 loop
			wait for 200 ns; 			
			g <= std_logic_vector(unsigned(g)+1);
		end loop;
-- alternativa com g seguindo o código Gray
--		for i in 1 to 16 loop
--			wait for 200 ns; 			
--			g <= g1; --std_logic_vector(unsigned(g)+1);
--		end loop;

		assert false
			report "Simulation Completed"
			severity failure;
   end process;
end tb_arch;
