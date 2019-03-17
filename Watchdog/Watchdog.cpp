#include <Arduino.h>

#include <avr/io.h>
#include <avr/wdt.h>
void setup()
{
  Serial.begin(9600);
  Serial.println("Setup\r\n");
  wdt_enable(WDTO_8S);
  wdt_reset();
//  Serial.println(MCUSR);
 // Serial.println(WDTCSR);
  Serial.flush();
  wdt_reset();
}

void loop()
{
  int serialByte = Serial.read();

  if(serialByte=='A')
  {
    Serial.println("Reset WDT");
    wdt_reset();
  }
  else if(serialByte=='Z')
  {
    wdt_enable(WDTO_15MS);
  }
}
