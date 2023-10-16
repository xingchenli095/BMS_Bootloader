# *****************************************************************************
TOOLPATH_COMPILER ?= 
# *********************Compiler Options******************************************
CC_OPT += -nostartfiles 
CC_OPT += -DOSB_TOOL=OSB_ghs 
CC_OPT += --gnu_asm 
CC_OPT += -DS32K3XX 
CC_OPT += -DI_CACHE_ENABLE 
CC_OPT += -Osize 
CC_OPT += -Wundef 
CC_OPT += --incorrect_pragma_warnings 
CC_OPT += -cpu=cortexm7 
CC_OPT += -Wimplicit-int 
CC_OPT += -DS32K344 
CC_OPT += -DENABLE_FPU 
CC_OPT += -dual_debug 
CC_OPT += -Wshadow 
CC_OPT += -keeptempfiles 
CC_OPT += -c 
CC_OPT += -thumb 
CC_OPT += -fpu=vfpv5_d16 
CC_OPT += --unsigned_chars 
CC_OPT += -DUSE_SW_VECTOR_MODE 
CC_OPT += -DMCAL_ENABLE_USER_MODE_SUPPORT 
CC_OPT += -c99 
CC_OPT += -fsingle  
CC_OPT += -G 
CC_OPT += -Wtrigraphs 
CC_OPT += --no_commons 
CC_OPT += --no_slash_comment 
CC_OPT += --ghstd=last 
CC_OPT += --unsigned_fields 
CC_OPT += -DD_CACHE_ENABLE 
CC_OPT += --no_exceptions 
CC_OPT += --prototype_errors 
CC_OPT += -DGHS 
# *********************Linker Options******************************************
LINK_OPT += -keepmap 
LINK_OPT += -v 
LINK_OPT += -lstartup 
LINK_OPT += -L$(TOOLPATH_COMPILER)/lib/thumb2 
LINK_OPT += -Mn 
LINK_OPT += -delete 
LINK_OPT += -cpu=cortexm7 
LINK_OPT += -lind_sd 
LINK_OPT += -ignore_debug_references 
LINK_OPT += -map 
LINK_OPT += -larch 
# *********************Assembler Options******************************************
ASM_OPT += -preprocess_assembly_files 
ASM_OPT += -DOSB_TOOL=OSB_ghs 
ASM_OPT += -cpu=cortexm7 
ASM_OPT += -list 
ASM_OPT += -c 
ASM_OPT += -fpu=vfpv5_d16 
ASM_OPT += -fsingle  
