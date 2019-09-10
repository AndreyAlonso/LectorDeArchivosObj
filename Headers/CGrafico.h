/**
 * Clase CGrafico
 * Relaciona los vertices con las caras para su uso posterior
 * en el pintado.
 **/
#ifndef CGRAFICO_H
#define CGRAFICO_H

#include <list>
#include "CVertice.h"
#include <GL/glut.h>
#include "CCara.h"

list<CVertice> v;
void display();
class CGrafico{
    private:
       
        list<CCara> caras; 
        list<CVertice> vertices;
    public:
        CGrafico();
        
        void dameVertices(list<CVertice> vertices);
        void dameCaras(list<CCara> caras);
        void muestraVertices();
        void muestraCaras();
        void pinta(int argc, char* argv[]);
        
        
};

#endif