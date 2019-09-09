#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>
#include "CVertice.h"
#include <list>

using namespace std;

class CArchivo{
    private:
        string nombreArchivo;
        list<CVertice> vertices;
    public:
        CArchivo(string nombre);
        string setNombre();
        string Split(string cadena, char c);
        bool validaArchivo();
        int abreArchivo();
        void capturaVertices(string renglon);
        list<float> separaRenglon(string renglon);
};

#endif