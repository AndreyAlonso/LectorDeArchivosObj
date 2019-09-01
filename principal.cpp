#include "CArchivo.cpp" //Clase CArchivo

#include <iostream>
#include <string> 

using namespace std;



int main()
{
    cout << "\nMain en C++" << endl;
    /*Se declara el objeto de tipo CArchivo*/
    CArchivo archivo("Archivo.obj");
    cout << "El nombre del archivo es: \t " << archivo.setNombre() << endl;
    return 0;
}
