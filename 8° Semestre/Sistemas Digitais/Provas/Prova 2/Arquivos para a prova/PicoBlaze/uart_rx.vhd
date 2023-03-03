library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart_rx is
   generic(
      DBIT    : integer := 8;    -- # data bits
      SB_TICK : integer := 16    -- # ticks for stop bits
   );
   port(
      clk, reset   : in  std_logic;
      rx           : in  std_logic;
      s_tick       : in  std_logic;
      rx_done_tick : out std_logic;
      dout         : out std_logic_vector(7 downto 0)
   );
end uart_rx;

architecture arch of uart_rx is
   type state_type is (idle, start, data, stop);
   signal state_reg     : state_type;
   signal state_next    : state_type;
   signal s_reg, s_next : unsigned(4 downto 0);
   signal n_reg, n_next : unsigned(2 downto 0);
   signal b_reg, b_next : std_logic_vector(7 downto 0);
   signal sync1_reg     : std_logic;
   signal sync2_reg     : std_logic;
   signal sync_rx       : std_logic;

begin
   -- synchronization for rx
   process(clk, reset)
   begin
      if reset = '1' then
         sync1_reg <= '0';
         sync2_reg <= '0';
      elsif (clk'event and clk = '1') then
         sync1_reg <= rx;
         sync2_reg <= sync1_reg;
      end if;
   end process;
   sync_rx <= sync2_reg;
   -- FSMD state & data registers
   process(clk, reset)
   begin
      if reset = '1' then
         state_reg <= idle;
         s_reg     <= (others => '0');
         n_reg     <= (others => '0');
         b_reg     <= (others => '0');
      elsif (clk'event and clk = '1') then
         state_reg <= state_next;
         s_reg     <= s_next;
         n_reg     <= n_next;
         b_reg     <= b_next;
      end if;
   end process;
   -- next-state logic & data path 
   process(state_reg, s_reg, n_reg, b_reg, s_tick, sync_rx)
   begin
      state_next   <= state_reg;
      s_next       <= s_reg;
      n_next       <= n_reg;
      b_next       <= b_reg;
      rx_done_tick <= '0';
      case state_reg is
         when idle =>
            if sync_rx = '0' then
               state_next <= start;
               s_next     <= (others => '0');
            end if;
         when start =>
            if (s_tick = '1') then
               if s_reg = 7 then
                  state_next <= data;
                  s_next     <= (others => '0');
                  n_next     <= (others => '0');
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when data =>
            if (s_tick = '1') then
               if s_reg = 15 then
                  s_next <= (others => '0');
                  b_next <= sync_rx & b_reg(7 downto 1);
                  if n_reg = (DBIT - 1) then
                     state_next <= stop;
                  else
                     n_next <= n_reg + 1;
                  end if;
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
         when stop =>
            if (s_tick = '1') then
               if s_reg = (SB_TICK - 1) then
                  state_next   <= idle;
                  rx_done_tick <= '1';
               else
                  s_next <= s_reg + 1;
               end if;
            end if;
      end case;
   end process;
   dout <= b_reg;
end arch;