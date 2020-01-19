# Record
A record consists of the following

record = (label) + ([instruction | directive] + (1{operands}3)) + (comments)

## Label
labels must start with a alphabetic character or _ with other character begin alphanumeric or _. Length of label must not exceed 32 characters.

label = 1{alphabetic}1 + 0{alphanumeric}31

## Instructions
There are 36 instructions. 9 of the instructions are related to branching. 13 are arithmetic or logical operations. 4 instructions for swapping for rotations. 2 memory operations. 1 for control vector. 1 conditional execution. 4 move operations. 2 move operations with offsets.

See ISA for details.

## Operands
There are 18 different operand types.

TYPE | # OPS | OPTYPE1 | OPTYPE2 | OPTYPE3 | NOTES
Branching 1 [ #V | $V | ch | lsym | usym] - 
only even values, -1024 <= offset <= 1022, BL: -8192 <= offset <= 8190 Arith 2 [ #C | $C | ch | reg | rsym | usym | lsym ] [ reg | rsym | usym ] - lsym and ch must be a predefined constant SWAP 2 [ reg | usym | rsym ] [ reg | usym | rsym ] SingleOp 1 [ reg | usym | rsym ] - LD 2 ([ '+' | '-' ]) + [ reg | rsym | usym ] + ([ '+' | '-' ]) [ reg | usym | rsym ] - modifiers are '+' or '-' either before or after ST 2 [ reg | usym | rsym ] ([ '+' | '-' ]) + [ reg | rsym | usym ] + ([ '+' | '-' ]) - modifiers are '+' or '-' either before or after SVC 1 [ #V | $V | ch |usym | lsym ] - - 0 <= value <= 15
CEX 3
[ "EQ" | "NE" | "CS" | "HS" | "CC" | "LO" | "MI" | "PL" | "VS" | "VC" | "HI" | "LS" | "GE" | "LT" | "GT" | "LE" | "AL" ] [ #V | $V | usym | lsym ] [ #V | $V | usym | lsym ] 0 <= value <= 7 REG_INIT 2 [ #V | $V | ch | usym | lsym ] [ reg | usym | rsym ] LDR 3 [ reg | usym | rsym ] [ #V | $V | ch | usym | lsym ] [ reg | usym | rsym ] -64 <= value <= 63 STR 3 [ reg | usym | rsym ] [ reg | usym | rsym ] [ #V | $V | ch | usym | lsym ] -64 <= value <= 63 ALIGN 0 - - - inc LC if LC odd BSS 1 [ #V | $V | ch | lsym ] - - inc LC by value of OP1 BYTE 1 [ #V | $V | ch | usym | lsym ] - - inc LC by 1 END 0 or 1 [ #V | $V | ch | lsym ] - - optional operand 
EQU 1 [ #V | $V | ch | reg | rsym | lsym ] - 
must be prededed by a label that was previously unknown or not in the symbol table ORG 1 [ #V | $V | ch | lsym ] - - change LC to value of OP1 WORD 1 [ #V | $V | ch | usym | lsym ] - - inc LC by 2