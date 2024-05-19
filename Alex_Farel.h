#ifndef Alex_Farel_h
#define Alex_Farel_h

#include <Arduino.h>

void attachPin(int ledDANGER, int ledSAFE, int ledWARNING, int Echo, int Triger);
long measureDist(int Echo, int Triger);
void indicateDist(int ledDANGER, int ledSAFE, int ledWARNING, long cm);

#endif