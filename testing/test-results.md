# Test Results

## 1. Presence Detection

The IR obstacle sensor was tested through ten consecutive insertion and removal cycles.

Result:
- 10/10 detection cycles were successful.
- LOW indicated presence.
- HIGH indicated absence.

## 2. Presence Timeout

The configured timeout was 10 seconds.

Observed transition after object removal:
- Approximately 10–12 seconds.

## 3. Temperature and Humidity

DHT11 readings were compared with reference instruments.

Temperature:
- Approximately +1.5°C offset.
- Within the specified ±2°C tolerance.

Humidity:
- Within approximately ±4% of the reference.

## 4. Sensor Stability

No NaN readings occurred during a one-hour continuous test.

## 5. Relay and LED Testing

### Person absent
- Motion RED: ON
- Motion GREEN: OFF
- Temperature RED/GREEN: OFF

### Person present
- Motion GREEN: ON
- Motion RED: OFF

### Person present and temperature <25°C
- Temperature RED: ON
- Temperature GREEN: OFF

### Person present and temperature ≥25°C
- Temperature GREEN: ON
- Temperature RED: OFF

## 6. LCD

The LCD successfully displayed:
- Startup message
- Wi-Fi IP address
- Temperature
- Humidity
- Presence status

Updates occurred every two seconds.

## 7. Wi-Fi

The NodeMCU connected to the 2.4 GHz Wi-Fi network in approximately 3–5 seconds.

## 8. Long-Term Stability

The system operated continuously for approximately two hours without:
- Spontaneous reboot
- NaN sensor readings
- LCD corruption
- Incorrect relay states
