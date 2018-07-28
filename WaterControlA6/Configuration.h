/*
 * Hardware Pins
*/
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
 * pins 0-1 Serial
 * 2-3 meter interrupts
 * 4 soft reset
 * 5-6 relays
 * 7 modem reset
 * 8,9 unused  (8 used by SIM800
 * 10,11,12 RGB
 * 13 led
 * 18-19 Serial1
 * 20 SDA
 * 21 SCL
 */
#define ANTENNA_BUG
//#define USE_BARO

// 0,1 UART
// 2,3,4 unused
const int A6_RESET_TRIGGER = 7;  // hardware reset of modem
const int ARD_RESET_TRIGGER = 4;  // connect via 2K resistor to RESET
const int IN1 = 5; // relay pins
const int IN2 = 6;
const int RED_LED_PIN = 10;
const int GREEN_LED_PIN = 11;
const int BLUE_LED_PIN = 12;
const int ONBOARD_LED = 13;
// now need to use 20/21 for I2C so move to 18/19
// couldnt use 2/3 because pins already soldered in and are too short
// needs to move modem serial from serial1 to serial2
const int METER_DRDY_1 = 2; // alarm must be an interrupt pin
const int METER_DRDY_2 = 3; // alarm must be an interrupt pin
// water meter observer calibration

// MEGA MISO 50 MOSI 51  SCK 52
// UNO MISO 12 MOSI 11  SCK 13

// Mega 2560 interrupt pins are 2,3,18,19,20,21
/*
 *   ICSP   MISO (1)  VCC
 *          SCK       MOSI
 *          RESET     GND
 */

#define DEFAULT_HOME_NUMBER "+972545919886"
#define DEFAULT_SMTP_SERVER "smtp.mail.yahoo.com"
#define DEFAULT_SENDER_ACCOUNT  "dhdh654321@yahoo.com"
#define DEFAULT_SENDER_PASSWORD "x"
#define DEFAULT_RECEIVER_ACCOUNT "mgadriver@gmail.com"
#define DEFAULT_APN "uinternet"
#define DEFAULT_PULSE_WIDTH 100
#define DEFAULT_REPORT_RATE (600L)
#define DEFAULT_LEAK_IN_SECS 1800
#define DEFAULT_TICKS_PER_LITER 265
#define DEFAULT_HTTP_SERVER "henrylineage.com" //"david-henry.dyndns.tv"
#define DEFAULT_GPRS_TIMEOUT 30
#define DEFAULT_WWW_PATH "/webdata/WC"
#define DEFAULT_REBOOT_TIME 7300

// Useful universal macros
#define SMS_LENGTH 160
#define TICKS_PER_SEC 1000
#define ONE_SECOND TICKS_PER_SEC
#define TEN_SECONDS (10*TICKS_PER_SEC)
#define TEN_MINUTES (600*TICKS_PER_SEC)

// GSM modem tcp/ip sessions
#define HTTPCID  1
#define SMTPCID  2
#define MQTTCID  3
#endif

// OLED stuff
#define Y_LINE0 10
#define Y_LINE1 21
#define Y_LINE2 31
/*
MySQL
ENUM ('ping','powerup','leak','eepromreport','tapchange','report',
# 'reset','calibrate') default 'report' ,
*/


