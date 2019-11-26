#ifndef CCARA_H
#define CCARA_H
#include <iostream>
#include "CVertice.h"
#include "CBezier.h"
#include <list>
#include <string>

using namespace std;

class CCara{
    private:
        list<long> vertices;
    public:
        CCara(list<long> vertices);
        Punto N;       // Normal del vertice
        list<long> VERTICES();
        string muestraCara();
        ~CCara();
};

#endif