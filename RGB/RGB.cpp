#include <Arduino.h>

void setColor(int red, int green, int blue);

/*
Adafruit Arduino - Lesson 3. RGB LED
*/
#define redPin  10
#define greenPin 11
#define bluePin 12
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}
void loop()
{

  setColor(255, 0, 0); // red
  delay(1000);
  setColor(0, 255, 0); // green
  delay(1000);
  setColor(0, 0, 255); // blue
  delay(1000);
#if 0
  setColor(255, 255, 0); // yellow
  delay(1000);
  setColor(80, 0, 80); // purple
  delay(1000);
  setColor(0, 255, 255); // aqua
  delay(1000);
#endif
}
void setColor(int red, int green, int blue)
{
#if 0
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
#else
#endif
  digitalWrite(redPin,red > 0 ? HIGH : LOW);
  digitalWrite(greenPin,green> 0 ? HIGH : LOW);
  digitalWrite(bluePin,blue> 0 ? HIGH : LOW);
}
