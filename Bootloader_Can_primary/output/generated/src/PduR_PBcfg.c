


/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <PduR_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_NAME PduR_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE PduR_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <PduR_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
PduR_ConstConfigLayoutType PduR_ConfigLayout = {
    { /* PduR_RootConfig */
        UINT32_C( 2147485970 ), /* PduR_PlatformSignature */
        UINT32_C( 3287920854 ), /* PduR_PublicInfoSignature */
        UINT32_C( 3945551040 ), /* PduR_CfgSignature */
        UINT32_C( 3958107115 ), /* PduR_LcfgSignature */
        TS_MAKENULLREF2CFG, /* PduR_BufDefaultRef */
        TS_MAKENULLREF2CFG, /* PduR_BufSbConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufDfConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTfConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufSbDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufDfDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTfDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTpConfigRef */
        { /* PduR_MTabLoIfConfig */
            TS_MAKENULLREF2CFG, /* MTabRxRef */
            UINT16_C( 0 ) /* MTabRxCount */
        },
        { /* PduR_MTabUpIfConfig */
            TS_MAKENULLREF2CFG, /* MTabTxRef */
            UINT16_C( 0 ) /* MTabTxCount */
        },
        { /* PduR_MTabUpTpConfig */
            TS_MAKENULLREF2CFG, /* MTabTxRef */
            UINT16_C( 0 ) /* MTabTxCount */
        },
        { /* PduR_GTabIfConfig */
            TS_MAKENULLREF2CFG, /* GTabRxRef */
            UINT16_C( 0 ) /* GTabRxCount */
        },
        { /* PduR_GTabTpConfig */
            TS_MAKENULLREF2CFG, /* GTabRxRef */
            TS_MAKENULLREF2CFG, /* GTabTxRef */
            TS_MAKENULLREF2CFG, /* GTabTpApiRef */
            UINT16_C( 0 ), /* GTabRxCount */
            UINT16_C( 0 ) /* GTabTxCount */
        },
        { /* PduR_Nto1TabTpConfig */
            TS_MAKENULLREF2CFG, /* Nto1TabTpRef */
            UINT16_C( 0 ) /* Nto1TabTpCount */
        },
        { /* PduR_RTabLoTpConfig */
            { /* PduR_RTabLoTpConfig[0] -- CanTp */
                TS_MAKEREF2CFG( PduR_RTabLoTpRx[0] ), /* RTabRxRef */
                TS_MAKEREF2CFG( PduR_RTabLoTpTx[0] ), /* RTabTxRef */
                UINT16_C( 2 ), /* RTabRxCount */
                UINT16_C( 1 ) /* RTabTxCount */
            }
        },
        { /* PduR_RTabUpTpConfig */
            { /* PduR_RTabUpTpConfig[0] -- BlPduR */
                TS_MAKEREF2CFG( PduR_RTabUpTpTx[0] ), /* RTabTxRef */
                TS_MAKENULLREF2CFG, /* RTabRxRef */
                UINT16_C( 1 ), /* RTabTxCount */
                UINT16_C( 0 ) /* RTabRxCount */
            }
        },
        UINT16_C( 0 ), /* PduR_ConfigurationId */
        UINT16_C( 0 ), /* PduR_BufSbCount */
        UINT16_C( 0 ), /* PduR_BufDfCount */
        UINT16_C( 0 ), /* PduR_BufTfCount */
        UINT16_C( 0 ), /* PduR_BufSbDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufDfDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufTfDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufTpCount */
        UINT16_C( 0 ), /* PduR_MultiTpTxSessionInfoRef */
        UINT16_C( 0 ), /* PduR_MultiIfTxInfoRef */
        UINT16_C( 0 ), /* PduR_BufSbDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_BufDfInfoRef */
        UINT16_C( 0 ), /* PduR_BufDfDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_BufTfInfoRef */
        UINT16_C( 0 ), /* PduR_BufTfDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_GateTpSessionInfoRef */
        UINT8_C( 0 ) /* PduR_MultiTpTxRPathsMax */
    },
    { /* PduR_RTabLoTpRx */
        { /* PduR_RTabLoTpRx[0] -- Routing path:'Pdu_Rx_Func_Group_0', calling module:'CanTp-LO-TP', PDU ID:0 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- BlPduR */
        },
        { /* PduR_RTabLoTpRx[1] -- Routing path:'Pdu_Rx_Phys_Group_0', calling module:'CanTp-LO-TP', PDU ID:1 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- BlPduR */
        }
    },
    { /* PduR_RTabLoTpTx */
        { /* PduR_RTabLoTpTx[0] -- Routing path:'Pdu_Tx_Group_0', calling module:'CanTp-LO-TP', PDU ID:0 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- BlPduR */
        }
    },
    { /* PduR_RTabUpTpTx */
        { /* PduR_RTabUpTpTx[0] -- Routing path:'Pdu_Tx_Group_0', calling module:'BlPduR-UP-TP', PDU ID:0 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- CanTp */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

