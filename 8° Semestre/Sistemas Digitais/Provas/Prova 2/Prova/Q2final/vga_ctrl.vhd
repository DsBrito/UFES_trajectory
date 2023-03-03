library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity vga_ctrl is 
    port(
        clk : in  STD_LOGIC;
        reset : in  STD_LOGIC;
		a_bcd2, a_bcd1, a_bcd0: in std_logic_vector(3 downto 0);
		b_bcd2, b_bcd1, b_bcd0: in std_logic_vector(3 downto 0);
		p_bcd4, p_bcd3, p_bcd2, p_bcd1, p_bcd0: in std_logic_vector(3 downto 0);
        hsync : out  STD_LOGIC;
        vsync : out  STD_LOGIC;
        rgb : out  STD_LOGIC_VECTOR (11 downto 0)
    );
end vga_ctrl;

architecture Behavioral of vga_ctrl is
    signal pixel_x, pixel_y: std_logic_vector(9 downto 0);
	signal video_on, pixel_tick: std_logic;
	signal text_on: std_logic;
    signal text_rgb: std_logic_vector(11 downto 0);
	signal rgb_reg, rgb_next: std_logic_vector(11 downto 0);
	
	signal refresh_tick: std_logic;
	signal a_bcd2_s, a_bcd1_s, a_bcd0_s: std_logic_vector(3 downto 0);
    signal b_bcd2_s, b_bcd1_s, b_bcd0_s: std_logic_vector(3 downto 0);
    signal p_bcd4_s, p_bcd3_s, p_bcd2_s, p_bcd1_s, p_bcd0_s: std_logic_vector(3 downto 0);
begin

	vga_sync_unit: entity work.vga_sync port map(
	   clk => clk, reset => reset, hsync => hsync,
	   vsync => vsync, video_on => video_on, pixel_x => pixel_x,
	   pixel_y => pixel_y, p_tick => pixel_tick
    );
    
    refresh_tick <= '1' when unsigned(pixel_x) = 0 and unsigned(pixel_y) = 480 else '0';
					
	vga_mult_result_unit: entity work.vga_mult_result port map(
	   clk=>clk, reset => reset, pixel_x => pixel_x, pixel_y => pixel_y,
	   a_bcd2 => a_bcd2, a_bcd1 => a_bcd1, a_bcd0 => a_bcd0,
	   b_bcd2 => b_bcd2, b_bcd1 => b_bcd1, b_bcd0 => b_bcd0,
       p_bcd4 => p_bcd3, p_bcd3 => p_bcd3, p_bcd2 => p_bcd2, p_bcd1 => p_bcd1, p_bcd0 => p_bcd0,
       video_on => video_on, text_on=>text_on, text_rgb=>text_rgb
	);
					
	-- registers				
	process(clk, reset)
	begin
		if reset = '1' then
			rgb_reg <= (others => '0');
		elsif(clk' event and clk = '1') then
			if (pixel_tick = '1') then
				rgb_reg <= rgb_next;
			end if;
		end if;
	end process;
	
	 -- rgb multiplexing circuit
	process(video_on, text_on, text_rgb)
	begin
		if video_on='0' then
				rgb_next <= "000000000000";
		else if text_on = '1' then
				rgb_next <= text_rgb;
			  else
				rgb_next <= "000011111100"; --background
			  end if;
		end if;
	end process;
	
	rgb <= rgb_reg;
end Behavioral;

