//----------------------------------------------slave program--------------------------------------------------
#include<avr/io.h>
#include<util/delay.h>
void setup()
{
  DDRB=0x00;
  Serial.begin(9600);
}
void loop()
{

  // while(!(TWCR&(1<<TWINT));
DDRB=0xFF;
  while (1)
  {
    TWCR = (1 << TWEN) | (1 << TWEA);
    TWAR = 0b11110000;
    TWCR = (1 << TWEN) | (1 << TWEA);
    if (TWSR == 0xA8)
    {
      //TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
      Serial.print("1");
      PORTB = 0b00000001;
      _delay_ms(1000);
      PORTB&=0x00;// notify when data is recieved
    }
    TWDR = 4;
    TWCR = (1 << TWEN) | (1 << TWEA) ;
  }
  while(1);
}





//if (TWDR == 3)
//    {
//      TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
//      PORTD = 0b11000000;
//      _delay_ms(100);
//
//    }
//    if (TWDR == 5)
//    {
//      TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
//      PORTD = 0b10000000;
//      _delay_ms(1000);
//
//    }
//    if (TWDR == 6)
//    {
//      TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
//      PORTD = 0b11000000;
//      _delay_ms(1000);
//
//    }
//
//    if (TWSR == 0xA0);
//    {
//      TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
//      PORTB = 0x00;
//      PORTD = 0x00;
//      _delay_ms(100);
//    }
//    _delay_ms(1000);






//
//
//
//
//
////----------------------------------------------slave program--------------------------------------------------
//#include<avr/io.h>
//#include<util/delay.h>
//int main(void)
//{
//
//  // while(!(TWCR&(1<<TWINT));
//
//  while (1)
//  {
//    TWCR = (1 << TWEN) | (1 << TWEA);
//    TWAR = 0x05 << 1 + 0x00;
//    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
//    if (TWDR == 1)
//    {
//      PORTD = 0b10000000;
//      _delay_ms(100);// notify when data is recieved
//    }
//    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); //most eggregious mistake
//    if (TWDR == 2)
//    {
//      PORTD = 0b11000000;
//      _delay_ms(100);
//
//    }
//    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
//    if (TWDR == 3)
//    {
//      PORTD = 0b11100000;
//      _delay_ms(100);
//
//    }
//    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
//    if (TWDR == 4)
//    {
//      PORTD = 0b11111000;
//      _delay_ms(100);
//
//    }
//    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
//    if (TWSR == 0xA0);
//    {
//      PORTB = 0x00;
//      PORTD = 0x00;
//      _delay_ms(100);
//    }
//    _delay_ms(1000);
//  }
//}







//
//
//
//#include<avr/io.h>
//#include<util/delay.h>
//
//int main()
//{
//  TWAR=0x04<<0+0x00;
//  DDRD = 0xFF;
//  DDRB = 0xFF;
//  while (1)
//  {
//    DDRC = 0x00;
//    PORTC = 0xFF;
//
//    //Start condition//
//
//    TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT); // start condition for TWI
//    while (!(TWCR & (1 << TWINT))); // wait till twint is set and confirms START codition is send
//    TWDR = 0x05 << 1 + 0x00;
//    TWCR = (1 << TWINT) | (1 << TWEN);
//    while (!(TWCR & (1 << TWINT)));
//    TWDR = 1;
//    TWCR = (1 << TWINT) | (1 << TWEN); // set twcr to start transmission
//    while (!(TWCR & (1 << TWINT)));
//    TWDR = 2;
//    TWCR = (1 << TWINT) | (1 << TWEN); // set twcr to start transmission
//    while (!(TWCR & (1 << TWINT)));
//    TWDR = 3;
//    TWCR = (1 << TWINT) | (1 << TWEN); // set twcr to start transmission
//    while (!(TWCR & (1 << TWINT)));
//    TWDR = 4;
//    TWCR = (1 << TWINT) | (1 << TWEN); // set twcr to start transmission
//    while (!(TWCR & (1 << TWINT)));
//    TWCR = (1 << TWINT) | (1 << TWEN)|(1<< TWSTO);
//    while (1);
//    //    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
//    //    while(1);
//    //     // stop the transmission
//  }
//}

