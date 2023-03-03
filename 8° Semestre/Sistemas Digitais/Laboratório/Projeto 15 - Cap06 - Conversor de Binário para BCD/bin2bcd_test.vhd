----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:00:35 04/24/2018 
-- Design Name: 
-- Module Name:    Bin_to_BCD_Converter_Test - Behavioral 
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
entity bin2bcd_test is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           btn : in  STD_LOGIC_VECTOR (0 downto 0);
			  sw : in  STD_LOGIC_VECTOR (12 downto 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0);           
           led : out  STD_LOGIC_VECTOR (0 downto 0));
end bin2bcd_test;

architecture Behavioral of bin2bcd_test is
	signal start, ready, done_tick, btn_tick: std_logic;
	signal bcd3, bcd2, bcd1, bcd0: std_logic_vector(3 downto 0);
	signal bin: std_logic_vector(12 downto 0);
begin
	-- debounce do botão 
	debounce0: entity work.debounce (fsmd_arch)
   port map(
      clk => clk,
		reset => reset, 
      sw => btn(0), 
      db_level => open,
		db_tick =>btn_tick
   ); 
	
	bin <= sw;
	bin2bcd0: entity work.bin2bcd (arch)
   port map(
      clk=>clk,
      reset=>reset,
      start=>start,
      bin=>bin,
      ready=>ready, 
		done_tick=>done_tick,
      bcd3=>bcd3,
		bcd2=>bcd2,
		bcd1=>bcd1,
		bcd0=>bcd0
		);
	disp_hex_mux0: entity work.disp_hex_mux (arch)
   port map(
      clk=>clk,
		reset=>reset,
      hex3=>bcd3,
		hex2=>bcd2, 
		hex1=>bcd1, 
		hex0=>bcd0,
      dp_in=>"1111",
      an=>an,
      sseg=>sseg
   );
	led(0) <= ready;
	start <= btn_tick and ready;

end Behavioral;

