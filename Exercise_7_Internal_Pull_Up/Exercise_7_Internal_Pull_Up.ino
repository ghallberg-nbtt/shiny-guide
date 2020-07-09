/*
  Toggle LED with debounce and internal pullup
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

const int SWITCH = 2; // Define switch as pin 2
const int LED = 8; // Define LED as pin 8

// variables will change:
boolean previousButton = HIGH; // Variable containing the previous button state
boolean currentButton = HIGH; // Variable containing the current button state
boolean ledOn = false;  // The present state of the LED (on or off)

void setup()
{
  pinMode (SWITCH, INPUT_PULLUP);  // Set the pin 2 as input and use internal pull-up
  pinMode (LED, OUTPUT);  // Set the pin 8 as output
}

void loop()

{
  currentButton = digitalRead(SWITCH); // Read the switch state

  if (previousButton != currentButton)  // If switch pressed
  {
    delay(5);  // Wait 5ms
    currentButton = digitalRead(SWITCH);  // Read switch again
  }
  
  if (previousButton == HIGH && currentButton == LOW)  // Detect a button press
  {
    ledOn = !ledOn;  // Toggle the LED state on > off and off > on
  }
  previousButton = currentButton;  // Reset button value
  digitalWrite(LED, ledOn);  // Change the LED state
}
