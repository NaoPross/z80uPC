; C crt0 loader
;
    module crt0

; general scope declarations
    extern _main    ; C code

; startup code
    org 0000h ; reset vector
    jp _start

_start:
    ld sp, 0xffff
    call _main
    jp _exit

_exit:
    ret
