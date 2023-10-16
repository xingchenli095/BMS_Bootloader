/*********************************************************************************/
/*                                                                               */
/*                                 Sa LAYER                                      */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                  SA layer                                     */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file SA_Cbk.h                        */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.20.0 BL3 */
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

#ifndef SA_CBK_H
#define SA_CBK_H


 



/*--------------------------------{SA_CustomCalculateKey}------------------------*/
extern void SA_CustomCalculateKey(u8 * aubSeed, u8 * aubCalculatedKey);

/*--------------------------------{SA_CustomGetRandomSeed}------------------------*/
extern void SA_CustomGetRandomSeed(u8 * aubSeed);

/*--------------------------------{SA_CustomStoreAsRetryCnt}---------------------*/
extern void SA_CustomStoreAsRetryCnt(u8 RetryCntValue);

/*--------------------------------{SA_CustomRestoreAsRetryCnt}-------------------*/
extern u8 SA_CustomRestoreAsRetryCnt(void);








#endif      /* SA_CBK_H */
