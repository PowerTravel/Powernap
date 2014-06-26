#include "MainWindow.h"

MainWindow::MainWindow()
{
	window = NULL;
	zombie = true;
	running = false;
	width = 640;
	height = 480;
	bpp = 32;
	title = "Main Window";

	if( initGLFW() )
	{
		zombie = false;
		running = true;
	}
}

MainWindow::~MainWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}


bool MainWindow::initGLFW()
{
	if( !glfwInit() ){
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if(window == NULL){
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	return true;
}

bool MainWindow::isZombie()
{
	return zombie;
}

bool MainWindow::isRunning()
{
	return running;
}

void MainWindow::getInput()
{
	glfwPollEvents();
}

void MainWindow::update()
{
	running = !glfwWindowShouldClose(window);
}

void MainWindow::draw()
{
	glfwSwapBuffers(window);
}
