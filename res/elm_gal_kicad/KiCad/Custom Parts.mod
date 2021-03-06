PCBNEW-LibModule-V1  06/04/2015 19:19:12
# encoding utf-8
Units mm
$INDEX
L8mm
TO220
$EndINDEX
$MODULE L8mm
Po 0 0 0 15 5522CDE9 00000000 ~~
Li L8mm
Sc 0
AR /551EE65F
Op 0 0 0
T0 0 2.286 1.016 1.016 0 0.2032 N V 21 N "L1"
T1 0 -2.286 1.016 1.016 0 0.2032 N V 21 N "220uH"
DC 0 0 0 4.445 0.381 21
$PAD
Sh "1" R 1.397 1.397 0 0 0
Dr 0.8128 0 0
At STD N 00E0FFFF
Ne 2 "N-0000065"
Po -2.54 0
$EndPAD
$PAD
Sh "2" C 1.397 1.397 0 0 0
Dr 0.8128 0 0
At STD N 00E0FFFF
Ne 1 "N-0000062"
Po 2.54 0
$EndPAD
$SHAPE3D
Na "discret/c_vert_c1v8.wrl"
Sc 1.5 1.5 1
Of 0 0 0
Ro 0 0 0
$EndSHAPE3D
$EndMODULE L8mm
$MODULE TO220
Po 0 0 0 15 55205912 00000000 ~~
Li TO220
Cd Transistor TO 220
Kw TR TO220 DEV
Sc 0
AR /5520271C
Op 0 0 0
T0 -6.985 0 1.016 1.016 2700 0.2032 N V 21 N "U1"
T1 -10.795 0 1.016 1.016 2700 0.2032 N V 21 N "LM317T"
DS 0 -2.54 -5.08 -2.54 0.3048 21
DS 0 0 -5.08 0 0.3048 21
DS 0 2.54 -5.08 2.54 0.3048 21
DS -5.08 5.08 -20.32 5.08 0.3048 21
DS -20.32 5.08 -20.32 -5.08 0.3048 21
DS -20.32 -5.08 -5.08 -5.08 0.3048 21
DS -5.08 -5.08 -5.08 5.08 0.3048 21
DS -12.7 3.81 -12.7 -5.08 0.3048 21
DS -12.7 3.81 -12.7 5.08 0.3048 21
$PAD
Sh "1" R 1.778 1.778 0 0 1800
Dr 1.143 0 0
At STD N 00E0FFFF
Ne 1 "N-0000071"
Po 0 2.54
$EndPAD
$PAD
Sh "3" C 1.778 1.778 0 0 1800
Dr 1.143 0 0
At STD N 00E0FFFF
Ne 2 "N-0000074"
Po 0 -2.54
$EndPAD
$PAD
Sh "2" C 1.778 1.778 0 0 1800
Dr 1.143 0 0
At STD N 00E0FFFF
Ne 3 "VCC"
Po 0 0
$EndPAD
$PAD
Sh "4" R 8.89 8.89 0 0 1800
Dr 3.048 0 0
At STD N 00F0FFFF
Ne 0 ""
Po -16.51 0
$EndPAD
$SHAPE3D
Na "discret/to220_horiz.wrl"
Sc 1 1 1
Of 0 0 0
Ro 0 0 0
$EndSHAPE3D
$EndMODULE TO220
$EndLIBRARY
