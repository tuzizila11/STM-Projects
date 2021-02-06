/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BalancingRobot.c
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

#include "BalancingRobot.h"
#include "BalancingRobot_private.h"

/* GPIOD output mask value definition. */
uint16_t GPIOD_maskWrite;

/* Block signals (default storage) */
B_BalancingRobot BalancingRobot_B;

/* Block states (default storage) */
DW_BalancingRobot BalancingRobot_DW;

/* Real-time model */
RT_MODEL_BalancingRobot BalancingRobot_M_;
RT_MODEL_BalancingRobot *const BalancingRobot_M = &BalancingRobot_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void BalancingRobot_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(BalancingRobot_M, 1));
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
  (BalancingRobot_M->Timing.TaskCounters.TID[1])++;
  if ((BalancingRobot_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [1.0s, 0.0s] */
    BalancingRobot_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void BalancingRobot_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  BalancingRobot_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void BalancingRobot_step1(void)        /* Sample time: [1.0s, 0.0s] */
{
  int8_T y;
  y = isSetup();
  if (y == 0) {
    setFlag();
    setupMPU6050();

    {
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    }
  }

  {
  }

  {
  }

  {
  }
}

/* Model step wrapper function for compatibility with a static main program */
void BalancingRobot_step(int_T tid)
{
  switch (tid) {
   case 0 :
    BalancingRobot_step0();
    break;

   case 1 :
    BalancingRobot_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void BalancingRobot_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BalancingRobot_M, 0,
                sizeof(RT_MODEL_BalancingRobot));

  /* block I/O */
  (void) memset(((void *) &BalancingRobot_B), 0,
                sizeof(B_BalancingRobot));

  /* states (dwork) */
  (void) memset((void *)&BalancingRobot_DW, 0,
                sizeof(DW_BalancingRobot));

  {
    /* user code (Start function Header) */
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
      /* TIM2 initialization. */
      /* Store TIM2 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM2_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim2;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM2_Conf.TIM_Prescaler = 839;
      TIM2_Conf.TIM_APBClock = 84000000;
      TIM2_Conf.TIM_ARR = 2000 - 1;
      TIM2_Conf.TIM_Clock = 100000.0;
      TIM2_Conf.TIM_Freq = 50.0;
      TIM2_Conf.CH1_duty = 0.0;
      TIM2_Conf.CH2_duty = 0.0;
      TIM2_Conf.CH3_duty = 0.0;
      TIM2_Conf.CH4_duty = 0.0;

      /* Input Capture data channel 1. */
      TIM2_Conf.ICC1ReadValue1 = 0;
      TIM2_Conf.ICC1ReadValue2 = 0;
      TIM2_Conf.ICC1ReadValue3 = 0;
      TIM2_Conf.ICC1ReadValue4 = 0;
      TIM2_Conf.ICC1CaptureNumber = 1;
      TIM2_Conf.ICC1Capture = 0;
      TIM2_Conf.ICC1Freq = 0;
      TIM2_Conf.ICC1Duty = 0;
      TIM2_Conf.CH1_type = INPUT_CAPTURE;
      TIM2_Conf.CH2_type = UNKNOWN;
      TIM2_Conf.CH3_type = UNKNOWN;
      TIM2_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM2_Conf.ItUpFcn = NULL;
      TIM2_Conf.ItTrgFcn = NULL;
      TIM2_Conf.ItComFcn = NULL;
      TIM2_Conf.ItBrkFcn = NULL;
      TIM2_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim2)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Timer is used as input capture. */
      /* Prescaler.*/
      __HAL_TIM_SET_PRESCALER(&htim2,TIM2_Conf.TIM_Prescaler);

      /* Autoreload: ARR is max value.*/
      __HAL_TIM_SET_AUTORELOAD(&htim2,0xFFFF);

      /* ClockDivision is null. */
      __HAL_TIM_SET_CLOCKDIVISION(&htim2,0x00);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim2,TIM_EVENTSOURCE_UPDATE);
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
      EXTI_Callback[1] = EXTI1_Callback;
    }

    {
      /* TIM3 Start. */

      /* Wait for htim3 State READY. */
      while ((&htim3)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_IC_Start(&htim3,TIM_CHANNEL_1);
    }

    {
      /* TIM2 Start. */

      /* Wait for htim2 State READY. */
      while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_IC_Start(&htim2,TIM_CHANNEL_1);
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

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  BalancingRobot_M->Timing.clockTick2 = BalancingRobot_M->Timing.clockTick0;
  BalancingRobot_DW.FunctionCallSubsystem_PREV_T =
    BalancingRobot_M->Timing.clockTick2;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BalancingRobot.c
 */
