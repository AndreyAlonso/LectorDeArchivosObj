/**
 * Clase CGrafico
 * Relaciona los vertices con las caras para su uso posterior
 * en el pintado.
 **/
#ifndef CGRAFICO_H
#define CGRAFICO_H

#include <list>
#include "Headers/CVertice.h"

class CGrafico{
    private:
        list<CVertice> grafico;
        CVertice *vertice;  
    public:
        CGrafico();
}

#endif