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
 .global OS_CORTEXM_IntCat2Exit
 .import OS_CheckForDispatch
 .import OS_Dispatch
 .import OS_CORTEXM_Dispatch
 .import OS_TaskSpOutOfBounds
 .import OS_inKernel
 .import OS_taskCurrent
 .import OS_CORTEXM_IntReturnFromInterrupt
 .import OS_kernel_ptr
 .align 4

OS_kernelDataAddr:
 .word OS_kernel_ptr
 .type OS_CORTEXM_IntCat2Exit, $function
OS_CORTEXM_IntCat2Exit:
 ldr r12, [sp, #(44)]
 cmn r12, #-0xfffffffd
 ite EQ
 moveq r0, #0
 movne r0, #1
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r5, r4
 mov r4, r0
 bl OS_CheckForDispatch
 cmp r0, #1
 beq Cat2ExitWithoutSave
 cmp r0, #2
 beq Cat2ExitWithSave
 strb r4, [r5, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 bl OS_CORTEXM_IntReturnFromInterrupt
Cat2ExitWithSave:
 mov r0, sp
 mrs r1, psp
 bl OS_CORTEXM_Dispatch
Cat2ExitWithoutSave:
 mov r0, #4
 bl OS_Dispatch
 .size OS_CORTEXM_IntCat2Exit, . - OS_CORTEXM_IntCat2Exit

