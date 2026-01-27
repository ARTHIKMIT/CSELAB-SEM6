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
	mov r1, #0	;First element
	mov r2, #1	;Second element
	mov r3, #8	;Counter	-> 8 elemets not incl first 2 (0, 1)
	
	;First 2 elements (Base case)
	str r1, [r0]
	add r0, r0, #4 ;increment pointer
	str r2, [r0]
	add r0, r0, #4 ;increment pointer
loop
	add r4, r1,r2	;next element in series
	str r4, [r0]
	add r0, r0, #4 ;increment pointer
	;Updating last 2 elements 
	mov r1, r2
	mov r2, r4
	
	subs r3, r3, #1
	bne loop	;if r1 > 0, loop
stop
	b stop
	AREA mydata, DATA, READWRITE
src DCD 0
	end