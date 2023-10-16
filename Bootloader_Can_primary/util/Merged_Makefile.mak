
### merged from Platforms_Os/SinglecoreOs
# Singlecore OS has the suffix _SCOS for board files
BOARD_SUFFIX := _SCOS

#################################################################
# Common Board_Pub.h is present only once for all Target/Derivate in boards folder
CC_INCLUDE_PATH  += $(PROJECT_ROOT)\source\boards

PREPROCESSOR_DEFINES += production_disclaimer
production_disclaimer_KEY := I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
production_disclaimer_VALUE := 1



TRESOS2_AUTOCONFIGURE_TARGETS :=



PREPROCESSOR_DEFINES += use_sw_vector_mode
use_sw_vector_mode_KEY := USE_SW_VECTOR_MODE
use_sw_vector_mode_VALUE := 1

PREPROCESSOR_DEFINES += Pdur_provide_adjacent_module_vendor_symbolic_names
Pdur_provide_adjacent_module_vendor_symbolic_names_KEY := PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES
Pdur_provide_adjacent_module_vendor_symbolic_names_VALUE := 1

# PREPROCESSOR_DEFINES += flash_inline_define
# flash_inline_define_KEY := _INLINE_
# flash_inline_define_VALUE := inline

ATOMICS_USE_GENERIC_IMPL := 1

# ATOMICS_USER_MULTICORE_CASE
# Assume the single-core case.
PREPROCESSOR_DEFINES += TS_ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_KEY = ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_VALUE = 0
