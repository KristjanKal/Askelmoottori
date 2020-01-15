#include <Arduino.h>
#include "Askelmoottori.h"


askelmoottori(int aja, int suunta);{
  
  pinMode(STEP, OUTPUT);
  _aja = aja;
  pinMode(DIR, OUTPUT);
  _suunta=suunta;
};
