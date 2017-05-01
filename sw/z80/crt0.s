    .area _HEADER (ABS)
    ;; reset vector
    .org 0
    jp init
    
    .org 0x08
    reti
    .org 0x10
    reti
    .org 0x18
    reti
    .org 0x20
    reti
    .org 0x28
    reti
    .org 0x30
    reti
    .org 0x38
    reti

    .org 0x100

init:
    ;; set stack
    ld sp,#0xFFFF

    ;; call C main function
    call _main

.globl _main
