/***********************************************************************************************
 * Proyecto:    Lector de Archivos WaveFront (.obj)
 * Fecha:       01/09/2019
 * Autor:       Hector Andrey Hernandez Alonso
 * Clases:      CArchivo, CCara, CVertice, CGrafico
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
    cout << "Escriba el nombre del archivo: ";
    cin >> nArchivo;
    if(nArchivo != "" || nArchivo != " ")
        return true;
    else
        return false;
}

void menu(int argc, char* argv[])
{
    int opcion;
    do
    {
        //system("clear");
        encabezado();
        cout << "Seleccione una opcion" << endl;
        cout << "1) Leer archivo" << endl;
        cout << "2) Muestra archivos directorio" << endl;
        cout << "3) Salir" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Opcion = ";
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                system("clear");
                if(pideArchivo())
                {
                    CArchivo archivo(nArchivo);//Creacion de objeto de la clase CArchivo
                    if(archivo.validaArchivo())
                    {
                        cout << "El archivo si tiene extension .obj" << endl;
                        if(archivo.abreArchivo() != -1)
                        {
                            archivo.setGrafico().pinta(argc,argv);
                            cout << "hasta ahora todo bien";
                        }
                    }
                    else{
                        system("clear");
                        cout << "ERROR: No se puede abrir el archivo: " << archivo.setNombre() 
                        << "\ndebe ser de tipo .obj\n" << endl;
                    }
                }
                else
                    cout << "ERROR";
            break;
            case 2:
                system("clear");
                cout << "Archivos en el directorio: \n" << endl;
                system("ls -1 *.obj");
                cout << "\n" << endl;
            break;
            default:
                opcion = 3;
                
        }
        
    }while(opcion != 3);
}

/*Encabezado del programa ejecutable*/
void encabezado()
{
    cout << "-------------------------------------------------";
    cout << "\n\tLECTOR DE ARCHIVOS WAVEFRAME\t (.obj)" << endl;
    cout << "-------------------------------------------------" << endl;
}
/*Pie de pagina del programa ejecutable*/
void pie()
{
    cout << "\n-------------------------------------------------" << endl;
}