/*WAP to implement Mid-Point Ellipse algorithm in Cpp.*/
#include <iostream>//ellipse(x, y, start_angle, end_angle, x_radius, y_radius)
#include <cmath>
#include <graphics.h>
using namespace std;
int x_c,y_c;
float x_n,y_n,p_1,p_2,r_x,r_y;
void draw_ellipse_region_1()
{
    if (p_1<0) //if p_1<0 , x_n = x_n + 1,  p_1=p_1+2*r_y^2*x_n+r_y^2;
    {
        x_n++; // change x_n only
        p_1=p_1+2*r_y*r_y*x_n+r_y*r_y;
    }
    else //if 0<=p_1 , x_n = x_n + 1,  y_n = y_n - 1,  p_1=p_1+2*r_y^2*x_n-2*r_x^2*y_n+r_y^2
{
        x_n++;  // change both x_n and y_n
        y_n--;
        p_1=p_1+2*r_y*r_y*x_n-2*r_x*r_x*y_n+r_y*r_y;
    }
    putpixel(x_c+x_n,y_c+y_n,GREEN); //1st quadrant
    putpixel(x_c-x_n,y_c+y_n,GREEN); //2 nd quadrant
    putpixel(x_c-x_n,y_c-y_n,GREEN); //3 rd quadrant
    putpixel(x_c+x_n,y_c-y_n,GREEN); //4 th quadrant
}
void draw_ellipse_region_2()
{
    if (0<p_2) // if 0<p_2 , y_n=y_n-1, p_2=p_2-2*r_x^2*y_n+r_x^2
    {
        y_n--; // change y_n only
        p_2=p_2-2*r_x*r_x*y_n+r_x*r_x;
    }
    else // if p_2<=0 , y_n=y_n-1, x_n = x_n+1,  p_2=p_2+2*r_y^2*x_n-2*r_x^2*y_n+r_x^2
    {
        x_n++; // change both x_n & y_n
        y_n--;
        p_2=p_2+2*r_y*r_y*x_n-2*r_x*r_x*y_n+r_x*r_x;
    }
    putpixel(x_c+x_n,y_c+y_n,GREEN); //1st quadrant
    putpixel(x_c-x_n,y_c+y_n,GREEN); //2 nd quadrant
    putpixel(x_c-x_n,y_c-y_n,GREEN); //3 rd quadrant
    putpixel(x_c+x_n,y_c-y_n,GREEN); //4 th quadrant
}
int main()
{
    int i;
    while(1)
    {
        cout<<"\n\n\n\t\t\t\t\t1366*768 ";
        cout<<"\n\n\n\t\t Enter ellipse coordinates (x,y,r_x,r_y) with in range (0,0) to (1365,767)";
        cout<<"\n\n Enter (x_c,y_c)";
        cout<<"\n Enter x_c: ";
        cin>>x_c;
        cout<<" Enter y_c: ";
        cin>>y_c;
        cout<<"\n\n Enter r_x: ";
        cin>>r_x;
        cout<<" Enter r_y: ";
        cin>>r_y;
        x_n=0;
        y_n=r_y;
        p_1=r_y*r_y-r_x*r_x*r_y+r_x*r_x/4; //  p_1=r_y^2-r_x^2*r_y+r_x^2/4
        initwindow(1366,768);
        for(i=0; i<=1365; i++) // creates white background
        {
            line(0,i,1365,i);
        }
        //setcolor(GREEN);
        //ellipse(x_c+50,y_c+50,0,360,r_x,r_y);
        while ((r_y*r_y*x_n)<=(r_x*r_x*y_n)) //2*r_y^2*x_n<=2*r_x^2*y_n
        {
            draw_ellipse_region_1();
        }
        p_2=r_y*r_y*(x_n+0.5)*(x_n+0.5)+r_x*r_x*(y_n-1)*(y_n-1)-r_x*r_x*r_y*r_y; //p_2=r_y^2*(x_n+0.5)^2+r_x^2*(y_n-1)^2-r_x^2*r_y^2;
        while (0<y_n)
        {
            draw_ellipse_region_2();
        }
        putpixel(x_c,y_c,GREEN); //At center of ellipse
        putpixel(x_c,y_c+r_y,GREEN); //At topmost point
        putpixel(x_c,y_c-r_y,GREEN); //At bottom point
        getch();
        closegraph();
    }
    return 0;
}

