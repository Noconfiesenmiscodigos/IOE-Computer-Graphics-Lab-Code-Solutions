/*WAP to implement Mid-Point Circle algorithm in Cpp.*/
#include <iostream>//circle(x,y,r)
#include <cmath>
#include <graphics.h>
using namespace std;
int x,y;
float x_n,y_n,p_n,r;
void draw_circle()
{
    if (p_n<0) // if p_n < 0 , x_n=x_n+1 , p_n=p_n+2*x_n+1
    {
        x_n++; // change x_n only
        p_n=p_n+2*x_n+1;
    }
    else // if 0 < = p_n , x_n=x_n+1 , y_n=y_n-1 , p_n=p_n+2*y_n+1
    {
         x_n++; // change x_n & y_n
         y_n--;
        p_n=p_n+2*x_n-2*y_n+1;
    }
    putpixel(x+x_n,y+y_n,GREEN); // 1st octant
    putpixel(x+y_n,y+x_n,GREEN); // 2 nd octant
    putpixel(x-y_n,y+x_n,GREEN); // 3 rd octant
    putpixel(x-x_n,y+y_n,GREEN); // 4 th octant
    putpixel(x-x_n,y-y_n,GREEN); // 5 th octant
    putpixel(x-y_n,y-x_n,GREEN); // 6 th octant
    putpixel(x+y_n,y-x_n,GREEN); // 7 th octant
    putpixel(x+x_n,y-y_n,GREEN); // 8 th octant
}
int main()
{
    int i;
    while(1)
    {
        cout<<"\n\n\n\t\t\t\t\t1366*768 ";
        cout<<"\n\n\n\t\t Enter circle coordinates (x,y,r) with in range (0,0) to (1365,767)";
        cout<<"\n\n Enter (x,y)";
        cout<<"\n Enter x: ";
        cin>>x;
        cout<<" Enter y: ";
        cin>>y;
        cout<<"\n\n Enter r: ";
        cin>>r;
        x_n=0;
        y_n=r;
        p_n=1.25-r; // p_n = 5/4 -r
        initwindow(1366,768);
        for(i=0; i<=1365; i++) // creates white background
        {
            line(0,i,1365,i);
        }
        //setcolor(GREEN);
        //circle(x,y,r+50);
        putpixel(x,y,GREEN); // At center of circle
        putpixel(x-r,y,GREEN); //At leftmost point
        putpixel(x+r,y,GREEN); //At rightmost point
        putpixel(x,y+r,GREEN); //At topmost point
        putpixel(x,y-r,GREEN); //At bottom point
        while (x_n<=y_n) // at 1st octant when angle = 45 degree x_0 = y_0
        {
            draw_circle();
        }
        getch();
        closegraph();
    }
    return 0;
}
