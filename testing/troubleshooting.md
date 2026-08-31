# Troubleshooting

| Problem | Possible Cause | Solution |
|---|---|---|
| LCD blank | Wrong I2C address or wiring | Run I2C scanner and check D1/D2 |
| LCD shows boxes | Contrast too high | Adjust LCD contrast potentiometer |
| Temperature shows NaN | DHT11 connection problem | Check D5 wiring and sensor |
| IR always HIGH/LOW | Sensitivity/wiring issue | Adjust potentiometer and check D6 |
| Relays do not click | Wrong GPIO or insufficient power | Check GPIO and 5V supply |
| LEDs do not light | Wrong polarity/resistor | Check LED orientation and 220 Ω resistor |
| Wi-Fi does not connect | Wrong credentials/5 GHz | Check credentials and use 2.4 GHz |
| Upload fails | Driver/board selection | Check CH340 driver and NodeMCU board |
| Temperature relays OFF | Person not detected | Resolve IR sensor issue |
| Random reboots | Insufficient power | Use suitable power supply and capacitor |
