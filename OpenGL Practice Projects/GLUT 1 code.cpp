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
    glFlush();//empties all commands in these buffers and forces all pending commands will to be executed immediately without waiting buffers are full
}
int main(int argc,char** argv)//argc parameter represents the number of command line arguments, and char *argv[] is an array of strings (character pointers) representing the individual arguments provided on the command line
{
    glutInit(&argc,argv);//used to initialize the GLUT library
    glutInitDisplayMode(GLUT_RGB);//sets the initial display mode,GLUT_RGB is Bit mask to select a color index mode window

    glutInitWindowPosition(0,0);//creates window from this location
    glutInitWindowSize(1366,768);//window size

    glutCreateWindow("Window1");//call back function, it creates a top-level window

    glutDisplayFunc(display);//sets the display callback for the current window
    
     init0();
    glutMainLoop();//enters the GLUT event processing loop
}




