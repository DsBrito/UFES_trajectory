----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:21:27 11/29/2020 
-- Design Name: 
-- Module Name:    timer - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

entity timer is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           start : in  STD_LOGIC;
           tick : out  STD_LOGIC);
end timer;

architecture Behavioral of timer is
--	--número de segundos
--	constant N: integer := 16;--32;
--	--número de ciclos por segundo 50 MHz 
--	constant P: integer := 50_000_000;
--	--número de bits para contar de 0 a P-1
--	constant K: integer := 26; 
--	--número de bits para contar de 0 a N-1
--	constant L: integer := 4;--número de bits para contar de 0 a N-1 
	constant N: integer := 4;--16;--32;--número de segundos
	constant P: integer := 16;--50_000_000;--número de ciclos por segundo 50 MHz 
	constant K: integer := 4;--26; --número de bits para contar de 0 a P-1
	constant L: integer := 2;--4;--5; --número de bits para contar de 0 a N-1 

	--contador de ciclos para dar 1 segundo
	signal count_reg,count_next: unsigned (K-1 downto 0); 
	--contador de segundos
	signal count_sec_reg,count_sec_next: unsigned (L-1 downto 0); 

begin
	process(clk, reset)
	begin
		if reset = '1' then
			count_reg <= (others=>'0');
			count_sec_reg <= (others=>'0'); --fechado
		elsif clk' event and clk = '1' then
			count_reg <= count_next;
			count_sec_reg <= count_sec_next;
		end if;
	end process;
	tick <= '1' when count_sec_reg = N-1 and count_reg = 0 else
			'0';
	process(count_reg,count_sec_reg, start)
	begin
		count_sec_next <= count_sec_reg;
		count_next <= count_reg;
		if start = '1' then 
			count_next <= (others=>'0');
			count_sec_next <= (others=>'0'); 			
		else
			if count_reg = P-1 then 
				count_next <= (others=>'0');
				if count_sec_reg = N-1 then
					count_sec_next <= (others=>'0'); 
				else
					count_sec_next <= count_sec_reg + 1;
				end if;
			else
				count_next <= count_reg + 1;
			end if;
		end if; 
	end process;
end Behavioral;

