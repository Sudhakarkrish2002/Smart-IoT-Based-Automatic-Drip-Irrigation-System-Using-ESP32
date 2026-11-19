# Automatic Drip Irrigation Controller Using ESP32 and Soil Moisture Sensor

## Project Overview

An IoT-based automatic irrigation system using ESP32 and a capacitive soil moisture sensor to monitor soil conditions and automatically control water supply through a drip irrigation system.

The system detects soil moisture levels and switches the water pump ON or OFF based on predefined moisture thresholds. Sensor readings and pump status are transmitted to the KiwisIoT dashboard for remote monitoring.

## Hardware Components

| S.No | Component Name | Quantity |
|---|---|---|
| 1 | ESP32 Development Board (38-pin) | 1 |
| 2 | Capacitive Soil Moisture Sensor | 1 |
| 3 | 1-Channel Relay Module (5V) | 1 |
| 4 | DC Water Pump (12V) | 1 |
| 5 | 12V DC Power Supply | 1 |
| 6 | Drip Irrigation Pipe and Connectors | 1 Set |
| 7 | Water Storage Tank | 1 |
| 8 | Jumper Wires | As Required |
| 9 | Breadboard or PCB | 1 |
| 10 | USB Cable | 1 |

## Pin Connections

### Soil Moisture Sensor to ESP32

| Sensor Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AOUT | GPIO 34 |

### Relay Module to ESP32

| Relay Pin | ESP32 Pin |
|---|---|
| VCC | Suitable 5V Supply |
| GND | Common GND |
| IN | GPIO 26 |

### Water Pump Connections

- 12V Power Supply Positive → Relay COM
- Relay NO → Water Pump Positive
- Water Pump Negative → 12V Power Supply Negative

**Note:** Verify relay compatibility with ESP32 3.3V logic and ensure the relay is rated for the pump's starting and operating current.

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- KiwisIoT Arduino Library
- KiwisIoT Platform

Platform Link: https://kiwisiot.in

## Installation and Setup

### Step 1: Install Arduino IDE

Download and install Arduino IDE on your computer.

### Step 2: Install ESP32 Board Package

Open Arduino IDE and install the ESP32 board package using Boards Manager.

Select:

Tools → Board → ESP32 Arduino → ESP32 Dev Module

### Step 3: Install Required Library

Install the KiwisIoT Arduino library compatible with ESP32.

### Step 4: Configure Wi-Fi

Update your Wi-Fi credentials in the Arduino program.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_DEVICE_TOPIC";
```

Replace the example values with your actual Wi-Fi and KiwisIoT device details.

### Step 5: Configure Soil Moisture Calibration

The program uses the following example calibration values:

```cpp
const int DRY_VALUE = 3000;
const int WET_VALUE = 1200;
```

Calibrate the sensor using actual dry and wet soil readings before operating the system.

### Step 6: Upload the Program

1. Connect the ESP32 to your computer using a USB cable.
2. Select ESP32 Dev Module.
3. Select the correct serial port.
4. Upload the Arduino program.
5. Open Serial Monitor at 115200 baud.

## Working Principle

1. The capacitive soil moisture sensor measures the moisture level in the soil.
2. The ESP32 reads the analog sensor values through GPIO 34.
3. The program converts the raw readings into an approximate moisture percentage.
4. When soil moisture falls below 30%, the ESP32 activates the relay.
5. The relay switches ON the 12V DC water pump.
6. Water is supplied to plants through drip irrigation pipes.
7. When soil moisture reaches 60% or above, the pump switches OFF.
8. Soil moisture readings and pump status are transmitted to KiwisIoT.

## Automatic Pump Control

| Soil Moisture Level | Pump Status |
|---|---|
| Below 30% | ON |
| 30
