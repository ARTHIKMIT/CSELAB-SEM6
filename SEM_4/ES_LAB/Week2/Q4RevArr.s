	AREA	RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =ARR 	;Beginning pointer to First/0th Element
	ADD R1, R0, #36	;Ending pointer to Last Element
	MOV R2, #10		;Counter
	MOV R5, #1		;Initalizing and Storing the array
loop1	STR R5, [R0], #4
		ADD R5, #1
		SUBS R2, #1
		BNE loop1
		MOV R2, #5	;Counter reset to N/2 as 0 and n-1 are swapped together
		LDR R0, =ARR
loop2	LDR R3, [R0]	;Loading elements from beginning
		LDR R4, [R1] 	;Loading elements from ending
		STR R4, [R0], #4	;Storing nth element and Incrementing the beginning pointer
		STR R3, [R1], #-4	;Storing 0th element and Decrementing the ending pointer
		SUBS R2, #1		;Decrementing Count
		BNE loop2
STOP
	B STOP
	AREA mydata, DATA, READWRITE
ARR DCD 0,0,0,0,0,0,0,0,0,0 ;DST location in data memory
	END