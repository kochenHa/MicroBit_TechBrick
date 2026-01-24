#include <Wire.h>

#define I2C_ADDRESS 0x05
#define SENSORPIN A3

int value;

void setup() {
  pinMode(SENSORPIN,INPUT);
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(10);
  value = analogRead(SENSORPIN);
}

void requestEvent() {
  byte writeValue = value>>2;
  Wire.write(writeValue);
}
