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

#define MEMMAP_ERROR_MCU

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Mcu */

#if (defined MCU_START_SEC_CODE)
  #undef MCU_START_SEC_CODE
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CODE)
  #undef MCU_STOP_SEC_CODE
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CODE_AC)
  #undef MCU_START_SEC_CODE_AC
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CODE_AC)
  #undef MCU_STOP_SEC_CODE_AC
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_CONFIG_DATA_UNSPECIFIED)
  #undef MCU_START_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_CONFIG_DATA_UNSPECIFIED)
  #undef MCU_STOP_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CONST_16)
  #undef MCU_START_SEC_CONST_16
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CONST_16)
  #undef MCU_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CONST_32)
  #undef MCU_START_SEC_CONST_32
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CONST_32)
  #undef MCU_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CONST_8)
  #undef MCU_START_SEC_CONST_8
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CONST_8)
  #undef MCU_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_CONST_UNSPECIFIED)
  #undef MCU_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_CONST_UNSPECIFIED)
  #undef MCU_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_RAMCODE)
  #undef MCU_START_SEC_RAMCODE
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_RAMCODE)
  #undef MCU_STOP_SEC_RAMCODE
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_CLEARED_32)
  #undef MCU_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_CLEARED_32)
  #undef MCU_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_CLEARED_8)
  #undef MCU_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_CLEARED_8)
  #undef MCU_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_INIT_32)
  #undef MCU_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_INIT_32)
  #undef MCU_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_INIT_8)
  #undef MCU_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_INIT_8)
  #undef MCU_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR_MCU

#elif (defined MCU_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef MCU_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU
#elif (defined MCU_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR_MCU

#endif

#if ((!defined MEMMAP_ERROR_MCU) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_MCU) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_MCU
  #error MEMMAP_ERROR_MCU the included memory section was not defined within the BSW-IMPLEMENTATION of Mcu.
#endif
