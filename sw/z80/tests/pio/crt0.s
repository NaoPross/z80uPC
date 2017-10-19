    .module crt0
    .area   _HEADER (ABS)

;; Reset vectors
    .org    0
    jp  init

    .org    0x38 ; the instruction 0xff (not written) resets to this location
    jp init

;; main code
    .org    0x100
    .globl  _main

init:
    ;; Set stack pointer directly above top of memory.
    ld  sp,#0xffff

    ;; Start of the program
    call    _main
    jp      _exit

_exit:
    halt
    ; jp  _exit

;; Ordering of segments for the linker.
    .area   _HOME
    .area   _CODE
    .area   _INITIALIZER
    .area   _GSINIT
    .area   _GSFINAL

    .area   _DATA
    .area   _INITIALIZED
    .area   _BSEG
    .area   _BSS
    .area   _HEAP

    .area   _CODE