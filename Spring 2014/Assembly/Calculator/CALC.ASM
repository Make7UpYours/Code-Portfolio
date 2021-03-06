	TITLE	CALCULATOR
	PAGE	60, 132
;
;	This program is a simple calculator program where
;	the user will enter a math operation and the program
;	will output the correct result.
;	written by William Freeman
;	on April 22, 2014
;
;	define constants
;
CR	EQU	0DH		;define carriage return
LF	EQU	0AH		;define line feed
EOT	EQU	'$'		;define end of text marker
NULL	EQU	0		;define NULL byte
QUIT	EQU	'n'		;define program quit byte
SPACE	EQU	' '		;define ASCII space char
;
;	define MACROS
;
READSTR	MACRO
	MOV	AH, 0AH		;set function code
	LEA	DX, #1		;point to buffer
	INT	21H		;read string from keyboard
	#EM
WRITE	MACRO
	LEA	DX, #1		;point to message
	MOV	AH,09H		;set function code
	INT	21H		;write the message
	#EM
READCH	MACRO
	MOV	AH, 01H		;set function code
	INT	21H		;read char from keyboard
	#EM
;
;	define variables
;
	JMP	START		;jump over variable definations
WELCOME	DB	"*********************************************************",CR,LF,
	DB	"* Simple Calculator:                                    *",CR,LF,
	DB	"* Enter the math operation you would like to compute    *",CR,LF,
	DB	"* and the program will perform the specified operation. *",CR,LF,
	DB	"*                                                       *",CR,LF,
	DB	"* You are limited performing operations on numbers      *",CR,LF,
	DB	"* that are 3-digits or less.                            *",CR,LF,
	DB	"*********************************************************",EOT
INPRMPT	DB	CR,LF,LF,"Enter equation (ex. xxx * xxx for multiplication):",CR,LF,EOT
MATH	DB	10,?,10 DUP ?
AGAIN	DB	CR,LF,LF,"Would you like to compute another equation? (y/n): ",EOT
BNUM1	DB	0
BNUM2	DB	0
OPCODE	DB	1 DUP ?
ASCNUM1	DB	3 DUP ?
ASCNUM2	DB	3 DUP ?
ERMSG	DB	CR,LF,LF,"Invalid mathematical operation used, try agian.",EOT
RESULT	DB	5 DUP ?,EOT
NEWLN	DB	CR,LF,EOT
EQUSIGN	DB	"= ",EOT
REMAIN	DB	5 DUP ?,EOT
REMSG	DB	'r',EOT
;
;	Code Segment
;
START:	WRITE 	WELCOME		;display program info

CALC:	WRITE	INPRMPT		;prompt user for input
	READSTR	MATH		;obtain input from user

	LEA	SI, MATH+2	;point to equation data
	LEA	DI, ASCNUM1	;point to first ASCII num
	CALL	BTX		;store first number in ASCII
	CALL	FINDNEXT	;find next token in equation

	MOV	BL, [SI]	;prep for opcode storage
	MOV	OPCODE, BL	;store opcode
	INC	SI		;point to location after opcode

	CALL	FINDNEXT	;find next token in equation
	LEA	DI, ASCNUM2	;point to second ASCII num
	CALL	BTX		;store second number in ASCII

	LEA	SI, ASCNUM1	;point to first ASCII number
	CALL 	A2B8		;convert to binary
	MOV	BNUM1, AL	;store first binary number

	LEA	SI, ASCNUM2	;point to second ASCII number
	CALL	A2B8		;convert to binary
	MOV	BNUM2, AL	;store second binary number

	LEA	SI, RESULT	;point SI to result location
	LEA	DI, REMAIN	;point to remainder data location
	MOV	AL, BNUM1	;load first binary number
	MOV	BL, BNUM2	;load second binary number

	MOV	AH, OPCODE	;prep for opcode determination
	CMP	AH, '+'		;check for addition
	JNE	N1		;continue to determine opcode

	CALL	ADDUP		;add the two numbers
	JMP	ENDX		;operation complete

N1:	CMP	AH, '-'		;check for subtraction
	JNE	N2		;continue to determine opcode	
	CALL	SUBEM		;subtract the two numbers
	JMP	ENDX		;operation complete

N2:	CMP	AH, '*'		;check for multiplication
	JNE	N3		;continue to determine opcode
	CALL	MULTIPLY	;multiply the two numbers
	JMP	ENDX		;operation complete

N3:	CMP	AH, '/'		;check for division
	JNE	N4		;bad opcode
	CALL	DIVIDE		;divide the two numbers
	JMP	ENDXX		;operation complete

N4:	WRITE	ERMSG		;bad user
	JMP	CALC		;force them to try again

ENDX:	WRITE	NEWLN		;move to next line
	WRITE	EQUSIGN		;display equals sign
	WRITE	SI		;display result
	
ENDXX:	WRITE	AGAIN		;ask user if they would like to quit
	READCH			;obtain user's answer
	OR	AL, 20H		;convert UC to LC
	CMP	AL, QUIT	;determine if user wants to quit
	JE	DONE		;quit program
	JMP	CALC		;start over again

DONE:	MOV	AX, 4C00H	;clean exit
	INT	21H


;
;***************************************************************************
;	SUBROUTINES
;***************************************************************************
;
;	Subroutine SLZ
;
;	This subroutine suppresses leading zeros from an ASCII set
;	of numbers
;
;	Entry:	SI points to ASCII numbers
;	Exit:	Numbers no longer have leading zeros
;
SLZ:	MOV	CX, 4		;set counter
SLZ0:	CMP	B[SI], '0'	;check for zero
	JNE	SLZ1		;done if no zeros
	INC	SI		;point to next number
	LOOP	SLZ0		;dec counter and start all over again
SLZ1:	RET
;
;***************************************************************************
;
;	Subroutine BTX
;
;	This subroutine separates a token from input string
;
;	Entry:	SI points to input data.
;		DI points to the save location of the token
;	Exit:	SI, DI modified
;
BTX:	MOV	CX, 0		;clear byte counter
P0:	CMP	B[SI], SPACE	;look for end of first token
	JE	P1		;found space
	CMP	B[SI], CR	;maybe it was a carriage return
	JE 	P1		;yes, treat it as a space
	INC	SI		;not fund, advance pointer
	INC	CL		;add 1 to count
	JMP	P0		;countinue counting
P1:	ADD	DI, 2		;find end of output buffer
	PUSH	SI		;save input pointer
	DEC	SI		;point SI to last input character
	MOV	DL, 3		;set output byte transfer count
P3:	MOV	AL, B[SI]	;get input byte
	DEC	SI		;back up input pointer
	MOV	B[DI], AL	;transfer to output
	DEC	DI		;back up output pointer
	DEC	DL		;decrement output count
	DEC	CL		;decrement input count
	JNZ	P3		;countinue byte transfer
	CMP	DL, 0		;has output buffer been filled?
	JE	P5		;yes, token is transfered
P4:	MOV	B[DI], 30H	;no, back fill with ASCII 0
	DEC	DI		;point back
	DEC	DL		;decrement output count
	JNE	P4		;continue fill
P5:	POP	SI		;restore input pointer
	RET
;
;***************************************************************************
;
;	Subroutine FINDNEXT
;
;	This subroutine locates the next token in a string
;
;	Entry:	SI points to space after previous token
;	Exit:	SI points to the next token
;
FINDNEXT:
	CMP	B[SI], SPACE	;look for spaces
	JNE	FN0		;not a space, must be a token
	INC	SI		;point to next character
	JMP	FINDNEXT	;check next character
FN0:	RET
;
;***************************************************************************
;
;	Subroutine A2B8
;
;	A subroutine to convert 3 ASCII numbers into 8 bit binary
;
;	Entry:	SI points to three ASCII bytes
;	Exit:	8 bit binary returned in AL
;
A2B8:	AND	B[SI], 0FH		;convert ASCII bytes to binary

	AND	B[SI+1], 0FH
			
	AND 	B[SI+2], 0FH

	MOV 	AH, 0			;clear multiplicand

	MOV 	AL, B[SI]		;get 100's bytes
				
	MOV	BL, 100

	MUL 	BL			;make binary

	MOV 	BH, AL			;save it
				
	MOV 	AH, 0

	MOV 	AL, B[SI+1]		;get tens digit
	MOV 	BL, 10			
					
	MUL 	BL			;make binary

	ADD 	AL, BH			;add to hundreds

	ADD 	AL, B[SI+2]		;add units

	RET


;
;***************************************************************************
;
;	Subroutine B2A8
;
;	This subroutine converts an 8 bit binary value into three bytes
;	of ASCII
;
;	Entry:	DI points to save buffer for ASCII
;		AL holds 8 bit value to convert
;	Exit:	none
;	Uses: CX as a counter
;
B2A8:	MOV	CX, 0		;clear counter
HUND:	SUB	AL, 100		;subtract 100
	JC	TENS		;if over subtracted, process tens
	INC	CX		;otherwise add to hundreds count
	JMP	HUND		;check for another hundred
TENS:	MOV	[DI], CL	;save hundreds count
	ADD	AL, 100		;add back excessive subtraction
	MOV	CX, 0		;clear counter
TENS1:	SUB	AL, 10		;count how many tens
	JC	UNITS		;subtracted too much
	INC	CX		;increment tens count
	JMP	TENS1		;count more
UNITS:	MOV	[DI+1], CL	;save tens count
	ADD	AL, 10		;restore count
	MOV	[DI+2], AL	;save units
	ADD	B[DI], 30H	;convert numbers to ASCII
	ADD	B[DI+1], 30H
	ADD	B[DI+2], 30H
	RET
;
;***************************************************************************
;
;	Subroutine B2A16
;
;	This subroutine converts a 16 bit binary value to 5 bytes of
;	ASCII
;
;	Entry:	SI points to the location where data is to be saved
;		AX holds the 16 bit value to convert
;	Exit:	SI holds the ASCII value of AX
;	Uses:	BX as a divisor, DX is altered
;
B2A16:	MOV	DX, 0		;clear DX
	MOV	BX, 10000	;load BX with divisor
	DIV	BX		;perform division
	MOV	B[SI], AL	;store the 0 - 9 digit
	ADD	B[SI], 30H	;add ASCII offset
	MOV	AX, DX		;move remaining value back to AX
	MOV	DX, 0		;clear DX
	MOV	BX, 1000	;load BX with divisor
	DIV	BX		;perform division
	MOV	B[SI+1], AL	;store thousands digit
	MOV	B[SI+1], 30H	;convert to ASCII
	MOV	AX, DX		;move remaining value back to AX
	MOV	BX, 0		;divisor now only 8 bits, clear BX
	MOV	BL, 100		;use BL to divide
	DIV	BL		;perform division
	MOV	B[SI+2], AL	;store hundreds digit
	ADD	B[SI+2], 30H	;convert to ASCII
	MOV	AL, AH		;move remaining value into AL
	MOV	AH, 0		;clear upper range
	MOV	BL, 10		;load BL with divisor
	DIV	BL		;determine tens value
	MOV	B[SI+3], AL	;store tens value
	ADD	B[SI+3], 30H	;convert to ASCII
	MOV	B[SI+4], AH	;remainder is the units
	ADD	B[SI+4], 30H	;convert to ASCII
	RET
;
;***************************************************************************
;
;	Subroutine ADDUP
;
;	This subroutine adds two 8 bit binary numbers together and
;	returns their result in ASCII form
;
;	Entry:	The first number to be added is stored in AL
;		The second number is stored in BL
;		SI points to the result location
;	Exit:	ASCII result is returned to the location pointed
;		to by SI
;	Uses:	B2A16 subroutine & SLZ subroutine
;
ADDUP:	MOV	AH, 0		;clear carry location
	ADD	AL, BL		;add first & second num
	ADC	AH, 0		;add carry
	CALL	B2A16		;convert AX to ASCII
	CALL	SLZ		;suppress leading zeros
	RET
;
;***************************************************************************
;
;	Subroutine SUBEM
;
;	This subroutine subtracts two 8 bit binary numbers and
;	returns their result in ASCII form
;
;	Entry:	The first number is stored in AL
;		The second number is stored in BL
;		SI points to the result location
;	Exit:	ASCII result is returned to the location pointed
;		to by SI
;	Uses:	B2A16 subroutine & SLZ subroutine
;
SUBEM:	SUB	AL, BL		;perform subtraction
	JNC	POS		;jump if result is positive
	MOV	AH, 0		;clear upper 8 bits
	NEG	AL		;perform 2's complement
	CALL	B2A16		;convert AX to ASCII
	CALL 	SLZ		;suppress the leading zeros
	DEC	SI		;point to previous data location
	MOV	B[SI], '-'	;insert negative sign
	RET			;return negative number
POS:	MOV	AH, 0		;clear upper 8 bits
	CALL	B2A16		;convert AX to ASCII
	CALL	SLZ		;suppress leading zeros
	RET
;
;***************************************************************************
;
;	Subroutine MULTIPLY
;
;	This subroutine multiplies two 8 bit binary numbers and
;	returns their result in ASCII form
;
;	Entry:	The first number is stored in AL
;		The second number is stored in BL
;		SI points to the result location
;	Exit:	ASCII result is returned to the location pointed
;		to by SI
;	Uses:	B2A16 subroutine & SLZ subroutine
MULTIPLY:
	MUL	BL		;perform multiplication
	CALL	B2A16		;convert AX to ASCII
	CALL	SLZ		;suppress leading zeros
	RET
;
;***************************************************************************
;
;	Subroutine DIVIDE
;
;	This subroutine divides two 8 bit binary numbers and
;	writes their result to the screen
;
;	Entry:	The first number is stored in AL
;		The second number is stored in BL
;		SI points to the result location
;		DI points to the remainder location
;	Exit:	ASCII result is returned to the location pointed
;		to by SI
;		ASCII remainder is retuned to the location pointed 
;		to by DI
;	Uses:	B2A16 subroutine & SLZ subroutine
;		WRITE macro
;		EQUSIGN variable & NEWLN variable
DIVIDE:	MOV	AH, 0		;clear AH for division
	DIV	BL		;perform division
	PUSH	AX		;save remainder
	MOV	AH, 0		;clear AH for quotient ASCII conversion
	CALL	B2A16		;convert to ASCII
	CALL	SLZ		;suppress quotient leading zeros
	POP	AX		;restore remainder
	MOV	AL, AH		;move remainder to AL for ASCII conversion
	MOV	AH, 0		;clear AH
	PUSH	AX		;save remainder
	WRITE	NEWLN		;display a new line
	WRITE	EQUSIGN		;display equals sign
	WRITE	SI		;display quotient
	LEA	SI, DI		;point to remainder data for ASCII
	POP	AX		;restore remainder
	CALL	B2A16		;convert remainder to ASCII
	CALL 	SLZ		;suppress leading zeros
	WRITE	REMSG		;display 'r'
	WRITE	SI		;display remainder
	RET
;