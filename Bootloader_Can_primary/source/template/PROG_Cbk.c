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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.9.0 BL-3.X */
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
#include "Target_Specific_Definition.h"

#define PROG_REPROG_REQUESTED  0x55AA55AAU
#define PROG_SIG_CLEAR 0x0U

NCS_PRI_VAR ptAPPL_START_ADDR pAPPL_START_ADDR;

#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
tNoIntShareVar stNoIntShareVar;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

#define PROG_START_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>
u32 m_ulApplValid;
#define PROG_STOP_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>

const u8 m_aubDecryptInitVector[16U] =
    {
        0x45, 0x62, 0x65, 0x62, 0x65, 0x62, 0x65, 0x62,
        0x65, 0x62, 0x65, 0x62, 0x65, 0x62, 0x65, 0x42
    };

const u8 m_aubDecryptionKey[16U] =
    {
        0x42, 0x65, 0x62, 0x74, 0x69, 0x62, 0x6f, 0x72, 
		0x74, 0x6b, 0x65, 0x6c, 0x65, 0x62, 0x65, 0x45
    };


/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */
/* Decl. for Demo DER encoding of the Signature Public key */
void Demo_CommonDerHeaderSequence(u8* HeaderBuffer,u32 PayloadLength);
u32 Demo_CommonDerLengthEncoding(u8* LengthEncodingBuffer,u32 PayloadLength);
/*DER encoding constants and encoding parameters*/
#ifndef CRYPTO_AL_DER_SEQUENCE_TAG
#define CRYPTO_AL_DER_SEQUENCE_TAG 0x30U
#endif
#ifndef CRYPTO_AL_DER_INTEGER_TAG
#define CRYPTO_AL_DER_INTEGER_TAG 0x02U
#endif
/*Length of the Public key Exponent used for the Signature verification*/
#define DEMO_ASYMPUBLICKEY_EXPO_LENGTH 0x04U

/*Payload length is currently set 1Byte as encoding steps are done in demo step by step*/
#define DEMO_DER_PAYLOAD_LENGTH 0x01U
#define DEMO_DER_PAYLOAD_LENGTH_VALUE 0x7FU
u8 m_aubAsymPublicKeyreorg[776U]={0U};
/** \brief API that check if a programming request has been received by the application
 **
 ** Callback is called: at Bootloader startup to know if a programing request has
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
    u8 ubRetVal = PROG_BOOT_NOREPROG;

    /* Check if the signature is set */
    if (stNoIntShareVar.ulProgSig == PROG_REPROG_REQUESTED)
    {
        /* comming from application must stay in boot */
        ubRetVal = PROG_BOOT_REPROG;
    }
    else
    {
        /* Prog signature is clear must jump in application after tested it */
    }

    /* Clear the prog signature*/
    stNoIntShareVar.ulProgSig = PROG_SIG_CLEAR;

    return ubRetVal;
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
    pAPPL_START_ADDR = (ptAPPL_START_ADDR)APP_START_ADDR;
    
	/* (Cortex-M processors) support only the Thumb instruction set. 
	    Therefore jump address should be indicated as odd numbers, 
		having bit[0] set indicating that the target contains a Thumb opcode 
	
	Example: If the value in branch instruction, lr is 0x02000001 then 
	         the processor will branch to address 0x02000000 but interpret 
			 the instruction found there as a Thumb opcode.*/
	
	pAPPL_START_ADDR = ((u32)pAPPL_START_ADDR | 0x1U);
	
	/* Jump in application */
    pAPPL_START_ADDR();
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
 ** \retval FALSE Reprogramming request has been received in Application
 **/
tProgBoolean PROG_ReturnsIsReProgRequestFromAppli(void)
{
    return FALSE;
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

/** \brief This API is called  to do the coherency check treatment
 **
 ** Callback is called: on the coherency check request reception
 **
 ** Callback shall implement: the algorithm performing the coherency check of the previously programmed blocks (E.g.: checking of blocks verions compatibility).
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

/** \brief Check if all the programming pre-conditions are met
 **
 ** Callback is called: On Programming precondition check
 **
 ** Callback shall implement: programming precondition check. Inform Bootloader
 **                           if the ECU is in a state where programming can be
 **                           performed. If condition are not correct programming
 **                           will be rejected by Bootloader and negative response
 **                           will be sent on the network.
 **
 ** \return state
 ** \retval PROG_E_OK All the programming pre-conditions are met
 ** \retval PROG_E_NOT_OK At least one programming pre-condition is NOT met
 **
 **/
tProgStatus PROG_CustCheckProgPrecond(tUdsStatus * ubDiagStatus)
{
    OSC_PARAM_UNUSED(ubDiagStatus);
    tProgStatus eProgStatus = PROG_E_OK;
    return eProgStatus;
}

#if ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_APPLI_CHECK_ALGO_EB == STD_OFF))
/** \brief Callback called after comparing the expected CRC and the calculated one.
 **
 ** Callback is called: After a successful or unsuccessful CRC verification
 **
 ** Callback shall implement: update of the logical block validity status
 **
 ** \param[in] ubLogicalBlockId The id of the logical block for which the compare was done
 ** \param[in] ubLogicalSegmentId The id of the logical segment  for which the compare was done
 **            (ignore if CRC is computed on the full logical block)
 ** \param[in] ubCompareSuccess TRUE if the 2 elements of the comparison are identical
 **
 **/
tProgStatus PROG_CustomSetDownloadVerificationSuccess(u8 ubLogicalBlockId, u8 ubLogicalSegmentId, tProgBoolean ubCompareSuccess)
{
    tProgStatus eProgStatus = PROG_E_OK;

    OSC_PARAM_UNUSED(ubLogicalBlockId);
    OSC_PARAM_UNUSED(ubLogicalSegmentId);

    if(PROG_TRUE == ubCompareSuccess)
    {
        m_ulApplValid = 0xAA55AA55U;
    }
    else
    {
        /*do nothing, application not valid*/
    }
    
    return eProgStatus; 
}

/** \brief Callback checking if the application is valid or not
 **
 ** Callback is called: at startup and on some routine.
 **
 ** Callback shall implement: It shall verify that the application
 ** with all its dependencies are correctly flashed
 ** and return the result of the check
 **
 ** \return Result of check
 ** \retval TRUE Application is valid
 ** \retval FALSE Application is not valid or not present
 **/

tProgBoolean PROG_IsValidApplication(void)
{
    tProgBoolean u8bIsValidApp;
    /*update return f(m_ulApplValid)*/
    if(0xAA55AA55 == m_ulApplValid)
    {
      u8bIsValidApp = TRUE;
    }
    else
    {
      u8bIsValidApp = FALSE;
    }
    return u8bIsValidApp;
}

#endif

/** \cond **/
/** \endcond **/
/** \brief Start the Fingerprint Writing
 **
 ** Callback is called: On reception of WriteDataByIdentifier service for Fingerprint
 **                     DID
 **
 ** Callback shall implement:
 **
 **                           1- Check the validity of FingerPrint data
 **
 **                           2- the writing in non-volatile memory of the
 **                            Fingerprint data (pubRamBuffer points on the
 **                            dataIdentifier field of the WriteDataByIdentifier
 **                            request)
 **                            Asynchronous management can be implemented, in this case
 **                            PROG_E_BUSY value is returned and further call to
 **                            PROG_CustomGetWriteFingerprintStatus will allow
 **                            Bootloader to get writing status
 **
 ** \param[in] pubRamBuffer pointer to a RAM buffer where the DID identifier and fingerprint data
**                          are located
 **
 ** \return Result
 ** \retval PROG_E_OK Write Fingerprint ok
 ** \retval PROG_E_NOT_OK Write Fingerprint failed
 ** \retval PROG_E_BUSY Write Fingerprint in progress
 **/
tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer)
{
    tProgStatus eProgStatus = PROG_E_OK;
    OSC_PARAM_UNUSED(pubRamBuffer);
    return eProgStatus;
}

/** \brief Get the status of the fingerprint writing
 **
 ** Callback is called: After PROG_CustomWriteFingerprint returns PROG_E_BUSY, this
 **                     callback is called periodically until getting a status
 **                     different from PROG_E_BUSY
 **
 ** Callback shall implement: provide status of the fingerprint writing
 **
 ** \return Result
 ** \retval PROG_E_OK Write Fingerprint ok
 ** \retval PROG_E_NOT_OK Write Fingerprint failed
 ** \retval PROG_E_BUSY Write Fingerprint in progress
 **/
tProgStatus PROG_CustomGetWriteFingerprintStatus(void)
{
    tProgStatus eProgStatus = PROG_E_OK;
    return eProgStatus;
}


/*
Modulus: a6754738bdf94dbc846ceb937a3896e747d5c6222453a83f6c86310e5819129613f9857d5e4a06bc5d927bdb011d23d8219549ced82c20592bdc419deb67fe43da87fcdfd01ac1acb07e513170c45d1e058fb56d8cb090a7f2565381785c4478362b253d47e056053516be15f448878d01c9dac06be45957882ccffc5ddaf06bc131c866349668de950e9121b134e5ae1c29815473a20028b9b7ea64d9dd8253a518b766dea714f7b37185a1d707a21cfa526a7d76f55119af728626b77e5b66328c2b37ec78be56380a4cd3900fe6a757f21b5728d31e5f1344aca933042b99240f89dc09e76a03678b402780bf64813c339e79893a3355674ff4807b200775
Public exponent: 00a54611
*/

const u32 m_ulPublicExponent = 0x00010001UL;

const u8 m_aubPublicModulus[PROG_KEY_LENGTH] =
    {
        0xBF, 0xE4, 0xB1, 0xDD, 0x88, 0xBC, 0xF8, 0xA4,
0xCE, 0x35, 0xE1, 0xB2, 0x52, 0x1F, 0x33, 0xD3,
0x1B, 0x53, 0x1B, 0x03, 0x82, 0x8D, 0x69, 0x0A,
0x86, 0xAC, 0xD5, 0x24, 0x79, 0x0C, 0x62, 0xD2,
0x70, 0xA6, 0x78, 0x08, 0x2E, 0xFF, 0x53, 0x86,
0xEE, 0xC7, 0x65, 0xE6, 0xB4, 0x20, 0x0D, 0xAE,
0x62, 0x4C, 0x41, 0x23, 0x52, 0xBD, 0xB8, 0x3B,
0x92, 0x1C, 0xFF, 0x64, 0xE9, 0x25, 0x2A, 0x93,
0x4F, 0xED, 0xED, 0x97, 0x3D, 0x0D, 0x85, 0xD0,
0x85, 0x4A, 0xA7, 0x8B, 0x37, 0x68, 0x48, 0x67,
0xBB, 0xA7, 0x54, 0xCE, 0x6D, 0x04, 0x52, 0xE9,
0xD9, 0x44, 0xB7, 0x1E, 0xAA, 0xD2, 0x1F, 0xCE,
0x24, 0xC6, 0xCF, 0x35, 0x95, 0x40, 0x8F, 0x89,
0x0A, 0x99, 0x13, 0x59, 0x78, 0xCB, 0x34, 0x18,
0x48, 0xE1, 0xCC, 0x1D, 0x92, 0x1A, 0x97, 0x5F,
0x77, 0xE0, 0x38, 0xD7, 0x92, 0x0D, 0x79, 0x85,
0xAF, 0x9A, 0xAA, 0x1B, 0x8D, 0x55, 0xC7, 0xD9,
0x66, 0x15, 0x72, 0x23, 0x4F, 0x56, 0x8C, 0x80,
0x36, 0x15, 0xF3, 0x33, 0x0A, 0x5B, 0x7F, 0x96,
0xC8, 0x36, 0x49, 0xF4, 0x2A, 0xA2, 0xB1, 0x0F,
0xC3, 0xB0, 0x60, 0xC4, 0xFD, 0xE3, 0xE2, 0x39,
0x1C, 0x78, 0xC3, 0x1F, 0xB3, 0x40, 0x58, 0x76,
0xAF, 0x97, 0x30, 0x3C, 0x53, 0x5E, 0xAE, 0x7C,
0x71, 0x63, 0x25, 0xAE, 0x94, 0x84, 0x3D, 0x5C,
0xB1, 0x88, 0x26, 0x95, 0x4B, 0xD1, 0xC9, 0x1A,
0xE9, 0x99, 0x9A, 0x4E, 0xFE, 0x30, 0x2D, 0xC3,
0x6E, 0xBD, 0xC1, 0xF4, 0x9D, 0xEA, 0x97, 0xE8,
0x73, 0x58, 0xC3, 0x31, 0x27, 0x08, 0x42, 0x69,
0xFD, 0xAE, 0x5D, 0x04, 0xC5, 0x96, 0x64, 0xFC,
0xAC, 0x9E, 0xF0, 0xAA, 0x8B, 0x02, 0xB1, 0x30,
0xB6, 0xD1, 0xF3, 0xF4, 0x07, 0xE1, 0xC0, 0xF3,
0xA7, 0x1C, 0xB8, 0x0D, 0xEF, 0x94, 0x9E, 0x11 
    };

/** \brief Get the public key modulus and exponent when using asymmetric cryptography. Used in SA_InitCrypto
 **
 ** \param[out] paubPublicModulus Public modulus array.
 ** \param[out] pulPublicExponent Public exponent value.
 **
 **/
/*---------------------------{PROG_CustomGetAsymPublicKey}-----------------------------*/
void PROG_CustomGetAsymPublicKey(const u8** paubPublicModulus, u32* pulPublicExponent)
{
    *paubPublicModulus = m_aubPublicModulus;
    *pulPublicExponent = m_ulPublicExponent;
}
/*------------------------{end PROG_CustomGetAsymPublicKey}--------------------------*/



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
 ** \param[in] uLength Data length
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
    tDataLength uLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
)
{
    OSC_PARAM_UNUSED(eMemType);
    OSC_PARAM_UNUSED(eOperationType);
    OSC_PARAM_UNUSED(uMemAddress);
    OSC_PARAM_UNUSED(uLength);
    OSC_PARAM_UNUSED(paubDataBuffer);
    
    return PROG_E_OK;
}

tProgStatus PROG_InvalidateSection_BlockID(u8 ubBlockId)
{


    return PROG_E_OK;
}


/** \brief Callback that shall request data decryption before writing them to memory
 ** Callback is called: receiving a TransferData before the decompression (if activated)
 **
 ** Callback shall implement: If needed, it shall decrypt the received data according to the EncryptingMethod.
 **
 ** \param[in] ubEncryptionMethod Encrypting method  indicator (from RequestDownload dataFormatIdentifier field)
 ** \param[in,out] pubData received data pointer (points to the encrypted data and callback implementation shall copy decrypted data at the same location than the encrypted one.)
 ** \param[in] DataLength received data length
 **
 ** \return Result of the decryption
 ** \retval PROG_E_OK Decryption finish successfully
 ** \retval PROG_E_NOT_OK Error happened during decryption
 **/
tProgStatus PROG_CustomDecryptData(u8 ubEncryptionMethod, u8 * pubData, u16 DataLength)
{
    OSC_PARAM_UNUSED(ubEncryptionMethod);
    OSC_PARAM_UNUSED(pubData);
    OSC_PARAM_UNUSED(DataLength);

    return PROG_E_OK;
}

void PROG_CustomDecryptGetInitVector(const u8** pubInitVect, u32 * pulInitVectLength)
{
  *pulInitVectLength = 16; /*CSM_SYM_KEY_MAX_SIZE*/
  *pubInitVect       = &m_aubDecryptInitVector[0U];
}

/** \brief Get symetrical decryption key and its length
 **
 ** \param[out] pubKey pointer to key array location
 ** \param[out] pointer to key length location
 **
 ** Callback shall implement: Retrieve the symetrical decryption key and its length
 **
 **/
void PROG_CustomGetSymDecryptionKey(const u8** pubKey, u32 * pulKeyLength)
{
  *pulKeyLength = 16;/*CSM_SYM_KEY_MAX_SIZE*/
  *pubKey       = &m_aubDecryptionKey[0];
}

/*DER Encoding for the non-DER encoded public keys*/
void Demo_CommonDerHeaderSequence(u8* HeaderBuffer,u32 PayloadLength)
{
   u32 ulHeaderLength;

   HeaderBuffer[0U] = CRYPTO_AL_DER_SEQUENCE_TAG;

   ulHeaderLength = Demo_CommonDerLengthEncoding((u8 *)&HeaderBuffer[1U], PayloadLength);
}

u32 Demo_CommonDerLengthEncoding(u8* LengthEncodingBuffer,u32 PayloadLength)
{
  u32 ulLengthEncodingLength;

  if(PayloadLength <= DEMO_DER_PAYLOAD_LENGTH_VALUE)
  {
     LengthEncodingBuffer[0u] = (u8)PayloadLength;
     ulLengthEncodingLength = 1u;
  }
  else
  {
    /* Values greater than 0x7f need a control byte */
    u32 ulnumberOfBytes = 0u;
    u32 ulLocPayloadLength = PayloadLength;
    u32 ulCurPos = 0u;
    while (ulLocPayloadLength != 0u)
    {
      ulLocPayloadLength >>= 8u;
      ulnumberOfBytes++;
    }
    LengthEncodingBuffer[0u] = (u8) 0x80u | (u8) ulnumberOfBytes;
    /* Encode the length with big endian byte order */
    for (ulCurPos = 1u; ulCurPos <= ulnumberOfBytes; ulCurPos++)
    {
      LengthEncodingBuffer[ulCurPos] = (u8)(PayloadLength >> (8u * (ulnumberOfBytes - ulCurPos)));
    }
    ulLengthEncodingLength = 1u + ulnumberOfBytes;
  }

  return ulLengthEncodingLength;
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
