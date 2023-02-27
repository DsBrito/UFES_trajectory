----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:09:37 11/11/2020 
-- Design Name: 
-- Module Name:    top_level_lab7 - Behavioral 
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
entity top_level_lab7 is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0));
end top_level_lab7;

architecture Behavioral of top_level_lab7 is
	signal timer_tick: std_logic;
	signal dig: std_logic_vector(1 downto 0);
	signal letter: std_logic_vector(7 downto 0);
begin
	-- instancia o timer
	timer_unit: entity work.timer (Behavioral)
						port map ( clk => clk, 
						reset => reset, 
						timer_tick => timer_tick);
	-- instancia a máquina de estados
   fsm_unit: entity work.fsm (Behavioral) 
						port map( clk=>clk,
           reset=>reset,
			  timer_tick=>timer_tick,
           dig=>dig,
           letter=>letter);
   -- instancia o decodificador 2:4 com saídas ativas em 0
	decod_unit: entity work.decod2_4_n (Behavioral)
						port map (a=>dig,
           s=>an);
	-- instancia o conversor de ascii para display de sete segmentos
	ascii_sseg_unit: entity work.ascii_sseg (Behavioral)
						port map (ascii_code=>letter,
									sseg=>sseg);
end Behavioral;

