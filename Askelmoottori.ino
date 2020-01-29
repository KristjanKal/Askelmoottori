#include "Askelmoottori.h"
#define DIR 13
#define MS1 12
#define MS2 11
#define RST 10
#define SLEEP 9
#define EN 8
#define STEP 7


askelmoottori motor1(13, 12, 11, 10, 9, 8, 7); //PINNIT mihin askelmoottori on kytketty arduino levyl
askelmoottori motor2(24, 26, 28, 30, 32, 34, 36); //PINNIT mihin askelmoottori on kytketty arduino levyl

void setup() {
 Serial.begin(9600);
}


void loop(){
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep(); 
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep();
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep(); 
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep();
  motor2.CW();
  motor2.aja();
  motor1.fullStep();
  motor1.CCW();
  motor1.aja();
  motor2.fullStep(); 
  motor2.CCW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep(); 
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep();
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep(); 
  motor2.CW();
  motor2.aja();
  motor1.quarterStep();
  motor1.CW();
  motor1.aja();
  motor2.quarterStep();
  motor2.CW();
  motor2.aja();
  motor1.fullStep();
  motor1.CW();
  motor1.aja();
  motor2.fullStep(); 
  motor2.CW();
  motor2.aja();
  motor1.halfStep();
  motor1.CCW();
  motor1.aja();
  motor2.halfStep();
  motor2.CCW();
  motor2.aja();
}

/*

void loop() {
  if(Serial.available()>0){
    int c = Serial.read();
    switch(c){
      case 'q':waitHigh=waitHigh+100;break;
      case 'a':waitHigh=waitHigh-100;break;
      case 'w':waitHigh=waitLow+100;break;
      case 's':waitHigh=waitLow-100;break;
      case 'k':_kierros();break;
      case 'l':_counterkierros();break;
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
*/
