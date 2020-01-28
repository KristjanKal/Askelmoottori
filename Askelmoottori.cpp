#include <Arduino.h>
#include "Askelmoottori.h"


askelmoottori::askelmoottori (int DIR, int MS1, int MS2, int RST, int SLEEP, int EN, int STEP){
  _DIR = DIR;
  pinMode(_DIR, OUTPUT);
  _MS1 = MS1;
  pinMode(_MS1, OUTPUT);
  _MS2 = MS2;
  pinMode(_MS2, OUTPUT);
  _RST = RST;
  pinMode(_RST, OUTPUT);
  _SLEEP = SLEEP;
  pinMode(_SLEEP, OUTPUT);
  _EN = EN;
  pinMode(_EN, OUTPUT);
  _STEP = STEP;
  pinMode(_STEP, OUTPUT);

  digitalWrite(_EN, LOW);
  digitalWrite(_RST, HIGH);
  digitalWrite(_SLEEP, HIGH);
  
}  

void askelmoottori::CW(){
  digitalWrite(_DIR, CLOCKWISE);
}

void askelmoottori::CCW(){
  digitalWrite(_DIR, COUNTERCLOCKWISE);
}   

void askelmoottori::aja(){
  for (int i = 0; i < stepsPerRevolution; i++) {
    _oneStep();  
  }
}
void askelmoottori::_oneStep(){
    digitalWrite(_STEP, LOW);
    delayMicroseconds(waitHigh);
    digitalWrite(_STEP, HIGH);
    delayMicroseconds(waitLow);
}
void askelmoottori::fullStep(){
  digitalWrite(_MS1, LOW);
  digitalWrite(_MS2, LOW);
}
void askelmoottori::halfStep(){
  digitalWrite(_MS1, HIGH);
  digitalWrite(_MS2, LOW);
}
void askelmoottori::quarterStep(){
  digitalWrite(_MS1, LOW);
  digitalWrite(_MS2, HIGH);
}
