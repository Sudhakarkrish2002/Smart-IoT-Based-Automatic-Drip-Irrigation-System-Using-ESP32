
#include <WiFi.h>
#include <KiwisIoT.h>

// Wi-Fi Configuration
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Configuration
const char* topic = "YOUR_DEVICE_TOPIC";

KiwisIoT kiwisiot(ssid, pass, topic);

// Pin Configuration
#define SOIL_PIN 34
#define RELAY_PIN 26

// Soil Moisture Calibration
// Replace these values with your actual sensor readings
#define DRY_VALUE 3000
#define WET_VALUE 1200

// Moisture Thresholds
#define PUMP_ON_THRESHOLD 30
#define PUMP_OFF_THRESHOLD 60

// Relay configuration (LOW-level trigger)
#define RELAY_ON LOW
#define RELAY_OFF HIGH

bool pumpStatus = false;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  analogReadResolution(12);

  kiwisiot.begin();

  Serial.println("Automatic Drip Irrigation Started");
}

void loop() {
  kiwisiot.run();

  // Read soil moisture sensor
  int soilValue = analogRead(SOIL_PIN);

  // Convert sensor reading into percentage
  int moisture = map(
    soilValue,
    DRY_VALUE,
    WET_VALUE,
    0,
    100
  );

  moisture = constrain(moisture, 0, 100);

  // Automatic pump control with two thresholds
  if (moisture < PUMP_ON_THRESHOLD) {
    pumpStatus = true;
  }
  else if (moisture >= PUMP_OFF_THRESHOLD) {
    pumpStatus = false;
  }

  // Control relay
  digitalWrite(
    RELAY_PIN,
    pumpStatus ? RELAY_ON : RELAY_OFF
  );

  // Send data to KiwisIoT
  kiwisiot.send("1", moisture);
  kiwisiot.send("2", pumpStatus ? 1 : 0);

  // Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  Serial.print("Pump Status: ");
  Serial.println(pumpStatus ? "ON" : "OFF");

  Serial.println("----------------------");

  delay(2000);
}
