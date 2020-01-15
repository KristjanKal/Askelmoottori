#ifndef Askelmoottori_h
#define Askelmoottori_h
#include <Arduino.h>

#define DIR 13
#define MS1 12
#define MS2 11
#define RST 10
#define SLEEP 9
#define EN 8
#define STEP 7

#define CLOCKWISE HIGH
#define COUNTERCLOCKWISE LOW


class askelmoottori {
  public:
  askelmoottori(int aja, int suunta);
  private:
  int _aja;
  int _suunta;
};
  

#endif
