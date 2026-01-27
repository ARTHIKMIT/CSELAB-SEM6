	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	ldr r0, = n1
	ldr r1, = n2
	ldr r2,[r0]
	ldr r3,[r1]
	umull r4, r5, r2, r3	;r4 -> lower 32 bits
stop
	b stop
n1 DCD 3
n2 DCD 7
	end