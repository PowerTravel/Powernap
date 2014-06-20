// Works on both OSX and CS

#ifndef SHADERTOOLS_H
#define SHADERTOOLS_H

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>

// GL,GLEW, FreeGLUT, GLFW headers
//#include <GL/glew.h>

//#ifdef CS
//#include <GL/freeglut.h>
//#include <GL/freeglut_ext.h>

struct Shader
{
	const char* filename; 	// contains the filename of the shader.
	GLenum type;			// Tells us what type of shader it contains.
	GLchar* source;			// Contains the source code
	GLuint s;
};

char* readShaderSource(const char* shaderFile);
extern GLuint initProgram(const char* vShaderFile, const char* fShaderFile);

#endif // SHADERTOOLS_H
