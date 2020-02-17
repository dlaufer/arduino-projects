#include <IRremote.h>

int RECV_PIN = 11;
char* out_str;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    get_button_pressed(String(results.value, HEX));
    Serial.println(out_str);
    irrecv.resume(); // Receive the next value
    delay(300);
  } else {
    delay(100);
  }
}

void get_button_pressed(String pressed_button){
  // Directional
  if (pressed_button == "ff22dd") {
    out_str = (char*)"left";
  }
  if (pressed_button == "ff629d") {
    out_str = (char*)"up";
  }
  if (pressed_button == "ffc23d") {
    out_str = (char*)"right";
  }
  if (pressed_button == "ffa857") {
    out_str = (char*)"down";
  }
  
  // General 
  if (pressed_button == "ff02fd") {
    out_str = (char*)"ok";
  }
  if (pressed_button == "ff42bd") {
    out_str = (char*)"star";
  }
  if (pressed_button == "ff52ad") {
    out_str = (char*)"pound";
  }

  // Numbers
  if (pressed_button == "ff6897") {
    out_str = (char*)"one";
  }
  if (pressed_button == "ff9867") {
    out_str = (char*)"two";
  }
  if (pressed_button == "ffb04f") {
    out_str = (char*)"three";
  }
  if (pressed_button == "ff30cf") {
    out_str = (char*)"four";
  }
  if (pressed_button == "ff18e7") {
    out_str = (char*)"five";
  }
  if (pressed_button == "ff7a85") {
    out_str = (char*)"six";
  }
  if (pressed_button == "ff10ef") {
    out_str = (char*)"seven";
  }
  if (pressed_button == "ff38c7") {
    out_str = (char*)"eight";
  }
  if (pressed_button == "ff5aa5") {
    out_str = (char*)"nine";
  }
  if (pressed_button == "ff4ab5") {
    out_str = (char*)"zero";
  }
}
