----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:28:26 12/11/2020 
-- Design Name: 
-- Module Name:    car_detect - Behavioral 
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



--#Pelo enunciado temos:
--								como entrada:	SI -> sinal interno
--											   	SE -> sinal externo

--								como saída:		INC -> incrementar a contagem
--													DEC -> decrementar a contagem
--#Explicação:
--					Entrada de um carro (incremento):
--												.Ativa o primeiro sensor-> SE
--												.Ativa o  primero e o segundo sensor-> SE.SI
--												.Ativa somente o segundo sensor-> SI

--					Saída de um carro (decremento):
--												.Ativa o segundo sensor-> SI
--												.Ativa o  segundo e o primeor sensor-> SI.SE
--												.Ativa somente o primeiro sensor-> SE
--
--#Codificação:
--					ENTRAR ->	SI'SE
--									 SISE	
--									 SISE'				
--									SI'SE'

--					  SAIR ->	 SISE'
--									 SISE	
--									SI'SE		
--									SI'SE'

--#Implementação:

-- criando as entradas e saída
entity car_detect is
		Port(
			clk : in  STD_LOGIC;
			reset : in  STD_LOGIC;
			SI: in STD_LOGIC;
			SE: in STD_LOGIC;
			inc: out STD_LOGIC;
			dec: out STD_LOGIC
		);
end car_detect;

-- criando sinais de controle
architecture Behavioral of car_detect is
	type eg_state_type is (s0,s1s0,s0e1,s1s1,s1e1,s0s1,s1e0,entrar,sair);
	signal state_reg, state_next : eg_state_type;
begin

-- criando process com o clock e reset
process(clk, reset)
	begin
		if(reset = '1') then
			state_reg <= s0; -- s0 sera registrado em state_reg
		elsif (clk'event and clk = '1') then
			state_reg <= state_next; -- proximo estado sera registrado em state_reg
		end if;
	end process;

-- criando proces com o estado registrado (state_reg) e os sensores internos e externo (SI e SE)	
	process(state_reg, SI, SE)
	begin
		case state_reg is
			when s0 =>  
				if (SI = '1' and SE = '0') then  -- SISE' = interno.externo' = saindo 
					state_next <= s1s0;
				elsif (SI = '0' and SE = '1') then  -- SI'SE = interno'.externo= entrando
					state_next <= s0e1;
				else
					state_next <= s0;
				end if;
				
			when s1s0 =>
				if (SI = '1' and SE = '1') then -- SISE = interno.externo= esta entre os dois sensoress (pode esta entrando ou saindo)
					state_next <= s1s1;
				elsif (SI = '0' and SE = '0') then -- SI'SE' = interno'.externo' = esta fora dos dois sensoress (pode ter entrado ou ter saído)
					state_next <= s0;
				else
					state_next <= s1s0;
				end if;
				
			when s0e1 =>
				if (SI = '1' and SE = '1') then -- SISE = interno.externo= esta entre os dois sensores (pode esta entrando ou saindo)
					state_next <= s1e1;
				elsif (SI = '0' and SE = '0') then -- SI'SE' = interno'.externo' = esta fora dos dois sensores (pode ter entrado ou ter saído)
					state_next <= s0;
				else
					state_next <= s0e1;
				end if;
				
			when s1s1=>
				if (SI = '0' and SE = '1') then -- SI'SE = interno'.externo= entrando
					state_next <= s0s1;
				elsif (SI = '1' and SE = '0') then -- SISE' = interno.externo' = saindo 
					state_next <= s1s0;
				else
					state_next <= s1s1;
				end if;
				
			when s1e1 =>
				if (SI = '1' and SE = '0') then -- SISE' = interno.externo' = saindo 
					state_next <= s1e0;
				elsif (SI = '0' and SE = '1') then -- SI'SE = interno'.externo= entrando
					state_next <= s0e1;
				else
					state_next <= s1e1;
				end if;
				
			when s0s1 =>
				if (SI = '0' and SE = '0') then  --  esta fora do alcance dos sensores, quando o sinal de controle for s0s1, o comando será para sair 
					state_next <= sair;
				elsif (SI = '1' and SE = '1') then -- SISE = interno.externo = esta entre os dois sensores
					state_next <= s1s1;
				else
					state_next <= s0s1;
				end if;
				
			when s1e0 =>                  
				if (SI = '0' and SE = '0') then --  esta fora do alcance dos sensores, quando o sinal de controle for s0s1, o comando será para entrar
					state_next <= entrar;
				elsif (SI = '1' and SE = '1') then -- SISE = interno.externo= esta entre os dois sensores
					state_next <= s1e1;
				else
					state_next <= s1e0;
				end if;
				
			when sair =>
				state_next <= s0; -- sinal de controle para sair 
				
			when entrar => -- sinal de controle para entrar
				state_next <= s0;
		end case;
		
	end process;
	
-- prcess para o estado registrado (codificação)
	process(state_reg)
	begin
		case state_reg is
			when s0 =>  
				inc <= '0';
				dec <= '0';
			when s1s0 => 
				inc <= '0';
				dec <= '0';
			when s0e1 => 
				inc <= '0';
				dec <= '0';
			when s1s1 => 
				inc <= '0';
				dec <= '0';
			when s1e1 =>
				inc <= '0';
				dec <= '0';			
			when s0s1 =>
				inc <= '0';
				dec <= '0';			
			when s1e0 => 
				inc <= '0';
				dec <= '0';
			when sair =>   -- irá decrementar -1 no registrador
				inc <= '0';
				dec <= '1';
			when entrar => -- irá incrementar +1 no registrador
				inc <= '1';
				dec <= '0';
		end case;
	end process;


end Behavioral;

