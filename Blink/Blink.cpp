#include <Arduino.h>

#define ONBOARD_LED 13
void setup() {
	pinMode(ONBOARD_LED,OUTPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.println("High");
	digitalWrite(ONBOARD_LED,HIGH);
	delay(1000);
	Serial.println("Low");
	digitalWrite(ONBOARD_LED,LOW);
	delay(1000);
}
