float v,V,Vo,Vdr,Vd,I;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(A0,INPUT);
pinMode(A2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<5;i++)
{
v=analogRead(A0);//read from pot in terms of 1024//
V=(v*5.0)/1024.0;//convert into 5v scale//
Vo=(V/5)*255.0;//convert into 255 scale t give input to diode circuit//
analogWrite(9,Vo);//send input of pot to diode circuit on 255 scale//
Vdr=analogRead(A2);//read voltsge of diode on 255 scale//
Vd=(Vdr/1024)*V;//convert voltage on scale of 5 v
I=(V-Vd)/2;
if(Vdr==0)
{
  continue;
}

Serial.print("Supplied Voltage");
Serial.print("  ");
Serial.print(V);
Serial.print("  ");
//Serial.print(Vo);
//Serial.print("  ");
//Serial.print(Vdr);
Serial.print("  Voltage accross diode is ");
Serial.print(Vd);
Serial.print("     Diode Current in micrAmps is ");
Serial.println(I
);
delay(100);
}
}
