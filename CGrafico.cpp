#include "Headers/CGrafico.h"
#include "CBezier.cpp"
/****************************************************
 * CGrafico()
 * Constructor de la clase CGrafico
 * Se inicializan los puntos pivote para el bezier
 ****************************************************/
CGrafico::CGrafico()
{
        // b1.creaP1(0.0,0.0,0.0);
    // b1.creaP2(0.0,0.2,0.0);
    // b1.creaP3(10.2,0.2,0.0);
    // b1.creaP4(20.2,0.0,0.0);

    // b2.creaP1(b1.dameP4().x,b1.dameP4().y,b1.dameP4().z);
    // b2.creaP2(0.2,-0.2,0.0);
    // b2.creaP3(0.4,-0.2,0.0);
    // b2.creaP4(0.4,0.0,0.0);

    // b3.creaP1(b2.dameP4().x,b2.dameP4().y,b2.dameP4().z);
    // b3.creaP2(0.4,0.2,0.0);
    // b3.creaP3(50.6,0.2,0.0);
    // b3.creaP4(100.6,0.0,0.0);


  b1.creaP1(0.0,0.0,0.0);
  b1.creaP2(0.0,0.2,0.0);
  b1.creaP3(0.2,0.2,0.0);
  b1.creaP4(0.4,0.0,0.0);

  // b2.creaP1(b1.dameP4().x,b1.dameP4().y,b1.dameP4().z);
  // b2.creaP2(0.2,-0.2,0.0);
  // b2.creaP3(0.4,-0.2,0.0);
  // b2.creaP4(0.4,0.0,0.0);

  // b3.creaP1(b2.dameP4().x,b2.dameP4().y,b2.dameP4().z);
  // b3.creaP2(0.4,0.2,0.0);
  // b3.creaP3(0.6,0.2,0.0);
  // b3.creaP4(0.6,0.0,0.0);

  //Una vez obtenidos los puntos pivote para el bezier, se procede a generar la curva
  generaBezier();

  lCurva = curva;
}
/**
 * Metodo dameVertices(list<CVertice> vertices)
 * @vertices: lista de vertices obtenidas del archivo
 */
void CGrafico::dameVertices(list<CVertice> vertices)
{
  int j = 1;
  this->vertices = vertices;
  //array[vertices.size()];
  array = (CVertice*)malloc(sizeof(CVertice)*(vertices.size()+1));
  for(CVertice cv: vertices)   //Se guarda en un arreglo los vertices para poder pintarlos
    array[j++] = cv; 
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
  
  
  glColor3f( 1.0, 0.0, 1.0 );
  for(CCara cc: c)
  {
    glBegin(GL_POLYGON);
    for(int i: cc.VERTICES())
      glVertex3f(array[i].x,array[i].y,array[i].z);  
    glEnd();
  }
  
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
 * Metodo generaBezier()
 * 
 * Se realiza la curva Bezier.
 * Cada punto de la curva se guarda en la lista "curva"
 */
void CGrafico::generaBezier()
{
  t = 0.0;
  Punto p;
  while(t <= 1) // Ciclo de la primera curva
  {
    p.x = b1.obtenX(t);
    p.y = b1.obtenY(t);
    p.z = b1.obtenZ(t);

    curva.insert(curva.end(),p);
    t += 0.006;
  }
  // t = 0.0;
  // while(t <= 1) // Ciclo de la segunda curva
  // {
  //   p.x = b2.obtenX(t);
  //   p.y = b2.obtenY(t);
  //   p.z = b2.obtenZ(t);

  //   curva.insert(curva.end(),p);
  //   t += 0.01;
  // }
  // t = 0.0;
  // while(t <= 1) // Ciclo de la tercer curva
  // {
  //   p.x = b3.obtenX(t);
  //   p.y = b3.obtenY(t);
  //   p.z = b3.obtenZ(t);

  //   curva.insert(curva.end(),p);
  //   t += 0.01;
  // }
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