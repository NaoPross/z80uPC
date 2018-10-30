
-- VHDL Test Bench Created from source file ADDRESS_DECODER.vhd -- 11/23/17  11:54:48
--
-- Notes: 
-- 1) This testbench template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the unit under test.
-- Lattice recommends that these types always be used for the top-level
-- I/O of a design in order to guarantee that the testbench will bind
-- correctly to the timing (post-route) simulation model.
-- 2) To use this template as your testbench, change the filename to any
-- name of your choice with the extension .vhd, and use the "source->import"
-- menu in the ispDesignExpert System Project Navigator to import the testbench.
-- Then edit the user defined section below, adding code to generate the 
-- stimulus for your design.
--
LIBRARY ieee;
LIBRARY generics;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE generics.components.ALL;

ENTITY testbench IS
END testbench;

ARCHITECTURE behavior OF testbench IS 

	COMPONENT ADDRESS_DECODER
	PORT(
		MMU_IN : IN std_logic_vector(15 downto 0);
		IORQ : IN std_logic;
		RD : IN std_logic;          
		MMU_OUT : OUT std_logic_vector(15 downto 12);
		CSROML : OUT std_logic;
		CSROMH : OUT std_logic;
		CSRAM : OUT std_logic;
		CSUART : OUT std_logic;
		CSCTC : OUT std_logic;
		CSPIO : OUT std_logic
		);
	END COMPONENT;

	SIGNAL MMU_IN :  std_logic_vector(15 downto 0);
	SIGNAL MMU_OUT :  std_logic_vector(15 downto 12);
	SIGNAL IORQ :  std_logic;
	SIGNAL RD :  std_logic;
	SIGNAL CSROML :  std_logic;
	SIGNAL CSROMH :  std_logic;
	SIGNAL CSRAM :  std_logic;
	SIGNAL CSUART :  std_logic;
	SIGNAL CSCTC :  std_logic;
	SIGNAL CSPIO :  std_logic;

BEGIN

	uut: ADDRESS_DECODER PORT MAP(
		MMU_IN => MMU_IN,
		MMU_OUT => MMU_OUT,
		IORQ => IORQ,
		RD => RD,
		CSROML => CSROML,
		CSROMH => CSROMH,
		CSRAM => CSRAM,
		CSUART => CSUART,
		CSCTC => CSCTC,
		CSPIO => CSPIO
	);


-- *** Test Bench - User Defined Section ***
   tb : PROCESS
   BEGIN
      wait; -- will wait forever
   END PROCESS;
-- *** End Test Bench - User Defined Section ***

END;
