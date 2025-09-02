// blink an LED on pin 13
// make a string to be spelled out and printed
String mystrg = "Hello, ESP32!";
int count;

void setup() {
  // put your setup code here, to run once:
  count = 0;
  Serial.begin(115200); // initialize serial communication at 115200 baud
  //initialize the LED pin
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  Serial.printf("string char: ""%c\n", mystrg[count]); // print the character at index count
  count++; // increment the count
  if (count >= mystrg.length()) {
    count = 0; // reset count if it exceeds the string length
  }
  
  delay(500); // wait for a second
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
  delay(500); // wait for a second
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off

}