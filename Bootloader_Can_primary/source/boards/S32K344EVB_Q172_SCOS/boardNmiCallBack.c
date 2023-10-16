/* boardNmiCallBack.c - board specific code.
 *
 * This file contains call back function from NMI handling.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: boardNmiCallBack.c 36932 2022-03-16 13:37:50Z yash272833 $
*/
#include <board.h>
#include <Os.h>
#include <Os_tool.h>
#include <Os_kernel.h>

void boardNmiCallBack(void)
{
	/* This is the default handling of NMI call back. */
#ifdef  TESTCASE_ExceptionHandlingCortexM
	/* For testing the common exception handling of OS for NMI */
	return;
#else
	OS_ENDLESSLOOP();
#endif /* TESTCASE_ExceptionHandlingCortexM */
	return;
}


/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
