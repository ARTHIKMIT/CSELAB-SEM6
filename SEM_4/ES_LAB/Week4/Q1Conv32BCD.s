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
	LDR R0, =0x01020304  ; Example Unpacked BCD

	; Extract the first digit
	; R1 -> holds digits
	AND R1, R0, #0x0F 
	MOV R2, R1
	
	AND R1, R0, #0x0F00
	MOV R1, R1, LSR #4
	ORR R2, R2, R1
	
	AND R1, R0, #0x0F0000
	MOV R1, R1, LSR #8
	ORR R2, R2, R1
	
	AND R1, R0, #0x0F000000
	MOV R1, R1, LSR #12
	ORR R2, R2, R1
STOP
	B STOP
	END
