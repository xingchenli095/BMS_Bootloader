#
# \file
#
# \brief AUTOSAR Bootloader_Can
#
# This file contains the implementation of the AUTOSAR
# module Bootloader_Can.
#
# \version 1.0.1
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# BOARD:
# This variable defines the used hardware (it is called board because
# of the usage of evaluation boards).
#
# For example:
# BOARD = eva168_2
#
BOARD_DEFAULT  = S32K344EVB_Q172
BOARD         ?= $(BOARD_DEFAULT)$(BOARD_SUFFIX)

#################################################################
# TARGET:
# default target of this project
TARGET				?= CORTEXM
DERIVATE			?= S32K34X

#################################################################
# TOOLCHAIN:
#
TOOLCHAIN			?= multi

#################################################################
# COMPILER:
# The build structure of the SSC allows to switch the compiler by
# changing the used compiler plugin. A compiler plugin is a set
# of makefile that implements the "Compiler Makefile Interface".
# Up to four makefile belongs to such an interface. These makefiles are:
#
# The variable COMPILER must contain the name of one <compiler_plugin>.
#
# For example:
# COMPILER = tasking_st10
#
COMPILER			?= $(TARGET)_$(DERIVATE)_$(TOOLCHAIN)

#################################################################
# DEPEND_GCC_OPTS:
# The gcc compiler is used to solve the dependencies for all source
# files. The command -make depend- creates a dependency file for
# each source file in the folder [output/depend] Some source files
# contain preprocessor statements which will cause an error if an
# expected macro will not exists. Therefore the variable DEPEND_GCC_OPTS
# allows the definition of macros for the preprocessor of the gcc
# compiler. For example the following macros are necesary to build
# the dependecies for the modules hal and osek:
# osek: -D _MODEL="'s'"
# hal:  -D IO_CPU_FREQ_HZ=$(CPU_FREQUENCY)
# assembler: -x assembler-with-cpp
#
# ATTENTION:
# If the gcc reports any errors by calling the command make depend
# you must add own macros to the variable DEPEND_GCC_OPTS to solve this
# problem.
#

# disables AR release version check in MCAL for all compilers
DEPEND_GCC_OPTS += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK
CC_OPT          += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK
LIBRARIES_LINK_ONLY +=$(TOOLPATH_COMPILER)/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/hard/libgcc.a

#################################################################
# EXCLUDE_MAKE_DEPEND :
# exclude files from dependency processing
#
EXCLUDE_MAKE_DEPEND +=
