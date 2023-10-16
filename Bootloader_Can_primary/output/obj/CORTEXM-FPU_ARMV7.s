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
 .global OS_CORTEXM_SaveVFPFullContext
 .global OS_CORTEXM_SetupVFPCoprocessor
 .align 4

OS_FPCCR_addr:
 .word 0xE000EF34
OS_CPACR_addr:
 .word 0xE000ED88
 .type OS_CORTEXM_SetupVFPCoprocessor, $function
OS_CORTEXM_SetupVFPCoprocessor:
 mrs r0, control
 bic r0, r0, #0x00000004
 msr control, r0
 isb
 ldr r1, OS_CPACR_addr
 ldr r0, [r1]
 orr r0, r0, #0xf00000
 str r0, [r1]
 ldr r1, OS_FPCCR_addr
 ldr r0, [r1]
 bic r0, r0, #((1 << 30) | (1 << 31))
 str r0, [r1]
 ldr r1, OS_CPACR_addr
 ldr r0, [r1]
 movw r2, #0xffff
 movt r2, #0xff0f
 and r0, r0, r2
 str r0, [r1]
 bx lr
 .size OS_CORTEXM_SetupVFPCoprocessor, . - OS_CORTEXM_SetupVFPCoprocessor
 .type OS_CORTEXM_SaveVFPFullContext, $function
OS_CORTEXM_SaveVFPFullContext:
 OS_ENABLE_FPU r1, r2, r3
 dsb
 isb
 vmrs r2, fpscr
 stmdb r0!, { r2, r3 }
 vstmdb.64 r0!, {d0-d15}
 str r3, [r1]
 bx lr
 .size OS_CORTEXM_SaveVFPFullContext, . - OS_CORTEXM_SaveVFPFullContext
