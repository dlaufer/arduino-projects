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
  
  val=digitalRead(buttonpin); //read the value of the sensor 
  if(val == HIGH) // turn on LED when sensor is blocked 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Blocked: ");
    lcd.setCursor(0, 1);
    lcd.print("Blocked");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Blocked: ");
    lcd.setCursor(0, 1);
    lcd.print("Light");
  }  

  delay(500);
}
