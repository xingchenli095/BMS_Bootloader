/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                2
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                1

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on SIUL2 instance
*/
static const uint16 Port_SIUL2_0_au16InMuxSettingsIndex[145] =
{
    /* Index to address the input settings for pad 0*/
    (uint16)1, 
    /* Index to address the input settings for pad 1*/
    (uint16)7, 
    /* Index to address the input settings for pad 2*/
    (uint16)11, 
    /* Index to address the input settings for pad 3*/
    (uint16)17, 
    /* Index to address the input settings for pad 4*/
    (uint16)23, 
    /* Index to address the input settings for pad 5*/
    (uint16)26, 
    /* Index to address the input settings for pad 6*/
    (uint16)27, 
    /* Index to address the input settings for pad 7*/
    (uint16)36, 
    /* Index to address the input settings for pad 8*/
    (uint16)42, 
    /* Index to address the input settings for pad 9*/
    (uint16)47, 
    /* Index to address the input settings for pad 10*/
    (uint16)52, 
    /* Index to address the input settings for pad 11*/
    (uint16)55, 
    /* Index to address the input settings for pad 12*/
    (uint16)60, 
    /* Index to address the input settings for pad 13*/
    (uint16)66, 
    /* Index to address the input settings for pad 14*/
    (uint16)71, 
    /* Index to address the input settings for pad 15*/
    (uint16)75, 
    /* Index to address the input settings for pad 16*/
    (uint16)80, 
    /* Index to address the input settings for pad 17*/
    (uint16)0, 
    /* Index to address the input settings for pad 18*/
    (uint16)0, 
    /* Index to address the input settings for pad 19*/
    (uint16)0, 
    /* Index to address the input settings for pad 20*/
    (uint16)0, 
    /* Index to address the input settings for pad 21*/
    (uint16)0, 
    /* Index to address the input settings for pad 22*/
    (uint16)0, 
    /* Index to address the input settings for pad 23*/
    (uint16)0, 
    /* Index to address the input settings for pad 24*/
    (uint16)0, 
    /* Index to address the input settings for pad 25*/
    (uint16)0, 
    /* Index to address the input settings for pad 26*/
    (uint16)0, 
    /* Index to address the input settings for pad 27*/
    (uint16)0, 
    /* Index to address the input settings for pad 28*/
    (uint16)0, 
    /* Index to address the input settings for pad 29*/
    (uint16)0, 
    /* Index to address the input settings for pad 30*/
    (uint16)0, 
    /* Index to address the input settings for pad 31*/
    (uint16)0, 
    /* Index to address the input settings for pad 32*/
    (uint16)86, 
    /* Index to address the input settings for pad 33*/
    (uint16)94, 
    /* Index to address the input settings for pad 34*/
    (uint16)101, 
    /* Index to address the input settings for pad 35*/
    (uint16)107, 
    /* Index to address the input settings for pad 36*/
    (uint16)113, 
    /* Index to address the input settings for pad 37*/
    (uint16)119, 
    /* Index to address the input settings for pad 38*/
    (uint16)0, 
    /* Index to address the input settings for pad 39*/
    (uint16)0, 
    /* Index to address the input settings for pad 40*/
    (uint16)125, 
    /* Index to address the input settings for pad 41*/
    (uint16)130, 
    /* Index to address the input settings for pad 42*/
    (uint16)134, 
    /* Index to address the input settings for pad 43*/
    (uint16)137, 
    /* Index to address the input settings for pad 44*/
    (uint16)142, 
    /* Index to address the input settings for pad 45*/
    (uint16)147, 
    /* Index to address the input settings for pad 46*/
    (uint16)153, 
    /* Index to address the input settings for pad 47*/
    (uint16)157, 
    /* Index to address the input settings for pad 48*/
    (uint16)161, 
    /* Index to address the input settings for pad 49*/
    (uint16)165, 
    /* Index to address the input settings for pad 50*/
    (uint16)0, 
    /* Index to address the input settings for pad 51*/
    (uint16)0, 
    /* Index to address the input settings for pad 52*/
    (uint16)0, 
    /* Index to address the input settings for pad 53*/
    (uint16)0, 
    /* Index to address the input settings for pad 54*/
    (uint16)0, 
    /* Index to address the input settings for pad 55*/
    (uint16)0, 
    /* Index to address the input settings for pad 56*/
    (uint16)0, 
    /* Index to address the input settings for pad 57*/
    (uint16)0, 
    /* Index to address the input settings for pad 58*/
    (uint16)0, 
    /* Index to address the input settings for pad 59*/
    (uint16)0, 
    /* Index to address the input settings for pad 60*/
    (uint16)0, 
    /* Index to address the input settings for pad 61*/
    (uint16)0, 
    /* Index to address the input settings for pad 62*/
    (uint16)0, 
    /* Index to address the input settings for pad 63*/
    (uint16)0, 
    /* Index to address the input settings for pad 64*/
    (uint16)171, 
    /* Index to address the input settings for pad 65*/
    (uint16)177, 
    /* Index to address the input settings for pad 66*/
    (uint16)185, 
    /* Index to address the input settings for pad 67*/
    (uint16)192, 
    /* Index to address the input settings for pad 68*/
    (uint16)195, 
    /* Index to address the input settings for pad 69*/
    (uint16)199, 
    /* Index to address the input settings for pad 70*/
    (uint16)204, 
    /* Index to address the input settings for pad 71*/
    (uint16)212, 
    /* Index to address the input settings for pad 72*/
    (uint16)219, 
    /* Index to address the input settings for pad 73*/
    (uint16)226, 
    /* Index to address the input settings for pad 74*/
    (uint16)233, 
    /* Index to address the input settings for pad 75*/
    (uint16)239, 
    /* Index to address the input settings for pad 76*/
    (uint16)244, 
    /* Index to address the input settings for pad 77*/
    (uint16)250, 
    /* Index to address the input settings for pad 78*/
    (uint16)255, 
    /* Index to address the input settings for pad 79*/
    (uint16)265, 
    /* Index to address the input settings for pad 80*/
    (uint16)274, 
    /* Index to address the input settings for pad 81*/
    (uint16)283, 
    /* Index to address the input settings for pad 82*/
    (uint16)0, 
    /* Index to address the input settings for pad 83*/
    (uint16)0, 
    /* Index to address the input settings for pad 84*/
    (uint16)0, 
    /* Index to address the input settings for pad 85*/
    (uint16)0, 
    /* Index to address the input settings for pad 86*/
    (uint16)0, 
    /* Index to address the input settings for pad 87*/
    (uint16)0, 
    /* Index to address the input settings for pad 88*/
    (uint16)0, 
    /* Index to address the input settings for pad 89*/
    (uint16)0, 
    /* Index to address the input settings for pad 90*/
    (uint16)0, 
    /* Index to address the input settings for pad 91*/
    (uint16)0, 
    /* Index to address the input settings for pad 92*/
    (uint16)0, 
    /* Index to address the input settings for pad 93*/
    (uint16)0, 
    /* Index to address the input settings for pad 94*/
    (uint16)0, 
    /* Index to address the input settings for pad 95*/
    (uint16)0, 
    /* Index to address the input settings for pad 96*/
    (uint16)288, 
    /* Index to address the input settings for pad 97*/
    (uint16)293, 
    /* Index to address the input settings for pad 98*/
    (uint16)298, 
    /* Index to address the input settings for pad 99*/
    (uint16)305, 
    /* Index to address the input settings for pad 100*/
    (uint16)312, 
    /* Index to address the input settings for pad 101*/
    (uint16)315, 
    /* Index to address the input settings for pad 102*/
    (uint16)323, 
    /* Index to address the input settings for pad 103*/
    (uint16)330, 
    /* Index to address the input settings for pad 104*/
    (uint16)335, 
    /* Index to address the input settings for pad 105*/
    (uint16)344, 
    /* Index to address the input settings for pad 106*/
    (uint16)352, 
    /* Index to address the input settings for pad 107*/
    (uint16)358, 
    /* Index to address the input settings for pad 108*/
    (uint16)364, 
    /* Index to address the input settings for pad 109*/
    (uint16)0, 
    /* Index to address the input settings for pad 110*/
    (uint16)0, 
    /* Index to address the input settings for pad 111*/
    (uint16)370, 
    /* Index to address the input settings for pad 112*/
    (uint16)380, 
    /* Index to address the input settings for pad 113*/
    (uint16)384, 
    /* Index to address the input settings for pad 114*/
    (uint16)0, 
    /* Index to address the input settings for pad 115*/
    (uint16)0, 
    /* Index to address the input settings for pad 116*/
    (uint16)0, 
    /* Index to address the input settings for pad 117*/
    (uint16)0, 
    /* Index to address the input settings for pad 118*/
    (uint16)0, 
    /* Index to address the input settings for pad 119*/
    (uint16)0, 
    /* Index to address the input settings for pad 120*/
    (uint16)0, 
    /* Index to address the input settings for pad 121*/
    (uint16)0, 
    /* Index to address the input settings for pad 122*/
    (uint16)0, 
    /* Index to address the input settings for pad 123*/
    (uint16)0, 
    /* Index to address the input settings for pad 124*/
    (uint16)0, 
    /* Index to address the input settings for pad 125*/
    (uint16)0, 
    /* Index to address the input settings for pad 126*/
    (uint16)0, 
    /* Index to address the input settings for pad 127*/
    (uint16)0, 
    /* Index to address the input settings for pad 128*/
    (uint16)390, 
    /* Index to address the input settings for pad 129*/
    (uint16)393, 
    /* Index to address the input settings for pad 130*/
    (uint16)396, 
    /* Index to address the input settings for pad 131*/
    (uint16)402, 
    /* Index to address the input settings for pad 132*/
    (uint16)0, 
    /* Index to address the input settings for pad 133*/
    (uint16)0, 
    /* Index to address the input settings for pad 134*/
    (uint16)408, 
    /* Index to address the input settings for pad 135*/
    (uint16)0, 
    /* Index to address the input settings for pad 136*/
    (uint16)412, 
    /* Index to address the input settings for pad 137*/
    (uint16)418, 
    /* Index to address the input settings for pad 138*/
    (uint16)424, 
    /* Index to address the input settings for pad 139*/
    (uint16)429, 
    /* Index to address the input settings for pad 140*/
    (uint16)434, 
    /* Index to address the input settings for pad 141*/
    (uint16)441, 
    /* Index to address the input settings for pad 142*/
    (uint16)0, 
    /* Index to address the input settings for pad 143*/
    (uint16)446, 
    /* Index to address the input settings for pad 144*/
    (uint16)453
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on SIUL2 instance
*/
static const Port_PinModeAvailabilityArrayType Port_SIUL2_0_au16PinModeAvailability =
{
    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GPIO |
        SIUL2_0_PORT1_GPIO |
        SIUL2_0_PORT2_GPIO |
        SIUL2_0_PORT3_GPIO |
        SIUL2_0_PORT4_GPIO |
        SIUL2_0_PORT5_GPIO |
        SIUL2_0_PORT6_GPIO |
        SIUL2_0_PORT7_GPIO |
        SIUL2_0_PORT8_GPIO |
        SIUL2_0_PORT9_GPIO |
        SIUL2_0_PORT10_GPIO |
        SIUL2_0_PORT11_GPIO |
        SIUL2_0_PORT12_GPIO |
        SIUL2_0_PORT13_GPIO |
        SIUL2_0_PORT14_GPIO |
        SIUL2_0_PORT15_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GPIO */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_GPIO |
        SIUL2_0_PORT33_GPIO |
        SIUL2_0_PORT34_GPIO |
        SIUL2_0_PORT35_GPIO |
        SIUL2_0_PORT36_GPIO |
        SIUL2_0_PORT37_GPIO |
        SIUL2_0_PORT40_GPIO |
        SIUL2_0_PORT41_GPIO |
        SIUL2_0_PORT42_GPIO |
        SIUL2_0_PORT43_GPIO |
        SIUL2_0_PORT44_GPIO |
        SIUL2_0_PORT45_GPIO |
        SIUL2_0_PORT46_GPIO |
        SIUL2_0_PORT47_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_GPIO |
        SIUL2_0_PORT49_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GPIO |
        SIUL2_0_PORT65_GPIO |
        SIUL2_0_PORT66_GPIO |
        SIUL2_0_PORT67_GPIO |
        SIUL2_0_PORT68_GPIO |
        SIUL2_0_PORT69_GPIO |
        SIUL2_0_PORT70_GPIO |
        SIUL2_0_PORT71_GPIO |
        SIUL2_0_PORT72_GPIO |
        SIUL2_0_PORT73_GPIO |
        SIUL2_0_PORT74_GPIO |
        SIUL2_0_PORT75_GPIO |
        SIUL2_0_PORT76_GPIO |
        SIUL2_0_PORT77_GPIO |
        SIUL2_0_PORT78_GPIO |
        SIUL2_0_PORT79_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GPIO |
        SIUL2_0_PORT81_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_GPIO |
        SIUL2_0_PORT97_GPIO |
        SIUL2_0_PORT98_GPIO |
        SIUL2_0_PORT99_GPIO |
        SIUL2_0_PORT100_GPIO |
        SIUL2_0_PORT101_GPIO |
        SIUL2_0_PORT102_GPIO |
        SIUL2_0_PORT103_GPIO |
        SIUL2_0_PORT104_GPIO |
        SIUL2_0_PORT105_GPIO |
        SIUL2_0_PORT106_GPIO |
        SIUL2_0_PORT107_GPIO |
        SIUL2_0_PORT108_GPIO |
        SIUL2_0_PORT111_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_GPIO |
        SIUL2_0_PORT113_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_GPIO |
        SIUL2_0_PORT129_GPIO |
        SIUL2_0_PORT130_GPIO |
        SIUL2_0_PORT131_GPIO |
        SIUL2_0_PORT134_GPIO |
        SIUL2_0_PORT136_GPIO |
        SIUL2_0_PORT137_GPIO |
        SIUL2_0_PORT138_GPIO |
        SIUL2_0_PORT139_GPIO |
        SIUL2_0_PORT140_GPIO |
        SIUL2_0_PORT141_GPIO |
        SIUL2_0_PORT143_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_GPIO */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT1_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT2_FCCU_FCCU_ERR0 |
        SIUL2_0_PORT3_FCCU_FCCU_ERR1 |
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_OUT |
        SIUL2_0_PORT11_CAN1_CAN1_TX |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_OUT |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_OUT |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_OUT |
        SIUL2_0_PORT34_ADC1_ADC1_MA_0 |
        SIUL2_0_PORT36_EMAC_EMAC_MII_RMII_TXD_1 |
        SIUL2_0_PORT37_EMAC_EMAC_MII_RMII_TXD_0 |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_OUT |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT64_CAN3_CAN3_TX |
        SIUL2_0_PORT66_EMAC_EMAC_MII_RMII_TXD_1 |
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT71_FXIO_FXIO_D10_OUT |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_OUT |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_OUT |
        SIUL2_0_PORT74_eMIOS_0_eMIOS_0_CH_6_G_OUT |
        SIUL2_0_PORT76_ADC1_ADC1_MA_2 |
        SIUL2_0_PORT79_CAN2_CAN2_TX */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_OUT |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_LCU0_LCU0_OUT1 |
        SIUL2_0_PORT101_EMAC_EMAC_MII_TXD2 |
        SIUL2_0_PORT102_EMAC_EMAC_MII_TXD3 |
        SIUL2_0_PORT103_EMAC_EMAC_MII_RMII_TXD_0 |
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_OUT |
        SIUL2_0_PORT106_EMAC_EMAC_MII_TXD3 |
        SIUL2_0_PORT107_EMAC_EMAC_MII_TXD2 |
        SIUL2_0_PORT111_FXIO_FXIO_D6_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT140_CMP0_CMP0_RRT |
        SIUL2_0_PORT143_FCCU_FCCU_ERR0 */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FCCU_FCCU_ERR1 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_0_eMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT1_eMIOS_0_eMIOS_0_CH_9_H_OUT |
        SIUL2_0_PORT2_eMIOS_1_eMIOS_1_CH_19_Y_OUT |
        SIUL2_0_PORT3_eMIOS_1_eMIOS_1_CH_20_Y_OUT |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT8_eMIOS_1_eMIOS_1_CH_12_H_OUT |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT10_eMIOS_0_eMIOS_0_CH_12_H_OUT |
        SIUL2_0_PORT11_eMIOS_0_eMIOS_0_CH_13_H_OUT |
        SIUL2_0_PORT12_eMIOS_0_eMIOS_0_CH_14_H_OUT |
        SIUL2_0_PORT13_eMIOS_0_eMIOS_0_CH_15_H_OUT |
        SIUL2_0_PORT14_eMIOS_1_eMIOS_1_CH_4_H_OUT |
        SIUL2_0_PORT15_eMIOS_0_eMIOS_0_CH_10_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_eMIOS_0_eMIOS_0_CH_11_H_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_OUT |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT34_eMIOS_0_eMIOS_0_CH_8_X_OUT |
        SIUL2_0_PORT35_eMIOS_0_eMIOS_0_CH_9_H_OUT |
        SIUL2_0_PORT36_eMIOS_0_eMIOS_0_CH_4_G_OUT |
        SIUL2_0_PORT37_eMIOS_0_eMIOS_0_CH_5_G_OUT |
        SIUL2_0_PORT40_eMIOS_1_eMIOS_1_CH_15_H_OUT |
        SIUL2_0_PORT41_eMIOS_1_eMIOS_1_CH_16_X_OUT |
        SIUL2_0_PORT42_eMIOS_1_eMIOS_1_CH_17_Y_OUT |
        SIUL2_0_PORT43_eMIOS_1_eMIOS_1_CH_18_Y_OUT |
        SIUL2_0_PORT44_eMIOS_0_eMIOS_0_CH_0_X_OUT |
        SIUL2_0_PORT45_eMIOS_0_eMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT46_eMIOS_0_eMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT47_eMIOS_0_eMIOS_0_CH_3_G_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_eMIOS_0_eMIOS_0_CH_4_G_OUT |
        SIUL2_0_PORT49_eMIOS_0_eMIOS_0_CH_5_G_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_0_X_OUT |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT66_eMIOS_0_eMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT67_eMIOS_0_eMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT68_eMIOS_0_eMIOS_0_CH_8_X_OUT |
        SIUL2_0_PORT69_eMIOS_0_eMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT70_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_OUT |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_OUT |
        SIUL2_0_PORT75_LPUART0_LPUART0_DTR_B |
        SIUL2_0_PORT76_eMIOS_1_eMIOS_1_CH_2_H_OUT |
        SIUL2_0_PORT77_eMIOS_1_eMIOS_1_CH_3_H_OUT |
        SIUL2_0_PORT78_eMIOS_0_eMIOS_0_CH_10_H_OUT |
        SIUL2_0_PORT79_eMIOS_0_eMIOS_0_CH_11_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_eMIOS_1_eMIOS_1_CH_9_H_OUT |
        SIUL2_0_PORT81_I3C0_I3C0_PUR */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT98_eMIOS_1_eMIOS_1_CH_21_Y_OUT |
        SIUL2_0_PORT99_eMIOS_1_eMIOS_1_CH_22_X_OUT |
        SIUL2_0_PORT100_eMIOS_1_eMIOS_1_CH_23_X_OUT |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_19_Y_OUT |
        SIUL2_0_PORT102_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_OUT |
        SIUL2_0_PORT106_eMIOS_0_eMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT107_eMIOS_0_eMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT108_eMIOS_0_eMIOS_0_CH_18_Y_OUT |
        SIUL2_0_PORT111_eMIOS_0_eMIOS_0_CH_0_X_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_0_eMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT113_eMIOS_0_eMIOS_0_CH_18_Y_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_OUT |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT131_SAI1_SAI1_D0_OUT |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_OUT |
        SIUL2_0_PORT136_eMIOS_0_eMIOS_0_CH_6_G_OUT |
        SIUL2_0_PORT137_eMIOS_0_eMIOS_0_CH_7_G_OUT |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_OUT |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT141_eMIOS_1_eMIOS_1_CH_5_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LCU0_LCU0_OUT4 |
        SIUL2_0_PORT1_LPUART0_LPUART0_RTS |
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_OUT |
        SIUL2_0_PORT4_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT7_eMIOS_1_eMIOS_1_CH_11_H_OUT |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_OUT |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT11_eMIOS_1_eMIOS_1_CH_1_H_OUT |
        SIUL2_0_PORT12_SYSTEM_CLKOUT_STANDBY |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_OUT |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_OUT |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_OUT |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT42_LPUART0_LPUART0_DTR_B |
        SIUL2_0_PORT45_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_OUT |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_OUT |
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_OUT |
        SIUL2_0_PORT67_CAN0_CAN0_TX |
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_OUT |
        SIUL2_0_PORT72_CAN1_CAN1_TX |
        SIUL2_0_PORT73_LPUART0_LPUART0_RTS |
        SIUL2_0_PORT75_eMIOS_1_eMIOS_1_CH_1_H_OUT |
        SIUL2_0_PORT76_eMIOS_0_eMIOS_0_CH_22_X_OUT |
        SIUL2_0_PORT77_eMIOS_0_eMIOS_0_CH_23_X_OUT |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_CAN2_CAN2_TX */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_OUT |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_OUT |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_OUT |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_OUT |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT102_eMIOS_1_eMIOS_1_CH_12_H_OUT |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_OUT |
        SIUL2_0_PORT105_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT106_eMIOS_1_eMIOS_1_CH_10_H_OUT |
        SIUL2_0_PORT107_EMAC_EMAC_MII_RMII_TX_EN |
        SIUL2_0_PORT108_LPUART2_LPUART2_RTS |
        SIUL2_0_PORT111_eMIOS_1_eMIOS_1_CH_14_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMAC_EMAC_MII_RMII_MDIO_OUT |
        SIUL2_0_PORT113_EMAC_EMAC_MII_RMII_MDC */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT129_FXIO_FXIO_D2_OUT |
        SIUL2_0_PORT130_eMIOS_0_eMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT131_eMIOS_0_eMIOS_0_CH_19_Y_OUT |
        SIUL2_0_PORT134_LPUART1_LPUART1_RTS |
        SIUL2_0_PORT137_eMIOS_1_eMIOS_1_CH_13_H_OUT |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_OUT |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_OUT |
        SIUL2_0_PORT1_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT3_LCU0_LCU0_OUT2 |
        SIUL2_0_PORT4_CMP0_CMP0_OUT |
        SIUL2_0_PORT6_eMIOS_1_eMIOS_1_CH_13_H_OUT |
        SIUL2_0_PORT7_CAN0_CAN0_TX |
        SIUL2_0_PORT8_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT9_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT10_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT11_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_0_eMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT33_eMIOS_0_eMIOS_0_CH_7_G_OUT |
        SIUL2_0_PORT35_ADC0_ADC0_MA_0 |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT46_LCU0_LCU0_OUT7 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_eMIOS_1_eMIOS_1_CH_7_H_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_OUT |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT68_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT69_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT70_LCU0_LCU0_OUT7 |
        SIUL2_0_PORT71_LCU0_LCU0_OUT6 |
        SIUL2_0_PORT72_eMIOS_1_eMIOS_1_CH_9_H_OUT |
        SIUL2_0_PORT73_eMIOS_1_eMIOS_1_CH_8_X_OUT |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT75_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT77_ADC1_ADC1_MA_1 |
        SIUL2_0_PORT78_ADC0_ADC0_MA_1 |
        SIUL2_0_PORT79_ADC0_ADC0_MA_2 */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_OUT |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT98_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT99_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT101_I3C0_I3C0_SDA_OUT |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_OUT |
        SIUL2_0_PORT104_I3C0_I3C0_SDA_OUT |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_eMIOS_1_eMIOS_1_CH_8_X_OUT |
        SIUL2_0_PORT131_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT134_eMIOS_1_eMIOS_1_CH_14_H_OUT |
        SIUL2_0_PORT136_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT137_CAN3_CAN3_TX |
        SIUL2_0_PORT138_eMIOS_0_eMIOS_0_CH_20_Y_OUT |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_21_Y_OUT |
        SIUL2_0_PORT140_eMIOS_1_eMIOS_1_CH_5_H_OUT |
        SIUL2_0_PORT143_eMIOS_0_eMIOS_0_CH_22_X_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_eMIOS_0_eMIOS_0_CH_23_X_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_1_eMIOS_1_CH_0_X_OUT |
        SIUL2_0_PORT1_LCU0_LCU0_OUT5 |
        SIUL2_0_PORT2_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT3_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT6_FXIO_FXIO_D19_OUT |
        SIUL2_0_PORT7_LPUART1_LPUART1_RTS |
        SIUL2_0_PORT11_CMP0_CMP0_RRT |
        SIUL2_0_PORT12_FXIO_FXIO_D9_OUT |
        SIUL2_0_PORT13_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT15_LPUART1_LPUART1_DTR_B */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LCU1_LCU1_OUT5 |
        SIUL2_0_PORT33_CAN0_CAN0_TX |
        SIUL2_0_PORT34_LCU1_LCU1_OUT3 |
        SIUL2_0_PORT36_EMAC_EMAC_MII_RMII_MDIO_OUT |
        SIUL2_0_PORT37_SYSTEM_CLKOUT_RUN |
        SIUL2_0_PORT40_LCU0_LCU0_OUT11 |
        SIUL2_0_PORT43_LCU0_LCU0_OUT8 |
        SIUL2_0_PORT45_LCU0_LCU0_OUT3 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT66_EMAC_EMAC_MII_RMII_TXD_0 |
        SIUL2_0_PORT67_I3C0_I3C0_PUR |
        SIUL2_0_PORT70_eMIOS_1_eMIOS_1_CH_6_H_OUT |
        SIUL2_0_PORT71_eMIOS_1_eMIOS_1_CH_7_H_OUT |
        SIUL2_0_PORT72_LCU1_LCU1_OUT7 |
        SIUL2_0_PORT73_LCU1_LCU1_OUT6 |
        SIUL2_0_PORT76_FXIO_FXIO_D19_OUT |
        SIUL2_0_PORT77_FXIO_FXIO_D16_OUT |
        SIUL2_0_PORT78_eMIOS_1_eMIOS_1_CH_4_H_OUT |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_I3C0_I3C0_SCL_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT99_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT100_LCU0_LCU0_OUT6 |
        SIUL2_0_PORT101_EMAC_EMAC_MII_TXD3 |
        SIUL2_0_PORT102_EMAC_EMAC_MII_TXD2 |
        SIUL2_0_PORT103_EMAC_EMAC_MII_RMII_TXD_1 |
        SIUL2_0_PORT104_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT105_I3C0_I3C0_SCL_OUT |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_OUT |
        SIUL2_0_PORT108_EMAC_EMAC_MII_RMII_TX_EN |
        SIUL2_0_PORT111_EMAC_EMAC_PPS2_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_1_eMIOS_1_CH_15_H_OUT |
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT131_LPUART2_LPUART2_RTS |
        SIUL2_0_PORT136_EMAC_EMAC_MII_RMII_MDC |
        SIUL2_0_PORT137_EMAC_EMAC_PPS3_OUT |
        SIUL2_0_PORT138_SYSTEM_CLKOUT_STANDBY |
        SIUL2_0_PORT140_EMAC_EMAC_PPS3_OUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT143_CMP1_CMP1_RRT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART1_LPUART1_RTS */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_OUT |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_OUT |
        SIUL2_0_PORT2_LCU0_LCU0_OUT3 |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT7_FXIO_FXIO_D9_OUT |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_OUT |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_OUT |
        SIUL2_0_PORT12_eMIOS_1_eMIOS_1_CH_2_H_OUT |
        SIUL2_0_PORT13_eMIOS_1_eMIOS_1_CH_3_H_OUT |
        SIUL2_0_PORT14_FXIO_FXIO_D14_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_1_eMIOS_1_CH_6_H_OUT |
        SIUL2_0_PORT33_eMIOS_1_eMIOS_1_CH_5_H_OUT |
        SIUL2_0_PORT34_SAI0_SAI0_D0_OUT |
        SIUL2_0_PORT35_LCU1_LCU1_OUT2 |
        SIUL2_0_PORT36_eMIOS_1_eMIOS_1_CH_10_H_OUT |
        SIUL2_0_PORT37_eMIOS_1_eMIOS_1_CH_11_H_OUT |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_OUT |
        SIUL2_0_PORT41_LCU0_LCU0_OUT10 |
        SIUL2_0_PORT42_LCU0_LCU0_OUT9 |
        SIUL2_0_PORT44_LCU0_LCU0_OUT2 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_14_H_OUT |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_15_H_OUT |
        SIUL2_0_PORT67_QuadSPI_QuadSPI_PCSFA |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_OUT |
        SIUL2_0_PORT74_LCU1_LCU1_OUT11 |
        SIUL2_0_PORT75_FXIO_FXIO_D19_OUT |
        SIUL2_0_PORT76_LCU1_LCU1_OUT9 |
        SIUL2_0_PORT77_LCU1_LCU1_OUT8 |
        SIUL2_0_PORT78_LCU1_LCU1_OUT1 |
        SIUL2_0_PORT79_LCU1_LCU1_OUT0 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT81_FXIO_FXIO_D14_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT97_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_OUT |
        SIUL2_0_PORT99_LCU0_LCU0_OUT0 |
        SIUL2_0_PORT101_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT102_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT104_eMIOS_0_eMIOS_0_CH_12_H_OUT |
        SIUL2_0_PORT105_eMIOS_0_eMIOS_0_CH_13_H_OUT |
        SIUL2_0_PORT106_SYSTEM_CLKOUT_RUN |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT111_SAI1_SAI1_SYNC_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPUART2_LPUART2_RTS |
        SIUL2_0_PORT113_FXIO_FXIO_D9_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT131_EMAC_EMAC_PPS0_OUT |
        SIUL2_0_PORT134_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT136_SAI1_SAI1_BCLK_OUT |
        SIUL2_0_PORT137_EMAC_EMAC_MII_RMII_TX_EN |
        SIUL2_0_PORT138_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT139_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT140_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT141_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT143_FXIO_FXIO_D2_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT7_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_TRGMUX_TRGMUX_OUT3 |
        SIUL2_0_PORT1_TRGMUX_TRGMUX_OUT0 |
        SIUL2_0_PORT4_JTAG_JTAG_TMSSWD_DIO_OUT |
        SIUL2_0_PORT5_SYSTEM_RESET_b_IN |
        SIUL2_0_PORT5_SYSTEM_RESET_b_OUT |
        SIUL2_0_PORT10_JTAG_TRACEnoETM_JTAG_TDOTRACEnoETM_SWO |
        SIUL2_0_PORT12_CMP1_CMP1_OUT |
        SIUL2_0_PORT15_FXIO_FXIO_D31_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FXIO_FXIO_D30_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_HSE_HSE_TAMPER_LOOP_OUT0 |
        SIUL2_0_PORT33_LCU1_LCU1_OUT4 |
        SIUL2_0_PORT34_FXIO_FXIO_D18_OUT |
        SIUL2_0_PORT35_FXIO_FXIO_D17_OUT |
        SIUL2_0_PORT37_EMAC_EMAC_MII_RMII_MDC |
        SIUL2_0_PORT40_FXIO_FXIO_D29_OUT |
        SIUL2_0_PORT41_FXIO_FXIO_D28_OUT |
        SIUL2_0_PORT42_FXIO_FXIO_D27_OUT |
        SIUL2_0_PORT43_FXIO_FXIO_D26_OUT |
        SIUL2_0_PORT44_FXIO_FXIO_D25_OUT |
        SIUL2_0_PORT45_FXIO_FXIO_D24_OUT |
        SIUL2_0_PORT46_FXIO_FXIO_D23_OUT |
        SIUL2_0_PORT47_FXIO_FXIO_D22_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_FXIO_FXIO_D21_OUT |
        SIUL2_0_PORT49_FXIO_FXIO_D20_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_QuadSPI_QuadSPI_IOFA3_OUT |
        SIUL2_0_PORT70_ADC0_ADC0_MA_2 |
        SIUL2_0_PORT71_CAN2_CAN2_TX |
        SIUL2_0_PORT72_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT73_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT74_eMIOS_1_eMIOS_1_CH_0_X_OUT |
        SIUL2_0_PORT75_LCU1_LCU1_OUT10 |
        SIUL2_0_PORT76_SAI0_SAI0_BCLK_OUT |
        SIUL2_0_PORT77_SAI0_SAI0_SYNC_OUT |
        SIUL2_0_PORT78_FXIO_FXIO_D16_OUT |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT81_FXIO_FXIO_D2_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_TRGMUX_TRGMUX_OUT1 |
        SIUL2_0_PORT97_TRGMUX_TRGMUX_OUT2 |
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT103_QuadSPI_QuadSPI_IOFA1_OUT |
        SIUL2_0_PORT104_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT105_FXIO_FXIO_D10_OUT |
        SIUL2_0_PORT106_QuadSPI_QuadSPI_SCKFA_OUT |
        SIUL2_0_PORT107_QuadSPI_QuadSPI_IOFA0_OUT |
        SIUL2_0_PORT108_QuadSPI_QuadSPI_IOFA2_OUT |
        SIUL2_0_PORT111_FXIO_FXIO_D10_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_EMAC_EMAC_PPS2_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_ADC0_ADC0_MA_0 |
        SIUL2_0_PORT131_CMP0_CMP0_OUT |
        SIUL2_0_PORT134_ADC0_ADC0_MA_1 |
        SIUL2_0_PORT136_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT137_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT138_TRGMUX_TRGMUX_OUT4 |
        SIUL2_0_PORT139_TRGMUX_TRGMUX_OUT5 |
        SIUL2_0_PORT140_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT143_TRGMUX_TRGMUX_OUT6 */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_TRGMUX_TRGMUX_OUT7 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT8_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT9_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT10_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT11_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT12_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT13_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT14_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT15_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ANALOG_INPUT_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_ADC0_ADC0_S8 |
        SIUL2_0_PORT1_ADC0_ADC0_S9 |
        SIUL2_0_PORT2_ADC1_ADC1_X_0 |
        SIUL2_0_PORT3_ADC1_ADC1_S17 |
        SIUL2_0_PORT4_ADC1_ADC1_S15 |
        SIUL2_0_PORT6_ADC0_ADC0_S18 |
        SIUL2_0_PORT7_ADC0_ADC0_S11 |
        SIUL2_0_PORT8_ADC0_ADC0_P2 |
        SIUL2_0_PORT9_ADC0_ADC0_P7 |
        SIUL2_0_PORT11_ADC1_ADC1_S10 |
        SIUL2_0_PORT12_ADC1_ADC1_P0 |
        SIUL2_0_PORT13_ADC1_ADC1_P1 |
        SIUL2_0_PORT14_ADC1_ADC1_P4 |
        SIUL2_0_PORT15_ADC1_ADC1_P7 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_ADC1_ADC1_S13 */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_ADC1_ADC1_S14 |
        SIUL2_0_PORT32_ADC0_ADC0_S14 |
        SIUL2_0_PORT33_ADC1_ADC1_S15 |
        SIUL2_0_PORT33_ADC0_ADC0_S15 |
        SIUL2_0_PORT40_ADC0_ADC0_X_0 |
        SIUL2_0_PORT41_ADC0_ADC0_X_1 |
        SIUL2_0_PORT42_ADC0_ADC0_X_2 |
        SIUL2_0_PORT43_ADC0_ADC0_X_3 |
        SIUL2_0_PORT44_ADC1_ADC1_X_1 |
        SIUL2_0_PORT45_ADC0_ADC0_S8 |
        SIUL2_0_PORT45_ADC1_ADC1_S8 |
        SIUL2_0_PORT46_ADC0_ADC0_S9 |
        SIUL2_0_PORT46_ADC1_ADC1_S9 |
        SIUL2_0_PORT47_ADC1_ADC1_S11 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_ADC1_ADC1_S12 |
        SIUL2_0_PORT49_ADC1_ADC1_X_2 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT69_ADC1_ADC1_S14 |
        SIUL2_0_PORT70_ADC1_ADC1_S18 |
        SIUL2_0_PORT71_ADC1_ADC1_S16 |
        SIUL2_0_PORT72_ADC0_ADC0_S12 |
        SIUL2_0_PORT73_ADC0_ADC0_S13 |
        SIUL2_0_PORT74_ADC1_ADC1_X_3 |
        SIUL2_0_PORT75_ADC0_ADC0_S17 */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT96_ADC0_ADC0_P1 |
        SIUL2_0_PORT97_ADC0_ADC0_P0 |
        SIUL2_0_PORT98_ADC0_ADC0_S16 |
        SIUL2_0_PORT99_ADC0_ADC0_S10 |
        SIUL2_0_PORT100_ADC0_ADC0_S19 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT128_ADC1_ADC1_P2 |
        SIUL2_0_PORT129_ADC1_ADC1_P3 |
        SIUL2_0_PORT130_ADC1_ADC1_P5 |
        SIUL2_0_PORT134_ADC1_ADC1_P6 |
        SIUL2_0_PORT138_ADC0_ADC0_P5 |
        SIUL2_0_PORT139_ADC0_ADC0_P6 |
        SIUL2_0_PORT141_ADC1_ADC1_S19 |
        SIUL2_0_PORT143_ADC0_ADC0_P3 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_ADC0_ADC0_P4 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ONLY_OUTPUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT141_PG_VRC_CTRL */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ONLY_INPUT_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_CMP1_CMP1_IN0 |
        SIUL2_0_PORT1_CMP1_CMP1_IN1 |
        SIUL2_0_PORT1_WKPU_WKPU_5 |
        SIUL2_0_PORT2_WKPU_WKPU_0 |
        SIUL2_0_PORT2_CMP1_CMP1_IN2 |
        SIUL2_0_PORT6_WKPU_WKPU_15 |
        SIUL2_0_PORT8_WKPU_WKPU_23 |
        SIUL2_0_PORT9_WKPU_WKPU_21 |
        SIUL2_0_PORT13_WKPU_WKPU_4 |
        SIUL2_0_PORT15_WKPU_WKPU_20 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_WKPU_WKPU_31 */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_WKPU_WKPU_7 |
        SIUL2_0_PORT34_WKPU_WKPU_8 |
        SIUL2_0_PORT40_WKPU_WKPU_25 |
        SIUL2_0_PORT41_WKPU_WKPU_17 |
        SIUL2_0_PORT43_WKPU_WKPU_16 |
        SIUL2_0_PORT44_WKPU_WKPU_12 |
        SIUL2_0_PORT45_WKPU_WKPU_11 |
        SIUL2_0_PORT47_WKPU_WKPU_33 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_WKPU_WKPU_13 |
        SIUL2_0_PORT49_WKPU_WKPU_14 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_CMP0_CMP0_IN2 |
        SIUL2_0_PORT67_CMP0_CMP0_IN4 |
        SIUL2_0_PORT68_CMP1_CMP1_IN3 |
        SIUL2_0_PORT70_WKPU_WKPU_3 |
        SIUL2_0_PORT71_WKPU_WKPU_2 |
        SIUL2_0_PORT73_WKPU_WKPU_10 |
        SIUL2_0_PORT75_WKPU_WKPU_18 */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT96_WKPU_WKPU_6 |
        SIUL2_0_PORT98_WKPU_WKPU_9 |
        SIUL2_0_PORT99_SYSTEM_NMI_b |
        SIUL2_0_PORT99_WKPU_WKPU_1 |
        SIUL2_0_PORT100_WKPU_WKPU_22 |
        SIUL2_0_PORT102_CMP0_CMP0_IN7 |
        SIUL2_0_PORT103_CMP0_CMP0_IN6 |
        SIUL2_0_PORT111_CMP0_CMP0_IN1 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_CMP0_CMP0_IN5 */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_WKPU_WKPU_26 |
        SIUL2_0_PORT130_WKPU_WKPU_27 |
        SIUL2_0_PORT134_WKPU_WKPU_29 |
        SIUL2_0_PORT136_CMP0_CMP0_IN3 |
        SIUL2_0_PORT137_CMP0_CMP0_IN0 |
        SIUL2_0_PORT139_WKPU_WKPU_28 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_WKPU_WKPU_19 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_SIUL_EIRQ_0 |
        SIUL2_0_PORT1_SIUL_EIRQ_1 |
        SIUL2_0_PORT2_SIUL_EIRQ_2 |
        SIUL2_0_PORT3_SIUL_EIRQ_3 |
        SIUL2_0_PORT4_SIUL_EIRQ_4 |
        SIUL2_0_PORT5_SIUL_EIRQ_5 |
        SIUL2_0_PORT6_CAN0_CAN0_RX |
        SIUL2_0_PORT7_SIUL_EIRQ_7 |
        SIUL2_0_PORT8_SIUL_EIRQ_16 |
        SIUL2_0_PORT9_SIUL_EIRQ_17 |
        SIUL2_0_PORT10_SIUL_EIRQ_18 |
        SIUL2_0_PORT11_SIUL_EIRQ_19 |
        SIUL2_0_PORT12_CAN1_CAN1_RX |
        SIUL2_0_PORT13_SIUL_EIRQ_21 |
        SIUL2_0_PORT14_SIUL_EIRQ_22 |
        SIUL2_0_PORT15_SIUL_EIRQ_23 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_SIUL_EIRQ_4 */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_CAN0_CAN0_RX |
        SIUL2_0_PORT33_SIUL_EIRQ_9 |
        SIUL2_0_PORT34_SIUL_EIRQ_10 |
        SIUL2_0_PORT35_SIUL_EIRQ_11 |
        SIUL2_0_PORT36_SIUL_EIRQ_12 |
        SIUL2_0_PORT37_SIUL_EIRQ_13 |
        SIUL2_0_PORT40_SIUL_EIRQ_14 |
        SIUL2_0_PORT41_SIUL_EIRQ_15 |
        SIUL2_0_PORT42_SIUL_EIRQ_24 |
        SIUL2_0_PORT43_SIUL_EIRQ_25 |
        SIUL2_0_PORT44_SIUL_EIRQ_26 |
        SIUL2_0_PORT45_SIUL_EIRQ_27 |
        SIUL2_0_PORT46_SIUL_EIRQ_28 |
        SIUL2_0_PORT47_SIUL_EIRQ_29 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_SIUL_EIRQ_30 |
        SIUL2_0_PORT49_SIUL_EIRQ_31 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_SIUL_EIRQ_0 |
        SIUL2_0_PORT65_CAN3_CAN3_RX |
        SIUL2_0_PORT66_CAN0_CAN0_RX |
        SIUL2_0_PORT67_SIUL_EIRQ_3 |
        SIUL2_0_PORT68_SIUL_EIRQ_4 |
        SIUL2_0_PORT69_SIUL_EIRQ_5 |
        SIUL2_0_PORT70_CAN2_CAN2_RX |
        SIUL2_0_PORT71_SIUL_EIRQ_7 |
        SIUL2_0_PORT72_SIUL_EIRQ_16 |
        SIUL2_0_PORT73_CAN1_CAN1_RX |
        SIUL2_0_PORT74_SIUL_EIRQ_18 |
        SIUL2_0_PORT75_SIUL_EIRQ_19 |
        SIUL2_0_PORT76_SIUL_EIRQ_20 |
        SIUL2_0_PORT77_SIUL_EIRQ_21 |
        SIUL2_0_PORT78_CAN2_CAN2_RX |
        SIUL2_0_PORT79_SIUL_EIRQ_23 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_CAN2_CAN2_RX |
        SIUL2_0_PORT81_FXIO_FXIO_D2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_SIUL_EIRQ_8 |
        SIUL2_0_PORT97_SIUL_EIRQ_9 |
        SIUL2_0_PORT98_SIUL_EIRQ_10 |
        SIUL2_0_PORT99_SIUL_EIRQ_11 |
        SIUL2_0_PORT100_SIUL_EIRQ_12 |
        SIUL2_0_PORT101_SIUL_EIRQ_13 |
        SIUL2_0_PORT102_SIUL_EIRQ_14 |
        SIUL2_0_PORT103_SIUL_EIRQ_15 |
        SIUL2_0_PORT104_SIUL_EIRQ_24 |
        SIUL2_0_PORT105_SIUL_EIRQ_25 |
        SIUL2_0_PORT106_SIUL_EIRQ_26 |
        SIUL2_0_PORT107_SIUL_EIRQ_27 |
        SIUL2_0_PORT108_SIUL_EIRQ_28 |
        SIUL2_0_PORT111_CAN3_CAN3_RX */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_0_eMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT113_SIUL_EIRQ_24 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_SIUL_EIRQ_0 |
        SIUL2_0_PORT129_SIUL_EIRQ_1 |
        SIUL2_0_PORT130_SIUL_EIRQ_2 |
        SIUL2_0_PORT131_SIUL_EIRQ_3 |
        SIUL2_0_PORT134_SIUL_EIRQ_6 |
        SIUL2_0_PORT136_SIUL_EIRQ_7 |
        SIUL2_0_PORT137_SIUL_EIRQ_8 |
        SIUL2_0_PORT138_SIUL_EIRQ_9 |
        SIUL2_0_PORT139_SIUL_EIRQ_10 |
        SIUL2_0_PORT140_SIUL_EIRQ_11 |
        SIUL2_0_PORT141_SIUL_EIRQ_12 |
        SIUL2_0_PORT143_SIUL_EIRQ_14 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_SIUL_EIRQ_15 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_0_eMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT1_eMIOS_0_eMIOS_0_CH_9_H_IN |
        SIUL2_0_PORT2_eMIOS_1_eMIOS_1_CH_19_Y_IN |
        SIUL2_0_PORT3_eMIOS_1_eMIOS_1_CH_20_Y_IN |
        SIUL2_0_PORT4_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT6_SIUL_EIRQ_6 |
        SIUL2_0_PORT7_eMIOS_1_eMIOS_1_CH_11_H_IN |
        SIUL2_0_PORT8_eMIOS_1_eMIOS_1_CH_12_H_IN |
        SIUL2_0_PORT9_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT10_eMIOS_0_eMIOS_0_CH_12_H_IN |
        SIUL2_0_PORT11_eMIOS_0_eMIOS_0_CH_13_H_IN |
        SIUL2_0_PORT12_SIUL_EIRQ_20 |
        SIUL2_0_PORT13_eMIOS_0_eMIOS_0_CH_15_H_IN |
        SIUL2_0_PORT14_eMIOS_1_eMIOS_1_CH_4_H_IN |
        SIUL2_0_PORT15_eMIOS_0_eMIOS_0_CH_10_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_eMIOS_0_eMIOS_0_CH_11_H_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_SIUL_EIRQ_8 |
        SIUL2_0_PORT33_eMIOS_0_eMIOS_0_CH_7_G_IN |
        SIUL2_0_PORT34_eMIOS_0_eMIOS_0_CH_8_X_IN |
        SIUL2_0_PORT35_eMIOS_0_eMIOS_0_CH_9_H_IN |
        SIUL2_0_PORT36_eMIOS_0_eMIOS_0_CH_4_G_IN |
        SIUL2_0_PORT37_eMIOS_0_eMIOS_0_CH_5_G_IN |
        SIUL2_0_PORT40_eMIOS_1_eMIOS_1_CH_15_H_IN |
        SIUL2_0_PORT41_eMIOS_1_eMIOS_1_CH_16_X_IN |
        SIUL2_0_PORT42_eMIOS_1_eMIOS_1_CH_17_Y_IN |
        SIUL2_0_PORT43_eMIOS_1_eMIOS_1_CH_18_Y_IN |
        SIUL2_0_PORT44_eMIOS_0_eMIOS_0_CH_0_X_IN |
        SIUL2_0_PORT45_eMIOS_0_eMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT46_eMIOS_0_eMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT47_eMIOS_0_eMIOS_0_CH_3_G_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_eMIOS_0_eMIOS_0_CH_4_G_IN |
        SIUL2_0_PORT49_eMIOS_0_eMIOS_0_CH_5_G_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_0_X_IN |
        SIUL2_0_PORT65_SIUL_EIRQ_1 |
        SIUL2_0_PORT66_SIUL_EIRQ_2 |
        SIUL2_0_PORT67_eMIOS_0_eMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT68_eMIOS_0_eMIOS_0_CH_8_X_IN |
        SIUL2_0_PORT69_eMIOS_0_eMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT70_SIUL_EIRQ_6 |
        SIUL2_0_PORT71_eMIOS_1_eMIOS_1_CH_7_H_IN |
        SIUL2_0_PORT72_eMIOS_1_eMIOS_1_CH_9_H_IN |
        SIUL2_0_PORT73_SIUL_EIRQ_17 |
        SIUL2_0_PORT74_eMIOS_0_eMIOS_0_CH_6_G_IN |
        SIUL2_0_PORT75_eMIOS_1_eMIOS_1_CH_1_H_IN |
        SIUL2_0_PORT76_eMIOS_0_eMIOS_0_CH_22_X_IN |
        SIUL2_0_PORT77_eMIOS_0_eMIOS_0_CH_23_X_IN |
        SIUL2_0_PORT78_SIUL_EIRQ_22 |
        SIUL2_0_PORT79_eMIOS_0_eMIOS_0_CH_11_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_eMIOS_1_eMIOS_1_CH_9_H_IN |
        SIUL2_0_PORT81_FXIO_FXIO_D14_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT98_eMIOS_1_eMIOS_1_CH_21_Y_IN |
        SIUL2_0_PORT99_eMIOS_1_eMIOS_1_CH_22_X_IN |
        SIUL2_0_PORT100_eMIOS_1_eMIOS_1_CH_23_X_IN |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT102_eMIOS_1_eMIOS_1_CH_12_H_IN |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_IN |
        SIUL2_0_PORT104_eMIOS_0_eMIOS_0_CH_12_H_IN |
        SIUL2_0_PORT105_eMIOS_0_eMIOS_0_CH_13_H_IN |
        SIUL2_0_PORT106_eMIOS_0_eMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT107_eMIOS_0_eMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT108_eMIOS_0_eMIOS_0_CH_18_Y_IN |
        SIUL2_0_PORT111_SIUL_EIRQ_31 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_1_eMIOS_1_CH_15_H_IN |
        SIUL2_0_PORT113_eMIOS_0_eMIOS_0_CH_18_Y_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT129_FXIO_FXIO_D2_IN |
        SIUL2_0_PORT130_eMIOS_0_eMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT131_eMIOS_0_eMIOS_0_CH_19_Y_IN |
        SIUL2_0_PORT134_eMIOS_1_eMIOS_1_CH_14_H_IN |
        SIUL2_0_PORT136_eMIOS_0_eMIOS_0_CH_6_G_IN |
        SIUL2_0_PORT137_eMIOS_0_eMIOS_0_CH_7_G_IN |
        SIUL2_0_PORT138_eMIOS_0_eMIOS_0_CH_20_Y_IN |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT140_eMIOS_1_eMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT141_eMIOS_1_eMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT143_eMIOS_0_eMIOS_0_CH_22_X_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_eMIOS_0_eMIOS_0_CH_23_X_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_1_eMIOS_1_CH_0_X_IN |
        SIUL2_0_PORT1_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT2_FCCU_FCCU_ERR_IN0 |
        SIUL2_0_PORT3_FCCU_FCCU_ERR_IN1 |
        SIUL2_0_PORT4_JTAG_JTAG_TMSSWD_DIO_IN |
        SIUL2_0_PORT6_eMIOS_1_eMIOS_1_CH_13_H_IN |
        SIUL2_0_PORT7_FXIO_FXIO_D9_IN |
        SIUL2_0_PORT8_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT10_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT11_eMIOS_1_eMIOS_1_CH_1_H_IN |
        SIUL2_0_PORT12_eMIOS_0_eMIOS_0_CH_14_H_IN |
        SIUL2_0_PORT13_eMIOS_1_eMIOS_1_CH_3_H_IN |
        SIUL2_0_PORT14_FXIO_FXIO_D14_IN |
        SIUL2_0_PORT15_FXIO_FXIO_D31_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FXIO_FXIO_D30_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_0_eMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT33_eMIOS_1_eMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT34_FXIO_FXIO_D18_IN |
        SIUL2_0_PORT35_FXIO_FXIO_D17_IN |
        SIUL2_0_PORT36_eMIOS_1_eMIOS_1_CH_10_H_IN |
        SIUL2_0_PORT37_eMIOS_1_eMIOS_1_CH_11_H_IN |
        SIUL2_0_PORT40_FXIO_FXIO_D29_IN |
        SIUL2_0_PORT41_FXIO_FXIO_D28_IN |
        SIUL2_0_PORT42_FXIO_FXIO_D27_IN |
        SIUL2_0_PORT43_FXIO_FXIO_D26_IN |
        SIUL2_0_PORT44_FXIO_FXIO_D25_IN |
        SIUL2_0_PORT45_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT46_FXIO_FXIO_D23_IN |
        SIUL2_0_PORT47_FXIO_FXIO_D22_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_FXIO_FXIO_D21_IN |
        SIUL2_0_PORT49_eMIOS_1_eMIOS_1_CH_7_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_14_H_IN |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT66_eMIOS_0_eMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_IN |
        SIUL2_0_PORT68_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT69_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT70_eMIOS_1_eMIOS_1_CH_6_H_IN |
        SIUL2_0_PORT71_FXIO_FXIO_D10_IN |
        SIUL2_0_PORT72_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT73_eMIOS_1_eMIOS_1_CH_8_X_IN |
        SIUL2_0_PORT74_eMIOS_1_eMIOS_1_CH_0_X_IN |
        SIUL2_0_PORT75_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT76_eMIOS_1_eMIOS_1_CH_2_H_IN |
        SIUL2_0_PORT77_eMIOS_1_eMIOS_1_CH_3_H_IN |
        SIUL2_0_PORT78_eMIOS_0_eMIOS_0_CH_10_H_IN |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT98_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT99_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_IN |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_19_Y_IN |
        SIUL2_0_PORT102_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_IN |
        SIUL2_0_PORT104_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT105_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT106_eMIOS_1_eMIOS_1_CH_10_H_IN |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT108_LPI2C1_LPI2C1_HREQ |
        SIUL2_0_PORT111_eMIOS_0_eMIOS_0_CH_0_X_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT113_EMAC_EMAC_PPS2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT130_eMIOS_1_eMIOS_1_CH_8_X_IN |
        SIUL2_0_PORT131_EMAC_EMAC_PPS0_IN |
        SIUL2_0_PORT134_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT136_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT137_eMIOS_1_eMIOS_1_CH_13_H_IN |
        SIUL2_0_PORT138_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_21_Y_IN |
        SIUL2_0_PORT140_EMAC_EMAC_PPS3_IN |
        SIUL2_0_PORT141_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT143_FCCU_FCCU_ERR_IN0 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FCCU_FCCU_ERR_IN1 */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_IN |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_IN |
        SIUL2_0_PORT2_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT3_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT6_FXIO_FXIO_D19_IN |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT8_LPUART2_LPUART2_RX |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_IN |
        SIUL2_0_PORT11_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT12_eMIOS_1_eMIOS_1_CH_2_H_IN |
        SIUL2_0_PORT13_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_IN |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_1_eMIOS_1_CH_6_H_IN |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_IN |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_IN |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_IN |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_IN |
        SIUL2_0_PORT41_LPUART1_LPUART1_RIN_B |
        SIUL2_0_PORT43_LPI2C0_LPI2C0_HREQ |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_IN |
        SIUL2_0_PORT45_FXIO_FXIO_D24_IN |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_IN |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_IN |
        SIUL2_0_PORT49_FXIO_FXIO_D20_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMAC_EMAC_MII_RMII_RXD_0 |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_15_H_IN |
        SIUL2_0_PORT66_LPUART0_LPUART0_RX |
        SIUL2_0_PORT68_JTAG_JTAG_TCKSWD_CLK |
        SIUL2_0_PORT69_JTAG_JTAG_TDI |
        SIUL2_0_PORT70_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT71_LPI2C0_LPI2C0_HREQ |
        SIUL2_0_PORT72_LPUART1_LPUART1_RX |
        SIUL2_0_PORT73_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT75_FXIO_FXIO_D19_IN |
        SIUL2_0_PORT76_FXIO_FXIO_D19_IN |
        SIUL2_0_PORT77_FXIO_FXIO_D16_IN |
        SIUL2_0_PORT78_eMIOS_1_eMIOS_1_CH_4_H_IN |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPUART2_LPUART2_RX |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT97_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT98_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT99_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT101_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT102_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT103_QuadSPI_QuadSPI_IOFA1_IN |
        SIUL2_0_PORT104_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT105_FXIO_FXIO_D10_IN |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT107_EMAC_EMAC_MII_RMII_TX_CLK |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT111_eMIOS_1_eMIOS_1_CH_14_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMAC_EMAC_MII_RMII_MDIO_IN |
        SIUL2_0_PORT113_FXIO_FXIO_D9_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT131_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_IN |
        SIUL2_0_PORT136_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT137_EMAC_EMAC_PPS3_IN |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT139_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT140_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT143_FXIO_FXIO_D2_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT5_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_IN |
        SIUL2_0_PORT2_LPUART0_LPUART0_RX |
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_IN |
        SIUL2_0_PORT6_LPUART3_LPUART3_RX |
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_IN |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_IN |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_IN |
        SIUL2_0_PORT12_FXIO_FXIO_D9_IN |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_IN |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_IN |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT34_SAI0_SAI0_D0_IN |
        SIUL2_0_PORT35_SAI0_SAI0_MCLK |
        SIUL2_0_PORT36_EMAC_EMAC_MII_RMII_MDIO_IN |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT40_LPUART1_LPUART1_DCD_B |
        SIUL2_0_PORT43_LPUART0_LPUART0_DSR_B |
        SIUL2_0_PORT44_LPUART0_LPUART0_DCD_B |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMAC_EMAC_MII_RMII_RXD_1 |
        SIUL2_0_PORT65_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_IN |
        SIUL2_0_PORT69_LPI2C1_LPI2C1_HREQ |
        SIUL2_0_PORT70_LPUART1_LPUART1_RX |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_IN |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_IN |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_IN |
        SIUL2_0_PORT74_TRGMUX_TRGMUX_IN11 |
        SIUL2_0_PORT75_TRGMUX_TRGMUX_IN10 |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT77_SAI0_SAI0_SYNC_IN |
        SIUL2_0_PORT78_FXIO_FXIO_D16_IN |
        SIUL2_0_PORT79_EMAC_EMAC_MII_CRS */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT81_EMAC_EMAC_MII_RMII_RX_DV */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_IN |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_IN |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_IN |
        SIUL2_0_PORT99_LPUART3_LPUART3_RX |
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT102_LPUART2_LPUART2_RX |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_IN |
        SIUL2_0_PORT106_EMAC_EMAC_MII_RX_CLK |
        SIUL2_0_PORT107_QuadSPI_QuadSPI_IOFA0_IN |
        SIUL2_0_PORT108_EMAC_EMAC_MII_RMII_TX_CLK |
        SIUL2_0_PORT111_EMAC_EMAC_PPS2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_LPUART2_LPUART2_RX */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT131_SAI1_SAI1_D0_IN |
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_IN |
        SIUL2_0_PORT137_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_IN |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT140_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_IN |
        SIUL2_0_PORT143_LPUART3_LPUART3_RX */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT6_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPUART0_LPUART0_CTS |
        SIUL2_0_PORT2_LPSPI1_LPSPI1_SIN |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_IN |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_IN |
        SIUL2_0_PORT7_LPUART0_LPUART0_DCD_B |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPUART1_LPUART1_DSR_B */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPUART0_LPUART0_RX |
        SIUL2_0_PORT33_HSE_HSE_TAMPER_EXTIN0 |
        SIUL2_0_PORT34_TRGMUX_TRGMUX_IN3 |
        SIUL2_0_PORT35_TRGMUX_TRGMUX_IN2 |
        SIUL2_0_PORT36_TRGMUX_TRGMUX_IN1 |
        SIUL2_0_PORT37_TRGMUX_TRGMUX_IN0 |
        SIUL2_0_PORT45_LPUART0_LPUART0_RIN_B */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMAC_EMAC_MII_RMII_TX_CLK |
        SIUL2_0_PORT65_EMAC_EMAC_MII_RMII_RXD_0 |
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_IN |
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT74_LPUART0_LPUART0_DSR_B |
        SIUL2_0_PORT76_SAI0_SAI0_BCLK_IN |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT79_EMAC_EMAC_MII_RMII_RX_DV */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_TRGMUX_TRGMUX_IN5 |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_IN |
        SIUL2_0_PORT101_EMAC_EMAC_MII_RX_CLK |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_IN |
        SIUL2_0_PORT105_EMAC_EMAC_MII_RMII_RXD_0 |
        SIUL2_0_PORT106_QuadSPI_QuadSPI_SCKFA_IN |
        SIUL2_0_PORT107_LPUART2_LPUART2_CTS |
        SIUL2_0_PORT108_QuadSPI_QuadSPI_IOFA2_IN |
        SIUL2_0_PORT111_FXIO_FXIO_D6_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_LPUART1_LPUART1_CTS |
        SIUL2_0_PORT131_TRGMUX_TRGMUX_IN6 |
        SIUL2_0_PORT136_SAI1_SAI1_BCLK_IN |
        SIUL2_0_PORT137_LPUART2_LPUART2_CTS |
        SIUL2_0_PORT140_SAI1_SAI1_MCLK |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT7_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_IN */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_IN |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT65_EMAC_EMAC_MII_RMII_RXD_1 |
        SIUL2_0_PORT66_QuadSPI_QuadSPI_IOFA3_IN |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_IN |
        SIUL2_0_PORT72_LPUART0_LPUART0_CTS |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_IN |
        SIUL2_0_PORT78_EMAC_EMAC_MII_COL |
        SIUL2_0_PORT79_EMAC_EMAC_MII_RXD2 */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_IN |
        SIUL2_0_PORT99_TRGMUX_TRGMUX_IN4 |
        SIUL2_0_PORT101_TRGMUX_TRGMUX_IN7 |
        SIUL2_0_PORT102_EMAC_EMAC_MII_RMII_TX_CLK |
        SIUL2_0_PORT104_EMAC_EMAC_MII_RMII_RXD_1 |
        SIUL2_0_PORT105_EMAC_EMAC_MII_RXD2 |
        SIUL2_0_PORT111_FXIO_FXIO_D10_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT143_LPUART1_LPUART1_CTS */
        (uint16)( SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT8_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_LPUART1_LPUART1_CTS */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT65_EMAC_EMAC_MII_RX_CLK |
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_IN |
        SIUL2_0_PORT78_EMAC_EMAC_MII_RMII_RX_ER |
        SIUL2_0_PORT79_TRGMUX_TRGMUX_IN8 */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_EMAC_EMAC_MII_RMII_RX_ER */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT101_I3C0_I3C0_SDA_IN |
        SIUL2_0_PORT104_EMAC_EMAC_MII_RXD3 |
        SIUL2_0_PORT105_I3C0_I3C0_SCL_IN |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_IN */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT9_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_LPUART0_LPUART0_RIN_B */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT78_EMAC_EMAC_MII_RXD3 |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_IN */
        (uint16)( SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_I3C0_I3C0_SCL_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT104_I3C0_I3C0_SDA_IN |
        SIUL2_0_PORT111_SAI1_SAI1_SYNC_IN */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT10_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT78_TRGMUX_TRGMUX_IN9 */
        (uint16)( SHL_PAD_U32(14U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT111_LPUART2_LPUART2_CTS */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT11_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT12_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT13_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_INOUT |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_INOUT |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_INOUT |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_INOUT |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_INOUT |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT71_FXIO_FXIO_D10_INOUT |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_INOUT |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_INOUT |
        SIUL2_0_PORT74_eMIOS_0_eMIOS_0_CH_6_G_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_INOUT |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_INOUT |
        SIUL2_0_PORT111_FXIO_FXIO_D6_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_INOUT */
        (uint16)( SHL_PAD_U32(8U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_0_eMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT1_eMIOS_0_eMIOS_0_CH_9_H_INOUT |
        SIUL2_0_PORT2_eMIOS_1_eMIOS_1_CH_19_Y_INOUT |
        SIUL2_0_PORT3_eMIOS_1_eMIOS_1_CH_20_Y_INOUT |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT8_eMIOS_1_eMIOS_1_CH_12_H_INOUT |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT10_eMIOS_0_eMIOS_0_CH_12_H_INOUT |
        SIUL2_0_PORT11_eMIOS_0_eMIOS_0_CH_13_H_INOUT |
        SIUL2_0_PORT12_eMIOS_0_eMIOS_0_CH_14_H_INOUT |
        SIUL2_0_PORT13_eMIOS_0_eMIOS_0_CH_15_H_INOUT |
        SIUL2_0_PORT14_eMIOS_1_eMIOS_1_CH_4_H_INOUT |
        SIUL2_0_PORT15_eMIOS_0_eMIOS_0_CH_10_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_eMIOS_0_eMIOS_0_CH_11_H_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_INOUT |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT34_eMIOS_0_eMIOS_0_CH_8_X_INOUT |
        SIUL2_0_PORT35_eMIOS_0_eMIOS_0_CH_9_H_INOUT |
        SIUL2_0_PORT36_eMIOS_0_eMIOS_0_CH_4_G_INOUT |
        SIUL2_0_PORT37_eMIOS_0_eMIOS_0_CH_5_G_INOUT |
        SIUL2_0_PORT40_eMIOS_1_eMIOS_1_CH_15_H_INOUT |
        SIUL2_0_PORT41_eMIOS_1_eMIOS_1_CH_16_X_INOUT |
        SIUL2_0_PORT42_eMIOS_1_eMIOS_1_CH_17_Y_INOUT |
        SIUL2_0_PORT43_eMIOS_1_eMIOS_1_CH_18_Y_INOUT |
        SIUL2_0_PORT44_eMIOS_0_eMIOS_0_CH_0_X_INOUT |
        SIUL2_0_PORT45_eMIOS_0_eMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT46_eMIOS_0_eMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT47_eMIOS_0_eMIOS_0_CH_3_G_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_eMIOS_0_eMIOS_0_CH_4_G_INOUT |
        SIUL2_0_PORT49_eMIOS_0_eMIOS_0_CH_5_G_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_0_X_INOUT |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT66_eMIOS_0_eMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT67_eMIOS_0_eMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT68_eMIOS_0_eMIOS_0_CH_8_X_INOUT |
        SIUL2_0_PORT69_eMIOS_0_eMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT70_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_INOUT |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_INOUT |
        SIUL2_0_PORT76_eMIOS_1_eMIOS_1_CH_2_H_INOUT |
        SIUL2_0_PORT77_eMIOS_1_eMIOS_1_CH_3_H_INOUT |
        SIUL2_0_PORT78_eMIOS_0_eMIOS_0_CH_10_H_INOUT |
        SIUL2_0_PORT79_eMIOS_0_eMIOS_0_CH_11_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_eMIOS_1_eMIOS_1_CH_9_H_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT98_eMIOS_1_eMIOS_1_CH_21_Y_INOUT |
        SIUL2_0_PORT99_eMIOS_1_eMIOS_1_CH_22_X_INOUT |
        SIUL2_0_PORT100_eMIOS_1_eMIOS_1_CH_23_X_INOUT |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_19_Y_INOUT |
        SIUL2_0_PORT102_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_INOUT |
        SIUL2_0_PORT106_eMIOS_0_eMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT107_eMIOS_0_eMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT108_eMIOS_0_eMIOS_0_CH_18_Y_INOUT |
        SIUL2_0_PORT111_eMIOS_0_eMIOS_0_CH_0_X_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_0_eMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT113_eMIOS_0_eMIOS_0_CH_18_Y_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_INOUT |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT131_SAI1_SAI1_D0_INOUT |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_INOUT |
        SIUL2_0_PORT136_eMIOS_0_eMIOS_0_CH_6_G_INOUT |
        SIUL2_0_PORT137_eMIOS_0_eMIOS_0_CH_7_G_INOUT |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_INOUT |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT141_eMIOS_1_eMIOS_1_CH_5_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_INOUT |
        SIUL2_0_PORT4_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT7_eMIOS_1_eMIOS_1_CH_11_H_INOUT |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_INOUT |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT11_eMIOS_1_eMIOS_1_CH_1_H_INOUT |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_INOUT |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_INOUT |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_INOUT |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT45_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_INOUT |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_INOUT |
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_INOUT |
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_INOUT |
        SIUL2_0_PORT75_eMIOS_1_eMIOS_1_CH_1_H_INOUT |
        SIUL2_0_PORT76_eMIOS_0_eMIOS_0_CH_22_X_INOUT |
        SIUL2_0_PORT77_eMIOS_0_eMIOS_0_CH_23_X_INOUT |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_INOUT |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_INOUT |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_INOUT |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_INOUT |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT101_eMIOS_0_eMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT102_eMIOS_1_eMIOS_1_CH_12_H_INOUT |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_INOUT |
        SIUL2_0_PORT105_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT106_eMIOS_1_eMIOS_1_CH_10_H_INOUT |
        SIUL2_0_PORT111_eMIOS_1_eMIOS_1_CH_14_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMAC_EMAC_MII_RMII_MDIO_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT129_FXIO_FXIO_D2_INOUT |
        SIUL2_0_PORT130_eMIOS_0_eMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT131_eMIOS_0_eMIOS_0_CH_19_Y_INOUT |
        SIUL2_0_PORT137_eMIOS_1_eMIOS_1_CH_13_H_INOUT |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_INOUT |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_INOUT |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_INOUT |
        SIUL2_0_PORT1_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT6_eMIOS_1_eMIOS_1_CH_13_H_INOUT |
        SIUL2_0_PORT8_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT9_FXIO_FXIO_D7_INOUT |
        SIUL2_0_PORT10_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT11_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_0_eMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT33_eMIOS_0_eMIOS_0_CH_7_G_INOUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_eMIOS_1_eMIOS_1_CH_7_H_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_INOUT |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT68_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT69_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT72_eMIOS_1_eMIOS_1_CH_9_H_INOUT |
        SIUL2_0_PORT73_eMIOS_1_eMIOS_1_CH_8_X_INOUT |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_INOUT |
        SIUL2_0_PORT75_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_INOUT |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_eMIOS_0_eMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT97_eMIOS_0_eMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT98_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT99_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT101_I3C0_I3C0_SDA_INOUT |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_INOUT |
        SIUL2_0_PORT104_I3C0_I3C0_SDA_INOUT |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_eMIOS_1_eMIOS_1_CH_8_X_INOUT |
        SIUL2_0_PORT131_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT134_eMIOS_1_eMIOS_1_CH_14_H_INOUT |
        SIUL2_0_PORT136_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT138_eMIOS_0_eMIOS_0_CH_20_Y_INOUT |
        SIUL2_0_PORT139_eMIOS_0_eMIOS_0_CH_21_Y_INOUT |
        SIUL2_0_PORT140_eMIOS_1_eMIOS_1_CH_5_H_INOUT |
        SIUL2_0_PORT143_eMIOS_0_eMIOS_0_CH_22_X_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_eMIOS_0_eMIOS_0_CH_23_X_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT5_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_eMIOS_1_eMIOS_1_CH_0_X_INOUT |
        SIUL2_0_PORT2_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT3_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT6_FXIO_FXIO_D19_INOUT |
        SIUL2_0_PORT12_FXIO_FXIO_D9_INOUT |
        SIUL2_0_PORT13_FXIO_FXIO_D8_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT36_EMAC_EMAC_MII_RMII_MDIO_INOUT */
        (uint16)( SHL_PAD_U32(4U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_eMIOS_1_eMIOS_1_CH_6_H_INOUT |
        SIUL2_0_PORT71_eMIOS_1_eMIOS_1_CH_7_H_INOUT |
        SIUL2_0_PORT76_FXIO_FXIO_D19_INOUT |
        SIUL2_0_PORT77_FXIO_FXIO_D16_INOUT |
        SIUL2_0_PORT78_eMIOS_1_eMIOS_1_CH_4_H_INOUT |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_I3C0_I3C0_SCL_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT99_FXIO_FXIO_D7_INOUT |
        SIUL2_0_PORT104_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT105_I3C0_I3C0_SCL_INOUT |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_INOUT |
        SIUL2_0_PORT111_EMAC_EMAC_PPS2_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_eMIOS_1_eMIOS_1_CH_15_H_INOUT |
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT137_EMAC_EMAC_PPS3_INOUT |
        SIUL2_0_PORT140_EMAC_EMAC_PPS3_INOUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT6_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_INOUT |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_INOUT |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_INOUT |
        SIUL2_0_PORT7_FXIO_FXIO_D9_INOUT |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_INOUT |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_INOUT |
        SIUL2_0_PORT12_eMIOS_1_eMIOS_1_CH_2_H_INOUT |
        SIUL2_0_PORT13_eMIOS_1_eMIOS_1_CH_3_H_INOUT |
        SIUL2_0_PORT14_FXIO_FXIO_D14_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_eMIOS_1_eMIOS_1_CH_6_H_INOUT |
        SIUL2_0_PORT33_eMIOS_1_eMIOS_1_CH_5_H_INOUT |
        SIUL2_0_PORT34_SAI0_SAI0_D0_INOUT |
        SIUL2_0_PORT36_eMIOS_1_eMIOS_1_CH_10_H_INOUT |
        SIUL2_0_PORT37_eMIOS_1_eMIOS_1_CH_11_H_INOUT |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_eMIOS_0_eMIOS_0_CH_14_H_INOUT |
        SIUL2_0_PORT65_eMIOS_0_eMIOS_0_CH_15_H_INOUT |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_INOUT |
        SIUL2_0_PORT75_FXIO_FXIO_D19_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT81_FXIO_FXIO_D14_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT97_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_INOUT |
        SIUL2_0_PORT101_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT102_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT104_eMIOS_0_eMIOS_0_CH_12_H_INOUT |
        SIUL2_0_PORT105_eMIOS_0_eMIOS_0_CH_13_H_INOUT |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT111_SAI1_SAI1_SYNC_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_FXIO_FXIO_D9_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT131_EMAC_EMAC_PPS0_INOUT |
        SIUL2_0_PORT134_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT136_SAI1_SAI1_BCLK_INOUT |
        SIUL2_0_PORT138_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT139_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT140_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT141_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT143_FXIO_FXIO_D2_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT7_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT4_JTAG_JTAG_TMSSWD_DIO_INOUT |
        SIUL2_0_PORT5_SYSTEM_RESET_b_INOUT |
        SIUL2_0_PORT15_FXIO_FXIO_D31_INOUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FXIO_FXIO_D30_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT34_FXIO_FXIO_D18_INOUT |
        SIUL2_0_PORT35_FXIO_FXIO_D17_INOUT |
        SIUL2_0_PORT40_FXIO_FXIO_D29_INOUT |
        SIUL2_0_PORT41_FXIO_FXIO_D28_INOUT |
        SIUL2_0_PORT42_FXIO_FXIO_D27_INOUT |
        SIUL2_0_PORT43_FXIO_FXIO_D26_INOUT |
        SIUL2_0_PORT44_FXIO_FXIO_D25_INOUT |
        SIUL2_0_PORT45_FXIO_FXIO_D24_INOUT |
        SIUL2_0_PORT46_FXIO_FXIO_D23_INOUT |
        SIUL2_0_PORT47_FXIO_FXIO_D22_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_FXIO_FXIO_D21_INOUT |
        SIUL2_0_PORT49_FXIO_FXIO_D20_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_QuadSPI_QuadSPI_IOFA3_INOUT |
        SIUL2_0_PORT72_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT73_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT74_eMIOS_1_eMIOS_1_CH_0_X_INOUT |
        SIUL2_0_PORT76_SAI0_SAI0_BCLK_INOUT |
        SIUL2_0_PORT77_SAI0_SAI0_SYNC_INOUT |
        SIUL2_0_PORT78_FXIO_FXIO_D16_INOUT |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT81_FXIO_FXIO_D2_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT103_QuadSPI_QuadSPI_IOFA1_INOUT |
        SIUL2_0_PORT104_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT105_FXIO_FXIO_D10_INOUT |
        SIUL2_0_PORT106_QuadSPI_QuadSPI_SCKFA_INOUT |
        SIUL2_0_PORT107_QuadSPI_QuadSPI_IOFA0_INOUT |
        SIUL2_0_PORT108_QuadSPI_QuadSPI_IOFA2_INOUT |
        SIUL2_0_PORT111_FXIO_FXIO_D10_INOUT */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_EMAC_EMAC_PPS2_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT136_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT137_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT140_FXIO_FXIO_D7_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
};

/**
* @brief Array of elements storing information about IN functionalities on the SIUL2 instance
*/
static const Port_InMuxSettingType Port_SIUL2_0_aInMuxSettings[] =
{
    /* INMUX settings for pad not available: */
    { NO_INPUTMUX_U16, 0U, 0U},
    /* INMUX settings for pad PORT0:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0 input func */
    {16U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_17_Y_IN input func */
    {65U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_0_X_IN input func */
    {80U, 3U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS7_IN input func */
    {228U, 1U, 0U},
    /* LPUART0_LPUART0_CTS input func */
    {360U, 1U, 0U},
    /* INMUX settings for pad PORT1:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_1 input func */
    {17U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_9_H_IN input func */
    {57U, 1U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS6_IN input func */
    {227U, 1U, 0U},
    /* INMUX settings for pad PORT2:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_2 input func */
    {18U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_19_Y_IN input func */
    {99U, 4U, 0U},
    /* FCCU_FCCU_ERR_IN0 input func */
    {148U, 1U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 3U, 0U},
    /* LPUART0_LPUART0_RX input func */
    {187U, 1U, 0U},
    /* LPSPI1_LPSPI1_SIN input func */
    {239U, 2U, 0U},
    /* INMUX settings for pad PORT3:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3 input func */
    {19U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_20_Y_IN input func */
    {100U, 4U, 0U},
    /* FCCU_FCCU_ERR_IN1 input func */
    {149U, 1U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 3U, 0U},
    /* LPSPI1_LPSPI1_SCK_IN input func */
    {238U, 1U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 1U, 0U},
    /* INMUX settings for pad PORT4:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4 input func */
    {20U, 1U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 8U, 0U},
    /* JTAG_JTAG_TMSSWD_DIO_IN input func */
    {186U, 0U, 0U},
    /* INMUX settings for pad PORT5:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_5 input func */
    {21U, 1U, 0U},
    /* INMUX settings for pad PORT6:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX input func */
    {0U, 2U, 0U},
    /* SIUL_EIRQ_6 input func */
    {22U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_13_H_IN input func */
    {93U, 1U, 0U},
    /* FXIO_FXIO_D19_IN input func */
    {171U, 4U, 0U},
    /* LPUART3_LPUART3_RX input func */
    {190U, 2U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS1_IN input func */
    {249U, 5U, 0U},
    /* LPUART1_LPUART1_CTS input func */
    {361U, 2U, 0U},
    /* LPUART0_LPUART0_RIN_B input func */
    {375U, 1U, 0U},
    /* INMUX settings for pad PORT7:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7 input func */
    {23U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_11_H_IN input func */
    {91U, 1U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 3U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 1U, 0U},
    /* LPUART0_LPUART0_DCD_B input func */
    {374U, 1U, 0U},
    /* INMUX settings for pad PORT8:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_16 input func */
    {32U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_12_H_IN input func */
    {92U, 2U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 2U, 0U},
    /* LPUART2_LPUART2_RX input func */
    {189U, 3U, 0U},
    /* LPSPI2_LPSPI2_SOUT_IN input func */
    {247U, 1U, 0U},
    /* INMUX settings for pad PORT9:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_17 input func */
    {33U, 1U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 2U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 3U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 1U, 0U},
    /* INMUX settings for pad PORT10:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_18 input func */
    {34U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_12_H_IN input func */
    {60U, 2U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 2U, 0U},
    /* INMUX settings for pad PORT11:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_19 input func */
    {35U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_13_H_IN input func */
    {61U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_1_H_IN input func */
    {81U, 3U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 2U, 0U},
    /* LPSPI1_LPSPI1_PCS0_IN input func */
    {232U, 2U, 0U},
    /* INMUX settings for pad PORT12:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN1_CAN1_RX input func */
    {1U, 2U, 0U},
    /* SIUL_EIRQ_20 input func */
    {36U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_14_H_IN input func */
    {62U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_2_H_IN input func */
    {82U, 4U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS5_IN input func */
    {237U, 1U, 0U},
    /* INMUX settings for pad PORT13:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_21 input func */
    {37U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_15_H_IN input func */
    {63U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_3_H_IN input func */
    {83U, 4U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS4_IN input func */
    {236U, 1U, 0U},
    /* INMUX settings for pad PORT14:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_22 input func */
    {38U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_4_H_IN input func */
    {84U, 7U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS3_IN input func */
    {235U, 2U, 0U},
    /* INMUX settings for pad PORT15:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_23 input func */
    {39U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_10_H_IN input func */
    {58U, 2U, 0U},
    /* FXIO_FXIO_D31_IN input func */
    {183U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS3_IN input func */
    {224U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS3_IN input func */
    {244U, 1U, 0U},
    /* INMUX settings for pad PORT16:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4 input func */
    {20U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_11_H_IN input func */
    {59U, 2U, 0U},
    /* FXIO_FXIO_D30_IN input func */
    {182U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS4_IN input func */
    {225U, 1U, 0U},
    /* LPSPI1_LPSPI1_PCS2_IN input func */
    {234U, 2U, 0U},
    /* LPUART1_LPUART1_DSR_B input func */
    {378U, 1U, 0U},
    /* INMUX settings for pad PORT32:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX input func */
    {0U, 3U, 0U},
    /* SIUL_EIRQ_8 input func */
    {24U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_3_G_IN input func */
    {51U, 4U, 0U},
    /* eMIOS_1_eMIOS_1_CH_6_H_IN input func */
    {86U, 1U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 3U, 0U},
    /* LPUART0_LPUART0_RX input func */
    {187U, 2U, 0U},
    /* LPI2C0_LPI2C0_SDAS_IN input func */
    {215U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 1U, 0U},
    /* INMUX settings for pad PORT33:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9 input func */
    {25U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_7_G_IN input func */
    {55U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_5_H_IN input func */
    {85U, 1U, 0U},
    /* LPI2C0_LPI2C0_SCLS_IN input func */
    {213U, 1U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 3U, 0U},
    /* HSE_HSE_TAMPER_EXTIN0 input func */
    {343U, 1U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 2U, 0U},
    /* INMUX settings for pad PORT34:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10 input func */
    {26U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_8_X_IN input func */
    {56U, 1U, 0U},
    /* FXIO_FXIO_D18_IN input func */
    {170U, 1U, 0U},
    /* LPSPI2_LPSPI2_SIN_IN input func */
    {246U, 2U, 0U},
    /* SAI0_SAI0_D0_IN input func */
    {316U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN3 input func */
    {347U, 1U, 0U},
    /* INMUX settings for pad PORT35:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11 input func */
    {27U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_9_H_IN input func */
    {57U, 2U, 0U},
    /* FXIO_FXIO_D17_IN input func */
    {169U, 1U, 0U},
    /* LPSPI2_LPSPI2_SOUT_IN input func */
    {247U, 2U, 0U},
    /* SAI0_SAI0_MCLK input func */
    {320U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN2 input func */
    {346U, 1U, 0U},
    /* INMUX settings for pad PORT36:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12 input func */
    {28U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_4_G_IN input func */
    {52U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_10_H_IN input func */
    {90U, 6U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_MDIO_IN input func */
    {291U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN1 input func */
    {345U, 1U, 0U},
    /* INMUX settings for pad PORT37:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_13 input func */
    {29U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_5_G_IN input func */
    {53U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_11_H_IN input func */
    {91U, 5U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN0 input func */
    {344U, 1U, 0U},
    /* INMUX settings for pad PORT40:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14 input func */
    {30U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_15_H_IN input func */
    {95U, 6U, 0U},
    /* FXIO_FXIO_D29_IN input func */
    {181U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS5_IN input func */
    {226U, 1U, 0U},
    /* LPUART1_LPUART1_DCD_B input func */
    {377U, 1U, 0U},
    /* INMUX settings for pad PORT41:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15 input func */
    {31U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_16_X_IN input func */
    {96U, 5U, 0U},
    /* FXIO_FXIO_D28_IN input func */
    {180U, 1U, 0U},
    /* LPUART1_LPUART1_RIN_B input func */
    {376U, 1U, 0U},
    /* INMUX settings for pad PORT42:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24 input func */
    {40U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_17_Y_IN input func */
    {97U, 4U, 0U},
    /* FXIO_FXIO_D27_IN input func */
    {179U, 1U, 0U},
    /* INMUX settings for pad PORT43:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_25 input func */
    {41U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_18_Y_IN input func */
    {98U, 4U, 0U},
    /* FXIO_FXIO_D26_IN input func */
    {178U, 1U, 0U},
    /* LPI2C0_LPI2C0_HREQ input func */
    {211U, 1U, 0U},
    /* LPUART0_LPUART0_DSR_B input func */
    {373U, 2U, 0U},
    /* INMUX settings for pad PORT44:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_26 input func */
    {42U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_0_X_IN input func */
    {48U, 1U, 0U},
    /* FXIO_FXIO_D25_IN input func */
    {177U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS3_IN input func */
    {251U, 1U, 0U},
    /* LPUART0_LPUART0_DCD_B input func */
    {374U, 2U, 0U},
    /* INMUX settings for pad PORT45:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_27 input func */
    {43U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_1_G_IN input func */
    {49U, 2U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 3U, 0U},
    /* FXIO_FXIO_D24_IN input func */
    {176U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS2_IN input func */
    {250U, 1U, 0U},
    /* LPUART0_LPUART0_RIN_B input func */
    {375U, 2U, 0U},
    /* INMUX settings for pad PORT46:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_28 input func */
    {44U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_2_G_IN input func */
    {50U, 3U, 0U},
    /* FXIO_FXIO_D23_IN input func */
    {175U, 1U, 0U},
    /* LPSPI1_LPSPI1_SCK_IN input func */
    {238U, 2U, 0U},
    /* INMUX settings for pad PORT47:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_29 input func */
    {45U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_3_G_IN input func */
    {51U, 1U, 0U},
    /* FXIO_FXIO_D22_IN input func */
    {174U, 1U, 0U},
    /* LPSPI1_LPSPI1_SIN_IN input func */
    {239U, 1U, 0U},
    /* INMUX settings for pad PORT48:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_30 input func */
    {46U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_4_G_IN input func */
    {52U, 2U, 0U},
    /* FXIO_FXIO_D21_IN input func */
    {173U, 1U, 0U},
    /* LPSPI1_LPSPI1_SOUT_IN input func */
    {240U, 2U, 0U},
    /* INMUX settings for pad PORT49:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_31 input func */
    {47U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_5_G_IN input func */
    {53U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_7_H_IN input func */
    {87U, 7U, 0U},
    /* FXIO_FXIO_D20_IN input func */
    {172U, 1U, 0U},
    /* LPSPI1_LPSPI1_PCS3_IN input func */
    {235U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 2U, 0U},
    /* INMUX settings for pad PORT64:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0 input func */
    {16U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_0_X_IN input func */
    {48U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_14_H_IN input func */
    {62U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_0 input func */
    {294U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_1 input func */
    {295U, 1U, 0U},
    /* EMAC_EMAC_MII_RMII_TX_CLK input func */
    {296U, 4U, 0U},
    /* INMUX settings for pad PORT65:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN3_CAN3_RX input func */
    {3U, 2U, 0U},
    /* SIUL_EIRQ_1 input func */
    {17U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_1_G_IN input func */
    {49U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_15_H_IN input func */
    {63U, 1U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 7U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_0 input func */
    {294U, 1U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_1 input func */
    {295U, 2U, 0U},
    /* EMAC_EMAC_MII_RX_CLK input func */
    {300U, 3U, 0U},
    /* INMUX settings for pad PORT66:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX input func */
    {0U, 1U, 0U},
    /* SIUL_EIRQ_2 input func */
    {18U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_2_G_IN input func */
    {50U, 2U, 0U},
    /* LPUART0_LPUART0_RX input func */
    {187U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS2_IN input func */
    {223U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS2_IN input func */
    {250U, 4U, 0U},
    /* QuadSPI_QuadSPI_IOFA3_IN input func */
    {308U, 1U, 0U},
    /* INMUX settings for pad PORT67:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3 input func */
    {19U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_3_G_IN input func */
    {51U, 3U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 3U, 0U},
    /* INMUX settings for pad PORT68:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4 input func */
    {20U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_8_X_IN input func */
    {56U, 2U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 8U, 0U},
    /* JTAG_JTAG_TCKSWD_CLK input func */
    {184U, 0U, 0U},
    /* INMUX settings for pad PORT69:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_5 input func */
    {21U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_16_X_IN input func */
    {64U, 2U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 7U, 0U},
    /* JTAG_JTAG_TDI input func */
    {185U, 0U, 0U},
    /* LPI2C1_LPI2C1_HREQ input func */
    {216U, 2U, 0U},
    /* INMUX settings for pad PORT70:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX input func */
    {2U, 6U, 0U},
    /* SIUL_EIRQ_6 input func */
    {22U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_6_H_IN input func */
    {86U, 4U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 3U, 0U},
    /* LPUART1_LPUART1_RX input func */
    {188U, 1U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 4U, 0U},
    /* INMUX settings for pad PORT71:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7 input func */
    {23U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_7_H_IN input func */
    {87U, 4U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 3U, 0U},
    /* LPI2C0_LPI2C0_HREQ input func */
    {211U, 2U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 6U, 0U},
    /* LPUART1_LPUART1_TX_IN input func */
    {364U, 1U, 0U},
    /* INMUX settings for pad PORT72:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_16 input func */
    {32U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_9_H_IN input func */
    {89U, 1U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 3U, 0U},
    /* LPUART1_LPUART1_RX input func */
    {188U, 2U, 0U},
    /* LPI2C0_LPI2C0_SCL_IN input func */
    {212U, 1U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 1U, 0U},
    /* LPUART0_LPUART0_CTS input func */
    {360U, 2U, 0U},
    /* INMUX settings for pad PORT73:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN1_CAN1_RX input func */
    {1U, 1U, 0U},
    /* SIUL_EIRQ_17 input func */
    {33U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_8_X_IN input func */
    {88U, 1U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 3U, 0U},
    /* LPI2C0_LPI2C0_SDA_IN input func */
    {214U, 1U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 2U, 0U},
    /* LPUART1_LPUART1_TX_IN input func */
    {364U, 2U, 0U},
    /* INMUX settings for pad PORT74:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_18 input func */
    {34U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_6_G_IN input func */
    {54U, 4U, 0U},
    /* eMIOS_1_eMIOS_1_CH_0_X_IN input func */
    {80U, 6U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 3U, 0U},
    /* TRGMUX_TRGMUX_IN11 input func */
    {355U, 1U, 0U},
    /* LPUART0_LPUART0_DSR_B input func */
    {373U, 1U, 0U},
    /* INMUX settings for pad PORT75:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_19 input func */
    {35U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_1_H_IN input func */
    {81U, 7U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 3U, 0U},
    /* FXIO_FXIO_D19_IN input func */
    {171U, 3U, 0U},
    /* TRGMUX_TRGMUX_IN10 input func */
    {354U, 1U, 0U},
    /* INMUX settings for pad PORT76:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_20 input func */
    {36U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_22_X_IN input func */
    {70U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_2_H_IN input func */
    {82U, 1U, 0U},
    /* FXIO_FXIO_D19_IN input func */
    {171U, 5U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 4U, 0U},
    /* SAI0_SAI0_BCLK_IN input func */
    {315U, 1U, 0U},
    /* INMUX settings for pad PORT77:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_21 input func */
    {37U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_23_X_IN input func */
    {71U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_3_H_IN input func */
    {83U, 7U, 0U},
    /* FXIO_FXIO_D16_IN input func */
    {168U, 3U, 0U},
    /* SAI0_SAI0_SYNC_IN input func */
    {321U, 1U, 0U},
    /* INMUX settings for pad PORT78:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX input func */
    {2U, 2U, 0U},
    /* SIUL_EIRQ_22 input func */
    {38U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_10_H_IN input func */
    {58U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_4_H_IN input func */
    {84U, 8U, 0U},
    /* FXIO_FXIO_D16_IN input func */
    {168U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 2U, 0U},
    /* EMAC_EMAC_MII_COL input func */
    {289U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_RX_ER input func */
    {293U, 2U, 0U},
    /* EMAC_EMAC_MII_RXD3 input func */
    {302U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN9 input func */
    {353U, 1U, 0U},
    /* INMUX settings for pad PORT79:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_23 input func */
    {39U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_11_H_IN input func */
    {59U, 1U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 6U, 0U},
    /* LPSPI2_LPSPI2_SCK_IN input func */
    {245U, 2U, 0U},
    /* EMAC_EMAC_MII_CRS input func */
    {290U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_RX_DV input func */
    {292U, 2U, 0U},
    /* EMAC_EMAC_MII_RXD2 input func */
    {301U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN8 input func */
    {352U, 1U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 2U, 0U},
    /* INMUX settings for pad PORT80:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX input func */
    {2U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_9_H_IN input func */
    {89U, 5U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 1U, 0U},
    /* LPUART2_LPUART2_RX input func */
    {189U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDAS_IN input func */
    {220U, 1U, 0U},
    /* LPSPI3_LPSPI3_SIN_IN input func */
    {253U, 3U, 0U},
    /* EMAC_EMAC_MII_RMII_RX_ER input func */
    {293U, 1U, 0U},
    /* I3C0_I3C0_SCL_IN input func */
    {371U, 2U, 0U},
    /* INMUX settings for pad PORT81:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FXIO_FXIO_D2_IN input func */
    {154U, 10U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 1U, 0U},
    /* LPI2C1_LPI2C1_SCLS_IN input func */
    {218U, 2U, 0U},
    /* LPSPI3_LPSPI3_SCK_IN input func */
    {252U, 3U, 0U},
    /* EMAC_EMAC_MII_RMII_RX_DV input func */
    {292U, 1U, 0U},
    /* INMUX settings for pad PORT96:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_8 input func */
    {24U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_2_G_IN input func */
    {50U, 1U, 0U},
    /* eMIOS_0_eMIOS_0_CH_16_X_IN input func */
    {64U, 1U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 1U, 0U},
    /* LPSPI3_LPSPI3_SOUT_IN input func */
    {254U, 1U, 0U},
    /* INMUX settings for pad PORT97:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9 input func */
    {25U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_3_G_IN input func */
    {51U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_17_Y_IN input func */
    {65U, 1U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 1U, 0U},
    /* LPSPI3_LPSPI3_SCK_IN input func */
    {252U, 1U, 0U},
    /* INMUX settings for pad PORT98:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10 input func */
    {26U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_21_Y_IN input func */
    {101U, 4U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 1U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 3U, 0U},
    /* LPSPI1_LPSPI1_SOUT_IN input func */
    {240U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN5 input func */
    {349U, 1U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 2U, 0U},
    /* INMUX settings for pad PORT99:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11 input func */
    {27U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_22_X_IN input func */
    {102U, 4U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 2U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 3U, 0U},
    /* LPUART3_LPUART3_RX input func */
    {190U, 3U, 0U},
    /* LPSPI1_LPSPI1_PCS0_IN input func */
    {232U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN4 input func */
    {348U, 1U, 0U},
    /* INMUX settings for pad PORT100:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12 input func */
    {28U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_23_X_IN input func */
    {103U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 6U, 0U},
    /* INMUX settings for pad PORT101:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_13 input func */
    {29U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_2_G_IN input func */
    {50U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_19_Y_IN input func */
    {67U, 2U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 4U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 5U, 0U},
    /* EMAC_EMAC_MII_RX_CLK input func */
    {300U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN7 input func */
    {351U, 1U, 0U},
    /* I3C0_I3C0_SDA_IN input func */
    {372U, 2U, 0U},
    /* INMUX settings for pad PORT102:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14 input func */
    {30U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_12_H_IN input func */
    {92U, 5U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 9U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 1U, 0U},
    /* LPUART2_LPUART2_RX input func */
    {189U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 7U, 0U},
    /* EMAC_EMAC_MII_RMII_TX_CLK input func */
    {296U, 2U, 0U},
    /* INMUX settings for pad PORT103:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15 input func */
    {31U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS3_IN input func */
    {224U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS3_IN input func */
    {251U, 5U, 0U},
    /* QuadSPI_QuadSPI_IOFA1_IN input func */
    {306U, 1U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 3U, 0U},
    /* INMUX settings for pad PORT104:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24 input func */
    {40U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_12_H_IN input func */
    {60U, 1U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 5U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 1U, 0U},
    /* LPSPI3_LPSPI3_SOUT_IN input func */
    {254U, 3U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_1 input func */
    {295U, 3U, 0U},
    /* EMAC_EMAC_MII_RXD3 input func */
    {302U, 1U, 0U},
    /* I3C0_I3C0_SDA_IN input func */
    {372U, 1U, 0U},
    /* INMUX settings for pad PORT105:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_25 input func */
    {41U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_13_H_IN input func */
    {61U, 2U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 5U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 4U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 2U, 0U},
    /* EMAC_EMAC_MII_RMII_RXD_0 input func */
    {294U, 3U, 0U},
    /* EMAC_EMAC_MII_RXD2 input func */
    {301U, 1U, 0U},
    /* I3C0_I3C0_SCL_IN input func */
    {371U, 1U, 0U},
    /* INMUX settings for pad PORT106:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_26 input func */
    {42U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_16_X_IN input func */
    {64U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_10_H_IN input func */
    {90U, 2U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 4U, 0U},
    /* EMAC_EMAC_MII_RX_CLK input func */
    {300U, 1U, 0U},
    /* QuadSPI_QuadSPI_SCKFA_IN input func */
    {309U, 1U, 0U},
    /* INMUX settings for pad PORT107:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_27 input func */
    {43U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_17_Y_IN input func */
    {65U, 3U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 5U, 0U},
    /* EMAC_EMAC_MII_RMII_TX_CLK input func */
    {296U, 1U, 0U},
    /* QuadSPI_QuadSPI_IOFA0_IN input func */
    {305U, 1U, 0U},
    /* LPUART2_LPUART2_CTS input func */
    {362U, 1U, 0U},
    /* INMUX settings for pad PORT108:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_28 input func */
    {44U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_18_Y_IN input func */
    {66U, 1U, 0U},
    /* LPI2C1_LPI2C1_HREQ input func */
    {216U, 1U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 5U, 0U},
    /* EMAC_EMAC_MII_RMII_TX_CLK input func */
    {296U, 3U, 0U},
    /* QuadSPI_QuadSPI_IOFA2_IN input func */
    {307U, 1U, 0U},
    /* INMUX settings for pad PORT111:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN3_CAN3_RX input func */
    {3U, 1U, 0U},
    /* SIUL_EIRQ_31 input func */
    {47U, 2U, 0U},
    /* eMIOS_0_eMIOS_0_CH_0_X_IN input func */
    {48U, 2U, 0U},
    /* eMIOS_1_eMIOS_1_CH_14_H_IN input func */
    {94U, 6U, 0U},
    /* EMAC_EMAC_PPS2_IN input func */
    {146U, 2U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 7U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 1U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 3U, 0U},
    /* SAI1_SAI1_SYNC_IN input func */
    {325U, 1U, 0U},
    /* LPUART2_LPUART2_CTS input func */
    {362U, 2U, 0U},
    /* INMUX settings for pad PORT112:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* eMIOS_0_eMIOS_0_CH_1_G_IN input func */
    {49U, 3U, 0U},
    /* eMIOS_1_eMIOS_1_CH_15_H_IN input func */
    {95U, 7U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 3U, 0U},
    /* EMAC_EMAC_MII_RMII_MDIO_IN input func */
    {291U, 2U, 0U},
    /* INMUX settings for pad PORT113:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24 input func */
    {40U, 3U, 0U},
    /* eMIOS_0_eMIOS_0_CH_18_Y_IN input func */
    {66U, 3U, 0U},
    /* EMAC_EMAC_PPS2_IN input func */
    {146U, 1U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 1U, 0U},
    /* LPUART2_LPUART2_RX input func */
    {189U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 1U, 0U},
    /* INMUX settings for pad PORT128:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0 input func */
    {16U, 4U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 7U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 1U, 0U},
    /* INMUX settings for pad PORT129:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_1 input func */
    {17U, 4U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 8U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 2U, 0U},
    /* INMUX settings for pad PORT130:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_2 input func */
    {18U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_3_G_IN input func */
    {51U, 5U, 0U},
    /* eMIOS_1_eMIOS_1_CH_8_X_IN input func */
    {88U, 4U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 4U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 1U, 0U},
    /* LPUART1_LPUART1_CTS input func */
    {361U, 1U, 0U},
    /* INMUX settings for pad PORT131:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3 input func */
    {19U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_19_Y_IN input func */
    {67U, 4U, 0U},
    /* EMAC_EMAC_PPS0_IN input func */
    {144U, 1U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 6U, 0U},
    /* SAI1_SAI1_D0_IN input func */
    {323U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN6 input func */
    {350U, 1U, 0U},
    /* INMUX settings for pad PORT134:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_6 input func */
    {22U, 4U, 0U},
    /* eMIOS_1_eMIOS_1_CH_14_H_IN input func */
    {94U, 5U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 4U, 0U},
    /* LPSPI0_LPSPI0_PCS2_IN input func */
    {223U, 1U, 0U},
    /* INMUX settings for pad PORT136:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7 input func */
    {23U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_6_G_IN input func */
    {54U, 1U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 5U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS1_IN input func */
    {249U, 1U, 0U},
    /* SAI1_SAI1_BCLK_IN input func */
    {322U, 1U, 0U},
    /* INMUX settings for pad PORT137:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_8 input func */
    {24U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_7_G_IN input func */
    {55U, 1U, 0U},
    /* eMIOS_1_eMIOS_1_CH_13_H_IN input func */
    {93U, 5U, 0U},
    /* EMAC_EMAC_PPS3_IN input func */
    {147U, 1U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 1U, 0U},
    /* LPUART2_LPUART2_CTS input func */
    {362U, 3U, 0U},
    /* INMUX settings for pad PORT138:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9 input func */
    {25U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_20_Y_IN input func */
    {68U, 2U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 2U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 1U, 0U},
    /* LPSPI3_LPSPI3_SIN_IN input func */
    {253U, 1U, 0U},
    /* INMUX settings for pad PORT139:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10 input func */
    {26U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_1_G_IN input func */
    {49U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_21_Y_IN input func */
    {69U, 2U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 3U, 0U},
    /* INMUX settings for pad PORT140:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11 input func */
    {27U, 4U, 0U},
    /* eMIOS_1_eMIOS_1_CH_5_H_IN input func */
    {85U, 5U, 0U},
    /* EMAC_EMAC_PPS3_IN input func */
    {147U, 3U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 9U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 1U, 0U},
    /* SAI1_SAI1_MCLK input func */
    {324U, 2U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 4U, 0U},
    /* INMUX settings for pad PORT141:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12 input func */
    {28U, 4U, 0U},
    /* eMIOS_1_eMIOS_1_CH_5_H_IN input func */
    {85U, 3U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 5U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 5U, 0U},
    /* LPSPI2_LPSPI2_PCS2_IN input func */
    {243U, 2U, 0U},
    /* INMUX settings for pad PORT143:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14 input func */
    {30U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_22_X_IN input func */
    {70U, 1U, 0U},
    /* FCCU_FCCU_ERR_IN0 input func */
    {148U, 2U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 1U, 0U},
    /* LPUART3_LPUART3_RX input func */
    {190U, 1U, 0U},
    /* LPSPI2_LPSPI2_SCK_IN input func */
    {245U, 1U, 0U},
    /* LPUART1_LPUART1_CTS input func */
    {361U, 3U, 0U},
    /* INMUX settings for pad PORT144:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15 input func */
    {31U, 4U, 0U},
    /* eMIOS_0_eMIOS_0_CH_23_X_IN input func */
    {71U, 2U, 0U},
    /* FCCU_FCCU_ERR_IN1 input func */
    {149U, 2U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 2U, 0U},
    /* LPSPI2_LPSPI2_SIN_IN input func */
    {246U, 1U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 3U, 0U}
};

/**
* @brief Array of elements storing information about INOUT functionalities on the SIUL2 instance
*/
static const Port_InoutSettingType Port_SIUL2_0_aInoutMuxSettings[PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16] =
{
    /* Inout settings for pad PORT0 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_17_Y_INOUT inout functionality */
    {0U, 33U, 65U, 2U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {0U, 35U, 154U, 2U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_0_X_INOUT inout functionality */
    {0U, 36U, 80U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_PCS7_INOUT inout functionality */
    {0U, 37U, 228U, 1U, 0U}, 
    /* Inout settings for pad PORT1 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_9_H_INOUT inout functionality */
    {1U, 33U, 57U, 1U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {1U, 35U, 155U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS6_INOUT inout functionality */
    {1U, 37U, 227U, 1U, 0U}, 
    /* Inout settings for pad PORT2 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_19_Y_INOUT inout functionality */
    {2U, 33U, 99U, 4U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {2U, 36U, 156U, 3U, 0U}, 
    /* Inout settings for pad PORT3 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_20_Y_INOUT inout functionality */
    {3U, 33U, 100U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_SCK_INOUT inout functionality */
    {3U, 34U, 238U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {3U, 36U, 157U, 3U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {3U, 37U, 363U, 1U, 0U}, 
    /* Inout settings for pad PORT4 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {4U, 34U, 158U, 8U, 0U}, 
    /* JTAG_JTAG_TMSSWD_DIO_INOUT inout functionality */
    {4U, 38U, 186U, 0U, 0U}, 
    /* Inout settings for pad PORT5 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* SYSTEM_RESET_b_INOUT inout functionality */
    {5U, 38U, 65535U, 0U, 0U}, 
    /* Inout settings for pad PORT6 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {6U, 34U, 233U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_13_H_INOUT inout functionality */
    {6U, 35U, 93U, 1U, 0U}, 
    /* FXIO_FXIO_D19_INOUT inout functionality */
    {6U, 36U, 171U, 4U, 0U}, 
    /* LPSPI3_LPSPI3_PCS1_INOUT inout functionality */
    {6U, 37U, 249U, 5U, 0U}, 
    /* Inout settings for pad PORT7 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {7U, 32U, 366U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {7U, 33U, 222U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_11_H_INOUT inout functionality */
    {7U, 34U, 91U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {7U, 37U, 161U, 3U, 0U}, 
    /* Inout settings for pad PORT8 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_12_H_INOUT inout functionality */
    {8U, 33U, 92U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_SOUT_INOUT inout functionality */
    {8U, 34U, 247U, 1U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {8U, 35U, 158U, 2U, 0U}, 
    /* Inout settings for pad PORT9 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {9U, 33U, 365U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {9U, 34U, 241U, 1U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {9U, 35U, 159U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {9U, 37U, 248U, 3U, 0U}, 
    /* Inout settings for pad PORT10 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_12_H_INOUT inout functionality */
    {10U, 33U, 60U, 2U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {10U, 35U, 152U, 2U, 0U}, 
    /* Inout settings for pad PORT11 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_13_H_INOUT inout functionality */
    {11U, 33U, 61U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_1_H_INOUT inout functionality */
    {11U, 34U, 81U, 3U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {11U, 35U, 153U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS0_INOUT inout functionality */
    {11U, 37U, 232U, 2U, 0U}, 
    /* Inout settings for pad PORT12 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS5_INOUT inout functionality */
    {12U, 32U, 237U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_14_H_INOUT inout functionality */
    {12U, 33U, 62U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {12U, 36U, 161U, 4U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_2_H_INOUT inout functionality */
    {12U, 37U, 82U, 4U, 0U}, 
    /* Inout settings for pad PORT13 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS4_INOUT inout functionality */
    {13U, 32U, 236U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_15_H_INOUT inout functionality */
    {13U, 33U, 63U, 2U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {13U, 36U, 160U, 4U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_3_H_INOUT inout functionality */
    {13U, 37U, 83U, 4U, 0U}, 
    /* Inout settings for pad PORT14 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_4_H_INOUT inout functionality */
    {14U, 33U, 84U, 7U, 0U}, 
    /* LPSPI1_LPSPI1_PCS3_INOUT inout functionality */
    {14U, 34U, 235U, 2U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {14U, 37U, 166U, 4U, 0U}, 
    /* Inout settings for pad PORT15 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_10_H_INOUT inout functionality */
    {15U, 33U, 58U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_PCS3_INOUT inout functionality */
    {15U, 34U, 224U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS3_INOUT inout functionality */
    {15U, 35U, 244U, 1U, 0U}, 
    /* FXIO_FXIO_D31_INOUT inout functionality */
    {15U, 38U, 183U, 1U, 0U}, 
    /* Inout settings for pad PORT16 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_11_H_INOUT inout functionality */
    {16U, 33U, 59U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS2_INOUT inout functionality */
    {16U, 34U, 234U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_PCS4_INOUT inout functionality */
    {16U, 35U, 225U, 1U, 0U}, 
    /* FXIO_FXIO_D30_INOUT inout functionality */
    {16U, 38U, 182U, 1U, 0U}, 
    /* Inout settings for pad PORT32 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SDAS_INOUT inout functionality */
    {32U, 32U, 215U, 1U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {32U, 33U, 166U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {32U, 34U, 221U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_3_G_INOUT inout functionality */
    {32U, 35U, 51U, 4U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_6_H_INOUT inout functionality */
    {32U, 37U, 86U, 1U, 0U}, 
    /* Inout settings for pad PORT33 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SCLS_INOUT inout functionality */
    {33U, 32U, 213U, 1U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {33U, 33U, 363U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {33U, 34U, 231U, 3U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_7_G_INOUT inout functionality */
    {33U, 35U, 55U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_5_H_INOUT inout functionality */
    {33U, 37U, 85U, 1U, 0U}, 
    /* Inout settings for pad PORT34 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_8_X_INOUT inout functionality */
    {34U, 33U, 56U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_SIN_INOUT inout functionality */
    {34U, 34U, 246U, 2U, 0U}, 
    /* SAI0_SAI0_D0_INOUT inout functionality */
    {34U, 37U, 316U, 1U, 0U}, 
    /* FXIO_FXIO_D18_INOUT inout functionality */
    {34U, 38U, 170U, 1U, 0U}, 
    /* Inout settings for pad PORT35 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_9_H_INOUT inout functionality */
    {35U, 33U, 57U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_SOUT_INOUT inout functionality */
    {35U, 34U, 247U, 2U, 0U}, 
    /* FXIO_FXIO_D17_INOUT inout functionality */
    {35U, 38U, 169U, 1U, 0U}, 
    /* Inout settings for pad PORT36 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_4_G_INOUT inout functionality */
    {36U, 33U, 52U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {36U, 34U, 231U, 2U, 0U}, 
    /* EMAC_EMAC_MII_RMII_MDIO_INOUT inout functionality */
    {36U, 36U, 291U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_10_H_INOUT inout functionality */
    {36U, 37U, 90U, 6U, 0U}, 
    /* Inout settings for pad PORT37 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_5_G_INOUT inout functionality */
    {37U, 33U, 53U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {37U, 34U, 222U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {37U, 35U, 221U, 2U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_11_H_INOUT inout functionality */
    {37U, 37U, 91U, 5U, 0U}, 
    /* Inout settings for pad PORT40 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_15_H_INOUT inout functionality */
    {40U, 33U, 95U, 6U, 0U}, 
    /* LPSPI0_LPSPI0_PCS5_INOUT inout functionality */
    {40U, 37U, 226U, 1U, 0U}, 
    /* FXIO_FXIO_D29_INOUT inout functionality */
    {40U, 38U, 181U, 1U, 0U}, 
    /* Inout settings for pad PORT41 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_16_X_INOUT inout functionality */
    {41U, 33U, 96U, 5U, 0U}, 
    /* FXIO_FXIO_D28_INOUT inout functionality */
    {41U, 38U, 180U, 1U, 0U}, 
    /* Inout settings for pad PORT42 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_17_Y_INOUT inout functionality */
    {42U, 33U, 97U, 4U, 0U}, 
    /* FXIO_FXIO_D27_INOUT inout functionality */
    {42U, 38U, 179U, 1U, 0U}, 
    /* Inout settings for pad PORT43 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_18_Y_INOUT inout functionality */
    {43U, 33U, 98U, 4U, 0U}, 
    /* FXIO_FXIO_D26_INOUT inout functionality */
    {43U, 38U, 178U, 1U, 0U}, 
    /* Inout settings for pad PORT44 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS3_INOUT inout functionality */
    {44U, 32U, 251U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_0_X_INOUT inout functionality */
    {44U, 33U, 48U, 1U, 0U}, 
    /* FXIO_FXIO_D25_INOUT inout functionality */
    {44U, 38U, 177U, 1U, 0U}, 
    /* Inout settings for pad PORT45 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS2_INOUT inout functionality */
    {45U, 32U, 250U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_1_G_INOUT inout functionality */
    {45U, 33U, 49U, 2U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {45U, 34U, 160U, 3U, 0U}, 
    /* FXIO_FXIO_D24_INOUT inout functionality */
    {45U, 38U, 176U, 1U, 0U}, 
    /* Inout settings for pad PORT46 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_2_G_INOUT inout functionality */
    {46U, 33U, 50U, 3U, 0U}, 
    /* LPSPI1_LPSPI1_SCK_INOUT inout functionality */
    {46U, 34U, 238U, 2U, 0U}, 
    /* FXIO_FXIO_D23_INOUT inout functionality */
    {46U, 38U, 175U, 1U, 0U}, 
    /* Inout settings for pad PORT47 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_3_G_INOUT inout functionality */
    {47U, 33U, 51U, 1U, 0U}, 
    /* LPSPI1_LPSPI1_SIN_INOUT inout functionality */
    {47U, 34U, 239U, 1U, 0U}, 
    /* FXIO_FXIO_D22_INOUT inout functionality */
    {47U, 38U, 174U, 1U, 0U}, 
    /* Inout settings for pad PORT48 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_4_G_INOUT inout functionality */
    {48U, 33U, 52U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_SOUT_INOUT inout functionality */
    {48U, 34U, 240U, 2U, 0U}, 
    /* FXIO_FXIO_D21_INOUT inout functionality */
    {48U, 38U, 173U, 1U, 0U}, 
    /* Inout settings for pad PORT49 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_5_G_INOUT inout functionality */
    {49U, 33U, 53U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS3_INOUT inout functionality */
    {49U, 34U, 235U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_7_H_INOUT inout functionality */
    {49U, 35U, 87U, 7U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {49U, 37U, 248U, 2U, 0U}, 
    /* FXIO_FXIO_D20_INOUT inout functionality */
    {49U, 38U, 172U, 1U, 0U}, 
    /* Inout settings for pad PORT64 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_0_X_INOUT inout functionality */
    {64U, 33U, 48U, 3U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_14_H_INOUT inout functionality */
    {64U, 37U, 62U, 2U, 0U}, 
    /* Inout settings for pad PORT65 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_1_G_INOUT inout functionality */
    {65U, 33U, 49U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {65U, 35U, 157U, 7U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_15_H_INOUT inout functionality */
    {65U, 37U, 63U, 1U, 0U}, 
    /* Inout settings for pad PORT66 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_2_G_INOUT inout functionality */
    {66U, 33U, 50U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_PCS2_INOUT inout functionality */
    {66U, 34U, 250U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS2_INOUT inout functionality */
    {66U, 35U, 223U, 2U, 0U}, 
    /* QuadSPI_QuadSPI_IOFA3_INOUT inout functionality */
    {66U, 38U, 308U, 1U, 0U}, 
    /* Inout settings for pad PORT67 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_3_G_INOUT inout functionality */
    {67U, 33U, 51U, 3U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {67U, 35U, 363U, 3U, 0U}, 
    /* Inout settings for pad PORT68 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_8_X_INOUT inout functionality */
    {68U, 33U, 56U, 2U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {68U, 35U, 157U, 8U, 0U}, 
    /* Inout settings for pad PORT69 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_16_X_INOUT inout functionality */
    {69U, 33U, 64U, 2U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {69U, 35U, 156U, 7U, 0U}, 
    /* Inout settings for pad PORT70 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {70U, 32U, 219U, 2U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {70U, 33U, 163U, 3U, 0U}, 
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {70U, 34U, 233U, 4U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_6_H_INOUT inout functionality */
    {70U, 36U, 86U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {70U, 37U, 222U, 4U, 0U}, 
    /* Inout settings for pad PORT71 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {71U, 32U, 162U, 3U, 0U}, 
    /* LPUART1_LPUART1_TX_INOUT inout functionality */
    {71U, 33U, 364U, 1U, 0U}, 
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {71U, 34U, 217U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_7_H_INOUT inout functionality */
    {71U, 36U, 87U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {71U, 37U, 221U, 6U, 0U}, 
    /* Inout settings for pad PORT72 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SCL_INOUT inout functionality */
    {72U, 32U, 212U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_9_H_INOUT inout functionality */
    {72U, 35U, 89U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {72U, 37U, 229U, 1U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {72U, 38U, 164U, 3U, 0U}, 
    /* Inout settings for pad PORT73 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SDA_INOUT inout functionality */
    {73U, 32U, 214U, 1U, 0U}, 
    /* LPUART1_LPUART1_TX_INOUT inout functionality */
    {73U, 33U, 364U, 2U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_8_X_INOUT inout functionality */
    {73U, 35U, 88U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {73U, 37U, 230U, 2U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {73U, 38U, 165U, 3U, 0U}, 
    /* Inout settings for pad PORT74 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_6_G_INOUT inout functionality */
    {74U, 32U, 54U, 4U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {74U, 35U, 242U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_0_X_INOUT inout functionality */
    {74U, 38U, 80U, 6U, 0U}, 
    /* Inout settings for pad PORT75 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_1_H_INOUT inout functionality */
    {75U, 34U, 81U, 7U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {75U, 35U, 167U, 3U, 0U}, 
    /* FXIO_FXIO_D19_INOUT inout functionality */
    {75U, 37U, 171U, 3U, 0U}, 
    /* Inout settings for pad PORT76 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_2_H_INOUT inout functionality */
    {76U, 33U, 82U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_22_X_INOUT inout functionality */
    {76U, 34U, 70U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {76U, 35U, 242U, 4U, 0U}, 
    /* FXIO_FXIO_D19_INOUT inout functionality */
    {76U, 36U, 171U, 5U, 0U}, 
    /* SAI0_SAI0_BCLK_INOUT inout functionality */
    {76U, 38U, 315U, 1U, 0U}, 
    /* Inout settings for pad PORT77 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_3_H_INOUT inout functionality */
    {77U, 33U, 83U, 7U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_23_X_INOUT inout functionality */
    {77U, 34U, 71U, 1U, 0U}, 
    /* FXIO_FXIO_D16_INOUT inout functionality */
    {77U, 36U, 168U, 3U, 0U}, 
    /* SAI0_SAI0_SYNC_INOUT inout functionality */
    {77U, 38U, 321U, 1U, 0U}, 
    /* Inout settings for pad PORT78 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_10_H_INOUT inout functionality */
    {78U, 33U, 58U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {78U, 34U, 241U, 2U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_4_H_INOUT inout functionality */
    {78U, 36U, 84U, 8U, 0U}, 
    /* FXIO_FXIO_D16_INOUT inout functionality */
    {78U, 38U, 168U, 1U, 0U}, 
    /* Inout settings for pad PORT79 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_11_H_INOUT inout functionality */
    {79U, 33U, 59U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_SCK_INOUT inout functionality */
    {79U, 34U, 245U, 2U, 0U}, 
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {79U, 36U, 365U, 2U, 0U}, 
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {79U, 38U, 217U, 6U, 0U}, 
    /* Inout settings for pad PORT80 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SIN_INOUT inout functionality */
    {80U, 32U, 253U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_9_H_INOUT inout functionality */
    {80U, 33U, 89U, 5U, 0U}, 
    /* LPI2C1_LPI2C1_SDAS_INOUT inout functionality */
    {80U, 35U, 220U, 1U, 0U}, 
    /* I3C0_I3C0_SCL_INOUT inout functionality */
    {80U, 36U, 371U, 2U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {80U, 37U, 167U, 1U, 0U}, 
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {80U, 38U, 219U, 5U, 0U}, 
    /* Inout settings for pad PORT81 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SCK_INOUT inout functionality */
    {81U, 32U, 252U, 3U, 0U}, 
    /* LPI2C1_LPI2C1_SCLS_INOUT inout functionality */
    {81U, 35U, 218U, 2U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {81U, 37U, 166U, 1U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {81U, 38U, 154U, 10U, 0U}, 
    /* Inout settings for pad PORT96 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_2_G_INOUT inout functionality */
    {96U, 33U, 50U, 1U, 0U}, 
    /* LPSPI3_LPSPI3_SOUT_INOUT inout functionality */
    {96U, 34U, 254U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_16_X_INOUT inout functionality */
    {96U, 35U, 64U, 1U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {96U, 37U, 152U, 1U, 0U}, 
    /* Inout settings for pad PORT97 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_3_G_INOUT inout functionality */
    {97U, 33U, 51U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_SCK_INOUT inout functionality */
    {97U, 34U, 252U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_17_Y_INOUT inout functionality */
    {97U, 35U, 65U, 1U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {97U, 37U, 153U, 1U, 0U}, 
    /* Inout settings for pad PORT98 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_21_Y_INOUT inout functionality */
    {98U, 33U, 101U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_SOUT_INOUT inout functionality */
    {98U, 34U, 240U, 1U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {98U, 35U, 156U, 1U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {98U, 36U, 158U, 3U, 0U}, 
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {98U, 37U, 366U, 2U, 0U}, 
    /* Inout settings for pad PORT99 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_22_X_INOUT inout functionality */
    {99U, 33U, 102U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_PCS0_INOUT inout functionality */
    {99U, 34U, 232U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {99U, 35U, 157U, 2U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {99U, 36U, 159U, 3U, 0U}, 
    /* Inout settings for pad PORT100 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_23_X_INOUT inout functionality */
    {100U, 33U, 103U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {100U, 34U, 233U, 6U, 0U}, 
    /* Inout settings for pad PORT101 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_19_Y_INOUT inout functionality */
    {101U, 33U, 67U, 2U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_2_G_INOUT inout functionality */
    {101U, 34U, 50U, 4U, 0U}, 
    /* I3C0_I3C0_SDA_INOUT inout functionality */
    {101U, 35U, 372U, 2U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {101U, 37U, 167U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {101U, 38U, 222U, 5U, 0U}, 
    /* Inout settings for pad PORT102 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {102U, 33U, 155U, 9U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_12_H_INOUT inout functionality */
    {102U, 34U, 92U, 5U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {102U, 37U, 165U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {102U, 38U, 221U, 7U, 0U}, 
    /* Inout settings for pad PORT103 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {103U, 33U, 365U, 3U, 0U}, 
    /* LPSPI3_LPSPI3_PCS3_INOUT inout functionality */
    {103U, 34U, 251U, 5U, 0U}, 
    /* LPSPI0_LPSPI0_PCS3_INOUT inout functionality */
    {103U, 35U, 224U, 2U, 0U}, 
    /* QuadSPI_QuadSPI_IOFA1_INOUT inout functionality */
    {103U, 38U, 306U, 1U, 0U}, 
    /* Inout settings for pad PORT104 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SOUT_INOUT inout functionality */
    {104U, 32U, 254U, 3U, 0U}, 
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {104U, 33U, 219U, 1U, 0U}, 
    /* I3C0_I3C0_SDA_INOUT inout functionality */
    {104U, 35U, 372U, 1U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {104U, 36U, 153U, 5U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_12_H_INOUT inout functionality */
    {104U, 37U, 60U, 1U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {104U, 38U, 163U, 5U, 0U}, 
    /* Inout settings for pad PORT105 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {105U, 33U, 217U, 2U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {105U, 34U, 152U, 5U, 0U}, 
    /* I3C0_I3C0_SCL_INOUT inout functionality */
    {105U, 36U, 371U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_13_H_INOUT inout functionality */
    {105U, 37U, 61U, 2U, 0U}, 
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {105U, 38U, 162U, 4U, 0U}, 
    /* Inout settings for pad PORT106 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_16_X_INOUT inout functionality */
    {106U, 33U, 64U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_10_H_INOUT inout functionality */
    {106U, 34U, 90U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {106U, 36U, 230U, 4U, 0U}, 
    /* QuadSPI_QuadSPI_SCKFA_INOUT inout functionality */
    {106U, 38U, 309U, 1U, 0U}, 
    /* Inout settings for pad PORT107 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_17_Y_INOUT inout functionality */
    {107U, 33U, 65U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {107U, 37U, 229U, 5U, 0U}, 
    /* QuadSPI_QuadSPI_IOFA0_INOUT inout functionality */
    {107U, 38U, 305U, 1U, 0U}, 
    /* Inout settings for pad PORT108 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_18_Y_INOUT inout functionality */
    {108U, 33U, 66U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {108U, 37U, 231U, 5U, 0U}, 
    /* QuadSPI_QuadSPI_IOFA2_INOUT inout functionality */
    {108U, 38U, 307U, 1U, 0U}, 
    /* Inout settings for pad PORT111 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {111U, 32U, 158U, 7U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_0_X_INOUT inout functionality */
    {111U, 33U, 48U, 2U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_14_H_INOUT inout functionality */
    {111U, 34U, 94U, 6U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {111U, 35U, 229U, 3U, 0U}, 
    /* EMAC_EMAC_PPS2_INOUT inout functionality */
    {111U, 36U, 146U, 2U, 0U}, 
    /* SAI1_SAI1_SYNC_INOUT inout functionality */
    {111U, 37U, 325U, 1U, 0U}, 
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {111U, 38U, 162U, 1U, 0U}, 
    /* Inout settings for pad PORT112 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_1_G_INOUT inout functionality */
    {112U, 33U, 49U, 3U, 0U}, 
    /* EMAC_EMAC_MII_RMII_MDIO_INOUT inout functionality */
    {112U, 34U, 291U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {112U, 35U, 230U, 3U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_15_H_INOUT inout functionality */
    {112U, 36U, 95U, 7U, 0U}, 
    /* Inout settings for pad PORT113 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_18_Y_INOUT inout functionality */
    {113U, 33U, 66U, 3U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {113U, 36U, 248U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {113U, 37U, 161U, 1U, 0U}, 
    /* EMAC_EMAC_PPS2_INOUT inout functionality */
    {113U, 38U, 146U, 1U, 0U}, 
    /* Inout settings for pad PORT128 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {128U, 33U, 230U, 1U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {128U, 34U, 155U, 7U, 0U}, 
    /* Inout settings for pad PORT129 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {129U, 33U, 229U, 2U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {129U, 34U, 154U, 8U, 0U}, 
    /* Inout settings for pad PORT130 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {130U, 33U, 231U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_3_G_INOUT inout functionality */
    {130U, 34U, 51U, 5U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_8_X_INOUT inout functionality */
    {130U, 35U, 88U, 4U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {130U, 37U, 165U, 4U, 0U}, 
    /* Inout settings for pad PORT131 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* SAI1_SAI1_D0_INOUT inout functionality */
    {131U, 33U, 323U, 2U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_19_Y_INOUT inout functionality */
    {131U, 34U, 67U, 4U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {131U, 35U, 158U, 6U, 0U}, 
    /* EMAC_EMAC_PPS0_INOUT inout functionality */
    {131U, 37U, 144U, 1U, 0U}, 
    /* Inout settings for pad PORT134 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_PCS2_INOUT inout functionality */
    {134U, 33U, 223U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_14_H_INOUT inout functionality */
    {134U, 35U, 94U, 5U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {134U, 37U, 164U, 4U, 0U}, 
    /* Inout settings for pad PORT136 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS1_INOUT inout functionality */
    {136U, 32U, 249U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_6_G_INOUT inout functionality */
    {136U, 33U, 54U, 1U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {136U, 35U, 164U, 1U, 0U}, 
    /* SAI1_SAI1_BCLK_INOUT inout functionality */
    {136U, 37U, 322U, 1U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {136U, 38U, 160U, 5U, 0U}, 
    /* Inout settings for pad PORT137 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_0_eMIOS_0_CH_7_G_INOUT inout functionality */
    {137U, 33U, 55U, 1U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_13_H_INOUT inout functionality */
    {137U, 34U, 93U, 5U, 0U}, 
    /* EMAC_EMAC_PPS3_INOUT inout functionality */
    {137U, 36U, 147U, 1U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {137U, 38U, 163U, 1U, 0U}, 
    /* Inout settings for pad PORT138 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SIN_INOUT inout functionality */
    {138U, 33U, 253U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {138U, 34U, 242U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_20_Y_INOUT inout functionality */
    {138U, 35U, 68U, 2U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {138U, 37U, 156U, 2U, 0U}, 
    /* Inout settings for pad PORT139 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {139U, 33U, 241U, 3U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_1_G_INOUT inout functionality */
    {139U, 34U, 49U, 4U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_21_Y_INOUT inout functionality */
    {139U, 35U, 69U, 2U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {139U, 37U, 157U, 1U, 0U}, 
    /* Inout settings for pad PORT140 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {140U, 34U, 365U, 4U, 0U}, 
    /* eMIOS_1_eMIOS_1_CH_5_H_INOUT inout functionality */
    {140U, 35U, 85U, 5U, 0U}, 
    /* EMAC_EMAC_PPS3_INOUT inout functionality */
    {140U, 36U, 147U, 3U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {140U, 37U, 160U, 1U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {140U, 38U, 159U, 9U, 0U}, 
    /* Inout settings for pad PORT141 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* eMIOS_1_eMIOS_1_CH_5_H_INOUT inout functionality */
    {141U, 33U, 85U, 3U, 0U}, 
    /* LPSPI2_LPSPI2_PCS2_INOUT inout functionality */
    {141U, 34U, 243U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {141U, 36U, 241U, 5U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {141U, 37U, 157U, 5U, 0U}, 
    /* Inout settings for pad PORT143 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI2_LPSPI2_SCK_INOUT inout functionality */
    {143U, 34U, 245U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_22_X_INOUT inout functionality */
    {143U, 35U, 70U, 1U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {143U, 37U, 154U, 1U, 0U}, 
    /* Inout settings for pad PORT144 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {144U, 33U, 366U, 3U, 0U}, 
    /* LPSPI2_LPSPI2_SIN_INOUT inout functionality */
    {144U, 34U, 246U, 1U, 0U}, 
    /* eMIOS_0_eMIOS_0_CH_23_X_INOUT inout functionality */
    {144U, 35U, 71U, 2U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {144U, 37U, 155U, 2U, 0U}
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    &Port_SIUL2_0_au16PinModeAvailability
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 *const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_au16InMuxSettingsIndex
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInoutMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
