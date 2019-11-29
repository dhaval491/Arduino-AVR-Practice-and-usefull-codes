

#include<Servo.h>
int a;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("give postion:");
while(Serial.available()==0){
}
a=Serial.parseInt();
myservo.write(a);
delay(1000);

}

