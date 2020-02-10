/*
 * USART.C
 *
 * Created: 2/8/2020 9:09:20 PM
 * Author : EbrahimOseif & AhmedEhab
 */



#include "USART.h"
#include "registers.h"

extern ST_USART_Config UART_Config;

/*********************************/
 void USART_Init() {
	

	ST_USART_Config* Config = &UART_Config;
	UBRRL = 103;
	
	UCSRA |= Config->SPEED_MODE | (UCSRA &= ~ SPEED_MASK);
	
	UCSRB |= Config->TRANSMIT | (UCSRB &= ~ TRANSMIT_EN_MASK);
	
	UCSRB |= Config->RECIEVE	| (UCSRB &= ~ RECIEVE_EN_MASK);
	
	UCSRC |= (URSEL);
	
	switch(Config->CHAR_SIZE){
		case USART_9_Bit_CHAR:
			UCSRB |= (UCSZ2);			
		    UCSRC |= (USART_8_Bit_CHAR);
			break;
			
		default:
			UCSRC |= Config->CHAR_SIZE;
			break;
	}
	
	UCSRC |= Config->STOPBIT | (UCSRC &= ~ STOP_BIT_MASK);
	
	UCSRC |= Config->PARITY_MODE | (UCSRC &= ~ PARITY_MASK);
	
	UCSRC |= Config->SYNCH_MODE | (UCSRC &= ~ MODE_MASK);

}



 void USART_Transmit(uint16_t data) {
	/* Wait for empty transmit buffer */
	ST_USART_Config* Config = &UART_Config;
	while (!( UCSRA & (1 << UDRE)))
		;
	/***********if the data to be transmitted is 9 bits, write the MSB first*****************/
	if ( Config->CHAR_SIZE  ==	USART_9_Bit_CHAR )
	{
		UCSRB |= ((data >> 8) & 1);
	}
		/* Put data into buffer, sends the data */
	UDR = (unsigned char)data;
	//PORTC_DATA = 0xff;
}




 uint8_t USART_Receive(uint16_t *Ptr_To_Val) {
	 
	 ST_USART_Config* Config = &UART_Config;
	 unsigned char local_u8ParityError = 0; // 0 means error
	 *Ptr_To_Val = 0;
	 /* Wait for data to be received */
	 while (!(UCSRA & (1 << RXC)) )
	 	;
	 /****************Check if parity error is not ON********/
	 if(((UCSRA >> PE)& 1) != 1)
	 {/***********if the data to be recieved is 9 bits, get the MSB first*****************/
	 if (Config->CHAR_SIZE  ==	USART_9_Bit_CHAR)
	 {
	 	*Ptr_To_Val = (((UCSRB >> 1)& 1) << 8) ;
	 }
	 
	 	/* Get and return received data from buffer */
	 	*Ptr_To_Val |= UDR;
	 	local_u8ParityError = 1; //no error
	 }
	 return local_u8ParityError;

}




 void USART_Rec_Int_Enable(void)
{
	UCSRB |= 1<< RXCIE ;

}

 void USART_Rec_Int_Disable(void)
{
	UCSRB &= ~(1<<RXCIE);
}




 void USART_Trans_Int_Enable(void)
{
	UCSRB |= 1<< TXCIE ;
}


 void USART_Trans_Int_Disable(void)
{
	UCSRB &= ~ (1<<TXCIE);

}








 void USART_Rec_Enable(void)
{
	UCSRB |= 1<< RXEN ;

}

 void USART_Rec_Disable(void)
{
	UCSRB &=~(1<<RXEN);

}





 void USART_Trans_Enable(void)
{
	UCSRB |= 1<<TXEN;
}

 void USART_Trans_Disable(void)
{
	UCSRB &= ~ (1<<TXEN) ;
}