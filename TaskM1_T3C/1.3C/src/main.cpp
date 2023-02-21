#include <Arduino.h>

const uint8_t motion = 2;
const uint8_t soil = 3;

uint8_t led_state = LOW;
uint8_t soil_led_state = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(motion, INPUT);
  pinMode(soil, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(motion), ledStatus, CHANGE);
  attachInterrupt(digitalPinToInterrupt(soil), soilledStatus, RISING);
}

void loop()
{
  delay(500);
}

void ledStatus()
{
  led_state = !led_state;
  digitalWrite(LED_BUILTIN, led_state);
  Serial.println("Motion Sensor interrupt is used");
}

void soilledStatus()
{
  soil_led_state = !soil_led_state;
  digitalWrite(LED_BUILTIN, soil_led_state);
  Serial.println("Soil Moisture Sensor interrupt is used");
}