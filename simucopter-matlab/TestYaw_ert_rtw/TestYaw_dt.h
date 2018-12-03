//
//  TestYaw_dt.h
//
//  Code generation for model "TestYaw".
//
//  Model version              : 1.78
//  Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
//  C++ source code generated on : Wed Jan 10 15:09:22 2018
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
    sizeof(real_T),
    sizeof(real32_T),
    sizeof(int8_T),
    sizeof(uint8_T),
    sizeof(int16_T),
    sizeof(uint16_T),
    sizeof(int32_T),
    sizeof(uint32_T),
    sizeof(boolean_T),
    sizeof(fcn_call_T),
    sizeof(int_T),
    sizeof(pointer_T),
    sizeof(action_T),
    2*sizeof(uint32_T),
    sizeof(Yaw_state_TestYaw_T),
    sizeof(copter_heading_TestYaw_T),
    sizeof(Motors_TestYaw_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
    "real_T",
    "real32_T",
    "int8_T",
    "uint8_T",
    "int16_T",
    "uint16_T",
    "int32_T",
    "uint32_T",
    "boolean_T",
    "fcn_call_T",
    "int_T",
    "pointer_T",
    "action_T",
    "timer_uint32_pair_T",
    "Yaw_state_TestYaw_T",
    "copter_heading_TestYaw_T",
    "Motors_TestYaw_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
    { (char_T *)(&TestYaw_B.HeadingsError), 0, 0, 4 }
    ,

    { (char_T *)(&TestYaw_DW.Scope_PWORK.LoggedData[0]), 11, 0, 7 },

    { (char_T *)(&TestYaw_DW.obj), 14, 0, 1 },

    { (char_T *)(&TestYaw_DW.obj_e0orcglns1), 15, 0, 1 },

    { (char_T *)(&TestYaw_DW.obj_o101f4jt2b), 16, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
    5U,
    rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
    { (char_T *)(&TestYaw_P.Constant1_Value), 0, 0, 4 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
    1U,
    rtPTransitions
};

// [EOF] TestYaw_dt.h
