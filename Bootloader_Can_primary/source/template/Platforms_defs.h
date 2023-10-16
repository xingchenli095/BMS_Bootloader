/* --------{ EB Automotive C Source File }-------- */

#ifndef _PLATFORMS_DEFS_H_
#define _PLATFORMS_DEFS_H_


#ifndef PLATFORMS_TOOLCHAIN
#error "PLATFORMS_TOOLCHAIN is not defined. Check your Makefiles!"
#endif

/*Supported Toolchains */
#define PLATFORMS_gnu           1
#define PLATFORMS_dcc           2
#define PLATFORMS_multi         3
#define PLATFORMS_tasking       4
#define PLATFORMS_softune       5
#define PLATFORMS_mwerks        6
#define PLATFORMS_ccs           7
#define PLATFORMS_ticgt         8
#define PLATFORMS_csp           9


/* exclude typdefs for ASM code */
#ifndef BOARD_ASM

#define PLATFORMS_MCU_IDLE      0x00
#define PLATFORMS_MCU_SLEEP     0x01
#define PLATFORMS_MCU_STANDBY   0x02

#define PLATFORMS_POWER_ON_RESET       0x00U /* Power on reset event. */
#define PLATFORMS_WATCHDOG_RESET       0x01U /* Internal Watchdog Timer reset event. */
#define PLATFORMS_SW_RESET             0x02U /* Software Reset event. */
#define PLATFORMS_RESET_UNDEFINED      0x03U /* Undefined reset source. */


#endif /* BOARD_ASM */

#endif /* _PLATFORMS_DEFS_H_ */
