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
--													IV -> receptor infravermelho (ativo quando abre o port�o)
--													Tic -> verifica contador (se chegou no final ou n�o)

--								como sa�da:		Start -> come�a contagem
--													L -> sinal luminoso
--													Motor -> (codificado)


--#Explica��o:
--					Ir� come�ar fechado
--					caso o sensor infravermelho detectar o comando para abrir, o port�o ser� aberto.
--					se n�o detectar nada, continuar� fechado.
--					uma vez detectado o comando para abrir, o Tic ira verificar se o contador chegou ao final ou n�o.
--					quando o comando for para fechar, o port�o ir� fechar apenas se os sensores internos e externos n�o detectarem algum objeto


--#Codifica��o:
--				
--					motor parado/travado - m1'm0' = 00
--								abrir port�o - m1'm0 = 01		
--								fechar por�o - m1m0' = 10
--								 n�o definido - m1m0 = 11

--#Implementa��o:

-- criando as entradas e sa�da


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
		if(reset = '1') then   		-- o port�o ir� come�ar fechado
			state_reg <= fechado;
		elsif (clk'event and clk = '1') then
			state_reg <= state_next;
		end if;
	end process;
	
	process(state_reg, Tick, IV, SI, SE, A, F)
	begin
		case state_reg is         
			when fechado =>			-- port�o se encontra frchado e se receptor ativar, significa que um comando para abrir o por�o foi solicidato.
				if (IV = '1') then
					state_next <= abrindo;
				else
					state_next <= fechado; -- se n�o detectar comando para abrir, ir� continuar fechado
				end if;
				
			when abrindo =>
				if (A = '1')then          -- A = 1 = completamente aberto
					state_next <= aberto;
				else
					state_next <= abrindo; -- o por�o ir� continuar abrindo at� que seja completamente aberto, caindo na primeira condi��o
				end if;
				
			when aberto =>
				if Tick = '1' then   -- se o contador chegou ao final, deve esperar um tempo ate que seja dado o comando de fechar
					state_next <= tempo;
				else
					state_next <= aberto; -- se nao chegou, deve continuar aberto.
				end if;
				
			when tempo =>    
				if (not(SI = '1' or SE = '1'))then -- so ir� fechar, se n�o for detectado algum obst�culo externo ou interno pelos sensores
					state_next <= fechando;
				else
					state_next <= tempo;  -- caso for encontrado, o port�o deve permanecer aberto e esperar o tempo para o pr�ximo comando
				end if;
				
			when fechando =>
				if F = '1' then   
					state_next <= fechado; 
				elsif ((not F = '1')and((SE = '1')or(SI = '1'))) then -- se em algum momento do fechamento do port�o os sensores detectarem algo, o portao ir� come�ar a abrir
					state_next <= abrindo;
				else
					state_next <= fechando;
				end if;
		end case;
	end process;
	
-- prcess para o estado registrado (codifica��o)

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
				
			-- o c�dio m1m0 = 11 n�o ir� ser usado porque n�o e definido.	
		end case;
	end process;



end Behavioral;

