
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;


entity car_detect is
	port(
		clk, reset: in std_logic;
		a, b: in std_logic;
		car_in, car_out: out std_logic
	);
end car_detect;

architecture arch of car_detect is
	type eg_state_type is (s0,s1,s2,s3,s4,s5,s6);
	signal state_reg, state_next: eg_state_type;
begin
	
	process(clk, reset)
		begin
			if(reset='1') then
				state_reg<= s0;
			elsif(clk'event and clk='1') then
				state_reg<=state_next;
			end if;
	end process;

	process(state_reg, a, b)
	begin
		
		car_in<='0';
		car_out<='0';

		case state_reg is
			when s0=>
				if(a='1') then
					if(b='1') then
						state_next<=s0;
					else
						state_next<=s1;
					end if;
				else
					if(b='1') then
						state_next<=s4;
					else
						state_next<=s0;
					end if;
				end if;
			when s1=>
				if(a='1') then
					if(b='1') then
						state_next<=s2;
					else
						state_next<=s1;
					end if;
				else
					state_next<=s0;
				end if;
			when s2=>
				if(b='1') then
					if(a='1') then
						state_next<=s2;
					else
						state_next<=s3;
					end if;
				else
					state_next<=s1;
				end if;
			when s3=>
				if(a='1') then
					state_next<=s2;
				else
					if(b='1') then
						state_next<=s3;
					else
						state_next<=s0;
						car_in<='1';
					end if;
				end if;
			when s4=>
				if(a='1') then
					state_next<=s5;
				else
					if(b='1') then
						state_next<=s4;
					else
						state_next<=s0;
					end if;
				end if;
			when s5=> 
				if(b='1') then
					if(a='1') then
						state_next<=s5;
					else
						state_next<=s4;
					end if;
				else
					state_next<=s6;
				end if;
			when s6=>
				if(a='1') then
					if(b='1') then
						state_next<=s5;
					else
						state_next<=s6;
					end if;
				else
					state_next<=s0;
					car_out<='1';
				end if;
		end case;
	end process;

end arch;

