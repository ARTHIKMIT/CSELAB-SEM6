	AREA	RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000	;stack ptr value when stack is empty	
	DCD Reset_Handler	;reset vector. The program linker requires Reset_Handler
	ALIGN
	AREA	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #10
	MOV R1, #20
	MOV R2, #30
	MOV R3, #40
	ADD R10, R1, R0
	ADD R10, R10, R2
	ADD R10, R10, R3
	NOP
STOP
	B STOP 
		END