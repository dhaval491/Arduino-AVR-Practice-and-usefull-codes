    int i,state=0;
float t,d,v=356.35; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,INPUT);
pinMode(10,OUTPUT);
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(7,LOW);
delayMicroseconds(2000);
digitalWrite(7,HIGH);
delayMicroseconds(10);
digitalWrite(7,LOW);
t=pulseIn(8,HIGH);
d=(50*t*v)/1000000;

if(Serial.available()>0)
{
  state=Serial.read();
}
if(state==44)//start
{
  digitalWrite(13,HIGH);//active enable pins
  digitalWrite(12,HIGH); 
}

if(state==49&&d>10)//revesre
{
  analogWrite(5,255);
  analogWrite(6,0);
  analogWrite(10,255 );
  analogWrite(11,0);
}
if(state==48&&d>10)//forward
{
  analogWrite(5,0);
  analogWrite(6,255);
  analogWrite(10,0);
  analogWrite(11,255);
}
if(state==46&&d>10)//left
{
  analogWrite(5,0);
  analogWrite(6,255);
  analogWrite(10,255);
  analogWrite(11,0);
}
if(state==45   &&d>10)//right
{
analogWrite(5,255);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,255);
}
if(state==47&&d>10)//stop
{
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0 );   
}
else if(d<10)
{
  analogWrite(5,0);
  analogWrite(6,255);
  analogWrite(10,0 );
  analogWrite(11,255);
}
Serial.print(state);
Serial.print("      ");
Serial.println(d);
delay(200);
}
