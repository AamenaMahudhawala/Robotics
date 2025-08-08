#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Scanning WiFi networks...");
  int numNetworks = WiFi.scanNetworks();

  if (numNetworks == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.println("Networks found:");
    for (int i = 0; i < numNetworks; i++) {
      Serial.printf("%d: %s (Signal Strength: %d dBm)\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
    }
  }
}

void loop() {
  // Nothing here
}
