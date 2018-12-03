//
// File: TestYaw.cpp
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
#include "TestYaw.h"
#include "TestYaw_private.h"
#include "TestYaw_dt.h"

// Block signals (auto storage)
B_TestYaw_T TestYaw_B;

// Block states (auto storage)
DW_TestYaw_T TestYaw_DW;

// Real-time model
RT_MODEL_TestYaw_T TestYaw_M_;
RT_MODEL_TestYaw_T *const TestYaw_M = &TestYaw_M_;

// Model step function
void TestYaw_step(void)
{
    // Start for MATLABSystem: '<Root>/Set_Motors' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Constant2'
    //   MATLABSystem: '<Root>/Set_Motors'

    if ((TestYaw_P.Constant1_Value >= -1.0) && (TestYaw_P.Constant1_Value <= 1.0))
    {
        copter_motors_set_roll(TestYaw_P.Constant1_Value);
    }

    if ((TestYaw_P.Constant1_Value >= -1.0) && (TestYaw_P.Constant1_Value <= 1.0))
    {
        copter_motors_set_pitch(TestYaw_P.Constant1_Value);
    }

    if ((TestYaw_P.Constant_Value >= -1.0) && (TestYaw_P.Constant_Value <= 1.0))
    {
        copter_motors_set_yaw(TestYaw_P.Constant_Value);
    }

    if ((TestYaw_P.Constant2_Value >= 0.0) && (TestYaw_P.Constant2_Value <= 1.0))
    {
        copter_motors_set_throttle(TestYaw_P.Constant2_Value);
    }

    // End of Start for MATLABSystem: '<Root>/Set_Motors'

    // MATLABSystem: '<Root>/Current Heading' incorporates:
    //   Start for MATLABSystem: '<Root>/Current Heading'

    TestYaw_B.CopterHeadng = copter_get_heading();

    // Sum: '<Root>/Sum' incorporates:
    //   Constant: '<Root>/Expected Heading'

    TestYaw_B.HeadingsError = TestYaw_P.ExpectedHeading_Value -
        TestYaw_B.CopterHeadng;

    // MATLAB Function: '<Root>/correction'
    // MATLAB Function 'correction': '<S2>:1'
    // '<S2>:1:3' if(deg < -20)
    if (TestYaw_B.HeadingsError < -20.0) {
        // '<S2>:1:4' correction = -1;
        TestYaw_B.correction = -1.0;
    } else {
        // '<S2>:1:5' else
        // '<S2>:1:5' if (deg > 20)
        if (TestYaw_B.HeadingsError > 20.0) {
            // '<S2>:1:6' correction = 1;
            TestYaw_B.correction = 1.0;
        } else {
            // '<S2>:1:7' else
            // '<S2>:1:8' correction = 0;
            TestYaw_B.correction = 0.0;
        }
    }

    // End of MATLAB Function: '<Root>/correction'

    // MATLABSystem: '<Root>/Copter Yaw State' incorporates:
    //   Start for MATLABSystem: '<Root>/Copter Yaw State'

    TestYaw_B.yawstate = copter_get_state_yaw();

    // MATLAB Function 'MATLAB Function': '<S1>:1'
    // '<S1>:1:3' if (u == 0)

    // External mode
    rtExtModeUploadCheckTrigger(1);

    {                                  // Sample time: [0.2s, 0.0s]
        rtExtModeUpload(0, TestYaw_M->Timing.taskTime0);
    }

    // signal main to stop simulation
    {                                  // Sample time: [0.2s, 0.0s]
        if ((rtmGetTFinal(TestYaw_M)!=-1) &&
            !((rtmGetTFinal(TestYaw_M)-TestYaw_M->Timing.taskTime0) >
                TestYaw_M->Timing.taskTime0 * (DBL_EPSILON))) {
            rtmSetErrorStatus(TestYaw_M, "Simulation finished");
        }

        if (rtmGetStopRequested(TestYaw_M)) {
            rtmSetErrorStatus(TestYaw_M, "Simulation finished");
        }
    }

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    TestYaw_M->Timing.taskTime0 =
        (++TestYaw_M->Timing.clockTick0) * TestYaw_M->Timing.stepSize0;
}

// Model initialize function
void TestYaw_initialize(void)
{
    // Registration code

    // initialize real-time model
    (void) memset((void *)TestYaw_M, 0,
                  sizeof(RT_MODEL_TestYaw_T));
    rtmSetTFinal(TestYaw_M, -1);
    TestYaw_M->Timing.stepSize0 = 0.2;

    // External mode info
    TestYaw_M->Sizes.checksums[0] = (3573190272U);
    TestYaw_M->Sizes.checksums[1] = (863684852U);
    TestYaw_M->Sizes.checksums[2] = (749334030U);
    TestYaw_M->Sizes.checksums[3] = (987963571U);

    {
        static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
        static RTWExtModeInfo rt_ExtModeInfo;
        static const sysRanDType *systemRan[6];
        TestYaw_M->extModeInfo = (&rt_ExtModeInfo);
        rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
        systemRan[0] = &rtAlwaysEnabled;
        systemRan[1] = &rtAlwaysEnabled;
        systemRan[2] = &rtAlwaysEnabled;
        systemRan[3] = &rtAlwaysEnabled;
        systemRan[4] = &rtAlwaysEnabled;
        systemRan[5] = &rtAlwaysEnabled;
        rteiSetModelMappingInfoPtr(TestYaw_M->extModeInfo,
            &TestYaw_M->SpecialInfo.mappingInfo);
        rteiSetChecksumsPtr(TestYaw_M->extModeInfo, TestYaw_M->Sizes.checksums);
        rteiSetTPtr(TestYaw_M->extModeInfo, rtmGetTPtr(TestYaw_M));
    }

    // block I/O
    (void) memset(((void *) &TestYaw_B), 0,
                  sizeof(B_TestYaw_T));

    // states (dwork)
    (void) memset((void *)&TestYaw_DW, 0,
                  sizeof(DW_TestYaw_T));

    // data type transition information
    {
        static DataTypeTransInfo dtInfo;
        (void) memset((char_T *) &dtInfo, 0,
                      sizeof(dtInfo));
        TestYaw_M->SpecialInfo.mappingInfo = (&dtInfo);
        dtInfo.numDataTypes = 17;
        dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
        dtInfo.dataTypeNames = &rtDataTypeNames[0];

        // Block I/O transition table
        dtInfo.BTransTable = &rtBTransTable;

        // Parameters transition table
        dtInfo.PTransTable = &rtPTransTable;
    }

    // Start for MATLABSystem: '<Root>/Set_Motors'
    TestYaw_DW.obj_o101f4jt2b.isInitialized = 0;
    TestYaw_DW.obj_o101f4jt2b.isInitialized = 1;

    // Start for MATLABSystem: '<Root>/Current Heading'
    TestYaw_DW.obj_e0orcglns1.isInitialized = 0;
    TestYaw_DW.obj_e0orcglns1.isInitialized = 1;

    // Start for MATLABSystem: '<Root>/Copter Yaw State'
    TestYaw_DW.obj.isInitialized = 0;
    TestYaw_DW.obj.isInitialized = 1;

    // user code (Initialize function Body)
    simucopter_init();
}

// Model terminate function
void TestYaw_terminate(void)
{
    // user code (Terminate function Body)
    simucopter_stop();

    // Start for MATLABSystem: '<Root>/Set_Motors' incorporates:
    //   Terminate for MATLABSystem: '<Root>/Set_Motors'

    if (TestYaw_DW.obj_o101f4jt2b.isInitialized == 1) {
        TestYaw_DW.obj_o101f4jt2b.isInitialized = 2;
    }

    // End of Start for MATLABSystem: '<Root>/Set_Motors'

    // Start for MATLABSystem: '<Root>/Current Heading' incorporates:
    //   Terminate for MATLABSystem: '<Root>/Current Heading'

    if (TestYaw_DW.obj_e0orcglns1.isInitialized == 1) {
        TestYaw_DW.obj_e0orcglns1.isInitialized = 2;
    }

    // End of Start for MATLABSystem: '<Root>/Current Heading'

    // Start for MATLABSystem: '<Root>/Copter Yaw State' incorporates:
    //   Terminate for MATLABSystem: '<Root>/Copter Yaw State'

    if (TestYaw_DW.obj.isInitialized == 1) {
        TestYaw_DW.obj.isInitialized = 2;
    }

    // End of Start for MATLABSystem: '<Root>/Copter Yaw State'
}

//
// File trailer for generated code.
//
// [EOF]
//
