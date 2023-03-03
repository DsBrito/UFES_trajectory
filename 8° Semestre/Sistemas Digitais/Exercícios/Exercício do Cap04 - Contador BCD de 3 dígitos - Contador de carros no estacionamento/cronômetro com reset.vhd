--===================================
-- Listing 4.18 modificada
--===================================
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity stop_watch is
   port(
      clk, reset: in std_logic;
      go, clr: in std_logic;
      d2, d1, d0: out std_logic_vector(3 downto 0)
   );
end stop_watch;

--===================================
-- 
--===================================
architecture if_arch of stop_watch is
   constant DVSR: integer:=5000000;
   signal ms_reg, ms_next: unsigned(22 downto 0);
   signal d2_reg, d1_reg, d0_reg: unsigned(3 downto 0);
   signal d2_next, d1_next, d0_next: unsigned(3 downto 0);
   signal ms_tick: std_logic;
begin
   -- register
   process(clk, reset)
   begin
		if reset = '1' then
         ms_reg <= (others=> '0');
         d2_reg <= (others=> '0');
         d1_reg <= (others=> '0');
         d0_reg <= (others=> '0');
      elsif (clk'event and clk='1') then
         ms_reg <= ms_next;
         d2_reg <= d2_next;
         d1_reg <= d1_next;
         d0_reg <= d0_next;
      end if;
   end process;

   -- next-state logic
   -- 0.1 sec tick generator: mod-5000000
   ms_next <=
      (others=>'0') when clr='1' or
                        (ms_reg=DVSR and go='1') else
      ms_reg + 1 when go='1' else
      ms_reg;
   ms_tick <= '1' when ms_reg=DVSR else '0';
   -- 0.1 sec counter
   process(d0_reg,d1_reg,d2_reg,ms_tick,clr)
   begin
      -- defult
      d0_next <= d0_reg;
      d1_next <= d1_reg;
      d2_next <= d2_reg;
      if clr='1' then
         d0_next <= "0000";
         d1_next <= "0000";
         d2_next <= "0000";
      elsif ms_tick='1' then
         if (d0_reg/=9) then
            d0_next <= d0_reg + 1;
         else       -- reach XX9
            d0_next <= "0000";
            if (d1_reg/=9) then
               d1_next <= d1_reg + 1;
            else    -- reach X99
               d1_next <= "0000";
               if (d2_reg/=9) then
                  d2_next <= d2_reg + 1;
               else -- reach 999
                  d2_next <= "0000";
               end if;
            end if;
         end if;
      end if;
   end process;
   -- output logic
   d0 <= std_logic_vector(d0_reg);
   d1 <= std_logic_vector(d1_reg);
   d2 <= std_logic_vector(d2_reg);
end if_arch;


