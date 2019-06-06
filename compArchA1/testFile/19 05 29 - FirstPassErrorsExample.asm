;
; Examples of some first pass errors
; - Look at console output and .LIS file
;
; L. Hughes
; 29 May 2019 - Revised for XM2
; 11 May 2018 - original

; Missing operand:
START	equ

; Invalid operand
	byte	'123'

; Unexpected operand
	align	R1

; Missing '#' or '$':
	org	100

; Symbols not in symbol table:
	ld	r0,r1	

; Unknown instruction:
Loop	lda	r3

; >"< not supported, should be >'<:
Data	byte	"x"

; Operands in wrong order:
	add	R0,#1	

; Unknown instruction (beqx) treated as a label.  "Loop" then examined
; and treated as an instruction:
	beqx	loop

; Unknown register
	swap	R1,R8	

; Bad BSS value - unknown value
	BSS	ArraySize

; Duplicate label
START	equ	#12

; Start not defined (put in symbol table as UNK - unknown symbol):
	end	Start