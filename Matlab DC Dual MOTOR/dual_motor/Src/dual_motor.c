/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dual_motor.c
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

#include "dual_motor.h"
#include "dual_motor_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define dual_motor_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define dual_motor_IN_S1               ((uint8_T)1U)
#define dual_motor_IN_S2               ((uint8_T)2U)
#define dual_motor_IN_S3               ((uint8_T)3U)
#define dual_motor_IN_S4               ((uint8_T)4U)

/* Block signals (default storage) */
B_dual_motor dual_motor_B;

/* Block states (default storage) */
DW_dual_motor dual_motor_DW;

/* Real-time model */
RT_MODEL_dual_motor dual_motor_M_;
RT_MODEL_dual_motor *const dual_motor_M = &dual_motor_M_;

/* Model step function */
void dual_motor_step(void)
{
  {
  }

  {
  }

  {
  }

  {
  }

  {
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  dual_motor_M->Timing.clockTick0++;
}

/* Model initialize function */
void dual_motor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)dual_motor_M, 0,
                sizeof(RT_MODEL_dual_motor));

  /* block I/O */
  (void) memset(((void *) &dual_motor_B), 0,
                sizeof(B_dual_motor));

  /* states (dwork) */
  (void) memset((void *)&dual_motor_DW, 0,
                sizeof(DW_dual_motor));

  {
    /* user code (Start function Header) */
    {
      /* TIM6 initialization. */
      /* Store TIM6 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM6_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim6;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM6_Conf.TIM_Prescaler = 8399;
      TIM6_Conf.TIM_APBClock = 84000000;
      TIM6_Conf.TIM_ARR = 10 - 1;
      TIM6_Conf.TIM_Clock = 10000.0;
      TIM6_Conf.TIM_Freq = 1000.0;
      TIM6_Conf.CH1_duty = 0.0;
      TIM6_Conf.CH2_duty = 0.0;
      TIM6_Conf.CH3_duty = 0.0;
      TIM6_Conf.CH4_duty = 0.0;
      TIM6_Conf.CH1_type = UNKNOWN;
      TIM6_Conf.CH2_type = UNKNOWN;
      TIM6_Conf.CH3_type = UNKNOWN;
      TIM6_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM6_Conf.ItUpFcn = NULL;
      TIM6_Conf.ItTrgFcn = NULL;
      TIM6_Conf.ItComFcn = NULL;
      TIM6_Conf.ItBrkFcn = NULL;
      TIM6_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM6_Conf.ItUpFcn = TIM6_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim6)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim6,TIM6_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim6,10 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim6,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM7 initialization. */
      /* Store TIM7 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM7_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim7;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM7_Conf.TIM_Prescaler = 839;
      TIM7_Conf.TIM_APBClock = 84000000;
      TIM7_Conf.TIM_ARR = 1000 - 1;
      TIM7_Conf.TIM_Clock = 100000.0;
      TIM7_Conf.TIM_Freq = 100.0;
      TIM7_Conf.CH1_duty = 0.0;
      TIM7_Conf.CH2_duty = 0.0;
      TIM7_Conf.CH3_duty = 0.0;
      TIM7_Conf.CH4_duty = 0.0;
      TIM7_Conf.CH1_type = UNKNOWN;
      TIM7_Conf.CH2_type = UNKNOWN;
      TIM7_Conf.CH3_type = UNKNOWN;
      TIM7_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM7_Conf.ItUpFcn = NULL;
      TIM7_Conf.ItTrgFcn = NULL;
      TIM7_Conf.ItComFcn = NULL;
      TIM7_Conf.ItBrkFcn = NULL;
      TIM7_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM7_Conf.ItUpFcn = TIM7_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim7)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim7,TIM7_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim7,1000 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim7,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM3 initialization. */
      /* Store TIM3 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM3_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim3;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM3_Conf.TIM_Prescaler = 839;
      TIM3_Conf.TIM_APBClock = 84000000;
      TIM3_Conf.TIM_ARR = 2000 - 1;
      TIM3_Conf.TIM_Clock = 100000.0;
      TIM3_Conf.TIM_Freq = 50.0;
      TIM3_Conf.CH1_duty = 0.0;
      TIM3_Conf.CH2_duty = 0.0;
      TIM3_Conf.CH3_duty = 0.0;
      TIM3_Conf.CH4_duty = 0.0;

      /* Input Capture data channel 1. */
      TIM3_Conf.ICC1ReadValue1 = 0;
      TIM3_Conf.ICC1ReadValue2 = 0;
      TIM3_Conf.ICC1ReadValue3 = 0;
      TIM3_Conf.ICC1ReadValue4 = 0;
      TIM3_Conf.ICC1CaptureNumber = 1;
      TIM3_Conf.ICC1Capture = 0;
      TIM3_Conf.ICC1Freq = 0;
      TIM3_Conf.ICC1Duty = 0;

      /* Input Capture data channel 2. */
      TIM3_Conf.ICC2ReadValue1 = 0;
      TIM3_Conf.ICC2ReadValue2 = 0;
      TIM3_Conf.ICC2ReadValue3 = 0;
      TIM3_Conf.ICC2ReadValue4 = 0;
      TIM3_Conf.ICC2CaptureNumber = 1;
      TIM3_Conf.ICC2Capture = 0;
      TIM3_Conf.ICC2Freq = 0;
      TIM3_Conf.ICC2Duty = 0;
      TIM3_Conf.CH1_type = INPUT_CAPTURE;
      TIM3_Conf.CH2_type = INPUT_CAPTURE;
      TIM3_Conf.CH3_type = UNKNOWN;
      TIM3_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM3_Conf.ItUpFcn = NULL;
      TIM3_Conf.ItTrgFcn = NULL;
      TIM3_Conf.ItComFcn = NULL;
      TIM3_Conf.ItBrkFcn = NULL;
      TIM3_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim3)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Timer is used as input capture. */
      /* Prescaler.*/
      __HAL_TIM_SET_PRESCALER(&htim3,TIM3_Conf.TIM_Prescaler);

      /* Autoreload: ARR is max value.*/
      __HAL_TIM_SET_AUTORELOAD(&htim3,0xFFFF);

      /* ClockDivision is null. */
      __HAL_TIM_SET_CLOCKDIVISION(&htim3,0x00);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim3,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM4 initialization. */
      /* Store TIM4 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM4_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim4;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM4_Conf.TIM_Prescaler = 839;
      TIM4_Conf.TIM_APBClock = 84000000;
      TIM4_Conf.TIM_ARR = 2000 - 1;
      TIM4_Conf.TIM_Clock = 100000.0;
      TIM4_Conf.TIM_Freq = 50.0;
      TIM4_Conf.CH1_duty = 0.0;
      TIM4_Conf.CH2_duty = 0.0;
      TIM4_Conf.CH3_duty = 0.0;
      TIM4_Conf.CH4_duty = 0.0;

      /* Input Capture data channel 1. */
      TIM4_Conf.ICC1ReadValue1 = 0;
      TIM4_Conf.ICC1ReadValue2 = 0;
      TIM4_Conf.ICC1ReadValue3 = 0;
      TIM4_Conf.ICC1ReadValue4 = 0;
      TIM4_Conf.ICC1CaptureNumber = 1;
      TIM4_Conf.ICC1Capture = 0;
      TIM4_Conf.ICC1Freq = 0;
      TIM4_Conf.ICC1Duty = 0;
      TIM4_Conf.CH1_type = INPUT_CAPTURE;
      TIM4_Conf.CH2_type = UNKNOWN;
      TIM4_Conf.CH3_type = UNKNOWN;
      TIM4_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM4_Conf.ItUpFcn = NULL;
      TIM4_Conf.ItTrgFcn = NULL;
      TIM4_Conf.ItComFcn = NULL;
      TIM4_Conf.ItBrkFcn = NULL;
      TIM4_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim4)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Timer is used as input capture. */
      /* Prescaler.*/
      __HAL_TIM_SET_PRESCALER(&htim4,TIM4_Conf.TIM_Prescaler);

      /* Autoreload: ARR is max value.*/
      __HAL_TIM_SET_AUTORELOAD(&htim4,0xFFFF);

      /* ClockDivision is null. */
      __HAL_TIM_SET_CLOCKDIVISION(&htim4,0x00);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim4,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM9 initialization. */
      /* Store TIM9 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM9_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim9;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM9_Conf.TIM_Prescaler = 3359;
      TIM9_Conf.TIM_APBClock = 168000000;
      TIM9_Conf.TIM_ARR = 100 - 1;
      TIM9_Conf.TIM_Clock = 50000.0;
      TIM9_Conf.TIM_Freq = 500.0;
      TIM9_Conf.CH1_duty = 0.0;
      TIM9_Conf.CH2_duty = 0.0;
      TIM9_Conf.CH3_duty = 0.0;
      TIM9_Conf.CH4_duty = 0.0;
      TIM9_Conf.CH1_type = OUTPUT_PWM;
      TIM9_Conf.CH2_type = OUTPUT_PWM;
      TIM9_Conf.CH3_type = UNKNOWN;
      TIM9_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM9_Conf.ItUpFcn = NULL;
      TIM9_Conf.ItTrgFcn = NULL;
      TIM9_Conf.ItComFcn = NULL;
      TIM9_Conf.ItBrkFcn = NULL;
      TIM9_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim9)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim9,TIM9_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim9,100 - 1);

      /* Set CH1 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim9,TIM_CHANNEL_1,(uint32_t)((100 - 1)/2));

      /* Set CH2 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim9,TIM_CHANNEL_2,(uint32_t)((100 - 1)/2));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim9,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */

    /* USART3 initialization for send. */
    USART3_Tx_Initialization();

    {
      /* External interrupt function registering. */
      EXTI_Callback[0] = EXTI0_Callback;
    }

    {
      /* TIM6 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim6);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim6);
    }

    {
      /* TIM7 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim7);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim7);
    }

    {
      /* TIM3 Start. */

      /* Wait for htim3 State READY. */
      while ((&htim3)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_IC_Start(&htim3,TIM_CHANNEL_1);
    }

    {
      /* TIM4 Start. */

      /* Wait for htim4 State READY. */
      while ((&htim4)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_IC_Start(&htim4,TIM_CHANNEL_1);
    }

    {
      /* TIM9 Start. */

      /* Wait for htim9 State READY. */
      while ((&htim9)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);

      /* Wait for htim9 State READY. */
      while ((&htim9)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
    }
  }

  dual_motor_DW.RateTransition5_write_buf = -1;
  dual_motor_DW.RateTransition5_read_buf = -1;
  dual_motor_DW.RateTransition_write_buf = -1;
  dual_motor_DW.RateTransition_read_buf = -1;
  dual_motor_DW.RateTransition10_write_buf = -1;
  dual_motor_DW.RateTransition10_read_buf = -1;
  dual_motor_DW.RateTransition2_write_buf = -1;
  dual_motor_DW.RateTransition2_read_buf = -1;
  dual_motor_DW.RateTransition3_write_buf = -1;
  dual_motor_DW.RateTransition3_read_buf = -1;
  dual_motor_DW.RateTransition4_write_buf = -1;
  dual_motor_DW.RateTransition4_read_buf = -1;
  dual_motor_DW.RateTransition6_write_buf = -1;
  dual_motor_DW.RateTransition6_read_buf = -1;
  dual_motor_DW.RateTransition8_write_buf = -1;
  dual_motor_DW.RateTransition8_read_buf = -1;
  dual_motor_DW.RateTransition9_write_buf = -1;
  dual_motor_DW.RateTransition9_read_buf = -1;

  /* System initialize for function-call system: '<Root>/Change Setpoint' */
  dual_motor_DW.is_active_c5_dual_motor = 0U;
  dual_motor_DW.is_c5_dual_motor = dual_motor_IN_NO_ACTIVE_CHILD;

  /* System initialize for function-call system: '<Root>/PID Loop' */
  dual_motor_M->Timing.clockTick2 = dual_motor_M->Timing.clockTick0;
  dual_motor_DW.PIDLoop_PREV_T = dual_motor_M->Timing.clockTick2;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] dual_motor.c
 */
