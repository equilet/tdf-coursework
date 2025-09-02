void setup() {  
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RX, TX); //rx/tx: leave it up to our board's config to define the mapping of these pins
  
  Serial.println("Boot OK.  Receiver ready.");
  delay(1000);
}

void loop() {

  if(Serial2.available()){
    //Serial.print("Received: ");
    char c = Serial2.read();
    Serial.printf("Received: %c\n", c); 
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(30);
  digitalWrite(LED_BUILTIN, LOW);
  delay(30); // keep loop alive
  
}