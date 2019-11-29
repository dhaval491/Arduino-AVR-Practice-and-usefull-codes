//write a progrsm to allow user to input whether the led blinks on odd count or even count//
String s1="Wellcome";
String s2=" Enter if you want LED to blink on odd count or even count";
String s3;
String count;
int i,j,k,l;

void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
s3=s1+s2;
Serial.println(s3);
while(Serial.available()==0){}
count=Serial.readString();
Serial.println(" ");
if(count=="odd")
{
for(i=1;i<=20;i++)
  {
    if(i%2==1)
    {
      Serial.print("LED blink no: ");
      Serial.println((i/2)+1);
      digitalWrite(12,HIGH);
      delay(500);
      digitalWrite(12,LOW);
      delay(500);
    }
    else
    {
      Serial.println("buzzer sounds");
      digitalWrite(8,OUTPUT);
      delay(500);
      digitalWrite(8,LOW);
      delay(500);
    }
  } 
 }
 else if(count=="even")
 {
for(j=1;j<=20;j++)
  {
    if(j%2==0)
    {
      Serial.print("LED blink no: ");
      Serial.println((j/2));
      digitalWrite(12,OUTPUT);
      delay(500);
      digitalWrite(12,LOW);
      delay(500);
    }
    else
    {
       Serial.println("buzzer sounds");
      digitalWrite(8,HIGH);
      delay(500);
      digitalWrite(8,LOW);
      delay(500); 
  }
 }
}
else
{
  Serial.println("Please choose correctly from 'odd' or 'even' ");
}
}
void loop() {
  // put your main code here, to run repeatedly:

}
