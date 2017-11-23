library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity ADDRESS_DECODER is
port(
	-- address input
	MMU_IN: in std_logic_vector(15 downto 0);
	-- address output
	MMU_OUT: out std_logic_vector(15 downto 12);

	-- other signals
	IORQ: in std_logic;
	RD:   in std_logic;

	-- chip selects output
	-- memory
	CSROML: out std_logic;
	CSROMH: out std_logic;
	CSRAM : out std_logic;
	-- io chips
	CSUART: out std_logic;
	CSCTC : out std_logic;
	CSPIO : out std_logic
);
end;

architecture Behavioral of ADDRESS_DECODER is
	signal ADDR_IN_LOW  : unsigned (7 downto 0);
	signal ADDR_IN_HIGH : unsigned (7 downto 0);
	signal ADDR_IN      : unsigned (15 downto 0);
begin
	-- PAGE TABLE (disabled)
	MMU_OUT <= MMU_IN(15 downto 12);	
	
	-- ENABLE SIGNALS
	ADDR_IN_LOW  <= unsigned(MMU_IN(7 downto 0));
	ADDR_IN_HIGH <= unsigned(MMU_IN(15 downto 8));
	ADDR_IN      <= unsigned(MMU_IN);

	-- io chips:
	---- region 0x0000 - 0x00FF ----
	
	CSPIO <= '0' when ((ADDR_IN_LOW >= 16#10#) and (ADDR_IN_LOW < 16#14#) and (IORQ = '0')) else '1';
	-- CSPIO  <= '0' when ((ADDR_IN >= 16#0010#) and (ADDR_IN < 16#0014#)) else '1';
	-- CSCTC  <= '0' when ((ADDR_IN >= 16#4100#) and (ADDR_IN < 16#4200#)) else '1'; -- test address range
	--CSUART <= '0' when ((ADDR_IN >= 16#4200#) and (ADDR_IN < 16#4300#)) else '1'; -- test address range

	-- read only memory:
	---- region 0x0000 - 0x4000 ----
	CSROML <= '0' when ((ADDR_IN >= 16#0000#) and (ADDR_IN < 16#2000#)) else '1';
	CSROMH <= '0' when ((ADDR_IN >= 16#2000#) and (ADDR_IN < 16#4000#)) else '1';

	-- random access memory:
	---- region 0x8000 - 0xFFFF ----
	CSRAM  <= '0' when (ADDR_IN >= 16#8000#) else '1';
end Behavioral;

