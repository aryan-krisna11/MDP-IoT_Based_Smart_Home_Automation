```cpp
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- WIFI ----------------
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

// ---------------- PINS ----------------
#define DHTPIN D5
#define DHTTYPE DHT11
#define IR_SENSOR D6

#define RELAY1 D3  // Motion RED
#define RELAY2 D4  // Motion GREEN
#define RELAY3 D7  // Temp RED
#define RELAY4 D0  // Temp GREEN

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- SENSOR ----------------
DHT dht(DHTPIN, DHTTYPE);

// ---------------- VARIABLES ----------------
bool personPresent = false;
float tempC = 0.0;
float humidity = 0.0;

unsigned long lastSeenTime = 0;
const unsigned long presenceTimeout = 10000;

void setup() {
    Serial.begin(115200);

    // LCD
    Wire.begin(D2, D1);
    lcd.begin(16, 2);
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Smart Room Hub");
    delay(2000);
    lcd.clear();

    // Pin configuration
    pinMode(IR_SENSOR, INPUT);
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    pinMode(RELAY3, OUTPUT);
    pinMode(RELAY4, OUTPUT);

    // Relays OFF initially (active LOW)
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);
    digitalWrite(RELAY3, HIGH);
    digitalWrite(RELAY4, HIGH);

    // Start DHT11
    dht.begin();

    // Wi-Fi
    WiFi.begin(ssid, password);

    lcd.print("Connecting WiFi");

    Serial.println("Connecting WiFi...");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected");
    Serial.println(WiFi.localIP());

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Connected");

    lcd.setCursor(0, 1);
    lcd.print(WiFi.localIP());

    delay(3000);
    lcd.clear();

    server.begin();
}

void loop() {

    // -------- IR SENSOR PRESENCE --------
    bool detected = (digitalRead(IR_SENSOR) == LOW);

    if (detected) {
        personPresent = true;
        lastSeenTime = millis();
    }

    if (millis() - lastSeenTime > presenceTimeout) {
        personPresent = false;
    }

    // -------- READ DHT --------
    tempC = dht.readTemperature();
    humidity = dht.readHumidity();

    // -------- MOTION RELAYS --------
    if (personPresent) {
        digitalWrite(RELAY2, LOW);   // Motion GREEN ON
        digitalWrite(RELAY1, HIGH);  // Motion RED OFF
    } 
    else {
        digitalWrite(RELAY2, HIGH);  // Motion GREEN OFF
        digitalWrite(RELAY1, LOW);   // Motion RED ON
    }

    // -------- TEMPERATURE RELAYS (ONLY WHEN PERSON PRESENT) --------
    if (personPresent) {

        if (tempC >= 25) {
            digitalWrite(RELAY4, LOW);   // Temp GREEN ON
            digitalWrite(RELAY3, HIGH);  // Temp RED OFF
        } 
        else {
            digitalWrite(RELAY4, HIGH);  // Temp GREEN OFF
            digitalWrite(RELAY3, LOW);   // Temp RED ON
        }
    } 
    else {
        // Nobody present -> both OFF
        digitalWrite(RELAY4, HIGH);
        digitalWrite(RELAY3, HIGH);
    }

    // -------- SERIAL OUTPUT --------
    Serial.print("Temp: ");
    Serial.print(tempC);

    Serial.print(" C | Humidity: ");
    Serial.print(humidity);

    Serial.print(" % | Person: ");
    Serial.println(personPresent ? "Present" : "Not Present");

    // -------- LCD DISPLAY --------
    lcd.setCursor(0, 0);

    lcd.print("T:");
    lcd.print(tempC);
    lcd.print("C H:");
    lcd.print(humidity);
    lcd.print("% ");

    lcd.setCursor(0, 1);

    lcd.print("Person:");
    lcd.print(personPresent ? "Yes " : "No ");

    delay(2000);
}
```
