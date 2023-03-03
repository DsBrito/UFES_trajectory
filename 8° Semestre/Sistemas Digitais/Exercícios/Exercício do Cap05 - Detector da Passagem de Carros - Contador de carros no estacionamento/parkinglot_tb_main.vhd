
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity stop_watch is
   port(
      clk, reset: in std_logic;
      inc1, dec1: in std_logic;
		inc2, dec2: in std_logic;
      d2, d1, d0: out std_logic_vector(3 downto 0)
   );
end stop_watch;

architecture if_arch of stop_watch is

   signal d2_reg, d1_reg, d0_reg: unsigned(3 downto 0);
   signal d2_next, d1_next, d0_next: unsigned(3 downto 0);
	signal inc: std_logic_vector(1 downto 0);
	signal dec: std_logic_vector(1 downto 0);
begin

	inc <= inc1 & inc2;
	dec <= dec1 & dec2;
   -- register
   process(clk,reset)
   begin
		if reset='1' then
			d2_reg <= (others=>'0');
			d1_reg <= (others=>'0');
			d0_reg <= (others=>'0');
      elsif (clk'event and clk='0') then
         d2_reg <= d2_next;
         d1_reg <= d1_next;
         d0_reg <= d0_next;
      end if;
   end process;
	

   process(d0_reg,d1_reg,d2_reg,inc,dec,reset)
   begin
      -- defult
      d0_next <= d0_reg;
      d1_next <= d1_reg;
      d2_next <= d2_reg;
      if reset='1' then
         d0_next <= "0000";
         d1_next <= "0000";
         d2_next <= "0000";
      elsif ((inc="10" and dec="00")  or (inc="01" and dec="00")) then
         if (d0_reg/=9) then
            d0_next <= d0_reg + 1;
         else         -- alcança XX9 (unidade)
            d0_next <= "0000";
            if (d1_reg/=9) then
               d1_next <= d1_reg + 1;
            else      -- alcança X99 (dezena)
               d1_next <= "0000";
               if (d2_reg/=9) then
                  d2_next <= d2_reg + 1;
               else    -- alcança 999 (centenza)
                  d2_next <= "0000";
               end if;
            end if;
         end if;
		elsif (inc="11") then
		 if (d0_reg/=9 and d0_reg/=8) then
            d0_next <= d0_reg + 2;
			elsif(d0_reg=9) then         -- alcança XX9 (unidade)
				d0_next <= "0001";
				if (d1_reg/=9) then
					d1_next <= d1_reg + 1;
				else
					d1_next <= "0000";
					if (d2_reg/=9) then
						d2_next <= d2_reg + 1;
					else
						d2_next <= "0000";
					end if;
				end if;	
			elsif(d0_reg=8) then
				d0_next <= "0000";
            if (d1_reg/=9) then
					d1_next <= d1_reg + 1;
				else
					d1_next <= "0000";
               if (d2_reg/=9) then
						d2_next <= d2_reg + 1;
					else
						d2_next <= "0000";
               end if;
            end if;
         end if;
		elsif ((dec="10" and inc="00") or (dec="01" and inc="00")) then
         if (d0_reg/=0) then
            d0_next <= d0_reg - 1;
         else         -- alcança XX9 (unidade)
            d0_next <= "1001";
            if (d1_reg/=0) then
               d1_next <= d1_reg - 1;
            else      -- alcança X99 (dezena)
               d1_next <= "1001";
               if (d2_reg/=0) then
                  d2_next <= d2_reg - 1;
               else   -- alcança 999 (centena)
                  d2_next <= "1001";
               end if;
            end if;
         end if;
		elsif (dec="11") then 
         if (d0_reg/=1 and d0_reg/=0) then
            d0_next <= d0_reg - 2;
			elsif(d0_reg=1) then        -- alcança XX9 (unidade)
				d0_next <= "1001";
				if (d1_reg/=0) then
					d1_next <= d1_reg - 1;
				else
					d1_next <= "1001";
					if (d2_reg/=0) then
						d2_next <= d2_reg - 1;
					else
						d2_next <= "1001";
					end if;
				end if;	
			elsif(d0_reg=0) then
				d0_next <= "1000";
            if (d1_reg/=0) then
					d1_next <= d1_reg - 1;
				else
					d1_next <= "1001";
               if (d2_reg/=0) then
						d2_next <= d2_reg - 1;
					else
						d2_next <= "1001";
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