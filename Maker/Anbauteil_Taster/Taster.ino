#include <Wire.h>

#define I2C_ADRESS 0x07
#define TASTER_PIN 4

volatile uint8_t buttonState = 0;

void setup() {
  Wire.begin(I2C_ADRESS);
  Wire.onRequest(requestEvent);
  pinMode(TASTER_PIN,INPUT_PULLUP);
}

void loop() {
  delay(10);
  buttonState = digitalRead(TASTER_PIN) == LOW ? 1 : 0;
}
void requestEvent() {
  Wire.write(buttonState);
}