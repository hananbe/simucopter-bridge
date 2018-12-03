//
// File: TestYaw.h
//
// Code generated for Simulink model 'TestYaw'.
//
// Model version                  : 1.78
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Wed Jan 10 15:09:22 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TestYaw_h_
#define RTW_HEADER_TestYaw_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef TestYaw_COMMON_INCLUDES_
# define TestYaw_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "simucopter.h"
#endif                                 // TestYaw_COMMON_INCLUDES_

#include "TestYaw_types.h"

// Shared type includes
#include "multiword_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

// Block signals (auto storage)
typedef struct {
    real_T HeadingsError;              // '<Root>/Sum'
    real_T correction;                 // '<Root>/correction'
    real_T CopterHeadng;               // '<Root>/Current Heading'
    real_T yawstate;                   // '<Root>/Copter Yaw State'
} B_TestYaw_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
    struct {
        void *LoggedData[4];
    } Scope_PWORK;                     // '<Root>/Scope'

    void *Set_Motors_PWORK;            // '<Root>/Set_Motors'
    void *CurrentHeading_PWORK;        // '<Root>/Current Heading'
    void *CopterYawState_PWORK;        // '<Root>/Copter Yaw State'
    Yaw_state_TestYaw_T obj;           // '<Root>/Copter Yaw State'
    copter_heading_TestYaw_T obj_e0orcglns1;// '<Root>/Current Heading'
    Motors_TestYaw_T obj_o101f4jt2b;   // '<Root>/Set_Motors'
} DW_TestYaw_T;

// Parameters (auto storage)
struct P_TestYaw_T_ {
    real_T Constant1_Value;            // Expression: 0
                                       //  Referenced by: '<Root>/Constant1'

    real_T Constant_Value;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant'

    real_T Constant2_Value;            // Expression: 0.1
                                       //  Referenced by: '<Root>/Constant2'

    real_T ExpectedHeading_Value;      // Expression: 0
                                       //  Referenced by: '<Root>/Expected Heading'

};

// Real-time Model Data Structure
struct tag_RTM_TestYaw_T {
    const char_T *errorStatus;
    RTWExtModeInfo *extModeInfo;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
        uint32_T checksums[4];
    } Sizes;

    //
    //  SpecialInfo:
    //  The following substructure contains special information
    //  related to other components that are dependent on RTW.

    struct {
        const void *mappingInfo;
    } SpecialInfo;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
        time_T taskTime0;
        uint32_T clockTick0;
        time_T stepSize0;
        time_T tFinal;
        boolean_T stopRequestedFlag;
    } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

    extern P_TestYaw_T TestYaw_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_TestYaw_T TestYaw_B;

// Block states (auto storage)
extern DW_TestYaw_T TestYaw_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

    // Model entry point functions
    extern void TestYaw_initialize(void);
    extern void TestYaw_step(void);
    extern void TestYaw_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

    extern RT_MODEL_TestYaw_T *const TestYaw_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'TestYaw'
//  '<S1>'   : 'TestYaw/MATLAB Function'
//  '<S2>'   : 'TestYaw/correction'

#endif                                 // RTW_HEADER_TestYaw_h_

//
// File trailer for generated code.
//
// [EOF]
//
