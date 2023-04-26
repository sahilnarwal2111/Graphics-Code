#include <GL/glut.h>
#include<math.h>

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glLoadIdentity();
    glBegin(GL_POLYGON);
    float p=sqrt(0.75);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, p, 0.0);

    glEnd();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(400, 300);
glutInitWindowPosition(100, 100);
glutCreateWindow(“Sahil Triangle");
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
