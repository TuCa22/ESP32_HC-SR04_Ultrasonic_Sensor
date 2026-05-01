#include <Arduino.h>

#define TRIG1 32
#define ECHO1 33
#define TRIG2 18
#define ECHO2 19

long duration1;
float distance1;
long duration2;
float distance2;

void setup()
{
  Serial.begin(115200);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
}

void loop()
{
  // digitalWrite(TRIG1, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIG1, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIG1, LOW);

  // duration1 = pulseIn(ECHO1, HIGH);
  // distance1 = duration1 * 0.034 / 2;
  // Serial.print(">Distance: ");
  // Serial.print(distance1);
  // Serial.println(" cm");
  // delay(500);

  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);

  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print(">Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");
  delay(500);
}
