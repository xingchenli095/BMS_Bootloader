#################################################################
#
# $Id: S32K344EVB_Q172.mak 38213 2022-10-18 07:31:55Z syns274107 $
#
# This makefile contains board-specific definitions and rules.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
##################################################################

############ TOOLCHAIN mapping ##############
OS_TOOLCHAIN=$(TOOLCHAIN)

ifeq ($(TOOLCHAIN),gcc)
OS_TOOLCHAIN=gnu
else ifeq ($(TOOLCHAIN),multi)
OS_TOOLCHAIN=ghs
endif

##################################################################
# DEFINITIONS

ifeq ($(OS_BOARD_DIR), )
OS_BOARD_DIR=$(BOARD_PROJECT_PATH)
endif

include $(OS_BOARD_DIR)\common.mak

CC_INCLUDE_PATH      += $(OS_BOARD_DIR)
CPP_INCLUDE_PATH     += $(OS_BOARD_DIR)
ASM_INCLUDE_PATH     += $(OS_BOARD_DIR)

CC_FILES_TO_BUILD    += $(OS_BOARD_DIR)\board.c
ASM_FILES_TO_BUILD   += $(OS_BOARD_DIR)\boardAsm.s
EXCLUDE_MAKE_DEPEND  += $(OS_BOARD_DIR)\boardAsm.s

LINK_CONST_CODE_TARGET ?= FLASH

# Setup config parameter ######################################################
# Boot from ROM or RAM ?
ifeq ($(LINK_CONST_CODE_TARGET),RAM)
LINK_VARIANT := ram
LDGEN_INC_OPT += -disableRomInit
CC_OPT += -DBOARD_INIT_DATA_SECTION=0
else
LINK_VARIANT := flash
CC_OPT += -DBOARD_INIT_DATA_SECTION=1
endif


## Defines for linker file generation for memory protected systems ##
ifeq ($(OS_TOOLCHAIN),gnu)
LINK_OPT += -Wl,--undefined=CORTEXMExceptionTable_C0
LINK_OPT += -Wl,--undefined=CORTEXMInterruptTable_C0
LINK_OPT += -Wl,--entry=boardResetStart
else ifeq ($(OS_TOOLCHAIN),ghs)
LINK_OPT += -u CORTEXMInterruptTable_C0
LINK_OPT += -u CORTEXMExceptionTable_C0
LINK_OPT += -e boardResetStart
else
$(error "Invalid / unsupported toolchain.")
endif

ifneq ($(OS_KERNEL_TYPE),FUNCTION_CALL)

LOC_FILE_SUFFIX=ldscript
OS_GENLD = $(AutosarOS_CORE_PATH)/bin/genld$(OS_HYPHEN)$(CPU).pl
LOC_FILE = $(PROJECT_ROOT)/output/generated/$(OS_ARCH)$(OS_HYPHEN)$(OS_TOOLCHAIN).$(LOC_FILE_SUFFIX)

# check if text region size was provided, if not then assume PROTECTION is
# turned off and we set the size to 0 to generate a default alignment
ifeq ($(OS_CORTEXM_GBL_TEXT_REGION_SIZE),)
OS_CORTEXM_GBL_TEXT_REGION_SIZE=0
endif

# check if rodata region size was provided, if not then assume PROTECTION is
# turned off and we set the size to 0 to generate a default alignment
ifeq ($(OS_CORTEXM_GBL_CONST_REGION_SIZE),)
OS_CORTEXM_GBL_CONST_REGION_SIZE=0
endif

# check if data region size was provided, if not then assume PROTECTION is
# turned off and we set the size to 0 to generate a default alignment
ifeq ($(OS_CORTEXM_GBL_DATA_REGION_SIZE),)
OS_CORTEXM_GBL_DATA_REGION_SIZE=0
endif

# gather all OS applications specific information
OS_APP_SPECS = $(foreach app, $(APPLICATIONS),                                                                                  \
		-app $(app) -size $(OS_CORTEXM_REGION_SIZE_$(app)) -core $(OS_CORE_$(app)) $(app)_gen.$(OBJ_FILE_SUFFIX) $(OBJS_$(app)) \
		$(foreach task,  $(TASKS_$(app)), -task $(task)   -size $(OS_CORTEXM_REGION_SIZE_$(task)) $(OBJS_$(task)))              \
		$(foreach isr,   $(ISRS_$(app)),  -isr $(isr)     -size $(OS_CORTEXM_REGION_SIZE_$(isr)) $(OBJS_$(isr)))                \
	)	$(foreach stack, $(OS_STACKS),    -stack $(stack) -size $(OS_CORTEXM_REGION_SIZE_$(stack)))

LDGEN_INC_OPT += -include $(OS_BOARD_DIR)\board_$(LINK_VARIANT)$(OS_HYPHEN)$(OS_TOOLCHAIN).$(LOC_FILE_SUFFIX)
LDGEN_INC_OPT += -numcores $(OS_N_CORES_MAX)
LDGEN_INC_OPT += -text-region-size $(OS_CORTEXM_GBL_TEXT_REGION_SIZE)
LDGEN_INC_OPT += -const-region-size $(OS_CORTEXM_GBL_CONST_REGION_SIZE)
LDGEN_INC_OPT += -data-region-size $(OS_CORTEXM_GBL_DATA_REGION_SIZE)
LDGEN_INC_OPT += -backend $(OS_TOOLCHAIN)
LDGEN_INC_OPT += $(OS_APP_SPECS)
LDGEN_INC_FILE ?= $(PROJECT_ROOT)/output/make/ldgen.inc
$(LDGEN_INC_FILE):
	$(file > $(LDGEN_INC_FILE),$(subst $\',,$(subst $\",,$(LDGEN_INC_OPT))))

$(LOC_FILE): $(OS_GENLD) $(LDGEN_INC_FILE) $(wildcard $(AutosarOS_CORE_PATH)/bin/Genld*.pm)
	$(PERL_EXE) $(OS_GENLD)		\
		@$(LDGEN_INC_FILE)										\
		-o $@

else

# Function call kernels are not supported.
$(error "Unsupported OS_KERNEL_TYPE.")

endif

# Editor settings - DO NOT DELETE
# vi:set ts=4:
#
