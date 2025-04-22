# PC-auto-boot-with-ESP32-ultrasonic-sensor

This project uses an ESP32 and an ultrasonic distance sensor to **automatically turn on a PC** when someone sits down at the desk — no buttons, no voice commands, just presence detection.

---

## How It Works

- The **HC-SR04 ultrasonic sensor** detects when someone is close to the desk
- The ESP32 connects to Wi-Fi and sends a **Wake-on-LAN (WOL)** "magic packet" to the PC's MAC address
- If the PC is off (but WOL-enabled), it boots up automatically

  ## Hardware Used

- ESP32 Dev Board
- HC-SR04 Ultrasonic Distance Sensor
- USB cable for power
- Your PC (with WOL enabled in BIOS and OS settings)

  ## Setup Steps

1. **Enable Wake-on-LAN on your PC**
   - BIOS: Enable `Wake on LAN from S5`
   - Device Manager: Enable "Allow this device to wake the computer" in your network adapter's Power Management tab

2. **Update the ESP32 sketch**
   - Enter your Wi-Fi `SSID`, `password`, and PC's **MAC address**

3. **Upload the code via Arduino IDE**
   - Make sure to install `ESP32` board support and `WakeOnLan` library

4. **Power the ESP32**
   - Can be powered via USB wall plug, PC port, or power bank
  
## Why?

Because pressing a button is too mainstream.  
This is a fun automation project that also makes for a solid intro to **ESP32**, **sensors**, and **networking hacks** like WOL.
