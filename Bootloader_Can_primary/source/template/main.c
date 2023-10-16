/**
 * \file
 *
 * \brief Autosar Demo
 *
 * This file contains the implementation of the Autosar
 * module Demo.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2010 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include "EB_Prj.h"
#include <Base_Modules.h>   /* Module enable defines and standard config pointer names */
#include "board.h"
#include <Port.h>   /* Module enable defines and standard config pointer names */
#include "Mcu.h"

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/******************************** DEFINES & VARIABLES ****************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------*/
/* Following define are necessary to set CAN_MOIPR to wanted Interrupt vectors   */
/* MODULE_CAN  => Base Address of the CAN for TRICORE 277                        */
/* RXINP_02    => Bit to set to select Interrupt Output 2 in Rx                  */
/* TXINP_01    => Bit to set to select Interrupt Output 1 in Tx                  */
/* SET_RXTXINP => Mask to apply to select only bit of Rx and Tx interruption     */
/*-------------------------------------------------------------------------------*/

void main(void)
{

	/* Initialization of Port */
    Port_Init(&Port_Config);

    /* Initialization of MCU */
    Mcu_Init(BASE_MCU_CONFIG_PTR);
	
    /* ignore return value (always E_NOT_OK). ERAY Pll is not supported for TC22
    * but the function tries to configure it anyway with 0 values. */
	Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);	
	
	/* Wait until the PLL is locked */
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
	{
		;
    }
	
	/* Activate the PLL Clock */
	Mcu_DistributePllClock();
	Mcu_SetMode(McuModeSettingConf_0);
	
	/*Start OS*/
	StartOS(OSDEFAULTAPPMODE);
}

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
