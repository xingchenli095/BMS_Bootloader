/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.12
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_CANSM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CanSM */

#if (defined CANSM_START_SEC_CODE)
  #undef CANSM_START_SEC_CODE
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_CODE)
  #undef CANSM_STOP_SEC_CODE
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_CONFIG_DATA_8)
  #undef CANSM_START_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_CONFIG_DATA_8)
  #undef CANSM_STOP_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_CONFIG_DATA_8)
  #undef CANSM_START_CONFIG_DATA_8
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_CONFIG_DATA_8)
  #undef CANSM_STOP_CONFIG_DATA_8
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_CONFIG_DATA_UNSPECIFIED)
  #undef CANSM_START_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_CONFIG_DATA_UNSPECIFIED)
  #undef CANSM_STOP_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_CONST_8)
  #undef CANSM_START_SEC_CONST_8
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_CONST_8)
  #undef CANSM_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_VAR_CLEARED_8)
  #undef CANSM_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_VAR_CLEARED_8)
  #undef CANSM_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_VAR_INIT_8)
  #undef CANSM_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_VAR_INIT_8)
  #undef CANSM_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_CANSM

#elif (defined CANSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef CANSM_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM
#elif (defined CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_CANSM

#endif

#if ((!defined MEMMAP_ERROR_CANSM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CANSM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CANSM
  #error MEMMAP_ERROR_CANSM the included memory section was not defined within the BSW-IMPLEMENTATION of CanSM.
#endif
