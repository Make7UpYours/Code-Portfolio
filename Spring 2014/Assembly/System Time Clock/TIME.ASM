	TITLE	SYSTEMTIME CLOCK
	PAGE	60, 132
;
;	This program reads the system time clock from the BIOS and
;	prints it back to the screen along with the current date.
;	written by William Freeman
;	on March 5, 2014
;
;	define constants
;
CR	EQU	0DH	;define carriage return
LF	EQU	0AH	;define line feed
EOT	EQU	'$'	;define end of text marker
NULL	EQU	0	;define NULL byte
;
;	define variables
;
	JMP	START	;jump over variable definitions
TMSG	DB	"Current System Time: "
TIME	DB	2 DUP ?,':',2 DUP ?,':',2 DUP ?,EOT
DMSG	DB	CR, LF, "Current System Date: "
DATE	DB	2 DUP ?, " ", 2 DUP ?, ", ", 4 DUP ?, EOT
;
;	Code Segment
;
START:	MOV	AH, 02H		;read BIOS time-clock
	INT	1AH		;CH->hrs, CL->min, DH->sec

	LEA	SI, TIME	;point to TIME data
	MOV	AL, CH		;store hours
	CALL	BCDASC		;convert hours from BCD to ASCII

	ADD	SI, 2		;point to mins
	MOV	AL, CL		;store mins
	CALL	BCDASC		;convert mins from BCD to ASCII

	ADD	SI, 2		;point to secs
	MOV	AL, DH		;store secs
	CALL	BCDASC		;convert secs from BCD to ASCII

	MOV	AH, 09H		;display time
	LEA	DX, TMSG	
	INT	21H

	MOV	AH, 04H		;read BIOS date
	INT	1AH		;CH->cent, CL->year, DH->month, DL->day

	LEA	SI, DATE	;point to DATE data
	MOV	AL, DH		;store month
	CALL	BCDASC		;convert month from BCD to ASCII

	ADD	SI, 2		;point to day
	MOV	AL, DL		;store day
	CALL	BCDASC		;convert day from BCD to ASCII

	ADD	SI, 3		;point to cent
	MOV	AL, CH		;store cent
	CALL	BCDASC		;convert cent from BCD to ASCII

	ADD	SI, 1		;point to year
	MOV	AL, CL		;store year
	CALL	BCDASC		;convert year from BCD to ASCII

	MOV	AH, 09H		;display date
	LEA	DX, DMSG
	INT 	21H

	MOV	AX, 4C00H	;clean exit
	INT	21H
;
;***************************************************************************
;	SUBROUTINES
;***************************************************************************
;	Subroutine BCSDASC
;	
;	This subroutine converts a byte of BCD into two bytes of
;	printable ASCII characters. No error checking is performed.
;
;	ENTRY:	SI points to the location where ASCII values are to be stored
;		AL contains the BCD byte
;	EXIT:	The BCD byte is converted to ASCII format for screen output
;		The ASCII bytes will be stored in the memory location that SI 
;		points to sequentially
BCDASC:	MOV	AH, AL		;save BCD
	SHR	AL, 4		;shift 4-bits

	ADD	AL, 30H		;make ASCII
	MOV	B[SI], AL	;save ASCII
	INC	SI		;point to next byte

	AND	AH, 0FH		;max out lower 4-bits
	ADD	AH, 30H		;make ASCII
	MOV	B[SI], AH	;save ASCII

	RET