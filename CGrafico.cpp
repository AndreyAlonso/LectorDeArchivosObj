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


  b1.creaP1(  0.497f,0.496f, 0.0f );
  b1.creaP2(  0.546f,-0.965f, 0.0f );
  b1.creaP3(  -0.01f,-1.03f, 0.0f );
  b1.creaP4(  0.001f, -0.808f, 0.0f );

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
  long j = 1;
  this->vertices = vertices;
  //array[vertices.size()];
  array = (CVertice*)malloc(sizeof(CVertice)*(vertices.size()+1));
  for(CVertice cv: vertices)   //Se guarda en un arreglo los vertices para poder pintarlos
    array[j++] = cv; 
  
  TAM = j;
  
}

void dameVertices(list<CVertice> vertices)
{
  long j = 1;
  v = vertices;
  //array[vertices.size()];
  array = (CVertice*)malloc(sizeof(CVertice)*(vertices.size()+1));
  for(CVertice cv: v)   //Se guarda en un arreglo los vertices para poder pintarlos
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
 *  Funcion calculaNormales()
 *  Se recorre la lista de las caras de la figura
 *  y se obtiene el vector normal
 *  
 */
void calculaNormales()
{

  list<CCara> temp;
  CVertice  p1,p2,p3, P,Q,N;
  GLfloat modulo;
  int i;
  for(CCara face : c){
    i = 0;
    modulo = 0;
    for(int pos: face.VERTICES()){
      switch(i){
        case 1:
          p1 = array[pos];
        break;
        case 2:
          p2 = array[pos];
        break;
        case 3:
          p3 = array[pos];
        break;
      }
      i++;

    }
    P.x = p2.x - p1.x;
    P.y = p2.y - p1.y;
    P.z = p2.z - p1.z;

    Q.x = p3.x - p1.x;
    Q.y = p3.y - p1.y;
    Q.z = p3.z - p1.z;

    N.x = (P.y * Q.z) - (P.z * Q.y);
    N.y = (P.z * Q.x) - (P.x * Q.z);
    N.z = (P.x * Q.y) - (P.y * Q.x);

    modulo = sqrt(pow(N.x,2) + pow(N.y,2) + pow(N.z,2));
    if( modulo != 0)
    {
      
      face.N.x = N.x/modulo;
      face.N.y = N.y/modulo;
      face.N.z = N.z/modulo;
      temp.insert(temp.end(),face);
    }
  }
  c = temp;
  // imprimeNormales();

}

void imprimeNormales()
{
 for(CCara face : c){
    cout << "vn:\t" << face.N.x << " \t\t" << face.N.y << " \t\t" << face.N.z << endl;
 } 
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
bool bandera = true;
/**
 * Funcion display()
 * Aqui se realiza el pintado de las figuras
 */
void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
   glLightfv(GL_LIGHT0, GL_POSITION, LightPos);        // Set Light1 Position
 glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);         // Set Light1 Ambience
 glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);         // Set Light1 Diffuse
 glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpc);        // Set Light1 Specular
 glEnable(GL_LIGHT0);                                // Enable Light1
 glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

  // glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  // glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  // glViewport(0,0,250,250);
  if(bandera)
  {
    //  pintaBezier();
      recorreBezier();
      bandera = false;
  }
  glFlush();
  glutSwapBuffers();
}
/**
 * Funcion pintaBezier()
 * Se recorre el bezier punto por punto
 * y se muestra en pantalla
 */
void pintaBezier()
{
  for(Punto bezier: lCurva)
  {
    glBegin(GL_POINTS);
    glVertex3f(bezier.x,bezier.y,bezier.z);
    glEnd();
  }
  
}

Punto rotacionX(float angulo, Punto actual)
{
  float aSen, aCos;
  Punto nuevo;
  aSen = sin(angulo*PI/180); 
  aCos = cos(angulo*PI/180);
  nuevo.y = actual.y * aCos - actual.z*aSen;
  nuevo.z = actual.y * aSen + actual.z*aCos;
  nuevo.x = actual.x;
  return nuevo;
  
}
void pintaFigura()
{
  GLfloat mat_ambient[] = { 0.04f, 0.28f, 0.36f, 1.0f };
  GLfloat mat_diffuse[] = { 0.05f, 0.5f, 0.9f, 1.0f };
  GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat mat_shininess[] = { 128.0f };
 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
       
  for(CCara caraFigura : c) //Se recorren todas las caras de la figura
  {
    glBegin(GL_POLYGON);
    // calculaNormales();
    glNormal3f(caraFigura.N.x,caraFigura.N.y,caraFigura.N.z);
    for(int iPunto : caraFigura.VERTICES())
    {
      // gluLookAt(array[iPunto].x,array[iPunto].y,-2, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0);
      glVertex3f(array[iPunto].x,array[iPunto].y,array[iPunto].z); 
    }
    glEnd(); 
  }
  glFlush();
  glutSwapBuffers();
}
void rotacion()
{
  Punto rot;
  Punto actual;
  for(long i = 0; i < TAM; i++)
  {

    actual.x = array[i].x;
    actual.y = array[i].y;
    actual.z = array[i].z;

    rot = rotacionX(5,actual);
    array[i].x = rot.x;
    array[i].y = rot.y;
    array[i].z = rot.z;
    
  }
}
/**
 * Se recorre la lista lCurva, contiene todos los puntos del bezier
 */
void recorreBezier()
{ 
  
  Punto rota;
  for(Punto pBezier : lCurva)
  {
    list<int> existe;
   traslacionOrigen();
   rotacion();
    for(int iPunto = 0; iPunto < TAM; iPunto++)
    {
     array[iPunto] = multMatriz4x1(array[iPunto],pBezier);
     glVertex3f(array[iPunto].x,array[iPunto].y,array[iPunto].z);  
    }
    
    pintaFigura();    
    
  }
  
}
/**
 * Funcion damePivote()
 * @return: Punto pivote a trasladar 
*/
Punto damePivote()
{ 
  Punto p;
  p.x = 0.0f - array[  c.front().VERTICES().front()  ].x;
  p.y = 0.0f - array[  c.front().VERTICES().front()  ].y;
  p.z = 0.0f - array[  c.front().VERTICES().front()  ].z;
  return p;
}
Punto damePivote(Punto b)
{ 
  Punto p;
  p.x = b.x - array[  c.front().VERTICES().front()  ].x;
  p.y = b.y - array[  c.front().VERTICES().front()  ].y;
  p.z = b.z - array[  c.front().VERTICES().front()  ].z;
  return p;
}


/**
 * Funcion traslacionOrigen(Punto actual)
 *
 * Se realiza la traslacion de todos los puntos de la figura al origen. 
 */
void traslacionOrigen()
{
    list<int> existe;
    pivote = damePivote();
    for(int i = 0; i < TAM; i++)
    {
      array[i].x += pivote.x;
      array[i].y += pivote.y;
      array[i].z += pivote.z;
    }
}
bool existeEnLista(list<int> lista, int busca)
{
  bool existe = false;
  for(int aux : lista)
  {
    if(busca == aux)
    {
      existe = true;
      break;
    }
  }
  return existe;
}
/**
 * Funcion multMatriz4x1(CVertice punto,Punto p)
 * @punto:  Punto actual de la figura
 * @p:      Punto pivote a trasladar
 * @return: nuevo punto resultado
 * 
 */
CVertice multMatriz4x1(CVertice punto,Punto p)
{
  CVertice nuevo;
  float vector[4];
  float m[4][4] = {0}; //Matriz de traslacion

  // Inicializacion de matriz de traslacion
  m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
  m[0][3] = punto.x;
  m[1][3] = punto.y;
  m[2][3] = punto.z;
  
  vector[0] = m[0][0] * p.x + m[0][3] * 1.0f;
  vector[1] = m[1][1] * p.y + m[1][3] * 1.0f;
  vector[2] = m[2][2] * p.z + m[2][3] * 1.0f;
  vector[3] = 1.0f;

  nuevo.x =  vector[0];
  nuevo.y =  vector[1];
  nuevo.z =  vector[2];
  

  return nuevo;
  
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
    glutInitWindowSize( 800, 600);
   glShadeModel(GL_SMOOTH);

    glutCreateWindow("Lector de Archivos WaveFront (.obj)");
    //  Habilitar la prueba de profundidad de Z-buffer

   

    v = vertices; //Se guardan los vertices en una lista global
    c = caras;    //Se guardan las caras en una lista global
    
    calculaNormales();

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
    t += 0.002;
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
  cout << "DESTRUCTOR" << endl;
}