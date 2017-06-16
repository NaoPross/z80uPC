library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity cpld_test is
	IN_PIN: in std_logic;
	OUT_PIN: out std_logic;
end;

architecture behavioral of cpld_test is
begin
	OUT_PIN <= not(IN_PIN);
end behavioral;

