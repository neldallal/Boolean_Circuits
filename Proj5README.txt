CSC 173

Project 5

Claudia Cortell
ccortell@u.rochester.edu

Nadine Eldallal
neldalla@u.rochester.edu

Build instructions:
1. cd into the folder containing the project files
2. run:
gcc -std=c99 -Wall -Werror -o main main.c Boolean.c Circuit.c Gates.c -lm


Run instructions:
Run: ./main

Notes:
- We did not implement the NAND gate needed in circuit b. Instead, we
	created an equivalent circuit by inverting the result of an AND gate 
	where there originally is a NAND gate.

- We did extra credit option 1, which is implementing boolean functions
	f and g. These functions are implemented in methods circuit_F and 
	circuit_G. These circuits were built using the minterm method.

