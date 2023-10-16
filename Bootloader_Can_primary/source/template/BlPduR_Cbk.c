/*********************************************************************************/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                           BlPduR callbacks                                    */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BlPduR_Cbk.c                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.5.0 BL-3.X                */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/
/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: BlPduR                                                           */
#include "BlPduR_Prj.h"
#include <Base_Modules.h>   /* Module enable defines and standard config pointer names */
/*                                                                               */
/*********************************************************************************/

/****************************** PUBLIC DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */
/*                                                                               */
/*********************************************************************************/
/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/*                                                                               */
/*********************************************************************************/

/******************************** IMPLEMENTATION *********************************/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*-------------------------------------------------------------------------------*/
/* - Private Functions                                                           */

/*-------------------------------------------------------------------------------*/
/* - Public Callbacks                                                            */

/*                                                                               */
/*********************************************************************************/

/** \brief Get the Rx Pdu Identifier on which the response after reset shall be sent
 **
 ** \param[out] pubRxPduId Rx Pdu Identifier pointer
 **
 **/
void BlPduR_GetRxPduId(u8* pubRxPduId)
{
    OSC_PARAM_UNUSED(pubRxPduId);
}

/** \brief Store the Rx Pdu Identifier on which the request shall be responded after reset has been received
 **
 ** \param[in] pubRxPduId Rx Pdu Identifier
 **
 **/
void BlPduR_StoreRxPduId(u8 ubRxPduId)
{
    OSC_PARAM_UNUSED(ubRxPduId);
}


/** \brief Initialization of modules of communication stack
 **
 **/
void BlPduR_Custom_Com_Init(void)
{
#if (BLPDUR_USE_PDUR == STD_ON)
    /* If one of the ASR stack is configured initialize the PduR */
    PduR_Init(BASE_PDUR_CONFIG_PTR);
#endif
    /* Init */
#if (BLPDUR_NETWORK_FLEXRAY_SUPPORTED == STD_ON)
    /* Start FlexRay Controller */
#if (BLPDUR_USE_FR == STD_ON)
    Fr_Init(BASE_FR_CONFIG_PTR);
#endif
#if (BLPDUR_USE_FRIF == STD_ON)
    FrIf_Init(BASE_FRIF_CONFIG_PTR);
#endif
#if (BLPDUR_USE_FRTP == STD_ON)
    FrTp_Init(BASE_FRTP_CONFIG_PTR);
#endif
#if (BLPDUR_USE_FRSM == STD_ON)
    FrSM_Init(BASE_FRSM_CONFIG_PTR);
    (void)FrSM_RequestComMode(0U, COMM_FULL_COMMUNICATION);
#endif
#endif /*(BLPDUR_NETWORK_FLEXRAY_SUPPORTED == STD_ON) */

#if (BLPDUR_NETWORK_ETH_SUPPORTED == STD_ON)
#if (BLPDUR_USE_ETHTRCV == STD_ON)
    /* Start Ethernet Controller */
    EthTrcv_Init(BASE_ETHTRCV_CONFIG_PTR);
#endif
#if (BLPDUR_USE_ETH == STD_ON)
    /* Start Ethernet Controller */
    Eth_Init(BASE_ETH_CONFIG_PTR);
#endif
#if (BLPDUR_USE_ETHIF == STD_ON)
    EthIf_Init(BASE_ETHIF_CONFIG_PTR);
#endif
#if (BLPDUR_USE_ETHSM == STD_ON)
    EthSM_Init(BASE_ETHSM_CONFIG_PTR);
#else
#if (BLPDUR_USE_ETHIF == STD_ON)
#if (BLPDUR_USE_ETH == STD_ON)
    (void)EthIf_ControllerInit(0U, 0U);
    (void)EthIf_SetControllerMode(0U, ETH_MODE_ACTIVE);
#endif /* (BLPDUR_USE_ETH == STD_ON) */
#if (BLPDUR_USE_ETHTRCV == STD_ON)
    (void)EthIf_TransceiverInit(0U, 0U);
    (void)EthIf_SetTransceiverMode(0U, ETHTRCV_MODE_ACTIVE);
#endif /* (BLPDUR_USE_ETHTRCV == STD_ON) */
#endif /* (BLPDUR_USE_ETHIF == STD_ON) */
#endif /* ((BLPDUR_USE_ETHSM == STD_ON) */
#if (BLPDUR_USE_TCPIP == STD_ON)
    TcpIp_Init(BASE_TCPIP_CONFIG_PTR);
#endif
#if (BLPDUR_USE_SOAD == STD_ON)
    SoAd_Init(BASE_SOAD_CONFIG_PTR);
#endif
#if (BLPDUR_USE_DOIP == STD_ON)
    DoIP_Init(BASE_DOIP_CONFIG_PTR);
#endif
#if (BLPDUR_USE_ETHSM == STD_ON)
    (void)EthSM_RequestComMode(0U, COMM_FULL_COMMUNICATION);
#elif (BLPDUR_USE_TCPIP == STD_ON)
    (void)TcpIp_RequestComMode(0U, TCPIP_STATE_ONLINE);
#endif
#endif /*(BLPDUR_NETWORK_ETH_SUPPORTED == STD_ON) */

#if (BLPDUR_NETWORK_CAN_SUPPORTED == STD_ON)
#if (BLPDUR_USE_CAN == STD_ON)
    /* Start Can Controller */
    Can_Init(BASE_CAN_CONFIG_PTR);
#endif
#if (BLPDUR_USE_CANIF == STD_ON)
    CanIf_Init(BASE_CANIF_CONFIG_PTR);
#endif
#if (BLPDUR_USE_CANTP == STD_ON)
    CanTp_Init(BASE_CANTP_CONFIG_PTR);
#endif
#if (BLPDUR_USE_CANSM == STD_ON)
    CanSM_Init(BASE_CANSM_CONFIG_PTR);
    (void)CanSM_RequestComMode(0U, COMM_FULL_COMMUNICATION);
#endif
#endif /*(BLPDUR_NETWORK_CAN_SUPPORTED == STD_ON) */

#if (BLPDUR_NETWORK_LIN_SUPPORTED == STD_ON)
#if (BLPDUR_USE_LIN == STD_ON)
    /* Interaction Layer initialisation */
    LIL_Init ();
    /* LIN layer initialisation */
    (void)l_sys_init ();
    l_ifc_init ();
#endif
#if (BLPDUR_USE_LTP == STD_ON)
    /* LTP initialisation */
    LTP_Init ();
#endif
#endif /*(BLPDUR_NETWORK_LIN_SUPPORTED == STD_ON) */

#if (BLPDUR_USE_UDS == STD_ON)
    UDS_Init ();
#endif /*(BLPDUR_USE_UDS == STD_ON)*/


}

/** \brief Deactivate the Communication
 **
 **/
void BlPduR_Custom_Com_Deactivate(void)
{
#if (BLPDUR_NETWORK_CAN_SUPPORTED == STD_ON)
    /* Stop Can communication */
    (void)CanSM_RequestComMode(0U, COMM_NO_COMMUNICATION);
#endif
#if (BLPDUR_NETWORK_FLEXRAY_SUPPORTED == STD_ON)
    /* Stop FlexRay communication */
    (void)FrSM_RequestComMode(0U, COMM_NO_COMMUNICATION);
#endif
#if (BLPDUR_NETWORK_ETH_SUPPORTED == STD_ON)
    /* Stop Ethernet communication */
#if (BLPDUR_USE_ETHSM == STD_ON)
    (void)EthSM_RequestComMode(0U, COMM_NO_COMMUNICATION);
#else
    (void) TcpIp_RequestComMode(0U, TCPIP_STATE_OFFLINE);
#endif
#endif
#if (BLPDUR_NETWORK_LIN_SUPPORTED == STD_ON)
    /* Stop Ethernet communication */
    (void)l_ifc_disconnect ();
#endif

}
