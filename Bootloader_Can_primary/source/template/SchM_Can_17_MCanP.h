#if !defined(SCHM_17_MCANP_H)
#define SCHM_17_MCANP_H
#include <TSAutosar.h>          /* EB specific standard types */

extern FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanDisInt(void);

extern FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanEnInt(void);

extern FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanWrMO(void);

extern FUNC(void, SCHM_CODE) SchM_Exit_Can_17_MCanP_CanDisInt(void);

extern FUNC(void, SCHM_CODE) SchM_Exit_Can_17_MCanP_CanEnInt(void);

extern FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanWrMO(void);

extern FUNC(void, SCHM_CODE) SchM_Exit_Can_17_MCanP_CanWrMO(void);

#endif
/*==================[end of file]============================================*/

