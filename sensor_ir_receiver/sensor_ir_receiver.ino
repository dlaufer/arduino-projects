#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int RECV_PIN = 3; // define input pin on Arduino 
IRrecv irrecv(RECV_PIN); 
decode_results results; // decode_results class is defined in IRremote.h
int RND = 0;


void setup()
{
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver 
}

void loop() 
{
  if (RND == 0) {
    lcd.print("IR Code:");
    RND += 1;
  }
  
  if (irrecv.decode(&results)) {
    
    String str = String(results.value, HEX);
    // Serial.println(str); 
    // Serial.println(results.value, HEX); 
    irrecv.resume(); // Receive the next value 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IR Code:");

    lcd.setCursor(0, 1);
    lcd.print(str);
    
    RND += 1;
  }
  delay (20); // small delay to prevent reading errors
}
