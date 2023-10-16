/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 3.7.12
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


  #ifndef CANSM_SYMBOLICNAMES_PBCFG_H
#define CANSM_SYMBOLICNAMES_PBCFG_H

/*==================[includes]===============================================*/
/*==================[macros]=================================================*/

/*------------------[symbolic name values]----------------------------------*/


#if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanSM_CanNetwork )
#error CanSM_CanNetwork is already defined
#endif /* #if (defined CanSM_CanNetwork ) */

/** \brief Export symbolic name value */
#define CanSM_CanNetwork 0U

#endif /* #if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */


/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANSM_SYMBOLICNAMES_PBCFG_H */
/*==================[end of file]============================================*/
