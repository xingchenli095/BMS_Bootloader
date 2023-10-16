.macro neg rDest rSrc
 rsb rDest,rSrc,#0
 .endm

.macro OS_GET_KERNEL_PTR litBase destReg sReg
 ldr destReg, litBase
 ldr destReg, [destReg]
 .endm

.macro OS_GENLIT_ACTIVATE_SVC

OS_SHCSR_Addr:
 .word 0xE000ED24
 .endm

.macro OS_ACTIVATE_SVC reg1 reg2
 ldr reg1, OS_SHCSR_Addr
 ldr reg2, [reg1]
 orr reg2, reg2, #0x00000080
 str reg2, [reg1]
 dsb
 isb
 .endm

.macro OS_SETLEVEL level oldLevel
 lsl level, level, #4
 mrs oldLevel, basepri
 lsr oldLevel, oldLevel, #4
 msr basepri, level
 .endm

.macro OS_ENABLE_FPU addrR tmpR storeR
 movw addrR, #(0xED88)
 movt addrR, #(0xE000)
 ldr storeR, [addrR]
 orr tmpR, storeR, #0x00f00000
 str tmpR, [addrR]
 .endm

.macro OS_DISABLE_FPU addrR tmpR storeR
 movw addrR, #(0xED88)
 movt addrR, #(0xE000)
 ldr storeR, [addrR]
 movw tmpR, #(0xffff)
 movt tmpR, #(0xff0f)
 and tmpR, storeR, tmpR
 str tmpR, [addrR]
 .endm

.macro OS_GET_MPU_CTRL_ADDR destR
 movw destR, #(0xED94)
 movt destR, #(0xE000)
 .endm

.macro OS_ENABLE_MPU reg1 reg2
 .endm

.macro OS_DISABLE_MPU_GET_STATE reg1 reg2 result
 .endm

.macro OS_MPU_SET_CTRL reg1 ctrl
 .endm

.macro DispatchInterrupt isrid entry exit level corevar
 cpsid i
 OS_DISABLE_MPU_GET_STATE r0, r1, r2
 OS_DISABLE_FPU r0, r1, r3
 push {r4-r11, lr}
 push {r2, r3}
 OS_GET_KERNEL_PTR corevar, r1, r0
 ldrb r4, [r1, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r0, #1
 strb r0, [r1, #(((((0 + 4) + 4) + 4) + 4) + 0)]
 mov r2, #level
 OS_SETLEVEL r2, r0
 push {r0}
 cpsie i
 mov r0, #isrid
 bl entry
 mov r0,r4
 bl exit
 .endm
 .section InterruptTable_C0, "ax"
 .thumb2
 .global CORTEXMInterruptTable_C0
 .import OS_CORTEXM_IntCat1Exit
 .import OS_CORTEXM_IntCat2Exit
 .import DispatchUnknownInterrupt
 .import OS_CORTEXM_IntReturnFromInterrupt
 .import OS_kernel_ptr
 .align 4

CORTEXMInterruptTable_C0:
 .word OS_CORTEXM_IRQ_C0_00
 .word OS_CORTEXM_IRQ_C0_01
 .word OS_CORTEXM_IRQ_C0_02
 .word OS_CORTEXM_IRQ_C0_03
 .word OS_CORTEXM_IRQ_C0_04
 .word OS_CORTEXM_IRQ_C0_05
 .word OS_CORTEXM_IRQ_C0_06
 .word OS_CORTEXM_IRQ_C0_07
 .word OS_CORTEXM_IRQ_C0_08
 .word OS_CORTEXM_IRQ_C0_09
 .word OS_CORTEXM_IRQ_C0_0a
 .word OS_CORTEXM_IRQ_C0_0b
 .word OS_CORTEXM_IRQ_C0_0c
 .word OS_CORTEXM_IRQ_C0_0d
 .word OS_CORTEXM_IRQ_C0_0e
 .word OS_CORTEXM_IRQ_C0_0f
 .word OS_CORTEXM_IRQ_C0_10
 .word OS_CORTEXM_IRQ_C0_11
 .word OS_CORTEXM_IRQ_C0_12
 .word OS_CORTEXM_IRQ_C0_13
 .word OS_CORTEXM_IRQ_C0_14
 .word OS_CORTEXM_IRQ_C0_15
 .word OS_CORTEXM_IRQ_C0_16
 .word OS_CORTEXM_IRQ_C0_17
 .word OS_CORTEXM_IRQ_C0_18
 .word OS_CORTEXM_IRQ_C0_19
 .word OS_CORTEXM_IRQ_C0_1a
 .word OS_CORTEXM_IRQ_C0_1b
 .word OS_CORTEXM_IRQ_C0_1c
 .word OS_CORTEXM_IRQ_C0_1d
 .word OS_CORTEXM_IRQ_C0_1e
 .word OS_CORTEXM_IRQ_C0_1f
 .word OS_CORTEXM_IRQ_C0_20
 .word OS_CORTEXM_IRQ_C0_21
 .word OS_CORTEXM_IRQ_C0_22
 .word OS_CORTEXM_IRQ_C0_23
 .word OS_CORTEXM_IRQ_C0_24
 .word OS_CORTEXM_IRQ_C0_25
 .word OS_CORTEXM_IRQ_C0_26
 .word OS_CORTEXM_IRQ_C0_27
 .word OS_CORTEXM_IRQ_C0_28
 .word OS_CORTEXM_IRQ_C0_29
 .word OS_CORTEXM_IRQ_C0_2a
 .word OS_CORTEXM_IRQ_C0_2b
 .word OS_CORTEXM_IRQ_C0_2c
 .word OS_CORTEXM_IRQ_C0_2d
 .word OS_CORTEXM_IRQ_C0_2e
 .word OS_CORTEXM_IRQ_C0_2f
 .word OS_CORTEXM_IRQ_C0_30
 .word OS_CORTEXM_IRQ_C0_31
 .word OS_CORTEXM_IRQ_C0_32
 .word OS_CORTEXM_IRQ_C0_33
 .word OS_CORTEXM_IRQ_C0_34
 .word OS_CORTEXM_IRQ_C0_35
 .word OS_CORTEXM_IRQ_C0_36
 .word OS_CORTEXM_IRQ_C0_37
 .word OS_CORTEXM_IRQ_C0_38
 .word OS_CORTEXM_IRQ_C0_39
 .word OS_CORTEXM_IRQ_C0_3a
 .word OS_CORTEXM_IRQ_C0_3b
 .word OS_CORTEXM_IRQ_C0_3c
 .word OS_CORTEXM_IRQ_C0_3d
 .word OS_CORTEXM_IRQ_C0_3e
 .word OS_CORTEXM_IRQ_C0_3f
 .word OS_CORTEXM_IRQ_C0_40
 .word OS_CORTEXM_IRQ_C0_41
 .word OS_CORTEXM_IRQ_C0_42
 .word OS_CORTEXM_IRQ_C0_43
 .word OS_CORTEXM_IRQ_C0_44
 .word OS_CORTEXM_IRQ_C0_45
 .word OS_CORTEXM_IRQ_C0_46
 .word OS_CORTEXM_IRQ_C0_47
 .word OS_CORTEXM_IRQ_C0_48
 .word OS_CORTEXM_IRQ_C0_49
 .word OS_CORTEXM_IRQ_C0_4a
 .word OS_CORTEXM_IRQ_C0_4b
 .word OS_CORTEXM_IRQ_C0_4c
 .word OS_CORTEXM_IRQ_C0_4d
 .word OS_CORTEXM_IRQ_C0_4e
 .word OS_CORTEXM_IRQ_C0_4f
 .word OS_CORTEXM_IRQ_C0_50
 .word OS_CORTEXM_IRQ_C0_51
 .word OS_CORTEXM_IRQ_C0_52
 .word OS_CORTEXM_IRQ_C0_53
 .word OS_CORTEXM_IRQ_C0_54
 .word OS_CORTEXM_IRQ_C0_55
 .word OS_CORTEXM_IRQ_C0_56
 .word OS_CORTEXM_IRQ_C0_57
 .word OS_CORTEXM_IRQ_C0_58
 .word OS_CORTEXM_IRQ_C0_59
 .word OS_CORTEXM_IRQ_C0_5a
 .word OS_CORTEXM_IRQ_C0_5b
 .word OS_CORTEXM_IRQ_C0_5c
 .word OS_CORTEXM_IRQ_C0_5d
 .word OS_CORTEXM_IRQ_C0_5e
 .word OS_CORTEXM_IRQ_C0_5f
 .word OS_CORTEXM_IRQ_C0_60
 .word OS_CORTEXM_IRQ_C0_61
 .word OS_CORTEXM_IRQ_C0_62
 .word OS_CORTEXM_IRQ_C0_63
 .word OS_CORTEXM_IRQ_C0_64
 .word OS_CORTEXM_IRQ_C0_65
 .word OS_CORTEXM_IRQ_C0_66
 .word OS_CORTEXM_IRQ_C0_67
 .word OS_CORTEXM_IRQ_C0_68
 .word OS_CORTEXM_IRQ_C0_69
 .word OS_CORTEXM_IRQ_C0_6a
 .word OS_CORTEXM_IRQ_C0_6b
 .word OS_CORTEXM_IRQ_C0_6c
 .word OS_CORTEXM_IRQ_C0_6d
 .word OS_CORTEXM_IRQ_C0_6e
 .word OS_CORTEXM_IRQ_C0_6f
 .word OS_CORTEXM_IRQ_C0_70
 .word OS_CORTEXM_IRQ_C0_71
 .word OS_CORTEXM_IRQ_C0_72
 .word OS_CORTEXM_IRQ_C0_73
 .word OS_CORTEXM_IRQ_C0_74
 .word OS_CORTEXM_IRQ_C0_75
 .word OS_CORTEXM_IRQ_C0_76
 .word OS_CORTEXM_IRQ_C0_77
 .word OS_CORTEXM_IRQ_C0_78
 .word OS_CORTEXM_IRQ_C0_79
 .word OS_CORTEXM_IRQ_C0_7a
 .word OS_CORTEXM_IRQ_C0_7b
 .word OS_CORTEXM_IRQ_C0_7c
 .word OS_CORTEXM_IRQ_C0_7d
 .word OS_CORTEXM_IRQ_C0_7e
 .word OS_CORTEXM_IRQ_C0_7f
 .word OS_CORTEXM_IRQ_C0_80
 .word OS_CORTEXM_IRQ_C0_81
 .word OS_CORTEXM_IRQ_C0_82
 .word OS_CORTEXM_IRQ_C0_83
 .word OS_CORTEXM_IRQ_C0_84
 .word OS_CORTEXM_IRQ_C0_85
 .word OS_CORTEXM_IRQ_C0_86
 .word OS_CORTEXM_IRQ_C0_87
 .word OS_CORTEXM_IRQ_C0_88
 .word OS_CORTEXM_IRQ_C0_89
 .word OS_CORTEXM_IRQ_C0_8a
 .word OS_CORTEXM_IRQ_C0_8b
 .word OS_CORTEXM_IRQ_C0_8c
 .word OS_CORTEXM_IRQ_C0_8d
 .word OS_CORTEXM_IRQ_C0_8e
 .word OS_CORTEXM_IRQ_C0_8f
 .word OS_CORTEXM_IRQ_C0_90
 .word OS_CORTEXM_IRQ_C0_91
 .word OS_CORTEXM_IRQ_C0_92
 .word OS_CORTEXM_IRQ_C0_93
 .word OS_CORTEXM_IRQ_C0_94
 .word OS_CORTEXM_IRQ_C0_95
 .word OS_CORTEXM_IRQ_C0_96
 .word OS_CORTEXM_IRQ_C0_97
 .word OS_CORTEXM_IRQ_C0_98
 .word OS_CORTEXM_IRQ_C0_99
 .word OS_CORTEXM_IRQ_C0_9a
 .word OS_CORTEXM_IRQ_C0_9b
 .word OS_CORTEXM_IRQ_C0_9c
 .word OS_CORTEXM_IRQ_C0_9d
 .word OS_CORTEXM_IRQ_C0_9e
 .word OS_CORTEXM_IRQ_C0_9f
 .word OS_CORTEXM_IRQ_C0_a0
 .word OS_CORTEXM_IRQ_C0_a1
 .word OS_CORTEXM_IRQ_C0_a2
 .word OS_CORTEXM_IRQ_C0_a3
 .word OS_CORTEXM_IRQ_C0_a4
 .word OS_CORTEXM_IRQ_C0_a5
 .word OS_CORTEXM_IRQ_C0_a6
 .word OS_CORTEXM_IRQ_C0_a7
 .word OS_CORTEXM_IRQ_C0_a8
 .word OS_CORTEXM_IRQ_C0_a9
 .word OS_CORTEXM_IRQ_C0_aa
 .word OS_CORTEXM_IRQ_C0_ab
 .word OS_CORTEXM_IRQ_C0_ac
 .word OS_CORTEXM_IRQ_C0_ad
 .word OS_CORTEXM_IRQ_C0_ae
 .word OS_CORTEXM_IRQ_C0_af
 .word OS_CORTEXM_IRQ_C0_b0
 .word OS_CORTEXM_IRQ_C0_b1
 .word OS_CORTEXM_IRQ_C0_b2
 .word OS_CORTEXM_IRQ_C0_b3
 .word OS_CORTEXM_IRQ_C0_b4
 .word OS_CORTEXM_IRQ_C0_b5
 .word OS_CORTEXM_IRQ_C0_b6
 .word OS_CORTEXM_IRQ_C0_b7
 .word OS_CORTEXM_IRQ_C0_b8
 .word OS_CORTEXM_IRQ_C0_b9
 .word OS_CORTEXM_IRQ_C0_ba
 .word OS_CORTEXM_IRQ_C0_bb
 .word OS_CORTEXM_IRQ_C0_bc
 .word OS_CORTEXM_IRQ_C0_bd
 .word OS_CORTEXM_IRQ_C0_be
 .word OS_CORTEXM_IRQ_C0_bf
 .word OS_CORTEXM_IRQ_C0_c0
 .word OS_CORTEXM_IRQ_C0_c1
 .word OS_CORTEXM_IRQ_C0_c2
 .word OS_CORTEXM_IRQ_C0_c3
 .word OS_CORTEXM_IRQ_C0_c4
 .word OS_CORTEXM_IRQ_C0_c5
 .word OS_CORTEXM_IRQ_C0_c6
 .word OS_CORTEXM_IRQ_C0_c7
 .word OS_CORTEXM_IRQ_C0_c8
 .word OS_CORTEXM_IRQ_C0_c9
 .word OS_CORTEXM_IRQ_C0_ca
 .word OS_CORTEXM_IRQ_C0_cb
 .word OS_CORTEXM_IRQ_C0_cc
 .word OS_CORTEXM_IRQ_C0_cd
 .word OS_CORTEXM_IRQ_C0_ce
 .word OS_CORTEXM_IRQ_C0_cf
 .word OS_CORTEXM_IRQ_C0_d0
 .word OS_CORTEXM_IRQ_C0_d1
 .word OS_CORTEXM_IRQ_C0_d2
 .word OS_CORTEXM_IRQ_C0_d3
 .word OS_CORTEXM_IRQ_C0_d4
 .word OS_CORTEXM_IRQ_C0_d5
 .word OS_CORTEXM_IRQ_C0_d6
 .word OS_CORTEXM_IRQ_C0_d7
 .word OS_CORTEXM_IRQ_C0_d8
 .word OS_CORTEXM_IRQ_C0_d9
 .word OS_CORTEXM_IRQ_C0_da
 .word OS_CORTEXM_IRQ_C0_db
 .word OS_CORTEXM_IRQ_C0_dc
 .word OS_CORTEXM_IRQ_C0_dd
 .word OS_CORTEXM_IRQ_C0_de
 .word OS_CORTEXM_IRQ_C0_df
 .word OS_CORTEXM_IRQ_C0_e0
 .word OS_CORTEXM_IRQ_C0_e1
 .word OS_CORTEXM_IRQ_C0_e2
 .word OS_CORTEXM_IRQ_C0_e3
 .word OS_CORTEXM_IRQ_C0_e4
 .word OS_CORTEXM_IRQ_C0_e5
 .word OS_CORTEXM_IRQ_C0_e6
 .word OS_CORTEXM_IRQ_C0_e7
 .word OS_CORTEXM_IRQ_C0_e8
 .word OS_CORTEXM_IRQ_C0_e9
 .word OS_CORTEXM_IRQ_C0_ea
 .word OS_CORTEXM_IRQ_C0_eb
 .word OS_CORTEXM_IRQ_C0_ec
 .word OS_CORTEXM_IRQ_C0_ed
 .word OS_CORTEXM_IRQ_C0_ee
 .word OS_CORTEXM_IRQ_C0_ef
 .section ".os_text", "ax"
 .align 4

OS_kernelDataAddr0:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_00
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_00, $function
OS_CORTEXM_IRQ_C0_00:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_00, . - OS_CORTEXM_IRQ_C0_00
 .global OS_CORTEXM_IRQ_C0_01
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_01, $function
OS_CORTEXM_IRQ_C0_01:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_01, . - OS_CORTEXM_IRQ_C0_01
 .global OS_CORTEXM_IRQ_C0_02
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_02, $function
OS_CORTEXM_IRQ_C0_02:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_02, . - OS_CORTEXM_IRQ_C0_02
 .global OS_CORTEXM_IRQ_C0_03
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_03, $function
OS_CORTEXM_IRQ_C0_03:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_03, . - OS_CORTEXM_IRQ_C0_03
 .global OS_CORTEXM_IRQ_C0_04
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_04, $function
OS_CORTEXM_IRQ_C0_04:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_04, . - OS_CORTEXM_IRQ_C0_04
 .global OS_CORTEXM_IRQ_C0_05
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_05, $function
OS_CORTEXM_IRQ_C0_05:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_05, . - OS_CORTEXM_IRQ_C0_05
 .global OS_CORTEXM_IRQ_C0_06
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_06, $function
OS_CORTEXM_IRQ_C0_06:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_06, . - OS_CORTEXM_IRQ_C0_06
 .global OS_CORTEXM_IRQ_C0_07
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_07, $function
OS_CORTEXM_IRQ_C0_07:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_07, . - OS_CORTEXM_IRQ_C0_07
 .global OS_CORTEXM_IRQ_C0_08
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_08, $function
OS_CORTEXM_IRQ_C0_08:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_08, . - OS_CORTEXM_IRQ_C0_08
 .global OS_CORTEXM_IRQ_C0_09
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_09, $function
OS_CORTEXM_IRQ_C0_09:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_09, . - OS_CORTEXM_IRQ_C0_09
 .global OS_CORTEXM_IRQ_C0_0a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0a, $function
OS_CORTEXM_IRQ_C0_0a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0a, . - OS_CORTEXM_IRQ_C0_0a
 .global OS_CORTEXM_IRQ_C0_0b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0b, $function
OS_CORTEXM_IRQ_C0_0b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0b, . - OS_CORTEXM_IRQ_C0_0b
 .global OS_CORTEXM_IRQ_C0_0c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0c, $function
OS_CORTEXM_IRQ_C0_0c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0c, . - OS_CORTEXM_IRQ_C0_0c
 .global OS_CORTEXM_IRQ_C0_0d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0d, $function
OS_CORTEXM_IRQ_C0_0d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0d, . - OS_CORTEXM_IRQ_C0_0d
 .global OS_CORTEXM_IRQ_C0_0e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0e, $function
OS_CORTEXM_IRQ_C0_0e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0e, . - OS_CORTEXM_IRQ_C0_0e
 .global OS_CORTEXM_IRQ_C0_0f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_0f, $function
OS_CORTEXM_IRQ_C0_0f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_0f, . - OS_CORTEXM_IRQ_C0_0f
 .global OS_CORTEXM_IRQ_C0_10
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_10, $function
OS_CORTEXM_IRQ_C0_10:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_10, . - OS_CORTEXM_IRQ_C0_10
 .global OS_CORTEXM_IRQ_C0_11
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_11, $function
OS_CORTEXM_IRQ_C0_11:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_11, . - OS_CORTEXM_IRQ_C0_11
 .global OS_CORTEXM_IRQ_C0_12
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_12, $function
OS_CORTEXM_IRQ_C0_12:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_12, . - OS_CORTEXM_IRQ_C0_12
 .global OS_CORTEXM_IRQ_C0_13
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_13, $function
OS_CORTEXM_IRQ_C0_13:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_13, . - OS_CORTEXM_IRQ_C0_13
 .global OS_CORTEXM_IRQ_C0_14
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_14, $function
OS_CORTEXM_IRQ_C0_14:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_14, . - OS_CORTEXM_IRQ_C0_14
 .global OS_CORTEXM_IRQ_C0_15
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_15, $function
OS_CORTEXM_IRQ_C0_15:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_15, . - OS_CORTEXM_IRQ_C0_15
 .global OS_CORTEXM_IRQ_C0_16
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_16, $function
OS_CORTEXM_IRQ_C0_16:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_16, . - OS_CORTEXM_IRQ_C0_16
 .global OS_CORTEXM_IRQ_C0_17
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_17, $function
OS_CORTEXM_IRQ_C0_17:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_17, . - OS_CORTEXM_IRQ_C0_17
 .global OS_CORTEXM_IRQ_C0_18
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_18, $function
OS_CORTEXM_IRQ_C0_18:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_18, . - OS_CORTEXM_IRQ_C0_18
 .global OS_CORTEXM_IRQ_C0_19
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_19, $function
OS_CORTEXM_IRQ_C0_19:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_19, . - OS_CORTEXM_IRQ_C0_19
 .global OS_CORTEXM_IRQ_C0_1a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1a, $function
OS_CORTEXM_IRQ_C0_1a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1a, . - OS_CORTEXM_IRQ_C0_1a
 .global OS_CORTEXM_IRQ_C0_1b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1b, $function
OS_CORTEXM_IRQ_C0_1b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1b, . - OS_CORTEXM_IRQ_C0_1b
 .global OS_CORTEXM_IRQ_C0_1c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1c, $function
OS_CORTEXM_IRQ_C0_1c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1c, . - OS_CORTEXM_IRQ_C0_1c
 .global OS_CORTEXM_IRQ_C0_1d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1d, $function
OS_CORTEXM_IRQ_C0_1d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1d, . - OS_CORTEXM_IRQ_C0_1d
 .global OS_CORTEXM_IRQ_C0_1e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1e, $function
OS_CORTEXM_IRQ_C0_1e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1e, . - OS_CORTEXM_IRQ_C0_1e
 .global OS_CORTEXM_IRQ_C0_1f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_1f, $function
OS_CORTEXM_IRQ_C0_1f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_1f, . - OS_CORTEXM_IRQ_C0_1f
 .align 4

OS_kernelDataAddr1:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_20
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_20, $function
OS_CORTEXM_IRQ_C0_20:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_20, . - OS_CORTEXM_IRQ_C0_20
 .global OS_CORTEXM_IRQ_C0_21
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_21, $function
OS_CORTEXM_IRQ_C0_21:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_21, . - OS_CORTEXM_IRQ_C0_21
 .global OS_CORTEXM_IRQ_C0_22
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_22, $function
OS_CORTEXM_IRQ_C0_22:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_22, . - OS_CORTEXM_IRQ_C0_22
 .global OS_CORTEXM_IRQ_C0_23
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_23, $function
OS_CORTEXM_IRQ_C0_23:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_23, . - OS_CORTEXM_IRQ_C0_23
 .global OS_CORTEXM_IRQ_C0_24
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_24, $function
OS_CORTEXM_IRQ_C0_24:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_24, . - OS_CORTEXM_IRQ_C0_24
 .global OS_CORTEXM_IRQ_C0_25
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_25, $function
OS_CORTEXM_IRQ_C0_25:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_25, . - OS_CORTEXM_IRQ_C0_25
 .global OS_CORTEXM_IRQ_C0_26
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_26, $function
OS_CORTEXM_IRQ_C0_26:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_26, . - OS_CORTEXM_IRQ_C0_26
 .global OS_CORTEXM_IRQ_C0_27
 .import OS_Cat2Entry
 .type OS_CORTEXM_IRQ_C0_27, $function
OS_CORTEXM_IRQ_C0_27:
 DispatchInterrupt 3, OS_Cat2Entry, OS_CORTEXM_IntCat2Exit, 2, OS_kernelDataAddr1
 .size OS_CORTEXM_IRQ_C0_27, . - OS_CORTEXM_IRQ_C0_27
 .global OS_CORTEXM_IRQ_C0_28
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_28, $function
OS_CORTEXM_IRQ_C0_28:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_28, . - OS_CORTEXM_IRQ_C0_28
 .global OS_CORTEXM_IRQ_C0_29
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_29, $function
OS_CORTEXM_IRQ_C0_29:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_29, . - OS_CORTEXM_IRQ_C0_29
 .global OS_CORTEXM_IRQ_C0_2a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2a, $function
OS_CORTEXM_IRQ_C0_2a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2a, . - OS_CORTEXM_IRQ_C0_2a
 .global OS_CORTEXM_IRQ_C0_2b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2b, $function
OS_CORTEXM_IRQ_C0_2b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2b, . - OS_CORTEXM_IRQ_C0_2b
 .global OS_CORTEXM_IRQ_C0_2c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2c, $function
OS_CORTEXM_IRQ_C0_2c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2c, . - OS_CORTEXM_IRQ_C0_2c
 .global OS_CORTEXM_IRQ_C0_2d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2d, $function
OS_CORTEXM_IRQ_C0_2d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2d, . - OS_CORTEXM_IRQ_C0_2d
 .global OS_CORTEXM_IRQ_C0_2e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2e, $function
OS_CORTEXM_IRQ_C0_2e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2e, . - OS_CORTEXM_IRQ_C0_2e
 .global OS_CORTEXM_IRQ_C0_2f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_2f, $function
OS_CORTEXM_IRQ_C0_2f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_2f, . - OS_CORTEXM_IRQ_C0_2f
 .global OS_CORTEXM_IRQ_C0_30
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_30, $function
OS_CORTEXM_IRQ_C0_30:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_30, . - OS_CORTEXM_IRQ_C0_30
 .global OS_CORTEXM_IRQ_C0_31
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_31, $function
OS_CORTEXM_IRQ_C0_31:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_31, . - OS_CORTEXM_IRQ_C0_31
 .global OS_CORTEXM_IRQ_C0_32
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_32, $function
OS_CORTEXM_IRQ_C0_32:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_32, . - OS_CORTEXM_IRQ_C0_32
 .global OS_CORTEXM_IRQ_C0_33
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_33, $function
OS_CORTEXM_IRQ_C0_33:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_33, . - OS_CORTEXM_IRQ_C0_33
 .global OS_CORTEXM_IRQ_C0_34
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_34, $function
OS_CORTEXM_IRQ_C0_34:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_34, . - OS_CORTEXM_IRQ_C0_34
 .global OS_CORTEXM_IRQ_C0_35
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_35, $function
OS_CORTEXM_IRQ_C0_35:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_35, . - OS_CORTEXM_IRQ_C0_35
 .global OS_CORTEXM_IRQ_C0_36
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_36, $function
OS_CORTEXM_IRQ_C0_36:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_36, . - OS_CORTEXM_IRQ_C0_36
 .global OS_CORTEXM_IRQ_C0_37
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_37, $function
OS_CORTEXM_IRQ_C0_37:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_37, . - OS_CORTEXM_IRQ_C0_37
 .global OS_CORTEXM_IRQ_C0_38
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_38, $function
OS_CORTEXM_IRQ_C0_38:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_38, . - OS_CORTEXM_IRQ_C0_38
 .global OS_CORTEXM_IRQ_C0_39
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_39, $function
OS_CORTEXM_IRQ_C0_39:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_39, . - OS_CORTEXM_IRQ_C0_39
 .global OS_CORTEXM_IRQ_C0_3a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3a, $function
OS_CORTEXM_IRQ_C0_3a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3a, . - OS_CORTEXM_IRQ_C0_3a
 .global OS_CORTEXM_IRQ_C0_3b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3b, $function
OS_CORTEXM_IRQ_C0_3b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3b, . - OS_CORTEXM_IRQ_C0_3b
 .global OS_CORTEXM_IRQ_C0_3c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3c, $function
OS_CORTEXM_IRQ_C0_3c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3c, . - OS_CORTEXM_IRQ_C0_3c
 .global OS_CORTEXM_IRQ_C0_3d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3d, $function
OS_CORTEXM_IRQ_C0_3d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3d, . - OS_CORTEXM_IRQ_C0_3d
 .global OS_CORTEXM_IRQ_C0_3e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3e, $function
OS_CORTEXM_IRQ_C0_3e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3e, . - OS_CORTEXM_IRQ_C0_3e
 .global OS_CORTEXM_IRQ_C0_3f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_3f, $function
OS_CORTEXM_IRQ_C0_3f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_3f, . - OS_CORTEXM_IRQ_C0_3f
 .align 4

OS_kernelDataAddr2:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_40
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_40, $function
OS_CORTEXM_IRQ_C0_40:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_40, . - OS_CORTEXM_IRQ_C0_40
 .global OS_CORTEXM_IRQ_C0_41
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_41, $function
OS_CORTEXM_IRQ_C0_41:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_41, . - OS_CORTEXM_IRQ_C0_41
 .global OS_CORTEXM_IRQ_C0_42
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_42, $function
OS_CORTEXM_IRQ_C0_42:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_42, . - OS_CORTEXM_IRQ_C0_42
 .global OS_CORTEXM_IRQ_C0_43
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_43, $function
OS_CORTEXM_IRQ_C0_43:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_43, . - OS_CORTEXM_IRQ_C0_43
 .global OS_CORTEXM_IRQ_C0_44
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_44, $function
OS_CORTEXM_IRQ_C0_44:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_44, . - OS_CORTEXM_IRQ_C0_44
 .global OS_CORTEXM_IRQ_C0_45
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_45, $function
OS_CORTEXM_IRQ_C0_45:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_45, . - OS_CORTEXM_IRQ_C0_45
 .global OS_CORTEXM_IRQ_C0_46
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_46, $function
OS_CORTEXM_IRQ_C0_46:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_46, . - OS_CORTEXM_IRQ_C0_46
 .global OS_CORTEXM_IRQ_C0_47
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_47, $function
OS_CORTEXM_IRQ_C0_47:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_47, . - OS_CORTEXM_IRQ_C0_47
 .global OS_CORTEXM_IRQ_C0_48
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_48, $function
OS_CORTEXM_IRQ_C0_48:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_48, . - OS_CORTEXM_IRQ_C0_48
 .global OS_CORTEXM_IRQ_C0_49
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_49, $function
OS_CORTEXM_IRQ_C0_49:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_49, . - OS_CORTEXM_IRQ_C0_49
 .global OS_CORTEXM_IRQ_C0_4a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4a, $function
OS_CORTEXM_IRQ_C0_4a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4a, . - OS_CORTEXM_IRQ_C0_4a
 .global OS_CORTEXM_IRQ_C0_4b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4b, $function
OS_CORTEXM_IRQ_C0_4b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4b, . - OS_CORTEXM_IRQ_C0_4b
 .global OS_CORTEXM_IRQ_C0_4c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4c, $function
OS_CORTEXM_IRQ_C0_4c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4c, . - OS_CORTEXM_IRQ_C0_4c
 .global OS_CORTEXM_IRQ_C0_4d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4d, $function
OS_CORTEXM_IRQ_C0_4d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4d, . - OS_CORTEXM_IRQ_C0_4d
 .global OS_CORTEXM_IRQ_C0_4e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4e, $function
OS_CORTEXM_IRQ_C0_4e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4e, . - OS_CORTEXM_IRQ_C0_4e
 .global OS_CORTEXM_IRQ_C0_4f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_4f, $function
OS_CORTEXM_IRQ_C0_4f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_4f, . - OS_CORTEXM_IRQ_C0_4f
 .global OS_CORTEXM_IRQ_C0_50
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_50, $function
OS_CORTEXM_IRQ_C0_50:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_50, . - OS_CORTEXM_IRQ_C0_50
 .global OS_CORTEXM_IRQ_C0_51
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_51, $function
OS_CORTEXM_IRQ_C0_51:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_51, . - OS_CORTEXM_IRQ_C0_51
 .global OS_CORTEXM_IRQ_C0_52
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_52, $function
OS_CORTEXM_IRQ_C0_52:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_52, . - OS_CORTEXM_IRQ_C0_52
 .global OS_CORTEXM_IRQ_C0_53
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_53, $function
OS_CORTEXM_IRQ_C0_53:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_53, . - OS_CORTEXM_IRQ_C0_53
 .global OS_CORTEXM_IRQ_C0_54
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_54, $function
OS_CORTEXM_IRQ_C0_54:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_54, . - OS_CORTEXM_IRQ_C0_54
 .global OS_CORTEXM_IRQ_C0_55
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_55, $function
OS_CORTEXM_IRQ_C0_55:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_55, . - OS_CORTEXM_IRQ_C0_55
 .global OS_CORTEXM_IRQ_C0_56
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_56, $function
OS_CORTEXM_IRQ_C0_56:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_56, . - OS_CORTEXM_IRQ_C0_56
 .global OS_CORTEXM_IRQ_C0_57
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_57, $function
OS_CORTEXM_IRQ_C0_57:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_57, . - OS_CORTEXM_IRQ_C0_57
 .global OS_CORTEXM_IRQ_C0_58
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_58, $function
OS_CORTEXM_IRQ_C0_58:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_58, . - OS_CORTEXM_IRQ_C0_58
 .global OS_CORTEXM_IRQ_C0_59
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_59, $function
OS_CORTEXM_IRQ_C0_59:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_59, . - OS_CORTEXM_IRQ_C0_59
 .global OS_CORTEXM_IRQ_C0_5a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5a, $function
OS_CORTEXM_IRQ_C0_5a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5a, . - OS_CORTEXM_IRQ_C0_5a
 .global OS_CORTEXM_IRQ_C0_5b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5b, $function
OS_CORTEXM_IRQ_C0_5b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5b, . - OS_CORTEXM_IRQ_C0_5b
 .global OS_CORTEXM_IRQ_C0_5c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5c, $function
OS_CORTEXM_IRQ_C0_5c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5c, . - OS_CORTEXM_IRQ_C0_5c
 .global OS_CORTEXM_IRQ_C0_5d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5d, $function
OS_CORTEXM_IRQ_C0_5d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5d, . - OS_CORTEXM_IRQ_C0_5d
 .global OS_CORTEXM_IRQ_C0_5e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5e, $function
OS_CORTEXM_IRQ_C0_5e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5e, . - OS_CORTEXM_IRQ_C0_5e
 .global OS_CORTEXM_IRQ_C0_5f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_5f, $function
OS_CORTEXM_IRQ_C0_5f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_5f, . - OS_CORTEXM_IRQ_C0_5f
 .align 4

OS_kernelDataAddr3:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_60
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_60, $function
OS_CORTEXM_IRQ_C0_60:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_60, . - OS_CORTEXM_IRQ_C0_60
 .global OS_CORTEXM_IRQ_C0_61
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_61, $function
OS_CORTEXM_IRQ_C0_61:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_61, . - OS_CORTEXM_IRQ_C0_61
 .global OS_CORTEXM_IRQ_C0_62
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_62, $function
OS_CORTEXM_IRQ_C0_62:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_62, . - OS_CORTEXM_IRQ_C0_62
 .global OS_CORTEXM_IRQ_C0_63
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_63, $function
OS_CORTEXM_IRQ_C0_63:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_63, . - OS_CORTEXM_IRQ_C0_63
 .global OS_CORTEXM_IRQ_C0_64
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_64, $function
OS_CORTEXM_IRQ_C0_64:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_64, . - OS_CORTEXM_IRQ_C0_64
 .global OS_CORTEXM_IRQ_C0_65
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_65, $function
OS_CORTEXM_IRQ_C0_65:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_65, . - OS_CORTEXM_IRQ_C0_65
 .global OS_CORTEXM_IRQ_C0_66
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_66, $function
OS_CORTEXM_IRQ_C0_66:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_66, . - OS_CORTEXM_IRQ_C0_66
 .global OS_CORTEXM_IRQ_C0_67
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_67, $function
OS_CORTEXM_IRQ_C0_67:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_67, . - OS_CORTEXM_IRQ_C0_67
 .global OS_CORTEXM_IRQ_C0_68
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_68, $function
OS_CORTEXM_IRQ_C0_68:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_68, . - OS_CORTEXM_IRQ_C0_68
 .global OS_CORTEXM_IRQ_C0_69
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_69, $function
OS_CORTEXM_IRQ_C0_69:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_69, . - OS_CORTEXM_IRQ_C0_69
 .global OS_CORTEXM_IRQ_C0_6a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_6a, $function
OS_CORTEXM_IRQ_C0_6a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_6a, . - OS_CORTEXM_IRQ_C0_6a
 .global OS_CORTEXM_IRQ_C0_6b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_6b, $function
OS_CORTEXM_IRQ_C0_6b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_6b, . - OS_CORTEXM_IRQ_C0_6b
 .global OS_CORTEXM_IRQ_C0_6c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_6c, $function
OS_CORTEXM_IRQ_C0_6c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_6c, . - OS_CORTEXM_IRQ_C0_6c
 .global OS_CORTEXM_IRQ_C0_6d
 .import OS_Cat2Entry
 .type OS_CORTEXM_IRQ_C0_6d, $function
OS_CORTEXM_IRQ_C0_6d:
 DispatchInterrupt 2, OS_Cat2Entry, OS_CORTEXM_IntCat2Exit, 2, OS_kernelDataAddr3
 .size OS_CORTEXM_IRQ_C0_6d, . - OS_CORTEXM_IRQ_C0_6d
 .global OS_CORTEXM_IRQ_C0_6e
 .import OS_Cat2Entry
 .type OS_CORTEXM_IRQ_C0_6e, $function
OS_CORTEXM_IRQ_C0_6e:
 DispatchInterrupt 0, OS_Cat2Entry, OS_CORTEXM_IntCat2Exit, 2, OS_kernelDataAddr3
 .size OS_CORTEXM_IRQ_C0_6e, . - OS_CORTEXM_IRQ_C0_6e
 .global OS_CORTEXM_IRQ_C0_6f
 .import OS_Cat2Entry
 .type OS_CORTEXM_IRQ_C0_6f, $function
OS_CORTEXM_IRQ_C0_6f:
 DispatchInterrupt 1, OS_Cat2Entry, OS_CORTEXM_IntCat2Exit, 2, OS_kernelDataAddr3
 .size OS_CORTEXM_IRQ_C0_6f, . - OS_CORTEXM_IRQ_C0_6f
 .global OS_CORTEXM_IRQ_C0_70
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_70, $function
OS_CORTEXM_IRQ_C0_70:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_70, . - OS_CORTEXM_IRQ_C0_70
 .global OS_CORTEXM_IRQ_C0_71
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_71, $function
OS_CORTEXM_IRQ_C0_71:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_71, . - OS_CORTEXM_IRQ_C0_71
 .global OS_CORTEXM_IRQ_C0_72
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_72, $function
OS_CORTEXM_IRQ_C0_72:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_72, . - OS_CORTEXM_IRQ_C0_72
 .global OS_CORTEXM_IRQ_C0_73
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_73, $function
OS_CORTEXM_IRQ_C0_73:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_73, . - OS_CORTEXM_IRQ_C0_73
 .global OS_CORTEXM_IRQ_C0_74
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_74, $function
OS_CORTEXM_IRQ_C0_74:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_74, . - OS_CORTEXM_IRQ_C0_74
 .global OS_CORTEXM_IRQ_C0_75
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_75, $function
OS_CORTEXM_IRQ_C0_75:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_75, . - OS_CORTEXM_IRQ_C0_75
 .global OS_CORTEXM_IRQ_C0_76
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_76, $function
OS_CORTEXM_IRQ_C0_76:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_76, . - OS_CORTEXM_IRQ_C0_76
 .global OS_CORTEXM_IRQ_C0_77
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_77, $function
OS_CORTEXM_IRQ_C0_77:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_77, . - OS_CORTEXM_IRQ_C0_77
 .global OS_CORTEXM_IRQ_C0_78
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_78, $function
OS_CORTEXM_IRQ_C0_78:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_78, . - OS_CORTEXM_IRQ_C0_78
 .global OS_CORTEXM_IRQ_C0_79
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_79, $function
OS_CORTEXM_IRQ_C0_79:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_79, . - OS_CORTEXM_IRQ_C0_79
 .global OS_CORTEXM_IRQ_C0_7a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7a, $function
OS_CORTEXM_IRQ_C0_7a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7a, . - OS_CORTEXM_IRQ_C0_7a
 .global OS_CORTEXM_IRQ_C0_7b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7b, $function
OS_CORTEXM_IRQ_C0_7b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7b, . - OS_CORTEXM_IRQ_C0_7b
 .global OS_CORTEXM_IRQ_C0_7c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7c, $function
OS_CORTEXM_IRQ_C0_7c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7c, . - OS_CORTEXM_IRQ_C0_7c
 .global OS_CORTEXM_IRQ_C0_7d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7d, $function
OS_CORTEXM_IRQ_C0_7d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7d, . - OS_CORTEXM_IRQ_C0_7d
 .global OS_CORTEXM_IRQ_C0_7e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7e, $function
OS_CORTEXM_IRQ_C0_7e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7e, . - OS_CORTEXM_IRQ_C0_7e
 .global OS_CORTEXM_IRQ_C0_7f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_7f, $function
OS_CORTEXM_IRQ_C0_7f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_7f, . - OS_CORTEXM_IRQ_C0_7f
 .align 4

OS_kernelDataAddr4:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_80
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_80, $function
OS_CORTEXM_IRQ_C0_80:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_80, . - OS_CORTEXM_IRQ_C0_80
 .global OS_CORTEXM_IRQ_C0_81
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_81, $function
OS_CORTEXM_IRQ_C0_81:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_81, . - OS_CORTEXM_IRQ_C0_81
 .global OS_CORTEXM_IRQ_C0_82
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_82, $function
OS_CORTEXM_IRQ_C0_82:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_82, . - OS_CORTEXM_IRQ_C0_82
 .global OS_CORTEXM_IRQ_C0_83
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_83, $function
OS_CORTEXM_IRQ_C0_83:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_83, . - OS_CORTEXM_IRQ_C0_83
 .global OS_CORTEXM_IRQ_C0_84
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_84, $function
OS_CORTEXM_IRQ_C0_84:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_84, . - OS_CORTEXM_IRQ_C0_84
 .global OS_CORTEXM_IRQ_C0_85
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_85, $function
OS_CORTEXM_IRQ_C0_85:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_85, . - OS_CORTEXM_IRQ_C0_85
 .global OS_CORTEXM_IRQ_C0_86
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_86, $function
OS_CORTEXM_IRQ_C0_86:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_86, . - OS_CORTEXM_IRQ_C0_86
 .global OS_CORTEXM_IRQ_C0_87
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_87, $function
OS_CORTEXM_IRQ_C0_87:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_87, . - OS_CORTEXM_IRQ_C0_87
 .global OS_CORTEXM_IRQ_C0_88
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_88, $function
OS_CORTEXM_IRQ_C0_88:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_88, . - OS_CORTEXM_IRQ_C0_88
 .global OS_CORTEXM_IRQ_C0_89
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_89, $function
OS_CORTEXM_IRQ_C0_89:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_89, . - OS_CORTEXM_IRQ_C0_89
 .global OS_CORTEXM_IRQ_C0_8a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8a, $function
OS_CORTEXM_IRQ_C0_8a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8a, . - OS_CORTEXM_IRQ_C0_8a
 .global OS_CORTEXM_IRQ_C0_8b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8b, $function
OS_CORTEXM_IRQ_C0_8b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8b, . - OS_CORTEXM_IRQ_C0_8b
 .global OS_CORTEXM_IRQ_C0_8c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8c, $function
OS_CORTEXM_IRQ_C0_8c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8c, . - OS_CORTEXM_IRQ_C0_8c
 .global OS_CORTEXM_IRQ_C0_8d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8d, $function
OS_CORTEXM_IRQ_C0_8d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8d, . - OS_CORTEXM_IRQ_C0_8d
 .global OS_CORTEXM_IRQ_C0_8e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8e, $function
OS_CORTEXM_IRQ_C0_8e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8e, . - OS_CORTEXM_IRQ_C0_8e
 .global OS_CORTEXM_IRQ_C0_8f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_8f, $function
OS_CORTEXM_IRQ_C0_8f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_8f, . - OS_CORTEXM_IRQ_C0_8f
 .global OS_CORTEXM_IRQ_C0_90
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_90, $function
OS_CORTEXM_IRQ_C0_90:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_90, . - OS_CORTEXM_IRQ_C0_90
 .global OS_CORTEXM_IRQ_C0_91
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_91, $function
OS_CORTEXM_IRQ_C0_91:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_91, . - OS_CORTEXM_IRQ_C0_91
 .global OS_CORTEXM_IRQ_C0_92
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_92, $function
OS_CORTEXM_IRQ_C0_92:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_92, . - OS_CORTEXM_IRQ_C0_92
 .global OS_CORTEXM_IRQ_C0_93
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_93, $function
OS_CORTEXM_IRQ_C0_93:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_93, . - OS_CORTEXM_IRQ_C0_93
 .global OS_CORTEXM_IRQ_C0_94
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_94, $function
OS_CORTEXM_IRQ_C0_94:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_94, . - OS_CORTEXM_IRQ_C0_94
 .global OS_CORTEXM_IRQ_C0_95
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_95, $function
OS_CORTEXM_IRQ_C0_95:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_95, . - OS_CORTEXM_IRQ_C0_95
 .global OS_CORTEXM_IRQ_C0_96
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_96, $function
OS_CORTEXM_IRQ_C0_96:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_96, . - OS_CORTEXM_IRQ_C0_96
 .global OS_CORTEXM_IRQ_C0_97
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_97, $function
OS_CORTEXM_IRQ_C0_97:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_97, . - OS_CORTEXM_IRQ_C0_97
 .global OS_CORTEXM_IRQ_C0_98
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_98, $function
OS_CORTEXM_IRQ_C0_98:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_98, . - OS_CORTEXM_IRQ_C0_98
 .global OS_CORTEXM_IRQ_C0_99
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_99, $function
OS_CORTEXM_IRQ_C0_99:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_99, . - OS_CORTEXM_IRQ_C0_99
 .global OS_CORTEXM_IRQ_C0_9a
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9a, $function
OS_CORTEXM_IRQ_C0_9a:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9a, . - OS_CORTEXM_IRQ_C0_9a
 .global OS_CORTEXM_IRQ_C0_9b
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9b, $function
OS_CORTEXM_IRQ_C0_9b:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9b, . - OS_CORTEXM_IRQ_C0_9b
 .global OS_CORTEXM_IRQ_C0_9c
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9c, $function
OS_CORTEXM_IRQ_C0_9c:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9c, . - OS_CORTEXM_IRQ_C0_9c
 .global OS_CORTEXM_IRQ_C0_9d
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9d, $function
OS_CORTEXM_IRQ_C0_9d:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9d, . - OS_CORTEXM_IRQ_C0_9d
 .global OS_CORTEXM_IRQ_C0_9e
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9e, $function
OS_CORTEXM_IRQ_C0_9e:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9e, . - OS_CORTEXM_IRQ_C0_9e
 .global OS_CORTEXM_IRQ_C0_9f
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_9f, $function
OS_CORTEXM_IRQ_C0_9f:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_9f, . - OS_CORTEXM_IRQ_C0_9f
 .align 4

OS_kernelDataAddr5:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_a0
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a0, $function
OS_CORTEXM_IRQ_C0_a0:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a0, . - OS_CORTEXM_IRQ_C0_a0
 .global OS_CORTEXM_IRQ_C0_a1
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a1, $function
OS_CORTEXM_IRQ_C0_a1:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a1, . - OS_CORTEXM_IRQ_C0_a1
 .global OS_CORTEXM_IRQ_C0_a2
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a2, $function
OS_CORTEXM_IRQ_C0_a2:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a2, . - OS_CORTEXM_IRQ_C0_a2
 .global OS_CORTEXM_IRQ_C0_a3
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a3, $function
OS_CORTEXM_IRQ_C0_a3:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a3, . - OS_CORTEXM_IRQ_C0_a3
 .global OS_CORTEXM_IRQ_C0_a4
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a4, $function
OS_CORTEXM_IRQ_C0_a4:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a4, . - OS_CORTEXM_IRQ_C0_a4
 .global OS_CORTEXM_IRQ_C0_a5
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a5, $function
OS_CORTEXM_IRQ_C0_a5:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a5, . - OS_CORTEXM_IRQ_C0_a5
 .global OS_CORTEXM_IRQ_C0_a6
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a6, $function
OS_CORTEXM_IRQ_C0_a6:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a6, . - OS_CORTEXM_IRQ_C0_a6
 .global OS_CORTEXM_IRQ_C0_a7
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a7, $function
OS_CORTEXM_IRQ_C0_a7:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a7, . - OS_CORTEXM_IRQ_C0_a7
 .global OS_CORTEXM_IRQ_C0_a8
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a8, $function
OS_CORTEXM_IRQ_C0_a8:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a8, . - OS_CORTEXM_IRQ_C0_a8
 .global OS_CORTEXM_IRQ_C0_a9
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_a9, $function
OS_CORTEXM_IRQ_C0_a9:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_a9, . - OS_CORTEXM_IRQ_C0_a9
 .global OS_CORTEXM_IRQ_C0_aa
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_aa, $function
OS_CORTEXM_IRQ_C0_aa:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_aa, . - OS_CORTEXM_IRQ_C0_aa
 .global OS_CORTEXM_IRQ_C0_ab
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ab, $function
OS_CORTEXM_IRQ_C0_ab:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ab, . - OS_CORTEXM_IRQ_C0_ab
 .global OS_CORTEXM_IRQ_C0_ac
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ac, $function
OS_CORTEXM_IRQ_C0_ac:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ac, . - OS_CORTEXM_IRQ_C0_ac
 .global OS_CORTEXM_IRQ_C0_ad
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ad, $function
OS_CORTEXM_IRQ_C0_ad:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ad, . - OS_CORTEXM_IRQ_C0_ad
 .global OS_CORTEXM_IRQ_C0_ae
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ae, $function
OS_CORTEXM_IRQ_C0_ae:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ae, . - OS_CORTEXM_IRQ_C0_ae
 .global OS_CORTEXM_IRQ_C0_af
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_af, $function
OS_CORTEXM_IRQ_C0_af:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_af, . - OS_CORTEXM_IRQ_C0_af
 .global OS_CORTEXM_IRQ_C0_b0
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b0, $function
OS_CORTEXM_IRQ_C0_b0:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b0, . - OS_CORTEXM_IRQ_C0_b0
 .global OS_CORTEXM_IRQ_C0_b1
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b1, $function
OS_CORTEXM_IRQ_C0_b1:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b1, . - OS_CORTEXM_IRQ_C0_b1
 .global OS_CORTEXM_IRQ_C0_b2
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b2, $function
OS_CORTEXM_IRQ_C0_b2:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b2, . - OS_CORTEXM_IRQ_C0_b2
 .global OS_CORTEXM_IRQ_C0_b3
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b3, $function
OS_CORTEXM_IRQ_C0_b3:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b3, . - OS_CORTEXM_IRQ_C0_b3
 .global OS_CORTEXM_IRQ_C0_b4
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b4, $function
OS_CORTEXM_IRQ_C0_b4:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b4, . - OS_CORTEXM_IRQ_C0_b4
 .global OS_CORTEXM_IRQ_C0_b5
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b5, $function
OS_CORTEXM_IRQ_C0_b5:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b5, . - OS_CORTEXM_IRQ_C0_b5
 .global OS_CORTEXM_IRQ_C0_b6
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b6, $function
OS_CORTEXM_IRQ_C0_b6:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b6, . - OS_CORTEXM_IRQ_C0_b6
 .global OS_CORTEXM_IRQ_C0_b7
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b7, $function
OS_CORTEXM_IRQ_C0_b7:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b7, . - OS_CORTEXM_IRQ_C0_b7
 .global OS_CORTEXM_IRQ_C0_b8
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b8, $function
OS_CORTEXM_IRQ_C0_b8:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b8, . - OS_CORTEXM_IRQ_C0_b8
 .global OS_CORTEXM_IRQ_C0_b9
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_b9, $function
OS_CORTEXM_IRQ_C0_b9:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_b9, . - OS_CORTEXM_IRQ_C0_b9
 .global OS_CORTEXM_IRQ_C0_ba
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ba, $function
OS_CORTEXM_IRQ_C0_ba:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ba, . - OS_CORTEXM_IRQ_C0_ba
 .global OS_CORTEXM_IRQ_C0_bb
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_bb, $function
OS_CORTEXM_IRQ_C0_bb:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_bb, . - OS_CORTEXM_IRQ_C0_bb
 .global OS_CORTEXM_IRQ_C0_bc
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_bc, $function
OS_CORTEXM_IRQ_C0_bc:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_bc, . - OS_CORTEXM_IRQ_C0_bc
 .global OS_CORTEXM_IRQ_C0_bd
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_bd, $function
OS_CORTEXM_IRQ_C0_bd:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_bd, . - OS_CORTEXM_IRQ_C0_bd
 .global OS_CORTEXM_IRQ_C0_be
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_be, $function
OS_CORTEXM_IRQ_C0_be:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_be, . - OS_CORTEXM_IRQ_C0_be
 .global OS_CORTEXM_IRQ_C0_bf
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_bf, $function
OS_CORTEXM_IRQ_C0_bf:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_bf, . - OS_CORTEXM_IRQ_C0_bf
 .align 4

OS_kernelDataAddr6:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_c0
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c0, $function
OS_CORTEXM_IRQ_C0_c0:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c0, . - OS_CORTEXM_IRQ_C0_c0
 .global OS_CORTEXM_IRQ_C0_c1
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c1, $function
OS_CORTEXM_IRQ_C0_c1:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c1, . - OS_CORTEXM_IRQ_C0_c1
 .global OS_CORTEXM_IRQ_C0_c2
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c2, $function
OS_CORTEXM_IRQ_C0_c2:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c2, . - OS_CORTEXM_IRQ_C0_c2
 .global OS_CORTEXM_IRQ_C0_c3
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c3, $function
OS_CORTEXM_IRQ_C0_c3:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c3, . - OS_CORTEXM_IRQ_C0_c3
 .global OS_CORTEXM_IRQ_C0_c4
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c4, $function
OS_CORTEXM_IRQ_C0_c4:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c4, . - OS_CORTEXM_IRQ_C0_c4
 .global OS_CORTEXM_IRQ_C0_c5
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c5, $function
OS_CORTEXM_IRQ_C0_c5:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c5, . - OS_CORTEXM_IRQ_C0_c5
 .global OS_CORTEXM_IRQ_C0_c6
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c6, $function
OS_CORTEXM_IRQ_C0_c6:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c6, . - OS_CORTEXM_IRQ_C0_c6
 .global OS_CORTEXM_IRQ_C0_c7
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c7, $function
OS_CORTEXM_IRQ_C0_c7:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c7, . - OS_CORTEXM_IRQ_C0_c7
 .global OS_CORTEXM_IRQ_C0_c8
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c8, $function
OS_CORTEXM_IRQ_C0_c8:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c8, . - OS_CORTEXM_IRQ_C0_c8
 .global OS_CORTEXM_IRQ_C0_c9
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_c9, $function
OS_CORTEXM_IRQ_C0_c9:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_c9, . - OS_CORTEXM_IRQ_C0_c9
 .global OS_CORTEXM_IRQ_C0_ca
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ca, $function
OS_CORTEXM_IRQ_C0_ca:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ca, . - OS_CORTEXM_IRQ_C0_ca
 .global OS_CORTEXM_IRQ_C0_cb
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_cb, $function
OS_CORTEXM_IRQ_C0_cb:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_cb, . - OS_CORTEXM_IRQ_C0_cb
 .global OS_CORTEXM_IRQ_C0_cc
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_cc, $function
OS_CORTEXM_IRQ_C0_cc:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_cc, . - OS_CORTEXM_IRQ_C0_cc
 .global OS_CORTEXM_IRQ_C0_cd
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_cd, $function
OS_CORTEXM_IRQ_C0_cd:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_cd, . - OS_CORTEXM_IRQ_C0_cd
 .global OS_CORTEXM_IRQ_C0_ce
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ce, $function
OS_CORTEXM_IRQ_C0_ce:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ce, . - OS_CORTEXM_IRQ_C0_ce
 .global OS_CORTEXM_IRQ_C0_cf
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_cf, $function
OS_CORTEXM_IRQ_C0_cf:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_cf, . - OS_CORTEXM_IRQ_C0_cf
 .global OS_CORTEXM_IRQ_C0_d0
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d0, $function
OS_CORTEXM_IRQ_C0_d0:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d0, . - OS_CORTEXM_IRQ_C0_d0
 .global OS_CORTEXM_IRQ_C0_d1
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d1, $function
OS_CORTEXM_IRQ_C0_d1:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d1, . - OS_CORTEXM_IRQ_C0_d1
 .global OS_CORTEXM_IRQ_C0_d2
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d2, $function
OS_CORTEXM_IRQ_C0_d2:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d2, . - OS_CORTEXM_IRQ_C0_d2
 .global OS_CORTEXM_IRQ_C0_d3
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d3, $function
OS_CORTEXM_IRQ_C0_d3:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d3, . - OS_CORTEXM_IRQ_C0_d3
 .global OS_CORTEXM_IRQ_C0_d4
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d4, $function
OS_CORTEXM_IRQ_C0_d4:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d4, . - OS_CORTEXM_IRQ_C0_d4
 .global OS_CORTEXM_IRQ_C0_d5
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d5, $function
OS_CORTEXM_IRQ_C0_d5:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d5, . - OS_CORTEXM_IRQ_C0_d5
 .global OS_CORTEXM_IRQ_C0_d6
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d6, $function
OS_CORTEXM_IRQ_C0_d6:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d6, . - OS_CORTEXM_IRQ_C0_d6
 .global OS_CORTEXM_IRQ_C0_d7
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d7, $function
OS_CORTEXM_IRQ_C0_d7:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d7, . - OS_CORTEXM_IRQ_C0_d7
 .global OS_CORTEXM_IRQ_C0_d8
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d8, $function
OS_CORTEXM_IRQ_C0_d8:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d8, . - OS_CORTEXM_IRQ_C0_d8
 .global OS_CORTEXM_IRQ_C0_d9
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_d9, $function
OS_CORTEXM_IRQ_C0_d9:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_d9, . - OS_CORTEXM_IRQ_C0_d9
 .global OS_CORTEXM_IRQ_C0_da
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_da, $function
OS_CORTEXM_IRQ_C0_da:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_da, . - OS_CORTEXM_IRQ_C0_da
 .global OS_CORTEXM_IRQ_C0_db
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_db, $function
OS_CORTEXM_IRQ_C0_db:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_db, . - OS_CORTEXM_IRQ_C0_db
 .global OS_CORTEXM_IRQ_C0_dc
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_dc, $function
OS_CORTEXM_IRQ_C0_dc:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_dc, . - OS_CORTEXM_IRQ_C0_dc
 .global OS_CORTEXM_IRQ_C0_dd
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_dd, $function
OS_CORTEXM_IRQ_C0_dd:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_dd, . - OS_CORTEXM_IRQ_C0_dd
 .global OS_CORTEXM_IRQ_C0_de
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_de, $function
OS_CORTEXM_IRQ_C0_de:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_de, . - OS_CORTEXM_IRQ_C0_de
 .global OS_CORTEXM_IRQ_C0_df
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_df, $function
OS_CORTEXM_IRQ_C0_df:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_df, . - OS_CORTEXM_IRQ_C0_df
 .align 4

OS_kernelDataAddr7:
 .word OS_kernel_ptr
 .global OS_CORTEXM_IRQ_C0_e0
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e0, $function
OS_CORTEXM_IRQ_C0_e0:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e0, . - OS_CORTEXM_IRQ_C0_e0
 .global OS_CORTEXM_IRQ_C0_e1
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e1, $function
OS_CORTEXM_IRQ_C0_e1:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e1, . - OS_CORTEXM_IRQ_C0_e1
 .global OS_CORTEXM_IRQ_C0_e2
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e2, $function
OS_CORTEXM_IRQ_C0_e2:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e2, . - OS_CORTEXM_IRQ_C0_e2
 .global OS_CORTEXM_IRQ_C0_e3
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e3, $function
OS_CORTEXM_IRQ_C0_e3:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e3, . - OS_CORTEXM_IRQ_C0_e3
 .global OS_CORTEXM_IRQ_C0_e4
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e4, $function
OS_CORTEXM_IRQ_C0_e4:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e4, . - OS_CORTEXM_IRQ_C0_e4
 .global OS_CORTEXM_IRQ_C0_e5
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e5, $function
OS_CORTEXM_IRQ_C0_e5:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e5, . - OS_CORTEXM_IRQ_C0_e5
 .global OS_CORTEXM_IRQ_C0_e6
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e6, $function
OS_CORTEXM_IRQ_C0_e6:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e6, . - OS_CORTEXM_IRQ_C0_e6
 .global OS_CORTEXM_IRQ_C0_e7
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e7, $function
OS_CORTEXM_IRQ_C0_e7:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e7, . - OS_CORTEXM_IRQ_C0_e7
 .global OS_CORTEXM_IRQ_C0_e8
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e8, $function
OS_CORTEXM_IRQ_C0_e8:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e8, . - OS_CORTEXM_IRQ_C0_e8
 .global OS_CORTEXM_IRQ_C0_e9
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_e9, $function
OS_CORTEXM_IRQ_C0_e9:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_e9, . - OS_CORTEXM_IRQ_C0_e9
 .global OS_CORTEXM_IRQ_C0_ea
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ea, $function
OS_CORTEXM_IRQ_C0_ea:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ea, . - OS_CORTEXM_IRQ_C0_ea
 .global OS_CORTEXM_IRQ_C0_eb
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_eb, $function
OS_CORTEXM_IRQ_C0_eb:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_eb, . - OS_CORTEXM_IRQ_C0_eb
 .global OS_CORTEXM_IRQ_C0_ec
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ec, $function
OS_CORTEXM_IRQ_C0_ec:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ec, . - OS_CORTEXM_IRQ_C0_ec
 .global OS_CORTEXM_IRQ_C0_ed
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ed, $function
OS_CORTEXM_IRQ_C0_ed:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ed, . - OS_CORTEXM_IRQ_C0_ed
 .global OS_CORTEXM_IRQ_C0_ee
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ee, $function
OS_CORTEXM_IRQ_C0_ee:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ee, . - OS_CORTEXM_IRQ_C0_ee
 .global OS_CORTEXM_IRQ_C0_ef
 .import OS_UnknownInterrupt
 .type OS_CORTEXM_IRQ_C0_ef, $function
OS_CORTEXM_IRQ_C0_ef:
 b DispatchUnknownInterrupt
 .size OS_CORTEXM_IRQ_C0_ef, . - OS_CORTEXM_IRQ_C0_ef

