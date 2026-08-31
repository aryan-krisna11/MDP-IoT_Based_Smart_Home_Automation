# Future Work

## 1. Web-Based Remote Monitoring

Implement HTTP endpoints such as:
- `/`
- `/data`

The `/data` endpoint can provide JSON data for remote monitoring.

## 2. Cloud Integration

Potential platforms:
- ThingSpeak
- Blynk

Possible functionality:
- Historical data logging
- Temperature trends
- Humidity trends
- Room usage analysis

## 3. Enhanced Sensing

Potential additions:
- LDR for light-based automation
- MQ-2 for gas/smoke monitoring
- HC-SR04 for extended detection range

## 4. Multi-Room Expansion

Use multiple NodeMCU devices with MQTT communication and a central Raspberry Pi/Node-RED dashboard.

## 5. RTC-Based Scheduling

Add a DS3231 RTC module for:
- Time-aware automation
- Sleep-hour control
- Different temperature thresholds by time

## 6. PCB Miniaturization

Move the breadboard prototype to a custom PCB using:
- KiCad
- EasyEDA
