
#include<Servo.h>
float v=356.5,d,t;
int trig=10,echo=9,pos=0;
Servo pointer;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(6,OUTPUT);
pointer.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delayMicroseconds(200);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
t=pulseIn(echo,HIGH);
d=(50.0*t*v)/1000000;
Serial.println(d);
if(d<20 and d>5)
{

  pos=(d-5)*(179/15);
  tone(11,1);
  
  pointer.write(pos);
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);
}
else
{
  digitalWrite(6,LOW); 
  noTone(11);
  pointer.write(179);
}
}
