#include<GL/glut.h>
#include<math.h>
void draw_triangle()
{
    glBegin(GL_POLYGON);
    //glColor3d(255.0, 255.0, 255.0);
    glColor3ub(1,1,1);
    float p=sqrt(0.75);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, p, 0.0);
    glEnd();
}
void drawline(float x1,float y1,float x2,float y2)
{
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
}
void draw_name()
{
     glColor3f(1.0,1.0,1.0);
    glRasterPos2f(0.35,0.3);
    char name[]=“Sahil";
    for(int i=0;name[i]!='\0';i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
}
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_triangle();
    draw_name();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);

    glutInitWindowPosition(100, 100);
    glutCreateWindow(“sahil triangles");
    glutDisplayFunc(disp);
    //disp();
    glutMainLoop();
    return 0;
}
