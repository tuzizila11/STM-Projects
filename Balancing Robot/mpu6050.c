#include "mpu6050.h"
#include "stm32f4xx.h"                  // Device header
#include "MadgwickAHRS.h"
#include "math.h"


void setFlag(void)
{
	setup_flag = 1;  //flag
}

int8_t isSetup(void)
{
	return setup_flag;
}

static uint8_t DeviceAddr = MPU6050_ADDRESS;

static inline void __i2c_start() {
    I2C1->CR1 |= I2C_CR1_START;
    while(!(I2C1->SR1 & I2C_SR1_SB));
}

static inline void __i2c_stop() {
    I2C1->CR1 |= I2C_CR1_STOP;
    while(!(I2C1->SR2 & I2C_SR2_BUSY));
		(void)I2C1->SR2;
}


void i2c_write(uint8_t regaddr, uint8_t data) {
    // send start condition
    __i2c_start();

    // send chipaddr in write mode
    // wait until address is sent
    I2C1->DR = (uint8_t)(DeviceAddr << 1);
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    // dummy read to clear flags
    (void)I2C1->SR2; // clear addr condition

    // send MAP byte with auto increment off
    // wait until byte transfer complete (BTF)
    I2C1->DR = regaddr;
    while (!(I2C1->SR1 & I2C_SR1_BTF));
		
    // send data
    // wait until byte transfer complete
    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_BTF));

    // send stop condition
    __i2c_stop();
}


uint8_t i2c_read(uint8_t regaddr) {
    uint8_t reg;

    // send start condition
    __i2c_start();

    // send chipaddr in write mode
    // wait until address is sent
    I2C1->DR = (uint8_t)(DeviceAddr << 1);
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    // dummy read to clear flags
    (void)I2C1->SR2; // clear addr condition

    // send MAP byte with auto increment off
    // wait until byte transfer complete (BTF)
    I2C1->DR = regaddr;
    while (!(I2C1->SR1 & I2C_SR1_BTF));

    // restart transmission by sending stop & start
    //__i2c_stop();
    __i2c_start();

    // send chipaddr in read mode. LSB is 1
    // wait until address is sent
    I2C1->DR = (uint8_t)(DeviceAddr << 1)|1U; // read
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    // dummy read to clear flags
    (void)I2C1->SR2; // clear addr condition

    // wait until receive buffer is not empty
    while (!(I2C1->SR1 & I2C_SR1_RXNE));
    // read content
    reg = (uint8_t)I2C1->DR;

    // send stop condition
    __i2c_stop();

    return reg;
}

void setupMPU6050(void)
{
	i2c_write(0x6B, 0x00);                    // exit sleep
	i2c_write(0x1B, 0x18);                    // gyro full scale = +/- 2000dps
	i2c_write(0x1C, 0x08);                    // accelerometer full scale = +/- 4g
	i2c_write(0x19, 0x63);                    // sample rate = 8kHz / 110 = 72.7Hz
	i2c_write(0x38, 0x01);                    // enable INTA interrupt
}

void	I2C_Init(void){
	RCC->AHB1ENR |= 1<<3;	//Clocks for GPIOD
	GPIOD->MODER |= 0x55400000;	//Bits 11..15 are output
	GPIOD->MODER |= 1<<8;	//PB4 reset to CS43L22
	GPIOD->ODR |= (1U<<4);	//set high
	//configure the AF
	RCC->AHB1ENR |= 1<<1;	//Clock for GPIOB
	RCC->APB1ENR |= 1 <<21;	//clock to I2C1
	GPIOB->AFR[0] |= (4<< 24);	//enable SCK to PB6
	GPIOB->AFR[1] |= (4<< 4);	//enable SDA to PB9
	GPIOB->MODER &= ~(3U << 12);	//clear bits 12 & 13 (PB6)
	GPIOB->MODER |= 2 << 12;	//MODER6[1:0] = 10 bin
	GPIOB->MODER &= ~(3U << 18);	//clear bits 18 & 19 (PB9)
	GPIOB->MODER |= 2 << 18;	//MODER9[1:0] = 10 bin
	GPIOB->OTYPER |= 1 <<6;	//PB6 open drain
	GPIOB->OTYPER |= 1<<9;	//PB9 open drain
	GPIOB->PUPDR &= ~(3U << 12);//	clear bits 12 & 13 (PB6)
	GPIOB->PUPDR &= ~(3U << 18	);//clear bits 18 & 19 (PB9)
	//Configure the I2C
	I2C1->CR2 = 0x004;	//16MHz HSI
	I2C1->CCR = 0x0014;	//100kHz Bit rate
	I2C1->TRISE = 0x0004;	//1000 ns / 62.5 ns = 16 + 1
	I2C1->CR1 = 0x0001;	//enable peripheral
}

void mpu6050_read_sensors(void) {

	// read the sensor values
	for(int i = 0; i < dataSize; i++)
	{
		rx_buffer[i] = i2c_read(ACCEL_XOUT_H_REG + (uint8_t)i);
	}

	// extract the raw values
	int16_t  accel_x  = (int16_t)((rx_buffer[0]  << 8) | rx_buffer[1]);
	int16_t  accel_y  = (int16_t)((rx_buffer[2]  << 8) | rx_buffer[3]);
	int16_t  accel_z  = (int16_t)((rx_buffer[4]  << 8) | rx_buffer[5]);
	int16_t  mpu_temp = (int16_t)((rx_buffer[6]  << 8) | rx_buffer[7]);
	int16_t  gyro_x   = (int16_t)((rx_buffer[8]  << 8) | rx_buffer[9]);
	int16_t  gyro_y   = (int16_t)((rx_buffer[10] << 8) | rx_buffer[11]);
	int16_t  gyro_z   = (int16_t)((rx_buffer[12] << 8) | rx_buffer[13]);
	//int16_t  magn_x   = (int16_t)((rx_buffer[14] << 8) | rx_buffer[15]);
	//int16_t  magn_y   = (int16_t)((rx_buffer[16] << 8) | rx_buffer[17]);
	//int16_t  magn_z   = (int16_t)((rx_buffer[18] << 8) | rx_buffer[19]);
	
	// calculate the offsets at power up
	if(samples < 100) {
		samples++;
		return;
	} else if(samples < 200) {
		gyro_x_offset += gyro_x;
		gyro_y_offset += gyro_y;
		gyro_z_offset += gyro_z;
		samples++;
		return;
	} else if(samples == 200) {
		gyro_x_offset /= 100;
		gyro_y_offset /= 100;
		gyro_z_offset /= 100;
		samples++;
	} else {
		gyro_x -= gyro_x_offset;
		gyro_y -= gyro_y_offset;
		gyro_z -= gyro_z_offset;
	}

	// convert accelerometer readings into G's
	accel_x_g = accel_x / 8192.0f;
	accel_y_g = accel_y / 8192.0f;
	accel_z_g = accel_z / 8192.0f;

	// convert temperature reading into degrees Celsius
	mpu_temp_c = mpu_temp / 340.0f + 36.53f;

	// convert gyro readings into Radians per second
	gyro_x_rad = gyro_x / 939.650784f;
	gyro_y_rad = gyro_y / 939.650784f;
	gyro_z_rad = gyro_z / 939.650784f;

	// convert magnetometer readings into Gauss's
	//magn_x_gs = magn_x / 660.0f;
	//magn_y_gs = magn_y / 660.0f;
	//magn_z_gs = magn_z / 660.0f;

}

void setupExt(void)
{
	RCC->AHB1ENR |= (1 << 0);
	GPIOA->MODER &= 0xFFFFFFFC;   // Reset bits 0-1 to clear old values
	GPIOA->MODER |= 0x00000000;   // Make button an input

	// enable SYSCFG clock (APB2ENR: bit 14)
	RCC->APB2ENR |= (1 << 14);
	
	SYSCFG->EXTICR[0] |= 0x00000000; // Write 0000 to map PA0 to EXTI0

	// Choose either rising edge trigger (RTSR) or falling edge trigger (FTSR)
	EXTI->RTSR |= 0x00001;   // Enable rising edge trigger on EXTI0

	// Mask the used external interrupt numbers.
	EXTI->IMR |= 0x00001;    // Mask EXTI0

	// Set Priority for each interrupt request
	NVIC_SetPriority(EXTI0_IRQn, 1); // Priority level 1

	// enable EXT0 IRQ from NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void enableI2C(void)
{
	I2C1->CR1 = 0x0001;	//enable peripheral
}

float Accel_x_g(void)
{
	return accel_x_g;
}
float Accel_y_g(void)
{
	return accel_y_g;
}

float Accel_z_g(void)
{
	return accel_z_g;
}

float Mpu_temp_c(void)
{
	return mpu_temp_c;
}

float Gyro_x_rad(void)
{
	return gyro_x_rad;
}

float Gyro_y_rad(void)
{
	return gyro_y_rad;
}

float Gyro_z_rad(void)
{
	return gyro_z_rad;
}

