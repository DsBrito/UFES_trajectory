library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity g_inc is
   port(
      g: in std_logic_vector(3 downto 0);
      g1: out std_logic_vector(3 downto 0)
   );
end g_inc ;

architecture direct_arch of g_inc is
begin
   with g select
      g1 <= "0001" when "0000",
            "0011" when "0001",
            "0010" when "0011",
            "0110" when "0010",
            "0111" when "0110",
            "0101" when "0111",
            "0100" when "0101",
            "1100" when "0100",
            "1101" when "1100",
            "1111" when "1101",
            "1110" when "1111",
            "1010" when "1110",
            "1011" when "1010",
            "1001" when "1011",
            "1000" when "1001",
            "0000" when others; -- "1000"
end direct_arch;

architecture indirect_arch of g_inc is
-- crie aqui os sinais intermediários que recebem os resultados de cada nível
	constant CONSTANTE: integer := 4;
	signal binario, binario_encremento: std_logic_vector(CONSTANTE-1 downto 0);

begin
	--1 passo -> Converter o código Gray para binário
   -- primeiro nível, conversão de Gray para binário
	
		binario<= g xor ('0' & binario(CONSTANTE-1 downto 1));
		
		
	--2 passo ->Incrementar o código binário
   -- segundo nível, incrementador binário
		
		binario_encremento<= std_logic_vector((unsigned(binario)) +1);
	


	--3 passo -> Converter o resultado de volta para o código Gray
   -- terceiro nível, conversão de binário para Gray

		g1<= binario_encremento xor ('0'& binario_encremento(CONSTANTE-1 downto 1));

end indirect_arch;

