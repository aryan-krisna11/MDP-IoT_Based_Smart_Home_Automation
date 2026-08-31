# 🏠 IoT-Based Smart Room Hub

An IoT-based smart room automation system using **ESP8266 NodeMCU** for continuous presence detection, environmental monitoring, relay-based control, and local status visualization.

![Smart Room Hub](assets/images/final-system.jpg)

## 📌 Overview

The **IoT-Based Smart Room Hub** is a low-cost embedded automation prototype designed to improve upon conventional motion-based room automation systems.

The system uses an **IR obstacle sensor** for continuous presence detection, a **DHT11 sensor** for temperature and humidity monitoring, a **16×2 I2C LCD** for local status display, and two dual-channel relay modules controlling four LED indicators.

The ESP8266 NodeMCU acts as the central controller and provides built-in Wi-Fi connectivity for future remote monitoring and cloud integration.

## ✨ Features

* 🔍 Continuous presence detection using an IR obstacle sensor
* ⏱️ Configurable 10-second presence timeout
* 🌡️ Real-time temperature monitoring
* 💧 Real-time humidity monitoring
* 💡 Four LED status indicators
* 🔌 Relay-based output control
* 📟 16×2 I2C LCD status display
* 📶 ESP8266 Wi-Fi connectivity
* ⚡ Occupancy-conditional temperature control
* 🛡️ Active-LOW relay control with safe initial OFF state
* 🔧 Expandable architecture for cloud and multi-room integration

## 🧠 How It Works

The system follows the data flow:

**Sensors → ESP8266 → Decision Logic → Relays / LCD / Serial Monitor**

### Presence Detection

The IR obstacle sensor is continuously monitored.

When a person is detected:

* Motion GREEN LED → ON
* Motion RED LED → OFF
* `personPresent` → `true`

When no detection occurs for the configured timeout:

* Motion GREEN LED → OFF
* Motion RED LED → ON
* `personPresent` → `false`

The default presence timeout is **10 seconds**.

### Temperature Control

Temperature control is dependent on room occupancy.

When a person is present:

| Temperature | Temperature Indicator |
| ----------- | --------------------- |
| `< 25°C`    | RED                   |
| `≥ 25°C`    | GREEN                 |

When nobody is present, both temperature indicators remain OFF.

This hierarchical control prevents unnecessary temperature-related relay activation in an unoccupied room.

## 🏗️ System Architecture

![System Architecture](assets/diagrams/system-architecture.png)

### Main Subsystems

1. **Presence Detection**

   * IR obstacle sensor
   * ESP8266 GPIO input

2. **Environmental Monitoring**

   * DHT11 temperature and humidity sensor

3. **Actuation**

   * Two 2-channel relay modules
   * Four LED indicators

4. **Display**

   * 16×2 LCD
   * I2C communication

5. **Communication**

   * ESP8266 Wi-Fi
   * ESP8266WebServer framework

## 🔌 Hardware Components

| Component                 | Quantity | Purpose                |
| ------------------------- | -------: | ---------------------- |
| ESP8266 NodeMCU           |        1 | Main controller        |
| MB102 Breadboard PSU      |        1 | Power supply           |
| 100 µF Capacitor          |        1 | Power stabilization    |
| 2-Channel 5V Relay Module |        2 | LED control            |
| IR Obstacle Sensor        |        1 | Presence detection     |
| DHT11 Sensor              |        1 | Temperature & humidity |
| 16×2 LCD + I2C Module     |        1 | Status display         |
| Red LED                   |        2 | Alert indicators       |
| Green LED                 |        2 | Normal indicators      |
| 220 Ω Resistor            |        4 | LED current limiting   |
| Breadboard                |        1 | Circuit assembly       |
| Jumper Wires              |    25–30 | Wiring                 |

## 📍 GPIO Pin Mapping

| Function          | NodeMCU |   GPIO | Component   |
| ----------------- | ------- | -----: | ----------- |
| LCD SCL           | D1      |  GPIO5 | I2C LCD     |
| LCD SDA           | D2      |  GPIO4 | I2C LCD     |
| Motion RED        | D3      |  GPIO0 | Relay 1 CH1 |
| Motion GREEN      | D4      |  GPIO2 | Relay 1 CH2 |
| DHT11 Data        | D5      | GPIO14 | DHT11       |
| IR Sensor OUT     | D6      | GPIO12 | IR Sensor   |
| Temperature RED   | D7      | GPIO13 | Relay 2 CH1 |
| Temperature GREEN | D0      | GPIO16 | Relay 2 CH2 |

## 💻 Software Requirements

* Arduino IDE
* ESP8266 Board Package
* ESP8266WiFi
* ESP8266WebServer
* DHT Sensor Library
* LiquidCrystal_I2C
* Wire

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/iot-smart-room-hub.git
cd iot-smart-room-hub
```

### 2. Open the firmware

Open:

```text
firmware/smart_room_hub/smart_room_hub.ino
```

using Arduino IDE.

### 3. Install the ESP8266 board package

In Arduino IDE:

```text
File → Preferences
```

Add the ESP8266 Board Manager URL and then install the ESP8266 board package through:

```text
Tools → Board → Boards Manager
```

### 4. Install required libraries

Install:

* DHT sensor library by Adafruit
* LiquidCrystal_I2C
* ESP8266WiFi
* ESP8266WebServer
* Wire

### 5. Configure Wi-Fi

Replace the placeholder credentials in the firmware with your own Wi-Fi credentials.

**Do not commit real Wi-Fi passwords or other credentials to GitHub.**

### 6. Select the board

Select:

```text
NodeMCU 1.0 (ESP-12E Module)
```

Then select the appropriate COM port.

### 7. Upload

Connect the NodeMCU through USB and upload the firmware.

Open Serial Monitor at:

```text
115200 baud
```

to verify initialization and Wi-Fi connection.

## 📟 LCD Output

The LCD displays environmental and occupancy information.

Example:

```text
T:23.5C H:65%
Person:Yes
```

## 🧪 Testing

The system was functionally tested across its major subsystems.

### Presence Detection

* 10 consecutive detection/removal cycles were tested.
* All 10 trials correctly switched between detected and absent states.
* The 10-second timeout transitioned the system approximately 10–12 seconds after removal.

### Environmental Monitoring

* DHT11 temperature readings showed approximately +1.5°C offset relative to a reference instrument.
* Humidity readings remained within approximately ±4% of the reference.
* No NaN readings occurred during a one-hour continuous test.

### Relay and LED Control

The motion indicators correctly changed according to presence.

Temperature indicators were activated only when occupancy was detected.

### System Stability

The system operated continuously for approximately **two hours** without spontaneous reboot, LCD corruption, invalid sensor readings, or relay-state errors.

## 📊 Results

The prototype successfully demonstrated:

* Continuous presence detection
* Occupancy-based control
* Temperature and humidity monitoring
* Relay-controlled LED indication
* LCD status visualization
* Wi-Fi connectivity
* Stable continuous operation

## 🔧 Troubleshooting

### LCD is blank

* Check D1/D2 wiring
* Verify the I2C address
* Run an I2C scanner
* Adjust the LCD contrast potentiometer

### DHT11 displays NaN

* Check D5 wiring
* Verify sensor power
* Check the DHT11 module connection

### IR sensor does not detect presence

* Adjust the sensor sensitivity potentiometer
* Check D6 wiring
* Verify the sensor power supply

### Relays do not activate

* Check GPIO assignments
* Verify the 5V supply
* Check relay wiring

### Wi-Fi does not connect

* Verify SSID and password
* Ensure the network provides 2.4 GHz connectivity

## 🔮 Future Work

Planned improvements include:

* Web-based real-time monitoring dashboard
* HTTP endpoints returning JSON
* ThingSpeak/Blynk cloud integration
* Historical environmental data logging
* LDR-based lighting automation
* MQ-2 gas/smoke monitoring
* HC-SR04 enhanced presence detection
* Multi-room MQTT architecture
* Raspberry Pi + Node-RED dashboard
* RTC-based scheduling
* Custom PCB implementation

## 🌱 Sustainable Development

The project contributes to:

* **SDG 7 – Affordable and Clean Energy**
* **SDG 9 – Industry, Innovation and Infrastructure**
* **SDG 11 – Sustainable Cities and Communities**

The occupancy-conditional control strategy is intended to reduce unnecessary operation in unoccupied spaces.

## 👥 Team

* **Aryan Krisna**
* **Ohm Shrivastava**
* **Joshua Lawrence**
* **Haripirthwin VS**
* **Nishanth Kumar S**

## 🎓 Institution

**Vellore Institute of Technology, Chennai**

School of Computer Science and Engineering (SCOPE)

B.Tech Computer Science and Engineering with Artificial Intelligence and Machine Learning

## 📄 Project Report

The complete project report is available in:

```text
docs/project-report.pdf
```

## 📚 References

The project report contains the complete reference list and literature review used for the project.

---

⭐ If you find this project useful, consider giving the repository a star.
