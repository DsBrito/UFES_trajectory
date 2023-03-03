--retirado do cap 7.3
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart_tx is
   port(
      clk, reset: in std_logic;
      tx_start: in std_logic;
		dnum, snum: in std_logic;
		par: std_logic_vector(1 downto 0);
      s_tick: in std_logic;
      din: in std_logic_vector(7 downto 0);
      tx_done_tick: out std_logic;
      tx: out std_logic
   );
end uart_tx ;

architecture arch of uart_tx is
   type state_type is (idle, start, data, parity, stop);
   signal state_reg, state_next: state_type;
   signal s_reg, s_next: unsigned(3 downto 0);
   signal n_reg, n_next: unsigned(2 downto 0);
   signal b_reg, b_next: std_logic_vector(7 downto 0);
   signal tx_reg, tx_next: std_logic;
	signal sb_tick: unsigned(5 downto 0);
	signal dbit: unsigned(3 downto 0);
	signal par_reg, par_next, par_get: std_logic;
begin
	dbit <= to_unsigned(7,4) when dnum='0' else
			  to_unsigned(8,4);
	sb_tick <= to_unsigned(16,6) when snum='0' else
				  to_unsigned(32,6);
	process(par, din, dnum)
	begin
		if dnum = '1' then --8 bits de dados 
			if par="01" then 
				-- paridade impar 
				par_get<= not(din(7) xor din(6) xor din(5) xor din(4) xor din(3) xor din(2) xor din(1) xor din(0));
			elsif par= "10" then
				-- paridade par 
				par_get<= din(7) xor din(6) xor din(5) xor din(4) xor din(3) xor din(2) xor din(1) xor din(0);
			else 
				par_get<='0';
			end if;
		else
			if par="01" then 
				-- paridade impar 
				par_get<= not(din(6) xor din(5) xor din(4) xor din(3) xor din(2) xor din(1) xor din(0));
			elsif par= "10" then
				-- paridade par 
				par_get<= din(6) xor din(5) xor din(4) xor din(3) xor din(2) xor din(1) xor din(0);
			else 
				par_get<= '0';
			end if;
		end if;
	end process;
   -- FSMD state & data registers
   process(clk,reset)
   begin
      if reset='1' then
         state_reg <= idle;
         s_reg <= (others=>'0');
         n_reg <= (others=>'0');
         b_reg <= (others=>'0');
			par_reg<='0';
         tx_reg <= '1';
      elsif (clk'event and clk='1') then
         state_reg <= state_next;
         s_reg <= s_next;
         n_reg <= n_next;
         b_reg <= b_next;
         tx_reg <= tx_next;
			par_reg <= par_next;
      end if;
   end process;
   -- next-state logic & data path functional units/routing
   process(state_reg,s_reg,n_reg,b_reg,s_tick,
           tx_reg,tx_start,din, par_reg, par_get, par)
   begin
      state_next <= state_reg;
      s_next <= s_reg;
      n_next <= n_reg;
      b_next <= b_reg;
      tx_next <= tx_reg;
		par_next<=par_reg;
      tx_done_tick <= '0';
      case state_reg is
         when idle =>
            tx_next <= '1';
            if tx_start='1' then
					s_next <= (others=>'0');
               b_next <= din;
					par_next<= par_get;
               state_next <= start;
            end if;
         when start =>
            tx_next <= '0';
            if (s_tick = '1') then
               if s_reg=15 then
                  state_next <= data;
                  s_next <= (others=>'0');
                  n_next <= (others=>'0');
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when data =>
            tx_next <= b_reg(0);
            if (s_tick = '1') then
               if s_reg=15 then
                  s_next <= (others=>'0');
                  b_next <= '0' & b_reg(7 downto 1) ;
                  if n_reg=(dbit-1) then
							if par="00" then
								state_next <= stop ;
							else
								state_next<= parity;
							end if;
                  else
                     n_next <= n_reg + 1;
                  end if;
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
			when parity =>
				tx_next<= par_reg;
            if (s_tick = '1') then
               if s_reg=15 then
                  s_next <= (others=>'0');
                  state_next <= stop ;
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when stop =>
            tx_next <= '1';
            if (s_tick = '1') then
               if s_reg=(sb_tick-1) then
                  state_next <= idle;
                  tx_done_tick <= '1';
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
      end case;
   end process;
   tx <= tx_reg;
end arch;
