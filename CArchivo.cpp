#include "Headers/CArchivo.h"

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
 * Metodo setNombre()
 * Envia el nombre del archivo aplicado en la encapsulacion
 */
string CArchivo::setNombre()
{
    return nombreArchivo;
}

/*
 *  Metodo ValidaArchivo()
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

/**
 * Metodo abreArchivo
 * 1. Verifica que el archivo existe en el directorio
 * 2. Si existe, entonces lo abre
 **/
int CArchivo::abreArchivo()
{
    ifstream archivo;
    archivo.open(nombreArchivo);
    string renglon;
    if(archivo.fail())
    {
        cout << "ERROR: No se pudo abrir el archivo "<< endl;
        return -1;
    }
    else{
       while(!archivo.eof()) //Ciclo mientras no encuentre final del archivo
       {
            getline(archivo,renglon); //Obtiene toda la linea del archivo hasta \n
            capturaVertices(renglon);   
            //cout << renglon << endl;
       }
    }
    archivo.close();
}
/**
 * Metodo capturaVertices()
 * @renglon:    Linea obtenida del archivo
 * Lee el archivo y va guardando en una lista de vertices
 * los vertices  obtenidos del archivo.
 */
void CArchivo::capturaVertices(string renglon)
{
    CVertice *vertice;
    switch(renglon[0])
    {
        case 'o':
            cout << "OBJETO: " << renglon << endl;
        break;
        case 'v':
            cout << "VERTICE: " << renglon << endl;
            separaRenglon(renglon);

        break;
        case 'f':
            cout << "CARA: " << renglon << endl;
        break;
        default:
            cout << "NO ES NINGUNO" << endl;

    }

}

/**
 * Metodo separaRenglon(string Renglon)
 * @renglon:    renglon obtenido del Archivo
 * Se obtienen las coordenadas x, y, z y se 
 * guardan en una lista 
 */
void CArchivo::separaRenglon(string renglon)
{
    int i;
    string dato = ""; 
    float pos;
    list<float> coordenadas;
    for(i = 0; i < renglon.length(); i++)
    {
        if(renglon[i] != 'v')
        {
            if(renglon[i] != ' ')
            {   
                dato += renglon[i];
            }
            else if(renglon[i] == ' ' && dato != "")
            {
                pos = stof(dato);
                coordenadas.insert(coordenadas.end(),pos);
                dato = "";
            }           
        }
        
    }
    if(!dato.empty()) //Si el dato no esta vacio, se agrega a la lista de coordenadas
    {
        pos = stof(dato);
        coordenadas.insert(coordenadas.end(),pos);
    }    
    cout << "\n\nLISTA DE VERTICES" << endl;
    for(float f: coordenadas)
        cout << f << endl;
}