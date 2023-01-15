# Doorbell Notification System

This project is a doorbell notification system that uses an ESP8266 microcontroller and IFTTT to send a notification to your phone when the doorbell is pressed.

## Requirements
- ESP8266 microcontroller
- IFTTT account and applet
- A doorbell button (I used a simple push button to model the system)
- Power source (e.g. USB cable or battery)
- USB-to-Serial converter

## Wiring
- Connect the doorbell button to the ESP8266 microcontroller between GND and a digital input pin (e.g. D1).
- Connect the ESP8266 microcontroller to your computer using a USB-to-Serial converter.

## IFTTT setup
1. Create an account on IFTTT
2. Create a new applet using the Webhooks service as the trigger and the Notifications service as the action.
3. Configure the applet to trigger when a specific event is received, and choose a custom event name (e.g. "doorbell_pressed").
4. Set the notification message to be sent to your phone when the event is triggered.

## ESP8266 setup
1. Install the Arduino IDE
2. Install the ESP8266 board package in the Arduino IDE
3. Open the sketch `doorbell.ino` in the Arduino IDE
4. Update the sketch with your Wi-Fi credentials and IFTTT event name
5. Upload the sketch to the ESP8266 microcontroller

## Usage
1. Power on the ESP8266 microcontroller
2. Press the doorbell button.
3. The ESP8266 microcontroller will send an event to IFTTT, which will trigger the applet and send a notification to your phone.

## Notes
- The ESP8266 microcontroller must be connected to a Wi-Fi network to send the event to IFTTT
- You can also customize the message and the way the notification is sent when setting up the IFTT applet
