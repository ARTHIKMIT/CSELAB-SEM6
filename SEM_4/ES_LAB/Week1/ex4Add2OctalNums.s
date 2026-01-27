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
	MOV R0, #8_1
	MOV R1, #8_2
	ADD R2, R1, R0
	NOP
STOP
	B STOP 
		END