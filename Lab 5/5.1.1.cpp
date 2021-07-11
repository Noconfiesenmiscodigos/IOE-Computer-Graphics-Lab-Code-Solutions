/*WAP to implement 2D Transformation (Translation,Scaling,Rotation,Shearing & Reflection) in Cpp*/
#include <iostream>
#include <cmath>
#include <graphics.h>
#define pi 3.141592654
using namespace std;
int i,choice,plot_count=0;
float x,y,z=1.0,x_n,y_n;
float x_p_1,y_p_1,x_p_2,y_p_2,x_p_3,y_p_3;
float t_x,t_y;//translation
float x_f,y_f,s_x,s_y;//Scaling
float x_r,y_r,thetha;//Rotation
float x_ref,y_ref,sh_x,sh_y;//Shearing
float m,c;//Reflection
float a[3][3];
void matrix_multiplication();
void create_graphics()
{
    initwindow(1366,768);
    setlinestyle(0,0,1);
    for(i=0; i<=1366; i++)
    {
        line(0,i,1366,i);
    }
    setcolor(LIGHTBLUE);
    line(0,384,1365,384);
    line(683,0,683,1365);
    setcolor(LIGHTGRAY);
    for(i=633; 0<=i; i=i-50)//633=683-50
    {
        line(i,0,i,768);
    }
    for(i=733; i<=1366; i=i+50)//733=683+50
    {
        line(i,0,i,768);
    }
    for(i=334; 0<=i; i=i-50)//334=384-50
    {
        line(0,i,1366,i);
    }
    for(i=434; i<=1365; i=i+50)//434=384+50
    {
        line(0,i,1365,i);
    }
    setcolor(GREEN);
    setlinestyle(0,0,3);//x_user=682+x_user*50, y_user=383-y_user*50
    line(782,183,982,33);//(682+50*2,383-50*4)&(682+50*6,383-50*7) or (2,4)&(6,7)
    line(982,33,632,533);//(682+50*6,383-50*7)&(682-50*1,383+50*3) or (6,7)&(-1,-3)
    line(632,533,782,183);//(682-50*1,383+50*3)&(682+50*2,383-50*4) or (-1,-3)&(2,4)
    setcolor(BLUE);
}
void plotcount()
{
    plot_count++;
    if (plot_count==1)
    {
        x_p_1=x_n;
        y_p_1=y_n;
    }
    if (plot_count==2)
    {
        x_p_2=x_n;
        y_p_2=y_n;
    }
    if (plot_count==3)
    {
        x_p_3=x_n;// (2,4),(6,7),(-1,-3)
        y_p_3=y_n;//(782,183),(982,33),(632,533)
        cout<<"\n\n\t\t(2,4) maps to ("<<x_p_1<<","<<y_p_1<<")";
        cout<<"\n\n\t\t(6,7) maps to ("<<x_p_2<<","<<y_p_2<<")";
        cout<<"\n\n\t\t(-1,-3) maps to ("<<x_p_3<<","<<y_p_3<<")";
        x_p_1=682+x_p_1*50;
        y_p_1=383-y_p_1*50;
        x_p_2=682+x_p_2*50;
        y_p_2=383-y_p_2*50;
        x_p_3=682+x_p_3*50;
        y_p_3=383-y_p_3*50;
        setlinestyle(0,0,3);
        line(x_p_1,y_p_1,x_p_2,y_p_2);
        line(x_p_2,y_p_2,x_p_3,y_p_3);
        line(x_p_3,y_p_3,x_p_1,y_p_1);
        setcolor(RED);
        setlinestyle(0,0,1);
        line(x_p_1,y_p_1,782,183);
        line(x_p_2,y_p_2,982,33);
        line(x_p_3,y_p_3,632,533);
        plot_count=0;
    }
}
void translation()
{
    x_n=x+t_x;
    y_n=y+t_y;
    plotcount();
}
void scaling()
{
    a[0][0]=s_x;
    a[0][1]=0;
    a[0][2]=x_f*(1-s_x);
    a[1][0]=0;
    a[1][1]=s_y;
    a[1][2]=y_f*(1-s_y);
    a[2][0]=0;
    a[2][1]=0;
    a[2][2]=1;
    matrix_multiplication();
    plotcount();
}
void rotation()
{
    a[0][0]=cos(thetha);
    a[0][1]=-sin(thetha);
    a[0][2]=x_r*(1-cos(thetha))+y_r*sin(thetha);
    a[1][0]=sin(thetha);
    a[1][1]=cos(thetha);
    a[1][2]=y_r*(1-cos(thetha))-x_r*sin(thetha);
    a[2][0]=0;
    a[2][1]=0;
    a[2][2]=1;
    matrix_multiplication();
    plotcount();
}
void shearing()
{
    a[0][0]=1;
    a[0][1]=sh_x;
    a[0][2]=-sh_x*y_ref;
    a[1][0]=sh_y;
    a[1][1]=1;
    a[1][2]=-sh_y*x_ref;
    a[2][0]=0;
    a[2][1]=0;
    a[2][2]=1;
    matrix_multiplication();
    plotcount();
}
void reflection()
{
    a[0][0]=(1-m*m)/(1+m*m);
    a[0][1]=2*m/(1+m*m);
    a[0][2]=-2*c*m/(1+m*m);
    a[1][0]=2*m/(1+m*m);
    a[1][1]=(m*m-1)/(1+m*m);
    a[1][2]=2*c/(1+m*m);
    a[2][0]=0;
    a[2][1]=0;
    a[2][2]=1;
    matrix_multiplication();
    plotcount();
}
void matrix_multiplication()
{
    x_n=x*a[0][0]+y*a[0][1]+z*a[0][2];
    y_n=x*a[1][0]+y*a[1][1]+z*a[1][2];
    //z_n=x*a[2][0]+y*a[2][1]+z*a[2][2];
}
int main()
{
    int i;
    while(1)
    {
        //cout<<"\n\n\n\t\t\t\t\t1366*768 ";//origin = (682,383)
        cout<<"\n\n\n\t\t\t\t\t(-13.66,0),(13.66,0),(0,-7.66),(0,7.66) ";
        cout<<"\n\n\n\t\t Enter type of 2D Transformation.";
        cout<<"\n\n\t\t 1. Translation";
        cout<<"\n\n\t\t 2. Scaling";
        cout<<"\n\n\t\t 3. Rotation";
        cout<<"\n\n\t\t 4. Shearing";
        cout<<"\n\n\t\t 5. Reflection\n\n";
        cout<<"\n\n\t\t Enter your choice: ";
        cin>>choice;
        if (choice==1)
        {
            cout<<"\n\n\t\t Translation  ";
            cout<<"\n\n\t\t Enter translation in x direction t_x : ";
            cin>>t_x;
            cout<<"\n\n\t\t Enter translation in y direction t_y : ";
            cin>>t_y;
            create_graphics();
            x=2;
            y=4;
            translation();
            x=6;
            y=7;
            translation();
            x=-1;
            y=-3;
            translation();
        }
        if (choice==2)
        {
            cout<<"\n\n\t\t Scaling  ";
            cout<<"\n\n\t\t Enter center of scaling x_f : ";
            cin>>x_f;
            cout<<"\n\n\t\t Enter center of scaling y_f : ";
            cin>>y_f;
            cout<<"\n\n\t\t Enter s_x : ";
            cin>>s_x;
            cout<<"\n\n\t\t Enter s_y : ";
            cin>>s_y;
            create_graphics();
            setcolor(RED);//mark new center as red
            setlinestyle(0,0,8);
            line(682+x_f*50,383-y_f*50,682+x_f*50,383-y_f*50);
            setcolor(BLUE);
			setlinestyle(0,0,2);
            x=2;
            y=4;
            scaling();
            x=6;
            y=7;
            scaling();
            x=-1;
            y=-3;
            scaling();
        }
        if (choice==3)
        {
            cout<<"\n\n\t\t Rotation  ";
            cout<<"\n\n\t\t Enter center of rotation x_r : ";
            cin>>x_r;
            cout<<"\n\n\t\t Enter center of rotation y_r : ";
            cin>>y_r;
            cout<<"\n\n\t\t Enter angle of rotation in degree : ";
            cin>>thetha;
            thetha=thetha*pi/180;
            create_graphics();
            setcolor(RED);//mark new center as red
            setlinestyle(0,0,8);
            line(682+x_r*50,383-y_r*50,682+x_r*50,383-y_r*50);
            setcolor(BLUE);
			setlinestyle(0,0,2);
            x=2;
            y=4;
            rotation();
            x=6;
            y=7;
            rotation();
            x=-1;
            y=-3;
            rotation();
        }
        if (choice==4)
        {
            cout<<"\n\n\t\t Shearing  ";
            cout<<"\n\n\t\t Enter shearing center x_ref : ";
            cin>>x_ref;
            cout<<"\n\n\t\t Enter shearing center y_ref : ";
            cin>>y_ref;
            cout<<"\n\n\t\t Enter sh_x : ";
            cin>>sh_x;
            cout<<"\n\n\t\t Enter sh_y : ";
            cin>>sh_y;
            create_graphics();
            setcolor(RED);//mark new center as red
            setlinestyle(0,0,8);
            line(682+x_ref*50,383-y_ref*50,682+x_ref*50,383-y_ref*50);
            setlinestyle(0,0,2);
            setcolor(BLUE);
            x=2;
            y=4;
            shearing();
            x=6;
            y=7;
            shearing();
            x=-1;
            y=-3;
            shearing();
        }
        if (choice==5)
        {
            cout<<"\n\n\t\t Reflection  ";
            cout<<"\n\n\t\t Enter m: ";
            cin>>m;
            cout<<"\n\n\t\t Enter c : ";
            cin>>c;
            create_graphics();
            setlinestyle(0,0,8);
            setcolor(RED);
            line(682,383-50*c,682,383-50*c);//y=mx+c, y intercept
            line(682+50*-c/m,383,682+50*-c/m,383);//y=mx+c, x intercept
            setlinestyle(0,0,2);
            setcolor(BLUE);//(2,4),(6,7),(-1,-3)
            x=2;
            y=4;
            reflection();
            x=6;
            y=7;
            reflection();
            x=-1;
            y=-3;
            reflection();
        }
        getch();
        closegraph();
    }
    return 0;
}

