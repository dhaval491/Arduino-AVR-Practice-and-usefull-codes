#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include<inttypes.h>
int c=0;
void USART_Init( unsigned int ubrr){
/* Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
int main(void)
{
  DDRB=0xFF;
  
  USART_Init(103);
  while(1)
  {
    while(!(UCSR0A & 1<<RXC0));
    c= UDR0;
    if(c>46)
    {
      PORTB=0xFF;
      _delay_ms(5000);
      PORTB=0x00;
    }
  }
}






















//int state=0;
//
//void setup() {
//  // put your setup code here, to run once:
//Serial.begin(9600);
//pinMode(5,OUTPUT);
//pinMode(6,OUTPUT);
//pinMode(10,OUTPUT);
//pinMode(11,OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//if(Serial.available()>0)
//{
//  state=Serial.read();
//}
//
//  Serial.println(state);
//  
//  
//}

