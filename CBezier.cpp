#include "Headers/CBezier.h"


CBezier::CBezier()
{

}

void CBezier::creaP1(float x, float y, float z)
{
    p1.x = x;
    p1.y = y;
    p1.z = z;
}
void CBezier::creaP2(float x, float y, float z)
{
    p2.x = x;
    p2.y = y;
    p2.z = z;
}
void CBezier::creaP3(float x, float y, float z)
{
    p3.x = x;
    p3.y = y;
    p3.z = z;
}
void CBezier::creaP4(float x, float y, float z)
{
    p4.x = x;
    p4.y = y;
    p4.z = z;
}

Punto CBezier::dameP1()
{
    return p1;
}
Punto CBezier::dameP2()
{
    return p2;
}
Punto CBezier::dameP3()
{
    return p3;
}
Punto CBezier::dameP4()
{
    return p4;
}

float CBezier::obtenX(float t)
{
    return (pow((1-t),3)* this->dameP1().x) + 
            (3*t*pow((1-t),2)* this->dameP2().x) +
            (3 * pow(t,2)*(1-t)*this->dameP3().x ) +
            pow(t,3)* this->dameP4().x;
}
float CBezier::obtenY(float t)
{
    return (pow((1-t),3)* this->dameP1().y) + 
            (3*t*pow((1-t),2)* this->dameP2().y) +
            (3 * pow(t,2)*(1-t)*this->dameP3().y ) +
            pow(t,3)* this->dameP4().y;
}
float CBezier::obtenZ(float t)
{
    return (pow((1-t),3)* this->dameP1().z) + 
            (3*t*pow((1-t),2)* this->dameP2().z) +
            (3 * pow(t,2)*(1-t)*this->dameP3().z ) +
            pow(t,3)* this->dameP4().z;
}

