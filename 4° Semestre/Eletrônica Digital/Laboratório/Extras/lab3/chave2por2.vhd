----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:03:59 09/25/2020 
-- Design Name: 
-- Module Name:    chave2por2 - Behavioral 
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

entity chave2por2 is
    Port ( x : in  STD_LOGIC_VECTOR (1 downto 0);
           ctrl : in  STD_LOGIC_VECTOR (1 downto 0);
           y : out  STD_LOGIC_VECTOR (1 downto 0));
end chave2por2;

architecture cond_arch of chave2por2 is

begin

 y <= x          when ctrl = "00" else
      x(0)& x(1) when ctrl = "01" else
		x(0)& x(0) when ctrl = "10" else
		x(1)& x(1); -- ctrl = "11"

end cond_arch;

--========================
-- abaixo está a segunda arquitetura usando o comando de atribuição selecionada
--======================== 
architecture sel_arch of chave2por2 is

begin

	with ctrl select 
	y <= x          when "00", 
        x(0)& x(1) when "01",
		  x(0)& x(0) when "10",
		  x(1)& x(1) when others; -- ctrl = "11"
end sel_arch;

--architecture if_arch of chave2por2 is
--
--begin
--	process(x,ctrl)
--	begin
--		if ctrl = "00" then
--			y <= x; 
--		elsif ctrl = "01" then
--			y <= x(0)& x(1);
--      elsif ctrl = "10" then
--			y <= x(0)& x(0); 
--		else -- ctrl = "11" 
--			y <= x(1)& x(1);
--		end if;
--	end process;
--end if_arch;
--
--architecture case_arch of chave2por2 is
--
--begin
--	process(x, ctrl)
--	begin
--		case ctrl is
--			when "00"   => y <= x;
--			when "01"   => y <= x(0)& x(1); 
--			when "10"   => y <= x(0)& x(0); 
--			when others => y <= x(0)& x(1); 
--		end case;
--	end process;
--		
--end case_arch;
