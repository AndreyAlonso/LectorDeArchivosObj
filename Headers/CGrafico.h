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

#define PI 3.14159265

/*Variables Globables*/

long TAM;
long TAM2;

double rotate_y=0;  //Rotar la figura en Y
double rotate_x=0;  //Rotar la figura en X
CBezier b1,b2,b3;   //Curvas bezier
double t = 0;       //Variable auxiliar para realizacion del bezier
list<CVertice> v;   //Lista global de los vertices obtenidos del archivo obj
list<CCara> c;      //Lista global de las caras obtenidas del archivo oj
list<Punto> lCurva; //Lista global que contiene los puntos (x,y,z) del bezier
CVertice* array;    //Arreglo de vertices //CVertice array[10000];
CVertice* pista;
Punto pivote;       //Punto pivote de la figura 
bool bandera = true;
list<CVertice> vEscenario;
list<CCara> cEscenario;
list<CVertice> copia;
/*  Iluminacion */
float LightPos[] = { 1.0f, 1.0f, 0.0f, 0.0f};   // Light Position
float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f};   // Ambient Light Values
float LightDif[] = { 1.0f, 1.0f, 1.0f, 1.0f};   // Diffuse Light Values
float LightSpc[] = { 1.0f, 1.0f, 1.0f, 1.0f};   // Specular Light Values

void specialKeys( int key, int x, int y ) ;
/* Prototipos de funciones externas a la clase CGrafico */
void display();
void recorreBezier();
void pintaBezier();
void pintaFigura();
void traslacionOrigen();
void dameVertices(list<CVertice> vertices);
CVertice multMatriz4x1(CVertice punto,Punto p);
Punto rotacionX(float angulo, Punto actual);
void rotacion();
Punto damePivote();
void calculaNormales();
void calculaNormalesEscenario();
void imprimeNormales();
void pintaEscenario();

class CGrafico{
    private:
        list<CCara> caras;          // Lista de los vertices del archivo obj
        list<CVertice> vertices;    // Lista de las caras del archivo obj
        list<Punto> curva;          // Contiene todos los puntos(x,y,z) del bezier
    public:
        CGrafico();                 //Constructor
        void dameVertices(list<CVertice> vertices);
        void dameVerticesEscenario(list<CVertice> vertices);
        void dameCaras(list<CCara> caras);
        void pinta(int argc, char* argv[],CGrafico escenario);
        
        void generaBezier();
        
};

#endif