#include "Headers/CVertice.h"

/************************************************
 * CVertice()
 * Constructor de la clase CVertice
 * @x   Posicion en eje X
 * @y   Posicion en eje Y
 * @z   Posicion en eje Z
 ************************************************/ 
CVertice::CVertice(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

CVertice::CVertice()
{
    //cout << "\t\tDENTRO DEconstructor" << endl;
}
/*******************
 *******************/
void CVertice::setX(float x)
{
    this->x = x;
}

void CVertice::setY(float y)
{
    this->y = y;
}
void CVertice::setZ(float z)
{
    this->z = z;
}
string CVertice::muestraCoordenada()
{
    return "V: {" + to_string(this->x) + ", "  + to_string(y) + ", " + to_string(z) + "}"; 
}