
  AREA RESET, DATA, READONLY
  EXPORT __Vectors
__Vectors 
  DCD 0x40001000 ; stack pointer value when stack is empty
  DCD Reset_Handler ; reset vector
  ALIGN
  AREA mycode, CODE, READONLY
  ENTRY
  EXPORT Reset_Handler
Reset_Handler
  LDR R0, =ARR
  
  ;storing data in array (10 to 1 descending order)
  MOV R9, #10
loop  
  STR R9, [R0], #4
  SUBS R9, #1
  BNE loop
  LDR R0, =ARR
  
  LDM R0, {R1-R10}
  STM R13!, {R1-R10}
  MOV R0, R13
  SUB R0, #40
  ADD R7, R0, #36 ;index for last element - n
  ;selection sort starts here
loopI
  LDM R0, {R3}  ;arr[i] → assumed to be smallest ele, R0 → i
  MOV R4, R0  ;smallest index (pointer)
  MOV R6, R0  ; i (initially = &arr[0]) → j
loopJ  
  ADD R6, #4  ;arr+4 = j+1
  CMP R6, R7  ; j should be < n
  
  BGT exitloopJ
  
  LDM R6, {R5} ;arr[j]
  CMP R5, R3  ;if arr[j] < smallest then continue else branch to skip
  
  BGT skip
  
  MOV R3, R5  ;smallest = arr[j]
  MOV R4, R6 ;storing index for smallest found
skip
  B loopJ
exitloopJ  ;Swapping logic
  LDM R0, {R8} ; r8 (temp) = arr[i] , since r0 is i
  STM R0, {R3}  ; arr[i] = smallest;
  STM R4, {R8}  ;smallest = temp
  ADD R0, #4   ;i++
  CMP R0, R7  ;i<n
  
  BEQ exit
  
  B loopI
exit  
  SUB R0, #36  
  LDM R0, {R1-R10}
STOP 
  B STOP
  AREA mydata, DATA, READWRITE
ARR DCD 1
  END
