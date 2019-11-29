#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
int extraTime = 0, x = 50;


int main(void)
{
  DDRB = 0x01;
  TCCR2A = 0x00; //Set normal mode Bit
  TIMSK2 = (1 << TOIE2);

  sei();

  TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20); //start at 1024 prescalar

  while (1)
  {
    if (extraTime < x)
    {
      PORTB = 0xFF;
    }
    if (extraTime > x && extraTime < (2 * x))
    {
      PORTB = 0x00;
    }
    if (extraTime > (2 * x))
    {
      extraTime = 0;
    }
    //TODO:: Please write your application code
  }
}

ISR(TIMER2_OVF_vect)
{
  extraTime++;
}
