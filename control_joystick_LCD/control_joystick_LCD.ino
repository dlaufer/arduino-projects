// include the library code for the LCD and initialize it
// used https://www.thegeekpub.com/235425/arduino-ultrasonic-sensor-tutorial/
// and this to actually setup LCD https://www.arduino.cc/en/Tutorial/HelloWorld

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
 
void setup() {  
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
  
  Serial.print(digitalRead(SW_pin));  
 
  // Prints the distance on the Serial Monitor
  lcd.clear();
  lcd.setCursor(0,0); // set the cursor to home
  lcd.print("Lets move!!! :)"); // write our name
  lcd.setCursor(0, 1);  
  lcd.print("X: ");
  lcd.print(analogRead(X_pin));
  lcd.print(", Y: ");
  lcd.print(analogRead(Y_pin));
 
  delay(500);
}
