-- Listing 9.5 modificada
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity mouse_led is
   port (
      clk, reset: in  std_logic;
      ps2d, ps2c: inout std_logic;
      led: out std_logic_vector(15 downto 0)
   );
end mouse_led;

architecture arch of mouse_led is
   signal p_reg, p_next: unsigned(9 downto 0);
   signal xm: std_logic_vector(8 downto 0);
   signal btnm: std_logic_vector(2 downto 0);
   signal m_done_tick: std_logic;

begin
   -- instantiation
   mouse_unit: entity work.mouse(arch)
      port map(clk=>clk, reset=>reset,
               ps2d=>ps2d, ps2c=>ps2c,
               xm=>xm, ym=>open, btnm=>btnm,
               m_done_tick=>m_done_tick);
   -- register
   process (clk, reset)
   begin
      if reset='1' then
         p_reg <= (others=>'0');
      elsif (clk'event and clk='1') then
         p_reg <= p_next;
      end if;
   end process;
   -- counter
   p_next <= p_reg when m_done_tick='0' else
             "0000000000" when btnm(1)='1' else --right button
             "1111111111" when btnm(0)='1' else --left button
             p_reg + unsigned(xm(8) & xm);

   with p_reg(9 downto 6) select
      led <= (0=>'1',others=>'0') when "0000",
             (1=>'1',others=>'0') when "0001", 
             (2=>'1',others=>'0') when "0010", 
             (3=>'1',others=>'0') when "0011", 
             (4=>'1',others=>'0') when "0100", 
             (5=>'1',others=>'0') when "0101", 
             (6=>'1',others=>'0') when "0110", 
             (7=>'1',others=>'0') when "0111", 
             (8=>'1',others=>'0') when  "1000", 
             (9=>'1',others=>'0') when  "1001", 
             (10=>'1',others=>'0') when "1010", 
             (11=>'1',others=>'0') when "1011", 
             (12=>'1',others=>'0') when "1100", 
             (13=>'1',others=>'0') when "1101", 
             (14=>'1',others=>'0') when "1110", 
             (15=>'1',others=>'0') when others;
end arch;