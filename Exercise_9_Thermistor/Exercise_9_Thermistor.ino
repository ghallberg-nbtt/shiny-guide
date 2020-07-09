/*
  Thermistor control
  Copyright 2020 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/shiny-guide/blob/master/LICENSE
*/
const int temperaturePin = 0;  // Thermistor connected to analog pin 0
const int ledLow = 8; // Define low temp LED - blue
const int ledNormal = 9; // Define normal temp LED - green
const int ledHigh = 10; // Define high temp LED - red
const int resistorValue = 10000; // We used a 10Kohm resistor
const int SWITCH = 2; // Define Degrees F and C switch

// Variables will change
boolean previousButton = HIGH; // Variable containing the previous button state
boolean currentButton = HIGH; // Variable containing the current button state
boolean celsiusSelected = HIGH;  // Flag if Celsius or Fahrenheit selected
float tempC = 0.0; //Floating point variable for temperature in Celsius
float tempF = 0.0; //Floating point variable for temperature in Fahrenheit

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (SWITCH, INPUT_PULLUP);  // Set the pin 2 as input and use internal pull-up
  pinMode (ledLow, OUTPUT);  // Set pin 8 as output for low temp alert
  pinMode (ledNormal, OUTPUT);  // Set pin 9 as output for normal temp alert
  pinMode (ledHigh, OUTPUT);  // Set pin 10 as output for high temp alert
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempReading = analogRead(temperaturePin);  // Read the ADC value from the thermistor
  double tempK = log(resistorValue * ((1024.0 / tempReading - 1))); //  Calibrate the ADC value based on our 10Kohm resistor
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );  // then convert this number to acutal temperature in Kelvin

  // Is Celsius or Fahrenheit selected?  currentButton = digitalRead(SWITCH); // Read the switch state
  currentButton = digitalRead(SWITCH); // Read the switch state for C or F
  if (previousButton != currentButton)  // If switch pressed
  {
    delay(5);  // Wait 5ms to debounce
    currentButton = digitalRead(SWITCH);  // Read switch again
  }

  if (previousButton == HIGH && currentButton == LOW)  // Detect a button press
  {
    celsiusSelected = !celsiusSelected;  // Toggle C/F state
  }
  previousButton = currentButton;  // Reset button value

  if (celsiusSelected) {
    tempC = tempK - 273.15;            // Convert Kelvin to Celsius
    Serial.print ("Temperature :");  // Print temperature to serial monitor
    Serial.print (tempC);
    Serial.println ("C");
  } else {
    float tempF = ((tempK - 273.15) * 9.0) / 5.0 + 32.0; // Convert Kelvin to Fahrenheit
    Serial.print ("Temperature :");  // Print temperature to serial monitor
    Serial.print (tempF);
    Serial.println ("F");
  }

  //Set Alarm LEDs
  if (tempK > 303.1) {
    // High alarm at > 25C
    digitalWrite (ledHigh, HIGH);  // turn on red LED
    digitalWrite (ledNormal, LOW);  // turn off green LED
    digitalWrite (ledLow, LOW);  // turn off blue LED
  } else if ((tempK <= 303.1) && (tempK >= 298.1)) {
    // Normal light between 25C and 20C
    digitalWrite (ledHigh, LOW);  // turn off red LED
    digitalWrite (ledNormal, HIGH);  // turn on green LED
    digitalWrite (ledLow, LOW);  // turn off blue LED
  } else {
    // Low alarm less than 20C
    digitalWrite (ledHigh, LOW);  // turn off red LED
    digitalWrite (ledNormal, LOW);  // turn off green LED
    digitalWrite (ledLow, HIGH);  // turn on blue LED
  }
  previousButton = currentButton;  // Reset button value
  delay (500);  // wait 1 second
}
