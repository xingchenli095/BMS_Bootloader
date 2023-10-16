#
# \file
#
# \brief AUTOSAR Make
#
# This file contains the implementation of the AUTOSAR
# module Make.
#
# \version 4.0.30
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# This makefile exports parameters derived from the
# project configuration into variables for make

# Only include these variables once
ifndef TRESOS2_ECU_ID

# project name in workspace
TRESOS2_PROJECT_NAME := Bootloader_Can
TRESOS2_ECU_ID       := demoBoot_Essentials_JLR_can_asr

# target and derivate
TARGET   := CORTEXM
DERIVATE := S32K34X

ifeq (,$(ENABLED_PLUGINS))
# In case enabled modules are NOT specified explicitly
# use all enabled modules (including modules, that are NOT generated)
PROJECT_MODULES := APP Atomics BM BaseNXP Base BlPduR CanIf CanSM CanTp Can ComM Compiler Det Dio EcuC Flash Fls Make McalExt Mcu MemMap Os PduR Platforms Port ProgOEMInd Prog Resource SA Uds
else
# otherwise only use generated modules
PROJECT_MODULES := APP Atomics BM BaseNXP Base BlPduR CanIf CanSM CanTp Can ComM Compiler Det Dio EcuC Flash Fls Make McalExt Mcu MemMap Os PduR Platforms Port ProgOEMInd Prog Resource SA Uds
endif

# add tresos2 make plugin if not yet contained in SOFTWARE_MODULES
SOFTWARE_MODULES := $(strip $(filter-out tresos2,$(SOFTWARE_MODULES)) tresos2)

# There might already modules added to SOFTWARE_MODULES. So add only what's
# not yet contained SOFTWARE_MODULES.
# Duplicated entries are removed by the sort function.
SOFTWARE_MODULES += $(sort $(filter-out $(SOFTWARE_MODULES),$(PROJECT_MODULES)))

# variables defining module versions and locations of the plugins
APP_VARIANT   := TS_TxDxM3I8R0
APP_CORE_PATH := $(TRESOS_BASE)/plugins/APP_TS_TxDxM3I8R0
Atomics_VARIANT   := TS_TxDxM1I0R0
Atomics_CORE_PATH := $(TRESOS_BASE)/plugins/Atomics_TS_TxDxM1I0R0
BM_VARIANT   := TS_TxDxM1I15R0
BM_CORE_PATH := $(TRESOS_BASE)/plugins/BM_TS_TxDxM1I15R0
BaseNXP_VARIANT   := TS_T40D34M20I1R0
Base_VARIANT   := TS_TxDxM5I2R0
Base_CORE_PATH := $(TRESOS_BASE)/plugins/Base_TS_TxDxM5I2R0
BlPduR_VARIANT   := TS_TxDxM0I27R0
BlPduR_CORE_PATH := $(TRESOS_BASE)/plugins/BlPduR_TS_TxDxM0I27R0
CanIf_VARIANT   := TS_TxDxM6I10R0
CanIf_CORE_PATH := $(TRESOS_BASE)/plugins/CanIf_TS_TxDxM6I10R0
CanSM_VARIANT   := TS_TxDxM3I7R0
CanSM_CORE_PATH := $(TRESOS_BASE)/plugins/CanSM_TS_TxDxM3I7R0
CanTp_VARIANT   := TS_TxDxM6I8R0
CanTp_CORE_PATH := $(TRESOS_BASE)/plugins/CanTp_TS_TxDxM6I8R0
Can_VARIANT   := TS_T40D34M20I1R0
ComM_VARIANT   := TS_T0D1M4I0R0
ComM_CORE_PATH := $(TRESOS_BASE)/plugins/ComM_TS_T0D1M4I0R0
Compiler_VARIANT   := TS_TxDxM1I0R0
Compiler_CORE_PATH := $(TRESOS_BASE)/plugins/Compiler_TS_TxDxM1I0R0
Det_VARIANT   := TS_TxDxM6I5R0
Det_CORE_PATH := $(TRESOS_BASE)/plugins/Det_TS_TxDxM6I5R0
Dio_VARIANT   := TS_T40D34M20I1R0
EcuC_VARIANT   := TS_TxDxM5I0R0
EcuC_CORE_PATH := $(TRESOS_BASE)/plugins/EcuC_TS_TxDxM5I0R0
Flash_VARIANT   := TS_T40D37M30I0R0
Flash_CORE_PATH := $(TRESOS_BASE)/plugins/Flash_TS_T40D37M30I0R0
Fls_VARIANT   := TS_T40D34M20I1R0
Make_VARIANT   := TS_TxDxM4I0R0
Make_CORE_PATH := $(TRESOS_BASE)/plugins/Make_TS_TxDxM4I0R0
McalExt_VARIANT   := TS_T40DxM1I0R0
McalExt_CORE_PATH := $(TRESOS_BASE)/plugins/McalExt_TS_T40DxM1I0R0
Mcu_VARIANT   := TS_T40D34M20I1R0
MemMap_VARIANT   := TS_TxDxM1I3R0
MemMap_CORE_PATH := $(TRESOS_BASE)/plugins/MemMap_TS_TxDxM1I3R0
Os_VARIANT   := TS_T40D37M6I1R0_AS45
Os_CORE_PATH := $(TRESOS_BASE)/plugins/Os_TS_T40D37M6I1R0_AS45
PduR_VARIANT   := TS_TxDxM5I3R0
PduR_CORE_PATH := $(TRESOS_BASE)/plugins/PduR_TS_TxDxM5I3R0
Platforms_VARIANT   := TS_T40DxM4I0R0
Platforms_CORE_PATH := $(TRESOS_BASE)/plugins/Platforms_TS_T40DxM4I0R0
Port_VARIANT   := TS_T40D34M20I1R0
ProgOEMInd_VARIANT   := TS_TxDxM1I12R0
ProgOEMInd_CORE_PATH := $(TRESOS_BASE)/plugins/ProgOEMInd_TS_TxDxM1I12R0
Prog_VARIANT   := TS_TxDxM2I51R0
Prog_CORE_PATH := $(TRESOS_BASE)/plugins/Prog_TS_TxDxM2I51R0
Resource_VARIANT   := TS_T40D34M20I1R0
Resource_CORE_PATH := $(TRESOS_BASE)/plugins/Resource_TS_T40D34M20I1R0
SA_VARIANT   := TS_TxDxM1I20R0
SA_CORE_PATH := $(TRESOS_BASE)/plugins/SA_TS_TxDxM1I20R0
Uds_VARIANT   := TS_TxDxM3I17R0
Uds_CORE_PATH := $(TRESOS_BASE)/plugins/Uds_TS_TxDxM3I17R0

# variables defining module generation output paths
# default output path for generated files
override GEN_OUTPUT_PATH  := $(subst \,/,$(PROJECT_ROOT)/output/generated)
# list of all output paths of generated files
override GEN_OUTPUT_PATHS := $(subst \,/,\
 $(GEN_OUTPUT_PATH)\
)

# output path for files created by the build environment
PROJECT_OUTPUT_PATH ?= $(abspath $(GEN_OUTPUT_PATH)/..)

# for compatibility reasons we need the AUTOSAR_BASE_OUTPUT_PATH
AUTOSAR_BASE_OUTPUT_PATH ?= $(GEN_OUTPUT_PATH)
override AUTOSAR_BASE_OUTPUT_PATH := $(subst \,/,$(AUTOSAR_BASE_OUTPUT_PATH))

endif
# Set Os Vendor to EB
OS_VENDOR := EB
