/***************************************************************************
  This sketch puts the sensor in gesture mode and decodes gestures.
  To use this, first put your hand close to the sensor to enable gesture mode.
  Then move your hand about 6" from the sensor in the up -> down, down -> up,
  left -> right, or right -> left direction.
 ***************************************************************************/

#include "Adafruit_APDS9960.h"
 
Adafruit_APDS9960 apds;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  delay(200);
	
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
}

// the loop function runs over and over again forever
void loop() {
    //read a gesture from the device
    uint8_t gesture = apds.readGesture();
    if(gesture == APDS9960_DOWN) Serial.println("down");
    if(gesture == APDS9960_UP) Serial.println("up");
    if(gesture == APDS9960_LEFT) Serial.println("left");
    if(gesture == APDS9960_RIGHT) Serial.println("right");
}
