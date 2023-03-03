----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:27:17 04/23/2018 
-- Design Name: 
-- Module Name:    division_test - Behavioral 
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

entity division_test is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           btn : in  STD_LOGIC_VECTOR (0 downto 0);
           sw : in  STD_LOGIC_VECTOR (7 downto 0);
           led : out  STD_LOGIC_VECTOR (0 downto 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0)
			  );
end division_test;

architecture Behavioral of division_test is
	signal db_tick, start, ready, done_tick: std_logic;
	signal quo, rmd : std_logic_vector(3 downto 0);
begin
	debounce_a: entity work.debounce (fsmd_arch)
   port map(
      clk => clk,
		reset => reset, 
      sw => btn(0), 
      db_level => open,
		db_tick =>db_tick
   );
	start <= db_tick and ready;
	
	led(0) <= ready;
	
	diva: entity work.div (arch)
    generic map(
       W => 4,
       CBIT => 3   -- CBIT=log2(W)+1
    )
    port map(
		clk => clk,
		reset => reset, 
      start=>start,
      dvsr => sw(3 downto 0), 
		dvnd => sw(7 downto 4),
      ready => ready,
		done_tick => done_tick,
      quo => quo,
		rmd => rmd
	);
	disp_muxa: entity work.disp_hex_mux (arch)
   port map(
      clk => clk, 
		reset => reset,
      hex3 => sw(7 downto 4), 
		hex2 => sw(3 downto 0),
		hex1 => quo,
		hex0 => rmd,
      dp_in =>"0010",
      an => an, 
      sseg => sseg
   );

end Behavioral;

