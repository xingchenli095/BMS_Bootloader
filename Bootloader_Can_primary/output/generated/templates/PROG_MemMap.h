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
/*%%   _____________________________   %%  \file PROG_MemMap.h                   */
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
/* Copyright 2019 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
/*
 *  MISRA deviation report:
 *  - This file violates MISRA-C:2012, Rule 4.10:
 *       "Precautions shall be taken in order to prevent the contents
 *        of a header file being included more than once."
 *    Reason:
 *       This file needs to be included more than once in a compilation unit
 */
/* CHECK: NOPARSE */

/*  MISRA-C:2012 Deviation List
 *
 *  MISRA-1) Deviated Rule: 3.4 (required)
 *   "All uses of the #pragma directive shall be documented and explained."
 *
 *   Reason:
 *   lib.
 *
 */
/* Deviation MISRA-1 <START> */
#if 0 /* to be able to use #elif for every module */
/*------------------[Start of a module]--------------------------------------*/

/* Start of History Record */
#elif (defined PROG_START_HISTORY_RECORD_SEC_CONST_8 )
   #undef      PROG_START_HISTORY_RECORD_SEC_CONST_8 
   #undef MEMMAP_ERROR
#elif (defined PROG_STOP_HISTORY_RECORD_SEC_CONST_8 )
   #undef      PROG_STOP_HISTORY_RECORD_SEC_CONST_8 
   #undef MEMMAP_ERROR
/* End of History Record */

#elif defined (PROG_START_SEC_CODE)
   #undef      PROG_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_CODE)
   #undef      PROG_STOP_SEC_CODE
   #undef MEMMAP_ERROR

#elif defined (PROG_GET_DID_F0F3_START_SEC_CODE)
   #undef      PROG_GET_DID_F0F3_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined (PROG_GET_DID_F0F3_STOP_SEC_CODE)
   #undef      PROG_GET_DID_F0F3_STOP_SEC_CODE
   #undef MEMMAP_ERROR

#elif defined (PROG_GET_DID_F0F6_START_SEC_CODE)
   #undef      PROG_GET_DID_F0F6_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined (PROG_GET_DID_F0F6_STOP_SEC_CODE)
   #undef      PROG_GET_DID_F0F6_STOP_SEC_CODE
   #undef MEMMAP_ERROR

#elif defined (PROG_START_SEC_VAR_INIT_8)
   #undef      PROG_START_SEC_VAR_INIT_8
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_VAR_INIT_8)
   #undef      PROG_STOP_SEC_VAR_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_START_SEC_VAR_NO_INIT_8

   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      PROG_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      PROG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef MEMMAP_ERROR

#elif defined (PROG_START_SEC_VAR_RAM_NO_INIT)
   #undef      PROG_START_SEC_VAR_RAM_NO_INIT
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_VAR_RAM_NO_INIT)
   #undef      PROG_STOP_SEC_VAR_RAM_NO_INIT
   #undef MEMMAP_ERROR
   
      
#elif defined (PROG_START_SEC_CONST_UNSPECIFIED)
   #undef      PROG_START_SEC_CONST_UNSPECIFIED
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PROG_STOP_SEC_CONST_UNSPECIFIED
   #undef MEMMAP_ERROR

#elif defined (PROG_START_SEC_CONST_8)
   #undef      PROG_START_SEC_CONST_8
   #undef MEMMAP_ERROR
#elif defined (PROG_STOP_SEC_CONST_8)
   #undef      PROG_STOP_SEC_CONST_8
   #undef MEMMAP_ERROR

#elif defined (PROG_SBL_HEADER_START_SEC_CONST_8)
   #undef      PROG_SBL_HEADER_START_SEC_CONST_8
   #undef MEMMAP_ERROR
#elif defined (PROG_SBL_HEADER_STOP_SEC_CONST_8)
   #undef      PROG_SBL_HEADER_STOP_SEC_CONST_8
   #undef MEMMAP_ERROR
   
   
   #elif defined (PROG_SBL_VALIDITY_START_SEC_CONST_8)
   #undef      PROG_SBL_VALIDITY_START_SEC_CONST_8
   #undef MEMMAP_ERROR

#elif defined (PROG_SBL_VALIDITY_STOP_SEC_CONST_8)
   #undef      PROG_SBL_VALIDITY_STOP_SEC_CONST_8
   #undef MEMMAP_ERROR
   
   #elif defined (PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR
   
   #elif defined (PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR
  


 #elif defined (PROG_ANTISCANNING_START_SEC_VAR_NO_INIT_8)
#undef      PROG_ANTISCANNING_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR

#elif defined (PROG_ANTISCANNING_FLAG_STOP_SEC_VAR_NO_INIT_8)
#undef      PROG_ANTISCANNING_FLAG_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR


#elif defined (PROG_TESTER_ADDRESS_FLAG_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_TESTER_ADDRESS_FLAG_START_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_TESTER_ADDRESS_FLAG_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_TESTER_ADDRESS_FLAG_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR


#elif defined (PROG_ECU_ADDRESS_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_ECU_ADDRESS_START_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_ECU_ADDRESS_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_ECU_ADDRESS_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_SUPPPOSITIVERESPONSE_FLAG_START_SEC_VAR_NO_INIT_8)
   #undef      PROG_SUPPPOSITIVERESPONSE_FLAG_START_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_SUPPPOSITIVERESPONSE_FLAG_STOP_SEC_VAR_NO_INIT_8)
   #undef      PROG_SUPPPOSITIVERESPONSE_FLAG_STOP_SEC_VAR_NO_INIT_8
   #undef MEMMAP_ERROR

#elif defined (PROG_BOOT_INFO_START_SEC_CONST_UNSPECIFIED)
   #undef      PROG_BOOT_INFO_START_SEC_CONST_UNSPECIFIED
   #undef MEMMAP_ERROR
#elif defined (PROG_BOOT_INFO_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PROG_BOOT_INFO_STOP_SEC_CONST_UNSPECIFIED
   #undef MEMMAP_ERROR
   
#elif (defined PROG_START_SEC_CODE_FLASH_PAGE)
  #undef PROG_START_SEC_CODE_FLASH_PAGE
  #undef MEMMAP_ERROR

#elif (defined PROG_STOP_SEC_CODE_FLASH_PAGE)
  #undef PROG_STOP_SEC_CODE_FLASH_PAGE
  #undef MEMMAP_ERROR

#endif
