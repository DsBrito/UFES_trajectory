----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:27:30 11/11/2020 
-- Design Name: 
-- Module Name:    timer1ms - Behavioral 
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
           timer_tick : out  STD_LOGIC);

end timer;

architecture Behavioral of timer is
	signal count_reg, count_next : unsigned(15 downto 0);
begin
   
	process(clk, reset)
	begin
		if reset = '1' then
			count_reg <= (others => '1');
		elsif clk'event and clk = '1' then
			count_reg <= count_next; 
		end if;
	end process;
	count_next <= count_reg - 1;
	timer_tick <= '1' when count_reg = 0 else 
	              '0';

end Behavioral;

