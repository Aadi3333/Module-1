#include <Arduino.h>

const uint8_t pin = 2;

uint8_t led_state = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(pin), ledStatus, CHANGE);
}

void loop()
{
  delay(500);
}

void ledStatus()
{
  led_state = !led_state;
  digitalWrite(LED_BUILTIN, led_state);
  Serial.println("Interrupt is used");
}