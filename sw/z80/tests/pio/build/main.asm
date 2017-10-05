;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _pio_write
	.globl _pio_set_mode
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;main.c:3: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
;main.c:7: pio_set_mode(PIO_A, PIO_MODE_BYTE_OUT, 0);
	xor	a, a
	push	af
	inc	sp
	ld	hl,#0x0001
	push	hl
	ld	l, #0x00
	push	hl
	call	_pio_set_mode
	pop	af
	pop	af
	inc	sp
;main.c:9: while (1) {
	ld	c,#0x00
00102$:
;main.c:10: pio_write(PIO_A, j++);
	ld	b,c
	inc	c
	push	bc
	push	bc
	inc	sp
	ld	hl,#0x0000
	push	hl
	call	_pio_write
	pop	af
	inc	sp
	pop	bc
	jr	00102$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
