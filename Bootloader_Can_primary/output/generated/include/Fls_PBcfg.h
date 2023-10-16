/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : C40_IP IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.1
*   Build Version        : S32K3_RTD_2_0_1_D2207_ASR_REL_4_4_REV_0000_20220707
*
*   (c) Copyright 2020 - 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLS_PBCFG_H
#define FLS_PBCFG_H

/**
*   @file Fls_PBcfg.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_PBcfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_PBCFG_VENDOR_ID                    43

#define FLS_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define FLS_PBCFG_AR_RELEASE_MINOR_VERSION     4
#define FLS_PBCFG_AR_RELEASE_REVISION_VERSION  0

#define FLS_PBCFG_SW_MAJOR_VERSION             2
#define FLS_PBCFG_SW_MINOR_VERSION             0
#define FLS_PBCFG_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define FLS_CONFIG_PB \
 extern const Fls_ConfigType Fls_Config;
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif    /* #ifndef FLS_PBCFG_H */
