#if !defined(SCHM_FLS_H)
#define SCHM_FLS_H

/**
 * \file
 *
 * \brief SchM stub for Fls module
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_02 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_03 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_04 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_05 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_06 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_07 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_08 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_09 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13 (void);
extern FUNC(void, SCHM_CODE) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_14 (void);

extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_03 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_07 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_08 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_09 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13 (void);
extern FUNC(void, SCHM_CODE) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_14 (void);
		
#define FLS_START_SEC_CODE
#include <Fls_MemMap.h>

extern FUNC(void, FLS_CODE) Fls_MainFunction (void);


#define FLS_STOP_SEC_CODE
#include <Fls_MemMap.h>

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* !defined(SCHM_FLS_H) */
/*==================[end of file]============================================*/
