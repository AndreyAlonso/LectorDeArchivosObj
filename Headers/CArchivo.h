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
        list<CVertice> vertices, vertices2;
        list<CCara> faces, faces2;
        CGrafico grafo;
        CGrafico pistaPatinaje;
    public:
        CArchivo(string nombre);
        string setNombre();
        string Split(string cadena, char c);
        bool validaArchivo();
        long abreArchivo();
        long abreArchivoEscenario(string escenario);
        void capturaVertices(string renglon);
        void capturaVerticesEscenario(string renglon);
        list<float> separaRenglon(string renglon);
        list<long> obtenCara(string renglon);
        CGrafico setGrafico();
        CGrafico setEscenario();
};

#endif