//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "TestYaw.h"
#include "TestYaw_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"

// Function prototype declaration
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void baseRateTask(void *arg)
{
    runModel = (rtmGetErrorStatus(TestYaw_M) == (NULL)) && !rtmGetStopRequested
        (TestYaw_M);
    while (runModel) {
        sem_wait(&baserateTaskSem);

        // External mode
        {
            boolean_T rtmStopReq = false;
            rtExtModePauseIfNeeded(TestYaw_M->extModeInfo, 1, &rtmStopReq);
            if (rtmStopReq) {
                rtmSetStopRequested(TestYaw_M, true);
            }

            if (rtmGetStopRequested(TestYaw_M) == true) {
                rtmSetErrorStatus(TestYaw_M, "Simulation finished");
                break;
            }
        }

        // External mode
        {
            boolean_T rtmStopReq = false;
            rtExtModeOneStep(TestYaw_M->extModeInfo, 1, &rtmStopReq);
            if (rtmStopReq) {
                rtmSetStopRequested(TestYaw_M, true);
            }
        }

        TestYaw_step();

        // Get model outputs here
        rtExtModeCheckEndTrigger();
        runModel = (rtmGetErrorStatus(TestYaw_M) == (NULL)) &&
            !rtmGetStopRequested(TestYaw_M);
    }

    runModel = 0;
    terminateTask(arg);
    pthread_exit((void *)0);
}

void exitTask(int sig)
{
    rtmSetErrorStatus(TestYaw_M, "stopping the model");
}

void terminateTask(void *arg)
{
    terminatingmodel = 1;
    printf("**terminating the model**\n");
    fflush(stdout);

    {
        int ret;
        runModel = 0;
    }

    rtExtModeShutdown(1);

    // Disable rt_OneStep() here

    // Terminate model
    TestYaw_terminate();
    sem_post(&stopSem);
}

int main(int argc, char **argv)
{
    printf("**starting the model**\n");
    fflush(stdout);
    rtmSetErrorStatus(TestYaw_M, 0);
    rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

    // Initialize model
    TestYaw_initialize();

    // External mode
    rtSetTFinalForExtMode(&rtmGetTFinal(TestYaw_M));
    rtExtModeCheckInit(1);

    {
        boolean_T rtmStopReq = false;
        rtExtModeWaitForStartPkt(TestYaw_M->extModeInfo, 1, &rtmStopReq);
        if (rtmStopReq) {
            rtmSetStopRequested(TestYaw_M, true);
        }
    }

    rtERTExtModeStartMsg();

    // Call RTOS Initialization funcation
    myRTOSInit(0.2, 0);

    // Wait for stop semaphore
    sem_wait(&stopSem);
    return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
