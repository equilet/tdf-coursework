// Program to test sending accelerometer data off a Photon in real time
// Uses an Analog Devices ADXL362 SPI accelerometer (the one in the Electron Sensor Kit)

//#include "Particle.h"
#include <ADXL362.h>
#include <SPI.h>
#include <ESP32Servo.h>
//SYSTEM_MODE(AUTOMATIC);
//SYSTEM_THREAD(ENABLED);
//SerialLogHandler logHandler(LOG_LEVEL_INFO);

// Connect the ADXL362 breakout:
// VIN: 3V3
// GND: GND
// SCL: A3 (SCK)
// SDA: A5 (MOSI)
// SDO: A4 (MISO)
// CS: A2 (SS)
// INT1: no connection
// INT1: no connection
ADXL362 accel;
Servo serv;

const int servoPin = T5;
int pos = 0;
unsigned long lastReport = 0;
const unsigned long lastReportPeriod = 100;

unsigned long temperatureReport = 0;
const unsigned long temperatureReportPeriod = 30000;
int16_t x, y, z, t;
float tc, tf;

void setup() {

  Serial.begin(9600);
  accel.begin(10);                   // Setup SPI protocol, issue device soft reset
  accel.beginMeasure();              // Switch ADXL362 to measure mode  
  serv.attach(servoPin);
  Serial.println("Starting up...");   
  
} 

void loop() {
  if (millis() - lastReport >= lastReportPeriod) {
      
    lastReport = millis();
    
    
    accel.readXYZTData(x, y, z, t);
    
    Serial.printf("x: %d, y: %d, z: %d, t: %d", x, y, z, t);
    pos = map(x, -1000, 1000, 0, 180);
  }

  if (millis() - temperatureReport >= temperatureReportPeriod) {
      temperatureReport = millis();
      tc = (t / 256.0) + 25;
      tf = (tc * 9.0/5.0) + 32.0;
      
      Serial.printf("temperature %.1f C, %.1f F", tc, tf);
      Serial.printf("last report %lu ms ago", millis() - lastReport);
      Serial.printf("current time %lu", millis()); 
  }

  //output: set the servo position
  serv.write(pos);

  Serial.printf("position: %d\n", pos);

  delay(1500);      // wait for 1.5 seconds   
  serv.write(90);   // set servo to mid-point
  delay(1500);      // wait for 1.5 seconds
    
}