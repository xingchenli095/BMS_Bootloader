#ifndef TARGET_SPEC_DEF
#define TARGET_SPEC_DEF

/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                                DEMO                                           */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file Test_Specific_Definition.h      */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
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
 
 /* This file is used to define all the constants used in integration for a specific target */

/* APP_START_ADDR should be changed according to the definition in memory mapping */
#define APP_START_ADDR       0x501052U
/* Define how many slice of crypto will be done per main function */
/*In case the BLU is flashed, at this addres is stored the BLU Pattern 0x424C5550U, meaning BLUP in ASCII */
#endif /*#ifndef TARGET_SPEC_DEF*/
