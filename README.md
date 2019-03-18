# WaterControlA6
## Flow Meters
Two Hall Effect water flow meters are located before and after the electrically operated water faucet. Each emits pulse as water flows
and these pulses are connected to Arduino interupt pins for counting.
## Tap Control
A pair of relays are connected in parallel to turn the faucet on or off.
## Logic
- Water flow is sampled every 10 seconds.
- The RGB led is set according to the readings.
- Every (n) minutes are report is sent via the HTTP client with current data e.g. uptime, meter readings, tap state.
- If a leak was detected the faucet is turned off.
## Visual Feeback
An RGB led gives feedback as follows:
- Green. No flow detected over the previous10 seconds
- Blue. Flow detected over the previous 10 seconds
- Red. Leak detected i.e. Water flowed continuously over a defined period of time
## Communication
### Modem
- This project is written around the GPRS A6 modem device.
- Another of my projects, A6GPRS, provides a TCP client interface and telephony interface to this device.
### SMS
- The device can act upon a variety of commands received, for example turn faucet on/off, reset all counter, reboot.
### HTTP
- The meter is an HTTP client and sents HTTP GET requested to the server.
## Parameter Storage
- All runtime parameters are saved in the Arduino EEPROM. While initialized upon flashing of the program, they can be modified
via SMS commands.
- Examples of parameters:
-- Leak time i.e. uninterrupted flow time that is interpreted as a leak, default 1800 seconds.
-- Report time i.w. how often the HTTP client sends a report, default 600 seconds.
-- HTTP client address
-- Pathname of HTTP request at the server
