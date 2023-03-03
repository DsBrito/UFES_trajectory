----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:32:37 04/25/2018 
-- Design Name: 
-- Module Name:    period_test - Behavioral 
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

entity period_test is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           sw : in  STD_LOGIC_VECTOR(1 DOWNTO 0);
           btn : in  STD_LOGIC_VECTOR (0 downto 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0));
end period_test;

architecture Behavioral of period_test is
	signal si_f, ready, start, done_tick:std_logic;
	signal prd: std_logic_vector(9 downto 0);
	signal prd_reg,prd_next: std_logic_vector(9 downto 0);
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
			reset => '0', 
			sw => sw, 
         si => si_f);
			

	period_counter0: entity work.period_counter (arch)
   port map(
      clk=>clk,
		reset=>reset,
      start=> start,
		si=> si_f,
      ready=>ready,
		done_tick=>done_tick,
      prd=>prd
   );
	process(clk,reset)
	begin
		if reset = '1' then
			prd_reg <= (others => '0');
		elsif clk'event and clk = '1' then
			prd_reg <= prd_next;
		end if;
	end process;
	prd_next <= prd when done_tick = '1' else 
					prd_reg;
	bcd3 <="0000";
	bcd2 <= "00"&prd_reg(9 downto 8);
	bcd1 <= prd_reg(7 downto 4);
	bcd0 <= prd_reg(3 downto 0);
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

