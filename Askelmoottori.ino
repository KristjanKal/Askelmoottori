#include "Askelmoottori.h"
#define DIR 13
#define MS1 12
#define MS2 11
#define RST 10
#define SLEEP 9
#define EN 8
#define STEP 7

#define CLOCKWISE HIGH
#define COUNTERCLOCKWISE LOW

int dir=CLOCKWISE;
void setup() {
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  pinMode(RST, OUTPUT);
  digitalWrite(RST, HIGH);
  pinMode(SLEEP, OUTPUT);
  digitalWrite(SLEEP, HIGH);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  fullStep();
  Serial.begin(9600);

  
}

void fullStep(){
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
}
void halfStep(){
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
}
void quarterStep(){
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, HIGH);
}
#define stepsPerRevolution 200
void _kierros(){
  dir=COUNTERCLOCKWISE;
  digitalWrite(DIR, dir);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
void _kierroscounter(){
  dir=CLOCKWISE;
  digitalWrite(DIR, dir);
  for (int i = 0; i < stepsPerRevolution; i++){
    step();
  }
}

void _aja(){
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}

void _suunta(){
  if(dir == CLOCKWISE){
    dir=COUNTERCLOCKWISE;
  }else{
    dir=CLOCKWISE;
  }
  digitalWrite(DIR,dir);
}


int waitHigh=1800, waitLow=1800;

void step(){
    digitalWrite(STEP, LOW);
    delayMicroseconds(waitHigh);
    digitalWrite(STEP, HIGH);
    delayMicroseconds(waitLow);
}

void loop() {
  if(Serial.available()>0){
    int c = Serial.read();
    switch(c){
      case 'q':waitHigh=waitHigh+100;break;
      case 'a':waitHigh=waitHigh-100;break;
      case 'w':waitHigh=waitLow+100;break;
      case 's':waitHigh=waitLow-100;break;
      case 'k':_kierros();break;
      case 'l':_kierroscounter();break;
      case 'm':_suunta();break;
      case 'n':_aja();break;
      case 'p':Serial.print("waitHigh :");
      Serial.print(waitHigh);
      Serial.print("  waitLow :");
      Serial.println(waitLow);
      break;
    }
  }
 

}
