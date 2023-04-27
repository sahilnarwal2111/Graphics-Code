#include<GL/glut.h>
#include<iostream>
using namespace std;
typedef struct color{GLubyte red;GLubyte green;GLubyte blue;} color;

void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void b_fill(float x,float y,color b,color f)
{
    color e;
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&e);
    int count=0;
    if((int)b.red==(int)e.red) count++;
    if((int)b.green==(int)e.green) count++;
    if((int)b.blue == (int)e.blue) count++;
    //cout<<count<<endl;
    if(count!=3)
    {
        int count=0;
        if((int)f.red==(int)e.red) count++;
        if((int)f.green==(int)e.green) count++;
        if((int)f.blue == (int)e.blue) count++;
        if(count!=3)
        {
            glBegin(GL_POINTS);
            glColor3ub(f.red,f.green,f.blue);
            glVertex2f(x,y);
            glEnd();
            glFlush();
            b_fill(x+1,y,b,f);
            b_fill(x-1,y,b,f);
            b_fill(x,y+1,b,f);
            b_fill(x,y-1,b,f);
        }
    }
}
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    color b_color,f_color;
    b_color.red=255;
    b_color.green=255;
    b_color.blue=255;
    f_color.red=0;
    f_color.green=255;
    f_color.blue=0;
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(150,150);
    glVertex2f(150,450);

    glVertex2f(150,450);
    glVertex2f(450,450);

    glVertex2f(450,450);
    glVertex2f(450,150);


    glVertex2f(450,150);
    glVertex2f(150,150);
    glEnd();
    b_fill(220,220,b_color,f_color);
    glFlush();
}
int main(int a,char** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutCreateWindow("Sahil boundary_fill in sqaure");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
    return 0;
}
