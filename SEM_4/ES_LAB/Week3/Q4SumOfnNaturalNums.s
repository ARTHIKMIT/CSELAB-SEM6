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
	mov r0, #8	;N
	mov r1, #0	;Sum
	mov r2, #1	;Natural number
	mov r3, #1	;to multiply by 1
loop
	MLA r1, r2, r3, r1	;r1 = r2*1 + r1
	subs r0, r0, #1
	beq stop	;if N==0 stop
	add r2, r2, #1
	b loop
stop
	b stop
	end