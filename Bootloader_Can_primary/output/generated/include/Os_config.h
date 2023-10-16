/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.113 CORTEXM/S32K34X
 * (Build 20221021)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * Date         : 10/16/23 2:21 PM           !!!IGNORE-LINE!!!
 */

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.6 (required)
 * An identifier with external linkage shall have exactly one external definition.
 *
 * Reason:
 * These symbols are defined in assembly language files and hence,
 * are not visible to the MISRA-C analyzer.
 */
#include <Os.h>
#include <Os_tool.h>
#include <CORTEXM/Os_CORTEXM_timer_fs_stm.h>

#define OS_GENERATION_ID_OS_CONF_H  0x7f73fe6dUL

#define OS_AUTOSAROS_VER            6

#define OS_AUTOSAROS_REV            1

#define OS_AUTOSAROS_CORE_BUILD     20221021

#define OS_AUTOSAROS_ARCH_BUILD     20221021

#ifndef OS_ASM
extern const os_uint32_t OS_os_GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_0GenBuildId;
#endif  /* OS_ASM */

/*===================================================================
 * Advanced Logical Core Interface
 *==================================================================*/
/* Advanced Logical Core Interface preprocessor macros. */
#define OS_ALCI_LOG_TO_PHY_CORE0  0

#define OS_ALCI_PHY_TO_LOG_CORE0  0

/*===================================================================
 * Alarms
 *==================================================================*/
#define OS_NALARMS  2
#define OS_NALARMCALLBACKS  0

#define OS_InternalNoOpAlarm  2

#define OS_ALARM  OS_ALARM_INIT(    /* AlarmCyclicTask */  \
  /* Application id */                        OS_SYSTEM_0,  \
  /* Application pointer */                   &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                           0x1u,  \
  /* Task wrapper */                          &OS_WrapActivateTask,  \
  /* Not used */                              0,  \
  /* Activated task */                        CyclicTask,  \
  /* Alarm counter */                         HwCounter,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[0]  \
),  \
OS_ALARM_INIT(    /* AlarmLoopTask */  \
  /* Application id */                        OS_SYSTEM_0,  \
  /* Application pointer */                   &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                           0x1u,  \
  /* Task wrapper */                          &OS_WrapActivateTask,  \
  /* Not used */                              0,  \
  /* Activated task */                        LoopTask,  \
  /* Alarm counter */                         HwCounter,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[1]  \
),  \
OS_ALARM_INIT(    /* OS_InternalNoOpAlarm */  \
  /* Application id */                        OS_SYSTEM_0,  \
  /* Application pointer */                   &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                           0x1u,  \
  /* No-Op wrapper */                         &OS_WrapNoOp,  \
  /* Not used */                              0,  \
  /* Not used */                              0,  \
  /* Alarm counter */                         HwCounter,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[2]  \
)
#define OS_NALARMS_CORE0  2

/*===================================================================
 * Application modes
 *==================================================================*/
#define OS_NSTARTMODES  1
/* Autostart Tasks */
#define OS_AUTOSTARTTASKS  \
  Init_Task,  \
  OS_NULLTASK

#define OS_STARTMODETASKS  \
  0

/* Autostart Alarms */
#define OS_AUTOSTARTALARMS  \
    {  \
      AlarmCyclicTask,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter(10000000),  \
      OS_NsToTicks_HwCounter(1000000)  \
    },  \
    {  \
      AlarmLoopTask,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter(10000000),  \
      OS_NsToTicks_HwCounter(10000000)  \
    },  \
    {  \
      OS_NULLALARM,  \
      OS_STARTMETHOD_REL,  \
      0,  \
      0  \
    }

#define OS_STARTMODEALARMS  \
  0

/* Autostart ScheduleTables */


/*===================================================================
 * Applications
 *==================================================================*/
#define OS_NAPPS        1
#define OS_NAPPSNONPRIV  0
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_0  0
#endif

#define OS_APPCONFIG  OS_APPCONFIG_INIT(    /* OS_SYSTEM_0 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_0GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0x1,  \
  /* Accessing applications */                      0x1,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_0,  \
  /* dynamic data */                                &OS_appDynamic_core0[0],  \
  /* CPU core */                                    0,  \
    OS_ARCHAPP_INIT(  \
      /* size of the private data region for MPU */                    OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
)

/* Trusted Functions */
#define OS_NFUNCTIONS  0

#define OS_SHOOKSTACKLEN  0
#define OS_EHOOKSTACKLEN  0
#define OS_NAPPS_CORE0    1

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_PROPERTIES_CORE0  (OS_U(0)|OS_COREPROP_USED_BIT)

/*===================================================================
 * Channel Initializers
 *==================================================================*/
#define OS_IOC_ENABLED  0

/*===================================================================
 * Configured Modes
 *==================================================================*/
#define OS_CONFIGMODE        (OS_BCC1|OS_SCHEDMIX|OS_EXTENDED|OS_DBGPROT_FULL)
#define OS_IECMODE           (OS_IEC_AUTOSAR)
#define OS_HOOKSELECTION     (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK)
#define OS_PERMITTEDCONTEXT  (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE       0

/*===================================================================
 * Counters
 *==================================================================*/
#define OS_NSHAREDHWCOUNTERTIMESTAMP         1
#define OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID  2
#define OS_SHAREDHWCOUNTERTIMESTAMP_COREID   0
#define OS_NCOUNTERS    1
#define OS_NSWCOUNTERS  0

#define OS_COUNTER  OS_COUNTER_INIT(    /* HwCounter */  \
  /* Application id */       OS_SYSTEM_0,  \
  /* Application pointer */  &OS_appTable[OS_SYSTEM_0],  \
  /* Update function */      &OS_HwCounterTimestampUpdate,  \
  /* Permissions */          0x1u,  \
  /* Hardware timer */       &OS_hwTimer[0],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core0[0]  \
)

#define OS_NINTERNALTICKERS  0
/* Number of counters available on cores */
#define OS_NCOUNTERS_CORE0  1

/*===================================================================
 * Events
 *==================================================================*/
#define OS_NEVENTS  0

/*===================================================================
 * Execution timer
 *==================================================================*/
#define OS_EXECUTIONTIMER_INIT     /* Execution timer init */  \
  OS_NULL

/*===================================================================
 * Time-stamp timer
 *==================================================================*/
#define OS_TIMESTAMPTIMERINDEX  0

/*===================================================================
 * Hardware Timers
 *==================================================================*/
#define OS_NHWTIMERS        1
#define OS_NHWTIMERS_CORE0  1

#define OS_HWTIMER {    /* STM0_0 */  \
  /* Driver table */                     &OS_timerSTMdriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core0[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    0u,  \
  /* Driver channel */                   0u,  \
  /* core */                             0u,  \
}

/*===================================================================
 * Hook Functions
 *==================================================================*/
#define OS_ERRORHOOK       &ErrorHook
#define OS_SHUTDOWNHOOK    &ShutdownHook

/*===================================================================
 * Interrupts
 *==================================================================*/

#define OS_NINTERRUPTS         4
#define OS_NCAT1_INTERRUPTS    0
#define OS_NCAT2_INTERRUPTS    4
#define OS_NCATK_INTERRUPTS    0
#define OS_NCAT2K_INTERRUPTS   0
#define OS_NISRSEXECTIMELIMIT  0
#define OS_NISRSINTLOCKLIMIT   0
#define OS_NISRSRESLOCKLIMIT   0
#define OS_NISRACCOUNTING      0
#define OS_CAT1LOCK            2
#define OS_CAT2LOCK            2
#define OS_KERNLOCK            2
#define OS_XCOREUNLOCK         OS_KERNLOCK
#define OS_ENABLEALLLOCK       15

/* Internal Interrupt Ids */
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM0_0  3
#endif

/* Isr Config Struct Init Macros. */
#define OS_ISRCONFIG  OS_ISRCONFIG_INIT(    /* CAN0_ORED_0_31_MB_IRQHandler */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_0_31_MB_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_0_31_MB_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[0],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 110,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT,  \
      /* size of the private data region for MPU */                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the ISR stack for MPU */                              OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0_ORED_32_63_MB_IRQHandler */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_32_63_MB_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_32_63_MB_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 111,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT,  \
      /* size of the private data region for MPU */                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the ISR stack for MPU */                              OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0_ORED_IRQHandler */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[2],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 109,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT,  \
      /* size of the private data region for MPU */                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the ISR stack for MPU */                              OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM0_0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        512u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM0_0,  \
  /* dynamic data */                      &OS_isrDynamic_core0[3],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 39,  \
      /* ISR priority */                                               2,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT,  \
      /* size of the private data region for MPU */                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the ISR stack for MPU */                              OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
)

/* Stack Macros */
#define OS_ISTACKBASE_0          OS_kernStack0
#define OS_ISTACKLEN_0           OS_U( 3072 )
#define OS_NINTERRUPTS_CORE0     4
#define OS_NISRACCOUNTING_CORE0  0

/*===================================================================
 * Kernel data
 *==================================================================*/
#define OS_KERNELDATA_INIT_CORE0  /* kernel data core 0 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_0, OS_ISTACKLEN_0 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_0,  \
  /* iStackLen */                OS_ISTACKLEN_0,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE

/*===================================================================
 * Optimization
 *==================================================================*/
#define OS_CAT1_DIRECTCALL  0

/*===================================================================
 * Rate Monitor
 *==================================================================*/
#define OS_NRATEMONS  0
#define OS_NRATEMONS_CORE0  0

#define OS_NRATETIMERS    OS_NRATETIMERS_CORE0
#define OS_RATEMONCONFIG  OS_RATEMONCONFIG_CORE0

/*===================================================================
 * Resource Lock Timing
 *==================================================================*/
#define OS_NRESLOCKTIMES  0

/*===================================================================
 * Resources
 *==================================================================*/
#define OS_NRESOURCES  1


#define OS_RESOURCES  OS_RESOURCES_INIT(    /* RES_SCHEDULER_0 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */          0x1u,  \
  /* Priority */             3,  \
  /* dynamic data */         &OS_resourceDynamic_core0[0]  \
)
/* Number of Non-Internal Used resources on cores */
#define OS_NRESOURCES_CORE0  1

/*===================================================================
 * Schedule Tables
 *==================================================================*/
#define OS_NSCHEDULES      0
#define OS_NSCHEDULESSYNC  0


/* ScheduleTables expiry points */

#define OS_NSCHEDULES_CORE0  0

/*===================================================================
 * Spinlocks
 *==================================================================*/
#define OS_NAUTOSARSPINLOCKS  0

/*===================================================================
 * Stacks
 *==================================================================*/
#define OS_STACK_REGION_ALIGNMENT  8
/* Task Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 1060, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 1060, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 292, 8 );
#endif
#endif  /* OS_ASM */
/* Interrupt Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack0, .bss.core0.os_kernstack0, 768, 8 );
#endif
#endif  /* OS_ASM */

/*===================================================================
 * Tasks
 *==================================================================*/
#ifndef OS_ASM
DeclareTask(Init_Task);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(CyclicTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(LoopTask);
#endif  /* OS_ASM */

#define OS_NTASKS               3
#define OS_NETASKS              0
#define OS_NTASKSEXECTIMELIMIT  0
#define OS_NTASKSINTLOCKLIMIT   0
#define OS_NTASKSRESLOCKLIMIT   0
#define OS_TASKCONFIG  OS_TASKCONFIG_INIT(    /* Init_Task */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[0],  \
  /* Run priority */                   3u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_Init_Task,  \
  /* Stack base */                     &OS_taskStack0_slot2[0],  \
  /* Stack size */                     1168u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_USEFPU|OS_TF_NONPREEMPT),  \
  /* Task ID */                        Init_Task,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              OS_NULL,  \
  /* end of data/bss */                OS_NULL,  \
  /* start of initial data */          OS_NULL,  \
  /* end of initial data */            OS_NULL,  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                    0x1u,  \
    OS_ARCHTASK_INIT(  \
      /* size of the private data region for MPU*/                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the task stack for MPU*/                             OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* CyclicTask */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[1],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_CyclicTask,  \
  /* Stack base */                     &OS_taskStack0_slot0[0],  \
  /* Stack size */                     4240u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_USEFPU),  \
  /* Task ID */                        CyclicTask,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              OS_NULL,  \
  /* end of data/bss */                OS_NULL,  \
  /* start of initial data */          OS_NULL,  \
  /* end of initial data */            OS_NULL,  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                    0x1u,  \
    OS_ARCHTASK_INIT(  \
      /* size of the private data region for MPU*/                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the task stack for MPU*/                             OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* LoopTask */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[2],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_LoopTask,  \
  /* Stack base */                     &OS_taskStack0_slot1[0],  \
  /* Stack size */                     4240u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_USEFPU),  \
  /* Task ID */                        LoopTask,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              OS_NULL,  \
  /* end of data/bss */                OS_NULL,  \
  /* start of initial data */          OS_NULL,  \
  /* end of initial data */            OS_NULL,  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                    0x1u,  \
    OS_ARCHTASK_INIT(  \
      /* size of the private data region for MPU*/                    OS_CORTEXM_MPU_SIZE_DISABLED,  \
      /* size of the task stack for MPU*/                             OS_CORTEXM_MPU_SIZE_DISABLED  \
    )  \
)
#define OS_NTASKS_CORE0  3

/*===================================================================
 * Tasks Common Scheduling
 *==================================================================*/
#define OS_NPRIORITIES_CORE0  4

/*===================================================================
 * Tasks Linked List Scheduling
 *==================================================================*/
#define OS_NTASKACCOUNTING  0
#define OS_NTASKACTIVATIONS  3
#define OS_NTASKACCOUNTING_CORE0   0
#define OS_NTASKACTIVATIONS_CORE0  3
#define OS_TASKACTIVATIONS_CORE0   \
  /* 0 */ &OS_taskTable[Init_Task],    \
  /* 1 */ &OS_taskTable[CyclicTask],    \
  /* 2 */ &OS_taskTable[LoopTask]

/*===================================================================
 * CORTEXM memory region sizes for MPU
 *==================================================================*/
#define OS_CORTEXM_MPU_GLOBAL_ROM_SIZE  OS_CORTEXM_MPU_SIZE_4M
#define OS_CORTEXM_MPU_GLOBAL_RAM_SIZE  OS_CORTEXM_MPU_SIZE_512K
#define OS_CORTEXM_MPU_SHOOK_SIZE       OS_CORTEXM_MPU_SIZE_DISABLED
#define OS_CORTEXM_MPU_EHOOK_SIZE       OS_CORTEXM_MPU_SIZE_DISABLED
#define OS_CORTEXM_MPU_SIZE_KERNSTACK0  OS_CORTEXM_MPU_SIZE_4K

/*===================================================================
 * CORTEXM Interrupts
 *==================================================================*/
#define OS_SRC6e_C0_NAME                      _OS_VECTOR_I110_FlexCAN0_1
#define OS_SRC6e_C0_ISRID                     CAN0_ORED_0_31_MB_IRQHandler
#define OS_SRC6e_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC6e_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC6e_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC6f_C0_NAME                      _OS_VECTOR_I111_FlexCAN0_2
#define OS_SRC6f_C0_ISRID                     CAN0_ORED_32_63_MB_IRQHandler
#define OS_SRC6f_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC6f_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC6f_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC6d_C0_NAME                      _OS_VECTOR_I109_FlexCAN0_0
#define OS_SRC6d_C0_ISRID                     CAN0_ORED_IRQHandler
#define OS_SRC6d_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC6d_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC6d_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC27_C0_NAME                      _OS_VECTOR_I039_STM_0
#define OS_SRC27_C0_ISRID                     Os_Counter_STM0_0
#define OS_SRC27_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC27_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC27_C0_LOCKLEVEL                 OS_KERNLOCK

#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
