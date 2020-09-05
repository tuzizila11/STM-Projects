/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_nucleo.h
 *
 * Code generated for Simulink model :motor_nucleo.
 *
 * Model version      : 1.132
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (May 28 2020)
 * C/C++ source code generated on  : Sat Aug 29 13:39:39 2020
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

#ifndef RTW_HEADER_motor_nucleo_h_
#define RTW_HEADER_motor_nucleo_h_
#include <math.h>
#include <string.h>
#include "motor_nucleo_TIM.h"
#include "motor_nucleo_USART.h"
#include "STM32_Config.h"
#include "motor_nucleo_External_Functions.h"
#ifndef motor_nucleo_COMMON_INCLUDES_
# define motor_nucleo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "getBuffPtr.h"
#include "main.h"
#include "stdio.h"
#include "stm32f4xx_hal_rcc.h"
#endif                                 /* motor_nucleo_COMMON_INCLUDES_ */

#include "motor_nucleo_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition4;              /* '<Root>/Rate Transition4' */
  real_T RateTransition3;              /* '<Root>/Rate Transition3' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T PRESCALER_TIM3;               /* '<S1>/PRESCALER_TIM3' */
  real_T PERIOD_TIM3;                  /* '<S1>/PERIOD_TIM3' */
  real_T Divide;                       /* '<S1>/Divide' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T Saturation;                   /* '<S44>/Saturation' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  uint32_T Timers1_o2;                 /* '<Root>/Timers1' */
  uint32_T Timers1_o3;                 /* '<Root>/Timers1' */
  uint32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  uint32_T buff;                       /* '<S2>/Telemetry' */
  uint32_T DataTypeConversion;         /* '<S1>/Data Type Conversion' */
  uint16_T USART_Send;                 /* '<S2>/USART_Send' */
  uint16_T nbChar;                     /* '<S2>/Telemetry' */
} B_motor_nucleo;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  volatile real_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile real_T RateTransition_Buffer1;/* '<Root>/Rate Transition' */
  volatile real_T RateTransition2_Buffer0;/* '<Root>/Rate Transition2' */
  volatile real_T RateTransition2_Buffer1;/* '<Root>/Rate Transition2' */
  volatile real_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  volatile real_T RateTransition3_Buffer1;/* '<Root>/Rate Transition3' */
  volatile real_T RateTransition4_Buffer0;/* '<Root>/Rate Transition4' */
  volatile real_T RateTransition4_Buffer1;/* '<Root>/Rate Transition4' */
  uint32_T PIDLoop_PREV_T;             /* '<Root>/PID Loop' */
  volatile int8_T RateTransition_write_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_read_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_last_buf_wr;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition2_write_buf;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition2_read_buf;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition2_last_buf_wr;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition3_write_buf;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition3_read_buf;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition3_last_buf_wr;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition4_write_buf;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition4_read_buf;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition4_last_buf_wr;/* '<Root>/Rate Transition4' */
} DW_motor_nucleo;

/* Real-time Model Data Structure */
struct tag_RTM_motor_nucleo {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_motor_nucleo motor_nucleo_B;

/* Block states (default storage) */
extern DW_motor_nucleo motor_nucleo_DW;

/* Model entry point functions */
extern void motor_nucleo_initialize(void);
extern void motor_nucleo_step(void);

/* Real-time Model object */
extern RT_MODEL_motor_nucleo *const motor_nucleo_M;

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
 * '<Root>' : 'motor_nucleo'
 * '<S1>'   : 'motor_nucleo/PID Loop'
 * '<S2>'   : 'motor_nucleo/Send Data'
 * '<S3>'   : 'motor_nucleo/PID Loop/Discrete PID Controller'
 * '<S4>'   : 'motor_nucleo/PID Loop/Gains'
 * '<S5>'   : 'motor_nucleo/PID Loop/Get APB1 Freq'
 * '<S6>'   : 'motor_nucleo/PID Loop/Discrete PID Controller/Anti-windup'
 * '<S7>'   : 'motor_nucleo/PID Loop/Discrete PID Controller/D Gain'
 * '<S8>'   : 'motor_nucleo/PID Loop/Discrete PID Controller/Filter'
 * '<S9>'   : 'motor_nucleo/PID Loop/Discrete PID Controller/Filter ICs'
 * '<S10>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/I Gain'
 * '<S11>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Ideal P Gain'
 * '<S12>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Integrator'
 * '<S14>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Integrator ICs'
 * '<S15>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/N Copy'
 * '<S16>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/N Gain'
 * '<S17>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/P Copy'
 * '<S18>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Parallel P Gain'
 * '<S19>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Reset Signal'
 * '<S20>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Saturation'
 * '<S21>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Saturation Fdbk'
 * '<S22>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Sum'
 * '<S23>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Sum Fdbk'
 * '<S24>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tracking Mode'
 * '<S25>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tsamp - Integral'
 * '<S27>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/postSat Signal'
 * '<S29>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/preSat Signal'
 * '<S30>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/D Gain/External Parameters'
 * '<S32>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/I Gain/External Parameters'
 * '<S35>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Integrator/Discrete'
 * '<S38>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/N Copy/Disabled'
 * '<S40>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/N Gain/External Parameters'
 * '<S41>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/P Copy/Disabled'
 * '<S42>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S43>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Saturation/Enabled'
 * '<S45>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S51>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'motor_nucleo/PID Loop/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'motor_nucleo/Send Data/Telemetry'
 */
#endif                                 /* RTW_HEADER_motor_nucleo_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] motor_nucleo.h
 */
