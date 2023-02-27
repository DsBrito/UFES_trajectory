-- Estes códigos foram retirados do livro RTL Hardware Design
-- e modificados para fazer instanciação de acordo com VHDL 93
--=============================
-- Listing 2.1 Even detector
--=============================
library ieee;
use ieee.std_logic_1164.all;

-- entity declaration
entity even_detector is
   port(
      a: in std_logic_vector(2 downto 0);
      even: out std_logic
   );
end even_detector;


--=============================
-- Listing 2.3
--=============================
architecture str_arch of even_detector is
   signal sig1,sig2: std_logic;
begin
   -- instantiation of the 1st xor instance
   unit1: entity work.my_xor2 (beh_arch)
      port map (i1 => a(0), i2 => a(1), o1 => sig1);
   -- instantiation of the 2nd xor instance
   unit2: entity work.my_xor2 (beh_arch)
      port map (i1 => sig1, i2 => a(2), o1 => sig2);
   -- instantiation of invertor
   unit3: entity work.not1 (beh_arch)
      port map (i1 => sig2, o1 => even);
end str_arch;
