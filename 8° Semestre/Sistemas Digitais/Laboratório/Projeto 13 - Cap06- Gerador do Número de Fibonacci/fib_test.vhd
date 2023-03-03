----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:53:50 04/17/2018 
-- Design Name: 
-- Module Name:    fib_test - Behavioral 
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

entity fib_test is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           btn : in  STD_LOGIC_VECTOR (0 downto 0);
           sw : in  STD_LOGIC_VECTOR (4 downto 0);
			  led: out STD_LOGIC_VECTOR(4 downto 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           sseg : out  STD_LOGIC_VECTOR (7 downto 0));
end fib_test;

architecture Behavioral of fib_test is
	signal f,f_reg, f_next : std_logic_vector (20 downto 0);
	signal ready, done_tick: std_logic;
	signal start, db_tick: std_logic;

begin
   -- instanciar o circuito de debounce para o botao
   db_unit: entity work.debounce(fsmd_arch)
      port map(
         clk=>clk, reset=>reset, sw=>btn(0),
         db_level=> open, db_tick=>db_tick
      );
	
	-- start será '1' se o botão for pressionado e o circuito estiver ready
	start <= db_tick and ready;
	
	-- instanciar o circuito que calcula o número de fibonacci 
	fib0: entity work.fib (arch)  
    port map(
        clk=>clk, reset=>reset, 
        start=>start,
        i=>sw, 
        ready => ready,
		  done_tick=>done_tick,
        f=>f
    );
	
	-- circuito que armazena o valor de f quando done_tick = '1'
	process(clk,reset)
	begin
		if reset = '1' then
			f_reg <= (others=>'0');
		elsif rising_edge(clk) then
			f_reg <= f_next;
		end if;
	end process;
	
	f_next <= f      when done_tick = '1' else 
	          f_reg;

	-- mostrar 5 bits mais significativos da resposta nos leds
	led <= f_reg(20 downto 16);

	 --instanciar o circuito que faz multiplexação entre os displays de 7-segmentos para mostrar 16 bits menos significativos
	 disp_hex0: entity work.disp_hex_mux (arch)
    port map(
      clk=>clk, reset=>reset,
      hex3 =>f_reg(15 downto 12), 
		hex2=>f_reg(11 downto 8),
		hex1=>f_reg(7 downto 4),
		hex0=>f_reg(3 downto 0),
      dp_in=>"1111",
      an=>an,
      sseg=>sseg
   );
				
end Behavioral;

