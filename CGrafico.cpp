#include "Headers/CGrafico.h"
/****************************************************
 * CGrafico()
 * Constructor de la clase CGrafico
 * Se inicializa la lista de vertices
 ****************************************************/
CGrafico::CGrafico()
{
    
}
/**
 * Metodo dameVertices(list<CVertice> vertices)
 * @vertices: lista de vertices obtenidas del archivo
 */
void CGrafico::dameVertices(list<CVertice> vertices)
{
  long j = 0;
  this->vertices = vertices;
  //cout << "El tamaño de la lista es\t" << vertices.size() << endl;
  array = (CVertice*)malloc(sizeof(CVertice)*vertices.size()+1);
  //array[vertices.size()];
  for(CVertice cv: vertices)   //Se guarda en un arreglo los vertices para poder pintarlos
  { 
    array[j] = cv;
    j++;
  }
    

  cout << "valor final de j\t" << j << endl;
}

/**
 * Metodo dameCaras(list<Caras> caras)
 * @caras:  lista de caras obtenidas del archivo
 */
void CGrafico::dameCaras(list<CCara> caras)
{
    this->caras = caras;
}

/**
 * Metoodo muestraVertices()
 * Muestra en pantalla las coordenadas (x,y,z)  del vertice
 */
void CGrafico::muestraVertices()
{
    cout << "LOS VERTICES DEL GRAFO SON" << endl;
    for(CVertice v: vertices)
        cout << v.muestraCoordenada() << endl;
}
/**
 * Metodo muestraCaras()
 * Muestra en pantalla los vertices que tiene la cara
 */
void CGrafico::muestraCaras()
{
    cout << "LAS CARAS DEL GRAFO SON" << endl;
    for(CCara c: caras)
        cout << c.muestraCara() << endl;
}
/**
 * Funcion display()
 * Aqui se realiza el pintado de las figuras
 */
void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glViewport(0,0,250,250);
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 0.0, 1.0 );
  for(CCara cc: c)
  {
    for(long i: cc.VERTICES())
      glVertex3f(array[i].x,array[i].y,array[i].z);  
  }
  glEnd();
  glFlush();
  glutSwapBuffers();
}
/**
 * Metodo pinta(int argc, char *argv[])
 * Se crea la ventana de OpenGL
 * Se manda llamar a las funciones para interactuar con la ventana OpenGL
 */
void CGrafico::pinta(int argc, char* argv[])
{
    glutInit(&argc,argv);   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(400,0);
    glutInitWindowSize( 400, 400);
  
    glutCreateWindow("Lector de Archivos WaveFront (.obj)");
    //  Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    v = vertices; //Se guardan los vertices en una lista global
    c = caras;    //Se guardan las caras en una lista global

    glutDisplayFunc(display);     //Llamada a la funcion display()
    glutSpecialFunc(specialKeys); //Llamada a la funcion specialKey()
    glutMainLoop();

    
}

/**
 * Funcion specialKeys(int key, int x, int y)
 * @key:  tecla pulsada
 * @x:    coordenada en el eje x
 * @y:    coordenada en el eje y
 */
void specialKeys( int key, int x, int y ) {

  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();
  
 
}



/**
 * Destructor de la clase CGrafico
 * Se vacia el arreglo y las listas
 */
CGrafico::~CGrafico()
{
   // delete[] array ;
//  v.clear();
//  c.clear();
  cout << "DEsTRUCTOR" << endl;
}