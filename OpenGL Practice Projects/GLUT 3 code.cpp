#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
float x_position=-10.0;
bool direction=true;//if direction=true moves forward, else moves backward
void init0()
{
    glClearColor(0,0,0,1);//specify clear values for the color buffers
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//clear buffers to preset values,GL_COLOR_BUFFER_BIT clears the OpenGL color and depth buffers

    glLoadIdentity();//replace the current matrix with the identity matrix
    //draw

     glBegin(GL_POLYGON);//GL_POLYGON Treats each triplet of vertices as an independent polygon

    glVertex2f(x_position,1.0);
    glVertex2f(x_position,-1.0);
    glVertex2f(x_position+2.0,-1.0);
    glVertex2f(x_position+2.0,1.0);
    if (x_position<8 && direction==true)
        x_position=x_position+0.15;
    else if (-10<=x_position)
    {
        x_position=x_position-0.15;
        direction=false;
    }
    else
        direction=true;
    glEnd();//delimit the vertices of a primitive or a group of like primitives

    glutSwapBuffers();//swaps the buffers of the current window if double buffered
}
void reshape(int w, int h)
{
    glViewport(0,0,w,h);//set the viewport
    glMatrixMode(GL_PROJECTION);//specify which matrix is the current matrix, GL_PROJECTION applies subsequent matrix operations to the projection matrix stack
    glLoadIdentity();//replace the current matrix with the identity matrix
    gluOrtho2D(-10,10,-10,10);//sets up a two-dimensional orthographic viewing region
    glMatrixMode(GL_MODELVIEW);//GL_MODELVIEW applies subsequent matrix operations to the modelview matrix stack,GL_MODELVIEW applies subsequent matrix operations to the modelview matrix stack
}
void timer(int)
{
    glutPostRedisplay();//marks the current window as needing to be redisplayed
    glutTimerFunc(17,timer,0 );//1000/60=16.6667=17
}
int main(int argc,char** argv)//argc parameter represents the number of command line arguments, and char *argv[] is an array of strings (character pointers) representing the individual arguments provided on the command line
{
    glutInit(&argc,argv);//used to initialize the GLUT library
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//sets the initial display mode,GLUT_RGB is Bit mask to select a color index mode window, In a double buffered scenario (GLUT_DOUBLE), there exist two framebuffer. One is used for drawing, the other one for display. At the end of each frame, these buffers are swapped.

    glutInitWindowPosition(0,0);//creates window from this location
    glutInitWindowSize(1366,768);//window size

    glutCreateWindow("Window1");//call back function, it creates a top-level window

    glutReshapeFunc(reshape);//call back function resize, it adjust graphics once it is resized
    glutDisplayFunc(display);//sets the display callback for the current window

    glutTimerFunc(0,timer,0);//registers a timer callback to be triggered in a specified number of milliseconds. 1000ms=1s
     init0();
    glutMainLoop();//enters the GLUT event processing loop
}




