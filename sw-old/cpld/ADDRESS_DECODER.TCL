#-- Lattice Semiconductor Corporation Ltd.
#-- Synplify OEM project file .\ADDRESS_DECODER.TCL
#-- Written on Thu Nov 23 11:54:33 2017


#-- begin a new section
project -new

#-- Device options
set_option -technology mach

#-- add_file options
add_file -vhdl -lib work "address_decoder.vhd"

#-- top module name
set_option -top_module ADDRESS_DECODER

#simulation options
set_option -write_verilog true
set_option -write_vhdl true

#-- set result format/file last
project -result_file "ADDRESS_DECODER.edi"

#-- error message log file
project -log_file ADDRESS_DECODER.log

#-- let's save it
project -save ADDRESS_DECODER.tc_

#-- run Synplify
project -run

#-- **************************************************

#-- exit from Synplify
exit
