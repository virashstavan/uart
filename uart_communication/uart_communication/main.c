/*
 * uart_communication.c
 *
 * Created: 24-07-2019 18:46:35
 * Author : steve
 */ 

#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#include<string.h>
// define some macros
#define BAUDrate 9600 
#define F_CPU 8000000UL                                 // define baud
#define ubrr 51
//char string1[10];
// function to initialize UART
void uart_init (int baud)
{   // to establish uart 0
    UBRR0H = (unsigned char)(baud>>8);                      // shift the register right by 8 bits
    UBRR0L =(unsigned char) baud;                           // set baud rate
    UCSR0B |= (1<<RXEN0)|(1<<TXEN0);                     // 4 rxen and 3 txen
                   // enable receiver and transmitter
    UCSR0C=0b10000110;
    
     /* // to establish uart 1
    UBRR1H = (unsigned char)(baud>>8);                      // shift the register right by 8 bits
    UBRR1L =(unsigned char) baud;                           // set baud rate
    UCSR1B |= (1<<RXEN1)|(1 << TXEN1); 
    // enable receiver and transmitter
    UCSR1C=0b10000110;   // 8bit data format*/
}

// function to send data
void USART_Transmit( unsigned char data )

{

    /* Wait for empty transmit buffer */

    while ( !( UCSR0A & (1<<UDRE0)) );
    
        UDR0 = data;
        //_delay_ms(10);
    
}

    // function to receive data
unsigned char USART_Receive( void )

{

    // Wait for data to be received 

    while ( !(UCSR0A & (1<<RXC0)) );

     ///Get and return received data from buffer 
    
    return UDR0;

}

void main()
{	
	uart_init(51);
	char data;	
    data=USART_Receive();
	USART_Transmit(data);
	while(1)
    {    
		
  	}
}

