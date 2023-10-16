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
 .global boardResetStart
 .global boardInvalidInterrupt
 .global boardInvalidException
 .global boardEnableICaches
 .global boardDisableInterruptsAsm
 .global boardEnableInterruptsAsm
 .import boardStart
 .import CORTEXMExceptionTable_C0
 .import OS_kernStack0
 .import OS_CORTEXM_SetupVFPCoprocessor
 .align 4
 .type boardInvalidInterrupt, $function
boardInvalidInterrupt:
InvalidInterruptLoop:
 b InvalidInterruptLoop
 .size boardInvalidInterrupt, . - boardInvalidInterrupt
 .type boardInvalidException, $function
boardInvalidException:
InvalidExceptionLoop:
 b InvalidExceptionLoop
 .size boardInvalidException, . - boardInvalidException

SHCSR_Value:
 .word 0x00070000
SHCSR_Addr:
 .word 0xE000ED24
VTOR_Addr:
 .word 0xE000ED08
BOARD_ExceptionTableAddr:
 .word (CORTEXMExceptionTable_C0)
BoardSPAddr:
 .word (OS_kernStack0 + 3072)
BoardDCISWAddr:
 .word 0xE000EF60
BoardICIALLUAddr:
 .word 0xE000EF50
BoardCCRAddr:
 .word 0xE000ED14
 .type boardEnableICaches, $function
boardEnableICaches:
 mov r0, #0
 ldr r12, BoardICIALLUAddr
 str r0, [r12]
 dsb
 isb
 ldr r1, BoardCCRAddr
 ldr r0, [r1]
 orr r0, r0, #(1 << 17)
 str r0, [r1]
 dsb
 isb
 bx lr
 .size boardEnableICaches, . - boardEnableICaches
 boardCatchM7:
  b boardCatchM7
  .type boardResetStart, $function
  boardResetStart:
  movs r4 ,#0
  msr primask ,r4
  movs r4 ,#0
  msr control ,r4
  movs r4 ,#0x1000000
  msr xpsr ,r4
  ldr r0, SHCSR_Value
  ldr r5, SHCSR_Addr
  ldr r1, [r5]
  orr r1, r0, r1
  str r1, [r5]
  ldr r1, =0x20400000
        ldr r2, =0x2040FFFF
        subs r2, r1
        subs r2, #1
        movs r0, 0
        movs r3, 0
  SRAM_LOOP:
        stm r1!, {r0,r3}
        subs r2, 8
        bge SRAM_LOOP
 bl OS_CORTEXM_SetupVFPCoprocessor
 ldr sp, BoardSPAddr
 ldr r0, VTOR_Addr
 ldr r1, BOARD_ExceptionTableAddr
 str r1, [r0]
 bl boardStart
 b boardCatchM7
 .size boardResetStart, . - boardResetStart
 .type boardDisableInterruptsAsm, $function
 boardDisableInterruptsAsm:
 cpsid i
 bx lr
 .size boardDisableInterruptsAsm, . - boardDisableInterruptsAsm
 .type boardEnableInterruptsAsm, $function
 boardEnableInterruptsAsm:
 cpsie i
 bx lr
 .size boardEnableInterruptsAsm, . - boardEnableInterruptsAsm

.section ".boot_header","ax"
  .long (0x5AA55AA5)
  .long ((1) << (0)) | ((0) << (1))
  .long 0
  .long (0x500000)
  .long 0
  .long (0)
  .long 0
  .long 0
  .long (0)
  .long (0)
  .long 0
