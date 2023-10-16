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
 .global OS_CORTEXM_IntCat1Exit
 .import OS_CORTEXM_IntReturnFromInterrupt
 .import OS_kernel_ptr
 .align 4

OS_kernelDataAddr:
 .word OS_kernel_ptr
 .type OS_CORTEXM_IntCat1Exit, $function
OS_CORTEXM_IntCat1Exit:
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r1, r4
 strb r0, [r1, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 bl OS_CORTEXM_IntReturnFromInterrupt
 .size OS_CORTEXM_IntCat1Exit, . - OS_CORTEXM_IntCat1Exit

