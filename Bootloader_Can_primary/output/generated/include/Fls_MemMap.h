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

#define MEMMAP_ERROR_FLS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Fls */

#if (defined FLS_START_SEC_CODE)
  #undef FLS_START_SEC_CODE
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CODE)
  #undef FLS_STOP_SEC_CODE
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CODE_AC)
  #undef FLS_START_SEC_CODE_AC
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CODE_AC)
  #undef FLS_STOP_SEC_CODE_AC
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONFIG_DATA_8)
  #undef FLS_START_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONFIG_DATA_8)
  #undef FLS_STOP_SEC_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_CONFIG_DATA_8)
  #undef FLS_START_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_CONFIG_DATA_8)
  #undef FLS_STOP_CONFIG_DATA_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_CONFIG_DATA_UNSPECIFIED)
  #undef FLS_START_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_CONFIG_DATA_UNSPECIFIED)
  #undef FLS_STOP_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONST_32)
  #undef FLS_START_SEC_CONST_32
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONST_32)
  #undef FLS_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_CONST_UNSPECIFIED)
  #undef FLS_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_CONST_UNSPECIFIED)
  #undef FLS_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_CLEARED_16)
  #undef FLS_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_CLEARED_16)
  #undef FLS_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_CLEARED_32)
  #undef FLS_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_CLEARED_32)
  #undef FLS_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_CLEARED_8)
  #undef FLS_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_CLEARED_8)
  #undef FLS_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef FLS_START_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef FLS_STOP_SEC_VAR_CLEARED_BOOLEAN
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_8)
  #undef FLS_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_8)
  #undef FLS_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_BOOLEAN)
  #undef FLS_START_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MEMMAP_ERROR_FLS

#elif (defined FLS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS
#elif (defined FLS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_FLS

#endif

#if ((!defined MEMMAP_ERROR_FLS) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FLS) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FLS
  #error MEMMAP_ERROR_FLS the included memory section was not defined within the BSW-IMPLEMENTATION of Fls.
#endif
