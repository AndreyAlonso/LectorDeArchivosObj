#ifndef CCARA_H
#define CCARA_H
#include <iostream>
#include "CVertice.h"
#include <list>

class CCara{
    private:
        list<int> vertices;
    public:
        CCara(list<int> vertices);
};

#endif