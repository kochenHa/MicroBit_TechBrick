#include <Wire.h>

#define I2C_ADDRESS 0x0C
#define OUTPUT_1_PIN 3
#define OUTPUT_2_PIN 4
#define Stop 0
#define Forwards 1
#define Backwards 2

int motorState = 0;

void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(OUTPUT_1_PIN,OUTPUT);
  pinMode(OUTPUT_2_PIN,OUTPUT);
}

void loop() {
  delay(50);
  switch(motorState) {
    case Stop:
      digitalWrite(OUTPUT_1_PIN, LOW);
      digitalWrite(OUTPUT_2_PIN, LOW);
      break;
    case Forwards:
      digitalWrite(OUTPUT_1_PIN, HIGH);
      digitalWrite(OUTPUT_2_PIN, LOW);
      break;
    case Backwards: 
      digitalWrite(OUTPUT_1_PIN, LOW);
      digitalWrite(OUTPUT_2_PIN, HIGH);
      break;
  }
}

void receiveEvent() {
  motorState = Wire.read();
}
