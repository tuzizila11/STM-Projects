/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dual_motor_TIM.c
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
#include "dual_motor_TIM.h"

/* Number of configured TIMER. */
uint16_t G_TIM_Count = 0;

/* Array of TIMER information. */
TIM_ConfTypeDef* G_TIM_Conf[5];
TIM_HandleTypeDef* G_TIM_Handler[5];

/* TIM6 informations. */
TIM_ConfTypeDef TIM6_Conf;

/* TIM6 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM6_PollTimeOut = 10;

/* TIM7 informations. */
TIM_ConfTypeDef TIM7_Conf;

/* TIM7 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM7_PollTimeOut = 10;

/* TIM3 informations. */
TIM_ConfTypeDef TIM3_Conf;

/* TIM3 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM3_PollTimeOut = 10;

/* TIM4 informations. */
TIM_ConfTypeDef TIM4_Conf;

/* TIM4 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM4_PollTimeOut = 10;

/* TIM9 informations. */
TIM_ConfTypeDef TIM9_Conf;

/* TIM9 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM9_PollTimeOut = 10;

/*******************************************************************************
 * Function Name  : TIM_PeriodElapsedCustomCallback
 * Description    : Timer callback for update event
 * Input          : TIM_HandleTypeDef*   TIM IC handle
 *******************************************************************************/
void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim)
{
  TIM_ConfTypeDef * pConf = G_TIM_Conf[0];
  TIM_HandleTypeDef* pHandler = G_TIM_Handler[0];

  {
    uint16_t idx = 0;
    for (idx = 0;idx < 5;idx++) {
      pHandler = G_TIM_Handler[idx];
      if (pHandler == htim) {
        pConf = G_TIM_Conf[idx];
        break;
      }
    }
  }

  if (pHandler == htim) {
    if (pConf->ItUpFcn != NULL) {
      /* Call update function for TIM6. */
      pConf->ItUpFcn();
    }
  }
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  extern void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim);

  /* Handle this event from model side. */
  TIM_PeriodElapsedCustomCallback(htim);
}

/*******************************************************************************
 * Function Name  : TIM6_ItUpFcn
 * Description    : TIM6 update interrupt
 * Input          : None
 * TIM6_ItUpFcn is called from TIM_PeriodElapsedCustomCallback function
 * in dual_motor_TIM.c file.
 *******************************************************************************/
void TIM6_ItUpFcn()
{
  {
    switch (dual_motor_DW.RateTransition5_write_buf) {
     case 0:
      dual_motor_DW.RateTransition5_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition5_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition5_read_buf =
        dual_motor_DW.RateTransition5_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition5_read_buf != 0) {
      dual_motor_B.RateTransition5 = dual_motor_DW.RateTransition5_Buffer1;
    } else {
      dual_motor_B.RateTransition5 = dual_motor_DW.RateTransition5_Buffer0;
    }

    dual_motor_DW.RateTransition5_read_buf = -1;

    /* Output and update for function-call system: '<Root>/PID Loop' */
    {
      real_T rtb_NProdOut;
      real_T rtb_NProdOut_f;
      real_T rtb_IProdOut_f;
      real_T rtb_SignPreIntegrator;
      real_T rtb_ZeroGain;
      boolean_T rtb_NotEqual;
      uint32_T PIDLoop_ELAPS_T;
      real_T tmp;
      real_T tmp_p;
      uint32_T PIDLoop_ELAPS_T_tmp;
      dual_motor_M->Timing.clockTick2 = dual_motor_M->Timing.clockTick0;
      PIDLoop_ELAPS_T_tmp = dual_motor_M->Timing.clockTick2;
      PIDLoop_ELAPS_T = PIDLoop_ELAPS_T_tmp - dual_motor_DW.PIDLoop_PREV_T;
      dual_motor_DW.PIDLoop_PREV_T = PIDLoop_ELAPS_T_tmp;

      {
        dual_motor_B.PRESCALER_TIM3 = TIM3->PSC;
      }

      rtb_NProdOut_f = HAL_RCC_GetPCLK1Freq();

      {
        dual_motor_B.PERIOD_TIM3_CCR1 = TIM3->CCR1;
      }

      dual_motor_B.Divide = ((1.0 / (dual_motor_B.PRESCALER_TIM3 + 1.0)) * (2.0 *
        rtb_NProdOut_f)) / dual_motor_B.PERIOD_TIM3_CCR1;
      dual_motor_B.Add1 = dual_motor_B.RateTransition5 - dual_motor_B.Divide;
      rtb_NProdOut = ((dual_motor_B.Add1 * 40.0) - dual_motor_DW.Filter_DSTATE) *
        100.0;
      rtb_IProdOut_f = ((dual_motor_B.Add1 * 10.0) +
                        dual_motor_DW.Integrator_DSTATE) + rtb_NProdOut;
      if (rtb_IProdOut_f > 700.0) {
        dual_motor_B.Saturation = 700.0;
      } else if (rtb_IProdOut_f < 273.0) {
        dual_motor_B.Saturation = 273.0;
      } else {
        dual_motor_B.Saturation = rtb_IProdOut_f;
      }

      dual_motor_B.Subtract = (0.21574973031283712 * dual_motor_B.Saturation) -
        58.899676375404532;

      {
        TIM9->CCR1 = dual_motor_B.Subtract;
      }

      {
        dual_motor_B.PRESCALER_TIM4 = TIM4->PSC;
      }

      {
        dual_motor_B.PERIOD_TIM4_CCR1 = TIM4->CCR1;
      }

      dual_motor_B.Divide_d = ((1.0 / (dual_motor_B.PRESCALER_TIM4 + 1.0)) *
        (2.0 * rtb_NProdOut_f)) / dual_motor_B.PERIOD_TIM4_CCR1;
      dual_motor_B.Add1_g = dual_motor_B.RateTransition5 - dual_motor_B.Divide_d;
      rtb_NProdOut_f = ((dual_motor_B.Add1_g * 40.0) -
                        dual_motor_DW.Filter_DSTATE_l) * 100.0;
      rtb_SignPreIntegrator = ((dual_motor_B.Add1_g * 10.0) +
        dual_motor_DW.Integrator_DSTATE_d) + rtb_NProdOut_f;
      if (rtb_SignPreIntegrator > 700.0) {
        dual_motor_B.Saturation_n = 700.0;
      } else if (rtb_SignPreIntegrator < 324.0) {
        dual_motor_B.Saturation_n = 324.0;
      } else {
        dual_motor_B.Saturation_n = rtb_SignPreIntegrator;
      }

      dual_motor_B.Subtract_p = (0.25641025641025644 * dual_motor_B.Saturation_n)
        - 83.07692307692308;

      {
        TIM9->CCR2 = dual_motor_B.Subtract_p;
      }

      tmp_p = floor(dual_motor_B.PERIOD_TIM3_CCR1);
      if ((rtIsNaN(tmp_p)) || (rtIsInf(tmp_p))) {
        tmp_p = 0.0;
      } else {
        tmp_p = fmod(tmp_p, 4.294967296E+9);
      }

      dual_motor_B.DataTypeConversion = (tmp_p < 0.0) ? ((uint32_T)((int32_T)
        (-((int32_T)((uint32_T)((real_T)(-tmp_p))))))) : ((uint32_T)tmp_p);
      rtb_ZeroGain = 0.0 * rtb_IProdOut_f;
      if (rtb_IProdOut_f > 700.0) {
        rtb_IProdOut_f -= 700.0;
      } else if (rtb_IProdOut_f >= 273.0) {
        rtb_IProdOut_f = 0.0;
      } else {
        rtb_IProdOut_f -= 273.0;
      }

      rtb_NotEqual = (rtb_ZeroGain != rtb_IProdOut_f);
      if (rtb_IProdOut_f < 0.0) {
        rtb_IProdOut_f = -1.0;
      } else if (rtb_IProdOut_f > 0.0) {
        rtb_IProdOut_f = 1.0;
      } else if (rtb_IProdOut_f == 0.0) {
        rtb_IProdOut_f = 0.0;
      } else {
        rtb_IProdOut_f = (rtNaN);
      }

      if (rtIsNaN(rtb_IProdOut_f)) {
        tmp_p = 0.0;
      } else {
        tmp_p = fmod(rtb_IProdOut_f, 256.0);
      }

      rtb_IProdOut_f = dual_motor_B.Add1 * 3.0;
      if (rtb_IProdOut_f < 0.0) {
        tmp = -1.0;
      } else if (rtb_IProdOut_f > 0.0) {
        tmp = 1.0;
      } else if (rtb_IProdOut_f == 0.0) {
        tmp = 0.0;
      } else {
        tmp = (rtNaN);
      }

      if (rtIsNaN(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 256.0);
      }

      if (rtb_NotEqual && (((int32_T)((int8_T)((tmp_p < 0.0) ? ((int32_T)
               ((int8_T)(-((int8_T)((uint8_T)((real_T)(-tmp_p))))))) : ((int32_T)
               ((int8_T)((uint8_T)tmp_p)))))) == ((tmp < 0.0) ? ((int32_T)
             ((int8_T)(-((int8_T)((uint8_T)((real_T)(-tmp))))))) : ((int32_T)
             ((int8_T)((uint8_T)tmp)))))) {
        rtb_IProdOut_f = 0.0;
      }

      tmp_p = floor(dual_motor_B.PERIOD_TIM4_CCR1);
      if ((rtIsNaN(tmp_p)) || (rtIsInf(tmp_p))) {
        tmp_p = 0.0;
      } else {
        tmp_p = fmod(tmp_p, 4.294967296E+9);
      }

      dual_motor_B.DataTypeConversion_c = (tmp_p < 0.0) ? ((uint32_T)((int32_T)(
        -((int32_T)((uint32_T)((real_T)(-tmp_p))))))) : ((uint32_T)tmp_p);
      rtb_ZeroGain = 0.0 * rtb_SignPreIntegrator;
      if (rtb_SignPreIntegrator > 700.0) {
        rtb_SignPreIntegrator -= 700.0;
      } else if (rtb_SignPreIntegrator >= 324.0) {
        rtb_SignPreIntegrator = 0.0;
      } else {
        rtb_SignPreIntegrator -= 324.0;
      }

      rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreIntegrator);
      if (rtb_SignPreIntegrator < 0.0) {
        rtb_SignPreIntegrator = -1.0;
      } else if (rtb_SignPreIntegrator > 0.0) {
        rtb_SignPreIntegrator = 1.0;
      } else if (rtb_SignPreIntegrator == 0.0) {
        rtb_SignPreIntegrator = 0.0;
      } else {
        rtb_SignPreIntegrator = (rtNaN);
      }

      rtb_ZeroGain = dual_motor_B.Add1_g * 3.0;
      if (rtIsNaN(rtb_SignPreIntegrator)) {
        tmp_p = 0.0;
      } else {
        tmp_p = fmod(rtb_SignPreIntegrator, 256.0);
      }

      if (rtb_ZeroGain < 0.0) {
        tmp = -1.0;
      } else if (rtb_ZeroGain > 0.0) {
        tmp = 1.0;
      } else if (rtb_ZeroGain == 0.0) {
        tmp = 0.0;
      } else {
        tmp = (rtNaN);
      }

      if (rtIsNaN(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 256.0);
      }

      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
      }

      rtb_SignPreIntegrator = 0.2 * ((real_T)PIDLoop_ELAPS_T);
      dual_motor_DW.Integrator_DSTATE += rtb_SignPreIntegrator * rtb_IProdOut_f;
      dual_motor_DW.Filter_DSTATE += rtb_SignPreIntegrator * rtb_NProdOut;
      if (rtb_NotEqual && (((tmp_p < 0.0) ? ((int32_T)((int8_T)(-((int8_T)
                ((uint8_T)((real_T)(-tmp_p))))))) : ((int32_T)((int8_T)((uint8_T)
               tmp_p)))) == ((tmp < 0.0) ? ((int32_T)((int8_T)(-((int8_T)
                ((uint8_T)((real_T)(-tmp))))))) : ((int32_T)((int8_T)((uint8_T)
               tmp)))))) {
        rtb_ZeroGain = 0.0;
      }

      dual_motor_DW.Integrator_DSTATE_d += rtb_SignPreIntegrator * rtb_ZeroGain;
      dual_motor_DW.Filter_DSTATE_l += rtb_SignPreIntegrator * rtb_NProdOut_f;
    }

    switch (dual_motor_DW.RateTransition_read_buf) {
     case 0:
      dual_motor_DW.RateTransition_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition_write_buf != 0) {
      dual_motor_DW.RateTransition_Buffer1 = dual_motor_B.Divide;
    } else {
      dual_motor_DW.RateTransition_Buffer0 = dual_motor_B.Divide;
    }

    dual_motor_DW.RateTransition_last_buf_wr =
      dual_motor_DW.RateTransition_write_buf;
    dual_motor_DW.RateTransition_write_buf = -1;
    switch (dual_motor_DW.RateTransition10_read_buf) {
     case 0:
      dual_motor_DW.RateTransition10_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition10_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition10_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition10_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition10_write_buf != 0) {
      dual_motor_DW.RateTransition10_Buffer1 = dual_motor_B.Subtract_p;
    } else {
      dual_motor_DW.RateTransition10_Buffer0 = dual_motor_B.Subtract_p;
    }

    dual_motor_DW.RateTransition10_last_buf_wr =
      dual_motor_DW.RateTransition10_write_buf;
    dual_motor_DW.RateTransition10_write_buf = -1;
    switch (dual_motor_DW.RateTransition2_read_buf) {
     case 0:
      dual_motor_DW.RateTransition2_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition2_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition2_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition2_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition2_write_buf != 0) {
      dual_motor_DW.RateTransition2_Buffer1 = dual_motor_B.Saturation;
    } else {
      dual_motor_DW.RateTransition2_Buffer0 = dual_motor_B.Saturation;
    }

    dual_motor_DW.RateTransition2_last_buf_wr =
      dual_motor_DW.RateTransition2_write_buf;
    dual_motor_DW.RateTransition2_write_buf = -1;
    switch (dual_motor_DW.RateTransition3_read_buf) {
     case 0:
      dual_motor_DW.RateTransition3_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition3_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition3_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition3_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition3_write_buf != 0) {
      dual_motor_DW.RateTransition3_Buffer1 = dual_motor_B.Add1;
    } else {
      dual_motor_DW.RateTransition3_Buffer0 = dual_motor_B.Add1;
    }

    dual_motor_DW.RateTransition3_last_buf_wr =
      dual_motor_DW.RateTransition3_write_buf;
    dual_motor_DW.RateTransition3_write_buf = -1;
    switch (dual_motor_DW.RateTransition4_read_buf) {
     case 0:
      dual_motor_DW.RateTransition4_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition4_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition4_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition4_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition4_write_buf != 0) {
      dual_motor_DW.RateTransition4_Buffer1 = dual_motor_B.Subtract;
    } else {
      dual_motor_DW.RateTransition4_Buffer0 = dual_motor_B.Subtract;
    }

    dual_motor_DW.RateTransition4_last_buf_wr =
      dual_motor_DW.RateTransition4_write_buf;
    dual_motor_DW.RateTransition4_write_buf = -1;
    switch (dual_motor_DW.RateTransition6_read_buf) {
     case 0:
      dual_motor_DW.RateTransition6_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition6_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition6_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition6_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition6_write_buf != 0) {
      dual_motor_DW.RateTransition6_Buffer1 = dual_motor_B.Divide_d;
    } else {
      dual_motor_DW.RateTransition6_Buffer0 = dual_motor_B.Divide_d;
    }

    dual_motor_DW.RateTransition6_last_buf_wr =
      dual_motor_DW.RateTransition6_write_buf;
    dual_motor_DW.RateTransition6_write_buf = -1;
    switch (dual_motor_DW.RateTransition8_read_buf) {
     case 0:
      dual_motor_DW.RateTransition8_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition8_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition8_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition8_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition8_write_buf != 0) {
      dual_motor_DW.RateTransition8_Buffer1 = dual_motor_B.Saturation_n;
    } else {
      dual_motor_DW.RateTransition8_Buffer0 = dual_motor_B.Saturation_n;
    }

    dual_motor_DW.RateTransition8_last_buf_wr =
      dual_motor_DW.RateTransition8_write_buf;
    dual_motor_DW.RateTransition8_write_buf = -1;
    switch (dual_motor_DW.RateTransition9_read_buf) {
     case 0:
      dual_motor_DW.RateTransition9_write_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition9_write_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition9_write_buf = (int8_T)
        ((dual_motor_DW.RateTransition9_last_buf_wr == 0) ? 1 : 0);
      break;
    }

    if (dual_motor_DW.RateTransition9_write_buf != 0) {
      dual_motor_DW.RateTransition9_Buffer1 = dual_motor_B.Add1_g;
    } else {
      dual_motor_DW.RateTransition9_Buffer0 = dual_motor_B.Add1_g;
    }

    dual_motor_DW.RateTransition9_last_buf_wr =
      dual_motor_DW.RateTransition9_write_buf;
    dual_motor_DW.RateTransition9_write_buf = -1;
  }
}

/*******************************************************************************
 * Function Name  : TIM7_ItUpFcn
 * Description    : TIM7 update interrupt
 * Input          : None
 * TIM7_ItUpFcn is called from TIM_PeriodElapsedCustomCallback function
 * in dual_motor_TIM.c file.
 *******************************************************************************/
void TIM7_ItUpFcn()
{
  {
    switch (dual_motor_DW.RateTransition4_write_buf) {
     case 0:
      dual_motor_DW.RateTransition4_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition4_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition4_read_buf =
        dual_motor_DW.RateTransition4_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition4_read_buf != 0) {
      dual_motor_B.RateTransition4 = dual_motor_DW.RateTransition4_Buffer1;
    } else {
      dual_motor_B.RateTransition4 = dual_motor_DW.RateTransition4_Buffer0;
    }

    dual_motor_DW.RateTransition4_read_buf = -1;
    switch (dual_motor_DW.RateTransition3_write_buf) {
     case 0:
      dual_motor_DW.RateTransition3_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition3_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition3_read_buf =
        dual_motor_DW.RateTransition3_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition3_read_buf != 0) {
      dual_motor_B.RateTransition3 = dual_motor_DW.RateTransition3_Buffer1;
    } else {
      dual_motor_B.RateTransition3 = dual_motor_DW.RateTransition3_Buffer0;
    }

    dual_motor_DW.RateTransition3_read_buf = -1;
    switch (dual_motor_DW.RateTransition2_write_buf) {
     case 0:
      dual_motor_DW.RateTransition2_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition2_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition2_read_buf =
        dual_motor_DW.RateTransition2_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition2_read_buf != 0) {
      dual_motor_B.RateTransition2 = dual_motor_DW.RateTransition2_Buffer1;
    } else {
      dual_motor_B.RateTransition2 = dual_motor_DW.RateTransition2_Buffer0;
    }

    dual_motor_DW.RateTransition2_read_buf = -1;
    switch (dual_motor_DW.RateTransition_write_buf) {
     case 0:
      dual_motor_DW.RateTransition_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition_read_buf =
        dual_motor_DW.RateTransition_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition_read_buf != 0) {
      dual_motor_B.RateTransition = dual_motor_DW.RateTransition_Buffer1;
    } else {
      dual_motor_B.RateTransition = dual_motor_DW.RateTransition_Buffer0;
    }

    dual_motor_DW.RateTransition_read_buf = -1;
    dual_motor_B.RateTransition1 = dual_motor_B.DataTypeConversion;
    switch (dual_motor_DW.RateTransition10_write_buf) {
     case 0:
      dual_motor_DW.RateTransition10_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition10_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition10_read_buf =
        dual_motor_DW.RateTransition10_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition10_read_buf != 0) {
      dual_motor_B.RateTransition10 = dual_motor_DW.RateTransition10_Buffer1;
    } else {
      dual_motor_B.RateTransition10 = dual_motor_DW.RateTransition10_Buffer0;
    }

    dual_motor_DW.RateTransition10_read_buf = -1;
    switch (dual_motor_DW.RateTransition9_write_buf) {
     case 0:
      dual_motor_DW.RateTransition9_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition9_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition9_read_buf =
        dual_motor_DW.RateTransition9_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition9_read_buf != 0) {
      dual_motor_B.RateTransition9 = dual_motor_DW.RateTransition9_Buffer1;
    } else {
      dual_motor_B.RateTransition9 = dual_motor_DW.RateTransition9_Buffer0;
    }

    dual_motor_DW.RateTransition9_read_buf = -1;
    switch (dual_motor_DW.RateTransition8_write_buf) {
     case 0:
      dual_motor_DW.RateTransition8_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition8_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition8_read_buf =
        dual_motor_DW.RateTransition8_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition8_read_buf != 0) {
      dual_motor_B.RateTransition8 = dual_motor_DW.RateTransition8_Buffer1;
    } else {
      dual_motor_B.RateTransition8 = dual_motor_DW.RateTransition8_Buffer0;
    }

    dual_motor_DW.RateTransition8_read_buf = -1;
    switch (dual_motor_DW.RateTransition6_write_buf) {
     case 0:
      dual_motor_DW.RateTransition6_read_buf = 1;
      break;

     case 1:
      dual_motor_DW.RateTransition6_read_buf = 0;
      break;

     default:
      dual_motor_DW.RateTransition6_read_buf =
        dual_motor_DW.RateTransition6_last_buf_wr;
      break;
    }

    if (dual_motor_DW.RateTransition6_read_buf != 0) {
      dual_motor_B.RateTransition6 = dual_motor_DW.RateTransition6_Buffer1;
    } else {
      dual_motor_B.RateTransition6 = dual_motor_DW.RateTransition6_Buffer0;
    }

    dual_motor_DW.RateTransition6_read_buf = -1;
    dual_motor_B.RateTransition7 = dual_motor_B.DataTypeConversion_c;

    /* Output and update for function-call system: '<Root>/Send Data' */
    {
      char_T string[100];
      static const char_T stringFormat[56] =
        "%u,%5.2f,%5.2f,%5.2f,%5.2f,%u,%5.2f,%5.2f,%5.2f,%5.2f\r\n";
      snprintf(string, 100, stringFormat, dual_motor_B.RateTransition1,
               dual_motor_B.RateTransition3, dual_motor_B.RateTransition2,
               dual_motor_B.RateTransition, dual_motor_B.RateTransition4,
               dual_motor_B.RateTransition7, dual_motor_B.RateTransition9,
               dual_motor_B.RateTransition8, dual_motor_B.RateTransition6,
               dual_motor_B.RateTransition10);
      dual_motor_B.buff = getBuffPtr(string);
      dual_motor_B.nbChar = 70U;

      {
        if (dual_motor_B.nbChar != 0) {
          /* Copy data to send. */
          TX_CopyData(&USART3_TxConf, (uint8_t*)dual_motor_B.buff, (uint16_t)
                      dual_motor_B.nbChar);
        }

        if (USART3_TxConf.nb2Send) {
          dual_motor_B.USART_Send = 0;
          USART3_TX_SendData(&USART3_TxConf);
        }

        if (USART3_TxConf.txStatus != SERIAL_TX_ON) {
          dual_motor_B.USART_Send = USART3_TxConf.nbSent;
        }

        USART3_TxConf.txStatus = SERIAL_TX_OFF;
      }
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] dual_motor_TIM.c
 */
