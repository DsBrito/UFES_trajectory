----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:58:26 10/12/2020 
-- Design Name: 
-- Module Name:    prog_prior_encoder - Behavioral 
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
library ieee;
use ieee.std_logic_1164.ALL;

entity prog_prior_encoder is
    Port ( r : in  std_logic_vector (7 downto 0);
           c : in  std_logic_vector (2 downto 0);
           code : out  std_logic_vector (2 downto 0);
           active : out  std_logic);
end prog_prior_encoder;

architecture behavioral of prog_prior_encoder is
	signal mask, lower_r, upper_r : std_logic_vector (7 downto 0);
   signal lower_code, upper_code: std_logic_vector (2 downto 0);
   signal lower_active : std_logic;        
begin
--==================
-- Criar bloco que gera mask
--==================


with c select
	mask <=	"00000001" when "000",
				"00000011" when "001",
				"00000111" when "010",
				"00001111" when "011",
				"00011111" when "100",
				"00111111" when "101",
				"01111111" when "110",
				"11111111" when others;

--==================
-- Criar bloco que gera lower_r
--==================
 lower_r <= r and mask; 

--==================
-- Criar bloco que gera upper_r
--==================
 upper_r <= r and (not mask);
 
--==================
-- Criar bloco que gera o codificador de prioridade fixa superior
-- que gera upper_code usando os códigos descritos na aula 10 
--==================
upper_code <=	"111" when upper_r(7)= '1' else
					"110" when upper_r(6)= '1' else
					"101" when upper_r(5)= '1' else
					"100" when upper_r(4)= '1' else
					"011" when upper_r(3)= '1' else
					"010" when upper_r(2)= '1' else
					"001" when upper_r(1)= '1' else
					"000";

--==================
-- Criar bloco que gera o codificador de prioridade fixa inferior
-- que gera lower_code usando os códigos descritos na aula 10 
--==================

lower_code <=	"111" when lower_r(7)= '1' else
					"110" when lower_r(6)= '1' else
					"101" when lower_r(5)= '1' else
					"100" when lower_r(4)= '1' else
					"011" when lower_r(3)= '1' else
					"010" when lower_r(2)= '1' else
					"001" when lower_r(1)= '1' else
					"000";






--==================
-- Criar bloco que gera o lower_active 
--==================
	lower_active <= lower_r(7) or lower_r(6) or
                   lower_r(5) or lower_r(4) or 
						 lower_r(3) or lower_r(2) or 
						 lower_r(1) or lower_r(0);
						
--==================
-- Criar bloco MUX 2:1 de 3 bits para gerar code
--==================

code <=	lower_code when lower_active='1' else
			upper_code;


			 
--==================
-- Criar bloco que gera a saída active 
--==================

active <=	r(7) or r(6) or r(5) or r(4) or
				r(3) or r(2) or r(1) or r(0); 


				
end behavioral;

