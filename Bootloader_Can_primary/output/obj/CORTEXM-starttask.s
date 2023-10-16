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

.macro OS_ENABLE_FPU addrR tmpR storeR
 movw addrR, #(0xED88)
 movt addrR, #(0xE000)
 ldr storeR, [addrR]
 orr tmpR, storeR, #0x00f00000
 str tmpR, [addrR]
 .endm

.macro OS_DISABLE_FPU addrR tmpR storeR
 movw addrR, #(0xED88)
 movt addrR, #(0xE000)
 ldr storeR, [addrR]
 movw tmpR, #(0xffff)
 movt tmpR, #(0xff0f)
 and tmpR, storeR, tmpR
 str tmpR, [addrR]
 .endm

.macro OS_GET_MPU_CTRL_ADDR destR
 movw destR, #(0xED94)
 movt destR, #(0xE000)
 .endm

.macro OS_ENABLE_MPU reg1 reg2
 .endm

.macro OS_DISABLE_MPU_GET_STATE reg1 reg2 result
 .endm

.macro OS_MPU_SET_CTRL reg1 ctrl
 .endm

.macro DispatchInterrupt isrid entry exit level corevar
 cpsid i
 OS_DISABLE_MPU_GET_STATE r0, r1, r2
 OS_DISABLE_FPU r0, r1, r3
 push {r4-r11, lr}
 push {r2, r3}
 OS_GET_KERNEL_PTR corevar, r1, r0
 ldrb r4, [r1, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r0, #1
 strb r0, [r1, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r2, #level
 OS_SETLEVEL r2, r0
 push {r0}
 cpsie i
 mov r0, #isrid
 bl entry
 mov r0,r4
 bl exit
 .endm
 .section ".os_text", "ax"
 .thumb2
 .global OS_CORTEXM_StartTask
 .import OS_kernel_ptr
 .align 4
 OS_GENLIT_ACTIVATE_SVC

OS_kernelDataAddr:
 .word OS_kernel_ptr
OS_CORTEXM_EPSR_T_Value:
 .word 0x01000000
OS_CORTEXM_EXC_RETURN_Value:
 .word 0xfffffffd
 .type OS_CORTEXM_StartTask, $function
OS_CORTEXM_StartTask:
 cpsid f
 mov sp, r1
 ldr r7, OS_CORTEXM_EPSR_T_Value
 mov r6, r0
 mov r5, r3
 push {r0-r7}
 mov r0, sp
 msr psp, r0
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r0, r1
 ldr sp, [r0, #((0 + 4) + 4)]
 mov r0, #16
 OS_SETLEVEL r0, r1
 tst r2, #0x80
 beq OS_SkipEnableFpu
 OS_ENABLE_FPU r0, r1, r1
OS_SkipEnableFpu:
 lsr r2, r2, #8
 tst r2, #0x01
 bne OS_SkipEnableMpu
 OS_ENABLE_MPU r0, r1
OS_SkipEnableMpu:
 mrs r0, ipsr
 cmp r0, #11
 bne OS_SkipActivateSVC
 OS_ACTIVATE_SVC r0, r1
OS_SkipActivateSVC:
 ldr pc, OS_CORTEXM_EXC_RETURN_Value
 .size OS_CORTEXM_StartTask, . - OS_CORTEXM_StartTask

