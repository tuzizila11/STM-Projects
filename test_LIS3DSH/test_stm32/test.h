/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.h
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

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <string.h>
#include "test_USART.h"
#include "STM32_Config.h"
#include "test_External_Functions.h"
#include "test_EXTI.h"
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "LIS3DSH.h"
#include "getBuffPtr.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T buff;                       /* '<S2>/Telemetry' */
  uint16_T USART_Send;                 /* '<S2>/USART_Send' */
  uint16_T nbChar;                     /* '<S2>/Telemetry' */
} B_test;

/* Real-time Model Data Structure */
struct tag_RTM_test {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_test test_B;

/* External function called from main */
extern void test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void test_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void test_initialize(void);
extern void test_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_test *const test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test'
 * '<S1>'   : 'test/MATLAB Function2'
 * '<S2>'   : 'test/Subsystem'
 * '<S3>'   : 'test/Subsystem/MATLAB Function1'
 * '<S4>'   : 'test/Subsystem/Telemetry'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test.h
 */
