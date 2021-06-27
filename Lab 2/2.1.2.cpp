/*WAP to implement BLA algorithm in Cpp*/
//Bresenham Line Drawing Algorithm
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
void init(){

    glClearColor(0,0,0,1.0);

}

int main(int argc, char**argv){

    takeData();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("BLA");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();



    //axis display
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

void reshape(int w, int h){

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);

}



// Main BLA Code
void draw(){

    glColor3f(1,1,1);


    float x1,x2,y1,y2,step,mx,my,dx,dy,temp,p,a;
    x1=X1;
    x2=X2;
    y1=Y1;
    y2=Y2;
    if(((x2-x1)<0&&(y2-y1)>0) || ((x2-x1)>0&&(y2-y1)<0))
        a=-1;
    else
        a=1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dy<dx){
        if(x1>x2){
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        p=2*dy -dx;
        //cout<<x1<<"\t"<<y1<<endl;
        glVertex2f(x1,y1);
        while((x1)<(x2)){
            if(p<0)
                p=p+2*dy;
            else{
                p=p+2*dy-2*dx;
                y1=y1+a;
            }
            x1=x1+1;
            //cout<<x1<<"\t"<<y1<<endl;
            glVertex2f(x1,y1);
        }
    }
    else{
        if(y1>y2){
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        p=2*dx -dy;
        //cout<<x1<<"\t"<<y1<<endl;
        glVertex2f(x1,y1);
        while((y1)<(y2)){
            if(p<0)
                p=p+2*dx;
            else{
                p=p+2*dx-2*dy;
                x1=x1+a;
            }
            y1=y1+1;
            //cout<<x1<<"\t"<<y1<<endl;
            glVertex2f(x1,y1);
        }
    }

}


void takeData(){

    cout<<"enter initial point: ";
    cin>>X1>>Y1;
    cout<<"enter final point: ";
    cin>>X2>>Y2;

}

