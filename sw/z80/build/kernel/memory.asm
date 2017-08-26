;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Wed Aug 23 21:44:59 2017
;--------------------------------------------------------
	.module memory
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _pages_table
	.globl _mmu_write_table
	.globl _page_map
	.globl _page_unmap
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_pages_table::
	.ds 192
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
;kernel/memory.c:5: int mmu_write_table(void)
;	---------------------------------
; Function mmu_write_table
; ---------------------------------
_mmu_write_table::
;kernel/memory.c:9: for (i = 0; i < PAGES_MAX_COUNT; i++) {
	ld	hl,#0x0000
00102$:
	inc	hl
	ld	a,l
	sub	a, #0x20
	ld	a,h
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	C,00102$
;kernel/memory.c:15: return 0;
	ld	hl,#0x0000
	ret
;kernel/memory.c:18: int page_map(int page, int pid, uint16_t addr)
;	---------------------------------
; Function page_map
; ---------------------------------
_page_map::
	push	ix
	ld	ix,#0
	add	ix,sp
;kernel/memory.c:20: if (page >= PAGES_MAX_COUNT)
	ld	a,4 (ix)
	sub	a, #0x20
	ld	a,5 (ix)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	C,00102$
;kernel/memory.c:21: return -1;
	ld	hl,#0xFFFF
	jr	00105$
00102$:
;kernel/memory.c:23: if (pages_table[page].used)
	ld	de,#_pages_table+0
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl,de
	ld	c,l
	ld	b,h
	ld	a,(hl)
	and	a,#0x01
	jr	Z,00104$
;kernel/memory.c:24: return -2;
	ld	hl,#0xFFFE
	jr	00105$
00104$:
;kernel/memory.c:26: pages_table[page].addr = addr;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	push	bc
	ld	hl, #0x000A
	add	hl, sp
	ld	bc, #0x0004
	ldir
	pop	bc
;kernel/memory.c:27: pages_table[page].pid = pid;
	ld	l, c
	ld	h, b
	inc	hl
	ld	a,6 (ix)
	ld	(hl),a
;kernel/memory.c:29: pages_table[page].used = 1;
	ld	a,(bc)
	or	a,#0x01
	ld	(bc),a
;kernel/memory.c:30: return 0;
	ld	hl,#0x0000
00105$:
	pop	ix
	ret
;kernel/memory.c:33: int page_unmap(int page)
;	---------------------------------
; Function page_unmap
; ---------------------------------
_page_unmap::
	push	ix
	ld	ix,#0
	add	ix,sp
;kernel/memory.c:35: if (page >= PAGES_MAX_COUNT)
	ld	a,4 (ix)
	sub	a, #0x20
	ld	a,5 (ix)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	C,00102$
;kernel/memory.c:36: return -1;
	ld	hl,#0xFFFF
	jr	00105$
00102$:
;kernel/memory.c:38: if (pages_table[page].used == 0)
	ld	de,#_pages_table+0
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl,de
	ld	e,l
	ld	d,h
	ld	a,(hl)
	and	a,#0x01
	jr	NZ,00104$
;kernel/memory.c:39: return -2;
	ld	hl,#0xFFFE
	jr	00105$
00104$:
;kernel/memory.c:41: pages_table[page].used = 0;
	ld	a,(de)
	and	a,#0xFE
	ld	(de),a
;kernel/memory.c:42: return 0;
	ld	hl,#0x0000
00105$:
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
