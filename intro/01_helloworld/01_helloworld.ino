char hello[] = "Hello World!";
//get the size of the message; note the null terminator '\0'
//note also that we account for this by subtracting 1 from the size
int size_hello = sizeof(hello) - 1;

// setup() runs once, when the device is first turned on
void setup() {
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // log the message
  Serial.println(hello);

  Serial.printf("the number of characters in that msg was %d\n", size_hello);
  // incur a delay of 3 seconds
  delay(3000);
}
