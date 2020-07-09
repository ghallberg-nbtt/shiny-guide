/*
Flashing an external LED
Copyright 2020 Gary Hallberg
Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

const int LED=9;  // Define LED for pin 9
void setup()
{
  pinMode (LED, OUTPUT);  // Set the LED pin as an output
}

void loop()
//repeat forever
{
  digitalWrite(LED, HIGH);  // Set the LED pin high
  delay (1000); // On for 1 second
  digitalWrite(LED, LOW); // Set the LED pin high
  delay (1000);  // Off for 1 second
}
