--retirado do cap 7.1
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart_rx is
   port(
      clk, reset: in std_logic;
		dnum, snum: in std_logic;
		par: in std_logic_vector(1 downto 0);
      rx: in std_logic;   
      s_tick: in std_logic;
		err: out std_logic_vector(1 downto 0);
      rx_done_tick: out std_logic;
      dout: out std_logic_vector(7 downto 0)
   );
end uart_rx ;

architecture arch of uart_rx is
   type state_type is (idle, start, data, parity, stop);
   signal state_reg, state_next: state_type;
   signal s_reg, s_next: unsigned(3 downto 0);
   signal n_reg, n_next: unsigned(2 downto 0);
   signal b_reg, b_next: std_logic_vector(7 downto 0);
	signal sb_tick: unsigned(5 downto 0);
	signal dbit: unsigned(3 downto 0);
	signal err_reg, err_next: std_logic_vector(1 downto 0);
	signal par_get, par_reg, par_next: std_logic;
begin
	--err_next<= err_reg; 
	
	dbit <= to_unsigned(7,4) when dnum='0' else
			  to_unsigned(8,4);
	sb_tick <= to_unsigned(16,6) when snum='0' else
				  to_unsigned(32,6);
	
	process(par,par_get, b_reg, dnum)
	begin
		if dnum = '1' then --8 bits de dados 
			if par="01" then 
				-- paridade impar 
				par_get<= not(b_reg(7) xor b_reg(6) xor b_reg(5) xor b_reg(4) xor b_reg(3) xor b_reg(2) xor b_reg(1) xor b_reg(0));
			elsif par= "10" then
				-- paridade par 
				par_get<= b_reg(7) xor b_reg(6) xor b_reg(5) xor b_reg(4) xor b_reg(3) xor b_reg(2) xor b_reg(1) xor b_reg(0);
			else
				par_get<='0';
			end if;
		else
			if par="01" then 
				-- paridade impar 
				par_get<= not(b_reg(6) xor b_reg(5) xor b_reg(4) xor b_reg(3) xor b_reg(2) xor b_reg(1) xor b_reg(0));
			elsif par= "10" then
				-- paridade par 
				par_get<= b_reg(6) xor b_reg(5) xor b_reg(4) xor b_reg(3) xor b_reg(2) xor b_reg(1) xor b_reg(0);
			else
				par_get<='0';
			end if;
		end if;
		--par_next<=par_get;
	end process;
	
   -- FSMD state & data registers
   process(clk,reset)
   begin
      if reset='1' then
         state_reg <= idle;
         s_reg <= (others=>'0');
         n_reg <= (others=>'0');
         b_reg <= (others=>'0');
			err_reg<= (others=>'0');
			par_reg<='0';
      elsif (clk'event and clk='1') then
         state_reg <= state_next;
         s_reg <= s_next;
         n_reg <= n_next;
         b_reg <= b_next;
			err_reg<= err_next;
			par_reg<=par_next;
      end if;
   end process;
   -- next-state logic & data path functional units/routing
   process(state_reg,s_reg,n_reg,b_reg,s_tick,rx, dbit, par, par_get, err_reg, par_reg)
   begin
      state_next <= state_reg;
      s_next <= s_reg;
      n_next <= n_reg;
      b_next <= b_reg;
		err_next<=err_reg;
      rx_done_tick <='0';
		par_next<=par_get;
		
      case state_reg is
         when idle =>
            if rx='0' then
               state_next <= start;
               s_next <= (others=>'0');
					--par_next<=par_reg;
            end if;
         when start =>
            if (s_tick = '1') then
               if s_reg=7 then
                  state_next <= data;
                  s_next <= (others=>'0');
                  n_next <= (others=>'0');
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when data =>
            if (s_tick = '1') then
               if s_reg=15 then
                  s_next <= (others=>'0');
                  b_next <= rx & b_reg(7 downto 1) ;
                  if n_reg=(dbit-1) then
							if dbit=7 then
								b_next<='0'& rx &b_reg(7 downto 2);
							end if;
							if par ="00" then
								state_next <= stop ;
							else
								par_next<=par_get;
								state_next<=parity;
							end if;
                  else
                     n_next <= n_reg + 1;
                  end if;
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
			when parity =>
				if (s_tick = '1') then
               if s_reg=15 then
                  s_next <= (others=>'0');
						if rx/= par_reg then
							err_next(0)<='1';
							--par_next<=par_get;
						else
							err_next(0)<='0';
						end if;	
						state_next <= stop ;
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when stop =>
            if (s_tick = '1') then
               if s_reg=15 then 
						if rx/='1' then
							err_next(1) <='1';
						else
							err_next(1) <='0';
						end if;
					end if;
					if s_reg=(sb_tick-1) then
                  state_next <= idle;
                  rx_done_tick <='1';
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
      end case;
   end process;
   dout <= b_reg;
	err<=err_reg;
	--par<=par_reg;
end arch;