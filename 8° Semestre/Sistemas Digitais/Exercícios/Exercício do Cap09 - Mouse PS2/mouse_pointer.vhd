----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:28:45 07/21/2021 
-- Design Name: 
-- Module Name:    mouse_pointer - Behavioral 
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

entity mouse_pointer is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           ps2d : inout  STD_LOGIC;
           ps2c : inout  STD_LOGIC;
           pointer_x : out  STD_LOGIC_VECTOR (9 downto 0);
           pointer_y : out  STD_LOGIC_VECTOR (9 downto 0);
           pointer_color : out  STD_LOGIC_VECTOR (7 downto 0));
end mouse_pointer;

architecture Behavioral of mouse_pointer is
   signal xm, ym: std_logic_vector(8 downto 0);
   signal btnm: std_logic_vector(2 downto 0);
   signal m_done_tick: std_logic;
	signal pointer_x_reg, pointer_x_next: unsigned (9 downto 0);
	signal pointer_y_reg, pointer_y_next: unsigned (9 downto 0);
	signal pointer_color_reg, pointer_color_next: unsigned (7 downto 0); 
	signal sum_x: signed (9 downto 0);
begin
   -- instantiation
   mouse_unit: entity work.mouse(arch)
      port map(clk=>clk, reset=>reset,
               ps2d=>ps2d, ps2c=>ps2c,
               xm=>xm, ym=>ym, btnm=>btnm,
               m_done_tick=>m_done_tick);
	-- atualizar o valor de pointer_x_reg, pointer_y_reg e pointer_color_reg
	process(clk, reset) 
	begin
		if reset = '1' then
			pointer_x_reg <= to_unsigned(320,10);
			pointer_y_reg <= to_unsigned(240,10);
			pointer_color_reg <= to_unsigned(125,8);
		elsif clk' event and clk = '1' then
			pointer_x_reg <= pointer_x_next;
			pointer_y_reg <= pointer_y_next;
			pointer_color_reg <= pointer_color_next;
		end if;
	end process;
	-- atualizar os próximos estados
--	pointer_color_next <= pointer_color_reg + 1 when m_done_tick = '1' and btnm(1) = '1' else
--								 pointer_color_reg - 1 when m_done_tick = '1' and btnm(0) = '1' else
--								 pointer_color_reg;
	process(pointer_color_reg, m_done_tick, btnm)
	begin
		pointer_color_next <= pointer_color_reg;
		if m_done_tick = '1' and btnm(1) = '1' then
			pointer_color_next <= pointer_color_reg + 1;
		elsif m_done_tick = '1' and btnm(0) = '1' then
			pointer_color_next <= pointer_color_reg - 1;
		end if;		
	end process;
	
	sum_x <= signed(pointer_x_reg) + signed(xm(8)&xm);
	process(pointer_x_reg, m_done_tick, xm)
	begin
		pointer_x_next <= pointer_x_reg;
		if m_done_tick = '1' then
			if sum_x < 0 then
				pointer_x_next <= (others=>'0');
			elsif sum_x > 631 then 
				pointer_x_next <= to_unsigned(631,10);
			else
				pointer_x_next <= unsigned (sum_x);
			end if;
		end if;
	end process;
	--atualizar pointer_y_next 
	
	pointer_x <= std_logic_vector(pointer_x_reg);
	pointer_y <= std_logic_vector(pointer_y_reg);
	pointer_color <= std_logic_vector(pointer_color_reg);

end Behavioral;

