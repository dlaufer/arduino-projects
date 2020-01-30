#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRsend irsend;
int RECV_PIN = 3; // define input pin on Arduino 
IRrecv irrecv(RECV_PIN); 
decode_results results; // decode_results class is defined in IRremote.h

void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver 
}

void loop() 
{
   for (int i = 0; i < 10; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     if (irrecv.decode(&results)) {
       Serial.println(results.value, HEX); 
       irrecv.resume(); // Receive the next value 
     } else {
      Serial.println("no reading");
     }
     delay(250);
   }
}
