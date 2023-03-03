--retirado do cap 4.11
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity mod_m_counter is
   port(
      clk, reset: in std_logic;
		m: in std_logic_vector(11 downto 0);
      max_tick: out std_logic;
      q: out std_logic_vector(11 downto 0)
   );
end mod_m_counter;

architecture arch of mod_m_counter is
	constant N:integer :=12;
   signal r_reg: unsigned(N-1 downto 0);
   signal r_next, r_inc: unsigned(N-1 downto 0);
begin
   -- register
   process(clk,reset)
   begin
      if (reset='1') then
         r_reg <= (others=>'0');
      elsif (clk'event and clk='1') then
         r_reg <= r_next;
      end if;
   end process;
   -- next-state logic
	r_inc<= r_reg+1;
   r_next <= (others=>'0') when r_inc=unsigned(m) else
             r_inc;
   -- output logic
   q <= std_logic_vector(r_reg);
   max_tick <= '1' when r_reg=(unsigned(m)-1) else '0';
end arch;