;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Wed Aug 23 21:44:59 2017
;--------------------------------------------------------
	.module process
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _proc_table
	.globl _newpid
	.globl _fork
	.globl _exec
	.globl _spawn
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_proc_table::
	.ds 6375
_newpid_last_pid_1_11:
	.ds 1
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
;kernel/process.c:7: static pid_t last_pid = 0;
	ld	iy,#_newpid_last_pid_1_11
	ld	0 (iy),#0x00
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;kernel/process.c:5: pid_t newpid(void)
;	---------------------------------
; Function newpid
; ---------------------------------
_newpid::
;kernel/process.c:8: return ++last_pid;
	ld	hl, #_newpid_last_pid_1_11+0
	inc	(hl)
	ld	iy,#_newpid_last_pid_1_11
	ld	l,0 (iy)
	ret
;kernel/process.c:11: int fork(void)
;	---------------------------------
; Function fork
; ---------------------------------
_fork::
;kernel/process.c:14: }
	ret
;kernel/process.c:16: int exec(char *path, char *args)
;	---------------------------------
; Function exec
; ---------------------------------
_exec::
;kernel/process.c:19: }
	ret
;kernel/process.c:21: int spawn(char *path, char *args)
;	---------------------------------
; Function spawn
; ---------------------------------
_spawn::
;kernel/process.c:24: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
