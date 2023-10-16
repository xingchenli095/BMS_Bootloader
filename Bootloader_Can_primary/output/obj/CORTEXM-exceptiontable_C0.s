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
 .global CORTEXMExceptionTable_C0
 .import boardResetStart
 .import OS_kernStack0
 .import OS_SystemCall
 .import OS_ExceptionNMIHandler
 .import OS_ExceptionHardFaultHandler
 .import OS_ExceptionMemManageHandler
 .import OS_ExceptionBusFaultHandler
 .import OS_ExceptionUsageFaultHandler
 .import OS_ExceptionReservedHandler_1
 .import OS_ExceptionReservedHandler_2
 .import OS_ExceptionReservedHandler_3
 .import OS_ExceptionReservedHandler_4
 .import OS_ExceptionDebugHandler
 .import OS_ExceptionReservedHandler_5
 .import OS_ExceptionPendSVHandler
 .import OS_ExceptionSysTickHandler
 .section ExceptionTable_C0, "ax"

CORTEXMExceptionTable_C0:
 .word (OS_kernStack0 + 3072)
 .word boardResetStart
 .word OS_ExceptionNMIHandler
 .word OS_ExceptionHardFaultHandler
 .word OS_ExceptionMemManageHandler
 .word OS_ExceptionBusFaultHandler
 .word OS_ExceptionUsageFaultHandler
 .word OS_ExceptionReservedHandler_1
 .word OS_ExceptionReservedHandler_2
 .word OS_ExceptionReservedHandler_3
 .word OS_ExceptionReservedHandler_4
 .word OS_SystemCall
 .word OS_ExceptionDebugHandler
 .word OS_ExceptionReservedHandler_5
 .word OS_ExceptionPendSVHandler
 .word OS_ExceptionSysTickHandler

