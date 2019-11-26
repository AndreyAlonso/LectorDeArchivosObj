#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>
#include "CVertice.h"
#include "CCara.h"
#include "CGrafico.h"
#include <list>

using namespace std;

class CArchivo{
    private:
        string nombreArchivo;
        list<CVertice> vertices;
        list<CCara> faces;
        CGrafico grafo;
    public:
        CArchivo(string nombre);
        string setNombre();
        string Split(string cadena, char c);
        bool validaArchivo();
        long abreArchivo();
        void capturaVertices(string renglon);
        list<float> separaRenglon(string renglon);
        list<long> obtenCara(string renglon);
        CGrafico setGrafico();
};

#endif