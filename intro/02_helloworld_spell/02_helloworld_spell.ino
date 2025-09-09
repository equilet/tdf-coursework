//make hello world message
//https://docs.arduino.cc/learn/programming/memory-guide/ 
char hello[] = "Hello World!";
//get the size of the message; note the null terminator '\0'
//note also that we account for this by subtracting 1 from the size
int size_hello = sizeof(hello) - 1;
int count = 0;

// setup() runs once, when the device is first turned on
void setup() {
  //note that you may not see this, as it happens very quickly 
  //...typically before you are able to connect to the serial port
  Serial.begin(9600);
  delay(200);
  Serial.println("-------------Welcome to the Hello World example!-------------");
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  // if we have reached the end of the message, reset the count
  if (count == size_hello) {
    count = 0;
  } 
  
  //log the current character
  Serial.printf("current character: %c\n", hello[count]);
  count++;

  // incur a delay of 3 seconds
  delay(300);
}
