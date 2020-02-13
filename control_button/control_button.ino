#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int buttonpin = 3; // define photo interrupter signal pin
int val; //define a numeric variable

 
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication  
  pinMode(buttonpin, INPUT); //photo interrupter pin as input
}
 
void loop() {
  
  val = digitalRead(buttonpin); // check the state of the button
  if(val==HIGH) // if button is pressed, turn LED on
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Button: ");
    lcd.setCursor(0, 1);
    lcd.print("...open..."); 
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Button: ");
    lcd.setCursor(0, 1);
    lcd.print("PRESSED!"); 
  }

  delay(100);
}
