	TITLE	GUESS GAME
	PAGE	60, 132
;
;	This program requires two people, one dealer and
;	player. The dealer has the player guess the number
;	and the player has 3 tries to guess that number.
;	if the player guesses within 3 tries, they win.
;	written by William Freeman
;	on April 9, 2014
;
;	define constants
;
CR	EQU	0DH		;define carriage return
LF	EQU	0AH		;define line feed
EOT	EQU	'$'		;define end of text marker
NULL	EQU	0		;define NULL byte
QUIT	EQU	'n'		;define game quit byte
;
;	define MACROS
;
READ	MACRO
	MOV	AH, 01H		;set function code
	INT	21H		;read char from keyboard
	#EM
WRITE	MACRO
	LEA	DX, #1		;point to message
	MOV	AH,09H		;set function code
	INT	21H		;write the message
	#EM
NOECHO	MACRO
	MOV	AH, 08H		;set function code
	INT	21H		;read char from keyboard, do not echo
	#EM
CHKGNUM	MACRO
	DEC	CL		;player has used one guess
	JZ	NOGUESS		;player is out of guesses
	#EM
CHKRND	MACRO
	INC	CH		;increase current round number
	CMP	CH, 10		;determine if max rounds have been played
	JE	MAXRND		;jump if rounds played are equal to 10	
	#EM
SAVERND	MACRO
	ADD	CH, 30H		;convert to ASCII
	MOV	ROUND, CH	;store round number
	MOV	B[SI], CH	;save round number for results
	ADD	SI, 2		;add space between round # and dealer's #
	SUB	CH, 30H		;convert back to binary
	#EM
NEWLINE	MACRO
	INC	SI		;point to an empty data location
	MOV	B[SI], CR	;store a carriage return
	INC	SI		;point to next data location
	MOV	B[SI], LF	;store a line feed
	INC	SI		;point to next data location for round #
	#EM
DETWIN	MACRO
	CMP	CL, 3		;determine if user has 3 guesses left
	JE	WIN25		;player wins 25 dollars
	CMP	CL, 2		;determine if user has 2 guesses left
	JE	WIN10		;player wins 10 dollars
	JMP	WIN5		;player has won their bet back
	#EM
;
;	define variables
;
	JMP	START		;jump over variable definations
PRGMSG	DB	"************************************************************",CR,LF,
	DB	"* Game Information:                                        *",CR,LF,
	DB	"* Requires one dealer and one player, the dealer           *",CR,LF,
	DB	"* chooses a number and the player has three tries          *",CR,LF,
	DB	"* to guess that number.                                    *",CR,LF,
	DB	"*                                                          *",CR,LF,
	DB	"* If the player guesses the number on the first try,       *",CR,LF,
	DB	"* they win 25, 10 on second try, and 5 dollars on the last.*",CR,LF,
	DB	"*                                                          *",CR,LF,
	DB	"* After each guess the player will be given a hint,        *",CR,LF,
	DB	"* letting the player know if their guess is too high       *",CR,LF,
	DB	"* or too low.                                              *",CR,LF,
	DB	"*                                                          *",CR,LF,
	DB	"* The game will keep going if they player wants to for     *",CR,LF,
	DB	"* a maximum of ten rounds. At the end of the game, a       *",CR,LF,
	DB	"* report will be outputted with all the results from       *",CR,LF,
	DB	"* each round.                                              *",CR,LF,
	DB	"************************************************************",EOT
DPRMPT	DB	CR,LF,LF,"Dealer, enter your number: ",EOT
GPRMPT	DB	CR,LF,LF,"Player, enter your guess: ",EOT
AGAIN	DB	CR,LF,LF,"Would you like to play another round? (y/n): ",EOT
BADNUM	DB	CR,LF,LF,"Dealer, you did not enter a valid number. Try again!",EOT
TOOLO	DB	CR,LF,LF,"Your guess was a little too low, try again.",EOT
TOOHI	DB	CR,LF,LF,"Your guess was a little too high, try again.",EOT
WINNER	DB	CR,LF,LF,"Your guess was just right, you win!",EOT
NOMORE	DB	CR,LF,LF,"You have reached the maximum number of rounds.",EOT
GAMEOVA	DB	CR,LF,LF,"Sorry, you have no more guesses and you lose.",EOT
EOR	DB	CR,LF,LF,"Thats the end of the round, the dealers number was: "
DEALNUM	DB	' ',EOT
DISPRND	DB	CR,LF,LF,"ROUND NUMBER: "
ROUND	DB	' ',EOT
DASHES	DB	CR,LF,"---------------",EOT
RMSG	DB	CR,LF,LF,"GAME RESULTS:",CR,LF,
	DB	"-------------",CR,LF,
	DB	"R D 1 2 3 RW",CR,LF,
	DB	"- - - - - --",CR,LF
RESULT	DB	255 DUP ' ',EOT
;
;	Code Segment
;
START:	WRITE	PRGMSG		;display program information
	LEA	SI, RESULT	;point to location to store data
	MOV	CH, 0		;current round number

GAME:	SAVERND			;store the round number for output
	WRITE	DISPRND		;display the current round number
	WRITE	DASHES		;make output pretty

	WRITE	DPRMPT		;prompt dealer for number
	NOECHO			;obtain dealer's number (Stored in AL)
	CALL	NUMVALID	;check dealer input
	JC	BAD		;bad input, display message for dealer

	MOV	BH,AL		;temp storage of dealer's number
	MOV	B[SI], AL	;save dealer's number for results
	ADD	SI, 2		;add space between dealer's # and player's #
	MOV	CL, 3		;the number of guesses a player has

GUESS:	WRITE	GPRMPT		;prompt player for guess
	READ			;obtain player's number (Stored in AL)

	MOV	B[SI], AL	;save player's number for results
	ADD	SI, 2		;add space between the player's numbers

	CMP	AL, BH		;compare dealer's and player's number
	JB	LO		;player's number is too low
	JA	HI		;player's number is too high
	JE	WIN		;player's number is just right

CONT:	MOV	DEALNUM, BH	;store dealer's number for output
	WRITE	EOR		;display the end of round message
	NEWLINE			;add a new line for the next round

	WRITE	AGAIN		;ask player if they want to continue
	READ			;obtain player's answer (Stored in AL)
	OR	AL, 20H		;convert UC to LC
	CMP	AL, QUIT	;determine if user wants to quit
	JE	DONE		;quit program
	JMP	GAME		;start a new game

DONE:	WRITE	RMSG		;display game results

	MOV	AX, 4C00H	;clean exit
	INT	21H

BAD:	WRITE	BADNUM		;display message for dealer
	JMP	GAME		;reprompt dealer for input

LO:	WRITE	TOOLO		;display message for too low of a guess
	CHKGNUM			;determine if there are any more guesses
	JMP	GUESS		;ask for next guess from player

HI:	WRITE	TOOHI		;display message for too high of a guess
	CHKGNUM			;determine if there are any more guesses
	JMP	GUESS		;ask for next guess from player

WIN:	WRITE	WINNER		;player has won
	DETWIN			;determine how much the player has won

WIN25:	ADD	SI,4		;move SI to point to RW
	MOV	B[SI],'2'	;insert ASCII 2 for result output
	INC	SI		;point to next data slot
	MOV	B[SI],'5'	;insert ASCII 5 for result output

	CHKRND			;see if there are more rounds to be played
	JMP	CONT		;see if player would like to play again

WIN10:	ADD	SI,2		;move SI to point to RW
	MOV	B[SI],'1'	;insert ASCII 1 for result output
	INC	SI		;point to next data slot
	MOV	B[SI],'0'	;insert ASCII 0 for result output

	CHKRND			;see if there are more rounds to be played
	JMP	CONT		;see if player would like to play again

WIN5:	INC	SI		;move SI to point to RW
	MOV	B[SI],'5'	;insert ASCII 5 for result output

	CHKRND			;see if there are more rounds to be played
	JMP	CONT		;see if player would like to play again

MAXRND:	WRITE	NOMORE		;let player know they can no longer play
	JMP	DONE		;display results

NOGUESS:
	WRITE	GAMEOVA		;let the player know they lost
	INC	SI		;add space 
	MOV	B[SI], '0'	;player has won zero dollars this round
	CHKRND			;see if there are more rounds to be played
	JMP	CONT		;ask if they want to go again
;
;***************************************************************************
;	SUBROUTINES
;***************************************************************************
;
;	Subroutine "0" - "9" Validity
;
;	Tests a valid for ASCII number 0 to 9
;
;	Entry:	Number to be tested is in AL
;	Exit:	Returns CF = 0 if valid
;		Returns CF = 1 if invalid
NUMVALID:
	CMP	AL, '0'		;test low range
	JB	NOTVLD		;too low, error flag is set (CF = 1)
	CMP	AL, '9'		;test high range
	JA	NOTVLD		;too high, error flag is set (CF = 1)
	CLC			;valid, clear error flag (CF = 0)
	RET
NOTVLD:	STC			;set not valid flag (CF = 1)
	RET
;
