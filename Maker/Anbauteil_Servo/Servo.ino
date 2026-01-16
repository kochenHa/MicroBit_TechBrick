#include <Servo_ATTinyCore.h>
#include <Wire.h>

#define I2C_ADDRESS 0x0B
#define SERVO_PIN 4

Servo myservo;
int servoAngle;

void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  myservo.attach(SERVO_PIN);
}

void loop() {
  delay(100);
  myservo.write(servoAngle);
}

void receiveEvent() {
    servoAngle = Wire.read();
}
