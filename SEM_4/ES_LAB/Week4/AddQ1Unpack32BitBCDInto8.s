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

	AND R1, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R2, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R3, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R4, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R5, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R6, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R7, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
	AND R8, R0, #0xF ;Extract digit
	MOV R0, R0, LSR #4
STOP
    B STOP
    END
