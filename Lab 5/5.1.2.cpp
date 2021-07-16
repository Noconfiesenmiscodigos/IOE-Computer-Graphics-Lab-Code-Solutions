/*WAP to implement 2D Transformation (Translation,Scaling,Rotation,Shearing & Reflection) in Cpp*/
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
float AxB3[3][3]= {1,0,0,
                   0,1,0,
                   0,0,1
                  };
float AxB1[3];
// matrix multiply
void matrix3x3(float A[3][3],float B[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            AxB3[i][j]=A[i][0]*B[0][j]+A[i][1]*B[1][j]+A[i][2]*B[2][j];
        }
    }
}

void matrix3x1(float A[3][3],float B[3])
{
    for(int i=0; i<3; i++)
    {
        AxB1[i]=A[i][0]*B[0]+A[i][1]*B[1]+A[i][2]*B[2];
    }
}

void drawTranslate();
void drawScale();
void drawRotate();
void drawReflect();
void drawShear();

int selector;
float xr=0,yr=0;  //reference
float tx,ty;  //translate
float sx,sy;  //scaling
float ang;    //rotation
int tor;    //reflection
float m=0,c=0;
float shx,shy;  //shearing
float x[4],y[4];
float nx[4],ny[4];


void init()
{

    glClearColor(0.1,0.1,0.1,1.0);  //background color
}


int main(int argc, char** argv)
{
    getinfo();
    if(selector>5||selector<0)
        return 0;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);

    glutCreateWindow("2D Transformation");

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


    glColor3f(.7,.7,.7);//axis line color
    glBegin(GL_LINES);
    glVertex2f(250,0);
    glVertex2f(-250,0);
    glVertex2f(0,250);
    glVertex2f(0,-250);
    glEnd();

    glColor3f(0,.8,.8);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        glVertex2f(x[i],y[i]);
    }
    glEnd();

    switch(selector)
    {
    case 1:
        drawTranslate();
        break;
    case 2:
        drawScale();
        break;
    case 3:
        drawRotate();
        break;
    case 4:
        drawReflect();
        break;
    case 5:
        drawShear();
        break;

    }



    glutSwapBuffers();

}


void reshape(int w,int h)
{


    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/30,timer,0);

}



void getinfo()
{
    int temp;
    cout<<"Enter the 4 points: "<<endl;
    cout<<"\t 1st point(x1,y1): ";
    cin>>x[0]>>y[0];
    cout<<"\t 2nd point(x2,y2): ";
    cin>>x[1]>>y[1];
    cout<<"\t 3rd point(x3,y3): ";
    cin>>x[2]>>y[2];
    cout<<"\t 4th point(x4,y4): ";
    cin>>x[3]>>y[3];
    cout<<"\nRemember Cyan Quad is original \nAND dark Yellow Quad is translated"<<endl;
    cout<<"\n======================================="<<endl;
    cout<<"\t1. Translate"<<endl;
    cout<<"\t2. Scale"<<endl;
    cout<<"\t3. rotate"<<endl;
    cout<<"\t4. reflect"<<endl;
    cout<<"\t5. shear"<<endl;
    cout<<endl<<"\tWhat do you want to do: ";
    cin>>selector;
    cout<<endl;
    switch(selector)
    {
    case 1:
        cout<<"Enter the following to tanslate:"<<endl;
        cout<<"\tTx: ";
        cin>>tx;
        cout<<"\tTy: ";
        cin>>ty;
        break;
    case 2:
        cout<<"Enter the following to scale:"<<endl;
        cout<<"\t1:origin scaling\n\t2:fixed point scaling \n \t Enter your choice: ";
        cin>>temp;
        if(temp==2)
        {
            cout<<"reference point:"<<endl;
            cout<<"\txRef: ";
            cin>>xr;
            cout<<"\tyRef: ";
            cin>>yr;
        }
        cout<<"\tSx: ";
        cin>>sx;
        cout<<"\tSy: ";
        cin>>sy;
        break;
    case 3:
        cout<<"Enter the following to rotate:"<<endl;
        cout<<"\t1:origin rotating\n\t2:fixed point rotate\n \t Enter your choice: ";
        cin>>temp;
        if(temp==2)
        {
            cout<<"reference point:"<<endl;
            cout<<"\txRef: ";
            cin>>xr;
            cout<<"\tyRef: ";
            cin>>yr;
        }
        cout<<"\tAngle: ";
        cin>>ang;
        ang=ang*PI/180;
        break;
    case 4:
        cout<<"Enter the type of reflection:"<<endl;
        cout<<"\t1.x-axis reflection."<<endl;
        cout<<"\t2.y-axis reflection."<<endl;
        cout<<"\t3.origin reflection."<<endl;
        cout<<"\t4.x=y reflection."<<endl;
        cout<<"\t5.x=-y reflection."<<endl;
        cout<<"\t6.y=mx+c reflection."<<endl;
        cout<<"\t Enter your choice: ";
        cin>>tor;
        if(tor==6)
        {
            cout<<"\t\t m: ";
            cin>>m;
            cout<<"\t\t c: ";
            cin>>c;
        }
        break;
    case 5:
        cout<<"Enter type of shear:"<<endl;
        cout<<"\t1.x-shear."<<endl;
        cout<<"\t2.y-shear."<<endl;
        cout<<"\t3.x-y-shear."<<endl;
        cout<<"\t4.reference x-y-shear."<<endl;
        cout<<"\t Enter your choice: ";
        cin>>temp;
        cout<<"\t Enter the following: "<<endl;

        if(temp==4)
        {
            cout<<"reference point:"<<endl;
            cout<<"\txRef: ";
            cin>>xr;
            cout<<"\tyRef: ";
            cin>>yr;
        }

        if(temp!=2)
        {
            cout<<"\t\t Shx: ";
            cin>>shx;
        }
        if(temp!=1)
        {
            cout<<"\t\t Shy: ";
            cin>>shy;
        }

        break;
    default:
        cout<<"\n\t Did you see "<<selector<<" in the list?\n\t Please go to hospital to check up your eyes."<<endl;
        break;
    }


}


//translate
void drawTranslate()
{
    float a[3][3]= {1,0,tx,
                    0,1,ty,
                    0,0,1
                   };
    glColor3f(.5,.5,0);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        float b[3]= {x[i],y[i],1};
        matrix3x1(a,b);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int i=0; i<4; i++)
    {
        float b[3]= {x[i],y[i],1};
        matrix3x1(a,b);
        glVertex2f(x[i],y[i]);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();
}


//Scaling

void drawScale()
{
    float a[3][3]= {1,0,xr,
                    0,1,yr,
                    0,0,1
                   };
    float b[3][3]= {sx,0,0,
                    0,sy,0,
                    0,0,1
                   };
    float c[3][3]= {1,0,-xr,
                    0,1,-yr,
                    0,0,1
                   };

    matrix3x3(a,b);
    matrix3x3(AxB3,c);

    glColor3f(.5,.5,0);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        float d[3]= {x[i],y[i],1};
        matrix3x1(AxB3,d);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int i=0; i<4; i++)
    {
        float d[3]= {x[i],y[i],1};
        matrix3x1(AxB3,d);
        glVertex2f(xr,yr);
        //cout<<AxB1[0]<<" "<<AxB1[1]<<endl;
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();

}





//rotation




void drawRotate()
{
    float a[3][3]= {1,0,xr,
                    0,1,yr,
                    0,0,1
                   };
    float b[3][3]= {cos(ang),-sin(ang),0,
                    sin(ang),cos(ang),0,
                    0,0,1
                   };
    float c[3][3]= {1,0,-xr,
                    0,1,-yr,
                    0,0,1
                   };

    matrix3x3(a,b);
    matrix3x3(AxB3,c);

    glColor3f(.5,.5,0);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        float d[3]= {x[i],y[i],1};
        matrix3x1(AxB3,d);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(xr,yr);
    glVertex2f((x[0]+x[2])/2,(y[0]+y[2])/2);
    float d[3]= {(x[0]+x[2])/2,(y[0]+y[2])/2,1};
    matrix3x1(AxB3,d);
    glVertex2f(xr,yr);
    glVertex2f(AxB1[0],AxB1[1]);
    glEnd();
}




//reflection

void drawReflect()
{
    float a[3][3]= {1,0,0,
                    0,1,0,
                    0,0,1
                   };
    switch(tor)
    {
    case 1:
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex2f(250,0);
        glVertex2f(-250,0);
        glEnd();
        break;
    case 2:
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex2f(0,250);
        glVertex2f(0,-250);
        glEnd();
        a[0][0]=-1;
        break;
    case 3:
        a[0][0]=-1;
        a[1][1]=-1;
        break;
    case 4:
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex2f(250,250);
        glVertex2f(-250,-250);
        glEnd();
        m=1;
        c=0;
        break;
    case 5:
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex2f(250,-250);
        glVertex2f(-250,250);
        glEnd();
        m=-1;
        c=0;
        break;
    case 6:
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex2f(250,m*250+c);
        glVertex2f(-250,-m*250+c);
        glEnd();
        break;
    }

    if(tor!=2&&tor!=3)
    {
        a[0][0]=(1-m*m)/(1+m*m);
        a[0][1]=(2*m)/(1+m*m);
        a[0][2]=(-2*c*m)/(1+m*m);
        a[1][0]=(2*m)/(1+m*m);
        a[1][1]=(m*m-1)/(1+m*m);
        a[1][2]=(2*c)/(1+m*m);
    }

    glColor3f(.5,.5,0);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        float d[3]= {x[i],y[i],1};
        matrix3x1(a,d);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int i=0; i<4; i++)
    {
        float b[3]= {x[i],y[i],1};
        matrix3x1(a,b);
        glVertex2f(x[i],y[i]);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();
}


//shearing

void drawShear()
{
    float a[3][3]= {1,shx,-shx*yr,
                    shy,1,-shy*xr,
                    0,0,1
                   };
    glColor3f(.5,.5,0);
    glBegin(GL_QUADS);
    for(int i=0; i<4; i++)
    {
        float d[3]= {x[i],y[i],1};
        matrix3x1(a,d);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int i=0; i<4; i++)
    {
        float b[3]= {x[i],y[i],1};
        matrix3x1(a,b);
        glVertex2f(x[i],y[i]);
        glVertex2f(AxB1[0],AxB1[1]);
    }
    glEnd();

}
