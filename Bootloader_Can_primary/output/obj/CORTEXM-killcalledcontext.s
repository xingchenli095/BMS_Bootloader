.macro neg rDest rSrc
 rsb rDest,rSrc,#0
 .endm

.macro OS_GET_KERNEL_PTR litBase destReg sReg
 ldr destReg, litBase
 ldr destReg, [destReg]
 .endm

.macro OS_GENLIT_ACTIVATE_SVC

OS_SHCSR_Addr:
 .word 0xE000ED24
 .endm

.macro OS_ACTIVATE_SVC reg1 reg2
 ldr reg1, OS_SHCSR_Addr
 ldr reg2, [reg1]
 orr reg2, reg2, #0x00000080
 str reg2, [reg1]
 dsb
 isb
 .endm

.macro OS_SETLEVEL level oldLevel
 lsl level, level, #4
 mrs oldLevel, basepri
 lsr oldLevel, oldLevel, #4
 msr basepri, level
 .endm
 .section ".os_text", "ax"
 .thumb2
 .global OS_KillCalledContext
 .align 4
 OS_GENLIT_ACTIVATE_SVC

OS_CORTEXM_EXC_RETURN_Value:
 .word 0xfffffff1
OS_KILLDONE_ADDR:
 .word OS_KillDone
 .type OS_KillCalledContext, $function
OS_KillCalledContext:
 cpsid i
 ldr r0, [r0, #0]
 cmp r0, #0
 beq OS_noStack
 mov sp, r0
 mrs r1, ipsr
 cmp r1, #11
 bne OS_ReturnFromException
 OS_ACTIVATE_SVC r2, r3
OS_ReturnFromException:
 pop {r1, r2, r3, r4-r11, lr}
 ldr r0, OS_KILLDONE_ADDR
 push {r0, r1}
 push {r0-r4, lr}
 lsl r3, r3, #4
 msr basepri, r3
 ldr lr, OS_CORTEXM_EXC_RETURN_Value
 bx lr
OS_KillDone:
 cpsie i
 bx lr
OS_noStack:
 mov r0, #21
 bx lr
 .size OS_KillCalledContext, . - OS_KillCalledContext

