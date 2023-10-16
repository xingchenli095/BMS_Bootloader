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
/*%%   _____________________________   %%  \file EBTesting_Prg.c                 */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.6.255 OSC_BOOT                */
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
#include "board.h"
/*                                                                               */
/*********************************************************************************/

/****************************** PUBLIC DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
tProgCohChkResult m_eCohChkResult = PROG_E_COHCHK_CORRECT;
tProgStatus m_eCohChkCProgStatus = PROG_E_OK;

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


/*--------------------------{UDS_EbTestingWriteDataByIdentifier}--------------------------------------*/
/* Deviation MISRA-1 */
tUdsStatus UDS_EbTestingWriteDataByIdentifier(u16 *puwLen, u8 *aubUdsData)
{

  u8 eUdsStatus;
  u16 uwDataIdentifier;

  uwDataIdentifier = (u16)((u16)((u16)aubUdsData[1] << 8U) & 0xFF00U);
  uwDataIdentifier |= (u16)((u16)aubUdsData[2] & 0x00FFU);

  /* Set positive response */
  eUdsStatus = UDS_ACK;

  switch(uwDataIdentifier)
  {
      case 0xEB01:
          /*EB Test DID for Coherency Check
          aubUdsData[3] - callback stubbed return status 
                        - range: PROG_E_OK(0),
                                 PROG_E_BUSY(1)
          aubUdsData[4] - stubbed coherency check result
                        - range: PROG_E_COHCHK_CORRECT(0),
                                 PROG_E_COHCHK_INCORRECT(1),
                                 PROG_E_COHCHK_INCORRECT_SW_HW(2),
                                 PROG_E_COHCHK_INCORRECT_SW_SW(3),
                                 PROG_E_COHCHK_INCORRECT_OTHER(4)
          */
          m_eCohChkCProgStatus = aubUdsData[3];
          m_eCohChkResult = aubUdsData[4];
          eUdsStatus = UDS_ACK;
          break;
      default:
          eUdsStatus = UDS_NRC_31;
          break;
  }

  if(eUdsStatus == UDS_ACK)
  {

      *puwLen = 3U;
  }

  return eUdsStatus;
}
/*--------------------------{end UDS_EbTestingWriteDataByIdentifier}----------------------------------*/