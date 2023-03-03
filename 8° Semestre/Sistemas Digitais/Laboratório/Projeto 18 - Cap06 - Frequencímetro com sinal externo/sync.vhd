----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:09:58 04/25/2018 
-- Design Name: 
-- Module Name:    sync - Behavioral 
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
entity sync is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           si : in  STD_LOGIC;
           si_f : out  STD_LOGIC);
end sync;
architecture Behavioral of sync is
	signal si_reg, si_next: std_logic_vector(1 downto 0);
begin
	process(clk,reset)
	begin
		if reset = '1' then 
			si_reg <= "00";
		elsif (clk'event and clk = '1') then
			si_reg <= si_next;
		end if;
	end process;
	si_next <= si & si_reg(1);
	si_f <= si_reg(0);
end Behavioral;

