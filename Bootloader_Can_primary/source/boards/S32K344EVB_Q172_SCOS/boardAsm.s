/* boardAsm.s - board specific assembly startup code.
 *
 * This file contains the early startup code implemented in assembly.
 * It exports the following functions and symbols:
 *
 *  boardResetStart:       Reset vector.
 *  boardInvalidInterrupt: Handler for invalid / spurious interrupts if
 *                         ErrorHandling is set to MINIMAL.
 *  boardInvalidException: Handler for exceptions if ExceptionHandling is
 *                         disabled.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: boardAsm.s 38213 2022-10-18 07:31:55Z syns274107 $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>
#include <Os_configuration.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global boardResetStart
	OS_global boardInvalidInterrupt
	OS_global boardInvalidException
	OS_global boardEnableICaches
	OS_global boardDisableInterruptsAsm
	OS_global boardEnableInterruptsAsm
	OS_extern boardStart
	OS_extern CORTEXMExceptionTable_C0
	OS_extern OS_kernStack0
	OS_extern OS_CORTEXM_SetupVFPCoprocessor

#ifdef OS_TESTSUITE_IS_RUNNING_
	OS_extern BTestOK
	OS_extern BPanic
#endif

	OS_align(4, 2)

/*
 * boardInvalidInterrupt()
 *
 * The boardInvalidInterrupt() routine is used for uninitialized
 * vectors of the vector table if error handling is set to minimal.
*/
	OS_ASM_FUNC(boardInvalidInterrupt)
OS_ASM_LABEL(boardInvalidInterrupt)
#ifdef OS_TESTSUITE_IS_RUNNING_
#ifdef TESTCASE_InvalidInterrupt
	bl		BTestOK
#else  /* TESTCASE_InvalidInterrupt */
	bl		BPanic
#endif /* TESTCASE_InvalidInterrupt */
#endif /* OS_TESTSUITE_IS_RUNNING_ */
OS_ASM_LABEL(InvalidInterruptLoop)
	b		InvalidInterruptLoop
	OS_ASM_END_FUNC(boardInvalidInterrupt)


/*
 * boardInvalidException()
 *
 * The boardInvalidException() routine is used for uninitialized
 * vectors of the exception table if Exception handling is off.
 *
*/
	OS_ASM_FUNC(boardInvalidException)
OS_ASM_LABEL(boardInvalidException)
#ifdef OS_TESTSUITE_IS_RUNNING_
#ifdef TESTCASE_InvalidException
	bl		BTestOK
#else  /* TESTCASE_InvalidException */
	bl		BPanic
#endif /* TESTCASE_InvalidException */
#endif /* OS_TESTSUITE_IS_RUNNING_ */
OS_ASM_LABEL(InvalidExceptionLoop)
	b		InvalidExceptionLoop
	OS_ASM_END_FUNC(boardInvalidException)

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

	/* The value for the system handler control and status register */
OS_ASM_LABEL(SHCSR_Value)
	OS_word 0x00070000

	/* The address of the system handler control and status register */
OS_ASM_LABEL(SHCSR_Addr)
	OS_word OS_CORTEXM_SHCSR

OS_ASM_LABEL(VTOR_Addr)
	OS_word 0xE000ED08

OS_ASM_LABEL(BOARD_ExceptionTableAddr)
	OS_word (CORTEXMExceptionTable_C0)

OS_ASM_LABEL(BoardSPAddr)
	OS_word (OS_kernStack0 + OS_ISTACKLEN_0)

OS_ASM_LABEL(BoardDCISWAddr)
	OS_word 0xE000EF60

OS_ASM_LABEL(BoardICIALLUAddr)
	OS_word 0xE000EF50

OS_ASM_LABEL(BoardCCRAddr)
	OS_word 0xE000ED14

/* boardEnableICaches
 *
 * Invalidates and enables caches.
*/
	OS_ASM_FUNC(boardEnableICaches)
OS_ASM_LABEL(boardEnableICaches)
	/* Invalidate instruction cache.
	*/
	mov			r0, #0
	ldr			r12, BoardICIALLUAddr
	str			r0, [r12]
	dsb
	isb

	ldr			r1, BoardCCRAddr
	ldr			r0, [r1]
	orr			r0, r0, #(1 << 17)		/* Set CCR.IC field */
	str			r0, [r1]
	dsb
	isb

	bx lr
	OS_ASM_END_FUNC(boardEnableICaches)

	OS_ASM_LABEL(boardCatchM7)
		b		boardCatchM7				/* Loop to catch unused cores (Cortex-M7) */
	/*
	 * boardResetStart
	 *
	 * Startup routine, for hardware initialization in assembly (which can not be done in C).
	 *
	*/
		OS_ASM_FUNC(boardResetStart)
		OS_ASM_LABEL(boardResetStart)
		/* After reset this routine is called
		 * - in privileged thread mode and
		 * - with sp == msp (sp_main) already set to reset value
		 * - with interrupt priority set to all enabled BASEPRI=0
		 * - with interrupt flag set to all enabled PRIMASK=0
		*/	
		movs     r4 ,#0
		msr primask ,r4
		movs     r4 ,#0
		msr control ,r4
		movs     r4 ,#0x1000000
		msr xpsr ,r4
		/* enable bus fault, mem manage fault and usage fault to invoke separate exceptions */
		ldr		r0, SHCSR_Value
		ldr		r5, SHCSR_Addr					/* system handler control and status register */
		ldr		r1, [r5]
		orr		r1, r0, r1
		str		r1, [r5]
		
    /* Initialize SRAM */
		ldr r1, =0x20400000
        ldr r2, =0x20427FFF
        subs    r2, r1
        subs    r2, #1
        movs    r0, 0
        movs    r3, 0
		SRAM_LOOP:
        stm r1!, {r0,r3}
        subs r2, 8
        bge SRAM_LOOP
	
	/* Initialize FPU */
	bl		OS_CORTEXM_SetupVFPCoprocessor

	/* set sp to top of kernel stack. */
	ldr		sp, BoardSPAddr

	/* Set VTOR to base of vector table address. */
	ldr		r0, VTOR_Addr
	ldr		r1, BOARD_ExceptionTableAddr
	str		r1, [r0]

	bl		boardStart					/* call C routine, never returns */

	/* If above function ever returns */
	b		boardCatchM7

	OS_ASM_END_FUNC(boardResetStart)

	OS_ASM_FUNC(boardDisableInterruptsAsm)
	OS_ASM_LABEL(boardDisableInterruptsAsm)
	cpsid   i
	bx lr
	OS_ASM_END_FUNC(boardDisableInterruptsAsm)


	OS_ASM_FUNC(boardEnableInterruptsAsm)
	OS_ASM_LABEL(boardEnableInterruptsAsm)
	cpsie   i
	bx lr
	OS_ASM_END_FUNC(boardEnableInterruptsAsm)

	OS_ASM_SRC_END

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
