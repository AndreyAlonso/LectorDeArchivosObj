#include "Headers/CCara.h"

/**
 * Constructor de la clase CCara
 * @vertices    Lista de int donde que contiene los vertices
 * 
 **/
CCara::CCara(list<long> vertices)
{
    this->vertices = vertices;
}


/**
 * Destructor de la clase CCara
 **/
CCara::~CCara()
{
    vertices.empty();
}

/**
 * Metodo VERTICES()
 * @return   lista de vertices int
 */
list<long> CCara::VERTICES()
{
    return vertices;
}

string CCara::muestraCara()
{
    string dato = "";
    for(long i: vertices)
        dato +=  to_string(i) + " ";
    return dato;
}