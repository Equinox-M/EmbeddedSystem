#include <LiquidCrystal.h>
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TOT_TARGETS 4
#define TOT_SENSORS 4
#define PIN_TARGET 7


Servo Targets[TOT_TARGETS];  //Servo
int targetSensor[] = {A0, A1, A2, A3};  // LDR Sensor
int readingSensor[TOT_SENSORS];
int targetTimer[] = {0, 0, 0, 0}; 
int score = 0;
int timer = 100;
unsigned long interval = 100; // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.

void setup() {
  Serial.begin(9600);

  lcd.backlight();
  lcd.clear();
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("SCORE: 0");
  lcd.setCursor(0, 1);
  lcd.print("TIMER: 0");

  //attaches the servos from pin 7 to 10
  for (int targetNumber = 0; targetNumber < TOT_TARGETS; targetNumber++)
  {
    Targets[targetNumber].attach(targetNumber + PIN_TARGET);
    Targets[targetNumber].write(0);
  }
}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);  //(Column,Row)
  lcd.print("SCORE: ");
  lcd.setCursor(12, 0);
  lcd.print(score);
  lcd.setCursor(0, 1);  //(Column,Row)
  lcd.print("TIME: ");
  lcd.setCursor(12, 1);
  lcd.print(timer);

  unsigned long currentMillis = millis(); // grab current time

  // check if "interval" time has passed (100 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {

    for (int targetsensorNumber = 0; targetsensorNumber < TOT_SENSORS; targetsensorNumber++) {
      readingSensor[targetsensorNumber] = analogRead((targetSensor[targetsensorNumber]));
    }
    previousMillis = millis();
    Serial.print(readingSensor[1]);
    Serial.println(readingSensor[2]);
  }
  villainTarget();
  targetDown();
  ifZero();
  Countdowntimer();
  
}

void villainTarget() {

  int target = random(1, 5);
  delay(10);
  if (target == 1) {
    targetTimer[0]++;
    Targets[0].write(90);
    delay(10);
    if (targetTimer[0] == 2) {
      targetTimer[0] = 0;
      Targets[0].write(0);
      delay(10);
    }
  } else if (target == 2) {
    targetTimer[1]++;
    Targets[1].write(90);
    delay(10);
    if (targetTimer[1] == 2) {
      targetTimer[1] = 0;
      Targets[1].write(0);
      delay(10);
    }

  } else if (target == 3) {
    targetTimer[2]++;
    Targets[2].write(90);
    delay(10);
    if (targetTimer[2] == 2) {
      targetTimer[2] = 0;
      Targets[2].write(0);
      delay(10);
    }
  } else if (target == 4) {
    targetTimer[3]++;
    Targets[3].write(90);
    delay(10);
    if (targetTimer[3] == 2) {
      targetTimer[3] = 0;
      Targets[3].write(0);
      delay(10);
    }
  }
}

void targetDown() {
  //if target 1
  if (readingSensor[0] > 450) {
    score++;
    Targets[0].write(0);
    delay(100);
  }
  //if target 2
  if (readingSensor[1] > 990) {
    score++;
    Targets[1].write(1);
    delay(100);
  }
  // if target speacial
  if (readingSensor[2] > 990) {
    score = score + 5;
    Targets[2].write(2);
    delay(100);
  }
  //if target 3
  if (readingSensor[3] > 985) {
    score++;
    Targets[3].write(3);
    delay(100);
  }
}


void Countdowntimer() {
  timer--;
  delay(1000);
}

void ifZero() {
  if (timer == 0) {
    for (int targetNumber = 0; targetNumber < TOT_TARGETS; targetNumber++)
    {
      Targets[targetNumber].write(0);
    }
    lcd.clear();
    lcd.print(" YOUR SCORE: ");
    lcd.setCursor(12, 0);
    lcd.print(score);
    delay(10000);
    score=0;
    timer = 100;
  }
}
