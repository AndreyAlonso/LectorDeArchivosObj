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
#include "CBezier.h"
#include "math.h"

/*Variables Globables*/
double rotate_y=0;  //Rotar la figura en Y
double rotate_x=0;  //Rotar la figura en X
CBezier b1,b2,b3;   //Curvas bezier
double t = 0;        //Variable auxiliar para realizacion del bezier
list<CVertice> v;   //Lista global de los vertices obtenidos del archivo obj
list<CCara> c;      //Lista global de las caras obtenidas del archivo oj
list<Punto> lCurva; //Lista global que contiene los puntos (x,y,z) del bezier
CVertice* array;    //Arreglo de vertices //CVertice array[10000];
Punto pivote;       //Punto pivote de la figura 
/* Prototipos de funciones externas a la clase CGrafico */
void display();
void specialKeys( int key, int x, int y );
void recorreBezier();
void pintaBezier();
void pintaFigura();
void traslacionOrigen();
void dameVertices(list<CVertice> vertices);
CVertice  multMatriz4x1(CVertice punto,Punto p);
bool existeEnLista(list<int> lista, int busca);

Punto damePivote(Punto p);
Punto damePivote();

class CGrafico{
    private:
        list<CCara> caras;          // Lista de los vertices del archivo obj
        list<CVertice> vertices;    // Lista de las caras del archivo obj
        list<Punto> curva;          // Contiene todos los puntos(x,y,z) del bezier
    public:
        CGrafico();     //Constructor
        ~CGrafico();    //Destructor
        void dameVertices(list<CVertice> vertices);
        void dameCaras(list<CCara> caras);
        void muestraVertices();
        void muestraCaras();
        void pinta(int argc, char* argv[]);
        void generaBezier();
        
};

#endif