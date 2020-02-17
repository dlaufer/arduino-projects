#include <IRremote.h>

int RECV_PIN = 11;
char* out_str;
int IN1=3;
int IN2=4;
int IN3=5;
int IN4=6;
int ENA=9;
int ENB=10;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");

  // setup pins for motor
  for (int i = 5; i <11; i ++)
  {
    pinMode(i, OUTPUT);  
  }
  forward();
}

void loop()
{
  if (irrecv.decode(&results)) {
    get_button_pressed(String(results.value, HEX));
    Serial.println(out_str);
    irrecv.resume(); // Receive the next value
    delay(300);
  } else {
    delay(100);
  }
}

void left() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,100);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,100);
  delay(500);
  stopAndWait();
}
void right() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,100);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,100);
  delay(500);
  stopAndWait();
}
void backward() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,100);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,100);
  delay(500);
  stopAndWait();
}
void forward() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,100);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,100);
  delay(500);
  stopAndWait();
}

void stopAndWait() {
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  delay(500);
}

void get_button_pressed(String pressed_button){
//  Serial.println(pressed_button);
  // Directional
  if (pressed_button == "ff22dd") {
    out_str = (char*)"left";
    left();
  }
  if (pressed_button == "ff629d") {
    out_str = (char*)"up";
    forward();
  }
  if (pressed_button == "ffc23d") {
    out_str = (char*)"right";
    right();
  }
  if (pressed_button == "ffa857") {
    out_str = (char*)"down";
    backward();
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
