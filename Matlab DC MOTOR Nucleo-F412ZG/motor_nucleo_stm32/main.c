/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
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

/* This section of code is going to be merged by the STM32CubeMX tool. */
/* USER CODE BEGIN 0 */
#include <stdio.h>
#include "motor_nucleo.h"
#include "rtwtypes.h"

/* Flags for taskOverrun */
static boolean_T OverrunFlags[1] = { false, };

/* Number of auto reload timer rotation computed */
static volatile uint32_t autoReloadTimerLoopVal_S = 1;

/* Remaining number of auto reload timer rotation to do */
volatile uint32_t remainAutoReloadTimerLoopVal_S = 1;

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main (void)
{
  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN 2 */
  /* Use Systick arm timer and interrupt to tick step() functions of the Simulink model. */
  /* Fundamental sample time is set to: '0.001' s */
  if (SysTick_Config((uint32_t)(SystemCoreClock/1000.0))) {
    autoReloadTimerLoopVal_S = 1;
    do {
      autoReloadTimerLoopVal_S++;
    } while ((uint32_t)(SystemCoreClock/1000.0)/autoReloadTimerLoopVal_S >
             SysTick_LOAD_RELOAD_Msk);

    SysTick_Config((uint32_t)(SystemCoreClock/1000.0)/autoReloadTimerLoopVal_S);
  }

  /* Set number of loop to do. */
  remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;

  {
    int i;
    for (i = 0; i < 1; i++) {
      OverrunFlags[i] = false;
    }
  }

  /* Initialize model */
  motor_nucleo_initialize();

  /* USER CODE END 2 */

  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN WHILE */
  /* Infinite loop */
  /* Real time from systickHandler */
  while (1) {
    /*Process tasks every solver time*/
    if (remainAutoReloadTimerLoopVal_S == 0) {
      remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;

      /* Check base rate for overrun */
      if (OverrunFlags[0]) {
        rtmSetErrorStatus(motor_nucleo_M, "Overrun");
      }

      OverrunFlags[0] = true;

      /* Step the model for base rate */
      motor_nucleo_step();

      /* Get model outputs here */

      /* Indicate task for base rate complete */
      OverrunFlags[0] = false;
    }
  }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] main.c
 */