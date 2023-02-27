----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:47:03 11/11/2020 
-- Design Name: 
-- Module Name:    descod2_4_n - Behavioral 
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

entity decod2_4_n is
    Port ( a : in  STD_LOGIC_VECTOR (1 downto 0);
           s : out  STD_LOGIC_VECTOR (3 downto 0));
end decod2_4_n;

architecture Behavioral of decod2_4_n is

begin
	with a select
	s <= "1110" when "00",
	     "1101" when "01",
	     "1011" when "10",
	     "0111" when others; 
end Behavioral;

