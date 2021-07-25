/*WAP to implement 3D Transformation.*/
/*
choice=1 ,  Translation, set t_x,t_y,t_z
choice=2 ,  Rotation about z axis (XY plane), set thitha
choice=3 ,  Rotation about x axis (YZ plane), set thitha
choice=4 ,  Rotation about y axis (XZ plane), set thitha
choice=5 ,  Scaling about a fixed point, set s_x,s_y,s_z,x_f,y_f,z_f
choice=6 ,  Refletion about z axis (XY plane)
choice=7 ,  Reflection about x axis (YZ plane)
choice=8 ,  Reflection about y axis (XZ plane)
choice=9 ,  Shearing about z axis keeping z same (XY plane), set sh_x,sh_y
choice=10,  Shearing about x axis keeping x same (YZ plane), set sh_y,sh_z
choice=11 , Shearing about y axis keeping y same (ZX plane), set sh_x,sh_z
*/
int choice=5;
float t_x=100,t_y=-150,t_z=-300;//Translation
float thitha=60;//Rotation thitha in degree
float s_x=2,s_y=2,s_z=2,x_f=20,y_f=-30,z_f=40 ;//Scaling
float sh_x=2,sh_y=-1,sh_z=-1.333;//Shearing
float a=400,b=-150,c=-150,d=300,e=-100,f=100,i=-50,j=100,k=120,l=-100,m=-230,n=10;
float ac=400,bc=-150,cc=200,dc=300,ec=-100,fc=150,ic=-50,jc=100,kc=200,lc=-100,mc=-230,nc=90;
void setup() 
{
 size(1300,700,P3D);
 draw();
 jump();
 endShape();
}
void draw()
{
 translate(width/2, height/2, 0);
 rotateX(PI/2);
 rotateZ(-PI/6);
 noFill();

 beginShape();
 strokeWeight(3);
 
 stroke(0,0,255);
 vertex(a,b,c);
 vertex(d,e,f);
 vertex(i,j,k);
 
 vertex(i,j,k);
 vertex(l,m,n);
 vertex(d,e,f);
 
 vertex(l,m,n);
 vertex(a,b,c);
 vertex(i,j,k);

 vertex(a,b,c);
 vertex(l,m,n);
 vertex(d,e,f);
 
  endShape();
  
  beginShape();
 
 stroke(0,0,0);
 vertex(ac,bc,cc);
 vertex(dc,ec,fc);
 vertex(ic,jc,kc);
 
 vertex(ic,jc,kc);
 vertex(lc,mc,nc);
 vertex(dc,ec,fc);
 
 vertex(lc,mc,nc);
 vertex(ac,bc,cc);
 vertex(ic,jc,kc);

 vertex(ac,bc,cc);
 vertex(lc,mc,nc);
 vertex(dc,ec,fc);
 
 endShape();
 
 strokeWeight(0.5);
 
 stroke(0,255,0);
 line(a,b,c,ac,bc,cc);
 line(d,e,f,dc,ec,fc); 
 line(i,j,k,ic,jc,kc);
 line(l,m,n,lc,mc,nc);
}
void jump()
{
  if (choice==1) translation();
  if (choice==2) rotation_z();
  if (choice==3) rotation_x();
  if (choice==4) rotation_y();
  if (choice==5) scaling();
  if (choice==6) reflection_z();
  if (choice==7) reflection_x();
  if (choice==8) reflection_y();
  if (choice==9) shearing_z();
  if (choice==10) shearing_x();
  if (choice==11) shearing_y();
}
void translation()//choice=1
{
  ac=a+t_x;
  bc=b+t_y;
  cc=c+t_z;
  
  dc=d+t_x;
  ec=e+t_y;
  fc=f+t_z;
  
  ic=i+t_x;
  jc=j+t_y;
  kc=k+t_z;
  
  lc=l+t_x;
  mc=m+t_y;
  nc=n+t_z;
}
void rotation_z()//choice=2
{
  thitha =thitha * 3.1415 /180;
  
  ac=a*cos(thitha)-b*sin(thitha);
  bc=a*sin(thitha)+b*cos(thitha);
  cc=c;
  
  dc=d*cos(thitha)-e*sin(thitha);
  ec=d*sin(thitha)+e*cos(thitha);
  fc=f;
  
  ic=i*cos(thitha)-j*sin(thitha);
  jc=i*sin(thitha)+j*cos(thitha);
  kc=kc+t_z;
  
  lc=l*cos(thitha)-m*sin(thitha);
  mc=l*sin(thitha)+m*cos(thitha);
  nc=n;
}
void rotation_x()//choice=3
{
  thitha =thitha * 3.1415 /180;
  
  ac=a;
  bc=b*cos(thitha)-c*sin(thitha);
  cc=b*sin(thitha)+c*cos(thitha);
  
  dc=d;
  ec=e*cos(thitha)-f*sin(thitha);
  fc=f*sin(thitha)+f*cos(thitha);
  
  ic=i;
  jc=j*cos(thitha)-k*sin(thitha);
  kc=j*sin(thitha)+k*cos(thitha);
  
  lc=l;
  mc=m*cos(thitha)-n*sin(thitha);
  nc=m*sin(thitha)+n*cos(thitha);
  
}
void rotation_y()//choice=4
{
  thitha =thitha * 3.1415 /180;
  
  ac=c*sin(thitha)+a*cos(thitha);
  bc=b;
  cc=c*cos(thitha)-a*sin(thitha);
  
  dc=f*sin(thitha)+d*cos(thitha);
  ec=e;
  fc=f*cos(thitha)-d*sin(thitha);
  
  ic=k*sin(thitha)+i*cos(thitha);
  jc=j;
  kc=k*cos(thitha)-i*sin(thitha);
  
  lc=n*sin(thitha)+l*cos(thitha);
  mc=m;
  nc=n*cos(thitha)-l*sin(thitha);
}
void scaling()//choice=5
{
  ac=a*s_x+(1-s_x)*x_f;
  bc=b*s_y+(1-s_y)*y_f;
  cc=c*s_z+(1-s_z)*z_f;
  
  dc=d*s_x+(1-s_x)*x_f;
  ec=e*s_y+(1-s_y)*y_f;
  fc=f*s_z+(1-s_z)*z_f;
  
  ic=i*s_x+(1-s_x)*x_f;
  jc=j*s_y+(1-s_y)*y_f;
  kc=k*s_z+(1-s_z)*z_f;
  
  lc=l*s_x+(1-s_x)*x_f;
  mc=m*s_y+(1-s_y)*y_f;
  nc=n*s_z+(1-s_z)*z_f;
}
void reflection_z()//choice=6
{
  ac=a;
  bc=b;
  cc=-c;
  
  dc=d;
  ec=e;
  fc=-f;
  
  ic=i;
  jc=j;
  kc=-k;
  
  lc=l;
  mc=m;
  nc=-n;
}
void reflection_x()//choice=7
{
  ac=-a;
  bc=b;
  cc=c;
  
  dc=-d;
  ec=e;
  fc=f;
  
  ic=-i;
  jc=j;
  kc=k;
  
  lc=-l;
  mc=m;
  nc=n;
}
void reflection_y()//choice=8
{
  ac=a;
  bc=-b;
  cc=c;
  
  dc=d;
  ec=-e;
  fc=f;
  
  ic=i;
  jc=-j;
  kc=k;
  
  lc=l;
  mc=-m;
  nc=n;
}
void shearing_z()//choice=9
{
  ac=a+sh_x*c;
  bc=b+sh_y*c;
  cc=c;
  
  dc=d+sh_x*f;
  ec=e+sh_y*f;
  fc=f;
  
  ic=i+sh_x*k;
  jc=j+sh_y*k;
  kc=k;
  
  lc=l+sh_x*n;
  mc=m+sh_y*n;
  nc=n;
}
void shearing_x()//choice=10
{
  ac=a;
  bc=b+sh_y*a;
  cc=c+sh_z*a;
  
  dc=d;
  ec=e+sh_y*d;
  fc=f+sh_z*d;
  
  ic=i;
  jc=j+sh_y*i;
  kc=k+sh_z*i;
  
  lc=l;
  mc=m+sh_y*l;
  nc=n+sh_z*l;
}
void shearing_y()//choice=11
{
  ac=a+sh_x*b;
  bc=b;
  cc=c+sh_z*b;
  
  dc=d+sh_x*e;
  ec=e;
  fc=f+sh_z*e;
  
  ic=i+sh_x*j;
  jc=j;
  kc=k+sh_z*j;
  
  lc=l+sh_x*m;
  mc=m;
  nc=n+sh_x*m;
}
