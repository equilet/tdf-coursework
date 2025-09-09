//#include "Particle.h"
#include "SparkFun_APDS9960.h"

SparkFun_APDS9960 apds;

void setup() {

  Serial.begin(9600);   

  if(!apds.init()){
    Serial.println("failed to initialize APDS  device!");
  }
  else{
    Serial.println("APDS device initialized!");
  }
  Serial.println("---------------------------");
  
  if ( apds.enableProximitySensor(false) ) {
      Serial.println(F("Proximity sensor is now running"));
  } else {
      Serial.println(F("Something went wrong during proximity sensor init!"));
  }
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
      Serial.println("Something went wrong trying to set PGAIN");
  }
  Serial.println("---------------------------");

  delay(700); //  Wait for initialization and calibration to finish

}

void loop() {
  // read the proximity value
  uint8_t prox = 0;
  if(!apds.readProximity(prox)){
    Serial.println("Error reading proximity value");
  }else{
     Serial.printf("proximity: %d\n", (int)prox);
  }

  delay(100);  //we can read the proximity value faster than the other sensors

}
