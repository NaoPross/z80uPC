;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (Linux)
;--------------------------------------------------------
	.module pio
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl __pio_data
	.globl __pio_control
	.globl _pio_set_mode
	.globl _pio_set_interrupts
	.globl _pio_set_interrupts_mask
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
_pio_port:
	.ds 2
_pio_ctrl:
	.ds 2
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
;pio.c:6: inline void _pio_data(int port, uint8_t data)
;	---------------------------------
; Function _pio_data
; ---------------------------------
__pio_data::
;pio.c:8: *(pio_port + port) = data;
	ld	hl,#2
	add	hl,sp
	ld	iy,#_pio_port
	ld	a,0 (iy)
	add	a, (hl)
	ld	c,a
	ld	a,1 (iy)
	inc	hl
	adc	a, (hl)
	ld	b,a
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	ld	(bc),a
	ret
;pio.c:11: inline void _pio_control(int port, uint8_t cmd)
;	---------------------------------
; Function _pio_control
; ---------------------------------
__pio_control::
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	hl,#2
	add	hl,sp
	ld	iy,#_pio_ctrl
	ld	a,0 (iy)
	add	a, (hl)
	ld	c,a
	ld	a,1 (iy)
	inc	hl
	adc	a, (hl)
	ld	b,a
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	ld	(bc),a
	ret
;pio.c:16: void pio_set_mode(int port, int mode, uint8_t io)
;	---------------------------------
; Function pio_set_mode
; ---------------------------------
_pio_set_mode::
;pio.c:19: _pio_control(port, ((mode << 6) | 0x0F));
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	rrca
	rrca
	and	a,#0xc0
	or	a, #0x0f
	ld	c,a
	pop	de
	pop	hl
	push	hl
	push	de
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	iy,(_pio_ctrl)
	ld	e, l
	ld	d, h
	add	iy, de
	ld	0 (iy), c
;pio.c:23: if (mode == PIO_MODE_BIT_IO) {
	ld	iy,#4
	add	iy,sp
	ld	a,0 (iy)
	sub	a, #0x03
	ret	NZ
	ld	a,1 (iy)
	or	a, a
	ret	NZ
;pio.c:24: _pio_control(port, io);
	ld	iy,#6
	add	iy,sp
	ld	c,0 (iy)
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	de,(_pio_ctrl)
	add	hl,de
	ld	(hl),c
;pio.c:24: _pio_control(port, io);
	ret
;pio.c:28: void pio_set_interrupts(int port, int control)
;	---------------------------------
; Function pio_set_interrupts
; ---------------------------------
_pio_set_interrupts::
;pio.c:31: _pio_control(port, (control | 0x07));
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	or	a, #0x07
	ld	c,a
	pop	de
	pop	hl
	push	hl
	push	de
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	de,(_pio_ctrl)
	add	hl,de
	ld	(hl),c
;pio.c:31: _pio_control(port, (control | 0x07));
	ret
;pio.c:34: void pio_set_interrupts_mask(int port, int control, uint8_t mask)
;	---------------------------------
; Function pio_set_interrupts_mask
; ---------------------------------
_pio_set_interrupts_mask::
;pio.c:38: _pio_control(port, (control | 0x17));
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	or	a, #0x17
	ld	c,a
	pop	de
	pop	hl
	push	hl
	push	de
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	iy,(_pio_ctrl)
	ld	e, l
	ld	d, h
	add	iy, de
	ld	0 (iy), c
;pio.c:39: _pio_control(port, mask);
	ld	iy,#6
	add	iy,sp
	ld	c,0 (iy)
;pio.c:13: *(pio_ctrl + port) = cmd;
	ld	de,(_pio_ctrl)
	add	hl,de
	ld	(hl),c
;pio.c:39: _pio_control(port, mask);
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__pio_port:
	.dw #0x4200
__xinit__pio_ctrl:
	.dw #0x4202
	.area _CABS (ABS)
