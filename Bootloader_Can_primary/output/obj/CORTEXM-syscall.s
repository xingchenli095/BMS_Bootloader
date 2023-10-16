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
 .align 4
 .global OS_SystemCall
 .import OS_CheckForDispatch
 .import OS_syscallTable
 .import OS_CORTEXM_Dispatch
 .import OS_Dispatch
 .import OS_TaskSpOutOfBounds
 .import OS_IntDisableConditionalX
 .import OS_kernel_ptr

OS_syscallTableAddr:
 .word OS_syscallTable
OS_kernelDataAddr:
 .word OS_kernel_ptr
 OS_GENLIT_ACTIVATE_SVC
 .type OS_SystemCall, $function
OS_SystemCall:
 cpsid f
 push {r4-r11, lr}
 OS_DISABLE_MPU_GET_STATE r4, r5, r6
 OS_DISABLE_FPU r4, r5, r7
 push {r5, r6, r7}
 ldr r10, OS_SHCSR_Addr
 ldr r8, [r10]
 bic r8, r8, #0x00000080
 str r8, [r10]
 dsb
 isb
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r5, r6
 ldrb r6, [r5, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r7, #0x1
 strb r7, [r5, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r9, lr
 cpsie f
 cmp r12, #64
 ldr r7, OS_syscallTableAddr
 bge GetScEntry
 add r7, r7, r12, LSL #2
GetScEntry:
 ldr r7,[r7]
 blx r7
 cpsid f
 tst r9, #0x00000008
 it NE
 tstne r9, #0x00000004
 ittee NE
 mrsne r8, psp
 strne r0, [r8,#0]
 mrseq r8, msp
 streq r0, [r8,#48]
 ldrb r7, [r5, #(((((((0 + 4) + 4) + 4) + 4) + 0) + 1) + 1)]
 cmp r7, #0
 beq JustReturn
 mov r0, r6
 bl OS_CheckForDispatch
 mov r7, r0
 cmp r7, #0
 beq JustReturn
 bl OS_IntDisableConditionalX
 str r0, [sp, #0]
 cpsie f
 cmp r7, #1
 beq WithoutSave
 mov r0, sp
 mrs r1, psp
 bl OS_CORTEXM_Dispatch
WithoutSave:
 mov r0, #3
 bl OS_Dispatch
JustReturn:
 cpsid f
 strb r6, [r5, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 OS_ACTIVATE_SVC r0, r1
 pop {r0, r1, r2}
 tst r2, #0x00f00000
 beq OS_Syscall_SkipEnableFpu
 OS_ENABLE_FPU r0, r2, r2
OS_Syscall_SkipEnableFpu:
 OS_MPU_SET_CTRL r0, r1
 pop {r4-r11,lr}
 bx lr
 .size OS_SystemCall, . - OS_SystemCall

