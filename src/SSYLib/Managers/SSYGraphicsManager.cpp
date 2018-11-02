#include "SSYGraphicsManager.h"
#include "../Sys/def_dbg.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef RENDER_DX
#include <set>
#include <d3d9.h>
#include <d3dx9math.h>
#else ifdef RENDER_OPENGL
// Include GLEW
#include <GL\glew.h>

// Include GLFW
#include <GL\glfw.h>

// Include GLM
//#include <glm.hpp>
#endif


int SSY::SSYGraphicsManager::Setup()
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		Dbg_Assert(0, "Failed to initialize GLFW\n");
		return 0;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	{
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		Dbg_Assert(0, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		return 0;
	}

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		Dbg_Assert(0, "Failed to initialize GLFW\n");
		return 0;
	}

	glfwSetWindowTitle( "Tutorial 01" );

	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	return 1;
}

void SSY::SSYGraphicsManager::Render()
{

}

void SSY::SSYGraphicsManager::Cleanup()
{
	
}