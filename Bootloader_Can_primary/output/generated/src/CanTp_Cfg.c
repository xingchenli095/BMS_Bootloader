/**
 * \file
 *
 * \brief AUTOSAR CanTp
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTp.
 *
 * \version 6.8.52
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/








    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





#include <TSAutosar.h>         /* EB specific standard types */
#include <ComStack_Types.h>    /* typedefs for AUTOSAR com stack */
#include <CanTp_Types.h>        /* Module public types */
#include <CanTp_Api.h>         /* Module public API */
#include <CanTp_Internal.h>    /* internal macros and variables */
#include <CanTp_InternalCfg.h> /* CanTp internal configuration */



#if(CANTP_JUMPTABLE_SUPPORT == STD_ON)
#include <CanTp_EntryTable.h>  /* CanTp entry jumptable */
#endif /* CANTP_JUMPTABLE_SUPPORT == STD_ON */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/


#define CANTP_START_SEC_VAR_CLEARED_8
#include <CanTp_MemMap.h>



#if(CANTP_DYNAMIC_NSA_ENABLED == STD_ON)
/** \brief If dynamic setting of N_SA values is enabled, the N_SA values are
 *         stored in following array.
 */
VAR(uint8, CANTP_VAR) CanTp_NSaValues[CANTP_MAX_RX_NSDUS + CANTP_MAX_FC_PDUS];
#endif

#define CANTP_STOP_SEC_VAR_CLEARED_8
#include <CanTp_MemMap.h>




#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTp_MemMap.h>

VAR(CanTp_ChannelType, CANTP_VAR) CanTp_Channel[CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS];

VAR(BufReq_ReturnType, CANTP_VAR) RetVal_DataReq;

#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTp_MemMap.h>


/* !LINKSTO CanTp.EB.JTM_MemMapSection_SharedVariables, 2 */
#define CANTP_START_SEC_VAR_INIT_JUMP_TABLE_SHARED_UNSPECIFIED
#include <CanTp_MemMap.h>
/** \brief Internal CanTp variables to be initialized by the C startup code */
/* !LINKSTO CanTp.JTM_0023, 1, CanTp.EB.JTM_11579, 1 */
VAR(CanTp_InitVariableType, CANTP_VAR) CanTp_InitVars =
  {
        CANTP_OFF                     /* default state */
  };

#define CANTP_STOP_SEC_VAR_INIT_JUMP_TABLE_SHARED_UNSPECIFIED
#include <CanTp_MemMap.h>




/** \brief Internal CanTp Counter for checking if all channels are idle or not (0 means all channels are IDLE) */
#if((CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS) > 255U)

  #define CANTP_START_SEC_VAR_CLEARED_16
  #include <CanTp_MemMap.h>

  VAR(uint16, CANTP_VAR) CanTp_NonIdleChannelCounter;

  #define CANTP_STOP_SEC_VAR_CLEARED_16
  #include <CanTp_MemMap.h>

#else /* (CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS <= 255U)*/

  #define CANTP_START_SEC_VAR_CLEARED_8
  #include <CanTp_MemMap.h>

  VAR(uint8, CANTP_VAR) CanTp_NonIdleChannelCounter;

  #define CANTP_STOP_SEC_VAR_CLEARED_8
  #include <CanTp_MemMap.h>
#endif /* (CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS > 255U) */



/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/


