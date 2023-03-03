--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:31:21 02/03/2021
-- Design Name:   
-- Module Name:   C:/Users/ElieteMaria/Desktop/TecladoPS2/2020-1/mux4x1/mux4x1_tb.vhd
-- Project Name:  mux4x1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux4x1
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY mux4x1_tb IS
END mux4x1_tb;
 
ARCHITECTURE behavior OF mux4x1_tb IS 
    --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';
   signal c : std_logic := '0';
   signal d : std_logic := '0';
   signal sel : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal s : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: entity work.mux4x1 PORT MAP (
          a => a,
          b => b,
          c => c,
          d => d,
          sel => sel,
          s => s
        );

   process
   begin
		a <= '0';
		wait for 10 ns;
		a <= '1';
		wait for 10 ns;
   end process;
   process
   begin
		b <= '0';
		wait for 20 ns;
		b <= '1';
		wait for 20 ns;
   end process;
   process
   begin
		c <= '0';
		wait for 40 ns;
		c <= '1';
		wait for 40 ns;
   end process;
   process
   begin
		d <= '0';
		wait for 80 ns;
		d <= '1';
		wait for 80 ns;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
		sel <= "00";
      wait for 160 ns;	
		sel <= "01";
      wait for 160 ns;	
		sel <= "10";
      wait for 160 ns;	
		sel <= "11";
      wait for 160 ns;	
		assert false
		report "Simulation Completed"
		severity failure;

   end process;

END;
