/*
  Brightness control for LED
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

const int LED = 9; // Define LED for Pin 9
void setup()
{
  pinMode (LED, OUTPUT);  // Set the LED pin as an output
}

void loop()
{
  for (int i = 0; i < 256; i++) // step up brightness
  {
    analogWrite(LED, i);  // control LED
    delay(10);
  }
  for (int i = 255; i >= 0; i--) // step down brightness
  {
    analogWrite(LED, i);  // control LED
    delay(10);
  }
  // step through 0%, 25%, 75% and 100% duty cycle
  analogWrite(LED, 0);  // 0% duty cycle
  delay (1000);
  analogWrite(LED, 63);  // 25% duty cycle
  delay (1000);
  analogWrite(LED, 127);  // 50% duty cycle
  delay (1000);
  analogWrite(LED, 191);  // 75% duty cycle
  delay (1000);
  analogWrite(LED, 255);  // 100% duty cycle
  delay (1000);
}
