----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:18:56 11/11/2020 
-- Design Name: 
-- Module Name:    fsm_top - Behavioral 
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
entity fsm is
    Port (  
			timer_tick: in STD_LOGIC;   -- sinal de entrada time adicionado
			clk : in  STD_LOGIC;
         reset : in  STD_LOGIC;
         letter : out  STD_LOGIC_VECTOR (7 downto 0);
         dig : out  STD_LOGIC_VECTOR (1 downto 0));
			  

end fsm;

architecture Behavioral of fsm is
	type eg_state_type is (s0,s1,s2,s3);        -- criação dos 4 estados s0/s1/s2/s3
	signal state_reg, state_next : eg_state_type;
begin

process(clk, reset) 
begin
	if (reset = '1') then
		state_reg <= s0;
	elsif (clk'event and clk='1') then
		state_reg <= state_next;
	end if;
end process;

process(state_reg, timer_tick) 
begin                                         -- Logica Combinacional da maquina de estados
	case state_reg is
		when s0 =>
			if timer_tick ='1' then
				state_next <=s1;
			else 
				state_next <=s0;
			end if;
		when s1 =>
			if timer_tick ='1' then
				state_next <=s2;
			else 
				state_next <=s1;
			end if;
		when s2 =>
			if timer_tick ='1' then
				state_next <=s3;
			else 
				state_next <=s2;
			end if;
		when s3 =>
			if timer_tick ='1' then
				state_next <=s0;
			else 
				state_next <=s3;
			end if;
	end case;
end process;


process(state_reg)
begin                             -- Letras escolhidas de acordo com o tb da professora
	case state_reg is
		when s0 =>
			letter <= "01010101"; --U
			dig <= "11";
		when s1 =>
			letter <= "01000110"; --F
			dig <= "10";
		when s2 => 
			letter <= "01000101"; --E
			dig  <= "01";
		when s3 =>
			letter <= "01010011"; --S
			dig  <= "00";
	end case;
end process;

end architecture;

