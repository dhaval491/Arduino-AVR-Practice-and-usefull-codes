#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
RF24 radio(7,8); //CE,CSN
const byte address[6]= "00001";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}

void loop() {

if(radio.available()){
  int data[2];
  radio.read(&data, sizeof(data));
  Serial.print("roll    ");Serial.print(data[0]);Serial.print("      pitch    ");Serial.println(data[1]);
}
}
