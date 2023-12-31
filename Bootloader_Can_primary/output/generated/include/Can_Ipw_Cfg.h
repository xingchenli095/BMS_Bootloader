/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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

#ifndef CAN_IPW_CFG_H
#define CAN_IPW_CFG_H

/**
*   @file    Can_Ipw_Cfg.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration settings generated by user settings.
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"

#include "Can_Ipw_PBcfg.h"

#include "FlexCAN_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_IPW_CFG_VENDOR_ID                    43
#define CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION     4
#define CAN_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define CAN_IPW_CFG_SW_MAJOR_VERSION             2
#define CAN_IPW_CFG_SW_MINOR_VERSION             0
#define CAN_IPW_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against FlexCAN_Ip_Cfg.h */
#if (CAN_IPW_CFG_VENDOR_ID != FLEXCAN_IP_CFG_VENDOR_ID_H)
    #error "Can_Ipw_Cfg.h and FlexCAN_Ip_Cfg.h have different vendor ids"
#endif
#if ((CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXCAN_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION    != FLEXCAN_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_CFG_AR_RELEASE_REVISION_VERSION != FLEXCAN_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
     )
     #error "AUTOSAR Version Numbers of Can_Ipw_Cfg.h and FlexCAN_Ip_Cfg.h are different"
#endif
#if ((CAN_IPW_CFG_SW_MAJOR_VERSION != FLEXCAN_IP_CFG_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_CFG_SW_MINOR_VERSION != FLEXCAN_IP_CFG_SW_MINOR_VERSION_H) || \
     (CAN_IPW_CFG_SW_PATCH_VERSION != FLEXCAN_IP_CFG_SW_PATCH_VERSION_H) \
     )
    #error "Software Version Numbers of Can_Ipw_Cfg.h and FlexCAN_Ip_Cfg.h are different"
#endif

/* Checks against Can_Ipw_PBcfg.h */
#if (CAN_IPW_CFG_VENDOR_ID != CAN_VENDOR_ID_IPW_PBCFG_H)
    #error "Can_Ipw_Cfg.h and Can_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != CAN_AR_RELEASE_MAJOR_VERSION_IPW_PBCFG_H) || \
     (CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION    != CAN_AR_RELEASE_MINOR_VERSION_IPW_PBCFG_H) || \
     (CAN_IPW_CFG_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION_IPW_PBCFG_H) \
    )
    #error "AUTOSAR Version Numbers of Can_Ipw_Cfg.h and Can_Ipw_PBcfg.h are different"
#endif
#if ((CAN_IPW_CFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_IPW_PBCFG_H) || \
     (CAN_IPW_CFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_IPW_PBCFG_H) || \
     (CAN_IPW_CFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_IPW_PBCFG_H) \
    )
    #error "Software Version Numbers of Can_Ipw_Cfg.h and Can_Ipw_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Can_Ipw_Cfg.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define CAN_USE_FLEXCAN_IP                     STD_ON
#define CAN_MB_INTERRUPT_SUPPORT               FLEXCAN_IP_MB_INTERRUPT_SUPPORT
#define CAN_ERROR_INTERRUPT_SUPPORT            FLEXCAN_IP_ERROR_INTERRUPT_SUPPORT
#define CAN_BUSOFF_INTERRUPT_SUPPORT           FLEXCAN_IP_BUSOFF_INTERRUPT_SUPPORT
#define CAN_FEATURE_HAS_DMA_ENABLE             FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE
#define CAN_FEATURE_HAS_PRETENDED_NETWORKING   FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING
#define CAN_FEATURE_HAS_ENHANCED_RX_FIFO       FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO
#define CAN_MB_ENHANCED_RXFIFO                 FLEXCAN_IP_MB_ENHANCED_RXFIFO
#define CAN_FEATURE_HAS_FD                     FLEXCAN_IP_FEATURE_HAS_FD
#define CAN_IPW_EXT \
CAN_IPW_CONFIG_PB

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_IPW_CFG_H */
