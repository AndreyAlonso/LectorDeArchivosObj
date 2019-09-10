#ifndef CCARA_H
#define CCARA_H
#include <iostream>
#include "CVertice.h"
#include <list>
#include <string>

using namespace std;

class CCara{
    private:
        list<int> vertices;
    public:
        CCara(list<int> vertices);
        list<int> VERTICES();
        string muestraCara();
        ~CCara();
};

#endif