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
	ldr r0, = src	;pointer to array
	mov r1, #10	;N -> counter
	mov r2, #0	;sum
	ldr r4, = dest
loop
	ldr r3,[r0]
	add r2, r2, r3
	add r0, r0, #4	;Incrementing pointer to next ele, i.e, by 4 bytes (=32bits)
	subs r1, r1, #1
	bne loop	;if r1 > 0, loop
	str r2, [r4]
stop
	b stop
src DCD 1,2,3,4,5,6,7,8,9,0
	AREA mydata, DATA, READWRITE
dest dcd 0
	end