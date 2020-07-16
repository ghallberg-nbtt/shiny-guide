/*
  Read from Pot
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/


const int POT=0;  // Pot wiper connected to analog pin 0
int val = 0;  // Variable to hold the reading from the POT

void setup()
{
  Serial.begin(9600);  // Initialize the serial monitor
}

void loop()
{
  val = analogRead(POT);  // Read the pot value and store is in val
  Serial.println(val);  // Print the value to the serial monitor
  delay(500); // Wait 0.5 seconds before next reading
}
