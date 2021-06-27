/*WAP to implement DDA algorithm in Cpp*/
//Digital Differential Analyzer Algorithm
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
void display();
void reshape(int,int);
void draw();
void takeData();
float X1,X2,Y1,Y2;
void init()
{
    glClearColor(0,0,0,1.0);
}
int main(int argc, char**argv)
{

    takeData();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("DDA");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


//axis drawing
    glPointSize(1);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(-250,0);
    glVertex2f(250,0);
    glVertex2f(0,-250);
    glVertex2f(0,250);

    glEnd();
    //draw
    glBegin(GL_POINTS);

    draw();

    glEnd();

    glFlush();

}

void reshape(int w, int h)
{

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-250,250,-250,250);
    //gluOrtho2D(-125,125,-125,125);
    glMatrixMode(GL_MODELVIEW);

}


//function

void draw()
{

    glColor3f(1,1,1);
    float x1,x2,y1,y2,step,mx,my,dx,dy;
    x1=X1;
    x2=X2;
    y1=Y1;
    y2=Y2;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dy)<abs(dx))
        step=abs(dx);
    else
        step=abs(dy);

    mx=dx/step;
    my=dy/step;

    glVertex2f(x1,y1);
    for(int i=0; i<step; i++)
    {
        x1=x1+mx;
        y1=y1+my;

        glVertex2f(x1,y1);
    }

}


void takeData()
{

    cout<<"enter initial point: ";
    cin>>X1>>Y1;
    cout<<"enter final point: ";
    cin>>X2>>Y2;

}

