/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               UDS layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file UDS_Cbk.c                      */
/*%%  |                             |  %%  \brief UDS layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.8.2 BL-3.X */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2015 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "board.h"
/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

void UDS_CustomPositiveAnswerInd (const u16 *puwLen, const u8 *aubUdsData)
{
    OSC_PARAM_UNUSED(puwLen);
    OSC_PARAM_UNUSED(aubUdsData);
}


/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] pulLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
tUdsStatus APP_GetBootInfo(PduLengthType *pulLen, u8 *aubUdsData)
{
	
	/* Expected return size including SID (1) DID (2) + data [BL_version(3) + NewBL_flag(1)] */
	*pulLen = 7U;
	/* Set data representing Bootloader version*/
    /* aubUdsData[3...4] - store Bootloader version from config.mk */
	aubUdsData[3] = 0x1U;
    aubUdsData[4] = 0x0U;
    aubUdsData[5] = 0x0U;
    /* aubUdsData[6] - store New Bootloader flag = 0xEBU for testing purpose. Enabled when is created bl_container.c. */
	aubUdsData[6] = 0x00U;
    /* aubUdsData[6] = 0xEBU;*/
	
	return UDS_ACK;
}