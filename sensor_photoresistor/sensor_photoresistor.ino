#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int sensorPin = 2; // define analog pin
int value = 0;

 
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication  
  pinMode(sensorPin, INPUT); //photo interrupter pin as input
}
 
void loop() {
  
  value = analogRead(sensorPin); //read the value of the sensor 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.setCursor(0, 1);
  lcd.print(1020 - value);

  delay(250);
}
