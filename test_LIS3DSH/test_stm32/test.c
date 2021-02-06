/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
 *
 * Code generated for Simulink model :test.
 *
 * Model version      : 1.459
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (May 28 2020)
 * C/C++ source code generated on  : Wed Sep  9 18:08:47 2020
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "test.h"
#include "test_private.h"

/* Block signals (default storage) */
B_test test_B;

/* Real-time model */
RT_MODEL_test test_M_;
RT_MODEL_test *const test_M = &test_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(test_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_M->Timing.TaskCounters.TID[1])++;
  if ((test_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [1.0s, 0.0s] */
    test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void test_step0(void)                  /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void test_step1(void)                  /* Sample time: [1.0s, 0.0s] */
{
  accelInit();
}

/* Model step wrapper function for compatibility with a static main program */
void test_step(int_T tid)
{
  switch (tid) {
   case 0 :
    test_step0();
    break;

   case 1 :
    test_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test));

  /* block I/O */
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test));

  /* user code (Start function Body) */

  /* USART3 initialization for send. */
  USART3_Tx_Initialization();

  {
    /* External interrupt function registering. */
    EXTI_Callback[0] = EXTI0_Callback;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test.c
 */
