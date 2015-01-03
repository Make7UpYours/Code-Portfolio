	TITLE	BUBBLE SORT
	PAGE	60, 132
;
;	This program takes a dataset input from the user and
;	performs a bubble sort on the dataset.
;	written by William Freeman
;	on March 25, 2014
;
;	define constants
;
CR	EQU	0DH		;define carriage return
LF	EQU	0AH		;define line feed
EOT	EQU	'$'		;define end of text marker
NULL	EQU	0		;define NULL byte
SPACE	EQU	' '		;define ASCII space
;
;	define MACROS
;
READ	MACRO
	LEA	DX, #1		;point to input buffer
	MOV	AH, 0AH		;set function code
	INT	21H		;read string from keyboard
	#EM
WRITE	MACRO
	LEA	DX, #1		;point to message
	MOV	AH,09H		;set function code
	INT	21H		;write the message
	#EM
;
;	define variables
;
	JMP	START		;jump over variable definations
DATAMSG	DB	"Enter a sequence to be sorted: ", EOT
NSRTMSG	DB	CR,LF,LF, "Your original unsorted data:",CR,LF,LF,EOT
SRTMSG	DB	CR,LF,LF, "Sorted data:", CR,LF,LF,EOT
INBUF	DB	50, ?, 50 DUP ?
;
;	Code Segment
;
START:	WRITE	DATAMSG		;prompt user for input
	READ	INBUF		;read input from user
	WRITE	NSRTMSG		;display unsorted data entered

	LEA	SI, INBUF+2	;point to data
	CALL	PRINT		;print the unsorted data

	WRITE	SRTMSG		;display sorted data
	LEA	SI, INBUF+2	;point to data
	CALL	BSORT		;perform bubble sort
	CALL	PRINT		;print the sorted data

	MOV	AX, 4C00H	;clean exit
	INT	21H
;
;***************************************************************************
;	SUBROUTINES
;***************************************************************************
;	Subroutine PRINT
;
;	This subroutine reads through a dataset and prints off
;	each element of the data set with spaces between each
;	element.
;
;	ENTRY:	SI points to the first element in the dataset to be printed.
;	EXIT:	The dataset is printed to the screen.
;
PRINT:	MOV	CL, B[SI-1]	;number of times to loop
XLOOP:	MOV	AH, 02H		;set function code
	MOV	DL, B[SI]	;load in next data element
	INT	21H
	MOV	DL, SPACE	;print a space
	INT	21H
	INC	SI
	DEC	CL
	JNE	XLOOP		;loop until all data is printed
	RET
;
;	Subroutine BSORT
;
;	This subroutine iterates though a dataset and uses the
;	bubblesort algorithm to sort the elements in descending
;	order.
;
;	ENTRY:	SI points to the first element in the dataset to be sorted.
;	EXIT:	The dataset is now sorted.
;
BSORT:	MOV	BH, B[SI-1]	;obtain the outter loop count
	MOV	BL, B[SI-1]	;obtain the inner loop count
	DEC	BL		;inner loop is run n-1 times
OUTTER:	MOV	CL, BL		;load the inner loop count

INNER:	MOV	AL, B[SI]	;compare values
	CMP	AL, B[SI+1]
	JAE	NOSWP		;data element is not less than next element

	MOV	AH, B[SI]	;load current dataset element
	MOV	AL, B[SI+1]	;load next dataset element
	MOV	B[SI+1], AH	;swap elements
	MOV	B[SI], AL

NOSWP:	INC 	SI		;point to next data element
	DEC	CL		;decrease inner loop count
	JNE	INNER		;inner loop until CL == 0
	LEA	SI, INBUF+2	;point back to first data element
	DEC	BH		;decrease outter loop count
	JNE	OUTTER		;outter loop until BH == 0
	RET
