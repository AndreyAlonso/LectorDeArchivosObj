#ifndef CBEZIER_H
#define CBEZIER_H
#include "Punto.h"
#include "math.h"

class CBezier
{
    private:
        Punto p1, p2,p3,p4;
        float t;
    public:
        CBezier();
        void creaP1(float x,float y,float z);
        void creaP2(float x,float y,float z);
        void creaP3(float x,float y,float z);
        void creaP4(float x,float y,float z);
        float obtenX(float t);
        float obtenY(float t);
        float obtenZ(float t);
        Punto dameP1();
        Punto dameP2();
        Punto dameP3();
        Punto dameP4();
};




#endif