#include <windows.h>
#include <GL/glut.h>

// Rotation angles for keyboard-controlled rotation
float angleX = 0.0f, angleY = 0.0f, angleZ = 0.0f;

double posx = 0, posy = 0, posz = 2.1, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;

static int  a2 = 0, a3 = 0, tx = 0, ty = 0, tz = 0, sx = 1, sy = 1, sz = 1,rx = 0, ry = 0, rz = 0;
float p = 1.4;
static double a1 = 0.8;

float color1 = 0.5f;
float color2 = 0.0f;
float color3 = 0.0f;

static void idle(void)
{
    glutPostRedisplay();
}

void init() {

  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(50.0, 3.22/3.0, 1, 20);

}


void boat(int value) {
    p = p - 0.025;
    if(p < -0.8){
        p = p + 2.4;
    }
    glutPostRedisplay();
    glutTimerFunc(50, boat, 1);
}

void timer( int value )
{
    color1 += 0.003f;
    color2 += 0.003f;
    color3 += color2;
    if (color1 > 1.0)
        color1 = 0.5;
    if (color2 > 1.0)
        color2 = 0;
    if (color3 > 1.0)
        color3 = 0;

    glutPostRedisplay();
    glutTimerFunc( 16, timer, 0 );
}


// Keyboard function to handle rotation
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':  // Rotate around x-axis
            angleX += 5.0f;
            break;
        case 'X':  // Rotate in opposite direction around x-axis
            angleX -= 5.0f;
            break;
        case 'y':  // Rotate around y-axis
            angleY += 5.0f;
            break;
        case 'Y':  // Rotate in opposite direction around y-axis
            angleY -= 5.0f;
            break;
        case 'z':  // Rotate around z-axis
            angleZ += 5.0f;
            break;
        case 'Z':  // Rotate in opposite direction around z-axis
            angleZ -= 5.0f;
            break;
        case 27:  // Escape key to exit
            exit(0);
    }
    glutPostRedisplay();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);

glRotatef(angleX, 1.0, 0.0, 0.0);  // Rotation around x-axis
    glRotatef(angleY, 0.0, 1.0, 0.0);  // Rotation around y-axis
    glRotatef(angleZ, 0.0, 0.0, 1.0);


    glPushMatrix();

glPushMatrix();
glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,-1.0,0.0);
    glVertex3f(-1.0,-1.0,0.0);
    glVertex3f(-1.0,1.0,0.0);


glEnd();
glPopMatrix();

glPushMatrix();
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);

        glVertex3f(0.0,-0.12,0.0);
        glVertex3f(0.1, -0.10,0.0);
        glVertex3f(0.2,-0.12,0.0);
        glVertex3f(0.3, -0.10,0.0);
        glVertex3f(0.4,-0.12,0.0);
        glVertex3f(0.5, -0.10,0.0);
        glVertex3f(0.6,-0.12,0.0);
        glVertex3f(0.7, -0.10,0.0);
        glVertex3f(0.8,-0.12,0.0);
        glVertex3f(0.9, -0.10,0.0);
        glVertex3f(1.0,-0.13,0.0);

        glVertex3f(1.0,-0.62,0.0);
        glVertex3f(0.9, -0.60,0.0);
        glVertex3f(0.8,-0.62,0.0);
        glVertex3f(0.7, -0.60,0.0);
        glVertex3f(0.6,-0.62,0.0);
        glVertex3f(0.5, -0.60,0.0);
        glVertex3f(0.4,-0.62,0.0);
        glVertex3f(0.3, -0.60,0.0);
        glVertex3f(0.2,-0.62,0.0);
        glVertex3f(0.1,-0.60,0.0);
        glVertex3f(0.0,-0.62,0.0);

        glVertex3f(-0.1,-0.6,0.0);
        glVertex3f(-0.2, -0.62,0.0);
        glVertex3f(-0.3,-0.6,0.0);
        glVertex3f(-0.4, -0.62,0.0);
        glVertex3f(-0.5,-0.6,0.0);
        glVertex3f(-0.6, -0.62,0.0);
        glVertex3f(-0.7,-0.6,0.0);
        glVertex3f(-0.8, -0.62,0.0);
        glVertex3f(-0.9,-0.6,0.0);
        glVertex3f(-1.0, -0.62,0.0);

        glVertex3f(-1.0,-0.11,0.0);
        glVertex3f(-0.9,-0.12,0.0);
        glVertex3f(-0.8,-0.10,0.0);
        glVertex3f(-0.7,-0.12,0.0);
        glVertex3f(-0.6,-0.10,0.0);
        glVertex3f(-0.5,-0.12,0.0);
        glVertex3f(-0.4,-0.10,0.0);
        glVertex3f(-0.3,-0.12,0.0);
        glVertex3f(-0.2,-0.10,0.0);
        glVertex3f(-0.1,-0.12,0.0);
        glVertex3f(-0.0,-0.10,0.0);

glEnd();
glPopMatrix();

glPushMatrix();
    glTranslatef(p,0.0,0.0);
    //glScalef(0.5,1.0,0.5);
    glBegin(GL_POLYGON);

        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.3,-0.32,0.0);     //Boat-bottom
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.55,-0.38,0.0);

    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.55,-0.38,0.0);
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.60,-0.335,0.02);     //Boat-Left
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.365,0.02);
        glVertex3f(-0.55,-0.38,0.0);


    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.3,-0.32,0.0);
        glVertex3f(-0.25,-0.335,0.02);     //Boat-Right
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.365,0.02);
        glVertex3f(-0.3,-0.38,0.0);


    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.365,0.05);
        glVertex3f(-0.55,-0.38,0.05);
        glVertex3f(-0.3,-0.38,0.05);       //Boat-Front
        glVertex3f(-0.25,-0.365,0.05);
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.365,0.02);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.55,-0.38,0.0);
        glVertex3f(-0.60,-0.365,0.02);
        glVertex3f(-0.65,-0.35,0.05);


    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.335,0.05);
        glVertex3f(-0.55,-0.32,0.05);
        glVertex3f(-0.3,-0.32,0.05);       //Boat-Back
        glVertex3f(-0.25,-0.335,0.05);
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.335,0.02);
        glVertex3f(-0.3,-0.32,0.0);
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.60,-0.335,0.02);
        glVertex3f(-0.65,-0.35,0.05);


    glEnd();
    glLineWidth(3.0);
    glColor3f(1.0,color1,color2);
    glBegin(GL_LINES);
        glVertex3f(-0.30,-0.35,0.20);   //Boat-handle
        glVertex3f(-0.2,-0.37,0.03);

    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.205,-0.37,0.03);
        glVertex3f(-0.18,-0.37,0.032);   //Boat-handle
        glVertex3f(-0.20,-0.37,0.00);


    glEnd();
    glLineWidth(4.0);
    glColor3f(0.5,0.5,0.5);




glPopMatrix();





glPushMatrix();
    glColor3f(0.5,0.5,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.28,0.0);
        glVertex3f(0.35,0.4,0.0);
        glVertex3f(0.4,0.4,0.0);
        glVertex3f(0.3,0.25,0.0);
        glVertex3f(0.1,0.1,0.0);
        glVertex3f(-0.1,-0.11,0.0);
        glVertex3f(-0.15,-0.11,0.0);
glEnd();
glPopMatrix();


glPushMatrix();
    glColor3f(0.3,0.2,0.14);

    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.5, 0.4,0.0);
        glVertex3f(0.5, 0.65,0.0);  // Bottom
        glVertex3f(0.3,0.65,0.0);


        glVertex3f(0.3,0.65,0.0);
        glVertex3f(0.5, 0.65,0.0);    //back
        glVertex3f(0.5, 0.65,0.3);
        glVertex3f(0.3,0.65,0.3);

        glColor3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.3,0.65,0.0);
        glVertex3f(0.3,0.65,0.3);      //left
        glVertex3f(0.3,0.4,0.3);


        glColor3f(0.3,0.2,0.14);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.5,0.4,0.0);
        glVertex3f(0.5,0.4,0.3);   //front
        glVertex3f(0.3,0.4,0.3);

        //glColor3f(1.0,0.0,1.0);
        glVertex3f(0.5,0.4,0.0);
        glVertex3f(0.5,0.65,0.0);
        glVertex3f(0.5, 0.65,0.3);    //right
        glVertex3f(0.5, 0.4,0.3);


glEnd();

glColor3f(0.3,0.1,0.14);
    glBegin(GL_POLYGON);


    glVertex3f(0.28,0.38,0.30);
    glVertex3f(0.52, 0.38,0.30);
    glVertex3f(0.52, 0.67,0.30);                       // top
    glVertex3f(0.28,0.67,0.30);

glEnd();

glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,1.0);
    glVertex3f(0.32,0.4,0.13);
    glVertex3f(0.35,0.4,0.13);
    glVertex3f(0.35,0.4,0.17);
    glVertex3f(0.32,0.4,0.17);

glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,1.0);
    glVertex3f(0.45,0.4,0.13);
    glVertex3f(0.48,0.4,0.13);
    glVertex3f(0.48,0.4,0.17);
    glVertex3f(0.45,0.4,0.17);


glEnd();
glPopMatrix();

glPushMatrix();
    glColor3f(0.3,0.2,0.14);
    glBegin(GL_POLYGON);

    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.00,0.0);    // Tree
    glVertex3f(-0.74,0.00,0.0);

    glVertex3f(-0.74,0.00,0.0);
    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.74,-0.05,0.4);   //Tree-left
    glVertex3f(-0.74,0.00,0.4);
    glVertex3f(-0.74,0.00,0.0);

    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.4);    //Tree-front
    glVertex3f(-0.74,-0.05,0.4);
    glVertex3f(-0.74,-0.05,0.0);

    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.00,0.0);
    glVertex3f(-0.7,-0.00,0.4);   //Tree-right
    glVertex3f(-0.7,-0.05,0.4);
    glVertex3f(-0.7,-0.05,0.0);

    glVertex3f(-0.74,0.00,0.0);
    glVertex3f(-0.7,0.00,0.0);
    glVertex3f(-0.7,0.00,0.4);    //Tree-back
    glVertex3f(-0.74,0.00,0.4);
    glVertex3f(-0.74,0.00,0.0);


    glEnd();
glPopMatrix();

glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.74,-0.025,0.4);     //tree-leaf
    glutSolidSphere(0.13,36,2);

glPopMatrix();
glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.7,-0.025,0.4);
    glutSolidSphere(0.13,36,2);       //tree-leaf

glPopMatrix();

glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.72,-0.05,0.4);
    glutSolidSphere(0.13,36,2);        //tree-leaf

glPopMatrix();
glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.72,-0.0,0.4);
    glutSolidSphere(0.13,36,2);        //tree-leaf

glPopMatrix();



glPushMatrix();
    glColor3f(color1,color2,0.0);
    glTranslatef(0.8,0.8,0.6);         //Sun
    glRotatef(45,1.0,0.0,0.0);
    glutSolidSphere(0.08,36,2);

glPopMatrix();
glPushMatrix();
    glLineWidth(1.0);
    glColor3f(1.0,color1,color2);
    glTranslatef(-0.1,0.2,-0.1);
    glRotatef(45,1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.82,0.82,0.0);      //Line
        glVertex3f(0.7,0.65,0.0);

        glVertex3f(0.86,0.81,0.0);
        glVertex3f(0.82,0.65,0.0);

        glVertex3f(0.91,0.81,0.0);
        glVertex3f(0.95,0.62,0.0);

        glVertex3f(0.81,0.90,0.0);
        glVertex3f(0.7,0.85,0.0);

    glEnd();
glPopMatrix();



  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

  glRotatef(300,1.0,0.0,0.0);

glFlush();



}
int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 500);
  glutCreateWindow("3D FARM HOUSE");
  glutTimerFunc(100, boat, 0);
  glutTimerFunc( 16, timer, 0 );
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  init();
  glutMainLoop();
}
