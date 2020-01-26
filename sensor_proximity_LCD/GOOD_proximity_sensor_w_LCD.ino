// include the library code for the LCD and initialize it
// used https://www.thegeekpub.com/235425/arduino-ultrasonic-sensor-tutorial/
// and this to actually setup LCD https://www.arduino.cc/en/Tutorial/HelloWorld

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// defines pins numbers
const int echoPin = 9;
const int trigPin = 10;
 
// defines variables
long duration;
int distanceCM;
int distanceIN;
 
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor to home
  lcd.print("Bluecadet!!! :)"); // write our name
  Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
 
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
 
  // Calculating the distance
  distanceCM = duration*0.034/2;
  distanceIN = duration*0.0133/2;
 
  // Prints the distance on the Serial Monitor
  lcd.setCursor(0, 1);
  lcd.print(distanceCM);
  lcd.print(" cm, ");
  lcd.setCursor(9, 1);
  lcd.print(distanceIN);
  lcd.print(" in");

  // Prints the distance on the Serial Monitor in CM
  Serial.print("DistanceCM: ");
  Serial.println(distanceCM);
  Serial.print("DistanceIN: ");
  Serial.println(distanceIN);
 
  delay(300);
}
