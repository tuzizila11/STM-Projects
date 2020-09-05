/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dual_motor.h
 *
 * Code generated for Simulink model :dual_motor.
 *
 * Model version      : 1.164
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (May 28 2020)
 * C/C++ source code generated on  : Fri Sep  4 03:57:37 2020
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

#ifndef RTW_HEADER_dual_motor_h_
#define RTW_HEADER_dual_motor_h_
#include <math.h>
#include <string.h>
#include "dual_motor_USART.h"
#include "STM32_Config.h"
#include "dual_motor_External_Functions.h"
#include "dual_motor_EXTI.h"
#include "dual_motor_TIM.h"
#ifndef dual_motor_COMMON_INCLUDES_
# define dual_motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "getBuffPtr.h"
#include "main.h"
#include "stdio.h"
#include "stm32f4xx_hal_rcc.h"
#endif                                 /* dual_motor_COMMON_INCLUDES_ */

#include "dual_motor_types.h"
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
  real_T RateTransition5;              /* '<Root>/Rate Transition5' */
  real_T RateTransition4;              /* '<Root>/Rate Transition4' */
  real_T RateTransition3;              /* '<Root>/Rate Transition3' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T RateTransition10;             /* '<Root>/Rate Transition10' */
  real_T RateTransition9;              /* '<Root>/Rate Transition9' */
  real_T RateTransition8;              /* '<Root>/Rate Transition8' */
  real_T RateTransition6;              /* '<Root>/Rate Transition6' */
  real_T PRESCALER_TIM3;               /* '<S2>/PRESCALER_TIM3' */
  real_T PERIOD_TIM3_CCR1;             /* '<S2>/PERIOD_TIM3_CCR1' */
  real_T Divide;                       /* '<S7>/Divide' */
  real_T Add1;                         /* '<S7>/Add1' */
  real_T Saturation;                   /* '<S48>/Saturation' */
  real_T Subtract;                     /* '<S7>/Subtract' */
  real_T PRESCALER_TIM4;               /* '<S2>/PRESCALER_TIM4' */
  real_T PERIOD_TIM4_CCR1;             /* '<S2>/PERIOD_TIM4_CCR1' */
  real_T Divide_d;                     /* '<S8>/Divide' */
  real_T Add1_g;                       /* '<S8>/Add1' */
  real_T Saturation_n;                 /* '<S97>/Saturation' */
  real_T Subtract_p;                   /* '<S8>/Subtract' */
  real_T setpoint;                     /* '<S1>/Chart' */
  uint32_T Timers1_o1;                 /* '<Root>/Timers1' */
  uint32_T Timers1_o2;                 /* '<Root>/Timers1' */
  uint32_T Timers3_o1;                 /* '<Root>/Timers3' */
  uint32_T Timers3_o2;                 /* '<Root>/Timers3' */
  uint32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  uint32_T RateTransition7;            /* '<Root>/Rate Transition7' */
  uint32_T buff;                       /* '<S3>/Telemetry' */
  uint32_T DataTypeConversion;         /* '<S7>/Data Type Conversion' */
  uint32_T DataTypeConversion_c;       /* '<S8>/Data Type Conversion' */
  uint16_T USART_Send;                 /* '<S3>/USART_Send' */
  uint16_T nbChar;                     /* '<S3>/Telemetry' */
} B_dual_motor;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S90>/Integrator' */
  real_T Filter_DSTATE_l;              /* '<S85>/Filter' */
  volatile real_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
  volatile real_T RateTransition5_Buffer1;/* '<Root>/Rate Transition5' */
  volatile real_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile real_T RateTransition_Buffer1;/* '<Root>/Rate Transition' */
  volatile real_T RateTransition10_Buffer0;/* '<Root>/Rate Transition10' */
  volatile real_T RateTransition10_Buffer1;/* '<Root>/Rate Transition10' */
  volatile real_T RateTransition2_Buffer0;/* '<Root>/Rate Transition2' */
  volatile real_T RateTransition2_Buffer1;/* '<Root>/Rate Transition2' */
  volatile real_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  volatile real_T RateTransition3_Buffer1;/* '<Root>/Rate Transition3' */
  volatile real_T RateTransition4_Buffer0;/* '<Root>/Rate Transition4' */
  volatile real_T RateTransition4_Buffer1;/* '<Root>/Rate Transition4' */
  volatile real_T RateTransition6_Buffer0;/* '<Root>/Rate Transition6' */
  volatile real_T RateTransition6_Buffer1;/* '<Root>/Rate Transition6' */
  volatile real_T RateTransition8_Buffer0;/* '<Root>/Rate Transition8' */
  volatile real_T RateTransition8_Buffer1;/* '<Root>/Rate Transition8' */
  volatile real_T RateTransition9_Buffer0;/* '<Root>/Rate Transition9' */
  volatile real_T RateTransition9_Buffer1;/* '<Root>/Rate Transition9' */
  uint32_T PIDLoop_PREV_T;             /* '<Root>/PID Loop' */
  volatile int8_T RateTransition5_write_buf;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition5_read_buf;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition5_last_buf_wr;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition_write_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_read_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_last_buf_wr;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition10_write_buf;/* '<Root>/Rate Transition10' */
  volatile int8_T RateTransition10_read_buf;/* '<Root>/Rate Transition10' */
  volatile int8_T RateTransition10_last_buf_wr;/* '<Root>/Rate Transition10' */
  volatile int8_T RateTransition2_write_buf;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition2_read_buf;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition2_last_buf_wr;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition3_write_buf;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition3_read_buf;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition3_last_buf_wr;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition4_write_buf;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition4_read_buf;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition4_last_buf_wr;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition6_write_buf;/* '<Root>/Rate Transition6' */
  volatile int8_T RateTransition6_read_buf;/* '<Root>/Rate Transition6' */
  volatile int8_T RateTransition6_last_buf_wr;/* '<Root>/Rate Transition6' */
  volatile int8_T RateTransition8_write_buf;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition8_read_buf;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition8_last_buf_wr;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition9_write_buf;/* '<Root>/Rate Transition9' */
  volatile int8_T RateTransition9_read_buf;/* '<Root>/Rate Transition9' */
  volatile int8_T RateTransition9_last_buf_wr;/* '<Root>/Rate Transition9' */
  uint8_T is_active_c5_dual_motor;     /* '<S1>/Chart' */
  uint8_T is_c5_dual_motor;            /* '<S1>/Chart' */
} DW_dual_motor;

/* Real-time Model Data Structure */
struct tag_RTM_dual_motor {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick2;
  } Timing;
};

/* Block signals (default storage) */
extern B_dual_motor dual_motor_B;

/* Block states (default storage) */
extern DW_dual_motor dual_motor_DW;

/* Model entry point functions */
extern void dual_motor_initialize(void);
extern void dual_motor_step(void);

/* Real-time Model object */
extern RT_MODEL_dual_motor *const dual_motor_M;

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
 * '<Root>' : 'dual_motor'
 * '<S1>'   : 'dual_motor/Change Setpoint'
 * '<S2>'   : 'dual_motor/PID Loop'
 * '<S3>'   : 'dual_motor/Send Data'
 * '<S4>'   : 'dual_motor/Change Setpoint/Chart'
 * '<S5>'   : 'dual_motor/PID Loop/Gains'
 * '<S6>'   : 'dual_motor/PID Loop/Get APB1 Freq'
 * '<S7>'   : 'dual_motor/PID Loop/Motor PID Control'
 * '<S8>'   : 'dual_motor/PID Loop/Motor PID Control1'
 * '<S9>'   : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller'
 * '<S10>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/D Gain'
 * '<S12>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Filter'
 * '<S13>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/I Gain'
 * '<S15>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Integrator'
 * '<S18>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/N Copy'
 * '<S20>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/N Gain'
 * '<S21>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/P Copy'
 * '<S22>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Saturation'
 * '<S25>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Sum'
 * '<S27>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/preSat Signal'
 * '<S34>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S35>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/D Gain/External Parameters'
 * '<S36>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/I Gain/External Parameters'
 * '<S39>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Integrator/Discrete'
 * '<S42>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/N Copy/Disabled'
 * '<S44>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/N Gain/External Parameters'
 * '<S45>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/P Copy/Disabled'
 * '<S46>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S47>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Saturation/Enabled'
 * '<S49>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S55>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'dual_motor/PID Loop/Motor PID Control/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller'
 * '<S59>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Anti-windup'
 * '<S60>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/D Gain'
 * '<S61>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Filter'
 * '<S62>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Filter ICs'
 * '<S63>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/I Gain'
 * '<S64>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain'
 * '<S65>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S66>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator'
 * '<S67>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator ICs'
 * '<S68>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/N Copy'
 * '<S69>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/N Gain'
 * '<S70>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/P Copy'
 * '<S71>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Parallel P Gain'
 * '<S72>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Reset Signal'
 * '<S73>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation'
 * '<S74>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation Fdbk'
 * '<S75>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Sum'
 * '<S76>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Sum Fdbk'
 * '<S77>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode'
 * '<S78>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode Sum'
 * '<S79>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Integral'
 * '<S80>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Ngain'
 * '<S81>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/postSat Signal'
 * '<S82>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/preSat Signal'
 * '<S83>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S84>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/D Gain/External Parameters'
 * '<S85>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S86>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/I Gain/External Parameters'
 * '<S88>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S89>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator/Discrete'
 * '<S91>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S92>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/N Copy/Disabled'
 * '<S93>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/N Gain/External Parameters'
 * '<S94>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/P Copy/Disabled'
 * '<S95>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S96>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Reset Signal/Disabled'
 * '<S97>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation/Enabled'
 * '<S98>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S99>'  : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Sum/Sum_PID'
 * '<S100>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S101>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S102>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S104>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S106>' : 'dual_motor/PID Loop/Motor PID Control1/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S107>' : 'dual_motor/Send Data/Telemetry'
 */
#endif                                 /* RTW_HEADER_dual_motor_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] dual_motor.h
 */
