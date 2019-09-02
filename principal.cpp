#include "CArchivo.cpp" //Clase CArchivo

#include <iostream>
#include <string> 

using namespace std;

/*  Prototipos de las funciones */
void encabezado();
void pie();


int main()
{
    encabezado();

    CArchivo archivo("Archivo.obj");//Creacion de objeto de la clase CArchivo

    if(archivo.validaArchivo())
    {
        cout << "El archivo si tiene extension .obj" << endl;
    }
    else{
        cout << "ERROR: No se puede abrir el archivo: " << archivo.setNombre() 
        << "\ndebe ser de tipo .obj" << endl;

    }
    pie();
    return 0;
}

/*Encabezado del programa ejecutable*/
void encabezado()
{
    cout << "-------------------------------------------------" ;
    cout << "\n\tLECTOR DE ARCHIVOS WAVEFRAME\t (.obj)" << endl;
    cout << "-------------------------------------------------\n" << endl;
}
/*Pie de pagina del programa ejecutable*/
void pie()
{
    cout << "\n----------------------------------------" << endl;
}