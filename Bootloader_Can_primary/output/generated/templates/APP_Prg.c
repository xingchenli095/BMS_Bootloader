/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                APP                                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file APP_Prg.c                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.8.0 BL3                */
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

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 16.7 (advisory)
 *   A pointer parameter in a function prototype should be declared as pointer to const
 *   if the pointer is not used to modify the addressed object.
 *
 *   Reason:
 *   The MISRA rule is not violated. This pointer will be used once the function is completed by customer.
 */


/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: EB                                                            */
#include "EB_Prj.h"
#include <APP_Trace.h>                /* Dbg related macros for EB */
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

/***************************** PRIVATE DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */

/* Interrupt context */
NCS_PRI_VAR u8 m_ubItContext;

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
/* - Public Functions                                                            */

/*--------------------------{APP_InterruptEnable}--------------------------------------*/
void APP_InterruptEnable (u8 ebStatus)
{
    DBG_APP_INTERRUPTENABLE_ENTRY(ebStatus);


    /* Implement here a treatment for a critical section exit. */
    /* Interrupts must be resumed. */
    m_ubItContext = ebStatus;

    DBG_APP_INTERRUPTENABLE_EXIT();
}
/*--------------------------{end APP_InterruptEnable}----------------------------------*/

/*--------------------------{APP_InterruptDisable}--------------------------------------*/
u8 APP_InterruptDisable (void)
{
    u8 eContext = 0U;

    DBG_APP_INTERRUPTDISABLE_ENTRY();


    /* Implement here a treatment for a critical section entry. */
    /* Interrupts must be suspended. */
    eContext = m_ubItContext;

    DBG_APP_INTERRUPTDISABLE_EXIT(eContext);
    return (eContext);
}
/*--------------------------{end APP_InterruptDisable}----------------------------------*/


/*--------------------------{APP_Init}--------------------------------------*/
void APP_Init (void)
{
    DBG_APP_INIT_ENTRY();
    DBG_APP_INIT_EXIT();
}
/*--------------------------{end APP_Init}----------------------------------*/





/*--------------------------{APP_Manage}--------------------------------------*/
void APP_Manage (void)
{
    DBG_APP_MANAGE_ENTRY();
    DBG_APP_MANAGE_EXIT();
}
/*--------------------------{end APP_Manage}----------------------------------*/


/*--------------------------{CAN_BusOffInd}--------------------------------------*/
void CAN_BusOffInd (void)
{
     DBG_CAN_BUSOFFIND_ENTRY();

    /* Set CAN HW to BusOff and unlock upper layer (TP) with CAN_TxFail function */
#if (CAN_CTRL_NB>1)
    CAN_BusOff(NM_CAN_BUS_IDX);
#else
    CAN_BusOff();
#endif

    /* Set COM to BUS_OFF: CAN is desactivated */
    (void) COM_ModeModify(COM_MODE_BUS_OFF);

    /* Set COM to BUS_ON: CAN is activated */
    (void) COM_ModeModify(COM_MODE_BUS_ON);

    /* Set CAN HW to BusOn */
#if (CAN_CTRL_NB>1)
    CAN_BusOn(NM_CAN_BUS_IDX);
#else
    CAN_BusOn();
#endif

    DBG_CAN_BUSOFFIND_EXIT();
}
/*--------------------------{end CAN_BusOffInd}----------------------------------*/


/*--------------------------{UDS_P2AboutToExpireInd}--------------------------------------*/
void UDS_P2AboutToExpireInd(void)
{
    DBG_UDS_P2ABOUTTOEXPIREIND_ENTRY();
    DBG_UDS_P2ABOUTTOEXPIREIND_EXIT();
}
/*--------------------------{end UDS_P2AboutToExpireInd}----------------------------------*/


/*--------------------------{APP_ReadFingerPrint}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus APP_ReadFingerPrint(u16 *puwLen, u8 *aubUdsData)
{
    /* Define pointer to length in callback */
    /* If nothing is implemented in callback, length returned is 0 and no response is sent */
    /* By default the callback length shall be 3 (service 1 and DID 2 ) */
    *puwLen = 3U;
    OSC_PARAM_UNUSED(aubUdsData);

    return UDS_ACK;
}
/*--------------------------{end APP_ReadFingerPrint}----------------------------------*/




/*--------------------------{APP_UdsSessionStatusInd}--------------------------------------*/
void APP_UdsSessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause)
{
    DBG_APP_UDSSESSIONSTATUSIND_ENTRY(eUdsNewSessType, eUdsOldSessType, eUdsChangingCause);

    OSC_PARAM_UNUSED(eUdsOldSessType);
    OSC_PARAM_UNUSED(eUdsChangingCause);
    OSC_PARAM_UNUSED(eUdsNewSessType);

    DBG_APP_UDSSESSIONSTATUSIND_EXIT();
}
/*--------------------------{end APP_UdsSessionStatusInd}----------------------------------*/

/*--------------------------{APP_TpDataBufferEmptyInd}--------------------------------------*/
void APP_TpDataBufferEmptyInd (tTpMsgIdx uMsgIdx)
{
    DBG_APP_TPDATABUFFEREMPTYIND_ENTRY(uMsgIdx);

    OSC_PARAM_UNUSED(uMsgIdx);

    DBG_APP_TPDATABUFFEREMPTYIND_EXIT();
}
/*--------------------------{end APP_TpDataBufferEmptyInd}----------------------------------*/

/*--------------------------{APP_TpTxConf}--------------------------------------*/
void APP_TpTxConf (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    DBG_APP_TPTXCONF_ENTRY(uMsgIdx, ebStatus);

    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(ebStatus);

    DBG_APP_TPTXCONF_EXIT();
}
/*--------------------------{end APP_TpTxConf}----------------------------------*/

/*--------------------------{APP_TpRxInd}--------------------------------------*/
void APP_TpRxInd (tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    DBG_APP_TPRXIND_ENTRY(uMsgIdx, ebStatus);

    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(ebStatus);

    DBG_APP_TPRXIND_EXIT();
}
/*--------------------------{end APP_TpRxInd}----------------------------------*/

/*--------------------------{APP_TpRxEnableInd}--------------------------------------*/
void APP_TpRxEnableInd (tTpMsgIdx uMsgIdx, tTpRxEnable uRxEnable)
{
    DBG_APP_TPRXENABLEIND_ENTRY(uMsgIdx, uRxEnable);

    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(uRxEnable);

    DBG_APP_TPRXENABLEIND_EXIT();
}
/*--------------------------{end APP_TpRxEnableInd}----------------------------------*/

/*-------------------------------------------------------------------------------*/

/*--------------------------{APP_GetUdsDataBufferInd}--------------------------------------*/
/* Deviation MISRA-1 */
void APP_GetUdsDataBufferInd(u16 *uwLen, u8 *paubUdsData, tTpMsgIdx uMsgIdx, tUdsStatus eStatusRxReq)
{
    DBG_APP_GETUDSDATABUFFERIND_ENTRY(uwLen, paubUdsData, uMsgIdx, eStatusRxReq);

    OSC_PARAM_UNUSED(uwLen);
    OSC_PARAM_UNUSED(paubUdsData);
    OSC_PARAM_UNUSED(uMsgIdx);
    OSC_PARAM_UNUSED(eStatusRxReq);

    DBG_APP_GETUDSDATABUFFERIND_EXIT();
}

/*--------------------------{end APP_GetUdsDataBufferInd}----------------------------------*/

#if (CAN_WAKE_UP_DETECTION  == CAN_WAKE_UP_ACTIVATE)
/*--------------------------{APP_CanWakeUpInd}--------------------------------------*/
void APP_CanWakeUpInd (void)
{
    DBG_APP_CANWAKEUPIND_ENTRY();
    DBG_APP_CANWAKEUPIND_EXIT();
}
/*--------------------------{end APP_CanWakeUpInd}----------------------------------*/
#endif
/*--------------------------{APP_CanCtrlModeErrorInd}--------------------------------------*/
void APP_CanCtrlModeErrorInd (tCanErrors uErrorID)
{
    DBG_APP_CANCTRLMODEERRORIND_ENTRY(uErrorID);

    OSC_PARAM_UNUSED(uErrorID);

    DBG_APP_CANCTRLMODEERRORIND_EXIT();
}
/*--------------------------{end APP_CanCtrlModeErrorInd}----------------------------------*/

/*--------------------------{NCS_SdfVariableCoherencyError}--------------------------------------*/
void NCS_SdfVariableCoherencyError(u16 uwParam)
{
    DBG_NCS_SDFVARIABLECOHERENCYERROR_ENTRY(uwParam);

    OSC_PARAM_UNUSED(uwParam);
    
    DBG_NCS_SDFVARIABLECOHERENCYERROR_EXIT();
}
/*--------------------------{end NCS_SdfVariableCoherencyError}----------------------------------*/

/*--------------------------{NCS_SdfVariableRangeError}--------------------------------------*/
void NCS_SdfVariableRangeError(u16 uwParam)
{
    DBG_NCS_SDFVARIABLERANGEERROR_ENTRY(uwParam);
    
    OSC_PARAM_UNUSED(uwParam);
    
    DBG_NCS_SDFVARIABLERANGEERROR_EXIT();
}
/*--------------------------{end NCS_SdfVariableRangeError}----------------------------------*/


