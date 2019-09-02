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
 * @param: archivo :    nombre del archivo 
 * @param: c:           caracter donde se realiza la separacion de la cadena
 * 
 * Se recorre el nombre de archivo, caracter por caracter hasta encontrar el deseado.
 * regresa todo lo que contiene la cadena despues del caracter encontrado
 */
string CArchivo::Split(string archivo, char c)
{
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