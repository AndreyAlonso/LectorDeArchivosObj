/***********************************************************************************************
 * Proyecto:    Lector de Archivos WaveFrame (.obj)
 * Fecha:       01/09/2019
 * Autor:       Hector Andrey Hernandez Alonso
 ***********************************************************************************************/
#include "CArchivo.cpp" //Clase CArchivo

#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

/*Variable global*/

string nArchivo;
/*  Prototipos de las funciones */
void encabezado();
void pie();
bool pideArchivo();


int main()
{
    encabezado();
    if(pideArchivo())
    {

        CArchivo archivo(nArchivo);//Creacion de objeto de la clase CArchivo

        if(archivo.validaArchivo())
        {
            cout << "El archivo si tiene extension .obj" << endl;
            if(archivo.abreArchivo() != -1)
            {
                cout << "hasta ahora todo bien";
            }
        }
        else{
            cout << "ERROR: No se puede abrir el archivo: " << archivo.setNombre() 
            << "\ndebe ser de tipo .obj" << endl;

        }
        
        
    }
    else
        cout << "ERROR";
    
    pie();
    return 0;
}

bool pideArchivo(){
    cout << "Escriba el nombre del archivo: ";
    cin >> nArchivo;
    if(nArchivo != "" || nArchivo != " ")
        return true;
    else
        return false;
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