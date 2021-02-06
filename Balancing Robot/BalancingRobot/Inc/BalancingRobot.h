/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BalancingRobot.h
 *
 * Code generated for Simulink model :BalancingRobot.
 *
 * Model version      : 1.522
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (May 28 2020)
 * C/C++ source code generated on  : Thu Oct  1 17:46:10 2020
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

#ifndef RTW_HEADER_BalancingRobot_h_
#define RTW_HEADER_BalancingRobot_h_
#include <math.h>
#include <string.h>
#include "BalancingRobot_USART.h"
#include "STM32_Config.h"
#include "BalancingRobot_External_Functions.h"
#include "BalancingRobot_EXTI.h"
#include "BalancingRobot_TIM.h"
#ifndef BalancingRobot_COMMON_INCLUDES_
# define BalancingRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MadgwickAHRS.h"
#include "getBuffPtr.h"
#include "main.h"
#include "mpu6050.h"
#include "pid_gains.h"
#include "stdio.h"
#include "stm32f4xx_hal_rcc.h"
#include "string.h"
#endif                                 /* BalancingRobot_COMMON_INCLUDES_ */

#include "BalancingRobot_types.h"

/* GPIOD output mask value declaration. */
extern uint16_t GPIOD_maskWrite;

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
  real_T PRESCALER_TIM3;               /* '<S9>/PRESCALER_TIM3' */
  real_T PERIOD_TIM3_CCR1;             /* '<S9>/PERIOD_TIM3_CCR1' */
  real_T Subtract;                     /* '<S61>/Subtract' */
  real_T PRESCALER_TIM2;               /* '<S9>/PRESCALER_TIM2' */
  real_T PERIOD_TIM2_CCR1;             /* '<S9>/PERIOD_TIM2_CCR1' */
  real_T Subtract_f;                   /* '<S62>/Subtract' */
  uint32_T Timers1_o1;                 /* '<Root>/Timers1' */
  uint32_T Timers1_o2;                 /* '<Root>/Timers1' */
  uint32_T Timers3_o1;                 /* '<Root>/Timers3' */
  uint32_T Timers3_o2;                 /* '<Root>/Timers3' */
  uint32_T buff;                       /* '<S1>/Telemetry' */
  uint16_T USART_Send;                 /* '<S1>/USART_Send' */
  uint16_T nbChar;                     /* '<S1>/Telemetry' */
} B_BalancingRobot;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S42>/Integrator' */
  real_T Filter_DSTATE;                /* '<S37>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S95>/Integrator' */
  real_T Filter_DSTATE_m;              /* '<S90>/Filter' */
  real_T Integrator_DSTATE_j;          /* '<S144>/Integrator' */
  real_T Filter_DSTATE_h;              /* '<S139>/Filter' */
  uint32_T FunctionCallSubsystem_PREV_T;/* '<Root>/Function-Call Subsystem' */
} DW_BalancingRobot;

/* Real-time Model Data Structure */
struct tag_RTM_BalancingRobot {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick2;
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_BalancingRobot BalancingRobot_B;

/* Block states (default storage) */
extern DW_BalancingRobot BalancingRobot_DW;

/* External function called from main */
extern void BalancingRobot_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void BalancingRobot_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void BalancingRobot_initialize(void);
extern void BalancingRobot_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_BalancingRobot *const BalancingRobot_M;

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
 * '<Root>' : 'BalancingRobot'
 * '<S1>'   : 'BalancingRobot/Function-Call Subsystem'
 * '<S2>'   : 'BalancingRobot/If Action Subsystem'
 * '<S3>'   : 'BalancingRobot/MATLAB Function'
 * '<S4>'   : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller'
 * '<S5>'   : 'BalancingRobot/Function-Call Subsystem/Gains'
 * '<S6>'   : 'BalancingRobot/Function-Call Subsystem/If Action Subsystem'
 * '<S7>'   : 'BalancingRobot/Function-Call Subsystem/If Action Subsystem1'
 * '<S8>'   : 'BalancingRobot/Function-Call Subsystem/MATLAB Function1'
 * '<S9>'   : 'BalancingRobot/Function-Call Subsystem/PID Loop'
 * '<S10>'  : 'BalancingRobot/Function-Call Subsystem/Telemetry'
 * '<S11>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Anti-windup'
 * '<S12>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/D Gain'
 * '<S13>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Filter'
 * '<S14>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Filter ICs'
 * '<S15>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/I Gain'
 * '<S16>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Ideal P Gain'
 * '<S17>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Integrator'
 * '<S19>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Integrator ICs'
 * '<S20>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/N Copy'
 * '<S21>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/N Gain'
 * '<S22>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/P Copy'
 * '<S23>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Parallel P Gain'
 * '<S24>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Reset Signal'
 * '<S25>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Saturation'
 * '<S26>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Saturation Fdbk'
 * '<S27>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Sum'
 * '<S28>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Sum Fdbk'
 * '<S29>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tracking Mode'
 * '<S30>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tsamp - Integral'
 * '<S32>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/postSat Signal'
 * '<S34>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/preSat Signal'
 * '<S35>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S36>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/D Gain/External Parameters'
 * '<S37>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S38>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/I Gain/External Parameters'
 * '<S40>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S41>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Integrator/Discrete'
 * '<S43>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S44>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/N Copy/Disabled'
 * '<S45>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/N Gain/External Parameters'
 * '<S46>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/P Copy/Disabled'
 * '<S47>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S48>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Reset Signal/Disabled'
 * '<S49>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Saturation/Enabled'
 * '<S50>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S51>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Sum/Sum_PID'
 * '<S52>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S53>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S54>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S56>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S58>'  : 'BalancingRobot/Function-Call Subsystem/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S59>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Gains'
 * '<S60>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Get APB1 Freq'
 * '<S61>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control'
 * '<S62>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1'
 * '<S63>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller'
 * '<S64>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Anti-windup'
 * '<S65>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/D Gain'
 * '<S66>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Filter'
 * '<S67>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Filter ICs'
 * '<S68>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/I Gain'
 * '<S69>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain'
 * '<S70>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S71>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Integrator'
 * '<S72>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Integrator ICs'
 * '<S73>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/N Copy'
 * '<S74>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/N Gain'
 * '<S75>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/P Copy'
 * '<S76>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Parallel P Gain'
 * '<S77>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Reset Signal'
 * '<S78>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Saturation'
 * '<S79>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Saturation Fdbk'
 * '<S80>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Sum'
 * '<S81>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Sum Fdbk'
 * '<S82>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode'
 * '<S83>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode Sum'
 * '<S84>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Integral'
 * '<S85>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Ngain'
 * '<S86>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/postSat Signal'
 * '<S87>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/preSat Signal'
 * '<S88>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S89>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/D Gain/External Parameters'
 * '<S90>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/I Gain/External Parameters'
 * '<S93>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S94>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Integrator/Discrete'
 * '<S96>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S97>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/N Copy/Disabled'
 * '<S98>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/N Gain/External Parameters'
 * '<S99>'  : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/P Copy/Disabled'
 * '<S100>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S101>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Reset Signal/Disabled'
 * '<S102>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Saturation/Enabled'
 * '<S103>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S104>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Sum/Sum_PID'
 * '<S105>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S106>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S107>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S109>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S111>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S112>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller'
 * '<S113>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Anti-windup'
 * '<S114>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/D Gain'
 * '<S115>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Filter'
 * '<S116>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Filter ICs'
 * '<S117>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/I Gain'
 * '<S118>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain'
 * '<S119>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S120>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator'
 * '<S121>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator ICs'
 * '<S122>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/N Copy'
 * '<S123>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/N Gain'
 * '<S124>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/P Copy'
 * '<S125>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Parallel P Gain'
 * '<S126>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Reset Signal'
 * '<S127>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation'
 * '<S128>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation Fdbk'
 * '<S129>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Sum'
 * '<S130>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Sum Fdbk'
 * '<S131>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode'
 * '<S132>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode Sum'
 * '<S133>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Integral'
 * '<S134>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Ngain'
 * '<S135>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/postSat Signal'
 * '<S136>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/preSat Signal'
 * '<S137>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S138>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/D Gain/External Parameters'
 * '<S139>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S140>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S141>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/I Gain/External Parameters'
 * '<S142>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S143>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S144>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator/Discrete'
 * '<S145>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S146>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/N Copy/Disabled'
 * '<S147>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/N Gain/External Parameters'
 * '<S148>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/P Copy/Disabled'
 * '<S149>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S150>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Reset Signal/Disabled'
 * '<S151>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation/Enabled'
 * '<S152>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S153>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Sum/Sum_PID'
 * '<S154>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S155>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S156>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S157>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S158>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S159>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S160>' : 'BalancingRobot/Function-Call Subsystem/PID Loop/Motor PID Control1/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S161>' : 'BalancingRobot/If Action Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_BalancingRobot_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BalancingRobot.h
 */
