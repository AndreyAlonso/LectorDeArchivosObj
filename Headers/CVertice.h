#ifndef CVERTICE_H
#define CVERTICE_H

#include <string>
using namespace std;
class CVertice
{
    private:
        
    public:
        CVertice(float x, float y, float z);
        CVertice();
        string muestraCoordenada();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        float x, y, z; //Coordenadas del vertice
        


};


#endif  