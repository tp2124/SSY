#include "SSYGraphicsManager.h"
#include "../Sys/def_dbg.h"
#include <stdio.h>

#ifdef RENDER_DX
#include <set>
#include <d3d9.h>
#include <d3dx9math.h>
#else ifdef RENDER_OPENGL
#include <GL/glu.h>
#include <GL/glut.h>
#endif

float g_vLandRotate[3] = {0.0, 0.0, 0.0};
float g_vLandTranslate[3] = {0.0, 0.0, 0.0};
float g_vLandScale[3] = {1.0, 1.0, 1.0};


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glScalef(g_vLandScale[0],g_vLandScale[1],g_vLandScale[2]);

    glRotatef(g_vLandRotate[0], 1.0, 0.0, 0.0);
	glRotatef(g_vLandRotate[1], 0.0, 1.0, 0.0);
	glRotatef(g_vLandRotate[2], 0.0, 0.0, 1.0);

	glTranslatef(g_vLandTranslate[0],g_vLandTranslate[1],g_vLandTranslate[2]);
			
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f); 
	glColor3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.0f); 
	glColor3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glEnd();

	//Double buffer swap
	glutSwapBuffers();
}

void menufunc(int value)
{
  switch (value)
  {
    case 0:
      exit(0);
      break;
  }
}

int g_iMenuId;

int SSY::SSYGraphicsManager::Setup()
{
	char *args[]= {"executable.exe"};
	int numArgs = 1;

	glutInit(&numArgs, args);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SwagSwirvYolo");
	glutDisplayFunc(display);

	g_iMenuId = glutCreateMenu(menufunc);
	glutSetMenu(g_iMenuId);
	glutAddMenuEntry("Quit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/* setup gl view here */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	
	glutMainLoop();
	//// Initialise GLFW
	//if( !glfwInit() )
	//{
	//	fprintf( stderr, "Failed to initialize GLFW\n" );
	//	Dbg_Assert(0, "Failed to initialize GLFW\n");
	//	return 0;
	//}

	//glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	//glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//// Open a window and create its OpenGL context
	//if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	//{
	//	fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
	//	Dbg_Assert(0, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
	//	return 0;
	//}

	//// Initialize GLEW
	//if (glewInit() != GLEW_OK) {
	//	fprintf(stderr, "Failed to initialize GLEW\n");
	//	Dbg_Assert(0, "Failed to initialize GLFW\n");
	//	return 0;
	//}

	//glfwSetWindowTitle( "Tutorial 01" );

	//// Ensure we can capture the escape key being pressed below
	//glfwEnable( GLFW_STICKY_KEYS );

	//// Dark blue background
	//glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	return 1;
}

void SSY::SSYGraphicsManager::Render()
{

}

void SSY::SSYGraphicsManager::Cleanup()
{
	
}