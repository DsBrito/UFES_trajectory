library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity keyboard is
    Port ( clk : in  STD_LOGIC;
           ps2c : in  STD_LOGIC;
           ps2d : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           k_done_tick : out  STD_LOGIC;
           k_press : out  STD_LOGIC;
           k_normal : out  STD_LOGIC;
           key : out  STD_LOGIC_VECTOR (7 downto 0));
end keyboard;

architecture Behavioral of keyboard is
	constant E0: std_logic_vector(7 downto 0):="11100000";
	constant F0: std_logic_vector(7 downto 0):="11110000";
	
	signal dout: std_logic_vector(7 downto 0);
    signal rx_done_tick: std_logic;
	
	type statetype is (idle, extended, released, done);
	signal state_reg, state_next: statetype;
	signal key_reg, key_next: std_logic_vector(7 downto 0);
	signal k_press_reg, k_press_next: std_logic;
	signal k_normal_reg, k_normal_next: std_logic;
begin
	ps2_rx_unit: entity work.ps2_rx(arch) port map(clk=>clk, reset=>reset, rx_en=>'1',ps2d=>ps2d,
		ps2c=>ps2c,rx_done_tick=>rx_done_tick, dout=>dout);
	
	process(clk, reset)
	begin
		if reset = '1' then
			state_reg <= idle;
			key_reg <= (others=>'0');
			k_normal_reg <= '0';
			k_press_reg <= '0';
		elsif clk' event and clk='1' then
			state_reg <= state_next;
			key_reg <= key_next;
			k_normal_reg <= k_normal_next;
			k_press_reg <= k_press_next;
		end if;
	end process;
	
	process(state_reg, key_reg, k_normal_reg, k_press_reg, rx_done_tick, dout)
	begin
		state_next <= state_reg;
		key_next <= key_reg;
		k_normal_next <= k_normal_reg;
		k_press_next <= k_press_reg;
		k_done_tick <= '0';
		
		case(state_reg) is
			when idle => 
				if rx_done_tick = '1' then
					if dout = E0 then
						k_normal_next <= '0';
						state_next <= extended;
					else 
						k_normal_next <= '1';
						if dout = F0 then
							k_press_next <= '0';
							state_next <= released;
						else
							k_press_next <= '1';
							key_next <= dout;
							state_next <= done;
						end if;
					end if;
				end if;
		    when released =>
                if rx_done_tick = '1' then
                    key_next <= dout;
                    state_next <= done;
                end if;
			when extended =>
				if rx_done_tick = '1' then
					if dout = F0 then
						k_press_next <= '0';
						state_next <= released;
					else
						k_press_next <= '1';
						key_next <= dout;
						state_next <= done;
					end if;
				end if;
			when done =>
				k_done_tick <= '1';
				state_next <= idle; 
		end case;
	end process;
	
	k_press <= k_press_reg;
	k_normal <= k_normal_reg;
	key <= key_reg;
end Behavioral;

