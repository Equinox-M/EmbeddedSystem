void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00100000;      //PB5 as input
  SREG |= 0b10000000;     //Enable interrupts in general
  EIMSK = 0b00000001;     //Enable INT0
  EICRA = 0b00000001;     //Set interrupt mode to any logic change

  pinMode(21, INPUT_PULLUP);  //Set INT0 (pin 21 on arduino mega) as input with internal pullup resistor.
}

ISR(INT0_vect)
{
  bool pin_status = ((PIND) & 0b00000001);   //Read pin 21 (PD0)
  PORTB = !pin_status << 5; //Same as digitalWrite(11, digitalRead(21))
}

void loop() {
  // put your main code here, to run repeatedly:

}
