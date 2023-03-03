library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity vga_mult_result is
	port(
			clk, reset: in  STD_LOGIC;
			a_bcd2, a_bcd1, a_bcd0: in std_logic_vector(3 downto 0);
			b_bcd2, b_bcd1, b_bcd0: in std_logic_vector(3 downto 0);
			p_bcd4, p_bcd3, p_bcd2, p_bcd1, p_bcd0: in std_logic_vector(3 downto 0);
			pixel_x, pixel_y: in std_logic_vector(9 downto 0);			
			video_on: in std_logic;
			text_on: out std_logic;
            text_rgb: out std_logic_vector(11 downto 0)
	      );
end vga_mult_result;
architecture Behavioral of vga_mult_result is
	 signal pix_x, pix_y: unsigned(9 downto 0);
	--font ROM
	 signal char_addr, char_addr_s: std_logic_vector (6 downto 0);
	 signal row_addr, row_addr_s: std_logic_vector(3 downto 0);
	 signal rom_addr: std_logic_vector (10 downto 0);
	 signal bit_addr, bit_addr_s: std_logic_vector(2 downto 0);
	 signal font_word: std_logic_vector(7 downto 0);
	 signal font_bit: std_logic;
	 
	 signal score_on: std_logic;
begin
	pix_x <= unsigned(pixel_x);
    pix_y <= unsigned(pixel_y);
	
	font_unit: entity work.font_rom
		port map(clk => clk, addr=>rom_addr, data => font_word);
	
	score_on <= '1' when pix_y(9 downto 5)=0 and pix_x(9 downto 4)<31 else '0'; 
        
    row_addr_s <= std_logic_vector(pix_y(4 downto 1));
    bit_addr_s <= std_logic_vector(pix_x(3 downto 1));
	
	--char_addr
	with pix_x(8 downto 4) select
     char_addr_s <=
        "1000001" when "00000", -- A
        "0000000" when "00001", -- ' '
        "0111101" when "00010", -- =
        "0000000" when "00011", -- ' '
        "011"&a_bcd2 when "00100", -- A2
        "011"&a_bcd1 when "00101", -- A1
        "011"&a_bcd0 when "00110", -- A0
        

		"0000000" when "00111", -- ' '
		"1000010" when "01000", -- B
        "0000000" when "01001", -- ' '
        "0111101" when "01010", -- =
        "0000000" when "01011", -- ' '
        "011"&b_bcd2 when "01100", -- B2
        "011"&b_bcd1 when "01101", -- B1
        "011"&b_bcd0 when "01110", -- B0
		  
		"0000000" when "01111", -- ' '
		"1010000" when "10000", -- P
		"0000000" when "10001", -- ' '
	    "0111101" when "10010", -- = 
		"0000000" when "10011", -- ' '
		"1000001" when "10100", -- A
		"0101010" when "10101", -- *
		"1000010" when "10110", -- B
		"0000000" when "10111", -- ' '
		"0111101" when "11000", -- =
		"0000000" when "11001", -- ' '
		"011"&p_bcd4 when "11010", -- P4
		"011"&p_bcd3 when "11011", -- P3
		"011"&p_bcd2 when "11100", -- P2
        "011"&p_bcd1 when "11101", -- P1
        "011"&p_bcd0 when others;  -- P0
        
	  
	process(score_on, char_addr_s, row_addr_s, bit_addr_s, font_bit, video_on)
	begin
		text_rgb <= (others=>'0');
		char_addr <= (others=>'0');
		row_addr <= (others=>'0');
		bit_addr <= (others=>'0');
		if score_on = '1' and video_on = '1' then
			char_addr <= char_addr_s;
            row_addr <= row_addr_s;
            bit_addr <= bit_addr_s;
            if font_bit='1' then
                text_rgb <= "111100000000";
			end if;
		end if;
	end process;
	
   rom_addr <= char_addr & row_addr;
   font_bit <= font_word(to_integer(unsigned(not bit_addr)));
   
   text_on <= score_on;
end Behavioral;

