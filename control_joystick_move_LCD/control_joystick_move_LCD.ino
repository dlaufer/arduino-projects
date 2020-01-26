// include the library code for the LCD and initialize it
// used https://www.thegeekpub.com/235425/arduino-ultrasonic-sensor-tutorial/
// and this to actually setup LCD https://www.arduino.cc/en/Tutorial/HelloWorld

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int currentX = 0;
int currentY = 0;

 
void setup() {  
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
  
  Serial.print(digitalRead(SW_pin));  
 
  // Prints the distance on the Serial Monitor
  lcd.clear();
  int x_read = analogRead(X_pin);
  int y_read = analogRead(Y_pin);
  
  // right
  if (x_read > 550 && currentX < 15) {
    currentX += 1;
  }
  // left
  if (x_read < 450 && currentX > 0) {
    currentX -= 1;
  }
  // up
  if (y_read < 450 && currentY > 0) {
    currentY -= 1;
  }
  // down
  if (y_read > 550 && currentY < 1) {
    currentY += 1;
  }
  
  lcd.setCursor(currentX, currentY);
  lcd.print("<>");
 
  delay(500);
}
