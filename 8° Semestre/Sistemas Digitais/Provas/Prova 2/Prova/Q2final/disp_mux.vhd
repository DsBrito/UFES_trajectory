library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity disp_mux is
   port(
      clk   : in  std_logic;
      reset : in  std_logic;
      in0   : in  std_logic_vector(7 downto 0);
      in1   : in  std_logic_vector(7 downto 0);
      in2   : in  std_logic_vector(7 downto 0);
      in3   : in  std_logic_vector(7 downto 0);
      an    : out std_logic_vector(3 downto 0);
      sseg  : out std_logic_vector(7 downto 0)
   );
end disp_mux;

architecture arch of disp_mux is
   -- refreshing rate around 1600 Hz (100MHz/2^16)
   constant N    : integer := 18;
   signal q_reg  : unsigned(N-1 downto 0);
   signal q_next : unsigned(N-1 downto 0);
   signal sel    : std_logic_vector(1 downto 0);
begin
   -- register
   process(clk, reset)
   begin
      if reset = '1' then
         q_reg <= (others => '0');
      elsif (clk'event and clk = '1') then
         q_reg <= q_next;
      end if;
   end process;
   -- next-state logic for the counter
   q_next <= q_reg + 1;
   -- 2 MSBs of counter to control 4-to-1 multiplexing
   -- and to generate active-low enable signal
   sel <= std_logic_vector(q_reg(N-1 downto N-2));
   process(sel, in0, in1, in2, in3)
   begin
      case sel is
         when "00" =>
            an(3 downto 0) <= "1110";
            sseg           <= in0;
         when "01" =>
            an(3 downto 0) <= "1101";
            sseg           <= in1;
         when "10" =>
            an(3 downto 0) <= "1011";
            sseg           <= in2;
         when others =>
            an(3 downto 0) <= "0111";
            sseg           <= in3;
      end case;
   end process;
end arch;