//make hello world message
char hello[] = "Hello World!";
//define the pin for the button
const int button_in = T6; //label is 14

int size_hello = sizeof(hello) - 1;
int count = 0;
int periodicity = 3000;
bool button_pressed = false;

// function prototypes
void button_press(void); // function prototype for the button press function
void change_period(void); 

// setup() runs once, when the device is first turned on
void setup() {
  Serial.begin(115200);
  // enable interrupts
  interrupts();
  // Initialize the button pin as an input
  pinMode(button_in, INPUT_PULLDOWN);
  // Attach an interrupt to the button pin
  attachInterrupt(button_in, button_press, RISING);
}

// function to be called when the button is pressed
// we do not want to do too much in the interrupt handler
void button_press(void) {
  button_pressed = true;
}

void change_period(void) {
  periodicity = random(300, 1000);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  // if the button is pressed, print the message
  if (button_pressed) {
    
    Serial.println("Button pressed!-------------------");
    button_pressed = false;
    change_period();
  }
  // if we have reached the end of the message, reset the count
  if (count == size_hello) {
    count = 0;
  } 
  
  //log the current character
  Serial.printf("current character: %c ", hello[count]);
  Serial.printf("...about to wait for %d ms\n", periodicity);
  count++;
  //wait for the amount of time specified by the periodicity variable
  delay(periodicity);
}
