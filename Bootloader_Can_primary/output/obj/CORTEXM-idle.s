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
 .global OS_CORTEXM_Idle
 .import OS_idleStack
 .import OS_kernel_ptr
 .align 4

OS_CORTEXM_EPSR_T_Value:
 .word 0x01000000
OS_CORTEXM_EXC_RETURN_Value:
 .word 0xfffffffd
OS_idleStackAddr:
 .word OS_idleStack
OS_kernelDataAddr:
 .word OS_kernel_ptr
 OS_GENLIT_ACTIVATE_SVC
IdleLoopHaltAddr:
 .word IdleLoopHalt
IdleLoopNoHaltAddr:
 .word IdleLoopNoHalt
 .type OS_CORTEXM_Idle, $function
OS_CORTEXM_Idle:
 cpsid i
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r5, r7
 mov r7, #0x0
 strb r7, [r5, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 ldr sp, OS_idleStackAddr
 add sp, sp, #(64 * 4)
 ldr r7, OS_CORTEXM_EPSR_T_Value
 ldrb r6, [r5, #((((((0 + 4) + 4) + 4) + 4) + 0) + 1)]
 cmp r6, #1
 beq OS_LoadIdleHaltAddr
 ldr r6, IdleLoopNoHaltAddr
 b OS_PushIdleContext
OS_LoadIdleHaltAddr:
 ldr r6, IdleLoopHaltAddr
OS_PushIdleContext:
 push {r0-r7}
 mov r0, sp
 msr psp, r0
 ldr sp, [r5, #((0 + 4) + 4)]
 mov r0, #16
 OS_SETLEVEL r0, r1
 cpsid f
 cpsie i
 mrs r0, ipsr
 cmp r0, #11
 bne OS_SkipActivateSVC
 OS_ACTIVATE_SVC r0, r1
OS_SkipActivateSVC:
 ldr pc, OS_CORTEXM_EXC_RETURN_Value
IdleLoopHalt:
 wfi
 b IdleLoopHalt
IdleLoopNoHalt:
 b IdleLoopNoHalt
 .size OS_CORTEXM_Idle, . - OS_CORTEXM_Idle

