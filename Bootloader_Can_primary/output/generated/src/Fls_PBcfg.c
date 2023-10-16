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
*   @file Fls_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_SW_MAJOR_VERSION_CFG_C               2
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

                    
#define FLS_START_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"

/* aFlsSectorFlags */
static const uint8 FlsConfigSet_aFlsSectorFlags[32U] =
{
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_0 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_8 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_16 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_24 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_32 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_40 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_48 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_56 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_64 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_72 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_80 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_88 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_96 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_104 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_112 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_120 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_128 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_136 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_144 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_152 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_160 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_168 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_176 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_184 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_192 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_200 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_208 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_216 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_224 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_232 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH,  /* FlsSector_240 */
    (uint8)FLS_SECTOR_ERASE_ASYNCH |(uint8)FLS_PAGE_WRITE_ASYNCH   /* FlsSector_248 */
};

#define FLS_STOP_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* aFlsSectorEndAddr */
static const Fls_AddressType FlsConfigSet_aFlsSectorEndAddr[32U] =
{
    (Fls_AddressType)65535U,  /* FlsSector_0 */
    (Fls_AddressType)131071U,  /* FlsSector_8 */
    (Fls_AddressType)196607U,  /* FlsSector_16 */
    (Fls_AddressType)262143U,  /* FlsSector_24 */
    (Fls_AddressType)327679U,  /* FlsSector_32 */
    (Fls_AddressType)393215U,  /* FlsSector_40 */
    (Fls_AddressType)458751U,  /* FlsSector_48 */
    (Fls_AddressType)524287U,  /* FlsSector_56 */
    (Fls_AddressType)589823U,  /* FlsSector_64 */
    (Fls_AddressType)655359U,  /* FlsSector_72 */
    (Fls_AddressType)720895U,  /* FlsSector_80 */
    (Fls_AddressType)786431U,  /* FlsSector_88 */
    (Fls_AddressType)851967U,  /* FlsSector_96 */
    (Fls_AddressType)917503U,  /* FlsSector_104 */
    (Fls_AddressType)983039U,  /* FlsSector_112 */
    (Fls_AddressType)1048575U,  /* FlsSector_120 */
    (Fls_AddressType)1114111U,  /* FlsSector_128 */
    (Fls_AddressType)1179647U,  /* FlsSector_136 */
    (Fls_AddressType)1245183U,  /* FlsSector_144 */
    (Fls_AddressType)1310719U,  /* FlsSector_152 */
    (Fls_AddressType)1376255U,  /* FlsSector_160 */
    (Fls_AddressType)1441791U,  /* FlsSector_168 */
    (Fls_AddressType)1507327U,  /* FlsSector_176 */
    (Fls_AddressType)1572863U,  /* FlsSector_184 */
    (Fls_AddressType)1638399U,  /* FlsSector_192 */
    (Fls_AddressType)1703935U,  /* FlsSector_200 */
    (Fls_AddressType)1769471U,  /* FlsSector_208 */
    (Fls_AddressType)1835007U,  /* FlsSector_216 */
    (Fls_AddressType)1900543U,  /* FlsSector_224 */
    (Fls_AddressType)1966079U,  /* FlsSector_232 */
    (Fls_AddressType)2031615U,  /* FlsSector_240 */
    (Fls_AddressType)2097151U   /* FlsSector_248 */
};

/* paSectorSize */
static const Fls_LengthType FlsConfigSet_aFlsSectorSize[32U] =
{
    (Fls_LengthType)8192U,  /* FlsSector_0 */
    (Fls_LengthType)8192U,  /* FlsSector_8 */
    (Fls_LengthType)8192U,  /* FlsSector_16 */
    (Fls_LengthType)8192U,  /* FlsSector_24 */
    (Fls_LengthType)8192U,  /* FlsSector_32 */
    (Fls_LengthType)8192U,  /* FlsSector_40 */
    (Fls_LengthType)8192U,  /* FlsSector_48 */
    (Fls_LengthType)8192U,  /* FlsSector_56 */
    (Fls_LengthType)8192U,  /* FlsSector_64 */
    (Fls_LengthType)8192U,  /* FlsSector_72 */
    (Fls_LengthType)8192U,  /* FlsSector_80 */
    (Fls_LengthType)8192U,  /* FlsSector_88 */
    (Fls_LengthType)8192U,  /* FlsSector_96 */
    (Fls_LengthType)8192U,  /* FlsSector_104 */
    (Fls_LengthType)8192U,  /* FlsSector_112 */
    (Fls_LengthType)8192U,  /* FlsSector_120 */
    (Fls_LengthType)8192U,  /* FlsSector_128 */
    (Fls_LengthType)8192U,  /* FlsSector_136 */
    (Fls_LengthType)8192U,  /* FlsSector_144 */
    (Fls_LengthType)8192U,  /* FlsSector_152 */
    (Fls_LengthType)8192U,  /* FlsSector_160 */
    (Fls_LengthType)8192U,  /* FlsSector_168 */
    (Fls_LengthType)8192U,  /* FlsSector_176 */
    (Fls_LengthType)8192U,  /* FlsSector_184 */
    (Fls_LengthType)8192U,  /* FlsSector_192 */
    (Fls_LengthType)8192U,  /* FlsSector_200 */
    (Fls_LengthType)8192U,  /* FlsSector_208 */
    (Fls_LengthType)8192U,  /* FlsSector_216 */
    (Fls_LengthType)8192U,  /* FlsSector_224 */
    (Fls_LengthType)8192U,  /* FlsSector_232 */
    (Fls_LengthType)8192U,  /* FlsSector_240 */
    (Fls_LengthType)8192U   /* FlsSector_248 */
};

/* paSectorPageSize */
static const Fls_LengthType FlsConfigSet_aFlsSectorPageSize[32U] =
{
    (Fls_LengthType)8U,  /* FlsSector_0 */
    (Fls_LengthType)8U,  /* FlsSector_8 */
    (Fls_LengthType)8U,  /* FlsSector_16 */
    (Fls_LengthType)8U,  /* FlsSector_24 */
    (Fls_LengthType)8U,  /* FlsSector_32 */
    (Fls_LengthType)8U,  /* FlsSector_40 */
    (Fls_LengthType)8U,  /* FlsSector_48 */
    (Fls_LengthType)8U,  /* FlsSector_56 */
    (Fls_LengthType)8U,  /* FlsSector_64 */
    (Fls_LengthType)8U,  /* FlsSector_72 */
    (Fls_LengthType)8U,  /* FlsSector_80 */
    (Fls_LengthType)8U,  /* FlsSector_88 */
    (Fls_LengthType)8U,  /* FlsSector_96 */
    (Fls_LengthType)8U,  /* FlsSector_104 */
    (Fls_LengthType)8U,  /* FlsSector_112 */
    (Fls_LengthType)8U,  /* FlsSector_120 */
    (Fls_LengthType)8U,  /* FlsSector_128 */
    (Fls_LengthType)8U,  /* FlsSector_136 */
    (Fls_LengthType)8U,  /* FlsSector_144 */
    (Fls_LengthType)8U,  /* FlsSector_152 */
    (Fls_LengthType)8U,  /* FlsSector_160 */
    (Fls_LengthType)8U,  /* FlsSector_168 */
    (Fls_LengthType)8U,  /* FlsSector_176 */
    (Fls_LengthType)8U,  /* FlsSector_184 */
    (Fls_LengthType)8U,  /* FlsSector_192 */
    (Fls_LengthType)8U,  /* FlsSector_200 */
    (Fls_LengthType)8U,  /* FlsSector_208 */
    (Fls_LengthType)8U,  /* FlsSector_216 */
    (Fls_LengthType)8U,  /* FlsSector_224 */
    (Fls_LengthType)8U,  /* FlsSector_232 */
    (Fls_LengthType)8U,  /* FlsSector_240 */
    (Fls_LengthType)8U   /* FlsSector_248 */
};

/* Info structure (reg prot, ecc trigger, etc) for each internal flash sector. */
static const Fls_Flash_InternalSectorInfoType FlsSector_0_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x000000UL),  /* pSectorStartAddressPtr */
    16U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_8_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x010000UL),  /* pSectorStartAddressPtr */
    24U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_16_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x020000UL),  /* pSectorStartAddressPtr */
    32U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_24_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x030000UL),  /* pSectorStartAddressPtr */
    40U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_32_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x040000UL),  /* pSectorStartAddressPtr */
    48U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_40_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x050000UL),  /* pSectorStartAddressPtr */
    56U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_48_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x060000UL),  /* pSectorStartAddressPtr */
    64U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_56_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x070000UL),  /* pSectorStartAddressPtr */
    72U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_64_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x080000UL),  /* pSectorStartAddressPtr */
    80U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_72_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x090000UL),  /* pSectorStartAddressPtr */
    88U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_80_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0A0000UL),  /* pSectorStartAddressPtr */
    96U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_88_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0B0000UL),  /* pSectorStartAddressPtr */
    104U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_96_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0C0000UL),  /* pSectorStartAddressPtr */
    112U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_104_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0D0000UL),  /* pSectorStartAddressPtr */
    120U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_112_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0E0000UL),  /* pSectorStartAddressPtr */
    128U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_120_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x0F0000UL),  /* pSectorStartAddressPtr */
    136U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_128_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x100000UL),  /* pSectorStartAddressPtr */
    144U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_136_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x110000UL),  /* pSectorStartAddressPtr */
    152U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_144_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x120000UL),  /* pSectorStartAddressPtr */
    160U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_152_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x130000UL),  /* pSectorStartAddressPtr */
    168U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_160_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x140000UL),  /* pSectorStartAddressPtr */
    176U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_168_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x150000UL),  /* pSectorStartAddressPtr */
    184U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_176_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x160000UL),  /* pSectorStartAddressPtr */
    192U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_184_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x170000UL),  /* pSectorStartAddressPtr */
    200U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_192_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x180000UL),  /* pSectorStartAddressPtr */
    208U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_200_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x190000UL),  /* pSectorStartAddressPtr */
    216U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_208_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1A0000UL),  /* pSectorStartAddressPtr */
    224U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_216_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1B0000UL),  /* pSectorStartAddressPtr */
    232U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_224_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1C0000UL),  /* pSectorStartAddressPtr */
    240U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_232_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1D0000UL),  /* pSectorStartAddressPtr */
    248U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_240_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1E0000UL),  /* pSectorStartAddressPtr */
    256U  /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_248_FlsConfigSet_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x1F0000UL),  /* pSectorStartAddressPtr */
    264U  /* Sector location to calculate cfgCRC */
};


/* FLASH physical sectorization description */
static const Fls_Flash_InternalSectorInfoType * const FlsConfigSet_aSectorList[32U] =
{
    &FlsSector_0_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S000 */
    &FlsSector_8_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S008 */
    &FlsSector_16_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S016 */
    &FlsSector_24_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S024 */
    &FlsSector_32_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S032 */
    &FlsSector_40_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S040 */
    &FlsSector_48_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S048 */
    &FlsSector_56_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S056 */
    &FlsSector_64_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S064 */
    &FlsSector_72_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S072 */
    &FlsSector_80_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S080 */
    &FlsSector_88_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S088 */
    &FlsSector_96_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S096 */
    &FlsSector_104_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S104 */
    &FlsSector_112_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S112 */
    &FlsSector_120_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_0_S120 */
    &FlsSector_128_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S128 */
    &FlsSector_136_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S136 */
    &FlsSector_144_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S144 */
    &FlsSector_152_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S152 */
    &FlsSector_160_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S160 */
    &FlsSector_168_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S168 */
    &FlsSector_176_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S176 */
    &FlsSector_184_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S184 */
    &FlsSector_192_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S192 */
    &FlsSector_200_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S200 */
    &FlsSector_208_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S208 */
    &FlsSector_216_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S216 */
    &FlsSector_224_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S224 */
    &FlsSector_232_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S232 */
    &FlsSector_240_FlsConfigSet_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_1_S240 */
    &FlsSector_248_FlsConfigSet_sInternalSectorInfo   /* FLS_CODE_ARRAY_0_BLOCK_1_S248 */
};

/* paHwCh */
static const Fls_HwChType FlsConfigSet_paHwCh[32U] =
{
    FLS_CH_INTERN,  /* FlsSector_0 */
    FLS_CH_INTERN,  /* FlsSector_8 */
    FLS_CH_INTERN,  /* FlsSector_16 */
    FLS_CH_INTERN,  /* FlsSector_24 */
    FLS_CH_INTERN,  /* FlsSector_32 */
    FLS_CH_INTERN,  /* FlsSector_40 */
    FLS_CH_INTERN,  /* FlsSector_48 */
    FLS_CH_INTERN,  /* FlsSector_56 */
    FLS_CH_INTERN,  /* FlsSector_64 */
    FLS_CH_INTERN,  /* FlsSector_72 */
    FLS_CH_INTERN,  /* FlsSector_80 */
    FLS_CH_INTERN,  /* FlsSector_88 */
    FLS_CH_INTERN,  /* FlsSector_96 */
    FLS_CH_INTERN,  /* FlsSector_104 */
    FLS_CH_INTERN,  /* FlsSector_112 */
    FLS_CH_INTERN,  /* FlsSector_120 */
    FLS_CH_INTERN,  /* FlsSector_128 */
    FLS_CH_INTERN,  /* FlsSector_136 */
    FLS_CH_INTERN,  /* FlsSector_144 */
    FLS_CH_INTERN,  /* FlsSector_152 */
    FLS_CH_INTERN,  /* FlsSector_160 */
    FLS_CH_INTERN,  /* FlsSector_168 */
    FLS_CH_INTERN,  /* FlsSector_176 */
    FLS_CH_INTERN,  /* FlsSector_184 */
    FLS_CH_INTERN,  /* FlsSector_192 */
    FLS_CH_INTERN,  /* FlsSector_200 */
    FLS_CH_INTERN,  /* FlsSector_208 */
    FLS_CH_INTERN,  /* FlsSector_216 */
    FLS_CH_INTERN,  /* FlsSector_224 */
    FLS_CH_INTERN,  /* FlsSector_232 */
    FLS_CH_INTERN,  /* FlsSector_240 */
    FLS_CH_INTERN   /* FlsSector_248 */
};

/* paSectorHwAddress */
static const Fls_AddressType FlsConfigSet_paSectorHwAddress[32U] =
{
    (Fls_AddressType)0U,  /* FlsSector_0 */
    (Fls_AddressType)0U,  /* FlsSector_8 */
    (Fls_AddressType)0U,  /* FlsSector_16 */
    (Fls_AddressType)0U,  /* FlsSector_24 */
    (Fls_AddressType)0U,  /* FlsSector_32 */
    (Fls_AddressType)0U,  /* FlsSector_40 */
    (Fls_AddressType)0U,  /* FlsSector_48 */
    (Fls_AddressType)0U,  /* FlsSector_56 */
    (Fls_AddressType)0U,  /* FlsSector_64 */
    (Fls_AddressType)0U,  /* FlsSector_72 */
    (Fls_AddressType)0U,  /* FlsSector_80 */
    (Fls_AddressType)0U,  /* FlsSector_88 */
    (Fls_AddressType)0U,  /* FlsSector_96 */
    (Fls_AddressType)0U,  /* FlsSector_104 */
    (Fls_AddressType)0U,  /* FlsSector_112 */
    (Fls_AddressType)0U,  /* FlsSector_120 */
    (Fls_AddressType)0U,  /* FlsSector_128 */
    (Fls_AddressType)0U,  /* FlsSector_136 */
    (Fls_AddressType)0U,  /* FlsSector_144 */
    (Fls_AddressType)0U,  /* FlsSector_152 */
    (Fls_AddressType)0U,  /* FlsSector_160 */
    (Fls_AddressType)0U,  /* FlsSector_168 */
    (Fls_AddressType)0U,  /* FlsSector_176 */
    (Fls_AddressType)0U,  /* FlsSector_184 */
    (Fls_AddressType)0U,  /* FlsSector_192 */
    (Fls_AddressType)0U,  /* FlsSector_200 */
    (Fls_AddressType)0U,  /* FlsSector_208 */
    (Fls_AddressType)0U,  /* FlsSector_216 */
    (Fls_AddressType)0U,  /* FlsSector_224 */
    (Fls_AddressType)0U,  /* FlsSector_232 */
    (Fls_AddressType)0U,  /* FlsSector_240 */
    (Fls_AddressType)0U   /* FlsSector_248 */
};



/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
const Fls_ConfigType Fls_Config =
{
    (Fls_AcErasePtrType)NULL_PTR,                                     /* FlsAcErase */
    (Fls_AcWritePtrType)NULL_PTR,                                     /* FlsAcWrite */
    NULL_PTR,                                                         /* FlsACCallback */
    NULL_PTR,                                                         /* FlsJobEndNotification */
    NULL_PTR,                                                         /* FlsJobErrorNotification */
    NULL_PTR,                                                         /* FlsMCoreTimeoutNotification */
    NULL_PTR,                                                         /* FlsReadFunctionCallout */
    MEMIF_MODE_FAST,                                                  /* FlsDefaultMode */
    1048576U,                                                         /* FlsMaxReadFastMode */
    1024U,                                                            /* FlsMaxReadNormalMode */
    256U,                                                             /* FlsMaxWriteFastMode */
    8U,                                                               /* FlsMaxWriteNormalMode */
    32U,                                                              /* FlsSectorCount */
    &FlsConfigSet_aFlsSectorEndAddr,                                  /* (*paSectorEndAddr)[] */
    &FlsConfigSet_aFlsSectorSize,                                     /* (*paSectorSize)[] */
    &FlsConfigSet_aSectorList,                                        /* (*pSectorList)[] */
    &FlsConfigSet_aFlsSectorFlags,                                    /* (*paSectorFlags)[] */
    &FlsConfigSet_aFlsSectorPageSize,                                 /* (*paSectorPageSize)[] */
    &FlsConfigSet_paHwCh,                                             /* (*paHwCh)[] */
    &FlsConfigSet_paSectorHwAddress,                                  /* (*paSectorHwAddress)[] */
    NULL_PTR,                                                         /* FlsQspiConfig */
    &FlsConfigSet_InitCfg,                                            /* FlsInternalConfig */
    53031U                                                            /* configCrc */
};


#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

