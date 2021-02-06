/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BalancingRobot_TIM.c
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
#include "BalancingRobot_TIM.h"

/* Number of configured TIMER. */
uint16_t G_TIM_Count = 0;

/* Array of TIMER information. */
TIM_ConfTypeDef* G_TIM_Conf[3];
TIM_HandleTypeDef* G_TIM_Handler[3];

/* TIM3 informations. */
TIM_ConfTypeDef TIM3_Conf;

/* TIM3 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM3_PollTimeOut = 10;

/* TIM2 informations. */
TIM_ConfTypeDef TIM2_Conf;

/* TIM2 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM2_PollTimeOut = 10;

/* TIM9 informations. */
TIM_ConfTypeDef TIM9_Conf;

/* TIM9 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM9_PollTimeOut = 10;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BalancingRobot_TIM.c
 */
