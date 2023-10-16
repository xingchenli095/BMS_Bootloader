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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.27.0 BL3                */
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


/** \brief Initialization of modules of communication stack and initialization of the stored PDUID of the active connection
 **
 **/
void BlPduR_Custom_Com_Init(void)
{
#ifndef PLATFORMS_STUBS_ENABLED
    if (PLATFORMS_SW_RESET != BoardGetResetType())
    {
        /* If it is not a Software reset then initialize the stored PDU ID to invalid to start a new connection later*/
        BlPduR_StoreRxPduId(BLPDUR_INVALID_PDU);
    }
#endif
}

/** \brief Deactivate the Communication
 **
 **/
void BlPduR_Custom_Com_Deactivate(void)
{

}
