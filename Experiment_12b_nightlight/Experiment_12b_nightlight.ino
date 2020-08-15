/*
  Nightlight
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

// Define constant values
const int LIGHT = 0; // Photocell on Analog Pin 0
const int LED = 3; // Set pin 3 as LED
const int high_level = 830;  // high light level
const int low_level = 440;  // low light level

// Define variables
int val = 0;  // Holds the analog reading from photocell

void setup()
{
  pinMode (LIGHT, OUTPUT); // LED output;
}

void loop()
{
  val = analogRead(LIGHT);  // Read the light sensor
  val = map (val, low_level, high_level, 255, 0); // Map the ADC value to PWM value
  val = constrain (val, 0, 255);  // Constrain the values
  analogWrite (LED, val);
}
