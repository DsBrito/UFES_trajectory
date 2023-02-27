library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity seq_mult is
   port(
      clk, reset: in std_logic;
      start: in std_logic;
      a_in, b_in: in std_logic_vector(7 downto 0);
      ready: out std_logic;
      r: out std_logic_vector(15 downto 0)
   );
end seq_mult;
architecture shift_add_arch of seq_mult is
   constant WIDTH: integer:=8;
   constant C_WIDTH: integer:=4; -- width of the counter
   constant C_INIT: unsigned(C_WIDTH-1 downto 0):="1000";
   type state_type is (idle, add, shift);
   signal state_reg, state_next: state_type;
   signal b_reg, b_next: unsigned(WIDTH-1 downto 0);
   signal a_reg, a_next: unsigned(2*WIDTH-1 downto 0);
   signal n_reg, n_next: unsigned(C_WIDTH-1 downto 0);
   signal p_reg, p_next: unsigned(2*WIDTH-1 downto 0);
begin
  -- state and data registers
   process(clk,reset)
   begin
      if reset='1' then
         state_reg <= idle;
         b_reg <= (others=>'0');
         a_reg <= (others=>'0');
         n_reg <= (others=>'0');
         p_reg <= (others=>'0');
      elsif (clk'event and clk='1') then
         state_reg <= state_next;
         b_reg <= b_next;
         a_reg <= a_next;
         n_reg <= n_next;
         p_reg <= p_next;
      end if;
   end process;
   -- combinational circuit     
   process(start,state_reg,b_reg,a_reg,n_reg,p_reg,
           b_in,a_in,n_next,a_next)
   begin
      b_next <= b_reg;
      a_next <= a_reg;
      n_next <= n_reg;
      p_next <= p_reg;
      ready <='0';
      case state_reg is
         when idle =>
            if start='1' then
               b_next <= unsigned(b_in);
               a_next <= "00000000" & unsigned(a_in);
               n_next <= C_INIT;
               p_next <= (others=>'0');
               if b_in(0)='1' then
                  state_next <= add;
               else
                  state_next <= shift;
               end if;
            else
               state_next <= idle;
            end if;
            ready <='1';
         when add =>
            p_next <= p_reg + a_reg;
            state_next <= shift;
         when shift =>
            n_next <= n_reg - 1;
            b_next <= '0' & b_reg (WIDTH-1 downto 1);
            a_next <= a_reg(2*WIDTH-2 downto 0) & '0';
            if (n_next /= "0000") then
               if b_next(0)='1' then
                  state_next <= add;
               else
                  state_next <= shift;
               end if;
            else
               state_next <= idle;
            end if;
      end case;
   end process;
   r <= std_logic_vector(p_reg);
end shift_add_arch;
