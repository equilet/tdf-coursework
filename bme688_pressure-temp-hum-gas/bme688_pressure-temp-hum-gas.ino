/* 
 * Project BME688_proj
 * Author: Jeffrey Lubow
 * Date:  
 */

#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C

double temperatureInC = 0;
double relativeHumidity = 0;
double pressureHpa = 0;
double gasResistanceKOhms = 0;
double approxAltitudeInM = 0;

void setup() {
  if (!bme.begin()) {
    //Particle.publish("Log", "Could not find a valid BME680 sensor, check wiring!");
  } else {
    Serial.begin(19200);
    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms
  }
}

void loop() {
  if (! bme.performReading()) {

    Serial.println("Failed to perform reading.  :(\n");

  } else {
    
    temperatureInC = bme.temperature;
    relativeHumidity = bme.humidity;
    pressureHpa = bme.pressure / 100.0;
    gasResistanceKOhms = bme.gas_resistance / 1000.0;
    approxAltitudeInM = bme.readAltitude(SEALEVELPRESSURE_HPA);

    Serial.printf(
      "Temperature: %.2f C, Humidity: %.2f %%, Pressure: %.2f hPa, Gas Resistance: %.2f kOhms, Altitude: %.2f m\n", 
      temperatureInC, relativeHumidity, pressureHpa, gasResistanceKOhms, approxAltitudeInM
    );
  }
  delay(2000);
}
