#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

float p=1,q=0;
float p1;
int x=0;
void myInit(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

void drawTriangle()
{
    x=1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(p, q, 0.0);
    p1=sqrt(200*200 - 100*100);
    glVertex3d(0,0,0 );
    glVertex3d(200,0 ,0 );
    glVertex3d(100, p1,0);

    glEnd();
    glFlush();
}

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    glFlush();
}
void onClick(int button,int state,int x,int y)
{
    float m1=p1/100;
    float m2=0;
    float m3=p1/(-100);
    float mc=(500-float(y))/float(x);
    float mc2=(500-float(y))/(float(x)-200);
    
    if(mc<m1 && mc>m2 && mc2>m3)
    {
        if(m3<0 && mc2<0)
            if(button==GLUT_LEFT_BUTTON)
            {
                //printf("%d and %d -> %f -> %f -> %f -> %f -> %f -> %f\n",x,y,mc,m1,mc,m2,mc2,m3);
                float temp=p;
                p=q;
                q=temp;
                drawTriangle();
            }
    }
}
