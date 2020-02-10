/*
 * UART_Config.h
 *
 * Created: 2020-02-10 3:22:00 PM
 *  Author: EbrahimOseif & AhmedEhab
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
 
 
 typedef enum USART_SYNCH_MODE
 {
	 USART_ASYNCH = 0x00,
	 USART_SYNC	 = 0x01
 }EN_USART_SYNCH_MODE;

typedef enum USART_SPEED_MODE
{
	USART_NORMAL_SPEED = 0x00,
	USART_DOUBLE_SPEED = 0x01
}EN_USART_SPEED_MODE;

typedef enum USART_TRANSMIT
{
	USART_TRANSMIT_DISABLE	= 0x00,
	USART_TRANSMIT_ENABLE	= 0x08
}EN_USART_TRANSMIT;

typedef enum USART_RECIEVE
{
	USART_RECIEVE_DISABLE	= 0x00,
	USART_RECIEVE_ENABLE	= 0x10
}EN_USART_RECIEVE;

typedef enum USART_CHAR_SIZE
{
	USART_5_Bit_CHAR 	= 0x00,
	USART_6_Bit_CHAR 	= 0x01,
	USART_7_Bit_CHAR	= 0x02,
	USART_8_Bit_CHAR	= 0x03,
	USART_9_Bit_CHAR
}EN_USART_CHAR_SIZE;


typedef enum USART_PARITY_MODE
{
	USART_NO_PARITY		= 0x00,
	USART_EVEN_PARITY   = 0x02,
	USART_ODD_PARITY	= 0x03
}EN_USART_PARITY_MODE;

typedef enum USART_STOPBIT
{
	USART_1_STOPBIT	= 0x00,
	USART_2_STOPBIT = 0x01
}EN_USART_STOPBIT;

typedef enum USART_RECIEVE_INT
{
	USART_RECIEVER_DISABLE 	= 0x00,
	USART_RECIEVER_ENABLE 	= 0x01
}EN_USART_RECIEVE_INT;

typedef enum USART_TRANSMITER_INT
{
	USART_TRANSMITER_DISABLE	= 0x00,
	USART_TRANSMITER_ENABLE		= 0x01
}EN_USART_TRANSMITER_INT;


typedef struct USART_Config
{
	EN_USART_SYNCH_MODE SYNCH_MODE ;
	EN_USART_SPEED_MODE SPEED_MODE;
	EN_USART_TRANSMIT TRANSMIT;
	EN_USART_RECIEVE RECIEVE;
	EN_USART_CHAR_SIZE CHAR_SIZE ;
	EN_USART_PARITY_MODE PARITY_MODE;
	EN_USART_STOPBIT STOPBIT;
	//	EN_USART_RECIEVE_INT RECIEVE_INT;
	//EN_USART_TRANSMITER_INT TRANSMITER_INT;
}ST_USART_Config;




#endif /* UART_CONFIG_H_ */