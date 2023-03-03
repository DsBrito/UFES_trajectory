library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity mult_8b_top is
	port(
		clk : in  STD_LOGIC;
        reset : in  STD_LOGIC;
        ps2c : in  STD_LOGIC;
		ps2d : in  STD_LOGIC;
		an: out STD_LOGIC_VECTOR(3 downto 0);
        sseg : out STD_LOGIC_VECTOR(7 downto 0);
        led : out STD_LOGIC_VECTOR(0 downto 0)
	);
end mult_8b_top;

architecture Behavioral of mult_8b_top is
    constant X: std_logic_vector(7 downto 0):="00100010";
    constant Y: std_logic_vector(7 downto 0):="00110101";
    constant IGUAL: std_logic_vector(7 downto 0):="01010101";
    constant S: std_logic_vector(7 downto 0):="00011011";
    constant I: std_logic_vector(7 downto 0):="01000011";
    constant O: std_logic_vector(7 downto 0):="01000100"; 
    constant ZERO: std_logic_vector(7 downto 0):="01000101";
    constant UM: std_logic_vector(7 downto 0):="00010110";
    constant DOIS: std_logic_vector(7 downto 0):="00011110";
    constant TRES: std_logic_vector(7 downto 0):="00100110";
    constant QUATRO: std_logic_vector(7 downto 0):="00100101";
    constant CINCO: std_logic_vector(7 downto 0):="00101110";
    constant SEIS: std_logic_vector(7 downto 0):="00110110";
    constant SETE: std_logic_vector(7 downto 0):="00111101";
    constant OITO: std_logic_vector(7 downto 0):="00111110";
    constant NOVE: std_logic_vector(7 downto 0):="01000110";
    constant A: std_logic_vector(7 downto 0):="00011100";
    constant B: std_logic_vector(7 downto 0):="00110010";
    constant C: std_logic_vector(7 downto 0):="00100001";
    constant D: std_logic_vector(7 downto 0):="00100011";
    constant E: std_logic_vector(7 downto 0):="00100100";
    constant F: std_logic_vector(7 downto 0):="00101011";
 
	type state is (idle, done, x_equal, y_equal, start, output, input, x_low, x_high, y_low, y_high);
	signal state_reg, state_next: state;
	 
	signal k_press : STD_LOGIC;
    signal k_normal : STD_LOGIC;
    signal key : STD_LOGIC_VECTOR (7 downto 0);
    signal k_done_tick : STD_LOGIC; 
	 
	 signal start_reg, start_next: STD_LOGIC;
	 signal ready_reg : STD_LOGIC;
	 
	 signal x_alto_reg, x_alto_next: STD_LOGIC_VECTOR (7 downto 0);
	 signal x_baixo_reg, x_baixo_next: STD_LOGIC_VECTOR (7 downto 0);
	 signal x_reg: STD_LOGIC_VECTOR (7 downto 0);
	 
	 signal y_alto_reg, y_alto_next: STD_LOGIC_VECTOR (7 downto 0);
	 signal y_baixo_reg, y_baixo_next: STD_LOGIC_VECTOR (7 downto 0);
	 signal y_reg: STD_LOGIC_VECTOR (7 downto 0);
	 
	 signal p_out: STD_LOGIC_VECTOR (15 downto 0);
	 signal z_reg , z_next: STD_LOGIC_VECTOR (15 downto 0);
	 signal done_tick: std_logic;
	 
	 signal sel_reg, sel_next: std_logic;
	 signal valid_reg, valid_next: std_logic;
	 
	 signal hex3, hex2, hex1, hex0: std_logic_vector(3 downto 0);
     signal dp_in: std_logic_vector(3 downto 0);
begin
	keyboard_unit: entity work.keyboard(Behavioral)
	port map(
	           clk=>clk, reset=>reset, ps2d=>ps2d, ps2c=>ps2c, k_press=>k_press, k_normal=>k_normal, key=>key, k_done_tick=>k_done_tick
    );
	
	booth_radix4_unit: entity work.booth_radix4(Behavioral)
	port map(
	           clk=>clk, reset=>reset, a_in=>x_reg, b_in=>y_reg, start=>start_reg, ready => ready_reg, p_out=>p_out, done_tick => done_tick
    );
	
	disp_hex_mux_unit: entity work.disp_hex_mux(arch)
	port map(
	           clk=>clk, reset=>reset, hex3=>hex3, hex2=>hex2, hex1=>hex1, hex0=>hex0, dp_in=>dp_in, an => an, sseg => sseg
	);
		
	process(clk, reset)
	begin
		if reset = '1' then
			state_reg <= idle;
			x_reg <= (others => '0');
			x_alto_reg <= (others => '0');
			x_baixo_reg <= (others => '0');
			y_reg <= (others => '0');
			y_alto_reg <= (others => '0');
			y_baixo_reg <= (others => '0');
			valid_reg <= '0';
			sel_reg <= '0';
		elsif clk' event and clk='1' then
			sel_reg <= sel_next;
			start_reg <= start_next;
			x_alto_reg <= x_alto_next;
			x_baixo_reg <= x_baixo_next;
			y_alto_reg <= y_alto_next;
			y_baixo_reg <= y_baixo_next;
			x_reg <= x_alto_next(3 downto 0) & x_baixo_reg(3 downto 0);
			y_reg <= y_alto_next(3 downto 0) & y_baixo_next(3 downto 0);
			valid_reg <= valid_next;
		end if;
	end process;
	
	process(state_reg, sel_reg, start_reg, x_alto_reg, x_baixo_reg, y_alto_reg, y_baixo_reg)
	begin
		state_next <= state_reg;
		sel_next <= sel_reg;
		start_next <= start_reg;
		x_alto_next <= x_alto_reg;
		x_baixo_next <= x_baixo_reg;
		y_alto_next <= y_alto_reg;
		y_baixo_next <= y_baixo_reg;
		valid_next <= valid_reg;
		
		case(state_reg) is
		    when idle => 
		      if(k_done_tick = '1' and k_press = '1') then
		          if(key = X) then
		              state_next <= x_equal;
		          elsif (key = Y) then
		              state_next <= y_equal;
		          elsif(key = S) then
                      state_next <= start;
                  elsif(key = I) then
                      state_next <= input;
                  elsif(key = O) then
                      state_next <= output;
                  end if;
              end if;
            when x_equal =>
                  if(k_done_tick ='1' and k_press = '1') then
                      if(key = IGUAL) then
                          state_next <= x_high;
                      end if;
                  end if;
            when y_equal =>
                  if(k_done_tick ='1' and k_press = '1') then
                      if(key = IGUAL) then
                          state_next <= y_high;
                      end if;
                  end if;
            when x_high =>
                  if(k_done_tick ='1' and k_press = '1') then
                      x_alto_next <= key;
                      state_next <= x_low;
                      sel_next <= '0';
                      valid_next <= '0';
                  end if;
              when x_low =>
                  if(k_done_tick ='1' and k_press = '1') then
                      x_baixo_next <= key;
                      state_next <= idle;
                  end if;                
              when y_high =>
                  if(k_done_tick ='1' and k_press = '1') then
                      y_alto_next <= key;
                      state_next <= y_low;
                      sel_next <= '0';
                      valid_next <= '0';
                  end if;                
              when y_low=>
                  if(k_done_tick ='1' and k_press = '1') then
                      y_baixo_next <= key;
                      state_next <= idle;
                  end if;
              when start =>
                  if(ready_reg = '1') then
                      start_next <= '1';
                      state_next <= done;
                  end if;
              when done =>
                  if(done_tick = '1') then
                      state_next <= idle;
                      start_next <= '0';
                      z_next <= p_out;
                      sel_next <= '1';
                      valid_next <= '1';
                  end if;
              when input =>
                  state_next <= idle;
                  sel_next <= '0';
              when output =>
                  state_next <= idle;
                  sel_next <= '1';	
		end case;
	end process;
	
    x_reg(7 downto 4) <=
           "0001" when x_alto_reg = UM else
           "0010" when x_alto_reg = DOIS else
           "0011" when x_alto_reg = TRES else
           "0100" when x_alto_reg = QUATRO else
           "0101" when x_alto_reg = CINCO else
           "0110" when x_alto_reg = SEIS else
           "0111" when x_alto_reg = SETE else
           "1000" when x_alto_reg = OITO else
           "1001" when x_alto_reg = NOVE else
           "1010" when x_alto_reg = A else
           "1011" when x_alto_reg = B else
           "1100" when x_alto_reg = C else
           "1101" when x_alto_reg = D else
           "1110" when x_alto_reg = E else
           "1111" when x_alto_reg = F else
           "0000";
   x_reg(3 downto 0) <=
           "0001" when x_baixo_reg = UM else
           "0010" when x_baixo_reg = DOIS else
           "0011" when x_baixo_reg = TRES else
           "0100" when x_baixo_reg = QUATRO else
           "0101" when x_baixo_reg = CINCO else
           "0110" when x_baixo_reg = SEIS else
           "0111" when x_baixo_reg = SETE else
           "1000" when x_baixo_reg = OITO else
           "1001" when x_baixo_reg = NOVE else
           "1010" when x_baixo_reg = A else
           "1011" when x_baixo_reg = B else
           "1100" when x_baixo_reg = C else
           "1101" when x_baixo_reg = D else
           "1110" when x_baixo_reg = E else
           "1111" when x_baixo_reg = F else
           "0000";
    y_reg(7 downto 4) <=
          "0001" when y_alto_reg = UM else
          "0010" when y_alto_reg = DOIS else
          "0011" when y_alto_reg = TRES else
          "0100" when y_alto_reg = QUATRO else
          "0101" when y_alto_reg = CINCO else
          "0110" when y_alto_reg = SEIS else
          "0111" when y_alto_reg = SETE else
          "1000" when y_alto_reg = OITO else
          "1001" when y_alto_reg = NOVE else
          "1010" when y_alto_reg = A else
          "1011" when y_alto_reg = B else
          "1100" when y_alto_reg = C else
          "1101" when y_alto_reg = D else
          "1110" when y_alto_reg = E else
          "1111" when y_alto_reg = F else
          "0000";
  y_reg(3 downto 0) <=
          "0001" when y_alto_reg = UM else
          "0010" when y_alto_reg = DOIS else
          "0011" when y_alto_reg = TRES else
          "0100" when y_alto_reg = QUATRO else
          "0101" when y_alto_reg = CINCO else
          "0110" when y_alto_reg = SEIS else
          "0111" when y_alto_reg = SETE else
          "1000" when y_alto_reg = OITO else
          "1001" when y_alto_reg = NOVE else
          "1010" when y_alto_reg = A else
          "1011" when y_alto_reg = B else
          "1100" when y_alto_reg = C else
          "1101" when y_alto_reg = D else
          "1110" when y_alto_reg = E else
          "1111" when y_alto_reg = F else
          "0000";
                  	
	process(sel_reg)
	begin
	    case sel_reg is
	       when '0' => 
            hex0 <= x_reg(3 downto 0);
            hex1 <= x_reg(7 downto 4);
            hex2 <= y_reg(3 downto 0);
            hex3 <= y_reg(7 downto 4);
            dp_in <= "1011";
		  when '1' =>
			hex0 <= z_reg(3 downto 0);
			hex1 <= z_reg(7 downto 4);
			hex2 <= z_reg(11 downto 8);
			hex3 <= z_reg(15 downto 12);
			dp_in <= "1111";
		end case;
	end process;
	
	led(0) <= valid_reg;
end Behavioral;

