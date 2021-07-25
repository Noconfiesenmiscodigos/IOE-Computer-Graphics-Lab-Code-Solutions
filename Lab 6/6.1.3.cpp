/*WAP to implement Cohen Sutherland Algorithm in Cpp.*/
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<math.h>
#define PI 3.14159265358979323846
using namespace std;

void display();   //display function
void reshape(int,int);   //reshape the viewport
void timer(int);    //for displaying no of frames in a sec

void getinfo(); //info from user
void getdata();//2 points


float xmin,xmax,ymin,ymax;
struct point
{
    float x;
    float y;
    int code=0;
};

void giveCode(point&);
void clipping(point,point);

int num;//number of lines
point p1,p2; //2 points for line
point sp1,sp2; // the point that lies in viewport

vector<point> orgPoint;
vector<point> clipPoint;


void init()
{

    glClearColor(0.1,0.1,0.1,1.0);  //background color
}


int main(int argc, char** argv)
{
    getinfo();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    glutInitWindowSize(1000,700);
    glutInitWindowPosition(0,0);

    glutCreateWindow("Clipping");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
    return 0;


}



void display()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glVertex2f(xmin,ymax);
    glVertex2f(xmin,ymin);

    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);

    //glVertex2f(p1.x,p1.y);
    //glVertex2f(p2.x,p2.y);

    for(int i=0; i<orgPoint.size(); i++)
    {
        glVertex2f(orgPoint.at(i).x,orgPoint.at(i).y);
    }
    glEnd();



    glColor3f(0,1,0);
    glBegin(GL_LINES);

    //glVertex2f(sp1.x,sp1.y);
    //glVertex2f(sp2.x,sp2.y);
    for(int i=0; i<clipPoint.size(); i++)
    {
        glVertex2f(clipPoint.at(i).x,clipPoint.at(i).y);
    }
    glEnd();


    glutSwapBuffers();

}


void reshape(int w,int h)
{


    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-250,250,-250,250);
    gluOrtho2D(0,1000,0,700);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/30,timer,0);

}



void getinfo()
{
    cout<<"\n\n";

    cout<<"\tEnter following:\n";
    cout<<"\t\tXmin: ";
    cin>>xmin;
    cout<<"\t\tXmax: ";
    cin>>xmax;
    cout<<"\t\tYmin: ";
    cin>>ymin;
    cout<<"\t\tYmax: ";
    cin>>ymax;

    cout<<"\n\t\tnumber of lines: ";
    cin>>num;

    for(int i=0; i<num; i++)
    {
        cout<<"\n LINE "<<i+1<<"#::"<<endl;
        getdata();
    }
}

void getdata()
{
    p1.code=0;
    p2.code=0;

    cout<<"\n\t Enter the line details:\n";
    cout<<"\t\t X1= ";
    cin>>p1.x;
    cout<<"\t\t Y1= ";
    cin>>p1.y;
    cout<<"\t\t X2= ";
    cin>>p2.x;
    cout<<"\t\t Y2= ";
    cin>>p2.y;

    giveCode(p1);
    giveCode(p2);

    orgPoint.push_back(p1);
    orgPoint.push_back(p2);

    clipping(p1,p2);
}

void giveCode(point &A)
{
    A.code=0;
    if(A.x<xmin)
        A.code+=1;  //1=0001
    if(A.x>xmax)
        A.code+=2;  //2=0010
    if(A.y<ymin)
        A.code+=4;  //4=0100
    if(A.y>ymax)
        A.code+=8;  //8=1000


}



// clipping code


void clipping(point A, point B)
{
    float m=(A.y-B.y)/(A.x-B.x);


    if((A.code|B.code) == false )
    {
        cout<<"This line lies completely inside."<<endl;
        sp1.x=A.x;
        sp1.y=A.y;
        sp2.x=B.x;
        sp2.y=B.y;

        clipPoint.push_back(sp1);
        clipPoint.push_back(sp2);

        return;
    }
    else if(A.code & B.code)
    {
        cout<<"Line lies completely outside."<<endl;
        return;
    }
    else
    {
        point check;
        if(A.code==0)
        {
            check.x=B.x;
            check.y=B.y;
            check.code=B.code;
        }
        else
        {
            check.x=A.x;
            check.y=A.y;
            check.code=A.code;
        }

        if(check.code&1)
        {
            check.y=check.y+ m*(xmin-check.x);
            check.x=xmin;
        }
        if(check.code&2)
        {
            check.y=check.y+ m*(xmax-check.x);
            check.x=xmax;
        }
        if(check.code&4)
        {
            check.x=check.x+(ymin-check.y)/m;
            check.y=ymin;
        }
        if(check.code&8)
        {
            check.x=check.x+ (ymax-check.y)/m;
            check.y=ymax;
        }

        if(A.code==0)
        {
            B.x=check.x;
            B.y=check.y;
            B.code=check.code;
        }
        else
        {
            A.x=check.x;
            A.y=check.y;
            A.code=check.code;
        }

        sp1.x=A.x;
        sp1.y=A.y;
        sp2.x=B.x;
        sp2.y=B.y;


        giveCode(sp1);
        giveCode(sp2);
        cout<<"The New points: "<<endl;
        cout<<"("<<sp1.x<<","<<sp1.y<<")\t";
        cout<<"("<<sp2.x<<" "<<sp2.y<<")"<<endl;
        clipping(sp1,sp2);
    }
    return;
}
