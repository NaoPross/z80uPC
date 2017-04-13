library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity ADDRESS_DECODER is

port(
	-- address input
	PA: in unsigned(15 downto 0);

	-- chip selects output
	-- memory
	CSROMH: out std_logic;
	CSROML: out std_logic;
	CSRAM : out std_logic;
	-- io chips
	CSUART: out std_logic;
	CSCTC : out std_logic;
	CSPIO : out std_logic
);

end;

architecture Behavioral of ADDRESS_DECODER is
begin
	-- memory
	CSROMH <= 0 when ((PA >= x"0000") and (PA < x"2000"));
	CSROML <= 0 when ((PA >= x"4000") and (PA < x"4000"));
	CSRAM  <= 0 when (PA >= x"D000");
	-- io chips
	CSUART <= 0 when ((PA >= x"4000") and (PA < x"4008"));
	-- CSCTC
	-- CSPIO 

end Behavioral;

