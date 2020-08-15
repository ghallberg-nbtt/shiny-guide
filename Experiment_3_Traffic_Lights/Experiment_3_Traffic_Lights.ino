/*
  Traffic Lights
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/

const int RED1 = 2; // Define Red Light for traffic light 1 as pin 2
const int AMBER1 = 3; // Define Amber Light for traffic light 1 as pin 3. We will use a yellow LED
const int GREEN1 = 4; // Define Green Light for traffic light 1 as pin 4
const int RED2 = 8; // Define Red Light for traffic light 2 as pin 8
const int AMBER2 = 9; // Define Amber Light for traffic light 2 as pin 9. We will use a yellow LED
const int GREEN2 = 10; // Define Green Light for traffic light 2 as pin 10

void setup()
{
  pinMode (RED1, OUTPUT);  // Set the pin as an output
  pinMode (AMBER1, OUTPUT);  // Set the pin as an output
  pinMode (GREEN1, OUTPUT);  // Set the pin as an output
  pinMode (RED2, OUTPUT);  // Set the pin as an output
  pinMode (AMBER2, OUTPUT);  // Set the pin as an output
  pinMode (GREEN2, OUTPUT);  // Set the pin as an output
}

void loop()
//repeat forever
{
  sequence1();  // Call sequence 1
  sequence2();  // Call sequence 2
  sequence3();  // Call sequence 3
  sequence4();  // Call sequence 4
}

void sequence1() {
  digitalWrite(RED1, HIGH);  // Set the Red light 1 high
  digitalWrite(AMBER1, LOW);  // Set the Amber light 1 low
  digitalWrite(GREEN1, LOW);  // Set the Green light 1 low
  digitalWrite(RED2, LOW);  // Set the Red light 2 low
  digitalWrite(AMBER2, LOW);  // Set the Amber light 2 low
  digitalWrite(GREEN2, HIGH);  // Set the Green light 2 high
  delay (1000);  // Delay 1 second
}
void sequence2() {
  digitalWrite(RED1, HIGH);  // Set the Red light 1 high
  digitalWrite(AMBER1, HIGH);  // Set the Amber light 1 high
  digitalWrite(GREEN1, LOW);  // Set the Green light 1 low
  digitalWrite(RED2, LOW);  // Set the Red light 2 low
  digitalWrite(AMBER2, HIGH);  // Set the Amber light 2 high
  digitalWrite(GREEN2, LOW);  // Set the Green light 2 low
  delay (1000);  // Delay 1 second
}
void sequence3() {
  digitalWrite(RED1, LOW);  // Set the Red light 1 low
  digitalWrite(AMBER1, LOW);  // Set the Amber light 1 low
  digitalWrite(GREEN1, HIGH);  // Set the Green light 1 high
  digitalWrite(RED2, HIGH);  // Set the Red light 2 high
  digitalWrite(AMBER2, LOW);  // Set the Amber light 2 low
  digitalWrite(GREEN2, LOW);  // Set the Green light 2 low
  delay (1000);  // Delay 1 second
}
void sequence4() {
  digitalWrite(RED1, LOW);  // Set the Red light 1 low
  digitalWrite(AMBER1, HIGH);  // Set the Amber light 1 high
  digitalWrite(GREEN1, LOW);  // Set the Green light 1 low
  digitalWrite(RED2, HIGH);  // Set the Red light 2 high
  digitalWrite(AMBER2, HIGH);  // Set the Amber light 2 high
  digitalWrite(GREEN2, LOW);  // Set the Green light 2 low
  delay (1000);  // Delay 1 second
}
