#define DIR 13
#define MS1 12
#define MS2 11
#define RST 10
#define SLEEP 9
#define EN 8
#define STEP 7

#define CLOCKWISE HIGH
#define COUNTERCLOCKWISE LOW


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
void kierros(){
  digitalWrite(DIR,COUNTERCLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
void kierross(){
  digitalWrite(DIR, CLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++){
    step();
  }
}
#define stepsPerRevolution 100
void puol(){
  digitalWrite(DIR,COUNTERCLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
void puoll(){
  digitalWrite(DIR,CLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
#define stepsPerRevolution 50
void vartti(){
  digitalWrite(DIR,COUNTERCLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
void varttii(){
  digitalWrite(DIR,CLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
#define stepsPerRevolution 300
void puolt(){
  digitalWrite(DIR,COUNTERCLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
}
void puoltt(){
  digitalWrite(DIR,CLOCKWISE);
  for (int i = 0; i < stepsPerRevolution; i++) {
    step();  
  }
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
      case 'k':kierros();break;
      case 'l':kierross();break;
      case 'j':puol();break;
      case 'h':puoll();break;
      case 'g':vartti();break;
      case 'f':varttii();break;
      case 'n':puolt();break;
      case 'm':puoltt();break;
      case 'p':Serial.print("waitHigh :");
      Serial.print(waitHigh);
      Serial.print("  waitLow :");
      Serial.println(waitLow);
      break;
    }
  }
 

}
