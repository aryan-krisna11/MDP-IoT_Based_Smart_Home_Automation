# Wiring Notes

## Power Distribution

- MB102 power supply is configured for 5V.
- Positive output connects to the breadboard positive rail.
- Negative output connects to the ground rail.
- 100 µF capacitor is connected across the power rails.
- NodeMCU VIN connects to the positive rail.
- NodeMCU GND connects to the ground rail.

## IR Obstacle Sensor

- VCC → 5V
- GND → GND
- OUT → NodeMCU D6 / GPIO12

## DHT11

- VCC → 5V
- GND → GND
- DATA → NodeMCU D5 / GPIO14

## LCD I2C

- VCC → 5V
- GND → GND
- SDA → NodeMCU D2 / GPIO4
- SCL → NodeMCU D1 / GPIO5
- I2C address used: 0x27

## Relay Modules

### Relay Module 1

- IN1 → D3 / GPIO0
- IN2 → D4 / GPIO2
- VCC → 5V
- GND → GND

### Relay Module 2

- IN1 → D7 / GPIO13
- IN2 → D0 / GPIO16
- VCC → 5V
- GND → GND

## LED Connections

Breadboard +5V → Relay COM → Relay NO → LED anode → 220 Ω resistor → GND
