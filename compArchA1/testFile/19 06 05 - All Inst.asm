;
; Assemble all instructions
; Check opcodes
;
; Larry Hughes
; 28 May 2019 - Modified for XM2
;  1 May 2019 - Original test
; 
r0	equ	R0
r1	equ	R1
r2	equ	R1
r3	equ	R1
r4	equ	R1
r5	equ	R5
LR	equ	r5
r6	equ	R6
SP	equ	R6
r7	equ	R7
PC	equ	R7
;
CONST0	EQU	#0
CONST1	EQU	#1
CONST2	EQU	#2
CONST4	EQU	#4
CONST8	EQU	#8
CONST16	EQU	$10
CONST32	EQU	$20
CONSTN1	EQU	$FF
CONSTN1a	EQU	#-1
CONSTN1b	EQU	$ffff
;
	org	#64
;
	LD	R1,R2
	LD.B	R2,R3
	ST	R1,R2
	ST.B	R2,R3
;
	LD	R1+,R2
	LD	R1-,R2
	LD	+R1,R2
	LD	-R1,R2
;
	LD.B	R1+,R2
	LD.B	R1-,R2
	LD.B	+R1,R2
	LD.B	-R1,R2
;
	ST	R1,R2+
	ST	R1,R2-
	ST	R1,+R2
	ST	R1,-R2
;
	ST.B	R1,R2+
	ST.B	R1,R2-
	ST.B	R1,+R2
	ST.B	R1,-R2
;
;	LDR	R1,#-500,R2	; Invalid relative value
	LDR	R2,#5,R3
	LDR.B	R2,$5,R3
	STR	R2,R3,#-15
	STR.B	R2,R3,$5
;
	MOVL	$1a,R3
	MOVLZ	'A',R3
	MOVH	$1234,R3	; '12' in R3
; Branching
	ORG	$100
LOOP
	ORG	$200
	BL	LOOP
	BNE	LOOP
	BNZ	LOOP
	BEQ	LOOP
	BZ	LOOP
	BNC	LOOP
	BLO	LOOP
	BC	LOOP
	BHS	LOOP
	BN	LOOP
	BGE	LOOP
	BLT	LOOP
	BRA	LOOP
;
	ORG	$300
	BL	FWDREF
	BNE	FWDREF
	BNZ	FWDREF
	BEQ	FWDREF
	BZ	FWDREF
	BNC	FWDREF
	BLO	FWDREF
	BC	FWDREF
	BHS	FWDREF
	BN	FWDREF
	BGE	FWDREF
	BLT	FWDREF
	BRA	FWDREF
;
	ORG	$400
FWDREF
;
; Register-register
	ADD	R1,R2
	ADD.B	R2,R3
	ADDC	R2,R3	; ADD with Carry
	ADDC.B	R2,R3
	SUB	R2,R3
	SUB.B	R2,R3
	SUBC	R2,R3
	SUBC.B	R2,R3
; 
; This might require changes to the pre-assembler
	DADD	R1,R2	; BCD arithmetic
	DADD.B	R2,R3	; BCD arithmetic
;
	CMP	R2,R3
	CMP.B	R2,R3
	XOR	R2,R3
	XOR.B	R2,R3
	AND	R2,R3
	AND.B	R2,R3
	BIT	R2,R3
	BIT.B	R2,R3
	BIC	R2,R3
	BIC.B	R2,R3
	BIS	R2,R3
	BIS.B	R2,R3
	MOV	R2,R3
	MOV.B	R2,R3
; Constant-register
	ADD	$1,R2
	ADD.B	$1,R3
	ADDC	$1,R3
	ADDC.B	$1,R3
	SUB	#1,R3
	SUB.B	#1,R3
	SUBC	#1,R3
	SUBC.B	#-1,R3
	SUBC.W	$FF,R3
	SUBC	$ffff,R3
; Named constant-register
	ADD	CONST0,R2
	ADD.B	CONST1,R3
	ADDC	CONST2,R3
	ADDC.B	CONST4,R3
	SUB	CONST8,R3
	SUB.B	CONST16,R3
	SUBC	CONST32,R3
	SUBC.B	CONSTN1,R3	
	SUBC.B	CONSTN1a,R3
	SUBC.B	CONSTN1b,R3
;
	ADD	CONST0,r2
	ADD.B	CONST1,r3
	ADDC	CONST2,r4
	ADDC.B	CONST4,r5
	SUB	CONST8,r6
	SUB.B	CONST16,r7
	SUBC	CONST32,PC
	SUBC.B	CONSTN1,LR	
	SUBC.B	CONSTN1a,SP
	SUBC.B	CONSTN1b,r6
;
	DADD	#1,R2	; BCD
	DADD.B	$1,R3	; BCD
;
	CMP	$1,R3
	CMP.B	$1,R3
	XOR	$1,R3
	XOR.B	$1,R3
	AND	$1,R3
	AND.B	#1,R3
	BIT	#1,R3
	BIT.B	#1,R3
	BIC	#1,R3
	BIC.B	#1,R3
	BIS	#1,R3
	BIS.B	$1,R3
;
	SWAP	R1,R2
;
	SRA	R3
	SRA.B	R2
	RRC	R3
	RRC.B	R2
	SWPB	R2
	SXT	R2
;
;
; New instructions for XM2
; CEX - Conditional execution
; SVC - Supervisory call
;
VECT3	equ	$3
VECT4	equ	#4
;
	org	$1000
;
	SVC	#15
	svc	#0
	svc	VECT3
;
;	svc	#-4
;
	org	#5000
	CEX	EQ,#3,#4
	CEX	NE,#0,#3
	CEX	AL,#0,#0
	CEX	LS,#7,#7
;
; Invalid CC, TC, and FC
;	cex	XX,#3,#4
;	cex	LT,#9,#4
;	cex	gt,#2,#-4
;

	END	LOOP
