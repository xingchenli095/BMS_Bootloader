/* board.h - board specific configuration
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board.h 38214 2022-10-18 10:47:30Z syns274107 $
*/

#ifndef BOARD_H
#define BOARD_H

#include <board_version_check.h>
#include <Os_timeconversion.h>
#include <Os.h>

#define BOARD_SIUL_BASE						OS_U(0x40290000)
#define BOARD_FIRC_BASE						OS_U(0x402D0000)
#define BOARD_FXOSC_BASE					OS_U(0x402D4000)
#define BOARD_PLL_BASE						OS_U(0x402E0000)
#define BOARD_MC_CGM_BASE					OS_U(0x402D8000)
#define BOARD_MC_ME_BASE					OS_U(0x402DC000)

#define BOARD_FALSE                         0
#define BOARD_TRUE                          1

/* I/O-port definitions for user "LED" */
/* XS32K3XXEVB-Q172
 * LEDs D32 and D33 are general purpose LEDs
 * D32: 0x131c active high GPIO31
 * D33: 0x138f active high GPIO140
 */

#define OS_REG_32(a)						(*((volatile os_uint32_t*)(a)))
#define OS_REG_8(a)							(*((volatile os_uint8_t*)(a)))

#define SIUL_GPDO31							OS_REG_8(BOARD_SIUL_BASE + 0x131cu)
#define SIUL_GPDO140						OS_REG_8(BOARD_SIUL_BASE + 0x138fu)

#define SIUL_MSCR31							OS_REG_32(BOARD_SIUL_BASE + 0x0240u + (31*4))
#define SIUL_MSCR140						OS_REG_32(BOARD_SIUL_BASE + 0x0240u + (140*4))

#define LEDS_INIT()							\
do {										\
	LEDS_SET(0xff);							\
	SIUL_MSCR31 = (1 << 21);				\
	SIUL_MSCR140 = (1 << 21);				\
} while (0)

#define LEDS_SET(x)							\
do {										\
	SIUL_GPDO31 = (((x) ^ 0x01) >> 0);		\
	SIUL_GPDO140 = (((x) ^ 0x02) >> 1);		\
} while (0)

#define CacheInvalidate(a,s)				do { } while (0)

/* frequency of the quartz oscillator installed on the board (FXOSC) */
#define BOARD_FXOSC_FREQ_HZ					OS_U(16000000)

#define BOARD_PWR_BASE                   (0xF0036000U)
#define Board_pwr                         BOARD_PWR_BASE[0]
#define PLATFORMS_SWRSTCON_SWRSTREQ       0x00000002u

#define BOARD_SCR_SLEEPDEEP_MASK32            0x00000004U
/*
 * SCR register
 */
#define BOARD_SCR_BASEADDR                    0xE000ED10U
#define BOARD_SRS                         (*(volatile os_uint32_t *)BOARD_SCR_BASEADDR)
/*
 * LPIT register definition
 */
#define BOARD_LPIT_BASE           0x40037000U
#define BOARD_LPIT_CVAL0_ADDR     (BOARD_LPIT_BASE + 0x24U)
#define BOARD_LPIT_CVAL0          (*(volatile os_uint32_t *)BOARD_LPIT_CVAL0_ADDR)

#define Board_stm0                      (0xF0001000U)

/**************************************************************
*  PLL Digital Interface
*  S32K3XX Reference manual: 29.4.2 Clock configuration
***************************************************************/
/* XOSC frequency is PLL input frequency: Fpll_ref = 16Mhz
 * Functional mode — PLL operates in integer-only mode.
 * Fpll_vco = fPLL_CORE_VCO = 960Mhz
 * Fpll_vco = Fpll_ref * (PLLDV[MFI] / PLLDV[RDIV])
 * Fpll_ref = 16Mhz
 * PLLDV[MFI] = 60
 * PLLDV[RDIV] = Divide by 1
 *
 * Fclkout = Fpll_phi = Fpll_vco / ((PLLDV[ODIV2]) * (PLLODIV_n[DIV] + 1))
 */

/**************************************************************
*  PLL Configuration in High Performance mode (CORE_CLK @ 160 Mhz)
*  S32K3XX Reference manual:
*   23.7.2.1 Option A - High Performance mode (CORE_CLK @ 160 MHz)
***************************************************************/
/* XOSC frequency is PLL0 input frequency. Fref = 40Mhz
 * Functional mode — PLL operates in integer-only mode.
 * PLL VCO frequency:			960 Mhz
 * PLLDV[ODIV2] = 2
 * PLLODIV2_CLK:				480 Mhz
 * PLLODIV_0[DIV] = 2
 * PLLODIV_1[DIV] = 1
 * Fpll_phi0 = PLL_PHI0_CLK:	160 Mhz
 * Fpll_phi1 = PLL_PHI1_CLK:	240 Mhz
 * CORE_CLK:					160 Mhz
 * AIPS_PLAT_CLK:				80 Mhz (clock for STM0/STM1 timers)
 * AIPS_SLOW_CLK:				40 Mhz (clock for PIT0/PIT1/PIT2 timers)
 */

#define BOARD_FIRC_STAT_SHIFT						OS_U(0)
#define BOARD_FIRC_STD_BY_EN						OS_U(1)

#define BOARD_FXOSC_CTRL_OSCON						OS_U(1)
#define BOARD_FXOSC_STAT_OSC_STAT_SHIFT				OS_U(31)

#define BOARD_PLLODIV_0_DIV 						OS_U(2)
#define BOARD_PLLODIV_1_DIV 						OS_U(1)
#define BOARD_PLLODIV_DE_SHIFT						OS_U(31)
#define BOARD_PLLODIV_DIV_SHIFT						OS_U(16)

#define BOARD_PLLDV_ODIV2_SHIFT						OS_U(25)
#define BOARD_PLLDV_RDIV_SHIFT						OS_U(12)
#define BOARD_PLLDV_MFI_SHIFT						OS_U(0)
#define BOARD_PLLDV_ODIV2							OS_U(2)
#define BOARD_PLLDV_RDIV							OS_U(1)
#define BOARD_PLLDV_MFI								OS_U(60)

#define BOARD_PLLFM_SSCGBYP_SHIFT					OS_U(30)

#define BOARD_PLLCR_PD_SHIFT						OS_U(31)
#define BOARD_PLLSR_LOCK_SHIFT						OS_U(2)

#define BOARD_SELCTL_PLL_PHI0_CLK					OS_U(8)
#define BOARD_SELCTL_PLL_PHI1_CLK					OS_U(9)
#define BOARD_SELCTL_AIPS_PLAT_CLK					OS_U(22)

#define BOARD_MC_CGM_CLK_SW							OS_U(4)
#define BOARD_MC_CGM_SELCTL_SHIFT					OS_U(24)
#define BOARD_MC_CGM_SELSTAT_SHIFT					OS_U(24)
#define BOARD_MC_CGM_DIV_SHIFT						OS_U(16)
#define BOARD_MC_CGM_DIV_1							OS_U(1)
#define BOARD_MC_CGM_DIV_3							OS_U(3)
#define BOARD_MC_CGM_DE_SHIFT						OS_U(31)
#define BOARD_MC_CGM_SELSTAT_MASK					OS_U(0x0F000000)

#define BOARD_MC_ME_PUPD_PCUD_EN					OS_U(0x1)
#define BOARD_MC_ME_CTL_KEY							OS_U(0x5AF0)
#define BOARD_MC_ME_CTL_KEY_INV						OS_U(0xA50F)
/* bit position for clock enable control for STM_0/STM_1 */
#define BOARD_MC_ME_PRTNX_COFB0_CLKEN_REQ29_SHIFT	OS_U(29)
/* bit position for clock enable control for PIT_0 */
#define BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ44_SHIFT	OS_U(12)
/* bit position for clock enable control for PIT_1 */
#define BOARD_MC_ME_PRTN0_COFB1_CLKEN_REQ45_SHIFT	OS_U(13)
/* bit position for clock enable control for PIT_2 */
#define BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ63_SHIFT	OS_U(31)
/* bit position for clock enable control for PLL */
#define BOARD_MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT	OS_U(24)

/* Timer configuration
 * STM Global Timer Prescaler (1-256).
 * 1 is subtracted from this value when it is written to the control register.
*/
#define BOARD_CORTEXM_STM_PRESCALER					OS_U(0x01)

#define OS_STM0_PRESCALER							BOARD_CORTEXM_STM_PRESCALER
#define OS_STM1_PRESCALER							BOARD_CORTEXM_STM_PRESCALER

/* Configure STM timer to operate in debug mode
 * - if set, counter won't increment as long as a debugger is *attached*
 */
#define OS_STM_DEBUG_MODE							OS_U(1)

/* Configure PIT timer to operate in debug mode
 * - if set, counter won't increment as long as a debugger is *attached*
 */
#define OS_PIT_DEBUG_MODE							OS_U(1)

/* Fpll_vco frequency */
#define BOARD_PLL_VCO_FREQ_HZ						(BOARD_FXOSC_FREQ_HZ * (BOARD_PLLDV_MFI / BOARD_PLLDV_RDIV))

/* PLL_PHI0_CLK frequency */
#define BOARD_PLL_PHI0_CLK_HZ						(BOARD_PLL_VCO_FREQ_HZ / (BOARD_PLLDV_ODIV2 * (BOARD_PLLODIV_0_DIV + 1)))

/* AIPS_PLAT_CLK frequency */
#define BOARD_AIPS_PLAT_CLK							(BOARD_PLL_PHI0_CLK_HZ / (BOARD_MC_CGM_DIV_1 + 1))

/* AIPS_SLOW_CLK frequency */
#define BOARD_AIPS_SLOW_CLK							(BOARD_PLL_PHI0_CLK_HZ / (BOARD_MC_CGM_DIV_3 + 1))

#if (BOARD_AIPS_PLAT_CLK == 80000000) && (BOARD_CORTEXM_STM_PRESCALER == 1)
#define OS_BoardSTMNsToTicks(ns)					OS_NsToTicks_80000000(ns)
#define OS_BoardSTMTicksToNs(ticks)					OS_TicksToNs_80000000(ticks)
#else
#error "Please adjust conversion macros."
#endif

#define OS_BoardSTM0TicksToNs(ticks)				OS_BoardSTMTicksToNs(ticks)
#define OS_BoardSTM0NsToTicks(ns)					OS_BoardSTMNsToTicks(ns)
#define OS_BoardSTM1TicksToNs(ticks)				OS_BoardSTMTicksToNs(ticks)
#define OS_BoardSTM1NsToTicks(ns)					OS_BoardSTMNsToTicks(ns)

#if (BOARD_AIPS_SLOW_CLK == 40000000)
#define OS_BoardPITNsToTicks(ns)					OS_NsToTicks_40000000(ns)
#define OS_BoardPITTicksToNs(ticks)					OS_TicksToNs_40000000(ticks)
#else
#error "Please adjust conversion macros."
#endif

#include <CORTEXM/Os_CORTEXM_timer_fs_stm_config.h>
#include <CORTEXM/Os_CORTEXM_timer_nxp_pit_config.h>


/*
 * MC_RGM Register mapping
 * Use to get reset type
 */
#define BOARD_MC_RGM_BASEADDR                0x4028C000U
#define BOARD_FES_OFFSET                     8
#define BOARD_DES_OFFSET                     0

#define BOARD_DES_POR                     0x00000001U
#define BOARD_FES_SW_RST                  0x000001C00U
#define BOARD_FES                         (*(volatile os_uint32_t *)(BOARD_MC_RGM_BASEADDR + BOARD_FES_OFFSET))
#define BOARD_DES                         (*(volatile os_uint32_t *)(BOARD_MC_RGM_BASEADDR + BOARD_DES_OFFSET))

/*
 * LPTMR register definition
 */
#define BOARD_LPTMR_BASE          0x40040000U
#define BOARD_LPTMR_CSR_ADDR      BOARD_LPTMR_BASE

#define BOARD_LPTMR_CSR_TCF       0x80U
#define BOARD_LPTMR_CSR           (*(volatile os_uint32_t *)BOARD_LPTMR_CSR_ADDR)

#define PROG_KEY_LENGTH                                    384U /* In bytes */

#ifndef OS_ASM

typedef struct os_board_core_pll_s os_board_core_pll_t;
struct os_board_core_pll_s
{
	os_reg32_t pllcr;				/* PLL Control Register		*/
	os_reg32_t pllsr;				/* PLL Status Register		*/
	os_reg32_t plldv;				/* PLL Divider				*/
	os_reg32_t pllfm;				/* PLL Frequency Modulation	*/
	os_reg32_t pllfd;				/* PLL Fractional Divider	*/
	os_reg32_t padding0;
	os_reg32_t pllcalreg2;			/* PLL Calibration Register 2	*/
	os_reg32_t padding1[25];
	os_reg32_t pllodiv[2];			/* PLL Output Divider		*/
};

typedef struct os_board_cgm_mux_0_s os_board_cgm_mux_0_t;
struct os_board_cgm_mux_0_s
{
	os_reg32_t csc;					/* Select Control Register			*/
	os_reg32_t css;					/* Select Status Register			*/
	os_reg32_t dc[7];				/* Divider n Control Register		*/
	os_reg32_t padding[4];
	os_reg32_t div_trig_ctrl;		/* Divider Trigger Control Register	*/
	os_reg32_t div_trig;			/* Divider Trigger Register			*/
	os_reg32_t div_upd_stat;		/* Divider Update Status Register	*/
};

typedef struct os_board_cgm_mux_X_s os_board_cgm_mux_X_t;
struct os_board_cgm_mux_X_s
{
	os_reg32_t csc;					/* Select Control Register			*/
	os_reg32_t css;					/* Select Status Register			*/
	os_reg32_t dc;					/* Divider n Control Register		*/
	os_reg32_t padding[12];
	os_reg32_t div_upd_stat;		/* Divider Update Status Register	*/
};

typedef struct os_board_cgm_s os_board_cgm_t;
struct os_board_cgm_s
{
	os_reg32_t padding0[0x300/4];		/* PCFS settings */
	os_board_cgm_mux_0_t mux_0;			/* Clock Multiplexer 0 */
	os_board_cgm_mux_X_t mux_1;			/* Clock Multiplexer 1 */
	os_board_cgm_mux_X_t mux_2;			/* Clock Multiplexer 2 */
	os_board_cgm_mux_X_t padding[7];
	os_board_cgm_mux_X_t mux_10;		/* Clock Multiplexer 10 */
	os_board_cgm_mux_X_t mux_11;		/* Clock Multiplexer 11 */
};

typedef struct os_board_fxosc_s os_board_fxosc_t;
struct os_board_fxosc_s
{
	os_reg32_t ctrl;				/* FXOSC Control Register */
	os_reg32_t stat;				/*  Oscillator Status Register */
};

typedef struct os_board_firc_s os_board_firc_t;
struct os_board_firc_s
{
	os_reg32_t stat;				/* FIRC Status Register */
	os_reg32_t stdby_enable;		/* Standby Enable Register */
};

typedef struct os_board_mc_me_prtn0_corex_reg_s os_board_mc_me_prtn0_corex_reg_t;
struct os_board_mc_me_prtn0_corex_reg_s
{
	os_reg32_t prtn0_corex_pconf;	/* base + 0h Partition 0 Core x Process Configuration Register (PRTN0_COREX_PCONF) */
	os_reg32_t prtn0_corex_pupd;	/* base + 4h Partition 0 Core x Process Update Register (PRTN0_COREX_PUPD) */
	os_reg32_t prtn0_corex_stat;	/* base + 8h Partition 0 Core x Status Register (PRTN0_COREX_STAT) */
	os_reg32_t prtn0_corex_addr;	/* base + Ch Partition 0 Core x Address Register (PRTN0_COREX_ADDR) */
};

typedef struct os_board_mc_me_s os_board_mc_me_t;
struct os_board_mc_me_s
{
	os_reg32_t ctl_key;				/* 0h Control Key Register (CTL_KEY) */
	os_reg32_t mode_conf;			/* 4h Mode Configuration Register (MODE_CONF) */
	os_reg32_t mode_upd;			/* 8h Mode Update Register (MODE_UPD) */
	os_reg32_t mode_stat;			/* Ch Mode Status Register (MODE_STAT) */
	os_reg32_t main_coreid;			/* 10h Main Core ID Register (MAIN_COREID) */
	os_reg32_t padding0[59];
	os_reg32_t prtn0_pconf;			/* 100h Partition 0 Process Configuration Register (PRTN0_PCONF) */
	os_reg32_t prtn0_pupd;			/* 104h Partition 0 Process Update Register (PRTN0_PUPD) */
	os_reg32_t prtn0_stat;			/* 108h Partition 0 Status Register (PRTN0_STAT) */
	os_reg32_t padding1[2];
	os_reg32_t prtn0_cofb1_stat;	/* 114h Partition 0 COFB Set 1 Clock Status Register (PRTN0_COFB1_STAT) */
	os_reg32_t padding2[7];
	os_reg32_t prtn0_cofb1_clken;	/* 134h Partition 0 COFB Set 1 Clock Enable Register (PRTN0_COFB1_CLKEN) */
	os_reg32_t padding3[2];

	/* 140h Partition 0 Core 0 Registers */
	os_board_mc_me_prtn0_corex_reg_t prtn0_core0_reg;
	os_reg32_t padding4[4];

	/* 160h Partition 0 Core 1 Registers */
	os_board_mc_me_prtn0_corex_reg_t prtn0_core1_reg;
	os_reg32_t padding5[6];

	os_reg32_t prtn0_core2_stat;	/* 188h Partition 0 Core 2 Status Register (PRTN0_CORE2_STAT) */
	os_reg32_t prtn0_core2_addr;	/* 18Ch Partition 0 Core 2 Address Register (PRTN0_CORE2_ADDR) */
	os_reg32_t padding6[92];
	os_reg32_t prtn1_pconf;			/* 300h Partition 1 Process Configuration Register (PRTN1_PCONF) */
	os_reg32_t prtn1_pupd;			/* 304h Partition 1 Process Update Register (PRTN1_PUPD) */
	os_reg32_t prtn1_stat;			/* 308h Partition 1 Status Register (PRTN1_STAT) */
	os_reg32_t padding7;

	/* 310h Partition 1 COFB Set X Clock Status Register (PRTN1_COFBX_STAT) */
	os_reg32_t prtn1_cofb_stat[4];
	os_reg32_t padding8[4];

	/* 330h Partition 1 COFB Set X Clock Enable Register (PRTN1_COFBX_CLKEN) */
	os_reg32_t prtn1_cofb_clken[4];
	os_reg32_t padding9[112];

	os_reg32_t prtn2_pconf;			/* 500h Partition 2 Process Configuration Register (PRTN2_PCONF) */
	os_reg32_t prtn2_pupd;			/* 504h Partition 2 Process Update Register (PRTN2_PUPD) */
	os_reg32_t prtn2_stat;			/* 508h Partition 2 Status Register (PRTN2_STAT) */
	os_reg32_t padding10;

	/* 510h Partition 2 COFB Set X Clock Status Register (PRTN2_COFBX_STAT) */
	os_reg32_t prtn2_cofb_stat[2];
	os_reg32_t padding11[6];

	/* 530h Partition 2 COFB Set X Clock Enable Register (PRTN2_COFBX_CLKEN) */
	os_reg32_t prtn2_cofb_clken[2];
};


#define BOARD_CORE_PLL	((os_board_core_pll_t *)	BOARD_PLL_BASE)
#define BOARD_MC_CGM	((os_board_cgm_t *)			BOARD_MC_CGM_BASE)
#define BOARD_FXOSC		((os_board_fxosc_t *)		BOARD_FXOSC_BASE)
#define BOARD_MC_ME		((os_board_mc_me_t *)		BOARD_MC_ME_BASE)

extern os_uint8_t m_ubBoardIntLockNestingCounter;
extern void boardStart(void);
extern void boardDisableInterruptsAsm(void);
extern void boardEnableInterruptsAsm(void);
extern void BoardPerformSwReset(void);
extern os_uint8_t BoardIsSwReset(void);
extern void BoardDisableInterrupts(void);
extern void BoardEnableInterrupts(void);
extern os_uint32_t BoardGetRandom(void);
extern os_uint32_t Mcu_schm_read_msr(void);
extern void BoardWriteEndinit(os_uint32_t state);
extern os_uint8_t BoardSchedulingTimer(void);
#endif /* ! OS_ASM */

#endif /* ! BOARD_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
