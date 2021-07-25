/*WAP to implement Cohen Sutherland Algorithm in Cpp.*/
#include <iostream>
#include <cmath>
#include <graphics.h>
#define pi 3.141592654
using namespace std;
int i,plot_count;
float m,x_1,y_1,x_2,y_2,xe1,ye1,xe2,ye2;
int b1,b2,b3,b4,b5,b6,b7,b8;
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
    setcolor(BLUE);
    setlinestyle(0,0,3);
    line(0,183,1366,183);//horizontal +ve
    line(0,583,1366,583);//horizontal -ve
    line(982,0,982,763);//vertcal +ve
    line(382,0,382,763);//vertcal -ve
}
void sutherland()
{
	if (x_1<-6) b1=1;
	else b1=0;
	if (6<x_1) b2=1;
	else b2=0;
	if (y_1<-4) b3=1;
	else b3=0;
	if (4<y_1) b4=1;
	else b4=0;
	
	if (x_2<-6) b5=1;
	else b5=0;
	if (6<x_2) b6=1;
	else b6=0;
	if (y_2<-4) b7=1;
	else b7=0;
	if (4<y_2) b8=1;
	else b8=0;
	
	if (b1==0 && b2==0 && b3==0 && b4==0 && b5==0 && b6==0 && b7==0 && b8==0)
	{   
	    setcolor(GREEN);
		line(682+x_1*50,383-50*y_1,682+x_2*50,383-50*y_2);
	}
	else if (b1*b5!=0 || b2*b6!=0 || b3*b7!=0 || b4*b8!=0)
	{
		setcolor(RED);
		line(682+x_1*50,383-50*y_1,682+x_2*50,383-50*y_2);
	}
	else 
	{
		m=(y_2-y_1)/(x_2-x_1);
		setcolor(RED);
		line(682+x_1*50,383-50*y_1,682+x_2*50,383-50*y_2);
		if (b1==1)
		{
		   xe1=-6;
		   ye1=y_1+m*(xe1-x_1);	
		}
		if (b2==1)
		{
		   xe1=6;
		   ye1=y_1+m*(xe1-x_1);	
		}
		if (b3==1)
		{
		   ye1=-4;
		   xe1=x_1+(ye1-y_1)/m;	
		}
		if (b4==1)
		{
		   ye1=4;
		   xe1=x_1+(ye1-y_1)/m;	
		}
		if (b5==1)
		{
		   xe2=-6;
		   ye2=y_2+m*(xe2-x_2);	
		}
		if (b6==1)
		{
		   xe2=6;
		   ye2=y_2+m*(xe2-x_2);	
		}
		if (b7==1)
		{
		   ye2=-4;
		   xe2=x_2+(ye2-y_2)/m;	
		}
		if (b8==1)
		{
		   ye2=4;
		   xe2=x_2+(ye2-y_2)/m;	
		}
		setcolor(CYAN);
        line(682+xe1*50,383-50*ye1,682+xe2*50,383-50*ye2);
        cout<<endl<<" xe1 = "<<xe1<<" ye1 = "<<ye1<<" xe2 = "<<xe2<<" ye2 = "<<ye2;
        cout<<endl<<" b1 = "<<b1<<" b2 = "<<b2<<" b3 = "<<b3<<" b4 = "<<b4;
        cout<<endl<<" b5 = "<<b5<<" b6 = "<<b6<<" b7 = "<<b7<<" b8 = "<<b8;
    }
}
int main()
{
    while(1)
    {
    	cout<<"\n\n\n\t\t\t\t\tCohen Sutherland Algorithm";
    	cout<<"\n\n\n\t\t\t\t(-13.66,0),(13.66,0),(0,-7.66),(0,7.66) ";
    	cout<<"\n\n\n\t\t\t\t\t(-6,4),(-6,-4),(6,-4),(6,4)";
    	cout<<"\n\n\n\t\t Enter coordinate of two points: ";
        cout<<"\n\n\t\t Enter x_1: ";
        cin>>x_1;
        cout<<"\n\n\t\t Enter y_1: ";
        cin>>y_1;
        cout<<"\n\n\t\t Enter x_2: ";
        cin>>x_2;
		cout<<"\n\n\t\t Enter y_2: ";
        cin>>y_2;
        create_graphics();
        sutherland();
    	getch();
    	closegraph();
	}
    return 0;
}


