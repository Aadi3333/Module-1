#include <Arduino.h>

const uint8_t motion = 2;
const uint8_t soil = 8;
const uint8_t ledpin = 5;
const uint8_t ledpin2 = 6;

const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

void setup()
{
  Serial.begin(9600);

  noInterrupts();

  DDRD &= (1 << motion);
  PORTD |= (1 << motion);

  DDRD &= (1 << soil);
  PORTD |= (1 << soil);

  DDRD |= (1 << ledpin);
  DDRD |= (1 << ledpin2);

  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  EIMSK |= (1 << INT0);

  PCICR |= B00000001;

  PCMSK0 |= B00000011;

  TCCR1A = 0;

  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);

  TCNT1 = t1_load;
  OCR1A = t1_comp;

  TIMSK1 |= (1 << OCIE1A);

  sei();
}

void loop()
{
  delay(500);
}

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = t1_load;
  PORTD ^= (1 << ledpin2);
}

ISR(INT0_vect)
{
  PORTD ^= (1 << ledpin);
  Serial.println("Motion Sensor interrupt is used");
}

ISR(PCINT0_vect)
{
  PORTD ^= (1 << ledpin);
  Serial.println(" Sensor interrupt is used");
}