#ifndef FLASHWRAPPERGENERATED_H
#define FLASHWRAPPERGENERATED_H
/*===============================================================================*/
/*                                                                               */
/*                               FLASH layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                              FLASH  configuration                             */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FlashWrapper_Generated.h        */
/*%%  |                             |  %%  \brief FLASH layer implementation     */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/*List the needed include files*/
#include "Flash_Types.h"
#include "Flash_Pub.h"
#include "Fls.h"
#include "Fls_Api.h"
#include "SchM_Fls.h"

/*Retrieve the Low Layer parameters names*/
/******/
/*Init*/
/******/
/*Configurations*/
#define FLW_INIT_ROUTINE_NAME                                                        Fls_Init
#define FLW_INIT_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB(Fls_Init)
#define FLW_INIT_ROUTINE_RETURN                                                      void
#define FLW_INIT_ROUTINE_TYPE_ARG1                                                   const Fls_ConfigType*
#define FLW_INIT_ROUTINE_SIGNATURE                                                   (FLW_INIT_ROUTINE_TYPE_ARG1 ARG1)
#define FLW_INIT_ROUTINE_SIGNATURE_CASTED(ARG1)                                      (FLW_INIT_ROUTINE_TYPE_ARG1) ARG1
/*Arguments wrapping*/
#define FLW_INIT_ROUTINE_CB_IN_ROM(ARG1)                                             FLWCbInROM_T.InitRoutine(FLW_INIT_ROUTINE_SIGNATURE_CASTED(ARG1))

/*******/                                                                            
/*Erase*/                                                                            
/*******/
/*Configurations*/
#define FLW_ERASE_ROUTINE_NAME                                                       Fls_Erase
#define FLW_ERASE_ROUTINE_TYPEDEF                                                    FLW_TYPEDEF_CB(Fls_Erase)
#define FLW_ERASE_ROUTINE_RETURN                                                     Std_ReturnType
#define FLW_ERASE_ROUTINE_TYPE_ARG1                                                  Fls_AddressType
#define FLW_ERASE_ROUTINE_TYPE_ARG2                                                  Fls_LengthType
#define FLW_ERASE_ROUTINE_SIGNATURE                                                  (FLW_ERASE_ROUTINE_TYPE_ARG1 ARG1, FLW_ERASE_ROUTINE_TYPE_ARG2 ARG2)
#define FLW_ERASE_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2)                                (FLW_ERASE_ROUTINE_TYPE_ARG1) ARG1, (FLW_ERASE_ROUTINE_TYPE_ARG2) ARG2
/*Critical section management*/
#define FLW_ERASE_IS_CRITICAL_SECTION_MNGT
/*Sector Size*/
#define FLW_ERASE_SECTOR_SIZE                                                        8192

/*Return existence*/
#define FLW_ERASE_ROUTINE_IS_RETURN_EXIST
/*Arguments wrapping*/
#define FLW_ERASE_ROUTINE_CB_IN_ROM(ARG1,ARG2)                                       FLWCbInROM_T.EraseRoutine(FLW_ERASE_ROUTINE_SIGNATURE_CASTED(ARG1,\
                                                                                                                                                  ARG2))

/*******/
/*Write*/
/*******/
/*Configurations*/
#define FLW_WRITE_ROUTINE_NAME                                                       Fls_Write
#define FLW_WRITE_ROUTINE_TYPEDEF                                                    FLW_TYPEDEF_CB(Fls_Write)
#define FLW_WRITE_ROUTINE_RETURN                                                     Std_ReturnType
#define FLW_WRITE_ROUTINE_TYPE_ARG1                                                  Fls_AddressType
#define FLW_WRITE_ROUTINE_TYPE_ARG2                                                  const uint8*
#define FLW_WRITE_ROUTINE_TYPE_ARG3                                                  Fls_LengthType
#define FLW_WRITE_ROUTINE_SIGNATURE                                                  (FLW_WRITE_ROUTINE_TYPE_ARG1 ARG1, FLW_WRITE_ROUTINE_TYPE_ARG2 ARG2, FLW_WRITE_ROUTINE_TYPE_ARG3 ARG3)
#define FLW_WRITE_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2,ARG3)                           (FLW_WRITE_ROUTINE_TYPE_ARG1) ARG1, (FLW_WRITE_ROUTINE_TYPE_ARG2) ARG2, (FLW_WRITE_ROUTINE_TYPE_ARG3) ARG3
/*Critical section management*/
#define FLW_WRITE_IS_CRITICAL_SECTION_MNGT
/*Return existence*/
#define FLW_WRITE_ROUTINE_IS_RETURN_EXIST
/*Arguments wrapping*/
#define FLW_WRITE_ROUTINE_CB_IN_ROM(ARG1,ARG2,ARG3)                                  FLWCbInROM_T.WriteRoutine(FLW_WRITE_ROUTINE_SIGNATURE_CASTED(ARG1,\
                                                                                                                                                  ARG3,\
                                                                                                                                                  ARG2))
																																				  

/******/
/*Read*/
/******/
/*Configurations*/
#define FLW_READ_ROUTINE_NAME                                                        Fls_Read
#define FLW_READ_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB(Fls_Read)
#define FLW_READ_ROUTINE_RETURN                                                      Std_ReturnType
#define FLW_READ_ROUTINE_TYPE_ARG1                                                   Fls_AddressType
#define FLW_READ_ROUTINE_TYPE_ARG2                                                   uint8*
#define FLW_READ_ROUTINE_TYPE_ARG3                                                   Fls_LengthType
#define FLW_READ_ROUTINE_SIGNATURE                                                   (FLW_READ_ROUTINE_TYPE_ARG1 ARG1, FLW_READ_ROUTINE_TYPE_ARG2 ARG2, FLW_READ_ROUTINE_TYPE_ARG3 ARG3)
#define FLW_READ_ROUTINE_SIGNATURE_CASTED(ARG1,ARG2,ARG3)                            (FLW_READ_ROUTINE_TYPE_ARG1) ARG1, (FLW_READ_ROUTINE_TYPE_ARG2) ARG2, (FLW_READ_ROUTINE_TYPE_ARG3) ARG3
/*Return existence*/
#define FLW_READ_ROUTINE_IS_RETURN_EXIST
/*Arguments wrapping*/
#define FLW_READ_ROUTINE_CB_IN_ROM(ARG1,ARG2,ARG3)                                   FLWCbInROM_T.ReadRoutine(FLW_READ_ROUTINE_SIGNATURE_CASTED(ARG1,\
                                                                                                                                                ARG3,\
                                                                                                                                                ARG2))

/******/
/*Main*/
/******/
/*Configurations*/
#define FLW_MAIN_ROUTINE_NAME                                                        Fls_MainFunction
#define FLW_MAIN_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB(Fls_MainFunction)
#define FLW_MAIN_ROUTINE_RETURN                                                      void
#define FLW_MAIN_ROUTINE_SIGNATURE                                                   (void)      
#define FLW_MAIN_ROUTINE_SIGNATURE_CASTED()
/*Arguments wrapping*/
#define FLW_MAIN_ROUTINE_CB_IN_ROM()                                                      FLWCbInROM_T.MainRoutine(FLW_MAIN_ROUTINE_SIGNATURE_CASTED())

/***********/
/*JobStatus*/
/***********/
/*Configurations*/
#define FLW_JOBSTATUS_ROUTINE_NAME                                                        Fls_GetJobResult
#define FLW_JOBSTATUS_ROUTINE_TYPEDEF                                                     FLW_TYPEDEF_CB(Fls_GetJobResult)
#define FLW_JOBSTATUS_ROUTINE_RETURN                                                      MemIf_JobResultType
#define FLW_JOBSTATUS_ROUTINE_TYPE_ARG1                                                   void
#define FLW_JOBSTATUS_ROUTINE_SIGNATURE                                                   (void)
#define FLW_JOBSTATUS_ROUTINE_SIGNATURE_CASTED()
/*Return existence*/
#define FLW_JOBSTATUS_ROUTINE_IS_RETURN_EXIST
/*Arguments wrapping*/
#define FLW_JOBSTATUS_ROUTINE_CB_IN_ROM()                                                 FLWCbInROM_T.JobStatusRoutine(FLW_JOBSTATUS_ROUTINE_SIGNATURE_CASTED())


/*******/
/*Dummy*/
/*******/
/*Dummy macro to allow the compilation*/
#define FLW_WRAPPER_INIT(ARG1)
#endif
