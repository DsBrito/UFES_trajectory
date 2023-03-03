----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:58:43 04/25/2018 
-- Design Name: 
-- Module Name:    low_freq_counter_test - Behavioral 
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

entity low_freq_counter_test is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           btn : in  STD_LOGIC_VECTOR (0 downto 0);
           sw : in  STD_LOGIC_VECTOR(1 DOWNTO 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0));
end low_freq_counter_test;

architecture Behavioral of low_freq_counter_test is
	signal start: std_logic;
	signal si_f: std_logic;
	signal bcd3, bcd2, bcd1, bcd0: std_logic_vector(3 downto 0);
	
begin
	
	-- debounce do botão 
	debounce0: entity work.debounce (fsmd_arch)
   port map(
      clk => clk,
		reset => reset, 
      sw => btn(0), 
      db_level => open,
		db_tick =>start
   ); 
	
   signal_generator0: entity work.signal_generator (Behavioral)
    Port map(
			clk => clk,
			reset => reset, 
			sw => sw, 
         si => si_f);
			
	-- instancia circuito de contagem de frequencia
	low_freq0: entity work.low_freq_counter (arch)
    port map(
        clk=>clk,
		  reset=>reset,
        start=>start,
        si=>si_f,
        bcd3=>bcd3,
		  bcd2=>bcd2, 
		  bcd1=>bcd1,
		  bcd0=>bcd0
    );
	disp_mux0: entity work.disp_hex_mux (arch)
   port map(
      clk => clk, 
		reset => reset,
      hex3 =>bcd3, 
		hex2 => bcd2,
		hex1 => bcd1,
		hex0 => bcd0,
      dp_in =>"1111",
      an => an, 
      sseg => sseg
   );
end Behavioral;

