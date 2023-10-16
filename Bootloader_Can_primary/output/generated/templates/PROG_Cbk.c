/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cbk.c                      */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.51.0 BL3 */
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
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "board.h"

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */


/** \brief API that check if a programming request has been received by the application
 **
 ** Callback is called: at Bootloader startup to know if a programming request has
 **                     been received in Application
 **
 ** Callback shall implement: get information from application if a programming
 **                          request has been received (e.g: read a flag from
 **                          noinit RAM shared between Bootloader and
 **                           Application)
 **
 ** \return Result of check
 ** \retval PROG_BOOT_REPROG Reprogramming request has been received
 ** \retval PROG_BOOT_NO_REPROG No reprogramming request received
 **/
u8 PROG_CheckProgRequest(void)
{
    return 0U;
}

/** \brief Callback performing jump to application software
 **
 ** Callback is called: at Bootloader startup if application is valid and shall
 **                    be executed
 **
 ** Callback shall implement: jump to application start address
 **
 **/
void PROG_JumpToApplication(void)
{

}

/** \brief API that returns information if a programming request has been received by the application
 **
 ** Callback is called: at reception of a request in BlPduR module to ignore the request if Rx simulation  
 **                           request is ongoing (programming request has been received by the application)
 **
 ** Callback shall implement: returns information from application if a programming
 **                          request has been received or not (e.g: from PROG_CheckProgRequest API)
 **
 ** \return Information checked in PROG_CheckProgRequest API
 ** \retval TRUE Reprogramming request has been received in Application
 ** \retval FALSE Reprogramming request has not been received in Application
 **/
tProgBoolean PROG_ReturnsIsReProgRequestFromAppli(void)
{
    return FALSE;
}


/** \brief Callback that shall disable ECC if needed
 ** Callback is called: When Bootloader perform read access on Flash that can be
 **                     unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, disabling of ECC check
 **                           Hardware specific)
 **/
void PROG_DisableECCCheck(void)
{

}


/** \brief Callback that shall enable ECC if needed
 ** Callback is called: After Bootloader has performed a read access on Flash
 **                    that can be unprogrammed and can cause ECC error
 **
 ** Callback shall implement: If needed, enabling of ECC check
 **                          (Hardware specific)
 **/
void PROG_EnableECCCheck(void)
{

}





/*------------------------------{PROG_CustomSetOpenProgSession}---------------------------*/



/** \brief Called before Bootloader perform a jump to application
 **
 ** Callback is called: Before jumping to Application
 **
 **  Callback shall implement: customer code that shall be executed before
 **  jumping to application
 **/
void PROG_SwitchApplicationModeInd(void)
{

}




/** \brief Get the status of the suppress positive response bit from the last reprogramming request in application
 **
 ** Callback is called: At startup when Bootloader shall send a response to a request that
 **                     has been received in application
 **
 ** Callback shall implement: get from application information if the
 **                          suppressPositiveResponse bit was set in the
 **                           received request (e.g: read a flag from noinit RAM
 **                           shared between Bootloader and  Application)
 **
 ** \return Suppression bit value
 ** \retval TRUE The suppress positive response bit was set (response will not be sent)
 ** \retval FALSE The suppress positive response bit was not set (response will be sent)
 **/
u8 PROG_GetSuppressBitFromAppli(void)
{
    return FALSE;
}


/** \brief Check if all the programming pre-conditions are met
 **
 ** Callback is called: On Programming precondition check
 **
 ** Callback shall implement: programming precondition check. Inform Bootloader
 **                           if the ECU is in a state where programming can be
 **                           performed. It shall check for the error condition Security access 
 **                           if locked and update error list (m_aubPreProgErrorList).
 **                           If condition are not correct programming will be rejected by Bootloader 
 **                           and negative response will be sent on the network.
 **
 ** \return state
 ** \retval PROG_E_OK All the programming pre-conditions are met
 ** \retval PROG_E_NOT_OK At least one programming pre-condition is NOT met
 **
 **/
tProgStatus PROG_CustCheckProgPrecond(tUdsStatus * ubDiagStatus)
{
    tProgStatus eProgStatus = PROG_E_OK;
    OSC_PARAM_UNUSED(ubDiagStatus);
    return eProgStatus;
}



/** \brief Callback for CRC storage
 **
 ** Callback is called: After CRC calculation
 **
 ** Callback shall implement: storage of the CRC value for further use
 **
 ** \param[in] ulCrcVal CRC value
 **
 **/
void PROG_CustomWriteCRC(u32 ulCrcVal)
{
    OSC_PARAM_UNUSED(ulCrcVal);
}


/** \brief This API is called  to do the coherency check treatment
 **
 ** Callback is called: on the coherency check request reception
 **
 ** Callback shall implement: the algorithm performing the coherency check of the previously programmed blocks (E.g.: checking of blocks versions compatibility).
 **
 ** \param[out] eCohChkResult The result of the coherency check.
 **             Can be: 0-correct, 1-incorrect, 2-incorrect error SW-HW, 3-incorrect error SW-SW, 4-incorrect other error
 **
 ** \return Coherency Check result
 ** \retval PROG_E_OK when the check has finished
 ** \retval PROG_E_BUSY if the check is on going
 **/
tProgStatus PROG_CustomCoherencyCheck(tProgCohChkResult* eCohChkResult)
{
    OSC_PARAM_UNUSED(eCohChkResult);
    return PROG_E_OK;
}










/** \brief This API is called to store the computed Application checksum in non-volatile memory
 **
 ** Callback is called:  Before sending response to CheckMemory request for authenticated block
 **
 ** Callback shall implement: store in non-volatile memory the Application checksum (will be
 ** compare at next startup with one calculated by application). It shall also update the checksum
 ** computed by application.
 **
 ** \param[in] pubComputedChecksum Pointer to Application checksum to store.
 ** \param[in] uwBlockIdentifier Block Identifier.
 **
 **/
void PROG_CustomSetApplicationChecksum(u8 * pubComputedChecksum, u16 uwBlockIdentifier)
{
    OSC_PARAM_UNUSED(pubComputedChecksum);
    OSC_PARAM_UNUSED(uwBlockIdentifier);
}






/** \brief Notification of a download event
 **
 ** Callback is called: On reception of RequestDownload routine
 **
 ** Callback shall implement: provide information that the Flash Memory was programmed and should be erased before a new writing and customer specific implementation on download event
 **
 ** \param[in] ulStartAddress received start address value
 ** \param[in] ulMemorySize received memory size value
 **
 ** \return eProgStatus success of the operation
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomDownloadNotification(u32 ulStartAddress, u32 ulMemorySize)
{
    OSC_PARAM_UNUSED(ulStartAddress);
    OSC_PARAM_UNUSED(ulMemorySize);
    return PROG_E_OK;
}



/** \brief Get the status of the Flash memory if it's full erased or not (i.e first download on this ECU)
 **
 ** Callback is called: On reception of Erase routine to skip erasing if memory has never been written
 **
 ** Callback shall implement: provide information if this is the first Flash programming
 **
 ** \return eIsFirstProgramming status return by the function (PROG_TRUE / PROG_FALSE)
 **/
tProgBoolean PROG_CustomIsFirstProgramming(void)
{
    return PROG_FALSE;
}

/** \brief Notification of memory access to allow customers to place their routines
 **
 ** Callback is called: After successful memory data access
 **
 ** Callback shall implement: Operation that need to be performed after a memory data access
 **
 ** \param[in] eMemType Memory type (RAM, Flash and Flash Ext)
 ** \param[in] eOperationType Operation type (Read, write and erase)
 ** \param[in] uMemAddress Start address
 ** \param[in] ulLength Data length
 ** \param[in] paubDataBuffer Data buffer
 **
 ** \return eProgStatus success of the operation(s)
 ** \retval PROG_E_OK
 ** \retval PROG_E_NOT_OK
 **/
tProgStatus PROG_CustomMemoryAccessNotification
(
    tProgMemType eMemType,
    tOperationType eOperationType,
    tProgAddressType uMemAddress,
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
)
{
    OSC_PARAM_UNUSED(eMemType);
    OSC_PARAM_UNUSED(eOperationType);
    OSC_PARAM_UNUSED(uMemAddress);
    OSC_PARAM_UNUSED(ulLength);
    OSC_PARAM_UNUSED(paubDataBuffer);

    return PROG_E_OK;
}

















/** \brief API that check whether the transition is allowed from the compare key to RD
 **
 ** Callback is called: at Bootloader before starting RD to know if the transition to RD is allowed
 **
 ** Callback shall implement: get information from Bootloader if a compare key
 **                          request has been received and completed successfully and also if needed integrator can
 **                          perform any prechecks before trainsition to RD.
 **
 ** \return Result of check
 ** \retval PROG_E_OK If Transition to RD is allowed
 ** \retval PROG_E_NOT_OK If Transition to RD is not allowed
 **/
tProgStatus PROG_Custom_Guard_CompareKey_RD(void)
{
  /*Transition is accepted*/
  return PROG_E_OK;
}
