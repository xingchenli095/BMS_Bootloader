/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.2.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#ifndef BASE_MODULES_H
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_APP_ENABLED
/** \brief Enable status of the module APP (/APP/APP) (VariantPreCompile) */
#define BASE_APP_ENABLED STD_ON
#endif

#ifndef BASE_APP_HEADER
/** \brief Name of the APP (/APP/APP) module's main header file */
#define BASE_APP_HEADER <APP.h>
#endif

#ifndef BASE_BM_ENABLED
/** \brief Enable status of the module BM (/BM/BM) (VariantPreCompile) */
#define BASE_BM_ENABLED STD_ON
#endif

#ifndef BASE_BM_HEADER
/** \brief Name of the BM (/BM/BM) module's main header file */
#define BASE_BM_HEADER <BM.h>
#endif

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

#ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_BASENXP_ENABLED
/** \brief Enable status of the module BaseNXP (/BaseNXP/BaseNXP) (VariantPreCompile) */
#define BASE_BASENXP_ENABLED STD_ON
#endif

#ifndef BASE_BASENXP_HEADER
/** \brief Name of the BaseNXP (/BaseNXP/BaseNXP) module's main header file */
#define BASE_BASENXP_HEADER <BaseNXP.h>
#endif

#ifndef BASE_BLPDUR_ENABLED
/** \brief Enable status of the module BlPduR (/BlPduR/BlPduR) (VariantPreCompile) */
#define BASE_BLPDUR_ENABLED STD_ON
#endif

#ifndef BASE_BLPDUR_HEADER
/** \brief Name of the BlPduR (/BlPduR/BlPduR) module's main header file */
#define BASE_BLPDUR_HEADER <BlPduR.h>
#endif

#ifndef BASE_CAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_HEADER <Can.h>
#endif

#ifndef BASE_CANIF_ENABLED
/** \brief Enable status of the module CanIf (/CanIf/CanIf) (VariantPostBuild) */
#define BASE_CANIF_ENABLED STD_ON
#endif


#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanIf (/CanIf/CanIf) */
#define BASE_CANIF_CONFIG_PTR (&CanIfInitCfg)
#endif

#ifndef BASE_CANIF_HEADER
/** \brief Name of the CanIf (/CanIf/CanIf) module's main header file */
#define BASE_CANIF_HEADER <CanIf.h>
#endif

#ifndef BASE_CANSM_ENABLED
/** \brief Enable status of the module CanSM (/CanSM/CanSM) (VariantPostBuild) */
#define BASE_CANSM_ENABLED STD_ON
#endif


#ifndef BASE_CANSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanSM (/CanSM/CanSM) */
#define BASE_CANSM_CONFIG_PTR (&CanSMConfiguration)
#endif

#ifndef BASE_CANSM_HEADER
/** \brief Name of the CanSM (/CanSM/CanSM) module's main header file */
#define BASE_CANSM_HEADER <CanSM.h>
#endif

#ifndef BASE_CANTP_ENABLED
/** \brief Enable status of the module CanTp (/CanTp/CanTp) (VariantPostBuild) */
#define BASE_CANTP_ENABLED STD_ON
#endif


#ifndef BASE_CANTP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanTp (/CanTp/CanTp) */
#define BASE_CANTP_CONFIG_PTR (&CanTpConfig)
#endif

#ifndef BASE_CANTP_HEADER
/** \brief Name of the CanTp (/CanTp/CanTp) module's main header file */
#define BASE_CANTP_HEADER <CanTp.h>
#endif

#ifndef BASE_COMM_ENABLED
/** \brief Enable status of the module ComM (/ComM/ComM) (VariantPostBuild) */
#define BASE_COMM_ENABLED STD_ON
#endif


#ifndef BASE_COMM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for ComM (/ComM/ComM) */
#define BASE_COMM_CONFIG_PTR (&ComMConfigSet)
#endif

#ifndef BASE_COMM_HEADER
/** \brief Name of the ComM (/ComM/ComM) module's main header file */
#define BASE_COMM_HEADER <ComM.h>
#endif

#ifndef BASE_COMPILER_ENABLED
/** \brief Enable status of the module Compiler (/Compiler/Compiler) (VariantPreCompile) */
#define BASE_COMPILER_ENABLED STD_ON
#endif

#ifndef BASE_COMPILER_HEADER
/** \brief Name of the Compiler (/Compiler/Compiler) module's main header file */
#define BASE_COMPILER_HEADER <Compiler.h>
#endif

#ifndef BASE_DET_ENABLED
/** \brief Enable status of the module Det (/Det/Det) (VariantPreCompile) */
#define BASE_DET_ENABLED STD_ON
#endif

#ifndef BASE_DET_HEADER
/** \brief Name of the Det (/Det/Det) module's main header file */
#define BASE_DET_HEADER <Det.h>
#endif

#ifndef BASE_DIO_ENABLED
/** \brief Enable status of the module Dio (/Dio/Dio) (VariantPreCompile) */
#define BASE_DIO_ENABLED STD_ON
#endif

#ifndef BASE_DIO_HEADER
/** \brief Name of the Dio (/Dio/Dio) module's main header file */
#define BASE_DIO_HEADER <Dio.h>
#endif

#ifndef BASE_ECUC_ENABLED
/** \brief Enable status of the module EcuC (/EcuC/EcuC) (VariantPostBuild) */
#define BASE_ECUC_ENABLED STD_ON
#endif

#ifndef BASE_ECUC_HEADER
/** \brief Name of the EcuC (/EcuC/EcuC) module's main header file */
#define BASE_ECUC_HEADER <EcuC.h>
#endif

#ifndef BASE_FLASH_ENABLED
/** \brief Enable status of the module Flash (/Flash/Flash) (VariantPreCompile) */
#define BASE_FLASH_ENABLED STD_ON
#endif

#ifndef BASE_FLASH_HEADER
/** \brief Name of the Flash (/Flash/Flash) module's main header file */
#define BASE_FLASH_HEADER <Flash.h>
#endif

#ifndef BASE_FLS_ENABLED
/** \brief Enable status of the module Fls (/Fls/Fls) (VariantPostBuild) */
#define BASE_FLS_ENABLED STD_ON
#endif

#ifndef BASE_FLS_HEADER
/** \brief Name of the Fls (/Fls/Fls) module's main header file */
#define BASE_FLS_HEADER <Fls.h>
#endif

#ifndef BASE_MCALEXT_ENABLED
/** \brief Enable status of the module McalExt (/McalExt/McalExt) (VariantPreCompile) */
#define BASE_MCALEXT_ENABLED STD_ON
#endif

#ifndef BASE_MCALEXT_HEADER
/** \brief Name of the McalExt (/McalExt/McalExt) module's main header file */
#define BASE_MCALEXT_HEADER <McalExt.h>
#endif

#ifndef BASE_MCU_ENABLED
/** \brief Enable status of the module Mcu (/Mcu/Mcu) (VariantPostBuild) */
#define BASE_MCU_ENABLED STD_ON
#endif

#ifndef BASE_MCU_HEADER
/** \brief Name of the Mcu (/Mcu/Mcu) module's main header file */
#define BASE_MCU_HEADER <Mcu.h>
#endif

#ifndef BASE_MEMMAP_ENABLED
/** \brief Enable status of the module MemMap (/MemMap/MemMap) (VariantPreCompile) */
#define BASE_MEMMAP_ENABLED STD_ON
#endif

#ifndef BASE_MEMMAP_HEADER
/** \brief Name of the MemMap (/MemMap/MemMap) module's main header file */
#define BASE_MEMMAP_HEADER <MemMap.h>
#endif

#ifndef BASE_OS_ENABLED
/** \brief Enable status of the module Os (/Os/Os) (VariantPreCompile) */
#define BASE_OS_ENABLED STD_ON
#endif

#ifndef BASE_OS_HEADER
/** \brief Name of the Os (/Os/Os) module's main header file */
#define BASE_OS_HEADER <Os.h>
#endif

#ifndef BASE_PDUR_ENABLED
/** \brief Enable status of the module PduR (/PduR/PduR) (VariantPostBuild) */
#define BASE_PDUR_ENABLED STD_ON
#endif


#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for PduR (/PduR/PduR) */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingTables)
#endif

#ifndef BASE_PDUR_HEADER
/** \brief Name of the PduR (/PduR/PduR) module's main header file */
#define BASE_PDUR_HEADER <PduR.h>
#endif

#ifndef BASE_PORT_ENABLED
/** \brief Enable status of the module Port (/Port/Port) (VariantPostBuild) */
#define BASE_PORT_ENABLED STD_ON
#endif

#ifndef BASE_PORT_HEADER
/** \brief Name of the Port (/Port/Port) module's main header file */
#define BASE_PORT_HEADER <Port.h>
#endif

#ifndef BASE_PROG_ENABLED
/** \brief Enable status of the module Prog (/Prog/Prog) (VariantPreCompile) */
#define BASE_PROG_ENABLED STD_ON
#endif

#ifndef BASE_PROG_HEADER
/** \brief Name of the Prog (/Prog/Prog) module's main header file */
#define BASE_PROG_HEADER <Prog.h>
#endif

#ifndef BASE_PROGOEMIND_ENABLED
/** \brief Enable status of the module ProgOEMInd (/ProgOEMInd/ProgOEMInd) (VariantPreCompile) */
#define BASE_PROGOEMIND_ENABLED STD_ON
#endif

#ifndef BASE_PROGOEMIND_HEADER
/** \brief Name of the ProgOEMInd (/ProgOEMInd/ProgOEMInd) module's main header file */
#define BASE_PROGOEMIND_HEADER <ProgOEMInd.h>
#endif

#ifndef BASE_RESOURCE_ENABLED
/** \brief Enable status of the module Resource (/Resource/Resource) (VariantPreCompile) */
#define BASE_RESOURCE_ENABLED STD_ON
#endif

#ifndef BASE_RESOURCE_HEADER
/** \brief Name of the Resource (/Resource/Resource) module's main header file */
#define BASE_RESOURCE_HEADER <Resource.h>
#endif

#ifndef BASE_SA_ENABLED
/** \brief Enable status of the module SA (/SA/SA) (VariantPreCompile) */
#define BASE_SA_ENABLED STD_ON
#endif

#ifndef BASE_SA_HEADER
/** \brief Name of the SA (/SA/SA) module's main header file */
#define BASE_SA_HEADER <SA.h>
#endif

#ifndef BASE_UDS_ENABLED
/** \brief Enable status of the module Uds (/Uds/Uds) (VariantPreCompile) */
#define BASE_UDS_ENABLED STD_ON
#endif

#ifndef BASE_UDS_HEADER
/** \brief Name of the Uds (/Uds/Uds) module's main header file */
#define BASE_UDS_HEADER <Uds.h>
#endif

#endif /* ifndef BASE_MODULES_H */
/*==================[end of file]============================================*/
