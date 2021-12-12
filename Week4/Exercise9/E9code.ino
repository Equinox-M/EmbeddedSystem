#include <avr/io.h>

unsigned long prevmillis1 = 0;
unsigned long prevmillis2 = 0;
unsigned long prevmillis3 = 0;
unsigned long prevmillis4 = 0;
unsigned long prevmillis5 = 0;
unsigned long prevmillis6 = 0;
unsigned long prevmillis7 = 0;
unsigned long prevmillis8 = 0;

unsigned long current1 = 0;
unsigned long current2 = 0;
unsigned long current3 = 0;
unsigned long current4 = 0;
unsigned long current5 = 0;
unsigned long current6 = 0;
unsigned long current7 = 0;
unsigned long current8 = 0;


void setup() {

  unsigned char *dir = (unsigned char*) 0x2A; //Points to DDRD (To set the pins to either OUTPUT/INPUT)
  
  *dir = 255;

}



void loop() {

  current1 = current2 = current3 = current4 = current5 = current6 = current7 = current8 = millis();
  unsigned char *port = (unsigned char*) 0x2B; //Points to PORTD (Pin 0-7 Arduino)
  
  //Pin 0
  if (((*port) & 0b00000001) == 0){
    
    if (current1 - prevmillis1 >= 515){

      *port |= 0b00000001;
      prevmillis1 = current1;
      
    }
    
  }

  else {

    if (current1 - prevmillis1 >= 781){

      *port &= 0b11111110;
      prevmillis1 = current1;
      
    }
  }

  //Pin 1
  if (((*port) & 0b00000010) == 0){
    
    if (current2 - prevmillis2 >= 1348){

      *port |= 0b00000010;
      prevmillis2 = current2;
      
    }
    
  }

  else {

    if (current2 - prevmillis2 >= 2014){

      *port &= 0b11111101;
      prevmillis2 = current2;
      
    }
  }

  //Pin 2
  if (((*port) & 0b00000100) == 0){
    
    if (current3 - prevmillis3 >= 573){

      *port |= 0b00000100;
      prevmillis3 = current3;
      
    }
    
  }

  else {

    if (current3 - prevmillis3 >= 343){

      *port &= 0b11111011;
      prevmillis3 = current3;
      
    }
  }

  //Pin 3
  if (((*port) & 0b00001000) == 0){
    
    if (current4 - prevmillis4 >= 1839){

      *port |= 0b00001000;
      prevmillis4 = current4;
      
    }
    
  }

  else {

    if (current4 - prevmillis4 >= 678){

      *port &= 0b11110111;
      prevmillis4 = current4;
      
    }
  }

  //Pin 4
  if (((*port) & 0b00010000) == 0){
    
    if (current5 - prevmillis5 >= 534){

      *port |= 0b00010000;
      prevmillis5 = current5;
      
    }
    
  }

  else {

    if (current5 - prevmillis5 >= 342){

      *port &= 0b11101111;
      prevmillis5 = current5;
      
    }
  }

  //Pin 5
  if (((*port) & 0b00100000) == 0){
    
    if (current6 - prevmillis6 >= 326){

      *port |= 0b00100000;
      prevmillis6 = current6;
      
    }
    
  }

  else {

    if (current6 - prevmillis6 >= 1478){

      *port &= 0b11011111;
      prevmillis6 = current6;
      
    }
  }

  //Pin 6
  if (((*port) & 0b01000000) == 0){
    
    if (current7 - prevmillis7 >= 351){

      *port |= 0b01000000;
      prevmillis7 = current7;
      
    }
    
  }

  else {

    if (current7 - prevmillis7 >= 1859){

      *port &= 0b10111111;
      prevmillis7 = current7;
      
    }
  }

  //Pin 7
  if (((*port) & 0b10000000) == 0){
    
    if (current8 - prevmillis8 >= 888){

      *port |= 0b10000000;
      prevmillis8 = current8;
      
    }
    
  }

  else {

    if (current8 - prevmillis8 >= 777){

      *port &= 0b01111111;
      prevmillis8 = current8;
      
    }
  }

}
