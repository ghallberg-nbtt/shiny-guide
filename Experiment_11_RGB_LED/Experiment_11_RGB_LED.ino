/*
  RGB LED
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/
// Define Pins
const int BLUE = 6;
const int GREEN = 9;
const int RED = 10;

// define variables
int redValue;
int greenValue;
int blueValue;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

// main loop
void loop()
{
  // Turn off all LEDs at start
  digitalWrite (RED, LOW);
  digitalWrite (GREEN, LOW);
  digitalWrite (BLUE, LOW);
  for (int i = 0; i < 256; i++) // step up brightness of red color
  {
    analogWrite(RED, i);  // red LED control
    delay(10);
  }
  for (int i = 255; i >= 0; i--) // step down brightness of red color and step up green
  {
    analogWrite(RED, i);  // red LED control
    analogWrite(GREEN, (255 - i)); // green LED control
    delay(10);
  }
  for (int i = 255; i >= 0; i--) // step down brightness of green color and step up blue
  {
    analogWrite(GREEN, i);  // green LED control
    analogWrite(BLUE, (255 - i)); // blue LED control
    delay(10);
  }
  delay (1000);
  // Random colors
  for (int i = 0; i < 30; i++) // step through 30 times
  {
    //  Generate random numbers for each color
    int randRed = random(255);
    int randGreen = random(255);
    int randBlue = random(255);
    analogWrite(RED, randRed);  // red LED control
    analogWrite(GREEN, randGreen);  // green LED control
    analogWrite(BLUE, randBlue);  // blue LED control
    delay(1000);
  }
}
