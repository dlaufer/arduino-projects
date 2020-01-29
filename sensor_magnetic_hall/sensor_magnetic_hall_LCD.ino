#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
 
// defines pins numbers
const int sensor = 3;
int val;
int result;
 
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  pinMode(sensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  
  val = digitalRead(sensor); //Read the sensor
  if(val == LOW) //when magnetic field is detected, turn led on
  {
    lcd.print("MAGNETS!"); 
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    lcd.print("...."); 
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(30);
}
