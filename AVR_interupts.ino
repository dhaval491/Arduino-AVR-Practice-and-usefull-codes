#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
int count=1;


ISR(INT0_vect)
{
  count++;
}
int main()
{
  DDRB=0xFF;
  PORTB=0x00;
 PORTD=0xFF;
 sei();
 EICRA = 0b00000011;         // Enable INT0
 EIMSK = 0b00000001;  
while(1)
{
  PORTB=0x00;
  if(count%5==0)
  {
    for(int i=0;i<5;i++)
    {
      PORTB=0xFF;
      _delay_ms(100);
      PORTB=0x00;
      _delay_ms(100);
     
    }
    count=1;
  }
}
}


