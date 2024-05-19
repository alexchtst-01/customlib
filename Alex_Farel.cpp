#include "Alex_Farel.h"

void attachPin(int ledDANGER, int ledSAFE, int ledWARNING, int Echo, int Triger)
{
    pinMode(ledDANGER, OUTPUT);
    pinMode(ledWARNING, OUTPUT);
    pinMode(ledSAFE, OUTPUT);
    pinMode(Triger, OUTPUT);
    pinMode(Echo, INPUT);
};

long measureDist(int Echo, int Triger)
{
    long cm, duration;

    digitalWrite(Triger, LOW);
    delayMicroseconds(2);
    digitalWrite(Triger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triger, LOW);

    duration = pulseIn(Echo, HIGH);
    // simplify
    cm = duration / 29 / 2;

    return cm;
};

void indicateDist(int ledDANGER, int ledSAFE, int ledWARNING, long cm)
{
    if (cm < 15)
    {
        digitalWrite(ledDANGER, HIGH);
        digitalWrite(ledSAFE, LOW);
        digitalWrite(ledWARNING, LOW);
        delay(200);
    }
    else if (cm >= 15 && cm < 40)
    {
        digitalWrite(ledSAFE, LOW);
        digitalWrite(ledWARNING, HIGH);
        digitalWrite(ledDANGER, LOW);
        delay(200);
    }
    else
    {
        digitalWrite(ledSAFE, HIGH);
        digitalWrite(ledWARNING, LOW);
        digitalWrite(ledDANGER, LOW);
        delay(200);
    }
};