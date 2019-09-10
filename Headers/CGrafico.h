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

double rotate_y=0; 
double rotate_x=0;


list<CVertice> v;
list<CCara> c;
void display();
void specialKeys( int key, int x, int y );

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