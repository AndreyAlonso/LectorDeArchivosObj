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
  // Resetear transformaciones
  glLoadIdentity();
  glColor3f( 1.0, 0.0, 1.0 );
  glBegin(GL_POLYGON);
  cout << "DISPLAY" << endl;
    for(CVertice  vd: v){
        glVertex3f(vd.x,vd.y,vd.z);
        cout << vd.muestraCoordenada() << endl;
    }
        
  glEnd();
  
 
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
    glutDisplayFunc(display);

    //  Pasar el control de eventos a GLUT
    glutMainLoop();

}