# GPIO Pin Mapping

| Function | NodeMCU Pin | GPIO | Component | Notes |
|---|---|---:|---|---|
| LCD SCL | D1 | GPIO5 | LCD I2C | I2C clock |
| LCD SDA | D2 | GPIO4 | LCD I2C | I2C data |
| Motion RED | D3 | GPIO0 | Relay 1 CH1 | Motion absent |
| Motion GREEN | D4 | GPIO2 | Relay 1 CH2 | Motion present |
| DHT11 Data | D5 | GPIO14 | DHT11 | Temperature/humidity |
| IR Sensor OUT | D6 | GPIO12 | IR Sensor | LOW = person detected |
| Temperature RED | D7 | GPIO13 | Relay 2 CH1 | Cold temperature |
| Temperature GREEN | D0 | GPIO16 | Relay 2 CH2 | Comfortable temperature |
| Power Input | VIN | — | MB102 | +5V |
| Ground | GND | — | All modules | Common ground |
