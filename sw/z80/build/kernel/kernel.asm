;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Wed Aug 23 21:44:59 2017
;--------------------------------------------------------
	.module kernel
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _kmain
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
;kernel/kernel.c:4: void kmain(void)
;	---------------------------------
; Function kmain
; ---------------------------------
_kmain::
;kernel/kernel.c:6: usart_init(USART_BAUDRATE_9600, USART_PARITY_EVEN, USART_STOP_BITS_1);
	ld	hl,#0x000A
	push	hl
	ld	l, #0x01
	push	hl
	ld	hl,#0x0000
	push	hl
	ld	hl,#0x000C
	push	hl
	call	_usart_init
	ld	hl,#8
	add	hl,sp
	ld	sp,hl
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
