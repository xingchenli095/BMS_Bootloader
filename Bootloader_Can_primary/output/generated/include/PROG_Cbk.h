/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cbk.h                      */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.51.0 BL3              */
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



#ifndef PROG_CBK_H
#define PROG_CBK_H

#if (PROG_CRY_PRESENT == STD_ON)
#include "Csm.h"
#endif /* (PROG_CRY_PRESENT == STD_ON) */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
#include "PROG_Encrypt.h"
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */

#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
extern tProgBoolean m_aubBlockDownloadStatus[PROG_SEGMENT_NB]; /* status of the logical download block downloded */
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_4)) */

/*------------------------------{PROG_SwitchApplicationModeInd}-----------------*/
extern void PROG_SwitchApplicationModeInd(void);

/*--------------------------{PROG_DisableECCCheck}------------------------------*/
extern void PROG_DisableECCCheck(void);

/*--------------------------{PROG_EnableECCCheck}-------------------------------*/
extern void PROG_EnableECCCheck(void);



/*--------------------------------{PROG_CheckProgRequest}------------------------*/
extern u8 PROG_CheckProgRequest(void);

/*--------------------------{PROG_JumpToApplication}-----------------------------*/
extern void PROG_JumpToApplication(void);
/*--------------------------------{PROG_ReturnsIsReProgRequestFromAppli}------------------------*/
extern tProgBoolean PROG_ReturnsIsReProgRequestFromAppli(void);


/*--------------------------{PROG_GetSuppressBitFromAppli}--------------------*/
extern u8 PROG_GetSuppressBitFromAppli(void);
/* PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON */

/*---------------------------{PROG_CustCheckProgPrecond}----------------------------*/
extern tProgStatus PROG_CustCheckProgPrecond(tUdsStatus * ubDiagStatus);



#ifdef NCS_UNITARY_TEST
extern void PROG_RamRead(tProgAddressType uMemAddress, tDataLength ulLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
extern void PROG_RamWrite(tProgAddressType uMemAddress, tDataLength ulLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
#endif     /* NCS_UNITARY_TEST */
/*---------------------------{PROG_CustomWriteCRC}-----------------------------*/
extern void PROG_CustomWriteCRC(u32 ulCrcVal);


/*---------------------------{PROG_CustomCoherencyCheck}-----------------------------*/
extern tProgStatus PROG_CustomCoherencyCheck(tProgCohChkResult* eCohChkResult);











 /*---------------------------{PROG_CustomSetApplicationChecksum}-----------------------------*/
extern void PROG_CustomSetApplicationChecksum(u8 * pubComputedChecksum, u16 uwBlockIdentifier);







/*---------------------------{PROG_CustomIsFirstProgramming}-----------------------------*/
extern tProgBoolean PROG_CustomIsFirstProgramming(void);

/*---------------------------{PROG_CustomDownloadNotification}-----------------------------*/
extern tProgStatus PROG_CustomDownloadNotification(u32 ulStartAddress, u32 ulMemorySize);



/*---------------------------{PROG_CustomMemoryAccessNotification}-------------------*/
extern tProgStatus PROG_CustomMemoryAccessNotification
(
    tProgMemType eMemType,
    tOperationType eOperationType,
    tProgAddressType uMemAddress,
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
);










#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
extern void PROG_CustomGetSymDecryptionKey(const u8** pubKey, u32 * pulKeyLength);
extern void PROG_CustomDecryptGetInitVector(const u8** pubInitVect, u32 * pulInitVectLength);
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */



 /*---------------------------{PROG_CustomGetDERFormat}-----------------------------*/


tProgStatus PROG_Custom_Guard_CompareKey_RD(void);
#endif     /* PROG_CBK_H */
