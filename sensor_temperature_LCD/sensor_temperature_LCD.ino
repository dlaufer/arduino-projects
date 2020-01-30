#include <OneWire.h> // https://github.com/PaulStoffregen/OneWire
#include <DallasTemperature.h> // https://github.com/milesburton/Arduino-Temperature-Control-Library
#include <LiquidCrystal.h>

// Declaration of the input pin which is connected with the sensor module
#define KY001_Signal_PIN 2

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// libraries configuration
OneWire oneWire(KY001_Signal_PIN);          
DallasTemperature sensors(&oneWire);  
 
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication
  sensors.begin(); // sensor will be initialized
}
 
void loop() {
  // temperature measurment will be started.
  sensors.requestTemperatures();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0));
//  Serial.write(176); // UniCode of the char-symbol "°-Symbol"
//  Serial.println("C");

  delay(250);
}
