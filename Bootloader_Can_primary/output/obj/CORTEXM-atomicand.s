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
 .file "CORTEXM-atomicand.s"
 .section ".os_text", "ax"
 .thumb2
 .global OS_AtomicFetchAnd
 .align 4
 .type OS_AtomicFetchAnd, $function
OS_AtomicFetchAnd:
 dsb
 stmfd r13!, {r4}
_retry:
 ldrex r2, [r0]
 and r3, r2, r1
 strex r4, r3, [r0]
 cmp r4, #0
 bne _retry
 mov r0, r2
 ldmfd r13!, {r4}
 dsb
 bx lr
 .size OS_AtomicFetchAnd, . - OS_AtomicFetchAnd

