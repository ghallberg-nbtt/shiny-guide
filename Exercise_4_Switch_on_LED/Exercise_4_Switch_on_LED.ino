/*
  Switch on LED
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

const int SWITCH = 2; // Define switch as pin 2
const int LED = 8; // Define LED as pin 8
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup()
{
  pinMode (SWITCH, INPUT);  // Set the pin 2 as input 
  pinMode (LED, OUTPUT);  // Set the pin 8 as output
}

void loop()
//repeat forever
{
  buttonState = digitalRead(SWITCH);  // read the state of the pushbutton value:

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(LED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(LED, LOW);
  }
}
