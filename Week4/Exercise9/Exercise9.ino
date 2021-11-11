unsigned long prevmillis1 = 0;
unsigned long prevmillis2 = 0;
unsigned long prevmillis3 = 0;
unsigned long prevmillis4 = 0;
unsigned long prevmillis5 = 0;
unsigned long prevmillis6 = 0;
unsigned long prevmillis7 = 0;
unsigned long prevmillis8 = 0;
unsigned long currentmillis1 = 0;
unsigned long currentmillis2 = 0;
unsigned long currentmillis3 = 0;
unsigned long currentmillis4 = 0;
unsigned long currentmillis5 = 0;
unsigned long currentmillis6 = 0;
unsigned long currentmillis7 = 0;
unsigned long currentmillis8 = 0;
bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;
bool flag7 = 0;
bool flag8 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRA = 0b11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentmillis1 = currentmillis2 = currentmillis3 = currentmillis4 = currentmillis5 = currentmillis6 = currentmillis7 = currentmillis8 =  millis();
  
  if (flag1 == 0) {
    PORTA |= 0b00000001;
    if ((currentmillis1 - prevmillis1) > 781) {
      flag1 = 1;
      prevmillis1 = currentmillis1;
    }
  }
  if (flag1 == 1) {
    PORTA &= 0b11111110;
    if ((currentmillis1 - prevmillis1) > 515) {
      flag1 = 0;
      prevmillis1 = currentmillis1;
    }
  }
  
  if (flag2 == 0) {
    PORTA |= 0b00000010;
    if ((currentmillis2 - prevmillis2) > 2014) {
      flag2 = 1;
      prevmillis2 = currentmillis2;
    }
  }
  if (flag2 == 1) {
    PORTA &= 0b11111101;
    if ((currentmillis2 - prevmillis2) > 1348) {
      flag2 = 0;
      prevmillis2 = currentmillis2;
    }
  }

  if (flag3 == 0) {
    PORTA |= 0b00000100;
    if ((currentmillis3 - prevmillis3) > 343) {
      flag3 = 1;
      prevmillis3 = currentmillis3;
    }
  }
  if (flag3 == 1) {
    PORTA &= 0b11111011;
    if ((currentmillis3 - prevmillis3) > 573) {
      flag3 = 0;
      prevmillis3 = currentmillis3;
    }
  }
  
  if (flag4 == 0) {
    PORTA |= 0b00001000;
    if ((currentmillis4 - prevmillis4) > 678) {
      flag4 = 1;
      prevmillis4 = currentmillis4;
    }
  }
  if (flag4 == 1) {
    PORTA &= 0b11110111;
    if ((currentmillis4 - prevmillis4) > 1839) {
      flag4 = 0;
      prevmillis4 = currentmillis4;
    }
  }

  if (flag5 == 0) {
    PORTA |= 0b00010000;
    if ((currentmillis5 - prevmillis5) > 342) {
      flag5 = 1;
      prevmillis5 = currentmillis5;
    }
  }
  if (flag5 == 1) {
    PORTA &= 0b11101111;
    if ((currentmillis5 - prevmillis5) > 534) {
      flag5 = 0;
      prevmillis5 = currentmillis5;
    }
  }
  
  if (flag6 == 0) {
    PORTA |= 0b00100000;
    if ((currentmillis6 - prevmillis6) > 1478) {
      flag6 = 1;
      prevmillis6 = currentmillis6;
    }
  }
  if (flag6 == 1) {
    PORTA &= 0b11011111;
    if ((currentmillis6 - prevmillis6) > 326) {
      flag6 = 0;
      prevmillis6 = currentmillis6;
    }
  }

  if (flag7 == 0) {
    PORTA |= 0b01000000;
    if ((currentmillis7 - prevmillis7) > 1859) {
      flag7 = 1;
      prevmillis7 = currentmillis7;
    }
  }
  if (flag7 == 1) {
    PORTA &= 0b10111111;
    if ((currentmillis7 - prevmillis7) > 351) {
      flag7 = 0;
      prevmillis7 = currentmillis7;
    }
  }
  
  if (flag8 == 0) {
    PORTA |= 0b10000000;
    if ((currentmillis8 - prevmillis8) > 777) {
      flag8 = 1;
      prevmillis8 = currentmillis8;
    }
  }
  if (flag8 == 1) {
    PORTA &= 0b01111111;
    if ((currentmillis8 - prevmillis8) > 888) {
      flag8 = 0;
      prevmillis8 = currentmillis8;
    }
  }
}
