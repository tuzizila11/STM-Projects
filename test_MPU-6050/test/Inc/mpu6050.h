#ifndef __MPU6050_H
#define __MPU6050_H

#include <stdint.h>

#define ACTION			GPIOD->ODR |= 1U<<12
#define ACTION_E   	GPIOD->ODR &= ~(1U<<12)
#define ADDRESS			GPIOD->ODR |= 1U<<13
#define ADDRESS_E   GPIOD->ODR &= ~(1U<<13)
#define WRITE				GPIOD->ODR |= 1<<14
#define WRITE_E			GPIOD->ODR &= ~(1U<<14)
#define READ				GPIOD->ODR |= 1U<<15
#define READ_E			GPIOD->ODR &= ~(1U<<15)

#define MPU6050_ADDRESS  	0x68
#define WHO_AM_I_REG			0x75
#define PWR_MAGT_1_REG		0x6B
#define CONFIG_REG				0x1A
#define GYRO_CONFIG_REG		0x1B
#define ACCEL_CONFIG_REG	0x1C
#define SMPLRT_DIV_REG		0x19
#define INT_STATUS_REG		0x3A
#define ACCEL_XOUT_H_REG	0x3B
#define TEMP_OUT_H_REG		0x41
#define GYRO_XOUT_H_REG		0x43
#define FIFO_EN_REG 			0x23
#define INT_ENABLE_REG 		0x38
#define I2CMACO_REG 			0x23
#define USER_CNT_REG			0x6A
#define FIFO_COUNTH_REG 	0x72
#define FIFO_R_W_REG 			0x74

#define dataSize 					14

extern int8_t isSetup(void);
extern void setFlag(void);
extern void setupMPU6050(void);
extern uint8_t i2c_read(uint8_t regaddr);
extern void i2c_write(uint8_t regaddr, uint8_t data);
extern void	I2C_Init(void);
extern void mpu6050_read_sensors(void);
extern void setupExt(void);
extern void enableI2C(void);

extern float Accel_x_g(void);
extern float Accel_y_g(void);
extern float Accel_z_g(void);
extern float Mpu_temp_c(void);
extern float Gyro_x_rad(void);
extern float Gyro_y_rad(void);
extern float Gyro_z_rad(void);

static float gyro_x_cal;
static float gyro_y_cal;
static float gyro_z_cal;



static int8_t setup_flag = 0;

static float accel_x_g;
static float accel_y_g;
static float accel_z_g;
static float mpu_temp_c;
static float gyro_x_rad;
static float gyro_y_rad;
static float gyro_z_rad;
static float magn_x_gs;
static float magn_y_gs;
static float magn_z_gs;
static uint8_t rx_buffer[dataSize];


#endif

