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

string CArchivo::setNombre()
{
    return nombreArchivo;
}