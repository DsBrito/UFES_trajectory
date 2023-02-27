----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:07:42 11/11/2020 
-- Design Name: 
-- Module Name:    ascii_sseg - Behavioral 
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

entity ascii_sseg is
    Port ( ascii_code : in  STD_LOGIC_VECTOR (7 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0));
end ascii_sseg;

architecture Behavioral of ascii_sseg is

begin
   with ascii_code select
      sseg <=
		   "10000001" when "00110000",--0
         "11001111" when "00110001",--1
         "10010010" when "00110010",--2
         "10000110" when "00110011",--3
         "11001100" when "00110100",--4
         "10100100" when "00110101",--5
         "10100000" when "00110110",--6
         "10001111" when "00110111",--7
         "10000000" when "00111000",--8
         "10000100" when "00111001",--9
         "10001000" when "01000001", --A
         "11100000" when "01000010", --b
         "10110001" when "01000011", --C
         "11000010" when "01000100", --d
         "10110000" when "01000101", --E
         "10111000" when "01000110", --F
			"10100001" when "01000111", --G
         "11001000" when "01001000", --H
         "11001111" when "01001001",-- I igual ao 1
         "11000011" when "01001010",  -- J
         "11111111" when "01001011",  -- K não dá para fazer
         "11110001" when "01001100",  -- L
         "11111111" when "01001101",  -- M não dá para fazer
         "11111111" when "01001110",  -- N não dá para fazer
         "10000001" when "01001111",  -- O igual 0
         "10011000" when "01010000",  -- P
         "11111111" when "01010001",  -- Q não dá para fazer
         "11111111" when "01010010",  -- R não dá para fazer
         "10100100" when "01010011",  -- S igual ao 5
			"11111111" when "01010100",  -- T não dá para fazer
         "11000001" when "01010101",  -- U
         "11111111" when "01010110",  -- V não dá para fazer
         "11111111" when "01010111",  -- W não dá para fazer
         "11111111" when "01011000",  -- X não dá para fazer
         "11111111" when "01011001",  -- Y não dá para fazer
         "11111111" when "01011010",  -- Z 
         "11111111" when others;      -- space
end Behavioral;


