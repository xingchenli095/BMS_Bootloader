#ifndef FLASH_CFG_H
#define FLASH_CFG_H

/*===============================================================================*/
/*                                                                               */
/*                               FLASH layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                              FLASH  configuration                             */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FLASH_Cfg.h                     */
/*%%  |                             |  %%  \brief FLASH layer implementation     */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                  */
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

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*===============================================================================*/
/* - Configuration Constants                                                     */

/*===============================================================================*/
/* - Configuration Variable or Register Aliases                                  */

/*===============================================================================*/
/* - Public Constants                                                            */
#define FLASH_PAGE_SIZE                   8U
#define FLASH_PAGE_PADDING_VALUE          255U
#define FLASH_SECTORS_TABLE_NB_ELEMENTS   4

#define FLASH_ERASE_MODE   FLASH_ASYNCHRONE_MODE


#define FLASH_WRITE_MODE   FLASH_ASYNCHRONE_MODE


#define FLASH_READ_MODE    FLASH_ASYNCHRONE_MODE




/*===============================================================================*/
/* - Public Macros                                                               */

/*                                                                               */
/*===============================================================================*/

#endif      /* FLASH_CFG_H */
