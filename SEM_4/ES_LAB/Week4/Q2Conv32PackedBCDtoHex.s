	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000      ; stack pointer value when stack is empty
	DCD Reset_Handler   ; reset vector
	ALIGN
	AREA	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	LDR R0, =0x99999999  ; Example packed BCD
	MOV R2, #1 ;place
	MOV R3, #0 ;Sum
	MOV R4, #10
Loop
	AND R1, R0, #0xF ;Extract digit
	MLA R3, R2, R1, R3
	MUL R2, R2, R4
	MOVS R0, R0, LSR #4
	BNE Loop
STOP
	B STOP
	END
