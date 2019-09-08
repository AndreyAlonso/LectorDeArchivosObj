#include "CArchivo.h"

/*
 * Constructor de la Clase CArchivo
 * nombre -> nombre del arhivo dado por el usuario
 * Se envía el nombre dado por el usuario a la variable nombreArchivo.
 */
CArchivo::CArchivo(string nombre)
{
    nombreArchivo = nombre;
}

/*
 * Metodo setNombre
 * Envia el nombre del archivo aplicado en la encapsulacion
 */
string CArchivo::setNombre()
{
    return nombreArchivo;
}

/*
 *  Metodo ValidaArchivo
 *  Segun el archivo, se verifica que cumpla con el tipo .obj
 *  Si cumple regresa true y si no, false
 */
bool CArchivo::validaArchivo()
{
    if(Split(nombreArchivo, '.') ==  ".obj")
        return true;
    return false;
    
}

/*
 * Metodo Split()
 * @archivo :    nombre del archivo 
 * @c:           caracter donde se realiza la separacion de la cadena
 * 
 * Se recorre el nombre de archivo, caracter por caracter hasta encontrar el deseado.
 * Regresa todo lo que contiene la cadena despues del caracter encontrado
 */
string CArchivo::Split(string archivo, char c)
{
    cout << "Nombre" << archivo << endl;
    int i;
    bool band = false;
    string extension = "";
    for(i = 0; i < archivo.length(); i++)
    {
        if(archivo[i] == c)
            band = true;
        if(band)
            extension += archivo[i];
    }
    return extension;
}

/*************************************************************
 * Metodo abreArchivo
 * 1. Verifica que el archivo existe en el directorio
 * 2. Si existe, entonces lo abre
 *************************************************************/
int CArchivo::abreArchivo()
{
    ifstream archivo;
    archivo.open(nombreArchivo);
    if(archivo.fail())
    {
        cout << "ERROR: No se pudo abrir el archivo "<< endl;
        return -1;
    }
    archivo.close();
}