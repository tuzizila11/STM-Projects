#include "LIS3DSH.h"

uint8_t setupComplete = 0;
uint8_t status_reg;

uint8_t data_OUT_X_L; 		 
uint8_t data_OUT_X_H; 		 
uint8_t data_OUT_Y_L; 		 
uint8_t data_OUT_Y_H; 		 
uint8_t data_OUT_Z_L; 		 
uint8_t data_OUT_Z_H;

void spi_write(uint8_t reg, uint8_t data)
{
    GPIOE->ODR &= ~(1U << 3); // enable
    // bit 15 is 0 for write for lis302dl
    uint32_t frame = 0;
    frame = data;
    frame |= (uint16_t)(reg << 8);
    // Send data
    SPI1->DR = frame;
    // wait until transmit is done (TXE flag)
    while (!(SPI1->SR & (1 << 1)));
    // wait until rx buf is not empty (RXNE flag)
    while (!(SPI1->SR & (1 << 0)));

    GPIOE->ODR |= (1 << 3); // disable
    (void)SPI1->DR; // dummy read
}

uint8_t spi_read(uint8_t reg)
{
    GPIOE->ODR &= ~(1U << 3); // enable
    // bit 15 is 1 for read for lis302dl
    uint16_t frame = 0;
    frame |= (uint16_t)(reg << 8);
    frame |= (1 << 15); // read bit
    // Send data
    SPI1->DR = frame;
    // wait until tx buf is empty (TXE flag)
    while (!(SPI1->SR & (1 << 1)));
    // wait until rx buf is not empty (RXNE flag)
    while (!(SPI1->SR & (1 << 0)));

    uint8_t b = (uint8_t)SPI1->DR;
    GPIOE->ODR |= (1 << 3); // disable
    return b;
}

void accelInit(void)
{
	if (setupComplete == 0)
	{
		// enable SPI - SPE bit 6
		SPI1->CR1 |= (1 << 6);
		
		spi_write(CTRL_REG4, 0x67);			// X, Y, Z enabled, ODR = 100 Hz
		spi_write(CTRL_REG3, 0x88);			// DRY active high on INT1 pin
		
		for(int i=0; i<10000000; i++);
		
		setupComplete = 1;
	}

}

uint8_t who_am_i(void)
{
	// read who am i
    return (int8_t)spi_read(WHO_AM_I);
}

void read_accel(void)
{
	status_reg = spi_read(STATUS);
	
	if (status_reg & (1 << 3))
	{
		data_OUT_X_L = spi_read(OUT_X_L);
		data_OUT_X_H = spi_read(OUT_X_H);
		data_OUT_Y_L = spi_read(OUT_Y_L);
		data_OUT_Y_H = spi_read(OUT_Y_H);
		data_OUT_Z_L = spi_read(OUT_Z_L);
		data_OUT_Z_H = spi_read(OUT_Z_H);
	}
	
}

int16_t accel_X()
{
	return (int16_t)((data_OUT_X_H << 8) + data_OUT_X_L);
}

int16_t accel_Y()
{
	return (int16_t)((data_OUT_Y_H << 8) + data_OUT_Y_L);
}

int16_t accel_Z()
{
	return (int16_t)((data_OUT_Z_H << 8) + data_OUT_Z_L);
}
