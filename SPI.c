/*
 * SPI.c
 *
 * Created: 2/8/2020 10:15:20 PM
 * Author : EbrahimOseif & AhmedEhab
 */
#include "SPI.h"
#include "registers.h"



struct S_SPI_Configuration gConfig ;

static void (*SPI_ISR)(void);

void SPI_Init(
		struct S_SPI_Configuration spi_Config )
{

	gConfig = spi_Config ;
		
	/********************Enable SPI Interrupt ******************/
		
	//SPCR = SPCR | (SPI_INT_ENABLE<<SPIE);
	//SPCR = SPCR |  (SPI_INT_ENABLE<<SPIE) | (SPI_ENABLE<<SPE) | (SPI_DATA_ORDER<<DORD) | (SLAVE_MODE<<MSTR) | (SPI_OPERATING_LEVEL<<CPOL) | (SPI_SAMPLING_EDGE<<CPHA) | (SPI_PRESCALAR);


	if (gConfig.INT_ENABLE == SPI_INT_ON)
		SetBit(SPCR, SPIE);
		
	else if (gConfig.INT_ENABLE == SPI_INT_OFF)
		ClearBit(SPCR, SPIE);

	/*******************Data Order ******************/

	if (gConfig.DATA_ORDER == SPI_LSB_FISRT)
		SetBit(SPCR, DORD);
	else if (gConfig.DATA_ORDER == SPI_MSB_FISRT)
		ClearBit(SPCR, DORD);

	/********************Master Slave Select ******************/

	if (gConfig.SLAVE_MODE == SPI_MASTER)
		SetBit(SPCR, MSTR);
		
	else if (gConfig.SLAVE_MODE == SPI_SLAVE)
		ClearBit(SPCR, MSTR);

	/********************clock polarity******************/
	if (gConfig.OPERATING_LEVEL == SPI_IDLE_LOW)
		SetBit(SPCR, CPOL);
	else if (gConfig.OPERATING_LEVEL == SPI_IDLE_HIGH)
		ClearBit(SPCR, CPOL);

	/********************clock phase******************/
	if (gConfig.SAMPLING_EDGE == SPI_RISING)
		SetBit(SPCR, CPHA);
		
	else if (gConfig.SAMPLING_EDGE == SPI_FALLING)
		ClearBit(SPCR, CPHA);

	/********************SPI pre-scalar in case of master ******************/
		SPCR = SPCR | (gConfig.PRESCALAR);
	/********************Double SPI speed if master******************/

		if (gConfig.DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_ON)
			SetBit(SPSR, SPI2X);
			
		else if (gConfig.DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_OFF)
			ClearBit(SPSR, SPI2X);

	/********************Enable SPI ******************/
		if (gConfig.ENABLE == SPI_ENABLE_ON)
			SetBit(SPCR, SPE);
			
		else if (gConfig.ENABLE == SPI_ENABLE_OFF)
			ClearBit(SPCR, SPE);
}



uint8_t  SPI_Send_And_receive(uint8_t u8_data)
{
/* Start transmission */
SPDR = u8_data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
	//return SPDR ; // Received data
return 1;
}

 uint8_t SPI_Checks_for_collision(void)
{
	 return GetBit(SPSR, WCOL); 
}


  void SPI_callBackFunc_Assign(void (*PtrToSPI_Isr) (void))
 {
 	SPI_ISR = PtrToSPI_Isr;
 }


  /*ISR(SPI_STC_vect)
  {
  	SPI_ISR();
  }*/

