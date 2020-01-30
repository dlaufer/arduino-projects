#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int ThermistorPin = A0;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
  T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: (Analog)");
  lcd.setCursor(0, 1);
  lcd.print(T);

  delay(400);
}
