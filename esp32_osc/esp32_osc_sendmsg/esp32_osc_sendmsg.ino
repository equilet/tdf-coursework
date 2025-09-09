/*---------------------------------------------------------------------------------------------
 NOTE:  THERE ARE DELIBERATE ERRORS IN THIS CODE THAT YOU ARE EXPECTED TO REMEDY
--------------------------------------------------------------------------------------------- */

#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

//#include "secrets.h"

//only do this as a quick test if ever, and 
//NEVER upload your personal credentials to the web, vie github commits, etc
char ssid[] = "xxx";    // your network SSID (name)
char pass[] = "xxx";    // your network password

WiFiUDP Udp;                             // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(x,x,x,x);          // remote IP of your computer
const unsigned int outPort = 1;          // remote port to receive OSC
const unsigned int localPort = 0;        // local port to listen for OSC packets (actually not used for sending)
const int counter = 0;

void setup() {
    Serial.begin(115200);

    // Connect to WiFi network
    Serial.println();
    Serial.println();
    //it is expected that you will have these defined in your shell's environment variable
    //windows (powershell):
    //setx WIFI_SSID "MyNetwork"
    //setx WIFI_PASS "supersecret"
    //macos/linux .zprofile .bash_profile
    //WIFI_SSID="MyNetwork"
    //WIFI_PASS="supersecret"
    Serial.printf("Connecting to %s\n", ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("ESP IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(localPort);
}

void loop() {
    OSCMessage msg("/test");
    msg.add("hello, osc. ");
    msg.add(String(counter));
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();

    counter++;
    
    //delay(50);
    blink(); //blink the led instead 
}

void blink() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
}
