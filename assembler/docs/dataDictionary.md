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

## Symbol Table
Symbol table is made up of 3 components

Symbol = label + [UNKNOWN | REGISTER | SYMBOL] + value