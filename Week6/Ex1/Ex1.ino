void setup() {
  // put your setup code here, to run once:
  DDRB = 0b10000000;     //PB7 (pin 13 at arduino mega) OC0A
  OCR0A = 127;           //50% duty cycle
  TCCR0A = 0b10000001;   //Normal output channel A, Phase Correct PWM 255 top
  TCCR0B = 0b00000011;   //64 pre-scaler
}

void loop() {
  // put your main code here, to run repeatedly:

}
