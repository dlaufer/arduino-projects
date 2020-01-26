#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int currentX = 0;
int currentY = 0;

int enemyX = 13;
int enemyY = 1;

int loopCount = 1;
int gameSpeed = 280;
int ticksPerIncrement = 14;
int winningGameSpeed = 9;

byte level0Enemy[] = {
  B00000,
  B00000,
  B00100,
  B01111,
  B01111,
  B00100,
  B00000,
  B00000
};

byte level1Enemy[] = {
  B00000,
  B00000,
  B11100,
  B10011,
  B01001,
  B10011,
  B11100,
  B00000
};

byte level2Enemy[] = {
  B00001,
  B01100,
  B10000,
  B11111,
  B11111,
  B10000,
  B01100,
  B00001
};


byte level3Enemy[] = {
  B01110,
  B10000,
  B11111,
  B11111,
  B11111,
  B11111,
  B10000,
  B01110
};
 
void setup() {  
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600); // Starts the serial communication
  randomSeed(analogRead(4)); // seed the random number with an empty pin?
  lcd.createChar(0, level0Enemy);
  lcd.createChar(1, level1Enemy);
  lcd.createChar(2, level2Enemy);
  lcd.createChar(3, level3Enemy);
}
 
void loop() {
  //  Serial.print(digitalRead(SW_pin));
  
  // Prints the distance on the Serial Monitor
  lcd.clear();

  if (didntRunIntoEnemy(currentX, currentY, enemyX, enemyY)) {
    // MOVE ENEMY
    enemyX -= 1;
    // reset enemy after dead
    if(enemyX < 0) {
      enemyX = 13;
      enemyY = random(0,2);
    }
  
    // MOVE PLAYER
    int x_read = analogRead(X_pin);
    int y_read = analogRead(Y_pin);
    // --right
    if (x_read > 550 && currentX < 12) { currentX += 1; }
    // --left
    if (x_read < 450 && currentX > 0) { currentX -= 1; }
    // --up
    if (y_read < 450 && currentY > 0) { currentY -= 1; }
    // --down
    if (y_read > 550 && currentY < 1) { currentY += 1; }

    loopCount += 1;

    if (loopCount % ticksPerIncrement == 0) {
      if(gameSpeed > 180) {
        gameSpeed -= 10;
      } else if (gameSpeed > 110) {
        gameSpeed -= 7;
      } else if (gameSpeed > 50) {
        gameSpeed -= 5;
      } else if (gameSpeed > 30) {
        gameSpeed -= 4;
      }
    }
  } else {
    printYouLose();
  }

  if(gameSpeed > winningGameSpeed) {
    printEnemy(enemyX, enemyY);
    printPlayer(currentX, currentY);
    printScore(loopCount);
  } else {
    printWinner();  
  }

  delay(gameSpeed);
}

bool didntRunIntoEnemy(int currentX, int currentY, int enemyX, int enemyY) {
  if (
    currentY == enemyY &&
    ( currentX == enemyX ||
      currentX + 1 == enemyX ||
      currentX + 2 == enemyX)
  ) {
    return false;
  } else {
    return true; 
  }
}

void printEnemy(int enemyX, int enemyY) {
  lcd.setCursor(enemyX, enemyY);
  int score = (int) (loopCount / ticksPerIncrement);
  if (score <= 9) {
    lcd.write(byte(0));
  } else if (score > 9 && score <= 19) {
    lcd.write(byte(1));
  } else if (score > 19 && score <= 29) {
    lcd.write(byte(2));
  } else if (score > 29) {
    lcd.write(byte(3));
  }
  
}

void printPlayer(int currentX, int currentY) {
  lcd.setCursor(currentX, currentY);
  lcd.print("()");
}

void printScore(int loopCount) {
  int score = (int) (loopCount / ticksPerIncrement);
  lcd.setCursor(14, 0);
  lcd.print(score);  
}

void printWinner() {  
  lcd.setCursor(3, 0);
  lcd.print("You Won!");
}

void printYouLose() {
  if(currentY == 0) {
    lcd.setCursor(0, 1);  
  } else {
    lcd.setCursor(0, 0);
  }  
  lcd.print("...you lose.");
}
