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

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H    0x7f73fe6dUL

#define OS_AUTOSAROS_VER         6

#define OS_AUTOSAROS_REV         1

#define OS_AUTOSAROS_CORE_BUILD  20221021

#define OS_AUTOSAROS_ARCH_BUILD  20221021

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#include <Os_api.h>

/*===================================================================
 * Alarms
 *==================================================================*/
#define AlarmCyclicTask  0
#define AlarmLoopTask  1

/*===================================================================
 * Application modes
 *==================================================================*/
#define OSDEFAULTAPPMODE  0

/*===================================================================
 * Applications
 *==================================================================*/
/* Application Hooks */
/* Trusted Functions */

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_CORE_ID_0  0

/*===================================================================
 * Core Mapping
 *==================================================================*/
#define RES_SCHEDULER  0u

/*===================================================================
 * Counters
 *==================================================================*/
/* Macros for the configured counter values and time conversions */
#define OSMAXALLOWEDVALUE_HwCounter  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter  OS_U(1000)
#define OSMINCYCLE_HwCounter  OS_U(1)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter(x)  OS_NsToTicks_STM0_0((x))
#define OS_TicksToNs_HwCounter(x)  OS_TicksToNs_STM0_0((x))
#define OS_TICKS2NS_HwCounter(x)   (OS_TicksToNs_STM0_0((x)))
#define OS_TICKS2US_HwCounter(x)   (OS_TicksToNs_STM0_0((x))/1000u)
#define OS_TICKS2MS_HwCounter(x)   (OS_TicksToNs_STM0_0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter(x)  (OS_TicksToNs_STM0_0((x))/1000000000u)

/* Non-Internal Counter Ids */
#define HwCounter  0


/* System Counter Macros */
#define OSMAXALLOWEDVALUE  OSMAXALLOWEDVALUE_HwCounter
#define OSTICKSPERBASE     OSTICKSPERBASE_HwCounter
#define OSMINCYCLE         OSMINCYCLE_HwCounter
#define OSTICKDURATION     OS_TicksToNs_HwCounter(1u)

/*===================================================================
 * Events
 *==================================================================*/

/*===================================================================
 * Interrupts
 *==================================================================*/
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_0_31_MB_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_0_31_MB_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_0_31_MB_IRQHandler_ISR_VECTOR    110
#define CAN0_ORED_0_31_MB_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_32_63_MB_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_32_63_MB_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_32_63_MB_IRQHandler_ISR_VECTOR    111
#define CAN0_ORED_32_63_MB_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_IRQHandler_ISR_VECTOR    109
#define CAN0_ORED_IRQHandler_ISR_LEVEL     7
#define Os_Counter_STM0_0_ISR_CATEGORY  2
#define Os_Counter_STM0_0_ISR_VECTOR    39
#define Os_Counter_STM0_0_ISR_LEVEL     2
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_0_31_MB_IRQHandler  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_32_63_MB_IRQHandler  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_IRQHandler  2
#endif

/*===================================================================
 * Resources
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_0  0
#endif

/*===================================================================
 * Schedule Tables
 *==================================================================*/

/*===================================================================
 * Spinlocks
 *==================================================================*/

/*===================================================================
 * Tasks
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Init_Task  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CyclicTask  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define LoopTask  2
#endif

/*===================================================================
 * Time-stamp timer
 *==================================================================*/
#define OS_TimestampNsToTicks(ns)     OS_NsToTicks_STM0_0(ns)
#define OS_TimestampTicksToNs(ticks)  OS_TicksToNs_STM0_0(ticks)
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
