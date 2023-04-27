#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float pi=3.14;
int width=500,height=500;
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0f,float(width)/height,1.0f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,2,-2,
    0,0,0,
    0,1,0);
}
void boundary(float vertices[][3])
{
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    //e1
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    //e2
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    //e3
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    //e4
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    //e5
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    //e6
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
    //e7
    glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    //e8
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);

    //e9
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    //e10
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
    //e11
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    //e12
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);

    glEnd();
}
void draw_cube(float vertices[8][3])
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    //front
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    glEnd();
    //back
    glBegin(GL_POLYGON);
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    glEnd();
    //left
    glBegin(GL_POLYGON);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    glEnd();
    //top
    glBegin(GL_POLYGON);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
    glEnd();
    //right
    glBegin(GL_POLYGON);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
    glEnd();
    //bottom
    glBegin(GL_POLYGON);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
    glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
    glEnd();
    boundary(vertices);
    glFlush();
}
void mat_mul(float a[4][4],float b[4][1],float r[4][1])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            r[i][j]=0;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<3;k++)
            {
                r[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}
void disp()
{
    float vertices[][3]={
    {300,300,300},
    {-300,300,300},
    {-300,-300,300},
    {300,-300,300},
    {300,300,-300},
    {-300,300,-300},
    {-300,-300,-300},
    {300,-300,-300}
    };
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            vertices[i][j]/=1000;
        }
    }
    draw_cube(vertices);
    float theta;
    cout<<"Enter angle of rotation -> ";
    cin>>theta;
    theta=theta*(pi/180);
    float mat[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            mat[i][j]=0;
        }
    }
    mat[0][0]=1;
    mat[1][1]=cos(theta);
    mat[1][2]=sin(theta);
    mat[2][1]=(-1)*sin(theta);
    mat[2][2]=cos(theta);
    mat[3][3]=1;
    float coordinates[4][1];
    coordinates[3][0]=1;
    for(int i=0;i<8;i++)
    {
        float result[4][1];
        coordinates[0][0]=vertices[i][0];
        coordinates[1][0]=vertices[i][1];
        coordinates[2][0]=vertices[i][2];
        mat_mul(mat,coordinates,result);
        vertices[i][0]=result[0][0];
        vertices[i][1]=result[1][0];
        vertices[i][2]=result[2][0];
    }
    draw_cube(vertices);
}

int main(int a,char ** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutCreateWindow("sahil 3d rotation");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
}
