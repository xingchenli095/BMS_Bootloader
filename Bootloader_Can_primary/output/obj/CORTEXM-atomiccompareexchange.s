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
 .file "CORTEXM-atomiccompareexchange.s"
 .section ".os_text", "ax"
 .thumb2
 .global OS_AtomicCompareExchange
 .align 4
 .type OS_AtomicCompareExchange, $function
OS_AtomicCompareExchange:
 dsb
 stmfd r13!, {r4}
 ldr r4, [r1]
_retry:
 ldrex r3, [r0]
 cmp r3, r4
 itttt ne
 strne r3, [r1]
 movne r0, #0
 ldmfdne r13!, {r4}
 bxne lr
 strex r3, r2, [r0]
 cmp r3, #0
 bne _retry
 mov r0, #1
 ldmfd r13!, {r4}
 dsb
 bx lr
 .size OS_AtomicCompareExchange, . - OS_AtomicCompareExchange

