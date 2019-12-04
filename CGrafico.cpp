#include "Headers/CGrafico.h"
#include "CBezier.cpp"
/****************************************************
 * CGrafico()
 * Constructor de la clase CGrafico
 * Se inicializan los puntos pivote para el bezier
 ****************************************************/
CGrafico::CGrafico()
{
  b1.creaP1(  0.92f, -0.52f, 0.0f );
  b1.creaP2(  0.626f, -0.772f, 0.0f );
  b1.creaP3(  0.075f, -0.604f, 0.0f );
  b1.creaP4(  -0.011f, -0.1082f, 0.0f );

  generaBezier();

  lCurva = curva;
}
/**
 * Metodo pinta(int argc, char *argv[])
 * Se crea la ventana de OpenGL
 * Se manda llamar a las funciones para interactuar con la ventana OpenGL
 */
void CGrafico::pinta(int argc, char* argv[],CGrafico escenario)
{
    long j = 1;
    glutInit(&argc,argv);   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(400,0);
    glutInitWindowSize( 800, 600);
    glShadeModel(GL_SMOOTH);

    glutCreateWindow("Animacion X-Wing");

    v = vertices; //Se guardan los vertices en una lista global
    c = caras;    //Se guardan las caras en una lista global
    copia = v;    //Se genera una copia de los vertices de la figura

    vEscenario = escenario.vertices;
    cEscenario = escenario.caras;
    
    pista = (CVertice*)malloc(sizeof(CVertice)*(vEscenario.size()+1));
    for(CVertice cv: vEscenario)
      pista[j++] = cv; 
    calculaNormales();
    copia = vertices;
   
    glClearColor(cred,cgreen,0.09,0.0);
    pintaFigura();
    pintaEscenario();
    glutDisplayFunc(display);     //Llamada a la funcion display()
    glutSpecialFunc(specialKeys); //Llamada a la funcion specialKey()
    glutMouseFunc(mouse);           
    glutMainLoop();

    
}
/**
 * Funcion pintaFigura()
 * 
 * Se muestra en pantalla la figura
 * aplicando la rotación y traslación
 */
void pintaFigura()
{
    glEnable(GL_LIGHT0);                               
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    calculaNormales();
	GLfloat mat_ambient[] = { 204/100,0.0,0.0,1.0};
	GLfloat mat_diffuse[] = {  204/100,0.0,0.0,1.0 };
	GLfloat mat_specular[] = {  204/100,0.0,0.0,1.0 };
	GLfloat mat_shininess[] = { 120.0f };
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    for(CCara caraFigura : c) //Se recorren todas las caras de la figura
    {
        glBegin(GL_POLYGON);
        glNormal3f(caraFigura.N.x,caraFigura.N.y,caraFigura.N.z);
        for(int iPunto : caraFigura.VERTICES())
        {      
            glVertex3f(array[iPunto].x,array[iPunto].y,array[iPunto].z);  
        }
        glEnd(); 
    }
    glFlush();
    glutSwapBuffers();
}
/**
 * Metodo dameVertices(list<CVertice> vertices)
 * @vertices: lista de vertices obtenidas del archivo
 */
void CGrafico::dameVertices(list<CVertice> vertices)
{
  long j = 1;
  this->vertices = vertices;
  array = (CVertice*)malloc(sizeof(CVertice)*(vertices.size()+1));
  for(CVertice cv: vertices)   //Se guarda en un arreglo los vertices para poder pintarlos
    array[j++] = cv; 
  TAM = j;
  
}

void CGrafico::dameVerticesEscenario(list<CVertice> vertices)
{
  long j = 1;
  this->vertices = vertices;
  //array[vertices.size()];
  pista = (CVertice*)malloc(sizeof(CVertice)*(vertices.size()+1));
  for(CVertice cv: vertices)   //Se guarda en un arreglo los vertices para poder pintarlos
    pista[j++] = cv; 
}

/**
 * Funcion dameVertices(list<CVertice> vertices)
 * @vertices: lista de vertices de la figura
 * Se reserva espacio de memoria para los vertices de la figura
 * Se almacenan en un apuntador
 */
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
void calculaNormalesEscenario()
{

  list<CCara> temp;
  CVertice  p1,p2,p3, P,Q,N;
  GLfloat modulo;
  int i;
  for(CCara face : cEscenario){
    i = 0;
    modulo = 0;
    for(int pos: face.VERTICES()){
      switch(i){
        case 1:
          p1 = pista[pos];
        break;
        case 2:
          p2 = pista[pos];
        break;
        case 3:
          p3 = pista[pos];
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
  cEscenario = temp;
  // imprimeNormales();

}

/**
 * Funcion impleNormales()
 * Se muestra en consola los vertices normales 
 * de las caras de la figura
 */
void imprimeNormales()
{
 for(CCara face : c){
    cout << "vn:\t" << face.N.x << " \t\t" << face.N.y << " \t\t" << face.N.z << endl;
 } 
}

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
   glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  pintaEscenario();
  pintaFigura();

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

/**
 * Funcion rotacionX(float angulo, Punto actual)
 * @angulo: angulo que se desea aplicar la rotacion
 * @actual: vertice actual de la figura a rotar
 * 
 * Se aplica la mutliplicacion de matrices para rotar
 * el vertice al nuevo punto
 */
Punto rotacionX(float angulo, Punto actual)
{
  float aSen, aCos;
  Punto nuevo;
  aSen = sin(angulo*PI/180); 
  aCos = cos(angulo*PI/180);
  nuevo.z = actual.z * aCos - actual.x*aSen;
  nuevo.x = actual.z * aSen + actual.x*aCos;
  nuevo.y = actual.y;
  return nuevo;
  
}


/***
 * Funcion rotacion()
 * Aplicando la mutliplicacion de matrices
 * Se rota la figura en el eje X 
 * 
 */
void rotacion()
{
  Punto rot;
  Punto actual;
  for(long i = 0; i < vEscenario.size(); i++)
  {

    actual.x = pista[i].x;
    actual.y = pista[i].y;
    actual.z = pista[i].z;

    rot = rotacionX(1,actual);
    pista[i].x = rot.x;
    pista[i].y = rot.y;
    pista[i].z = rot.z;
    
  }
}
/**
 * Se recorre la lista lCurva, contiene todos los puntos del bezier
 */
void recorreBezier()
{ 
  for(Punto pBezier : lCurva)
  {
    traslacionOrigen();
    rotacion();
    for(int iPunto = 0; iPunto < TAM; iPunto++)
    {
      array[iPunto] = multMatriz4x1(array[iPunto],pBezier);
      glVertex3f(array[iPunto].x,array[iPunto].y,array[iPunto].z);  
    }
    pintaEscenario();  
    pintaFigura();
    // pintaPlano();
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


/**
 * Funcion traslacionOrigen(Punto actual)
 *
 * Se realiza la traslacion de todos los puntos de la figura al origen. 
 */
void traslacionOrigen()
{
    pivote = damePivote();
    for(int i = 0; i < TAM; i++)
    {
      array[i].x += pivote.x;
      array[i].y += pivote.y;
      array[i].z += pivote.z;
    }
    for(int i =0; i < v.size(); i++)
    {
      array[i].x += (0.0 - array[  c.front().VERTICES().front()  ].x);
      array[i].y += (0.0 - array[  c.front().VERTICES().front()  ].y);
      array[i].z += (0.0 - array[  c.front().VERTICES().front()  ].z);
    }
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
  m[0][3] = (1-0.003)*punto.x;
  m[1][3] = (1-0.003)*punto.y;
  m[2][3] = (1-0.003)*punto.z;
  
  vector[0] = m[0][0] * p.x + m[0][3] * 1.0f;
  vector[1] = m[1][1] * p.y + m[1][3] * 1.0f;
  vector[2] = m[2][2] * p.z + m[2][3] * 1.0f;
  vector[3] = 1.0f;

  nuevo.x =  vector[0];
  nuevo.y =  vector[1];
  nuevo.z =  vector[2];
  

  return nuevo;
  
}

void specialKeys( int key, int x, int y ) 
{  
    v = copia;
    long j = 1;
    array = (CVertice*)malloc(sizeof(CVertice)*(copia.size()+1));
    for(CVertice cv: copia)
      array[j++] = cv; 
    if (key == GLUT_KEY_RIGHT)
    {
        recorreBezier();
        
    }
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
        v = copia;
    pintaEscenario();
    pintaFigura();


}


void pintaPlano()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glClearColor(cred,cgreen,0.09,0.0);
  pintaEscenario();
  pintaFigura();
  v = copia;
  glutSwapBuffers();
  glFlush();

}

void pintaEscenario()
{
  glEnable(GL_LIGHT0);                                // Enable Light1
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  calculaNormalesEscenario();
	GLfloat mat_ambient[] = { 192/100, 192/100,192/100, 1.0f };
  GLfloat mat_diffuse[] = {192/100, 192/100,192/100, 1.0f };
  GLfloat mat_specular[] = { 192/100, 192/100,192/100, 1.0f  };
  GLfloat mat_shininess[] = { 128.0f };
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  for(CCara caraFigura : cEscenario) //Se recorren todas las caras de la figura
  {
    glNormal3f(caraFigura.N.x,caraFigura.N.y,caraFigura.N.z);

    glBegin(GL_POLYGON);
     
    for(int iPunto : caraFigura.VERTICES())
    {        
      glVertex3f(pista[iPunto].x,pista[iPunto].y,pista[iPunto].z); 
    }
    glEnd(); 
  }
  
//   glFlush();
//  glutSwapBuffers();

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
}
void mouse(int button, int state, int x, int y)
{
   // Wheel reports as button 3(scroll up) and button 4(scroll down)
   if ((button == 3) || (button == 4)) // It's a wheel event
   {
       // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
       if (state == GLUT_UP)  // Disregard redundant GLUT_UP events
       {
         if(button == 3)
         {
            cred += 0.01;
            cgreen +=0.01;
         }
         else if (button == 4)
         {
           cred -= 0.01;
         cgreen -=0.01;
         }
       }
       if (state == GLUT_DOWN)  // Disregard redundant GLUT_UP events
       {
         
       }

   }else{  // normal button event
       printf("Button %s At %d %d\n", (state == GLUT_DOWN) ? "Down" : "Up", x, y);
   }
   
   pintaEscenario();
   pintaFigura();
   pintaPlano();
}
