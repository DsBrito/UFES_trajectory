
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
entity mult_seq is
	generic (N: natural := 8;--número de bits dos operandos
	         W: natural := 4 --número de bits para contar de 0 a N-1 
				);	
    Port  (clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           start : std_logic;
			  xin : in  STD_LOGIC_VECTOR (N-1 downto 0);
           yin : in  STD_LOGIC_VECTOR (N-1 downto 0);
           zout : out  STD_LOGIC_VECTOR (2*N-1 downto 0);
           done, idle : out  STD_LOGIC);
end mult_seq;

architecture Behavioral of mult_seq is
	type state_type is (s_idle, s_mult, s_done);
	signal state_reg, state_next: state_type;
	signal count_reg, count_next: unsigned(W-1 downto 0);
	signal x_reg, x_next: unsigned(N-1 downto 0);
	signal y_reg, y_next: unsigned(N-1 downto 0);
	signal z_reg, z_next: unsigned(2*N-1 downto 0);
	alias z_left: unsigned(N-1 downto 0) is z_reg (2*N-1 downto N);
	signal sum: unsigned(N downto 0);
	signal x_and_y0: unsigned(N-1 downto 0);
	
begin
	process(clk, reset)
	begin
		if reset = '1' then
			state_reg <= s_idle;
			x_reg <= (others => '0');
			y_reg <= (others => '0');
			z_reg <= (others => '0');
			count_reg <= (others => '0');
		elsif clk' event and clk = '1' then
			state_reg <= state_next;
			x_reg <= x_next;
			y_reg <= y_next;
			z_reg <= z_next;
			count_reg <= count_next;
		end if;
	end process;
	x_and_y0 <= x_reg when y_reg(0) = '1' else
					(others=> '0');
	sum <= ('0' & x_and_y0) + ('0' & z_left);
	process(state_reg, x_reg, y_reg, z_reg, count_reg, xin, yin, start,sum)
	begin
		--valores default
		state_next <= state_reg;
		x_next <= x_reg;
		y_next <= y_reg;
		z_next <= z_reg;
		count_next <= count_reg;
		done <= '0';
		idle <= '0';
		case state_reg is
			when s_idle => 
				idle <= '1';
				if start = '1' then
					x_next <= unsigned(xin);
					y_next <= unsigned(yin);
					z_next <= (others=> '0');
					count_next <= to_unsigned(N,W);
					state_next <= s_mult;
				end if;
			when s_mult => 
				z_next <= sum & z_reg(N-1 downto 1);
				y_next <= '0' & y_reg(N-1 downto 1);
				count_next <= count_reg - 1;
				if count_next = 0 then
					state_next <= s_done;
				end if;
			when s_done => 
				done <= '1';
				state_next <= s_idle;
		end case;
	end process;
	zout <= std_logic_vector(z_reg);
end Behavioral;

