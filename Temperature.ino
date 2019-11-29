
int v;
int T;
void setup()
{
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);

}

void loop() 
 { // put your main code here, to run repeatedly:
v=analogRead(A0);
T=v/1024.*205;
Serial.println(v);

}
