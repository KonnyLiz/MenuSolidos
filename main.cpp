//solidos#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define NP 4000
#define AGE 200

//DECLARACION DE VARIABLES A UTILIZAR
float winWid,winHeight;
float rx,ry; // variables que representan las coordenadas
int vf[5]={2}; // venctor donde almacenaremos el id de la imagen a imprimir
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat mat_ambient[] = { 0.05f, 0.0f, 0.0f,1.0f };
    GLfloat mat_diffuse[] = { 0.5f, 0.4f, 0.4f, 1.0f };
    GLfloat mat_specular[] = { 0.7f, 0.04f, 0.04f, 1.0f };
    GLfloat shine[] = {0.078125f};
float light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    
void init (void){
    glLightfv(GL_LIGHT0,GL_POSITION,light_position); //configurando posicion de la luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
    //glShadeModel(GL_SMOOTH);
}

//METODO QUE PERMITE IMPRIMIR LA IMAGEN A MOSTRAR
void menu(int opc){
    vf[1]=opc; // En el vector VF, en su campo 1, se almacenara el id de la imagen
    glPushMatrix();
    glColor3f(1.0,1.0,0.0); 
    glTranslated((rx*0.001),(ry*0.001),0.0); // ubicando la posicion donde se imprimira la imagen
    // rx, ry, se multiplica por 0.001, porque sus valores son centenas y al hacer esa operacion
    // permite obtener su valor en decimal ("0.000")
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    
    switch(opc){ // checando la imagen elegida para mostrar
       case 1:
           cerr << "Esfera\n";
           glRotatef (40,0.1,0.1,0.0);
           glutWireSphere(0.2,8,8);
           break;

       case 2:
           cerr << "Cubo\n";
           glRotatef (60,0.1,0.1,0.0);
           glutWireCube(0.18);
           break;
       case 3:
           cerr << "Cono\n";
           glRotatef (60,0.1,0.1,0.0);
           glutWireCone(0.1,0.2,6,6);
           break;
       case 4:
           cerr << "Tetera\n";
           glutWireTeapot(0.1);
           break;
       case 5:
           cerr << "Tetrahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutWireTetrahedron();
           break;
       case 6:
           cerr << "Octahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutWireOctahedron();

        break;
       case 7:
           cerr << "Dodecahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutWireDodecahedron();
            break;
       case 8:
           cerr << "Icosahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutWireIcosahedron();
           break;
       case 9:
           cerr << "Torus \n";
           //glScalef(0.13, 0.13, 0.0);
           //glRotatef(60,0.1,0.1,0.0);
     
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat_ambient);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mat_diffuse);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
            glutSolidTorus(0.10, 0.30, 40, 20);
           break;
           case 10:
           cerr << "cubo solido \n";
           //glScalef(0.13, 0.13, 0.0);
           //glRotatef(60,0.1,0.1,0.0);
     
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat_ambient);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mat_diffuse);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
            glutSolidCube(0.5);
           break;
   }

   glPopMatrix();
   glFlush();
}

// METODO QUE REPINTA LA PANTALLA
void redraw( void ){
    //Limpiando la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    // Haciendo uso del metodo menu, pasandoles como paramentro el id
    // de la figura que se eligio, así pues cada vez que se pueda el cursor
    // dicha imagen se repintara
     menu(vf[1]);
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y )
{
  
  if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
    glutPostRedisplay();

}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER CLICK REDECHO
void motion(int x, int y){
    //cerr << "motion. x:" << x << ", y:" << y << " \n";
     rx = float(x);
     ry = winHeight - float(y);

}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER MOVER EL CURSO Y PRESIONAR EL CLICK DERECHO
void mousebutton(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        rx = float(x);
        ry = winHeight - float(y);
       //	 redraw();
    }
}


int main(int argc, char *argv[]){
    winWid = 600.0;
    winHeight = 400.0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(" ");
    glutPositionWindow(200,100);
    glutReshapeWindow(int(winWid),int(winHeight));
init();

    // CREACION DEL MENU PARA ELEGIR ALGUNA IMAGEN
    glutCreateMenu(menu);
      glutAddMenuEntry("ESFERA",1);
      glutAddMenuEntry("CUBO",2);
      glutAddMenuEntry("CONO",3);
      glutAddMenuEntry("TETERA",4);
      glutAddMenuEntry("TETRAHEDRO",5);
      glutAddMenuEntry("OCTAHEDRO",6);
      glutAddMenuEntry("DODECAHEDRO",7);
      glutAddMenuEntry("ICOSAHEDRO",8);
      glutAddMenuEntry("TORUS",9);
      glutAddMenuEntry("cubo solido",10);
      glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

 glutSpecialFunc(specialKeys);
    glutDisplayFunc(redraw);
    glutIdleFunc(redraw);
    glutMotionFunc(motion);
    glutMouseFunc(mousebutton);
    glutMainLoop();

    return 0;
}
