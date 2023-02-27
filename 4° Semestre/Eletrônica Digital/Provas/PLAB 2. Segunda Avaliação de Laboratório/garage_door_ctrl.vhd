----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:36:07 12/10/2020 
-- Design Name: 
-- Module Name:    garage_door_ctrl - Behavioral 
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
--								como entrada:	A -> completamente aberto
--											   	F -> completamente fechado
--													SI -> sensor interno
--													SE -> sensor externo
--													IV -> receptor infravermelho (ativo quando abre o portão)
--													Tic -> verifica contador (se chegou no final ou não)

--								como saída:		Start -> começa contagem
--													L -> sinal luminoso
--													Motor -> (codificado)


--#Explicação:
--					Irá começar fechado
--					caso o sensor infravermelho detectar o comando para abrir, o portão será aberto.
--					se não detectar nada, continuará fechado.
--					uma vez detectado o comando para abrir, o Tic ira verificar se o contador chegou ao final ou não.
--					quando o comando for para fechar, o portão irá fechar apenas se os sensores internos e externos não detectarem algum objeto


--#Codificação:
--				
--					motor parado/travado - m1'm0' = 00
--								abrir portão - m1'm0 = 01		
--								fechar porão - m1m0' = 10
--								 não definido - m1m0 = 11

--#Implementação:

-- criando as entradas e saída


entity garage_door_ctrl is
	Port(
		clk,reset: in STD_LOGIC;
		IV: in STD_LOGIC;
		SI,SE: in STD_LOGIC;
		Tick: in STD_LOGIC;
		A,F: in STD_LOGIC;
		L,start: out STD_LOGIC;
		m: out STD_LOGIC_VECTOR (1 downto 0)
		);
end garage_door_ctrl;

architecture Behavioral of garage_door_ctrl is
	type eg_state_type is (aberto, abrindo, fechado, fechando, tempo);
	signal state_reg, state_next : eg_state_type;
begin

	process(clk, reset)
	begin
		if(reset = '1') then   		-- o portão irá começar fechado
			state_reg <= fechado;
		elsif (clk'event and clk = '1') then
			state_reg <= state_next;
		end if;
	end process;
	
	process(state_reg, Tick, IV, SI, SE, A, F)
	begin
		case state_reg is         
			when fechado =>			-- portão se encontra frchado e se receptor ativar, significa que um comando para abrir o porão foi solicidato.
				if (IV = '1') then
					state_next <= abrindo;
				else
					state_next <= fechado; -- se não detectar comando para abrir, irá continuar fechado
				end if;
				
			when abrindo =>
				if (A = '1')then          -- A = 1 = completamente aberto
					state_next <= aberto;
				else
					state_next <= abrindo; -- o porão irá continuar abrindo até que seja completamente aberto, caindo na primeira condição
				end if;
				
			when aberto =>
				if Tick = '1' then   -- se o contador chegou ao final, deve esperar um tempo ate que seja dado o comando de fechar
					state_next <= tempo;
				else
					state_next <= aberto; -- se nao chegou, deve continuar aberto.
				end if;
				
			when tempo =>    
				if (not(SI = '1' or SE = '1'))then -- so irá fechar, se não for detectado algum obstáculo externo ou interno pelos sensores
					state_next <= fechando;
				else
					state_next <= tempo;  -- caso for encontrado, o portão deve permanecer aberto e esperar o tempo para o próximo comando
				end if;
				
			when fechando =>
				if F = '1' then   
					state_next <= fechado; 
				elsif ((not F = '1')and((SE = '1')or(SI = '1'))) then -- se em algum momento do fechamento do portão os sensores detectarem algo, o portao irá começar a abrir
					state_next <= abrindo;
				else
					state_next <= fechando;
				end if;
		end case;
	end process;
	
-- prcess para o estado registrado (codificação)

	process(state_reg)
	begin
		case state_reg is
			when tempo =>
				L <= '1';
				m <= "00";
				start <= '0';
				
				
			when abrindo =>
				L <= '1';
				m <= "01";
				start <= '1';
			when aberto =>
				L <= '1';
				m <= "00";
				start <= '0';
				
		
			when fechando =>
				L <= '1';
				m <= "10";
				start <= '0';
			when fechado =>  
				L <= '0';
				m <= "00";
				start <= '0';
				
			-- o códio m1m0 = 11 não irá ser usado porque não e definido.	
		end case;
	end process;



end Behavioral;

