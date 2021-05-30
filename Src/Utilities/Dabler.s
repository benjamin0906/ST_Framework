.syntax unified
.cpu cortex-m0plus
.thumb
.global Dabler
.section .text:Dabler
.type Dabler %function
Dabler:
	/* First argument (R0): Number to transform into string
	   Second argument (R1): Pointer points to a char array*/
	push {r2-r7}
	movs r2, #32
	MOVS R5, #0
	MOVS R6, #0

	/* Check the MSB */
dd_cyc_start:
	MOVS R7, #28
	MOVS R4, #3
adding_check_cycle1:
	MOV R3, R5
	LSLS R3, R3, R7
	LSRS R3, R3, #28
	CMP R3, #5
	BLT after_add
	ADDS R5, R5, R4
after_add:
	LSLS R4, R4, #4
	SUBS R7, R7, #4
	BGE adding_check_cycle1

	/* Carry forward the lower 8 BCD digits */
	LSLS R3, R6, #28
	LSRS R3, R3, #28
	CMP R3, #5
	BLT after_last_add
	ADDS R6, R6, #3
after_last_add:
	/* Mandator shift of the R6 */
	LSLS R6, R6, #1

	/* Placing the highest bit of R5 into R6 before shifting the R5 */
	LSRS R3, R5, #31
	ORRS R6, R6, R3

	/* Mandatory shifting the R5 after "shifting" its highest bit into the R6 */
	LSLS R5, R5, #1
	LSRS R3, R0, #31
	ORRS R5, R5, R3
	LSLS R0, R0, #1

	/* Decrease cycle counter */
	SUBS R2, R2, #1
	BNE dd_cyc_start

	MOVS R0, #0
	LSRS R3, R6, #4
	ADDS R3, R3, #'0'
	STRB R3, [R1, R0]
	CMP R3, #'0'
	BEQ a1
	ADDS R0, R0, #1
	LSLS R6, #28
	LSRS R6, #28
a1:
	ADDS R3, R6, R0
	CMP R3, #0
	BEQ Store_cycle_Start
	ADDS R6, R6, #'0'
	STRB R6, [R1, R0]
	ADDS R0, R0, #1
Store_cycle_Start:
	MOVS R7, #0
Store_cycle:
	MOV R3, R5
	LSLS R3, R3, R7
	LSRS R3, R3, #28
	CMN R3, R0
	BEQ a3
	ADDS R3, R3, #'0'
	STRB R3, [R1, R0]
	ADDS R0, R0, #1
a3:
	ADDS R7, R7, #4
	CMP R7, #32
	BLT Store_cycle

	CMP R0, #0
	BNE AddClosingZero
	ADDS R0, #1
AddClosingZero:
	MOVS R3, #0
	STRB R3, [R1, R0]

	POP {r2-r7}
	bx lr
