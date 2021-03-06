#include <iostream>
#include <stdio.h>
#include "ShaderTools.h"
#include "MainWindow.h"
//#include <glm/glmp>
GLFWwindow* initGLFW();
bool initGL();

int main(int argc, const char *argv[])
{
	MainWindow window = MainWindow();
	if(window.isZombie()){
		std::cout<<"Main Window is a zombie."<<std::endl;
		exit(EXIT_FAILURE);
	}

	if( !initGL() ){
		std::cout<<"GL failed to initiate"<<std::endl;
		exit(EXIT_FAILURE);
	}

	Rect r = window.getWindowDim();
	printf("Window dim at start: %d, %d, %d, %d \n", r.x, r.y, r.w, r.h);
	while( window.isRunning() )
	{
		window.getInput();
		window.update();
		window.draw();
	}
	
	r = window.getWindowDim();
	printf("Window dim at exit: %d, %d, %d, %d \n", r.x, r.y, r.w, r.h);

	std::cout<<"All is ok."<<std::endl;

	return 0;
}

bool initGL()
{
	
	glewExperimental = GL_TRUE;
	if( glewInit() != GLEW_OK ){
		return false;
	}

	GLuint program = initProgram("shaders/vshader.glsl","shaders/fshader.glsl");

	glUseProgram(program);

	glLineWidth(1.0);
	glPointSize(1.0);
	glClearColor(0.0,0.0,0.0,0.0);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	
	return true;
}
