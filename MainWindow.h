#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Timer.h"

struct Rect
{
	int x;
	int y;
	int w;
	int h;
};

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

		Rect getWindowDim();
		void setWindowDim(Rect r);
	private:

		// Fields
		GLFWwindow* window;
		
		static bool INITIALIZED;

		int width;
		int height;
		int bpp;
		std::string header;
		bool zombie;
		bool running;

		Timer fpsLock;
		Timer fpsCount;
		int FRAMES_PER_SECOND;
		int frameCounter;
		bool countFPS;


		// Initiates glfw and creates a window.
		bool initGLFW();
};


#endif // MAINWINDOW_H
