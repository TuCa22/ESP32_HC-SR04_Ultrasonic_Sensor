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
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);

  duration1 = pulseIn(ECHO1, HIGH, 30000);
  distance1 = duration1 * 0.034 / 2;

  delay(30);

  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);

  duration2 = pulseIn(ECHO2, HIGH, 30000);
  distance2 = duration2 * 0.0343 / 2;

  Serial.print("Left: ");
  Serial.print(distance1);
  if (distance1 > 0 && distance1 <= 20)
  {
    Serial.print(" [ OBJECT ] ");
  }
  else
  {
    Serial.print(" [ CLEAR ] ");
  }

  Serial.print("  |  ");
  Serial.print("Right: ");
  Serial.print(distance2);
  if (distance2 > 0 && distance2 <= 20)
  {
    Serial.println(" [ OBJECT ] ");
  }
  else
  {
    Serial.println(" [ CLEAR ] ");
  }
  delay(200);
}