#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    delay(100); 

    // Initialize Wi-Fi (e.g., set mode or connect)
    WiFi.mode(WIFI_STA); // Set to station mode for example
    // Or, if connecting to an access point:
    // WiFi.begin("your_SSID", "your_password"); 
    // while (WiFi.status() != WL_CONNECTED) {
    //   delay(1000);
    //   Serial.println("Connecting to WiFi...");
    // }
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
}

void loop() {
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
    delay(500);
}