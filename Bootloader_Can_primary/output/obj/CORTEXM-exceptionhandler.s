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
 .global OS_ExceptionNMIHandler
 .global OS_ExceptionHardFaultHandler
 .global OS_ExceptionMemManageHandler
 .global OS_ExceptionBusFaultHandler
 .global OS_ExceptionUsageFaultHandler
 .global OS_ExceptionReservedHandler_1
 .global OS_ExceptionReservedHandler_2
 .global OS_ExceptionReservedHandler_3
 .global OS_ExceptionReservedHandler_4
 .global OS_ExceptionDebugHandler
 .global OS_ExceptionReservedHandler_5
 .global OS_ExceptionPendSVHandler
 .global OS_ExceptionSysTickHandler
 .global OS_ExceptionHandler
 .global OS_CORTEXM_K_Exception
 .import OS_Exception
 .import OS_CheckForDispatch
 .import OS_CORTEXM_Dispatch
 .import OS_Dispatch
 .import OS_kernel_ptr
 .import boardNmiCallBack
 .align 4
 OS_GENLIT_ACTIVATE_SVC

OS_CORTEXM_EXC_RETURN_Value:
 .word 0xfffffff1
OS_kernelDataAddr:
 .word OS_kernel_ptr
HFSR_Addr:
 .word 0xE000ED2C
CFSR_Addr:
 .word 0xE000ED28
MMFAR_Addr:
 .word 0xE000ED34
BFAR_Addr:
 .word 0xE000ED38
OS_ExceptionHandlerSvcAddr:
 .word OS_ExceptionHandlerSvc
OS_CFSR_DerivedFault:
 .word (((1 << 4) << 0) | ((1 << 4) << 8))
 .type OS_CORTEXM_PanicStop, $function
OS_CORTEXM_PanicStop:
 b OS_CORTEXM_PanicStop
 .size OS_CORTEXM_PanicStop, . - OS_CORTEXM_PanicStop
 .type OS_ExceptionNMIHandler, $function
OS_ExceptionNMIHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 push {r1,lr}
 bl boardNmiCallBack
 pop {r1,lr}
 mov r0, #0x08
 ldr r12, OS_SHCSR_Addr
 ldr r2, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionNMIHandler, . - OS_ExceptionNMIHandler
 .type OS_ExceptionHardFaultHandler, $function
OS_ExceptionHardFaultHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 mov r0, #0x0c
 ldr r12, HFSR_Addr
 ldr r2, [r12]
 str r2, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionHardFaultHandler, . - OS_ExceptionHardFaultHandler
 .type OS_ExceptionMemManageHandler, $function
OS_ExceptionMemManageHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 ldr r12, CFSR_Addr
 ldr r2, [r12]
 ldr r3, MMFAR_Addr
 ldr r3, [r3]
 and r0, r2, #0xFF
 str r0, [r12]
 mov r0, #0x10
 ldr r12, OS_CFSR_DerivedFault
 tst r2, r12
 bne OS_NoContext
 b OS_ExceptionHandler
 .size OS_ExceptionMemManageHandler, . - OS_ExceptionMemManageHandler
 .type OS_ExceptionBusFaultHandler, $function
OS_ExceptionBusFaultHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 ldr r12, CFSR_Addr
 ldr r2, [r12]
 ldr r3, BFAR_Addr
 ldr r3, [r3]
 and r0, r2, #0xFF00
 str r0, [r12]
 mov r0, #0x14
 ldr r12, OS_CFSR_DerivedFault
 tst r2, r12
 bne OS_NoContext
 b OS_ExceptionHandler
 .size OS_ExceptionBusFaultHandler, . - OS_ExceptionBusFaultHandler
 .type OS_ExceptionUsageFaultHandler, $function
OS_ExceptionUsageFaultHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 mov r0, #0x18
 ldr r12, CFSR_Addr
 ldr r2, [r12]
 lsr r3, r2, #16
 lsl r3, r3, #16
 str r3, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionUsageFaultHandler, . - OS_ExceptionUsageFaultHandler
 .type OS_ExceptionReservedHandler_1, $function
OS_ExceptionReservedHandler_1:
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionReservedHandler_1, . - OS_ExceptionReservedHandler_1
 .type OS_ExceptionReservedHandler_2, $function
OS_ExceptionReservedHandler_2:
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionReservedHandler_2, . - OS_ExceptionReservedHandler_2
 .type OS_ExceptionReservedHandler_3, $function
OS_ExceptionReservedHandler_3:
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionReservedHandler_3, . - OS_ExceptionReservedHandler_3
 .type OS_ExceptionReservedHandler_4, $function
OS_ExceptionReservedHandler_4:
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionReservedHandler_4, . - OS_ExceptionReservedHandler_4
 .type OS_ExceptionDebugHandler, $function
OS_ExceptionDebugHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 mov r0, #0x30
 ldr r12, OS_SHCSR_Addr
 ldr r2, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionDebugHandler, . - OS_ExceptionDebugHandler
 .type OS_ExceptionReservedHandler_5, $function
OS_ExceptionReservedHandler_5:
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionReservedHandler_5, . - OS_ExceptionReservedHandler_5
 .type OS_ExceptionPendSVHandler, $function
OS_ExceptionPendSVHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 mov r0, #0x38
 ldr r12, OS_SHCSR_Addr
 ldr r2, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionPendSVHandler, . - OS_ExceptionPendSVHandler
 .type OS_ExceptionSysTickHandler, $function
OS_ExceptionSysTickHandler:
 cpsid f
 OS_DISABLE_MPU_GET_STATE r0, r2, r1
 mov r0, #0x3c
 ldr r12, OS_SHCSR_Addr
 ldr r2, [r12]
 mov r3, #0
 b OS_ExceptionHandler
 .size OS_ExceptionSysTickHandler, . - OS_ExceptionSysTickHandler
 .type OS_NoContext, $function
OS_NoContext:
 push { r4-r11, lr }
 OS_DISABLE_FPU r5, r6, r7
 push { r1, r7 }
 mov r10, #1
 OS_SETLEVEL r10, r11
 push { r11 }
 cpsie f
 mrs r4, CONTROL
 push {r0, r2, r3, r4, r5, lr}
 bic r4, r4, #0x00000001
 msr CONTROL, r4
 tst lr, #0x00000008
 it NE
 tstne lr, #0x00000004
 itee NE
 mrsne r0, psp
 mrseq r0, msp
 addeq r0, r0, #(18 * 4)
 mov r1, sp
 ldr r2, OS_ExceptionHandlerSvcAddr
 mov r3, #0x01000000
 ldr r6, OS_CORTEXM_EXC_RETURN_Value
 cmp lr, r6
 it EQ
 orreq r3, r3, #4
 push {r2, r3}
 push {r0, r1, r2, r3, r12, lr}
 bic lr, lr, #(1 << 2)
 bx lr
 b OS_CORTEXM_PanicStop
 .size OS_NoContext, . - OS_NoContext
 .type OS_ExceptionHandler, $function
OS_ExceptionHandler:
 push {r4-r11, lr}
 OS_DISABLE_FPU r5, r6, r7
 push { r1, r7 }
 mov r10, #1
 OS_SETLEVEL r10, r11
 push { r11 }
 cpsie f
 cpsie i
 mrs r4, CONTROL
 push {r0, r2, r3, r4, r5, lr}
 bic r4, r4, #0x00000001
 msr CONTROL, r4
 tst lr, #0x00000008
 it NE
 tstne lr, #0x00000004
 itee NE
 mrsne r0, psp
 mrseq r0, msp
 addeq r0, r0, #(18 * 4)
 mov r1, sp
 ldr r2, OS_ExceptionHandlerSvcAddr
 ldr r3, [r0, #(7 * 4)]
 push {r2, r3}
 push {r0, r1, r2, r3, r12, lr}
 bic lr, lr, #(1 << 2)
 bx lr
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionHandler, . - OS_ExceptionHandler
 .type OS_ExceptionHandlerSvc, $function
OS_ExceptionHandlerSvc:
 mov r12, #(61)
 svc #0
 b OS_CORTEXM_PanicStop
 .size OS_ExceptionHandlerSvc, . - OS_ExceptionHandlerSvc
 .type OS_CORTEXM_K_Exception, $function
OS_CORTEXM_K_Exception:
 mov r4, r0
 mov r5, r1
 ldr r0, [r5, #0]
 ldr r2, [r5, #4]
 ldr r3, [r5, #8]
 ldr r7, [r5, #12]
 ldr r6, [r5, #20]
 msr CONTROL, r7
 ldr r1, [r4, #(0x18)]
 bl OS_Exception
 tst r6, #0x00000008
 it NE
 tstne r6, #0x00000004
 ite NE
 movne r7, #0
 moveq r7, #1
 mov r0, r7
 bl OS_CheckForDispatch
 cmp r0, #0
 beq OS_Exc_JustReturn
 cmp r0, #1
 beq OS_Exc_WithoutSave
 add r0, sp, #(6 * 4)
 mov r1, r4
 bl OS_CORTEXM_Dispatch
 bl OS_Dispatch
 b OS_CORTEXM_PanicStop
OS_Exc_WithoutSave:
 mov r0, #3
 bl OS_Dispatch
 b OS_CORTEXM_PanicStop
OS_Exc_JustReturn:
 OS_ACTIVATE_SVC r1, r2
 OS_GET_KERNEL_PTR OS_kernelDataAddr, r8, r0
 str r7, [r8, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov sp, r5
 pop {r0, r2, r3, r4, r5, lr}
 pop {r0, r1, r2}
 tst r2, #0x00f00000
 beq OS_ExceptionHandler_SkipEnableFpu
 OS_ENABLE_FPU r5, r2, r2
OS_ExceptionHandler_SkipEnableFpu:
 OS_SETLEVEL r0, r2
 cpsid f
 OS_MPU_SET_CTRL r2, r1
 pop {r4-r11}
 sub sp, sp, #4
 bx lr
 .size OS_CORTEXM_K_Exception, . - OS_CORTEXM_K_Exception

