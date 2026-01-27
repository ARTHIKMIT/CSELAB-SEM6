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
	LDR R0, = SRC	;Loads address of SRC into R0
	LDR R1, = DST	;Loads address of DST onto R1
	LDR R3,[R0]	;Loads data pointed by R0 into R3
	STR R3,[R1]	;Stores data from R3 into Address poineted by R1
STOP
	B STOP	;Infinte Loop
SRC DCD 8	;SRC location in code memory
	AREA mydata, DATA, READWRITE
DST DCD 0		;DST location in data memory
	END