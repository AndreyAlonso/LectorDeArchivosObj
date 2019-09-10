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
    this->vertices = vertices;
}

/**
 * Metodo dameCaras(list<Caras> caras)
 * @caras:  lista de caras obtenidas del archivo
 */
void CGrafico::dameCaras(list<CCara> caras)
{
    this->caras = caras;
}

void CGrafico::muestraVertices()
{
    cout << "LOS VERTICES DEL GRAFO SON" << endl;
    for(CVertice v: vertices)
        cout << v.muestraCoordenada() << endl;
}

void CGrafico::muestraCaras()
{
    cout << "LAS CARAS DEL GRAFO SON" << endl;
    for(CCara c: caras)
        cout << c.muestraCara() << endl;
}
void display()
{
    //  Borrar pantalla y Z-bufferg
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
   glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glViewport(0,0,250,250);
  // Resetear transformaciones
  
  glColor3f( 1.0, 0.0, 1.0 );
 
  for(CCara cc: c)
  {
      for(int  i: cc.VERTICES()){
          glBegin(GL_POLYGON);
          for(CVertice vc: v)
          {
            glVertex3f(vc.x,vc.y,vc.z);
          }

           glEnd();
     //   glVertex3f(vd.x,vd.y,vd.z);
    }
  }
 
  //cout << "DISPLAY" << endl;
  
    
        
 
  
 
  glFlush();
  glutSwapBuffers();
}



void CGrafico::pinta(int argc, char* argv[])
{

    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(400,0);
    glutInitWindowSize( 400, 400);
    
    glutCreateWindow("Piramide");
    
    //  Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
    
    // Funciones de retrollamada
    v = vertices;
    c = caras;
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //  Pasar el control de eventos a GLUT
    glutMainLoop();

}

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