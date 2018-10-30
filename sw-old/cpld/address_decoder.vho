-- VHDL netlist-file
library mach;
use mach.components.all;

library ieee;
use ieee.std_logic_1164.all;
entity address_decoder is
  port (
    CSROML : out std_logic;
    CSROMH : out std_logic;
    CSRAM : out std_logic;
    CSUART : out std_logic;
    CSCTC : out std_logic;
    CSPIO : out std_logic;
    MMU_IN : in std_logic_vector(15 downto 0);
    MMU_OUT : out std_logic_vector(15 downto 12)
  );
end address_decoder;

architecture NetList of address_decoder is

  signal MMU_IN_15_PIN : std_logic;
  signal MMU_OUT_15_COM : std_logic;
  signal CSROML_COM : std_logic;
  signal CSROMH_COM : std_logic;
  signal CSRAM_COM : std_logic;
  signal CSUART_COM : std_logic;
  signal CSCTC_COM : std_logic;
  signal CSPIO_COM : std_logic;
  signal MMU_IN_14_PIN : std_logic;
  signal MMU_IN_13_PIN : std_logic;
  signal MMU_IN_12_PIN : std_logic;
  signal MMU_IN_11_PIN : std_logic;
  signal MMU_IN_10_PIN : std_logic;
  signal MMU_IN_9_PIN : std_logic;
  signal MMU_IN_8_PIN : std_logic;
  signal MMU_IN_7_PIN : std_logic;
  signal MMU_IN_6_PIN : std_logic;
  signal MMU_IN_5_PIN : std_logic;
  signal MMU_IN_4_PIN : std_logic;
  signal MMU_IN_3_PIN : std_logic;
  signal MMU_IN_2_PIN : std_logic;
  signal MMU_OUT_14_COM : std_logic;
  signal MMU_OUT_13_COM : std_logic;
  signal MMU_OUT_12_COM : std_logic;
  signal T_0 : std_logic;
  signal T_1 : std_logic;
  signal T_2 : std_logic;
  signal T_3 : std_logic;
  signal T_4 : std_logic;
  signal T_5 : std_logic;
  signal T_6 : std_logic;
  signal T_7 : std_logic;
  signal T_8 : std_logic;
  signal T_9 : std_logic;
  signal T_10 : std_logic;
  signal T_11 : std_logic;
  signal T_12 : std_logic;
  signal T_13 : std_logic;
  signal T_14 : std_logic;
  signal T_15 : std_logic;
  signal T_16 : std_logic;
  signal GATE_T_1_A : std_logic;
  signal GATE_T_1_B : std_logic;
  signal GATE_T_5_A : std_logic;
  signal GATE_T_8_A : std_logic;
  signal GATE_T_9_A : std_logic;
  signal GATE_T_12_A : std_logic;
  signal GATE_T_14_DN : std_logic;

begin
  IN_MMU_IN_15_I_1:   IBUF port map ( O=>MMU_IN_15_PIN, I0=>MMU_IN(15) );
  OUT_MMU_OUT_15_I_1:   OBUF port map ( O=>MMU_OUT(15), I0=>MMU_OUT_15_COM );
  OUT_CSROML_I_1:   OBUF port map ( O=>CSROML, I0=>CSROML_COM );
  OUT_CSROMH_I_1:   OBUF port map ( O=>CSROMH, I0=>CSROMH_COM );
  OUT_CSRAM_I_1:   OBUF port map ( O=>CSRAM, I0=>CSRAM_COM );
  OUT_CSUART_I_1:   OBUF port map ( O=>CSUART, I0=>CSUART_COM );
  OUT_CSCTC_I_1:   OBUF port map ( O=>CSCTC, I0=>CSCTC_COM );
  OUT_CSPIO_I_1:   OBUF port map ( O=>CSPIO, I0=>CSPIO_COM );
  IN_MMU_IN_14_I_1:   IBUF port map ( O=>MMU_IN_14_PIN, I0=>MMU_IN(14) );
  IN_MMU_IN_13_I_1:   IBUF port map ( O=>MMU_IN_13_PIN, I0=>MMU_IN(13) );
  IN_MMU_IN_12_I_1:   IBUF port map ( O=>MMU_IN_12_PIN, I0=>MMU_IN(12) );
  IN_MMU_IN_11_I_1:   IBUF port map ( O=>MMU_IN_11_PIN, I0=>MMU_IN(11) );
  IN_MMU_IN_10_I_1:   IBUF port map ( O=>MMU_IN_10_PIN, I0=>MMU_IN(10) );
  IN_MMU_IN_9_I_1:   IBUF port map ( O=>MMU_IN_9_PIN, I0=>MMU_IN(9) );
  IN_MMU_IN_8_I_1:   IBUF port map ( O=>MMU_IN_8_PIN, I0=>MMU_IN(8) );
  IN_MMU_IN_7_I_1:   IBUF port map ( O=>MMU_IN_7_PIN, I0=>MMU_IN(7) );
  IN_MMU_IN_6_I_1:   IBUF port map ( O=>MMU_IN_6_PIN, I0=>MMU_IN(6) );
  IN_MMU_IN_5_I_1:   IBUF port map ( O=>MMU_IN_5_PIN, I0=>MMU_IN(5) );
  IN_MMU_IN_4_I_1:   IBUF port map ( O=>MMU_IN_4_PIN, I0=>MMU_IN(4) );
  IN_MMU_IN_3_I_1:   IBUF port map ( O=>MMU_IN_3_PIN, I0=>MMU_IN(3) );
  IN_MMU_IN_2_I_1:   IBUF port map ( O=>MMU_IN_2_PIN, I0=>MMU_IN(2) );
  OUT_MMU_OUT_14_I_1:   OBUF port map ( O=>MMU_OUT(14), I0=>MMU_OUT_14_COM );
  OUT_MMU_OUT_13_I_1:   OBUF port map ( O=>MMU_OUT(13), I0=>MMU_OUT_13_COM );
  OUT_MMU_OUT_12_I_1:   OBUF port map ( O=>MMU_OUT(12), I0=>MMU_OUT_12_COM );
  GATE_MMU_OUT_15_I_1:   BUFF port map ( I0=>MMU_IN_15_PIN, O=>MMU_OUT_15_COM );
  GATE_T_0_I_1:   NOR3 port map ( O=>T_0, I2=>MMU_IN_14_PIN, I1=>MMU_IN_15_PIN, I0=>MMU_IN_13_PIN );
  GATE_T_1_I_1:   INV port map ( I0=>MMU_IN_14_PIN, O=>GATE_T_1_A );
  GATE_T_1_I_2:   INV port map ( I0=>MMU_IN_15_PIN, O=>GATE_T_1_B );
  GATE_T_1_I_3:   AND3 port map ( O=>T_1, I0=>MMU_IN_13_PIN, I2=>GATE_T_1_A, I1=>GATE_T_1_B );
  GATE_CSRAM_I_1:   INV port map ( I0=>MMU_IN_15_PIN, O=>CSRAM_COM );
  GATE_T_2_I_1:   AND4 port map ( O=>T_2, I3=>T_13, I2=>T_14, I1=>T_15, I0=>T_16 );
  GATE_T_3_I_1:   AND4 port map ( O=>T_3, I3=>T_9, I2=>T_10, I1=>T_11, I0=>T_12 );
  GATE_T_4_I_1:   AND4 port map ( O=>T_4, I3=>T_5, I2=>T_6, I1=>T_7, I0=>T_8 );
  GATE_MMU_OUT_14_I_1:   BUFF port map ( I0=>MMU_IN_14_PIN, O=>MMU_OUT_14_COM );
  GATE_MMU_OUT_13_I_1:   BUFF port map ( I0=>MMU_IN_13_PIN, O=>MMU_OUT_13_COM );
  GATE_MMU_OUT_12_I_1:   BUFF port map ( I0=>MMU_IN_12_PIN, O=>MMU_OUT_12_COM );
  GATE_CSROML_I_1:   INV port map ( I0=>T_0, O=>CSROML_COM );
  GATE_CSROMH_I_1:   INV port map ( I0=>T_1, O=>CSROMH_COM );
  GATE_CSUART_I_1:   INV port map ( I0=>T_2, O=>CSUART_COM );
  GATE_CSCTC_I_1:   INV port map ( I0=>T_3, O=>CSCTC_COM );
  GATE_CSPIO_I_1:   INV port map ( I0=>T_4, O=>CSPIO_COM );
  GATE_T_5_I_1:   AND2 port map ( O=>T_5, I1=>MMU_IN_9_PIN, I0=>GATE_T_5_A );
  GATE_T_5_I_2:   INV port map ( O=>GATE_T_5_A, I0=>MMU_IN_8_PIN );
  GATE_T_6_I_1:   NOR2 port map ( O=>T_6, I1=>MMU_IN_10_PIN, I0=>MMU_IN_11_PIN );
  GATE_T_7_I_1:   NOR2 port map ( O=>T_7, I1=>MMU_IN_12_PIN, I0=>MMU_IN_13_PIN );
  GATE_T_8_I_1:   AND2 port map ( O=>T_8, I1=>MMU_IN_14_PIN, I0=>GATE_T_8_A );
  GATE_T_8_I_2:   INV port map ( O=>GATE_T_8_A, I0=>MMU_IN_15_PIN );
  GATE_T_9_I_1:   AND2 port map ( O=>T_9, I1=>MMU_IN_8_PIN, I0=>GATE_T_9_A );
  GATE_T_9_I_2:   INV port map ( O=>GATE_T_9_A, I0=>MMU_IN_9_PIN );
  GATE_T_10_I_1:   NOR2 port map ( O=>T_10, I1=>MMU_IN_10_PIN, I0=>MMU_IN_11_PIN );
  GATE_T_11_I_1:   NOR2 port map ( O=>T_11, I1=>MMU_IN_12_PIN, I0=>MMU_IN_13_PIN );
  GATE_T_12_I_1:   AND2 port map ( O=>T_12, I1=>MMU_IN_14_PIN, I0=>GATE_T_12_A );
  GATE_T_12_I_2:   INV port map ( O=>GATE_T_12_A, I0=>MMU_IN_15_PIN );
  GATE_T_13_I_1:   NOR2 port map ( O=>T_13, I1=>MMU_IN_2_PIN, I0=>MMU_IN_3_PIN );
  GATE_T_14_I_1:   NOR4 port map ( I0=>MMU_IN_7_PIN, I1=>MMU_IN_6_PIN, O=>T_14, I2=>MMU_IN_5_PIN, I3=>GATE_T_14_DN );
  GATE_T_14_I_2:   INV port map ( I0=>MMU_IN_4_PIN, O=>GATE_T_14_DN );
  GATE_T_15_I_14:   NOR4 port map ( O=>T_15, I3=>MMU_IN_8_PIN, I2=>MMU_IN_9_PIN, I1=>MMU_IN_10_PIN, I0=>MMU_IN_11_PIN );
  GATE_T_16_I_14:   NOR4 port map ( O=>T_16, I3=>MMU_IN_12_PIN, I2=>MMU_IN_13_PIN, I1=>MMU_IN_14_PIN, I0=>MMU_IN_15_PIN );

end NetList;