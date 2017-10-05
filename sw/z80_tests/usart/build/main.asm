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
	.globl _usart_write
	.globl _usart_init
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
;main.c:5: usart_init(USART_BAUDRATE_1200, USART_PARITY_EVEN, USART_STOP_BITS_1);
	ld	hl,#0x000a
	push	hl
	ld	l, #0x01
	push	hl
	ld	l, #0x60
	push	hl
	call	_usart_init
	ld	hl,#6
	add	hl,sp
	ld	sp,hl
;main.c:6: usart_write("Hello, World!\n", 13);
	ld	hl,#0x000d
	push	hl
	ld	hl,#___str_0
	push	hl
	call	_usart_write
	pop	af
	pop	af
;main.c:8: while(1) {
00102$:
;main.c:9: usart_write("done\n", 5);
	ld	hl,#0x0005
	push	hl
	ld	hl,#___str_1
	push	hl
	call	_usart_write
	pop	af
	pop	af
	jr	00102$
___str_0:
	.ascii "Hello, World!"
	.db 0x0a
	.db 0x00
___str_1:
	.ascii "done"
	.db 0x0a
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
