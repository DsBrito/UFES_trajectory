-- TestBench Template 

  library ieee;
  use ieee.std_logic_1164.all;
  use ieee.numeric_std.all;

  entity testbench IS
  end testbench;

  architecture behavior_tb of testbench is 
	 signal src0,src1,result:  std_logic_vector(7 downto 0);
	 signal ctrl: std_logic_vector(2 downto 0);
  begin

  -- Component Instantiation
  uut: entity work.simple_alu(case_arch) 
  port map (ctrl=>ctrl, src0=>src0,src1=>src1,result=>result);

  --  Test Bench Statements
   process
   begin
      ctrl<="000";
	
		for i in 1 to 8 loop
		
		--x=4
		--y=8
--------------------------------------------------------------------------------------------
			src0 <= "00000100"; -->x=4
			src1 <= "00001000"; -->y=8
		
			case ctrl is
				when "000"|"001"|"010"|"011" =>
					if not (result ="00000101" ) then 
					assert true
						report"Erro"
						severity note;
					end if;
				when "100" =>
					if not (result ="00001010" ) then
					assert true
						report"Erro"
						severity note;
					end if;
				when "101" =>
					if not (result ="11111100") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "110" =>
					if not (result = "00000000") then
					assert true
						report"Erroe"
						severity note;
					end if;
				when others =>
					if not (result = "00001100") then
					assert true
						report"Erro"
						severity note;
					end if;
			end case;
--------------------------------------------------------------------------------------			
			wait for 200 ns;
			src0 <= "00000100"; -->  x
 			src1 <= "11111000"; -->-y
			
			
			case ctrl is
				when "000"|"001"|"010"|"011" =>
					if not (result ="00000101" ) then
					assert true
						report"Erro"
						severity note;
					end if;
				when "100" =>
					if not (result = "11111100") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "101" =>
					if not (result ="00001010") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "110" =>
					if not (result = "00000000") then
					assert true
						report"Erro"
						severity note;
					end if;
				when others =>
					if not (result = "11111000") then
					assert true
						report"ERRO"
						severity note;
					end if;
			end case;
			
----------------------------------------------------------------------------------			
			wait for 200 ns;
			src0 <= "11111100"; -->-x
			src1 <= "00001000"; -->y
			

			case ctrl is
				when "000"|"001"|"010"|"011" =>
					if not (result = "11111101") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "100" =>
					if not (result ="00000100" ) then
					assert true
						report"Erro"
						severity note;
					end if;
				when "101" =>
					if not (result = "11110100") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "110" =>
					if not (result = "00001000") then
					assert true
						report"Erro"
						severity note;
					end if;
				when others =>
					if not (result = "11111100") then
					assert true
						report"Erro"
						severity note;
					end if;
			end case;
----------------------------------------------------------------------------------			
			wait for 200 ns;
			src0 <= "11111100"; -->-x
			src1 <= "11111000"; -->-y
			
						case ctrl is
				when "000"|"001"|"010"|"011" =>
					if not (result = "11111101") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "100" =>
					if not (result = "11110100") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "101" =>
					if not (result = "00000100") then
					assert true
						report"Erro"
						severity note;
					end if;
				when "110" =>
					if not (result = "11111000") then
					assert true
						report"Erro"
						severity note;
					end if;
				when others =>
					if not (result = "11111100") then
					assert true
						report"Erro"
						severity note;
					end if;
			end case;
----------------------------------------------------------------------------------
		
			wait for 200 ns;
	
			ctrl <= std_logic_vector(unsigned(ctrl)+1);
			
		end loop;

      assert false
         report "Simulation Completed"
         severity failure;		
   end process;
  --  Test Bench Statements
end behavior_tb;