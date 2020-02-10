/*
 * UART_Config.c
 *
 * Created: 2020-02-10 3:22:24 PM
 *  Author: EbrahimOseif & AhmedEhab
 */ 
#include "UART_Config.h"

#define F_CPU			16000000ul	/* CPU Frequency */
#define BAUD		    9600ul		/* Baud rate */

/*************************************/
/*									 */
/*		User Configurations          */
/*                                   */
/*************************************/
ST_USART_Config UART_Config = {
	/* for synchronous write USART_SYNCH 
	for asynchronous write USART_ASYNCH */  USART_ASYNCH  ,
	
	/*for normal speed write USART_NORMAL_SPEED 
	for double speed write USART_DOUBLE_SPEED */  USART_NORMAL_SPEED  ,
	
	/*to enable transmitter write USART_TRANSMIT_ENABLE
	to disable transmitter write USART_TRANSMIT_DISABLE*/  USART_TRANSMIT_ENABLE  ,
	
	/*to enable receiver write USART_RECIEVE_ENABLE
	to disable receiver write USART_RECIEVE_DISABLE*/  USART_RECIEVE_ENABLE  ,
	
	/*for 5 bit data write USART_5_Bit_CHAR
	for 6 bit data write USART_6_Bit_CHAR
	for 7 bit data write USART_7_Bit_CHAR
	for 8 bit data write USART_8_Bit_CHAR
	for 9 bit data write USART_9_Bit_CHAR*/  USART_8_Bit_CHAR  ,
	
	/*for even parity write USART_EVEN_PARITY
	for odd parity write USART_ODD_PARITY
	for no parity write USART_NO_PARITY*/  USART_EVEN_PARITY  ,
	
	/*for 1 stop bit write USART_1_STOPBIT
	for 2 stop bits write USART_2_STOPBIT*/  USART_1_STOPBIT  
	
};