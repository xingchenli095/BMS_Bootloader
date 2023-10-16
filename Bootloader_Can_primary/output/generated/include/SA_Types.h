/*********************************************************************************/
/*                                                                               */
/*                                 Sa LAYER                                      */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               Security Access                                 */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file SA_Types.h                   */
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

#ifndef SA_TYPES_H
#define SA_TYPES_H

#include "SA_Cfg.h"
#include <ComStack_Cfg.h>



typedef u8 tSaStatus;
#define SA_E_STATUS_UNKNOWN 0x00U
#define SA_E_OK             0x01U
#define SA_E_NOT_OK         0x02U
#define SA_E_BUSY           0x03U
/*Following are for Anti-scanning*/
#define SA_E_NOK_INVALID_KEY      0x04U

/*Following are for Request Seed Limit*/







/* SA boolean type */
#define SA_FALSE               0U
#define SA_TRUE                1U
typedef u8 tSaBoolean;













#endif      /* SA_TYPES_H */
