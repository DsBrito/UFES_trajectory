-- Testbench - rotate_right 
  library ieee;
  use ieee.std_logic_1164.all;
  use ieee.numeric_std.all;

  entity testbench is
  end testbench;

  architecture behavior of testbench IS 
          signal a: std_logic_vector(7 downto 0);
          signal amt: std_logic_vector(2 downto 0);
			 signal y: std_logic_vector(7 downto 0);
  begin

	-- Instanciação do Componente
	-- Alterando para multi_level_arch
	uut: entity work.rotate_right(multi_level_arch)
   port map(a=>a, amt=>amt, y=>y);


   process
   begin
      -- vetores de teste 
      a <= "11110000";
      amt <= "000";
		for i in 1 to 8 loop
			wait for 200 ns;
			amt <= std_logic_vector(unsigned(amt)+1);
		end loop;
      -- terminar simulação 
      assert false
         report "Simulation Completed"
         severity failure;
   end process;

  end;
