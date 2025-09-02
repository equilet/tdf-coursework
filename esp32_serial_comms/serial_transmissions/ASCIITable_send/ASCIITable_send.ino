int thisByte = 33;
int oldByte = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);  //make sure that you have selected the correct baud rate in your serial monitor first!!
  Serial2.begin(9600, SERIAL_8N1, RX, TX);  //rx/tx: leave it up to our board's config to define the mapping of these pins
  //Serial.println("Sender ready");
}


void loop() {  
  //Serial.write(thisByte); //send the raw byte
  thisByte = (thisByte == '~') ? 33 : thisByte + 1; //reset to 33 each time we reach the end

  if(oldByte != thisByte){
    char ascii = (char)thisByte;
    Serial2.print(ascii);  //.print() expects a char
    Serial.println(ascii); //post to monitor
    //Serial.print('A'); //print a specific character
    oldByte = thisByte;
  }
  

  digitalWrite(LED_BUILTIN, HIGH);
  delay(40);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);  // total 50ms
}
