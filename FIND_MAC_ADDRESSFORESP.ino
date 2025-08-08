#include <WiFi.h>

void setup(){
  Serial.begin(115200);
  
  // Variable to store the MAC address
  uint8_t baseMac[6];
  
  // Get MAC address of the WiFi station interface
  esp_read_mac(baseMac, ESP_MAC_WIFI_STA);
  Serial.print("Station MAC: ");
  for (int i = 0; i < 5; i++) {
    Serial.printf("%02X:", baseMac[i]);
  }
  Serial.printf("%02X\n", baseMac[5]);
  
  // Get the MAC address of the Wi-Fi AP interface
  esp_read_mac(baseMac, ESP_MAC_WIFI_SOFTAP);
  Serial.print("SoftAP MAC: ");
  for (int i = 0; i < 5; i++) {
    Serial.printf("%02X:", baseMac[i]);
  }
  Serial.printf("%02X\n", baseMac[5]);
  
  // Get the MAC address of the Bluetooth interface
  esp_read_mac(baseMac, ESP_MAC_BT);
  Serial.print("Bluetooth MAC: ");
  for (int i = 0; i < 5; i++) {
    Serial.printf("%02X:", baseMac[i]);
  }
  Serial.printf("%02X\n", baseMac[5]);

  // Get the MAC address of the Ethernet interface
  esp_read_mac(baseMac, ESP_MAC_ETH);
  Serial.print("Ethernet MAC: ");
  for (int i = 0; i < 5; i++) {
    Serial.printf("%02X:", baseMac[i]);
  }
  Serial.printf("%02X\n", baseMac[5]);
}
 
void loop(){
}
/*

  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/get-change-esp32-esp8266-mac-address-arduino/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.  
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

#ifdef ESP32
  #include <WiFi.h>
  #include <esp_wifi.h>
#else
  #include <ESP8266WiFi.h>
#endif

void setup(){
  Serial.begin(115200);

  Serial.print("ESP Board MAC Address: ");
  #ifdef ESP32
    WiFi.mode(WIFI_STA);
    WiFi.STA.begin();
    uint8_t baseMac[6];
    esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
    if (ret == ESP_OK) {
      Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                    baseMac[0], baseMac[1], baseMac[2],
                    baseMac[3], baseMac[4], baseMac[5]);
    } else {
      Serial.println("Failed to read MAC address");
    }
  #else
    Serial.println(WiFi.macAddress());
  #endif
}
 
void loop(){

}*/ 
