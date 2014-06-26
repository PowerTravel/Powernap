#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class MainWindow
{	
	public:
		
		// Constructor and destructor
		MainWindow();	
		virtual ~MainWindow();

		// Public members
		bool isZombie();
		bool isRunning();

		void getInput();
		void update();
		void draw();

	private:

		// Fields
		GLFWwindow* window;

		int width;
		int height;
		int bpp;
		std::string title;
		bool zombie;
		bool running;

		// Initiates glfw and creates a window.
		bool initGLFW();
};


#endif // MAINWINDOW_H
