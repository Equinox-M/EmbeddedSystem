void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00100000;       //PB5 (pin 11 on arduino mega) OC1A
  OCR1A = 255;             //25% duty cycle
  TCCR1A = 0b10000011;     //Normal output channel A, 10 bit phase correct PWM
  TCCR1B = 0b00000010;     //8 pre-scaler
}

void loop() {
  // put your main code here, to run repeatedly:

}
