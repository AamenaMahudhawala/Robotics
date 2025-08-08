
#include "Wire.h"
#include "Adafruit_TCS34725.h"
#include "BluetoothSerial.h"

//Define ESP32 I2C Pins 
#define SDA_PIN 21
#define SCL_PIN 22

BluetoothSerial SerialBT;  // Create Bluetooth Serial object

/* Initialize with specific integration time and gain */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud
  SerialBT.begin("ESP32_BT");  // Start Bluetooth Serial with the name "ESP32_BT"
  Wire.begin(SDA_PIN, SCL_PIN);  // Initialize I2C with custom pins
  while(true){
  if (tcs.begin()) {
    Serial.println("Found TCS34725 sensor");
    break;
  } else {
    Serial.println("No TCS34725 found ... check connections!");

  }
  }
}

void loop() {
  uint16_t r, g, b, c;

  // Read raw color data
  tcs.getRawData(&r, &g, &b, &c);

  // Send raw RGB values over Bluetooth

    // Format the data as tab-separated (good for Serial Plotter or external tools)
    Serial.print(r); Serial.print("\t");
    Serial.print(g); Serial.print("\t");
    Serial.print(b); Serial.print("\t");
    Serial.println(c);  // Newline after the last value (C)

    delay(614);  // Wait for the integration time to complete (614ms)

 // Try again after a short delay
  
}
