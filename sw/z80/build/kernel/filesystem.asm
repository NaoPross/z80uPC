;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Wed Aug 23 21:44:59 2017
;--------------------------------------------------------
	.module filesystem
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _fs_parse_superblock
	.globl _fs_parse_path
	.globl _fs_get_inode
	.globl _fs_new_inode
	.globl _fs_free_inode
	.globl _fs_chmod
	.globl _fs_chown
	.globl _fs_rename
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
;kernel/filesystem.c:3: struct filesystem * fs_parse_superblock(struct filesystem *fs)
;	---------------------------------
; Function fs_parse_superblock
; ---------------------------------
_fs_parse_superblock::
;kernel/filesystem.c:5: return 0;
	ld	hl,#0x0000
	ret
;kernel/filesystem.c:9: uint16_t fs_parse_path(const char *path)
;	---------------------------------
; Function fs_parse_path
; ---------------------------------
_fs_parse_path::
;kernel/filesystem.c:11: return 0;
	ld	hl,#0x0000
	ld	e,l
	ld	d,h
	ret
;kernel/filesystem.c:15: inode_t * fs_get_inode(inode_t *buffer, uint16_t i_number)
;	---------------------------------
; Function fs_get_inode
; ---------------------------------
_fs_get_inode::
;kernel/filesystem.c:17: return 0;
	ld	hl,#0x0000
	ret
;kernel/filesystem.c:20: inode_t * fs_new_inode(inode_t *inode, const char *name)
;	---------------------------------
; Function fs_new_inode
; ---------------------------------
_fs_new_inode::
;kernel/filesystem.c:22: return 0;
	ld	hl,#0x0000
	ret
;kernel/filesystem.c:25: int fs_free_inode(const inode_t *inode)
;	---------------------------------
; Function fs_free_inode
; ---------------------------------
_fs_free_inode::
;kernel/filesystem.c:27: return 0;
	ld	hl,#0x0000
	ret
;kernel/filesystem.c:30: void fs_chmod(inode_t *inode, uint8_t mode)
;	---------------------------------
; Function fs_chmod
; ---------------------------------
_fs_chmod::
;kernel/filesystem.c:32: }
	ret
;kernel/filesystem.c:34: void fs_chown(inode_t *inode, uint8_t uid)
;	---------------------------------
; Function fs_chown
; ---------------------------------
_fs_chown::
;kernel/filesystem.c:37: }
	ret
;kernel/filesystem.c:39: int fs_rename(inode_t *inode, const char *name)
;	---------------------------------
; Function fs_rename
; ---------------------------------
_fs_rename::
;kernel/filesystem.c:41: return 0;
	ld	hl,#0x0000
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
