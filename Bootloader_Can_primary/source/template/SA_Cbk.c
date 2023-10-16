/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               SA layer                                        */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file SA_Cbk.c                        */
/*%%  |                             |  %%  \brief SA layer source plugin file    */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.0.255 OSC_BOOT */
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
/*--------------------------------{SA_CustomCalculateKey}------------------------*/
void SA_CustomCalculateKey(u8 * aubSeed, u8 * m_aubCalculatedKey)
{
  OSC_PARAM_UNUSED(aubSeed);
  m_aubCalculatedKey[0] = 0x01;
  m_aubCalculatedKey[1] = 0x02;
  m_aubCalculatedKey[2] = 0x03;
  m_aubCalculatedKey[3] = 0x04;
}
/*------------------------------{end SA_CustomCalculateKey}----------------------*/

/*--------------------------------{SA_CustomStoreAsRetryCnt}---------------------*/
#if (SA_ANTISCANNING_ENABLED == STD_ON) 
void SA_CustomStoreAsRetryCnt(u8 RetryCntValue)
{
    OSC_PARAM_UNUSED(RetryCntValue);
}
#endif /*(PROG_SA_ANTISCANNING_ENABLE == STD_ON)*/
/*------------------------------{end SA_CustomStoreAsRetryCnt}-------------------*/

/*--------------------------------{SA_CustomRestoreAsRetryCnt}-------------------*/
#if (SA_ANTISCANNING_ENABLED == STD_ON) 
u8 SA_CustomRestoreAsRetryCnt(void)
{
    u8 RetAsRetryCnt = 0;
    
    /*Fetch from NVM*/
    return RetAsRetryCnt;
}
#endif /*(PROG_SA_ANTISCANNING_ENABLE == STD_ON)*/
/*------------------------------{end SA_CustomRestoreAsRetryCnt}-----------------*/

/** \brief Get the Random number for unlocking the security.
 **
 ** Callback is called: This callback is called on the reception of securityaccess service to generate the seed
 ** 
 ** Callback shall implement: customer specific generation algorithm
 **
 ** \param[out] aubSeed Address of the seed array
 **
 **/
void SA_CustomGetRandomSeed(u8 *aubSeed)
{
    u8 ubIdx;
    u8 ubIdxRandom = 3;
    u32 ulTempSeedData = 0;
    ulTempSeedData = BoardGetRandom();

    /* For each byte of the seed */
    for (ubIdx = 0U; ubIdx < SA_SEED_LEN; ubIdx++)
    {
        /* Copy each byte of the random seed */
        aubSeed[ubIdx] = (u8)((u32)(ulTempSeedData >> (8U*ubIdxRandom)) & 0x000000FFU);

        /* If all of the four bytes of the random seed have been copied */
        if (0U == ubIdxRandom)
        {
            /* Set the index to the first copied byte of the random seed */
            ubIdxRandom = 3U;

            /* Generate an other random seed */
            ulTempSeedData = BoardGetRandom();
        }
        else
        {
            /* Decrease the index of the copied byte of the random seed */
            ubIdxRandom--;
        }
    }
}