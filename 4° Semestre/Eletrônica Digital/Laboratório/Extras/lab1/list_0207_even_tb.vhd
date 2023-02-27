--=============================
-- Listing 2.7 even detector testbench
--=============================
library ieee;
use ieee.std_logic_1164.all;

entity even_detector_testbench is
end even_detector_testbench;

architecture tb_arch of even_detector_testbench is
   signal test_in: std_logic_vector(2 downto 0);
   signal test_out: std_logic;
begin
   -- instantiate the circuit under test
   uut: entity work.even_detector (str_arch)
      port map( a=>test_in, even=>test_out);
   -- test vector generator
   process
   begin
      test_in <= "000";
      wait for 200 ns;
      test_in <= "001";
      wait for 200 ns;
      test_in <= "010";
      wait for 200 ns;
      test_in <= "011";
      wait for 200 ns;
      test_in <= "100";
      wait for 200 ns;
      test_in <= "101";
      wait for 200 ns;
      test_in <= "110";
      wait for 200 ns;
      test_in <= "111";
      wait for 200 ns;
   end process;
   --verifier
   process
      variable error_status: boolean;
   begin
      wait on test_in;
      wait for 100 ns;
      if ((test_in="000" and test_out = '1') or
          (test_in="001" and test_out = '0') or
          (test_in="010" and test_out = '0') or
          (test_in="011" and test_out = '1') or
          (test_in="100" and test_out = '0') or
          (test_in="101" and test_out = '1') or
          (test_in="110" and test_out = '1') or
          (test_in="111" and test_out = '0'))
      then
         error_status := false;
      else
         error_status := true;
      end if;
      -- error reporting
      assert not error_status
         report "test failed."
         severity note;
   end process;
end tb_arch;