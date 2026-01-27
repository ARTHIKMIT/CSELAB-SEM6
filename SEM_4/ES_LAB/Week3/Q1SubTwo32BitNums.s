	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	ldr r0, = n1
	ldr r1, = n2
	ldr r2, = dest
	ldr r3,[r0]
	ldr r4,[r1]
	subs r6, r4, r3
	STR R6, [R2]
stop
	b stop
n1 DCD 3
n2 DCD 7
	AREA mydata, DATA, READWRITE
dest dcd 1
	end