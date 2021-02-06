/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BalancingRobot_EXTI.c
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
#include "BalancingRobot_EXTI.h"

/* Exti function pointer array */
void (*EXTI_Callback[16])(void) = { NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

/**
 * @brief  EXTI line detection callbacks.
 * @param  GPIO_Pin Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  uint16_t pinNum = 0;
  switch (GPIO_Pin) {
   case GPIO_PIN_1 :
    pinNum = 1;
    break;

   case GPIO_PIN_2 :
    pinNum = 2;
    break;

   case GPIO_PIN_3 :
    pinNum = 3;
    break;

   case GPIO_PIN_4 :
    pinNum = 4;
    break;

   case GPIO_PIN_5 :
    pinNum = 5;
    break;

   case GPIO_PIN_6 :
    pinNum = 6;
    break;

   case GPIO_PIN_7 :
    pinNum = 7;
    break;

   case GPIO_PIN_8 :
    pinNum = 8;
    break;

   case GPIO_PIN_9 :
    pinNum = 9;
    break;

   case GPIO_PIN_10 :
    pinNum = 10;
    break;

   case GPIO_PIN_11 :
    pinNum = 11;
    break;

   case GPIO_PIN_12 :
    pinNum = 12;
    break;

   case GPIO_PIN_13 :
    pinNum = 13;
    break;

   case GPIO_PIN_14 :
    pinNum = 14;
    break;

   case GPIO_PIN_15 :
    pinNum = 15;
    break;

   default:
    pinNum = 0;
    break;
  }

  if (EXTI_Callback[pinNum] != NULL) {
    (*EXTI_Callback[pinNum])();
  }
}

/*******************************************************************************
 * Function Name  : EXTI1_Callback
 * Description    : Callback for External Interrupt connected to Pin1
 * Input          : -
 *******************************************************************************/
void EXTI1_Callback()
{
  {
    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      real_T x;
      real_T y;
      real_T z;
      real_T mpuTmp;
      real_T x1;
      real_T b_y1;
      real_T z1;
      real_T q_0;
      real_T q_1;
      real_T q_2;
      real_T q_3;
      real_T pitch;
      char_T string[205];
      static const char_T stringFormat[132] =
        "%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7u,%9.2f,%9.2f,%9.2f,%9.2f,%9u,%11.2f,%9.2f,%11.2f,%9.2f\r\n";
      real_T rtb_NProdOut;
      real_T rtb_SignPreIntegrator_m;
      real_T rtb_Filter_i;
      real_T rtb_ZeroGain;
      boolean_T rtb_NotEqual;
      real_T rtb_Switch;
      real_T rtb_Add1_l;
      real_T rtb_NProdOut_k1;
      real_T rtb_Divide_l;
      real_T rtb_Add1_g;
      real_T rtb_NProdOut_a;
      real_T rtb_SignPreIntegrator;
      real_T rtb_ZeroGain_ke;
      real_T rtb_Switch_p;
      uint32_T FunctionCallSubsystem_ELAPS_T;
      real_T tmp;
      real_T tmp_p;
      real_T rtb_SignPreIntegrator_p;
      real_T rtb_ZeroGain_i;
      uint32_T FunctionCallSubsystem_ELAPS_T_t;
      BalancingRobot_M->Timing.clockTick2 = BalancingRobot_M->Timing.clockTick0;
      FunctionCallSubsystem_ELAPS_T_t = BalancingRobot_M->Timing.clockTick2;
      FunctionCallSubsystem_ELAPS_T = FunctionCallSubsystem_ELAPS_T_t -
        BalancingRobot_DW.FunctionCallSubsystem_PREV_T;
      BalancingRobot_DW.FunctionCallSubsystem_PREV_T =
        FunctionCallSubsystem_ELAPS_T_t;
      mpu6050_read_sensors();
      x = Accel_x_g();
      y = Accel_y_g();
      z = Accel_z_g();
      mpuTmp = Mpu_temp_c();
      x1 = Gyro_x_rad();
      b_y1 = Gyro_y_rad();
      z1 = Gyro_z_rad();
      q_0 = getQ_0();
      q_1 = getQ_1();
      q_2 = getQ_2();
      q_3 = getQ_3();
      pitch = getPitch();
      MadgwickAHRSupdateIMU(x1, b_y1, z1, x, y, z);
      rtb_SignPreIntegrator_m = getKp_theta();
      rtb_Switch = getKi_theta();
      rtb_NProdOut = getKd_theta();
      rtb_NProdOut_a = getN();
      rtb_NProdOut = (((0.0 - pitch) * rtb_NProdOut) -
                      BalancingRobot_DW.Filter_DSTATE) * rtb_NProdOut_a;
      rtb_SignPreIntegrator_m = (((0.0 - pitch) * rtb_SignPreIntegrator_m) +
        BalancingRobot_DW.Integrator_DSTATE) + rtb_NProdOut;
      if (rtb_SignPreIntegrator_m > 39.0) {
        rtb_Filter_i = 39.0;
      } else if (rtb_SignPreIntegrator_m < -39.0) {
        rtb_Filter_i = -39.0;
      } else {
        rtb_Filter_i = rtb_SignPreIntegrator_m;
      }

      if (rtb_Filter_i < 0.0) {
        {
          if (1.0 == 0)
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
          else
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
        }

        {
          /* Set GPIOD output mask value. */
          GPIOD_maskWrite = GPIOD->ODR;
          GPIOD_maskWrite &= 0xFFE1 ;
          GPIOD_maskWrite |= (uint16_t)0.0 << 1;
          GPIOD_maskWrite |= (uint16_t)1.0 << 2;
          GPIOD_maskWrite |= (uint16_t)1.0 << 3;
          GPIOD_maskWrite |= (uint16_t)0.0 << 4;

          /* Write GPIOD input value */
          GPIOD->ODR = (uint16_t)GPIOD_maskWrite;
        }
      } else {
        {
          if (0.0 == 0)
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
          else
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
        }

        {
          /* Set GPIOD output mask value. */
          GPIOD_maskWrite = GPIOD->ODR;
          GPIOD_maskWrite &= 0xFFE1 ;
          GPIOD_maskWrite |= (uint16_t)1.0 << 1;
          GPIOD_maskWrite |= (uint16_t)0.0 << 2;
          GPIOD_maskWrite |= (uint16_t)0.0 << 3;
          GPIOD_maskWrite |= (uint16_t)1.0 << 4;

          /* Write GPIOD input value */
          GPIOD->ODR = (uint16_t)GPIOD_maskWrite;
        }
      }

      rtb_Filter_i = fabs(rtb_Filter_i);
      if (rtb_SignPreIntegrator_m > 39.0) {
        rtb_SignPreIntegrator_m -= 39.0;
      } else if (rtb_SignPreIntegrator_m >= -39.0) {
        rtb_SignPreIntegrator_m = 0.0;
      } else {
        rtb_SignPreIntegrator_m -= -39.0;
      }

      rtb_NotEqual = (0.0 != rtb_SignPreIntegrator_m);
      if (rtb_SignPreIntegrator_m < 0.0) {
        rtb_SignPreIntegrator_m = -1.0;
      } else {
        if (rtb_SignPreIntegrator_m > 0.0) {
          rtb_SignPreIntegrator_m = 1.0;
        }
      }

      rtb_SignPreIntegrator_p = fmod(rtb_SignPreIntegrator_m, 256.0);
      rtb_SignPreIntegrator_m = (0.0 - pitch) * rtb_Switch;
      if (rtb_SignPreIntegrator_m < 0.0) {
        rtb_Add1_g = -1.0;
      } else if (rtb_SignPreIntegrator_m > 0.0) {
        rtb_Add1_g = 1.0;
      } else {
        rtb_Add1_g = rtb_SignPreIntegrator_m;
      }

      tmp_p = fmod(rtb_Add1_g, 256.0);
      if (rtb_NotEqual && (((int32_T)((int8_T)((rtb_SignPreIntegrator_p < 0.0) ?
              ((int32_T)((int8_T)(-((int8_T)((uint8_T)((real_T)
                    (-rtb_SignPreIntegrator_p))))))) : ((int32_T)((int8_T)
                ((uint8_T)rtb_SignPreIntegrator_p)))))) == ((tmp_p < 0.0) ?
            ((int32_T)((int8_T)(-((int8_T)((uint8_T)((real_T)(-tmp_p))))))) :
            ((int32_T)((int8_T)((uint8_T)tmp_p)))))) {
        rtb_Switch = 0.0;
      } else {
        rtb_Switch = rtb_SignPreIntegrator_m;
      }

      rtb_Filter_i *= 39.0;

      {
        BalancingRobot_B.PRESCALER_TIM3 = TIM3->PSC;
      }

      rtb_Divide_l = HAL_RCC_GetPCLK1Freq();

      {
        BalancingRobot_B.PERIOD_TIM3_CCR1 = TIM3->CCR1;
      }

      rtb_ZeroGain = ((1.0 / (BalancingRobot_B.PRESCALER_TIM3 + 1.0)) * (2.0 *
        rtb_Divide_l)) / BalancingRobot_B.PERIOD_TIM3_CCR1;
      rtb_Add1_l = rtb_Filter_i - rtb_ZeroGain;
      rtb_SignPreIntegrator = getKp();
      rtb_Switch_p = getKi();
      rtb_ZeroGain_ke = getKd();
      rtb_NProdOut_a = getN();
      rtb_NProdOut_k1 = ((rtb_Add1_l * rtb_ZeroGain_ke) -
                         BalancingRobot_DW.Filter_DSTATE_m) * rtb_NProdOut_a;
      rtb_SignPreIntegrator_m = ((rtb_Add1_l * rtb_SignPreIntegrator) +
        BalancingRobot_DW.Integrator_DSTATE_d) + rtb_NProdOut_k1;
      if (rtb_SignPreIntegrator_m > 700.0) {
        rtb_Add1_g = 700.0;
      } else if (rtb_SignPreIntegrator_m < 0.0) {
        rtb_Add1_g = 0.0;
      } else {
        rtb_Add1_g = rtb_SignPreIntegrator_m;
      }

      BalancingRobot_B.Subtract = (0.21574973031283712 * rtb_Add1_g) -
        58.899676375404532;

      {
        TIM9->CCR1 = BalancingRobot_B.Subtract;
      }

      {
        BalancingRobot_B.PRESCALER_TIM2 = TIM2->PSC;
      }

      {
        BalancingRobot_B.PERIOD_TIM2_CCR1 = TIM2->CCR1;
      }

      rtb_Divide_l = ((1.0 / (BalancingRobot_B.PRESCALER_TIM2 + 1.0)) * (2.0 *
        rtb_Divide_l)) / BalancingRobot_B.PERIOD_TIM2_CCR1;
      rtb_Add1_g = rtb_Filter_i - rtb_Divide_l;
      rtb_NProdOut_a *= (rtb_Add1_g * rtb_ZeroGain_ke) -
        BalancingRobot_DW.Filter_DSTATE_h;
      rtb_SignPreIntegrator = ((rtb_Add1_g * rtb_SignPreIntegrator) +
        BalancingRobot_DW.Integrator_DSTATE_j) + rtb_NProdOut_a;
      if (rtb_SignPreIntegrator > 700.0) {
        rtb_SignPreIntegrator_p = 700.0;
      } else if (rtb_SignPreIntegrator < 0.0) {
        rtb_SignPreIntegrator_p = 0.0;
      } else {
        rtb_SignPreIntegrator_p = rtb_SignPreIntegrator;
      }

      BalancingRobot_B.Subtract_f = (0.25641025641025644 *
        rtb_SignPreIntegrator_p) - 83.07692307692308;

      {
        TIM9->CCR2 = BalancingRobot_B.Subtract_f;
      }

      rtb_SignPreIntegrator_p = fmod(floor(BalancingRobot_B.PERIOD_TIM3_CCR1),
        4.294967296E+9);
      if (rtb_SignPreIntegrator_m > 700.0) {
        rtb_SignPreIntegrator_m -= 700.0;
      } else {
        if (rtb_SignPreIntegrator_m >= 0.0) {
          rtb_SignPreIntegrator_m = 0.0;
        }
      }

      rtb_NotEqual = (0.0 != rtb_SignPreIntegrator_m);
      if (rtb_SignPreIntegrator_m < 0.0) {
        rtb_SignPreIntegrator_m = -1.0;
      } else {
        if (rtb_SignPreIntegrator_m > 0.0) {
          rtb_SignPreIntegrator_m = 1.0;
        }
      }

      rtb_ZeroGain_ke = rtb_Add1_l * rtb_Switch_p;
      tmp_p = fmod(rtb_SignPreIntegrator_m, 256.0);
      if (rtb_ZeroGain_ke < 0.0) {
        rtb_ZeroGain_i = -1.0;
      } else if (rtb_ZeroGain_ke > 0.0) {
        rtb_ZeroGain_i = 1.0;
      } else {
        rtb_ZeroGain_i = rtb_ZeroGain_ke;
      }

      tmp = fmod(rtb_ZeroGain_i, 256.0);
      if (rtb_NotEqual && (((tmp_p < 0.0) ? ((int32_T)((int8_T)(-((int8_T)
                ((uint8_T)((real_T)(-tmp_p))))))) : ((int32_T)((int8_T)((uint8_T)
               tmp_p)))) == ((tmp < 0.0) ? ((int32_T)((int8_T)(-((int8_T)
                ((uint8_T)((real_T)(-tmp))))))) : ((int32_T)((int8_T)((uint8_T)
               tmp)))))) {
        rtb_SignPreIntegrator_m = 0.0;
      } else {
        rtb_SignPreIntegrator_m = rtb_ZeroGain_ke;
      }

      tmp_p = fmod(floor(BalancingRobot_B.PERIOD_TIM2_CCR1), 4.294967296E+9);
      if (rtb_SignPreIntegrator > 700.0) {
        rtb_SignPreIntegrator -= 700.0;
      } else {
        if (rtb_SignPreIntegrator >= 0.0) {
          rtb_SignPreIntegrator = 0.0;
        }
      }

      rtb_NotEqual = (0.0 != rtb_SignPreIntegrator);
      if (rtb_SignPreIntegrator < 0.0) {
        rtb_SignPreIntegrator = -1.0;
      } else {
        if (rtb_SignPreIntegrator > 0.0) {
          rtb_SignPreIntegrator = 1.0;
        }
      }

      rtb_ZeroGain_ke = rtb_Add1_g * rtb_Switch_p;
      tmp = fmod(rtb_SignPreIntegrator, 256.0);
      if (rtb_ZeroGain_ke < 0.0) {
        rtb_ZeroGain_i = -1.0;
      } else if (rtb_ZeroGain_ke > 0.0) {
        rtb_ZeroGain_i = 1.0;
      } else {
        rtb_ZeroGain_i = rtb_ZeroGain_ke;
      }

      rtb_SignPreIntegrator = fmod(rtb_ZeroGain_i, 256.0);

      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
      }

      rtb_Switch_p = 0.001 * ((real_T)FunctionCallSubsystem_ELAPS_T);
      BalancingRobot_DW.Integrator_DSTATE_d += rtb_Switch_p *
        rtb_SignPreIntegrator_m;
      BalancingRobot_DW.Filter_DSTATE_m += rtb_Switch_p * rtb_NProdOut_k1;
      if (rtb_NotEqual && (((tmp < 0.0) ? ((int32_T)((int8_T)(-((int8_T)
                ((uint8_T)((real_T)(-tmp))))))) : ((int32_T)((int8_T)((uint8_T)
               tmp)))) == ((rtb_SignPreIntegrator < 0.0) ? ((int32_T)((int8_T)
              (-((int8_T)((uint8_T)((real_T)(-rtb_SignPreIntegrator))))))) :
                           ((int32_T)((int8_T)((uint8_T)rtb_SignPreIntegrator))))))
      {
        rtb_ZeroGain_ke = 0.0;
      }

      BalancingRobot_DW.Integrator_DSTATE_j += rtb_Switch_p * rtb_ZeroGain_ke;
      BalancingRobot_DW.Filter_DSTATE_h += rtb_Switch_p * rtb_NProdOut_a;
      snprintf(string, 205, stringFormat, x, y, z, mpuTmp, x1, b_y1, z1, q_0,
               q_1, q_2, q_3, pitch, (rtb_SignPreIntegrator_p < 0.0) ?
               ((uint32_T)((int32_T)(-((int32_T)((uint32_T)((real_T)
        (-rtb_SignPreIntegrator_p))))))) : ((uint32_T)rtb_SignPreIntegrator_p),
               rtb_Add1_l, 0.0 - pitch, rtb_ZeroGain, BalancingRobot_B.Subtract,
               (tmp_p < 0.0) ? ((uint32_T)((int32_T)(-((int32_T)((uint32_T)
        ((real_T)(-tmp_p))))))) : ((uint32_T)tmp_p), rtb_Add1_g, rtb_Filter_i,
               rtb_Divide_l, BalancingRobot_B.Subtract_f);
      BalancingRobot_B.buff = getBuffPtr(string);
      BalancingRobot_B.nbChar = strlen(string);

      {
        if (BalancingRobot_B.nbChar != 0) {
          /* Copy data to send. */
          TX_CopyData(&USART3_TxConf, (uint8_t*)BalancingRobot_B.buff, (uint16_t)
                      BalancingRobot_B.nbChar);
        }

        if (USART3_TxConf.nb2Send) {
          BalancingRobot_B.USART_Send = 0;
          USART3_TX_SendData(&USART3_TxConf);
        }

        if (USART3_TxConf.txStatus != SERIAL_TX_ON) {
          BalancingRobot_B.USART_Send = USART3_TxConf.nbSent;
        }
      }

      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
      }

      BalancingRobot_DW.Integrator_DSTATE += rtb_Switch_p * rtb_Switch;
      BalancingRobot_DW.Filter_DSTATE += rtb_Switch_p * rtb_NProdOut;
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BalancingRobot_EXTI.c
 */
