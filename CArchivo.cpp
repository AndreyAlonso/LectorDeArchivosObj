#include "Headers/CArchivo.h"
#include "CVertice.cpp"
#include "CCara.cpp"
#include "CGrafico.cpp"
/*
 * Constructor de la Clase CArchivo
 * nombre -> nombre del arhivo dado por el usuario
 * Se envía el nombre dado por el usuario a la variable nombreArchivo.
 */
CArchivo::CArchivo(string nombre)
{
    nombreArchivo = "archivos/" + nombre;
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
    
    grafo.dameVertices(vertices);
    grafo.dameCaras(faces);
    //grafo.muestraVertices();
    //grafo.muestraCaras();
    //cout << "Se procede a pintar" << endl;
    
}
/**
 * Metodo capturaVertices()
 * @renglon:    Linea obtenida del archivo
 * return:      Lista de flotantes, se asignan al vertice
 * Lee el archivo y va guardando en una lista de vertices
 * los vertices  obtenidos del archivo.
 */
void CArchivo::capturaVertices(string renglon)
{
    list<float> puntos;
    list<int>   caras;
    CCara* objeto;
    float x,y,z;
    switch(renglon[0])
    {
        case 'o':
            //cout << "OBJETO: " << renglon << endl;
        break;
        case 'v':
        if(renglon[1] == ' ')
        {
            puntos = separaRenglon(renglon);
            x = puntos.front();
            puntos.pop_front();
            y = puntos.front();
            puntos.pop_front();
            z = puntos.front();
            puntos.pop_front();
            vertices.insert(vertices.end(),CVertice(x,y,z));
        }
            
        break;
        case 'f':
        if(renglon[1] == ' ')
        {
            caras = obtenCara(renglon);
            objeto = new CCara(caras);
            faces.insert(faces.end(),*objeto);
        }
            
        break;
       // default:
            //cout << "NO ES NINGUNO" << endl;
    }

}

/**
 * Metodo separaRenglon(string Renglon)
 * @renglon:    renglon obtenido del Archivo
 * Se obtienen las coordenadas x, y, z y se 
 * guardan en una lista 
 */
list<float> CArchivo::separaRenglon(string renglon)
{
    int i;
    string dato = ""; 
    float pos;
    string dd;
    list<float> coordenadas;    
    for(i = 0; i < renglon.length(); i++)
    {
        if(renglon[i] != 'v' && renglon[0] != '#' && renglon[i+1] != 'n'&& renglon[0] != 'm' && renglon[0] != 's')
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

    return coordenadas;
}
/**
 * Metodo obtenCara(string renglon)
 * @renglon:    renglon obtenido del archivo
 * return:  lista de los vertices obtenidos en una cara
 *
 **/
list<int> CArchivo::obtenCara(string renglon)
{
    int i;
    string dato = ""; 
    float pos;
    list<int> coordenadas;    
    for(i = 0; i < renglon.length(); i++)
    {
        if(renglon[i] != 'f' && renglon[0] != '#' && renglon[i+1] != 'n'&& renglon[0] != 'm' && renglon[0] != 's')
        {
            if(renglon[i] != ' ')
            {   
                dato += renglon[i];
            }
            else if(renglon[i] == ' ' && dato != "")
            {
                pos = stoi(dato);
                coordenadas.insert(coordenadas.end(),pos);
                dato = "";
            }           
        }
    }
    if(!dato.empty()) //Si el dato no esta vacio, se agrega a la lista de coordenadas
    {
        pos = stoi(dato);
        coordenadas.insert(coordenadas.end(),pos);
    }    
    return coordenadas;
}

CGrafico CArchivo::setGrafico()
{
    return grafo;
}