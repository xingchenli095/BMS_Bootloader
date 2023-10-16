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

#define MEMMAP_ERROR_DIO

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dio */

#if (defined DIO_START_SEC_CODE)
  #undef DIO_START_SEC_CODE
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_CODE)
  #undef DIO_STOP_SEC_CODE
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_CONFIG_DATA_UNSPECIFIED)
  #undef DIO_START_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_CONFIG_DATA_UNSPECIFIED)
  #undef DIO_STOP_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_SEC_CONST_16)
  #undef DIO_START_SEC_CONST_16
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_CONST_16)
  #undef DIO_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_SEC_CONST_32)
  #undef DIO_START_SEC_CONST_32
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_CONST_32)
  #undef DIO_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_SEC_CONST_8)
  #undef DIO_START_SEC_CONST_8
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_CONST_8)
  #undef DIO_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR_DIO

#elif (defined DIO_START_SEC_VAR_INIT_32)
  #undef DIO_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DIO
#elif (defined DIO_STOP_SEC_VAR_INIT_32)
  #undef DIO_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR_DIO

#endif

#if ((!defined MEMMAP_ERROR_DIO) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DIO) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DIO
  #error MEMMAP_ERROR_DIO the included memory section was not defined within the BSW-IMPLEMENTATION of Dio.
#endif
