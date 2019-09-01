#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <string>

using namespace std;

class CArchivo{
    private:
        string nombreArchivo;
    public:
        CArchivo(string nombre);
        string setNombre();
        
        

};

#endif