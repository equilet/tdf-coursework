//make hello world message
char hello[] = "Hello World!";
//define the pin for the button
const int button_in = T6; //label is 14
const int led_out2 = T9; //label is 32


int size_hello = sizeof(hello) - 1; 
int count = 0;
int count_cycle = 0;
int periodicity = 600;
bool button_pressed = false;

void button_press(void); // function prototype for the button press function

// setup() runs once, when the device is first turned on
void setup() {
  interrupts();
  Serial.begin(115200);
  delay(200);
  pinMode(button_in, INPUT_PULLDOWN);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(led_out2, OUTPUT);
  digitalWrite(led_out2, LOW);
  attachInterrupt(button_in, button_press, RISING);
}

// function to be called when the button is pressed
// we do not want to do too much in the interrupt handler
void button_press(void) {
  button_pressed = true;
}

void change_period(void) {
  //periodicity = random(300, 1000);
  periodicity = random(100, 600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(led_out2, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led_out2, LOW);
  // if the button is pressed, print the message
  if (button_pressed) {
    
    Serial.println("Button pressed!-------------------");
    button_pressed = false;
    change_period();
    

  }
  // if we have reached the end of the message, reset the count
  if (count == size_hello) {
    count = 0;
    count_cycle++;
    Serial.printf("count cycle was incremented to: %d\n", count_cycle);
  } 
  
  //log the current character
  Serial.printf("current character: %c ", hello[count]);
  Serial.printf("...about to wait for %d ms\n", periodicity);
  count++;
  //wait for the amount of time specified by the periodicity variable
  delay(periodicity);
}
