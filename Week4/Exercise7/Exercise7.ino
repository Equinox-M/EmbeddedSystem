unsigned long prevmillis1 = 0;
unsigned long prevmillis2 = 0;
unsigned long currentmillis1 = 0;
unsigned long currentmillis2 = 0;
bool flag1 = 0;
bool flag2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentmillis1 = millis();
  currentmillis2 = millis();
  if (flag1 == 0) {
    digitalWrite(2, HIGH);
    if ((currentmillis1 - prevmillis1) > 750) {
      flag1 = 1;
      prevmillis1 = currentmillis1;
    }
  }
  if (flag1 == 1) {
    digitalWrite(2, LOW);
    if ((currentmillis1 - prevmillis1) > 350) {
      flag1 = 0;
      prevmillis1 = currentmillis1;
    }
  }
  
  if (flag2 == 0) {
    digitalWrite(3, HIGH);
    if ((currentmillis2 - prevmillis2) > 400) {
      flag2 = 1;
      prevmillis2 = currentmillis2;
    }
  }
  if (flag2 == 1) {
    digitalWrite(3, LOW);
    if ((currentmillis2 - prevmillis2) > 600) {
      flag2 = 0;
      prevmillis2 = currentmillis2;
    }
  }
}
