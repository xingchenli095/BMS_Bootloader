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

/**
*   @file Qspi_Ip_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_PBCFG_VENDOR_ID_C                      43
#define QSPI_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define QSPI_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define QSPI_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define QSPI_IP_PBCFG_SW_MAJOR_VERSION_C               2
#define QSPI_IP_PBCFG_SW_MINOR_VERSION_C               0
#define QSPI_IP_PBCFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_PBcfg.h header file are of the same vendor */
#if (QSPI_IP_PBCFG_VENDOR_ID_C != QSPI_IP_PBCFG_VENDOR_ID)
    #error "Qspi_Ip_PBcfg.c and Qspi_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_PBcfg.h header file are of the same Autosar version */
#if ((QSPI_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_PBcfg.h are different"
#endif
/* Check if current file and Qspi_Ip_PBcfg.h header file are of the same software version */
#if ((QSPI_IP_PBCFG_SW_MAJOR_VERSION_C != QSPI_IP_PBCFG_SW_MAJOR_VERSION) || \
     (QSPI_IP_PBCFG_SW_MINOR_VERSION_C != QSPI_IP_PBCFG_SW_MINOR_VERSION) || \
     (QSPI_IP_PBCFG_SW_PATCH_VERSION_C != QSPI_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

                    



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* External QSPI flash parameters. */





#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/
