#include "Headers/CCara.h"

/**
 * Constructor de la clase CCara
 * @vertices    Lista de int donde que contiene los vertices
 * 
 **/
CCara::CCara(list<int> vertices)
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
 * return   lista de vertices
 */
list<int> CCara::VERTICES()
{
    return vertices;
}

string CCara::muestraCara()
{
    string dato = "";
    for(int i: vertices)
        dato +=  to_string(i) + " ";
    return dato;
}