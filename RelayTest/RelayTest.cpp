#include <Arduino.h>

// 5V relay pins
#define IN1 5
#define IN2 6
#define LED 13
#define PULSE_WIDTH 80
//#define BUTTON 20

int state = 0;
void RelaySet(int in1, int in2)
{
  // sets power on to other side of relay
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
}
void Action(int s)
{
  Serial.println(s);
  switch (s)
  {
    case 0:
      RelaySet(HIGH,HIGH);
      break;
    case 1:
      RelaySet(HIGH,LOW);
      break;
    case 2:
      RelaySet(LOW,LOW);
      break;
    case 3:
      RelaySet(LOW,HIGH);
      break;
  }
}
#ifdef BUTTON
void TapOnOff()
{
if (digitalRead(BUTTON) ==LOW)
  state++;
  state %= 4;
  Action(state);
}
#endif
void TapOpen()
{
  RelaySet(HIGH,HIGH);
  delay(PULSE_WIDTH);
  RelaySet(HIGH,LOW);
}
void TapClose()
{
  RelaySet(LOW,LOW);
  delay(PULSE_WIDTH);
  RelaySet(LOW,HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
// initialize relay pins and turn power off to output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  RelaySet(LOW,HIGH);
#ifdef BUTTON
  // well use a button to turn on/off
  pinMode(BUTTON,INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON),TapOnOff, CHANGE);
#endif
}
int count;
void loop() {
#if 0
  TapOpen();
  delay(3000);
  TapClose();
  delay(3000);
#else
  Action(count++);
  delay(2000);
  count %= 4;
#endif
}
