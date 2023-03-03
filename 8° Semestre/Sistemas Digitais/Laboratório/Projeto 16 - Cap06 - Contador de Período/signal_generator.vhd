----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:33:06 04/25/2018 
-- Design Name: 
-- Module Name:    signal_generator - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity signal_generator is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           sw : in  STD_LOGIC_VECTOR (1 downto 0);
           si : out  STD_LOGIC);
end signal_generator;

architecture Behavioral of signal_generator is
	signal count_reg,count_next: unsigned(26 downto 0);
	constant max1: integer := 100_000_000; -- 1Hz
	constant max2: integer := 32_000_000; -- 3,125Hz
	constant max3: integer := 13_468_013; -- 7,425Hz
	constant max4: integer := 12_500_000; --8Hz 
begin
	process(clk,reset)
	begin
		if reset = '1' then 
			count_reg <= (others=>'0');
		elsif (clk'event and clk='1') then 
			count_reg <= count_next;
		end if;
	end process;
	

	process(count_reg,sw)
	begin
		count_next <= count_reg+1;
		si <= '0';
		case sw is 
			when "00"=> if count_reg >= (max1/2) then
								si <= '1';
								if count_reg = max1-1 then 	
									count_next <= (others=>'0');
								end if;
							end if;
			when "01"=> if count_reg >= (max2/2) then
								si <= '1';
								if count_reg = max2-1 then 	
									count_next <= (others=>'0');
								end if;
							end if;
			when "10"=> if count_reg >= (max3/2) then
								si <= '1';
								if count_reg = max3-1 then 	
									count_next <= (others=>'0');
								end if;
							end if;
			when others=> if count_reg >= (max4/2) then
								si <= '1';
								if count_reg = max4-1 then 	
									count_next <= (others=>'0');
								end if;
							end if;
			end case;		
	end process;
end Behavioral;

