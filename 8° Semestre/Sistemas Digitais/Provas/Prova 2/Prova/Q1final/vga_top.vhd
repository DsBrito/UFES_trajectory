library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--use IEEE.NUMERIC_STD.ALL;


entity vga_top is
  Port (
        clk : in  STD_LOGIC;
        reset : in  STD_LOGIC;
        hsync : out  STD_LOGIC;
        vsync : out  STD_LOGIC;
        rgb : out  STD_LOGIC_VECTOR (11 downto 0)
   );
end vga_top;

       
architecture Behavioral of vga_top is

begin
    vga_ctrl_unit: entity work.vga_ctrl port map(
    clk => clk, reset => reset, hsync => hsync, vsync => vsync, rgb => rgb,
    a_bcd2 => "0001", a_bcd1 => "0001", a_bcd0 => "0001",
    b_bcd2 => "0001", b_bcd1 => "0001", b_bcd0=> "0001",
    p_bcd4 => "0001", p_bcd3 => "0001", p_bcd2 => "0001", p_bcd1 => "0001", p_bcd0 => "0001");

end Behavioral;
