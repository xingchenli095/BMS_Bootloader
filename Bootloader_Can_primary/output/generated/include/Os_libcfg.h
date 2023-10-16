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
 * 
 * The name of the optimized lib will be : OS_lib_6002ef7b98
 */

#ifndef OS_LIBCFG_H
#define OS_LIBCFG_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_LIBCONF_H  0x7f73fe6dUL

#define OS_AUTOSAROS_VER         6

#define OS_AUTOSAROS_REV         1

#define OS_AUTOSAROS_CORE_BUILD  20221021

#define OS_AUTOSAROS_ARCH_BUILD  20221021

#define OS_USE_OPTIMIZATION_OPTIONS         0
#if OS_USE_OPTIMIZATION_OPTIONS
#define OS_EXCLUDE_EXTRA_CHECK              1
#define OS_EXCLUDE_STACKCHECK               1
#define OS_EXCLUDE_PRETASKHOOK              1
#define OS_EXCLUDE_POSTTASKHOOK             1
#define OS_EXCLUDE_STARTUPHOOK              1
#define OS_EXCLUDE_PREISRHOOK               1
#define OS_EXCLUDE_POSTISRHOOK              1
#define OS_EXCLUDE_PROTECTIONHOOK           1
#define OS_EXCLUDE_TIMINGPROTECTION         1
#define OS_EXCLUDE_RATEMONITORS             1
#define OS_EXCLUDE_RESOURCEONISR            1
#define OS_EXCLUDE_PARAMETERACCESS          1
#define OS_EXCLUDE_ERRORHOOK_APP            1
#define OS_EXCLUDE_MULTIPLE_ACTIVATIONS     1
#define OS_EXCLUDE_EVENTS                   1
#define OS_EXCLUDE_ERRORHANDLINGFORVOIDAPI  1
#define OS_EXCLUDE_SWCOUNTER                1
#endif

#ifdef __cplusplus
}
#endif
#endif  /* OS_LIBCFG_H */
