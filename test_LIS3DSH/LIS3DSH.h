#ifndef __LIS3DSH_H
#define __LIS3DSH_H
#include <stdint.h>
#include "stm32f4xx.h"

#define OUT_T  			0x0C 
#define INFO1  			0x0D 
#define INFO2  			0x0E 
#define WHO_AM_I 		0x0F 
#define OFF_X  			0x10 
#define OFF_Y  			0x11 
#define OFF_Z  			0x12 
#define CS_X  			0x13 
#define CS_Y  			0x14 
#define CS_Z  			0x15 
#define LC_L  			0x16 
#define LC_H  			0x17 
#define STAT  			0x18 
#define PEAK1  			0x19 
#define PEAK2  			0x1A 
#define VFC_1  			0x1B 
#define VFC_2  			0x1C 
#define VFC_3  			0x1D 
#define VFC_4  			0x1E 
#define THRS3  			0x1F 
#define CTRL_REG4  	0x20 
#define CTRL_REG1  	0x21 
#define CTRL_REG2  	0x22 
#define CTRL_REG3  	0x23 
#define CTRL_REG5  	0x24 
#define CTRL_REG6  	0x25 
#define STATUS  		0x27
#define OUT_X_L 		0x28 
#define OUT_X_H 		0x29 
#define OUT_Y_L 		0x2A 
#define OUT_Y_H 		0x2B 
#define OUT_Z_L 		0x2C 
#define OUT_Z_H 		0x2D 

extern void spi_write(uint8_t reg, uint8_t data);
extern uint8_t spi_read(uint8_t reg);
extern void accelInit(void);
extern uint8_t who_am_i(void);
extern void read_accel(void);

extern int16_t accel_X(void);
extern int16_t accel_Y(void);
extern int16_t accel_Z(void);

extern int16_t rbuf[3];

#endif /* __LIS3DSH_H */

