/* board.c - board specific code
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board.c 38213 2022-10-18 07:31:55Z syns274107 $
 */

#include <Os.h>
#include <Os_configuration.h>
#include <Os_kernel.h>
#include <CORTEXM/Os_mpu_CORTEXM.h>

#include <board.h>
#include "Platforms_defs.h"
#include "Mcu.h"

/* linker generated symbol for global data/bss */
#if (BOARD_INIT_DATA_SECTION == 1)
extern os_uint32_t OS_TOOL_INITDATA;
extern os_uint32_t OS_TOOL_STARTDATA;
extern os_uint32_t OS_TOOL_ENDDATA;
#endif
extern os_uint32_t OS_TOOL_STARTBSS;
extern os_uint32_t OS_TOOL_ENDBSS;

os_uint8_t m_ubBoardIntLockNestingCounter = 0;

os_reg32_t boardPanicReason = 0;

/* BOARD_PANIC handles fatal errors. This implementation simply performs an
 * infinite loop.
 */
#define BOARD_PANIC(reason)		\
	boardPanicReason = reason;	\
	for (;;)					\
	{							\
		/* stall here */		\
	}

/* Function prototypes. */
extern int main(void);
extern void boardEnableICaches(void);

#ifndef PLATFORMS_STUBS_ENABLED
void BoardDisableInterrupts (void)
{
    if (m_ubBoardIntLockNestingCounter < 255U)
    {
        if (m_ubBoardIntLockNestingCounter == 0U)
        {
            boardDisableInterruptsAsm();
        }
        /* Manage nesting
         * !LINKSTO OsekCore.Platforms.Board.102, 1
         */
        m_ubBoardIntLockNestingCounter++;
    }
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardEnableInterrupts (void)
{
    if (m_ubBoardIntLockNestingCounter > 0U)
    {
        /* Manage nesting
         * !LINKSTO OsekCore.Platforms.Board.102, 1
         */
        m_ubBoardIntLockNestingCounter--;

        if (m_ubBoardIntLockNestingCounter == 0U)
        {
            boardEnableInterruptsAsm();
        }
    }
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardPerformSwReset(void)
{
 Mcu_PerformReset();
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
os_uint8_t BoardIsSwReset(void)
{    
    os_uint8_t BoardResetReturn;

    volatile os_uint32_t BoardResetFES = BOARD_FES;
	volatile os_uint32_t BoardResetDES = BOARD_DES;

    if (BoardResetDES == BOARD_DES_POR)
    {
        BoardResetReturn = PLATFORMS_POWER_ON_RESET;
    } 
    else if (BoardResetFES == BOARD_FES_SW_RST)
    {
        BoardResetReturn = PLATFORMS_SW_RESET;
    } 
    else 
    {
        BoardResetReturn = PLATFORMS_RESET_UNDEFINED;
    }

    return BoardResetReturn;
}
#endif

#ifndef PLATFORMS_STUBS_ENABLED
void BoardSetState(os_uint8_t ubState)
{

    switch (ubState)
    {
      case PLATFORMS_MCU_SLEEP :
        /* request into sleep mode: wait for interrupt */
        BOARD_SRS = BOARD_SCR_SLEEPDEEP_MASK32;
        break;

      case PLATFORMS_MCU_IDLE :
      default :
          /* do nothing since MCU is normally in RUN mode already !*/
        break;
      /* no default handling */
    }

    if(PLATFORMS_MCU_SLEEP == ubState)
    {
       /* infinite loop to wait Sleep / Standby*/
       for(;;)
       {

       }
    }
}
#endif

os_uint8_t BoardSchedulingTimer (void)
{
    os_uint8_t ubFlag = BOARD_FALSE;

    /* Timer is scheduled at 1ms */
    if (BOARD_LPTMR_CSR_TCF == ((os_uint8_t)(BOARD_LPTMR_CSR & BOARD_LPTMR_CSR_TCF)))
    {
        /* reset timer */
        BOARD_LPTMR_CSR |= (BOARD_LPTMR_CSR_TCF);

        /* Set return flag to TRUE */
        ubFlag = BOARD_TRUE;
    }

    return ubFlag;
}


#ifndef PLATFORMS_STUBS_ENABLED
os_uint32_t BoardGetRandom(void)
{
    os_uint32_t ulBoardRandom;

    /* Get 32bit running counter */
   /* ulBoardRandom = BOARD_LPIT_CVAL0;

    /* Bit inverted */
   /* ulBoardRandom = ~(ulBoardRandom);

    /* Manipulate the Random value so it is not that easy to find !*/
    /*ulBoardRandom =
            (os_uint32_t) ((os_uint32_t) ulBoardRandom + (os_uint32_t) (ulBoardRandom << 16U)
                    + (os_uint32_t) (ulBoardRandom <<12U));*/

    return ulBoardRandom;
}
#endif

static void boardDisableMpu(void)
{
	os_int32_t i;

	/* Disable all 16 of S32K344's memory regions. */
	for (i = 0; i < 16; ++i)
	{
		OS_CORTEXM_SetRegion(i, 0, 0);
	}
}

/* initialize memory sections (data, bss). */
static void boardInitMemorySections(void)
{
	register os_uint32_t *p;
#if (BOARD_INIT_DATA_SECTION == 1)
	register os_uint32_t *q;

	/* sanity check: alignment */
	if (((os_address_t)(&OS_TOOL_INITDATA) & 3u) != 0u)
	{
		BOARD_PANIC(7u);
	}
	if (((os_address_t)(&OS_TOOL_STARTDATA) & 3u) != 0u)
	{
		BOARD_PANIC(8u);
	}
	if (((os_address_t)(&OS_TOOL_ENDDATA) & 3u) != 0u)
	{
		BOARD_PANIC(9u);
	}
	if (((os_address_t)(&OS_TOOL_STARTBSS) & 3u) != 0u)
	{
		BOARD_PANIC(10u);
	}
	if (((os_address_t)(&OS_TOOL_ENDBSS) & 3u) != 0u)
	{
		BOARD_PANIC(11u);
	}

	/* Copy the data section out from flash to RAM. */
	for	(p = &OS_TOOL_STARTDATA, q = &OS_TOOL_INITDATA;
		 p < &OS_TOOL_ENDDATA;
		 p++, q++)
	{
		*p = *q;
	}
#endif

	for (p = &OS_TOOL_STARTBSS; p < &OS_TOOL_ENDBSS; p++)
	{
		*p = 0;
	}
}

void boardEnableClocks(void)
{
	/* PRTN0 */
	/* Enable clock for PIT_0 timer module in partition 0 */
	BOARD_MC_ME->prtn0_cofb1_clken |= (1u << BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ44_SHIFT);
	/* Enable clock for PIT_1 timer module in partition 0 */
	BOARD_MC_ME->prtn0_cofb1_clken |= (1u << BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ45_SHIFT);
	/* Trigger the hardware process for enabling the clocks */
	BOARD_MC_ME->prtn0_pupd |= BOARD_MC_ME_PUPD_PCUD_EN;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY_INV;
	while ( (BOARD_MC_ME->prtn0_pupd & 0x1u) == 1);

	/* Check that timer clocks are running */
	while (((BOARD_MC_ME->prtn0_cofb1_stat >> BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ44_SHIFT) & 0x1u) == 0);
	while (((BOARD_MC_ME->prtn0_cofb1_stat >> BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ45_SHIFT) & 0x1u) == 0);

	/* PRTN1 */
	/* Enable clock for STM_0 timer module in partition 1 */
	BOARD_MC_ME->prtn1_cofb_clken[0] |= (1u << BOARD_MC_ME_PRTNX_COFB0_CLKEN_REQ29_SHIFT);
	/* Enable clock for PIT_2 timer module in partition 1 */
	BOARD_MC_ME->prtn1_cofb_clken[1] |= (1u << BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ63_SHIFT);
	/* Enable clock for PLL module in partition 1 */
	BOARD_MC_ME->prtn1_cofb_clken[1] |= (1u << BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT);
	/* Trigger the hardware process for enabling the clocks */
	BOARD_MC_ME->prtn1_pupd |= BOARD_MC_ME_PUPD_PCUD_EN;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY_INV;
	while ( (BOARD_MC_ME->prtn1_pupd & 0x1u) == 1);

	/* Check that timer clocks are running */
	while (((BOARD_MC_ME->prtn1_cofb_stat[0] >> BOARD_MC_ME_PRTNX_COFB0_CLKEN_REQ29_SHIFT) & 0x1u) == 0);
	while (((BOARD_MC_ME->prtn1_cofb_stat[1] >> BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ63_SHIFT) & 0x1u) == 0);
	while (((BOARD_MC_ME->prtn1_cofb_stat[1] >> BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT) & 0x1u) == 0);

	/* PRTN2 */
	/* Enable clock for STM_1 timer module in partition 2 */
	BOARD_MC_ME->prtn2_cofb_clken[0] |= (1u << BOARD_MC_ME_PRTNX_COFB0_CLKEN_REQ29_SHIFT);
	/* Trigger the hardware process for enabling the clocks */
	BOARD_MC_ME->prtn2_pupd |= BOARD_MC_ME_PUPD_PCUD_EN;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY;
	BOARD_MC_ME->ctl_key |= BOARD_MC_ME_CTL_KEY_INV;
	while ( (BOARD_MC_ME->prtn2_pupd & 0x1u) == 1);

	/* Check that timer clock is running */
	while (((BOARD_MC_ME->prtn2_cofb_stat[0] >> BOARD_MC_ME_PRTNX_COFB0_CLKEN_REQ29_SHIFT) & 0x1u) == 0);
}

void boardSetupClocks(void)
{
	/* FIRC is the default system clock source.
	 * S32K3XX Reference manual: 23.4.1.1 Chip clock sources
	 */
	if( (BOARD_MC_CGM->mux_0.css & BOARD_MC_CGM_SELSTAT_MASK) != 0u)
	{
		BOARD_PANIC(0x13u);
	}
	/**************************************************************
	*  PLL Initializations
	*  S32K3xx Reference Manual cl. 29.5 Initialization information
	***************************************************************/
	/* Disable the divider */
	BOARD_CORE_PLL->pllodiv[0] = 0x0;
	BOARD_CORE_PLL->pllodiv[1] = 0x0;
	/* Disable the analog PLL block */
	BOARD_CORE_PLL->pllcr |= (1u << BOARD_PLLCR_PD_SHIFT);
	BOARD_CORE_PLL->plldv = (BOARD_PLLDV_RDIV << BOARD_PLLDV_RDIV_SHIFT) | (BOARD_PLLDV_MFI << BOARD_PLLDV_MFI_SHIFT);
	/* Set MFN for integer mode. Fractional mode disabled */
	BOARD_CORE_PLL->pllfd = 0x0;
	/* Bypass spread spectrum modulation */
	BOARD_CORE_PLL->pllfm |= (1u << BOARD_PLLFM_SSCGBYP_SHIFT);
	/* Configure the division factor to achieve the required frequency */
	BOARD_CORE_PLL->plldv |= (BOARD_PLLDV_ODIV2 << BOARD_PLLDV_ODIV2_SHIFT);
	BOARD_CORE_PLL->pllodiv[0] |= BOARD_PLLODIV_0_DIV << BOARD_PLLODIV_DIV_SHIFT;
	BOARD_CORE_PLL->pllodiv[1] |= BOARD_PLLODIV_1_DIV << BOARD_PLLODIV_DIV_SHIFT;
	/* Turn on crystal oscillator and wait for its clock to be stable */
	BOARD_FXOSC->ctrl |= BOARD_FXOSC_CTRL_OSCON;
	while ( ((BOARD_FXOSC->stat >> BOARD_FXOSC_STAT_OSC_STAT_SHIFT) & 0x1u) == 0);
	/* Enable the analog PLL block */
	BOARD_CORE_PLL->pllcr &= ~(1u << BOARD_PLLCR_PD_SHIFT);
	/* Wait for the PLL to acquire the lock */
	while (((BOARD_CORE_PLL->pllsr >> BOARD_PLLSR_LOCK_SHIFT) & 0x1u) == 0);
	/* Enable PLL output divider */
	BOARD_CORE_PLL->pllodiv[0] |= (1u << BOARD_PLLODIV_DE_SHIFT);
	BOARD_CORE_PLL->pllodiv[1] |= (1u << BOARD_PLLODIV_DE_SHIFT);

	/**************************************************************
	*  MC_CGM MUX_X Initializations
	*  S32K3xx Reference Manual cl. 23.7.2.1 Option A - High Performance mode (CORE_CLK @ 160 MHz)
	***************************************************************/
	/* set MUX_0_DC_X divider */
	BOARD_MC_CGM->mux_0.dc[1] |= BOARD_MC_CGM_DIV_1 << BOARD_MC_CGM_DIV_SHIFT;
	BOARD_MC_CGM->mux_0.dc[2] |= BOARD_MC_CGM_DIV_3 << BOARD_MC_CGM_DIV_SHIFT;
	BOARD_MC_CGM->mux_0.dc[4] |= BOARD_MC_CGM_DIV_3 << BOARD_MC_CGM_DIV_SHIFT;
	BOARD_MC_CGM->mux_0.dc[3] |= BOARD_MC_CGM_DIV_1 << BOARD_MC_CGM_DIV_SHIFT;
	BOARD_MC_CGM->mux_0.dc[5] |= BOARD_MC_CGM_DIV_3 << BOARD_MC_CGM_DIV_SHIFT;
	/* set MUX_0 clock source to PLL_PHI0_CLK */
	BOARD_MC_CGM->mux_0.csc = (BOARD_SELCTL_PLL_PHI0_CLK << BOARD_MC_CGM_SELCTL_SHIFT) | BOARD_MC_CGM_CLK_SW;
	while (((BOARD_MC_CGM->mux_0.css >> BOARD_MC_CGM_SELSTAT_SHIFT) & BOARD_SELCTL_PLL_PHI0_CLK) != BOARD_SELCTL_PLL_PHI0_CLK);

	/* STM0: set MUX_1 clock source to AIPS_PLAT_CLK */
	BOARD_MC_CGM->mux_1.csc = (BOARD_SELCTL_AIPS_PLAT_CLK << BOARD_MC_CGM_SELCTL_SHIFT) | BOARD_MC_CGM_CLK_SW;
	while (((BOARD_MC_CGM->mux_1.css >> BOARD_MC_CGM_SELSTAT_SHIFT) & BOARD_SELCTL_AIPS_PLAT_CLK) != BOARD_SELCTL_AIPS_PLAT_CLK);
	/* Enable MUX_1_DC_0 divider */
	BOARD_MC_CGM->mux_1.dc |= (1u << BOARD_MC_CGM_DE_SHIFT);

	/* STM1: set MUX_2 clock source to AIPS_PLAT_CLK */
	BOARD_MC_CGM->mux_2.csc = (BOARD_SELCTL_AIPS_PLAT_CLK << BOARD_MC_CGM_SELCTL_SHIFT) | BOARD_MC_CGM_CLK_SW;
	while (((BOARD_MC_CGM->mux_2.css >> BOARD_MC_CGM_SELSTAT_SHIFT) & BOARD_SELCTL_AIPS_PLAT_CLK) != BOARD_SELCTL_AIPS_PLAT_CLK);
	/* Enable MUX_2_DC_0 divider */
	BOARD_MC_CGM->mux_2.dc |= (1u << BOARD_MC_CGM_DE_SHIFT);


	/* set MUX_10_DC_0 divider */
	BOARD_MC_CGM->mux_10.dc |= BOARD_MC_CGM_DIV_1 << BOARD_MC_CGM_DIV_SHIFT;
	/* set MUX_10 clock source to PLL_PHI1_CLK */
	BOARD_MC_CGM->mux_10.csc = (BOARD_SELCTL_PLL_PHI1_CLK << BOARD_MC_CGM_SELCTL_SHIFT) | BOARD_MC_CGM_CLK_SW;
	while (((BOARD_MC_CGM->mux_10.css >> BOARD_MC_CGM_SELSTAT_SHIFT) & BOARD_SELCTL_PLL_PHI1_CLK) != BOARD_SELCTL_PLL_PHI1_CLK);
	/* Enable MUX_10_DC_0 divider */
	BOARD_MC_CGM->mux_10.dc |= (1u << BOARD_MC_CGM_DE_SHIFT);


	/* set MUX_11_DC_0 divider */
	BOARD_MC_CGM->mux_11.dc |= BOARD_MC_CGM_DIV_1 << BOARD_MC_CGM_DIV_SHIFT;
	/* set MUX_11 clock source to PLL_PHI1_CLK */
	BOARD_MC_CGM->mux_11.csc = (BOARD_SELCTL_PLL_PHI1_CLK << BOARD_MC_CGM_SELCTL_SHIFT) | BOARD_MC_CGM_CLK_SW;
	while (((BOARD_MC_CGM->mux_11.css >> BOARD_MC_CGM_SELSTAT_SHIFT) & BOARD_SELCTL_PLL_PHI1_CLK) != BOARD_SELCTL_PLL_PHI1_CLK);
	/* Enable MUX_11_DC_0 divider */
	BOARD_MC_CGM->mux_11.dc |= (1u << BOARD_MC_CGM_DE_SHIFT);
}

/* boardStart() - called from assembler */
void boardStart(void)
{
	/* Initialize DATA and BSS. */
	boardInitMemorySections();
	boardEnableClocks();
	boardSetupClocks();

	/*test_leds();*/
	LEDS_INIT();
	LEDS_SET(0);
	LEDS_SET(1);
	LEDS_SET(0);

	boardDisableMpu();

	boardEnableICaches();

	/* When all that is done, we can start the OS in the main() function */
	/* note: main() is running in "kernel mode" and on the kernel stack */
	main();
	/* NOT REACHED */
	while (1); /* loop endlessly */
}

#if (OS_TOOL == OS_gnu)
/* To avoid drawing in the C-library, we need to provide a memcpy
 * and memset function for gcc-generated code.
 * Probably, you may want to use a proper C-library instead.
*/
extern void *memcpy(void *, const void *, os_size_t);
extern void *memset(void *, int, os_size_t);

#define unlikely(expr) __builtin_expect(!!(expr), 0)

void *memcpy(void *dest, const void *src, os_size_t n)
{
	os_size_t i;
	void * tmp = dest;

	/* check assumptions */
	if (unlikely(   (((os_uint32_t) dest & 3) != 0)
		         || (((os_uint32_t) src & 3) != 0)
		         || (((os_uint32_t) n & 3) != 0)
	   )        )
	{
		/* We need to use the slow version... */
		const os_uint8_t * s8 = (const os_uint8_t *) src;
		os_uint8_t * d8 = (os_uint8_t *) dest;

		for (i = 0; i < n; i++)
		{
			*d8++ = *s8++;
		}
	}
	else
	{
		/* Use unrolled 32-bit accesses */
		const os_uint32_t * s32 = (const os_uint32_t *) src;
		os_uint32_t * d32 = (os_uint32_t *) dest;

		n /= 4u;
		switch (n & 3)
		{
			case 3:
				*d32++ = *s32++;
			case 2:
				*d32++ = *s32++;
			case 1:
				*d32++ = *s32++;
			default:
				break;
		}
		n /= 4u;

		for (i = 0; i < n; i++)
		{
			*d32++ = *s32++;
			*d32++ = *s32++;
			*d32++ = *s32++;
			*d32++ = *s32++;
		}
	}

	return tmp;

}

void *memset(void *str, int c, os_size_t n)
{
	os_size_t i;
	for (i = 0; i < n ; ++i) {
		*(os_uint8_t *)(str+i) = (os_uint8_t)c;
	}
	return str;
}
#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
