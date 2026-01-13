#include <Wire.h>

#define ECHO_PIN 4
#define TRIGGER_PIN 3
#define I2C_ADDRESS 0x08

const int maximumRange = 200;
const int minimumRange = 2;
uint8_t ui8Abstand;
long abstand;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT); 
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(50);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  abstand = duration/58.2;
  if (abstand >= maximumRange || abstand <= minimumRange) {
    ui8Abstand = 0;
  }
  else {
    ui8Abstand = abstand;
  }
}

void requestEvent() {
  Wire.write(ui8Abstand);
}
