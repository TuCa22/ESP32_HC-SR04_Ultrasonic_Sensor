#include <Arduino.h>

#define TRIG1 32
#define ECHO1 33

long duration1;
float distance1;

void setup()
{
  Serial.begin(115200);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
}

void loop()
{
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);

  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print(">Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");
  delay(500);
}
