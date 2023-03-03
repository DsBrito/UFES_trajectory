-- Listing 7.4
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity uart is   port(
      clk, reset: in std_logic;
		bd_rate: in std_logic_vector(1 downto 0);	-- Seleciona baud_rate
		dnum, snum: in std_logic;						-- nbits dados e stop
		par: in std_logic_vector(1 downto 0);		-- paridade
		err: out std_logic_vector(2 downto 0);		-- erros
      rd_uart, wr_uart: in std_logic;
      rx: in std_logic;
      w_data: in std_logic_vector(7 downto 0);
      tx_full, rx_empty: out std_logic;
      r_data: out std_logic_vector(7 downto 0);
      tx: out std_logic
   );
end uart;

architecture str_arch of uart is
   signal tick: std_logic;
   signal rx_done_tick: std_logic;
   signal tx_fifo_out: std_logic_vector(7 downto 0);
   signal rx_data_out: std_logic_vector(7 downto 0);
   signal tx_empty, tx_fifo_not_empty: std_logic;
   signal tx_done_tick: std_logic;
  	signal dvsr: std_logic_vector(11 downto 0);
	signal full: std_logic;
	signal overrun_err_reg, overrun_err_next: std_logic;
begin
	with bd_rate select
	dvsr<=std_logic_vector(to_unsigned(325,12)) when "00", -- 9600
			std_logic_vector(to_unsigned(651,12)) when "01", --4800
			std_logic_vector(to_unsigned(1302,12)) when "10", -- 2400
			std_logic_vector(to_unsigned(2604,12)) when others; -- 1200

	process(clk, reset)
	begin
		if reset='1' then
			overrun_err_reg <='0';
		elsif clk' event and clk='1' then
			overrun_err_reg<= overrun_err_next;
		end if;
	end process;
	
   baud_gen_unit: entity work.mod_m_counter(arch)
      port map(clk=>clk, reset=>reset,
					m=>dvsr,
               q=>open, 
					max_tick=>tick);
   
	uart_rx_unit: entity work.uart_rx(arch)
      port map(clk=>clk, reset=>reset,  
					dnum=>dnum,
					snum=>snum, 
					par=>par, 
					rx=>rx, s_tick=>tick, err=>err(1 downto 0),
					rx_done_tick=>rx_done_tick,
               dout=>rx_data_out);
   
	fifo_rx_unit: entity work.fifo(arch)
      port map(clk=>clk, 
					reset=>reset, 
					rd=>rd_uart,
               wr=>rx_done_tick, 
					w_data=>rx_data_out,
               empty=>rx_empty, 
					full=>full, 
					r_data=>r_data);

   fifo_tx_unit: entity work.fifo(arch)
      port map(clk=>clk, 
					reset=>reset, 
					rd=>tx_done_tick,
               wr=>wr_uart, 
					w_data=>w_data, 
					empty=>tx_empty,
               full=>tx_full, 
					r_data=>tx_fifo_out);
					
   uart_tx_unit: entity work.uart_tx(arch)
      port map(clk=>clk, reset=>reset,
               tx_start=>tx_fifo_not_empty, 
					dnum=>dnum,
					snum=>snum,
					par=> par,
               s_tick=>tick, din=>tx_fifo_out,
               tx_done_tick=> tx_done_tick, tx=>tx);
							
	process(overrun_err_reg, full, rx_done_tick)
	begin
		if(full='1' and rx_done_tick='1')then
			overrun_err_next<= '1';
		else
			overrun_err_next<= overrun_err_reg;
		end if;
	end process;
				
	err(2)<= overrun_err_reg;	 
   tx_fifo_not_empty <= not tx_empty;
end str_arch;