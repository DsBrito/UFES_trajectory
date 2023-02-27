-- TestBench Johnsons
--=====================================================================================
--> Dionatas
--=====================================================================================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity johnsons_counter_8bits is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
			  enable: in STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (7 downto 0));
end johnsons_counter_8bits;

architecture Behavioral of johnsons_counter_8bits is
	signal count_reg: STD_LOGIC_VECTOR(7 downto 0);
begin

---------------------------------------------------------------------------------------------
--> Descrevendo a arquitetura para gerar a contagem seguindo a tabela quando enable = '1'
---------------------------------------------------------------------------------------------
process(clk, reset, enable, count_reg)
    begin 
		if(reset = '1') then
---------------------------------------------------------------------------------------------
--> Dando RESET/Usando a tabela do slide 3 como referência
---------------------------------------------------------------------------------------------
         count_reg <= "00000000";       
      elsif (clk'event and clk = '1' and enable = '1') then
---------------------------------------------------------------------------------------------
--> Deeslocando de 7 à 1 pela direita/Usando a tabela do slide 3 como referência
---------------------------------------------------------------------------------------------
         count_reg(6 downto 0) <= count_reg(7 downto 1);
---------------------------------------------------------------------------------------------
--> Invertendo o bit 0 e colocando na posião 7/Usando a tabela do slide 3 como referência
---------------------------------------------------------------------------------------------
			count_reg(7) <= not count_reg(0);
			
      end if;                      
    count <= count_reg;
    end process;
end Behavioral;

