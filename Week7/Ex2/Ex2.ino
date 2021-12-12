volatile bool changed = 0;

void setup() {
  // put your setup code here, to run once:
  DDRA = 0b00000001;      //PA0 as output
  SREG |= 0b10000000;     //Enable interrupts in general
  PCICR = 0b00000001;     //Enable PCINT0
  PCMSK0 = 0b00010000;     //Enable PCINT on PB4
  Serial.begin(9600);

  pinMode(10, INPUT_PULLUP);  //Set PB4 (pin 10 on arduino mega) as input with internal pullup resistor.
}

ISR(PCINT0_vect)
{
  changed = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (changed == 1)
  {
    PORTA = 0b00000001;
    Serial.println("CHANGE DETECTED");
    changed = 0;
  }
  else
  {
    PORTA = 0b00000000;
  }
}
