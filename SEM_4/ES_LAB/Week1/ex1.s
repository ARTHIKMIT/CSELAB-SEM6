	AREA	RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000	;stack ptr value when stack is empty
					;Processor uses a full descending stack => ptr holds address of last stacked item
					;when a new item is pushed, ptr is decremented and item is written to new mem loc		
	DCD Reset_Handler	;reset vector. The program linker requires Reset_Handler
	ALIGN
	AREA	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #20
	MOV R1, #5
	ADD R2, R1, R0
	NOP
STOP
	B STOP 
		END