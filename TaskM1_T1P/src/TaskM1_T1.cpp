#include <Arduino.h>

const uint8_t PIR_PIN = 4;

void setup()
{
  Serial.begin(9600);
   pinMode(PIR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop()
{
  bool input = digitalRead(PIR_PIN);

  if (input)
  {
    Serial.println("Motion Detected by the sensor");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    Serial.println("Motion Not Detected by the sensor");
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(1000);
}