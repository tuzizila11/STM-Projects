/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_EXTI.c
 *
 * Code generated for Simulink model :test.
 *
 * Model version      : 1.497
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (May 28 2020)
 * C/C++ source code generated on  : Sun Sep 20 02:49:40 2020
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

#include "test.h"
#include "test_EXTI.h"

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
 * Function Name  : EXTI0_Callback
 * Description    : Callback for External Interrupt connected to Pin0
 * Input          : -
 *******************************************************************************/
void EXTI0_Callback()
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
      char_T string[99];
      static const char_T stringFormat[74] =
        "%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f,%7.3f\r\n";
      mpu6050_read_sensors();
      x = Accel_x_g();
      y = Accel_y_g();
      z = Accel_z_g();
      mpuTmp = Mpu_temp_c();
      x1 = Gyro_x_rad();
      b_y1 = Gyro_y_rad();
      z1 = Gyro_z_rad();
      MadgwickAHRSupdateIMU(x1, b_y1, z1, x, y, z);
      q_0 = getQ_0();
      q_1 = getQ_1();
      q_2 = getQ_2();
      q_3 = getQ_3();
      pitch = getPitch();
      snprintf(string, 99, stringFormat, x, y, z, mpuTmp, x1, b_y1, z1, q_0, q_1,
               q_2, q_3, pitch);
      test_B.buff = getBuffPtr(string);
      test_B.nbChar = strlen(string);

      {
        if (test_B.nbChar != 0) {
          /* Copy data to send. */
          TX_CopyData(&USART3_TxConf, (uint8_t*)test_B.buff, (uint16_t)
                      test_B.nbChar);
        }

        if (USART3_TxConf.nb2Send) {
          test_B.USART_Send = 0;
          USART3_TX_SendData(&USART3_TxConf);
        }

        if (USART3_TxConf.txStatus != SERIAL_TX_ON) {
          test_B.USART_Send = USART3_TxConf.nbSent;
        }
      }

      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
      }
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test_EXTI.c
 */
