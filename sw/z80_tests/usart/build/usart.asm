;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (Linux)
;--------------------------------------------------------
	.module usart
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _usart_word_length
	.globl _usart_set_baudrate
	.globl _usart_set_parity
	.globl _usart_set_stop_bits
	.globl _usart_set_autoflow
	.globl _usart_init
	.globl _usart_transmit
	.globl _usart_receive
	.globl _usart_write
	.globl _usart_read
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
__usart:
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
;usart.c:5: void usart_set_baudrate(uint16_t baudrate)
;	---------------------------------
; Function usart_set_baudrate
; ---------------------------------
_usart_set_baudrate::
	push	ix
	ld	ix,#0
	add	ix,sp
;usart.c:8: _usart->LCR.divisor_latch_access = 1;
	ld	hl,(__usart)
	ld	bc,#0x0004
	add	hl,bc
	ld	a,(hl)
	or	a,#0x80
	ld	(hl),a
;usart.c:9: _usart->buffer = 0x00FF & baudrate; // LSBs
	ld	hl,(__usart)
	ld	c,4 (ix)
	ld	(hl),c
;usart.c:10: memcpy(&_usart->IER, &(baudrate >>8), 1);
	ld	de,(__usart)
	inc	de
	ld	l,5 (ix)
	ld	h,#0x00
	ld	a, (hl)
	ld	(de), a
;usart.c:12: _usart->LCR.divisor_latch_access = 0;
	ld	hl,(__usart)
	ld	bc,#0x0004
	add	hl,bc
	ld	a,(hl)
	and	a,#0x7f
	ld	(hl),a
	pop	ix
	ret
;usart.c:15: void usart_set_parity(int mode)
;	---------------------------------
; Function usart_set_parity
; ---------------------------------
_usart_set_parity::
;usart.c:18: _usart->LCR.even_parity = 1;
	ld	hl,(__usart)
	ld	bc,#0x0004
	add	hl,bc
;usart.c:17: if (mode == USART_PARITY_EVEN) {
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	dec	a
	jr	NZ,00104$
	ld	a,1 (iy)
	or	a, a
	jr	NZ,00104$
;usart.c:18: _usart->LCR.even_parity = 1;
	ld	a,(hl)
	or	a,#0x10
	ld	(hl),a
	jr	00105$
00104$:
;usart.c:20: else if (mode == USART_PARITY_ODD) {
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	sub	a, #0x02
	jr	NZ,00105$
	ld	a,1 (iy)
	or	a, a
	jr	NZ,00105$
;usart.c:21: _usart->LCR.even_parity = 0;
	ld	a,(hl)
	and	a,#0xef
	ld	(hl),a
00105$:
;usart.c:24: _usart->LCR.parity = (mode == USART_PARITY_NONE) ? 0 : 1;
	ld	hl,(__usart)
	ld	bc,#0x0004
	add	hl,bc
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	rlca
	rlca
	rlca
	and	a,#0xf8
	and	a,#0x08
	ld	c,a
	ld	a,(hl)
	and	a,#0xf7
	or	a,c
	ld	(hl),a
	ret
;usart.c:27: void usart_set_stop_bits(int count)
;	---------------------------------
; Function usart_set_stop_bits
; ---------------------------------
_usart_set_stop_bits::
;usart.c:29: _usart->LCR.stop_bits = (count == USART_STOP_BITS_1) ? 0 : 1;
	ld	bc,(__usart)
	inc	bc
	inc	bc
	inc	bc
	inc	bc
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	sub	a, #0x0a
	jr	NZ,00103$
	ld	a,1 (iy)
	or	a, a
	jr	NZ,00103$
	ld	a,#0x01
	jr	00104$
00103$:
	xor	a,a
00104$:
	xor	a, #0x01
	add	a, a
	add	a, a
	and	a,#0x04
	ld	l,a
	ld	a,(bc)
	and	a,#0xfb
	or	a,l
	ld	(bc),a
	ret
;usart.c:32: void usart_word_length(int length)
;	---------------------------------
; Function usart_word_length
; ---------------------------------
_usart_word_length::
;usart.c:34: _usart->LCR.word_length = length;
	ld	hl,(__usart)
	ld	bc,#0x0004
	add	hl,bc
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	and	a,#0x03
	ld	c,a
	ld	a,(hl)
	and	a,#0xfc
	or	a,c
	ld	(hl),a
	ret
;usart.c:37: void usart_set_autoflow(int mode)
;	---------------------------------
; Function usart_set_autoflow
; ---------------------------------
_usart_set_autoflow::
;usart.c:39: _usart->MCR.autoflow = (mode == USART_AUTOFLOW_OFF) ? 0 : 1;
	ld	hl,(__usart)
	ld	bc,#0x000c
	add	hl,bc
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	and	a,#0x01
	ld	c,a
	ld	a,(hl)
	and	a,#0xfe
	or	a,c
	ld	(hl),a
;usart.c:40: _usart->MCR.data_terminal_ready = (mode == USART_AUTOFLOW_ALL);
	ld	hl,(__usart)
	ld	bc,#0x0005
	add	hl,bc
	ld	a,0 (iy)
	sub	a, #0x03
	jr	NZ,00103$
	ld	a,1 (iy)
	or	a, a
	jr	NZ,00103$
	ld	a,#0x01
	jr	00104$
00103$:
	xor	a,a
00104$:
	and	a,#0x01
	ld	c,a
	ld	a,(hl)
	and	a,#0xfe
	or	a,c
	ld	(hl),a
	ret
;usart.c:43: inline void usart_init(uint16_t baudrate, int parity, int stop_bits)
;	---------------------------------
; Function usart_init
; ---------------------------------
_usart_init::
;usart.c:45: usart_set_baudrate(baudrate);
	pop	bc
	pop	hl
	push	hl
	push	bc
	push	hl
	call	_usart_set_baudrate
	pop	af
;usart.c:46: usart_set_parity(parity);
	ld	hl, #4
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	_usart_set_parity
	pop	af
;usart.c:47: usart_set_stop_bits(stop_bits);
	ld	hl, #6
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	_usart_set_stop_bits
;usart.c:48: usart_set_autoflow(USART_AUTOFLOW_OFF);
	ld	hl, #0x0000
	ex	(sp),hl
	call	_usart_set_autoflow
	pop	af
	ret
;usart.c:51: void usart_transmit(uint8_t data)
;	---------------------------------
; Function usart_transmit
; ---------------------------------
_usart_transmit::
;usart.c:53: _usart->buffer = data;
	ld	hl,(__usart)
	ld	iy,#2
	add	iy,sp
	ld	a,0 (iy)
	ld	(hl),a
;usart.c:54: while (_usart->LSR.transmitter_holder_empty == 0); // wait
00101$:
	ld	hl,(__usart)
	ld	bc,#0x000d
	add	hl,bc
	ld	a,(hl)
	rlca
	rlca
	rlca
	jr	NC,00101$
	ret
;usart.c:57: uint8_t usart_receive()
;	---------------------------------
; Function usart_receive
; ---------------------------------
_usart_receive::
;usart.c:59: return _usart->buffer;
	ld	hl,(__usart)
	ld	l,(hl)
	ret
;usart.c:62: int usart_write(uint8_t *data, size_t size)
;	---------------------------------
; Function usart_write
; ---------------------------------
_usart_write::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;usart.c:64: uint8_t *dp = data;
	ld	a,4 (ix)
	ld	-2 (ix),a
	ld	a,5 (ix)
	ld	-1 (ix),a
;usart.c:66: while (size--) {
	ld	c,6 (ix)
	ld	b,7 (ix)
00104$:
	ld	e, c
	ld	d, b
	dec	bc
	ld	a,d
	or	a,e
	jr	Z,00106$
;usart.c:67: _usart->buffer = *(dp++);
	ld	de,(__usart)
	pop	hl
	push	hl
	ld	a,(hl)
	inc	-2 (ix)
	jr	NZ,00126$
	inc	-1 (ix)
00126$:
	ld	(de),a
;usart.c:68: while (_usart->LSR.transmitter_empty);
00101$:
	ld	hl,(__usart)
	ld	de,#0x000d
	add	hl,de
	ld	a,(hl)
	rlca
	rlca
	jr	NC,00104$
	jr	00101$
00106$:
;usart.c:72: return size;
	ld	l, c
	ld	h, b
	ld	sp, ix
	pop	ix
	ret
;usart.c:75: int usart_read(uint8_t *buffer, size_t count)
;	---------------------------------
; Function usart_read
; ---------------------------------
_usart_read::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl,#-6
	add	hl,sp
	ld	sp,hl
;usart.c:77: uint8_t *bp = buffer;
	ld	a,4 (ix)
	ld	-6 (ix),a
	ld	a,5 (ix)
	ld	-5 (ix),a
;usart.c:80: while (count--) {
	ld	c,6 (ix)
	ld	b,7 (ix)
	ld	-4 (ix),#0x00
	ld	-3 (ix),#0x00
00105$:
	ld	e, c
	ld	d, b
	dec	bc
	ld	a,d
	or	a,e
	jr	Z,00107$
;usart.c:81: *(bp++) = _usart->buffer;
	ld	hl,(__usart)
	ld	e,(hl)
	pop	hl
	push	hl
	ld	(hl),e
	inc	-6 (ix)
	jr	NZ,00123$
	inc	-5 (ix)
00123$:
	ld	de,(__usart)
;usart.c:83: if (_usart->LSR.framing_error || _usart->LSR.parity_error) {
	ld	hl,#0x000d
	add	hl,de
	ld	-2 (ix),l
	ld	-1 (ix),h
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	a,(hl)
	rrca
	rrca
	rrca
	and	a,#0x01
	jr	NZ,00101$
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	a,(hl)
	rrca
	rrca
	and	a,#0x01
	jr	Z,00102$
00101$:
;usart.c:84: bp--; // delete last byte (?)
	pop	hl
	push	hl
	dec	hl
	ex	(sp), hl
	jr	00105$
00102$:
;usart.c:86: read_count++;
	inc	-4 (ix)
	jr	NZ,00105$
	inc	-3 (ix)
	jr	00105$
00107$:
;usart.c:90: return read_count;
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit___usart:
	.dw #0x4000
	.area _CABS (ABS)
