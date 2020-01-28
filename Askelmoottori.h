#ifndef Askelmoottori_h
#define Askelmoottori_h
#include <Arduino.h>

#define stepsPerRevolution 200
#define CLOCKWISE HIGH
#define COUNTERCLOCKWISE LOW
#define waitHigh 1800
#define waitLow 1800

class askelmoottori{
  public:
    askelmoottori(int DIR, int MS1, int MS2, int RST, int SLEEP, int EN, int STEP);
    void CW();
    void CCW();
    void aja();
    void fullStep();
    void halfStep();
    void quarterStep();     
  private:
    int _DIR;
    int _MS1;
    int _MS2;
    int _RST;
    int _SLEEP;
    int _EN;
    int _STEP; 
    void _oneStep();  
};
  

#endif
