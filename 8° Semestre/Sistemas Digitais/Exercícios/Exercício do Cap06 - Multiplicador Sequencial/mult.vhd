
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


use IEEE.NUMERIC_STD.ALL;



entity mult is
	generic(
		N: integer:=8
	);
	port(
		clk, reset, start: in std_logic;
		x_in, y_in: in std_logic_vector(N-1 downto 0);
		result: out std_logic_vector(2*N-1 downto 0);
		ready, done: out std_logic
	);
end mult;

architecture arch_mult of mult is

	
	signal x_reg, y_reg, x_next, y_next: unsigned(N-1 downto 0);
	signal a_ext, b_ext: unsigned(N downto 0);
	signal sum_ext: std_logic_vector(N downto 0);
	signal z_reg, z_next: unsigned(2*N-1 downto 0);
	signal and_out: unsigned(N-1 downto 0);
	type state_type is (idle_1, calc);
	signal count_reg, count_next: unsigned(3 downto 0);
	signal state_reg, state_next: state_type;
	signal done_reg, done_next, ready_reg, ready_next: std_logic;
	
begin

process(clk, reset)
begin
	if(reset='1') then
		state_reg <= idle_1;
		x_reg<=(others=>'0');
		y_reg<=(others=>'0');
		z_reg<=(others=>'0');
		ready_reg<='0';
		done_reg<='0';
		count_reg<=(others=>'0');
	elsif(clk'event and clk='1') then
		state_reg<= state_next;
		x_reg<=x_next;
		y_reg<=y_next;
		z_reg<=z_next;
		ready_reg<=ready_next;
		done_reg<=done_next;
		count_reg<=count_next;
	end if;
end process;
		--
process(count_reg,state_reg, start, x_in, y_in, 
			 z_reg, x_reg, y_reg, ready_reg, done_reg, 
			 sum_ext)
begin
	state_next<=state_reg;
	x_next<=x_reg;
	y_next<=y_reg;
	z_next<=z_reg;
	done_next<=done_reg;
	ready_next<=ready_reg;
	count_next<=count_reg;
	
	case state_reg is
		when idle_1=>
			ready_next<='1';
			if(start='1') then
				x_next<=unsigned(x_in);
				y_next<=unsigned(y_in);
				z_next<=(others=>'0');
				count_next<=(others=>'0');
				ready_next<='0';
				state_next<=calc;
			else
				
				state_next<=idle_1;
			end if;
		when calc=>
			done_next<='0';
			if(count_reg=8) then
				done_next<='0';
				state_next<=idle_1;
			else
				state_next<=calc;
				y_next<="0" & y_reg(N-1 downto 1);
				z_next<=unsigned(sum_ext) & z_reg(N-1 downto 1);
				count_next<=count_reg+1;
				if(count_reg=7) then
					done_next<='1';
					
				end if;
			end if;
	end case;
end process;

and_out<=(others=>'0') when y_reg(0)='0' else (x_reg);
a_ext<=unsigned('0' & and_out);
b_ext<=unsigned('0' & z_reg(2*N-1 downto N));
sum_ext<=std_logic_vector(a_ext + b_ext); 

result<=std_logic_vector(z_reg);
ready<=ready_reg;
done<=done_reg;

end arch_mult;

