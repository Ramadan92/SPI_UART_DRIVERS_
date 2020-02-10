/*
 * USART.h
 *
 * Created: 2/8/2020 9:09:20 PM
 * Author : EbrahimOseif & AhmedEhab
 */

#ifndef USART_USART_H_
#define USART_USART_H_

#include "UART_Config.h"
#include "std_types.h"

//Configuration

#define BAUD_RATE		(((F_CPU)/ (BAUD *16ul))-1)	
#define UBRR			(UBRRL | UBRRH << 8)

#define MODE_MASK	0X40

#define SPEED_MASK	0x01

#define  TRANSMIT_EN_MASK 0x08

#define  RECIEVE_EN_MASK 0x10

#define  CHAR_SIZE_MASK 0x10

#define PARITY_MASK		0x30

#define STOP_BIT_MASK	0x08

#define RECIEVE_INT_MASK 0x80

#define TRANSMITER_INT_MASK 0x40




///////////////////////////////////APIs
 void USART_Init(void);
 void USART_Transmit(uint16_t data);
 uint8_t USART_Receive(uint16_t *Ptr_To_Val);
 void USART_Rec_Int_Enable(void);
 void USART_Rec_Int_Disable(void);
 
 void USART_Trans_Int_Enable(void);
 void USART_Trans_Int_Disable(void);
 
 void USART_Rec_Enable(void);
 void USART_Rec_Disable(void);
 
 void USART_Trans_Enable(void);
 void USART_Trans_Disable(void);
 
 void USART_callback_Rec_Int(void (*Ptr_to_Func)(void));
 void USART_callback_Trans_Int(void (*Ptr_to_Func)(void));
/********************************Registers***********************************/


/**********************UCSRA************************/
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR		3
#define PE 		2
#define U2X		1
#define MPCM	0

/**********************UCSRB************************/
#define RXCIE 	7
#define TXCIE	6
#define UDRIE	5
#define RXEN 	4
#define TXEN	3
#define UCSZ2	0x04
#define RXB8	1
#define TXB8	0

/**********************UCSRC************************/
#define URSEL	0x80
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0




#endif /* USART_USART_H_ */
