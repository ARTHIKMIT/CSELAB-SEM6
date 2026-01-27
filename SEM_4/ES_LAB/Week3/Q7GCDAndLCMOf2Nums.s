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
	ldr r0, =n1
	ldr r1, =n2
	ldr r2, [r0]
	ldr r3, [r1]
	
gcd_loop
	cmp r3, #0
	moveq r4, r2          ; If n2 == 0, then GCD = n1 (r2)
	beq compute_lcm       ; If GCD found, proceed to LCM calculation
	mov r5, r2            ; Store n1 (r2) in r5 for next iteration
	mov r6, r3            ; Store n2 (r3) in r6 for next iteration
	
	; Calculate remainder: r5 % r6 -> r7 i.e, n1%n2
	mov r7, r5
	udiv r7, r7, r6       ; r7 = r5 / r6 (quotient), udiv -> unsigned division
	mul r7, r7, r6       ; r7 = quotient * r6
	sub r7, r5, r7       ; r7 = remainder (r5 % r6)
	
	; Prepare for next iteration
	mov r2, r6            ; n1 becomes n2
	mov r3, r7            ; n2 becomes remainder (r5 % r6)
	b gcd_loop            ; Repeat the process

compute_lcm
	; LCM(a, b) = (a * b) / GCD(a, b)
	ldr r2, [r0]	;Resetting n1, n2
	ldr r3, [r1]
	mul r5, r2, r3        ; r5 = n1 * n2 (a * b)
	udiv r6, r5, r4       ; r6 = (n1 * n2) / GCD (LCM)
	
	; Store the GCD and LCM in memory
	ldr r9, =dest_gcd
	str r4, [r9]          ; Store GCD in memory
	ldr r9, =dest_lcm
	str r6, [r9]          ; Store LCM in memory
	
stop
	b stop

n1 DCD 3                 ; n1
n2 DCD 7                 ; n2

	AREA mydata, DATA, READWRITE
dest_gcd DCD 0
dest_lcm DCD 0
	end
