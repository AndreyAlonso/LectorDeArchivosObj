#ifndef CCARA_H
#define CCARA_H
#include <iostream>
#include "CVertice.h"
#include <list>
#include <string>

using namespace std;

class CCara{
    private:
        list<long> vertices;
    public:
        CCara(list<long> vertices);
        list<long> VERTICES();
        string muestraCara();
        ~CCara();
};

#endif