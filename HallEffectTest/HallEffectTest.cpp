#include <Arduino.h>


#define ONBOARD_LED  13
#define METER_DRDY_1 2 // alarm must be an interrupt pin
#define METER_DRDY_2 3 // alarm must be an interrupt pin

unsigned long totalMeterCount[2] = { 0, 0 };

void MeterCount1() {
	totalMeterCount[0]++;
}

void MeterCount2() {
	totalMeterCount[1]++;
}
void setup() {
	// response for water meter pulses
	attachInterrupt(digitalPinToInterrupt(METER_DRDY_1), MeterCount1, RISING);
	attachInterrupt(digitalPinToInterrupt(METER_DRDY_2), MeterCount2, RISING);
	Serial.begin(115200);
	pinMode(METER_DRDY_1,OUTPUT);
	pinMode(METER_DRDY_2,OUTPUT);
}

void loop() {
	delay(10000);
	Serial.println("Meter 1: " + totalMeterCount[0]);
	Serial.println("Meter 2: " + totalMeterCount[1]);
}
