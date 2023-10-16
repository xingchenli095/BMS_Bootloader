#ifndef IOC_GEN_LIBCFG_H
#define IOC_GEN_LIBCFG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.1 (advisory)
 * #include directives should only be preceded by preprocessor directives
 * or comments.
 *
 * Reason:
 * The C++ guards allow usage of the OS with a C++-compiler.
 */

/* Deviation MISRAC2012-1 <*> */

#include <public/Ioc_defs.h>

#define IOC_LCFG_KERNEL_TYPE  IOC_AUTOCOREOS
#ifdef __cplusplus
}
#endif
#endif  /* IOC_GEN_LIBCFG_H */
