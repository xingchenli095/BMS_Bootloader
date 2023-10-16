/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cfg_Impl60.h              */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.51.0 BL3              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/
#ifndef PROG_CFG_IMPL60_H
#define PROG_CFG_IMPL60_H






#define PROG_ECU_RESET_RESPONSE_SIZE                       2U
#define PROG_DSC_RESPONSE_SIZE                             2U
#define PROG_TD_RESPONSE_SIZE                              2U
#define PROG_RTE_RESPONSE_SIZE                             1U
#define PROG_COMPARE_KEY_RESPONSE_SIZE                     2U
#define PROG_ERASE_POS_RESPONSE_SIZE                       4U
#define PROG_CHK_PROG_DEP_POS_RESPONSE_SIZE                4U
#define PROG_ERASE_REQUEST_DATA                            4U
#define PROG_RD_RESPONSE_SIZE                              4U
#define PROG_TD_MIN_SIZE                                   2U
#define PROG_TD_MIN_SIZE_RD                                3U
#define PROG_WF_RESPONSE_SIZE                              3U
#define PROG_NRC_SIZE                                      3U
#define PROG_AUTOCONTROL_POS_RESPONSE_SIZE                 4U
#define PROG_CHK_PROG_PRECOND_SIZE                         4U
#define PROG_CRC_COMP_RESPONSE_SIZE                        4U
#define PROG_COH_CHK_RESP_SIZE                             5U
#define PROG_RTE_SIZE                                      1U

#define PROG_BOOT_REPROG                                   1U
#define PROG_BOOT_NOREPROG                                 0U

#define PROG_ERASE_ADDR_LEN                                4U
#define PROG_ERASE_SIZE_LEN                                4U

#define PROG_GET_PROG_CNTR_ENABLE                          1U
#define PROG_GET_PROG_CNTR_DISABLE                         0U
#define PROG_CNTR_GET_TYPE                                 PROG_GET_PROG_CNTR_DISABLE

#define PROG_REPROG_TYPE                                   PROG_NO_REPROG_TYPE




#define PROG_ERASE_ALL                                     STD_OFF
#define PROG_ERASE_TYPE                                    PROG_ERASE_BY_ADDR
#undef PROG_ERASE_ALFI
#define PROG_ERASE_ALFI                        STD_OFF



#define PROG_VERIFICATION_ON_THE_FLY                       STD_OFF
#define PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA        STD_ON
#define PROG_SIGNATURE_CALCULATION                         STD_OFF
#define PROG_HASH_CALCULATION                              STD_OFF
#define PROG_VERIFICATION_METHOD                           PROG_VERIFICATION_CRC

#define PROG_CRC_ALGO                                      PROG_CRC32_ETHERNET
#define PROG_CRC_CALCULATION                               PROG_TD_CRC32

#define PROG_RANGE_CKS                                     STD_OFF
#define PROG_SEG_LIST_CKS                                  STD_ON
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                   STD_OFF
#define PROG_MAX_RD_ADDRESS_LENGTH                         4U
/*Download type*/
#define PROG_DOWNLOAD_TYPE                                 PROG_DOWNLOAD_BY_ADDR

/* Maximum Number of byte on which Block is coded in the Erase request */
#define PROG_MAX_BYTE_ERASE_BLOCK_LENGTH                   1U

#define PROG_CVN_CHECK                                     STD_OFF

/* Routine type defines */
#define PROG_ROUTINE_TYPE_1                                0x10U
#define PROG_ROUTINE_TYPE_2                                0x20U
#define PROG_ROUTINE_TYPE_3                                0x30U

/* Routine status defines */
#define PROG_ROUTINE_FINISHED_OK                           0x00U
#define PROG_ROUTINE_FINISHED_NOK                          0x01U
#define PROG_ROUTINE_IN_PROGRESS                           0x02U

/* specific routine result value */
#define PROG_ROUTINE_ACTIVE                                0x01U
#define PROG_ROUTINE_RESAVAILABLE                          0x02U
#define PROG_ROUTINE_PREDIF                                0x08U
#define PROG_ROUTINE_STOP_SUBFUNC                          0x10U
#define PROG_ROUTINE_RES_SUBFUNC                           0x20U
#define PROG_ROUTINE_SELFTERM                              0x40U
#define PROG_ROUTINE_AUTONOMOUS                            0x80U

#define PROG_APPL_VALID                                    0x00000002U
#define PROG_APPL_INVALID                                  0x00000001U

#define PROG_MAGIC_NUM_SIZE                                8U

/* Size in Bytes of the FingerPrint */
#define PROG_FINGERPRINT_SIZE                              16U
/* Size in Bytes reserved to the FingerPrint which is a multiple of size of page */
#define PROG_FINGERPRINT_FLASH_PAGE_SIZE                   16U
#define PROG_FINGERPRINT_FLASH_EXT_PAGE_SIZE               16U
#define PROG_FINGERPRINT_CUSTOM_MEM_PAGE_SIZE              16U

#define PROG_P2_PROG_SESSION_VAL                           (u16)50U
#define PROG_P2STAR_PROG_SESSION_VAL                       (u16)5000U
#define PROG_P2_DEFAULT_SESSION_VAL                        (u16)50U
#define PROG_P2STAR_DEFAULT_SESSION_VAL                    (u16)5000U

#define PROG_IMPL_VARIANT                                  PROG_IMPL_60

#define PROG_WATCHDOG_ENABLE                               STD_OFF
#define PROG_REQUEST_DOWNLOAD_ENABLE                       STD_ON
#define PROG_SECURITY_ENABLE                               STD_ON
#define PROG_SA_SEED_ENABLE                                STD_ON
#define PROG_SA_KEY_ENABLE                                 STD_ON
#define PROG_ERASE_MEMORY_ENABLE                           STD_ON
#define PROG_TRANSFER_DATA_ENABLE                          STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE                  STD_ON
#define PROG_ECU_RESET_ENABLE                              STD_ON
#define PROG_ACTIVE_SBL_ENABLE                             STD_OFF
#define PROG_UPDATE_PSI_ENABLE                             STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                    STD_ON
#define PROG_COMMUNICATION_CONTROL_ENABLE                  STD_ON
#define PROG_CHECK_MEMORY_ENABLE                           STD_ON
#define PROG_GET_EXPECTED_CRC_ENABLED                      STD_OFF
#define PROG_CRC_COMPUTE_COMPARE_ENABLE                    STD_OFF
#define PROG_SET_CRC_COMPARE_RESULT_ENABLE                 STD_ON
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE       STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE        STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE         STD_OFF
#define PROG_NETWORK_MANAGEMENT_ENABLE                     STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE               STD_OFF
#define PROG_APPLI_CHECK_ENABLE                            STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                       STD_ON
#define PROG_PEC_ENABLE                                    STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                                     STD_ON

#define PROG_AUTHENTICATED_BOOT_ENABLE                     STD_OFF
#define PROG_BOOT_VERIFICATION                             STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION              STD_OFF

#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION             STD_OFF


#define PROG_SBL_HEADER_DEFINE                             STD_OFF
#define PROG_ENABLE_DOWNGRADE_PROTECTION                   STD_OFF

#define PROG_SWITCH_APPLICATION_MODE_ENABLE                STD_ON
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE              STD_ON
#define PROG_CAL_CRC_ENABLE                                STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                    STD_OFF
#define PROG_PRE_INIT_ENABLE                               STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                      STD_ON

#define PROG_SLEEP_MANAGEMENT_TYPE                      PROG_SLEEP_MANAGEMENT_OFF

#define PROG_ANTISCANNING_ENABLED                          STD_OFF

/* Security access limit request seed */

#define PROG_LIMIT_NB_REQUEST_SEED_ENABLED              STD_OFF

/* Define if NRC78 shall be sent before SecurityAccess */
#define PROG_NRC78_ON_SA_ENABLE                                STD_ON

/*Use of StartAddress - EndAddress instead of StartAddress-Length*/
#define PROG_USE_START_ADDR_END_ADDR                       STD_OFF

/*Programming Status usage*/
#define PROG_REQ_PROGRAMMING_STATUS_ENABLE                 STD_OFF

#define PROG_USE_ECUID_CALLBACK                            STD_OFF

/*Use Coherency check*/
#define PROG_COHERENCY_CHECK_ENABLE                        STD_ON


/* Use Programming counter */
#define PROG_PROGRAMMING_CNTR_ENABLE                       STD_OFF

/* Use partial checksum verification */
#define PROG_PARTIAL_VERIFY_CRC                            STD_OFF


/*Enable the response after reset in function of reset cause*/
#define PROG_RESET_CAUSE_ENABLE                            STD_OFF
/* Disable bypass of SA */
#define PROG_BYPASS_SA_COMPARE_KEY                         STD_OFF
/* Programming pre-conditions check */
#define PROG_PRECOND_CHECK_ENABLE                          STD_ON

/* Dynamic reconfiguration of TP parameters: BS and STmin */
#define PROG_UPDATE_TP_PARAM_ENABLE                        STD_OFF

extern const u8 m_aCfgMagicNumProgrammedValue[PROG_MAGIC_NUM_SIZE];
extern const u8 m_aCfgMagicNumRevokedValue[PROG_MAGIC_NUM_SIZE];

#define PROG_CRY_PRESENT                                   STD_OFF

#define PROG_CAL_PRESENT                                   STD_OFF


#define PROG_CRYSHE_PRESENT                                STD_OFF

/* Downloading Flash driver feature activation */
#define PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE                STD_OFF
#define PROG_DOWNLOAD_FLASH_ROUTINES_REJECT_AFTER_FAILURE  STD_OFF
/****************************************************/
/*                  UDS                             */
/****************************************************/
#define PROG_RESPONSE_PARAMETERS_OFFSET                    (u8) (1U)/* This define is used because the tables in C starts from 0 and not 1
                                                                    and the indexes in the specifications starts sometimes from 1 */
/* Services */

/* Routines */
#define PROG_RC_ROUTINE_STATUS_BASE_INDEX                  PROG_MSG_BYTE_INDEX(5U)

/* Routine 0x0202 */

/* CRC Offset*/
#define PROG_RC_CRC_OFFSET         0U

#define PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX           PROG_MSG_BYTE_INDEX(5U) + PROG_RC_CRC_OFFSET

/* Routine 0xFF00 */
#define PROG_RC_STATUS_RECORD_ERASEVERIF_BASE_INDEX        PROG_RC_ROUTINE_STATUS_BASE_INDEX
#define PROG_RC_STATUS_RECORD_ERASEVERIF_OK                (u8) 0U
#define PROG_RC_STATUS_RECORD_ERASEVERIF_NOT_OK            (u8) 1U

/* Routine 0xFF01 */

/* Block Id in Fingerprint */
#define PROG_BLOCKID_IN_FINGERPRINT                        STD_OFF


#define PROG_DECOMP_FLASH_ROUTINES                         STD_OFF

/*Introduced below the compiler switch to support Fingerprint for the Segments in RAM*/
#ifndef PROG_RAMSEG_FINGERPRINT_SUPPORT
#define PROG_RAMSEG_FINGERPRINT_SUPPORT                    STD_ON
#endif


#define PROG_CSM_HASH_USED                                 STD_OFF
#define PROG_CSM_MAC_USED                                  STD_OFF

#define PROG_SIGNATURE_CALCULATION_OVER_HASH               STD_OFF
#define PROG_COMPUTE_HASH_WITH_ADDR_LEN                    STD_OFF
#define PROG_RESUM_REPROG                                  STD_OFF

/*Securiy access request seed delay timer*/

#define PROG_REQUEST_SEED_DELAY_TIMER_ENABLED            STD_OFF

#endif /* PROG_CFG_IMPL_60_H */
