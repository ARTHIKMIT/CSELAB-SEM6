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
	mov r0, #50
	mov r1, #8
	mov r2, #0	;Ans (Q)
	mov r3, r0	;temp var -> 50 for 50/8
loop
	subs r3, r3, r1
	bmi stop
	add r2, r2, #1
	b loop
stop
	b stop
	end