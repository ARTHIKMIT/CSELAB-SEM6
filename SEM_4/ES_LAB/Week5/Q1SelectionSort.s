	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =ARR
	MOV R1, #0 ;loop counter i
	ADD R7, R0, #36 ;index for last element
	
	MOV R9, #10
loop			;storing data in array (10 to 1 descending order)
	STR R9, [R0], #4
	SUBS R9, #1
	BNE loop

	LDR R0, =ARR ;resetting pointer
	;selection sort starts here
loopI	
	LDR R3, [R0]	; min Element
	MOV R4, R0	; min Index
	MOV R6, R0	; j
loopJ	
	ADD R6, #4
	CMP R6, R7	; if j>n
	BGT exitloopJ
	LDR R5, [R6]	;arr[j]
	CMP R5, R3	;if > skip else swap
	BGT skip
	MOV R3, R5	;updating min element
	MOV R4, R6 	;updating min index
 skip
	B loopJ
exitloopJ
	LDR R8, [R0]	; temp reg 
	STR R3, [R0]	;swapping r3-> min ele
	STR R8, [R4]	;r4 -> min index
	ADD R0, #4	;shortening array
	CMP R0, R7	;if only 1 ele left stop
	BEQ STOP
	B loopI
STOP 
	B STOP
	AREA mydata, DATA, READWRITE
ARR DCD 1
	END
