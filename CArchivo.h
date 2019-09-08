#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CArchivo{
    private:
        string nombreArchivo;
    public:
        CArchivo(string nombre);
        string setNombre();
        string Split(string cadena, char c);
        bool validaArchivo();
        int abreArchivo();
        
        

};

#endif