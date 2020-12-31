#include <Wire.h>

#define slave_address 1
char readByte;

void setup() {  
  Wire.begin();  // Master
  Serial.begin(9600);
  Serial.println("Transfer Message to Slave");
}

void loop() {
  if (Serial.available()) {
    readByte = Serial.read();
    Serial.write(readByte);
    Wire.beginTransmission(slave_address);
    Wire.write(readByte);
    Wire.endTransmission();
  }
}