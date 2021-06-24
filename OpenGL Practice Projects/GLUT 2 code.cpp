#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void init0()
{
    glClearColor(0,0,0,1);//specify clear values for the color buffers
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//clear buffers to preset values,GL_COLOR_BUFFER_BIT clears the OpenGL color and depth buffers

    glLoadIdentity();//replace the current matrix with the identity matrix
    //draw
    //glBegin(GL_POINTS);//delimit the vertices of a primitive or a group of like primitives,GL_POINTS treats each vertex as a single point

    //glPointSize(10.0);// specify the diameter of rasterized points
    //glVertex2f(5.0,5.0);//specify a vertex
    //glVertex2f(5.0,-5.0);//specify a vertex
    //glVertex2f(-5.0,5.0);//specify a vertex

    //glBegin(GL_TRIANGLES);//delimit the vertices of a primitive or a group of like primitives,GL_TRIANGLES Treats each triplet of vertices as an independent triangle, draws a connected group of triangles

    //glVertex2f(0.0,7.0);
    //glVertex2f(4.0,-3.0);
    //glVertex2f(-4.0,3.0);

    //glBegin(GL_QUADS);//GL_QUADS Treats each triplet of vertices as an independent quadrilateral

    //glVertex2f(0.0,7.0);
    //glVertex2f(4.0,-3.0);
    //glVertex2f(-4.0,3.0);
     //glVertex2f(6.0,-6.0);

     glBegin(GL_POLYGON);//GL_POLYGON Treats each triplet of vertices as an independent polygon

    glVertex2f(0.0,7.0);
    glVertex2f(4.0,-3.0);
    glVertex2f(-4.0,3.0);
     glVertex2f(3.0,-6.0);
     glVertex2f(8.0,-9.0);

    glEnd();//delimit the vertices of a primitive or a group of like primitives
    glFlush();//empties all commands in these buffers and forces all pending commands will to be executed immediately without waiting buffers are full
}
void reshape(int w, int h)
{
    glViewport(0,0,w,h);//set the viewport
    glMatrixMode(GL_PROJECTION);//specify which matrix is the current matrix, GL_PROJECTION applies subsequent matrix operations to the projection matrix stack
    glLoadIdentity();//replace the current matrix with the identity matrix
    gluOrtho2D(-10,10,-10,10);//sets up a two-dimensional orthographic viewing region
    glMatrixMode(GL_MODELVIEW);//GL_MODELVIEW applies subsequent matrix operations to the modelview matrix stack,GL_MODELVIEW applies subsequent matrix operations to the modelview matrix stack
}
int main(int argc,char** argv)//argc parameter represents the number of command line arguments, and char *argv[] is an array of strings (character pointers) representing the individual arguments provided on the command line
{
    glutInit(&argc,argv);//used to initialize the GLUT library
    glutInitDisplayMode(GLUT_RGB);//sets the initial display mode,GLUT_RGB is Bit mask to select a color index mode window

    glutInitWindowPosition(0,0);//creates window from this location
    glutInitWindowSize(1366,768);//window size

    glutCreateWindow("Window1");//call back function, it creates a top-level window

    glutReshapeFunc(reshape);//call back function resize, it adjust graphics once it is resized
    glutDisplayFunc(display);//sets the display callback for the current window

     init0();
    glutMainLoop();//enters the GLUT event processing loop
}




