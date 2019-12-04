/***********************************************************************************************
 * Proyecto:    Lector de Archivos WaveFront (.obj)
 * Fecha:       01/09/2019
 * Autor:       Hector Andrey Hernandez Alonso
 * Clases:      CArchivo, CCara, CVertice, CGrafico, CBezier
 ***********************************************************************************************/
#include "Headers/CArchivo.h" //Clase CArchivo
#include "CArchivo.cpp"
#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

/*Variable global*/
string nArchivo;

/*  Prototipos de las funciones */
void encabezado();
void menu(int argc, char* argv[]);
void pie();
bool pideArchivo();


int main(int argc, char* argv[])
{   
    system("clear");
    menu(argc,argv);
    pie();
    return 0;
}

bool pideArchivo(){
    encabezado();
    cout << "Escriba el nombre del archivo: ";
    cin >> nArchivo;
    if(nArchivo != "" || nArchivo != " ")
        return true;
    else
        return false;
}

void menu(int argc, char* argv[])
{

    CArchivo archivo("xwing.obj");
    if(archivo.abreArchivo() != -1){
        archivo.setGrafico().pinta(argc,argv,archivo.setEscenario());
    }
}

/*Encabezado del programa ejecutable*/
void encabezado()
{
    cout << "-------------------------------------------------";
    cout << "\n\tLECTOR DE ARCHIVOS WAVEFRONT\t (.obj)" << endl;
    cout << "-------------------------------------------------" << endl;
}
/*Pie de pagina del programa ejecutable*/
void pie()
{
    cout << "\n-------------------------------------------------" << endl;
}