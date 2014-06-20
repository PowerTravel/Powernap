#include <iostream>
#include "ShaderTools.h"
//#include <glm/glm.hpp>
GLFWwindow* initGLFW();
bool initGL();


int main(int argc, const char *argv[])
{

	GLFWwindow* window = NULL;
	if( (window = initGLFW()) == NULL ){
		exit(EXIT_FAILURE);
	}

	if( !initGL() ){
		exit(EXIT_FAILURE);
	}
	
	std::cout<<"All is ok."<<std::endl;

	return 0;
}

bool initGL()
{
	
	glewExperimental = GL_TRUE;
	if( glewInit() != GLEW_OK ){
		return false;
	}

	GLuint program = initProgram("vshader.glsl","fshader.glsl");

	glUseProgram(program);

	//initiateGLSLVariables(&program);

	glLineWidth(1.0);
	glPointSize(1.0);
	glClearColor(0.0,0.0,0.0,0.0);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	
	return true;
}

GLFWwindow* initGLFW()
{
	GLFWwindow* window = NULL;

	if( !glfwInit() ){
		return NULL;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	

	window = glfwCreateWindow(640, 480, "Compilation Test", NULL, NULL);

	if(window == NULL){
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);

	return window;
}
