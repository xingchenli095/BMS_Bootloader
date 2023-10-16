/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file implement a task allowing scheduling the MainFunction call of the BSW
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/
#include <Os.h>
#include <Std_Types.h>
#include <EB_Prj.h>
#include <Watchdog.h>
#include "FlashWrapper.h"

#include <Dio_Cfg.h>
#include <Dio.h>
/*==================[Private define]===============================*/
/* Refresh rate of the watchdog in ms */
#define SWT_TRIGGER     10U

int LedCount = 0u;

/*==================[Private variable]===============================*/
u8 m_ubScheduleFlag;
/*==================[OS resource declarations]===============================*/

DeclareTask(Init_Task);
DeclareTask(OS_TASK_CyclicTask);
DeclareTask(OS_TASK_LoopTask);

/*==================[OS resource definitions]================================*/
TASK(Init_Task)
{
	FLW_Init() ;
	/* Initialization of EB Stack */
    BM_StartUp();
    m_ubScheduleFlag = 0;

 (void) TerminateTask();
}

/*Task definition, task is called every 1ms*/
TASK(CyclicTask)
{

LedCount ++;
if (LedCount == 100)
{
  if(Dio_ReadChannel(DioConf_DioChannel_MY_LED_CYCLIC) == 0U)
  {
    Dio_WriteChannel(DioConf_DioChannel_MY_LED_CYCLIC, 1U);
  }
  else if(Dio_ReadChannel(DioConf_DioChannel_MY_LED_CYCLIC) == 1U)
  {
    Dio_WriteChannel(DioConf_DioChannel_MY_LED_CYCLIC, 0U);
  }

  LedCount = 0;
}


    m_ubScheduleFlag = 1;

  (void) TerminateTask();
}


/*Task definition, task is called every 1ms*/
TASK(LoopTask)
{
    
  while (1)
  {
	/* Scheduler timer */
	if(m_ubScheduleFlag == 0x01U)
	{
	  /* CAN Application cyclic task */
	  BlPduR_Manage();
	  m_ubScheduleFlag = 0;
	}
	
	/* Call the prog_hsm main function */
	PROG_BckdManage();
	FLASH_MainFunction();
  }
 (void) TerminateTask();
}


void ShutdownHook(StatusType errorID)
{
  /* endless loop? */
  TS_PARAM_UNUSED(errorID);
}

void ErrorHook(StatusType error)
{
  static uint8 a = 0;
  /* Figuring out the error code */
  switch (error)
  {
    case E_OS_ACCESS:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_CALLEVEL:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_ID:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_LIMIT:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_NOFUNC:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_RESOURCE:
    {
      /* place user code here */
      a++;
      break;
    }
    case E_OS_STATE:
    {
      a++;
      /* place user code here */
      break;
    }
    case E_OS_VALUE:
    {
      /* place user code here */
      a++;
      break;
    }
    default:
    {
      /* place user code here */
      a++;
      break;
    }
  }
} /* void ErrorHook(StatusType error) */

/*==================[end of file]============================================*/
