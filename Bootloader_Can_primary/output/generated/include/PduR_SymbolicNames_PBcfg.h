/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.49
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H
#define PDUR_SYMBOLIC_NAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/* -------------------- Routing path: 0 Pdu_Rx_Func_Group_0 */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Func_Group_0)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Func_Group_0 is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Func_Group_0 0U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Func_Group_0)
#error PduR_Sdu_Rx_Func_Group_0 is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Func_Group_0 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Func_Group_0_d)
#error PduRConf_PduRDestPdu_Sdu_Rx_Func_Group_0_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Func_Group_0_d 0U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 1 Pdu_Rx_Phys_Group_0 */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Phys_Group_0)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Phys_Group_0 is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Phys_Group_0 1U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Phys_Group_0)
#error PduR_Sdu_Rx_Phys_Group_0 is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Phys_Group_0 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Phys_Group_0_d)
#error PduRConf_PduRDestPdu_Sdu_Rx_Phys_Group_0_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Phys_Group_0_d 1U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 2 Pdu_Tx_Group_0 */
#if (defined PduRConf_PduRSrcPdu_Sdu_Tx_Group_0)
#error PduRConf_PduRSrcPdu_Sdu_Tx_Group_0 is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Tx_Group_0 0U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Tx_Group_0)
#error PduR_Sdu_Tx_Group_0 is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Tx_Group_0 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Tx_Group_0_d)
#error PduRConf_PduRDestPdu_Sdu_Tx_Group_0_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Tx_Group_0_d 0U /* DEST CanTp-LO-TP */



/* Define vendor specific destination PDU IDs of adjacent modules */
#if (defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES)

/* -------------------- Routing path: 0 Pdu_Rx_Func_Group_0 */
#define PDURSA_Sdu_Rx_Func_Boot_Group_0 0U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Rx_Func_Boot_Group_0 1U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 1 Pdu_Rx_Phys_Group_0 */
#define PDURSA_Sdu_Rx_Phys_Boot_Group_0 1U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Rx_Phys_Boot_Group_0 0U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 2 Pdu_Tx_Group_0 */
#define PDURSA_Sdu_Tx_Boot_Group_0 0U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_Tx_Boot_Group_0 0U /* DEST CanTp-LO-TP */

#endif /* defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H  */
/*==================[end of file]===========================================*/
