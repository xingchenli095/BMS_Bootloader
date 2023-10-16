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
/*%%   _____________________________   %%  \file APP_Pub.h                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.6.0 BL-2.X                */
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

#ifndef APP_PUB_H
#define APP_PUB_H

/** \brief Initialize layer
 **
 ** This function initializes all layers of the complete STACK.
 ** EB_Init is called in this API.
 ** It shall be called only once at ECU startup.
 **
 **/
extern void APP_Init (void);

/** \brief Regular tick of the layer
 **
 ** Ensure cyclic tasks of the layer.
 **
 **/
extern void APP_Manage (void);

#ifdef CRYPTO_CRYPTO_MAIN_FUNCTION_EXISTS
#if (CRYPTO_CRYPTO_MAIN_FUNCTION_EXISTS == STD_ON)
/* Use the name of the crypto driver main function */
extern void Crypto_MainFunction(void);
#endif
#endif

#endif      /* APP_PUB_H */

