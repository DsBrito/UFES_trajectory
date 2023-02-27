----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:26:40 11/29/2020 
-- Design Name: 
-- Module Name:    motor_ctrl - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity motor_ctrl is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           m : in  STD_LOGIC_VECTOR (1 downto 0);--01 abrir e 10 fechar, 00 parado
			  pos: out std_logic_vector(3 downto 0);-- (4 downto 0); --para contar de 0 até 31
           A : out  STD_LOGIC;
           F : out  STD_LOGIC);
end motor_ctrl;

architecture Behavioral of motor_ctrl is
	constant N: integer := 4;--16;--32;--número de segundos
	constant P: integer := 16;--50_000_000;--número de ciclos por segundo 50 MHz 
	constant K: integer := 4;--26; --número de bits para contar de 0 a P-1
	constant L: integer := 2;--4;--5; --número de bits para contar de 0 a N-1 
	signal count_reg,count_next: unsigned (K-1 downto 0); --contador de ciclos para dar 1 segundo
	signal count_sec_reg,count_sec_next: unsigned (L-1 downto 0); --contador de segundos
begin
	process(clk, reset)
	begin
		if reset = '1' then
			count_reg <= (others=>'0');
			count_sec_reg <= (others=>'0'); --fechado
		elsif clk' event and clk = '1' then
			count_reg <= count_next;
			count_sec_reg <= count_sec_next;
		end if;
	end process;
	A <= '1' when count_sec_reg = N-1 and count_reg = 0 else
			'0';
	F <= '1' when count_sec_reg = 0 and count_reg = 0 else
			'0'; 
	process(count_reg,count_sec_reg,m)
	begin
		count_sec_next <= count_sec_reg;
		count_next <= count_reg;
		if m = "01" then --abrindo
			if count_sec_reg /= N-1 then 
				if count_reg = P-1 then 
					count_next <= (others=>'0');
					count_sec_next <= count_sec_reg + 1;
				else
					count_next <= count_reg + 1;
				end if;
			end if;
		elsif m = "10" then --fechando
			if count_sec_reg /= 0 then 
				if count_reg = P-1 then 
					count_next <= (others=>'0');
					count_sec_next <= count_sec_reg - 1;
				else
					count_next <= count_reg + 1;
				end if;
			end if;
		end if; 
	end process;
	pos <= std_logic_vector("00"&count_sec_reg);
	
end Behavioral;

