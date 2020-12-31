#include <Wire.h>

#define slave_address 1
char readByte;

void setup() {  
  Wire.begin(slave_address);  //  slave device with address 1
  Wire.onReceive(getMessage); // receive Event
  Serial.begin(9600);
  Serial.println("Slave Received Message:");
}

void loop() {

}

void getMessage(int length) {
  while (Wire.available()) 
  {
    readByte = Wire.read();
    Serial.print(readByte);
  }
}