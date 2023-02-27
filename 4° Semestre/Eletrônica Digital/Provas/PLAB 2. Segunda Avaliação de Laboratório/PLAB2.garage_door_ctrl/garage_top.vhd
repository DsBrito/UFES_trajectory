----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:21:48 12/06/2020 
-- Design Name: 
-- Module Name:    garage_top - Behavioral 
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

entity garage_top is
	port (  clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           IV : in  STD_LOGIC;
           SI : in  STD_LOGIC;
           SE : in  STD_LOGIC;
			  A : out STD_LOGIC;
			  F : out STD_LOGIC;
			  tick: out std_logic;
           L : out  STD_LOGIC
           );
end garage_top;

architecture Behavioral of garage_top is
	signal start, AA,FF, tick_t: std_logic;
	signal pos: std_logic_vector(3 downto 0);
	signal m: std_logic_vector(1 downto 0);
begin
	A <= AA;
	F <= FF;
	tick <= tick_t;
   garage_door_unit: entity work.garage_door_ctrl(Behavioral)
      port map(clk=>clk, 
		         reset=>reset, 
               SI =>SI,
               SE =>SE,
					IV=>IV,
					Tick=>Tick_t,
               A => AA,
               F => FF,
					L => L,
					start => start,
					m => m
					);  
	motor_unit: entity work.motor_ctrl (Behavioral)
    Port map( clk => clk, 
           reset => reset,
           m => m,
			  pos=> pos,
           A => AA,
           F => FF);
	timer_unit: entity work.timer (Behavioral)
		Port map ( clk => clk,
				  reset =>reset,
				  start =>start,
				  tick => tick_t);


end Behavioral;

