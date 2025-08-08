#include "BluetoothSerial.h"  // Include Bluetooth Serial library

BluetoothSerial SerialBT;     // Create Bluetooth Serial object

void setup() {
  Serial.begin(115200);        // Initialize Serial Monitor
  SerialBT.begin("ESP32_Robot");  // Bluetooth device name
  Serial.println("Bluetooth Started. Waiting for connection...");
}

void loop() {
  // Generate random values for x, y, theta
  float x = random(-100, 100) / 10.0;
  float y = random(-100, 100) / 10.0;
  float theta = random(0, 360);

  // Send values as comma-separated string
  String data = String(x) + "," + String(y) + "," + String(theta);
  SerialBT.println(data);  // Send via Bluetooth
  Serial.println(data);    // Display on Serial Monitor

  delay(1000);  // Send data every 1 second
}
