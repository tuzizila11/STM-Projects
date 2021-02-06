void	I2C_Init(void);
void	who_am_I(void);
void	I2C_Write (unsigned char c);
unsigned char	I2C_Read (int ack);
void	I2C_Addr (unsigned char adr);
void	I2C_Start(void);
void	I2C_Stop (void);

#define ACTION			GPIOD->ODR |= 1U<<12
#define ACTION_E   	GPIOD->ODR &= ~(1U<<12) 
#define ADDRESS			GPIOD->ODR |= 1U<<13
#define ADDRESS_E   GPIOD->ODR &= ~(1U<<13)   
#define WRITE				GPIOD->ODR |= 1<<14
#define WRITE_E			GPIOD->ODR &= ~(1U<<14)
#define READ				GPIOD->ODR |= 1U<<15
#define READ_E			GPIOD->ODR &= ~(1U<<15)

void	I2C_Start(void) {
	ACTION;	//To highlight start on MSO
	I2C1->CR1 |= 1<<8;	//I2C Start
	while (!(I2C1->SR1 & 0x0001));	//wait for start bit - see status register
}

void	I2C_Stop (void) {
	I2C1->CR1 |= 0x0200;
	while (I2C1->SR2 & 0x0002);	//wait for BUSY set see status register
	ACTION_E;	//Highlight stop on MSO
}

void	I2C_Write (unsigned char c){
	WRITE;	//Indicate write on MSO
	I2C1->DR = c;
	while (!(I2C1->SR1 & (1<<7)));	// Wait TxE bit set - see status register
	WRITE_E;
} 

unsigned char	I2C_Read (int ack){
	READ;	//Indicate read on MSO
	if (ack) I2C1->CR1 |= 0x0400;	//multiple bytes - set acknowledge bit in I2C_CR1
      else I2C1->CR1 &= ~0x0400U;	//single or last byte clear ack bit
	while (!(I2C1->SR1 & 0x00000040));	// Wait until RxNE bit set - see status register
	READ_E;
return (char)(I2C1->DR);
}

void	I2C_Addr (unsigned char adr){
	char res;
	ADDRESS;	//Signal for MSO
	I2C1->DR = adr | 0;	//Write to I2C Address register
	while (!(I2C1->SR1 & 0x0002));	//wait until address sent - see status register
	res = (char)(I2C1->SR2);	//dummy read to clear - see status register 2
	ADDRESS_E;
}

void	who_am_I(void) {
	char res;
	I2C_Start();	//see I2C_CR1 for code
	I2C_Addr(0x94);	//Write Address of slave: Note 1 and I2C_DR for code
	I2C_Write(0x01);	//write to sub-address/register/MAP - see Note 2 and I2C_DR for code
	I2C_Start();	//I2C Start - Restart
	I2C_Addr(0x95);	// I2C Address for read. Note 1
	res = I2C_Read(0);	//read register -See Note 3 and I2C_DR for code
	I2C_Stop();	//see I2C_CR1 for code
}

