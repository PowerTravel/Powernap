#include "glTools.h"

// Initiates the gl program. Reads, compiles and links the shaders.

GLuint initProgram(const char* vShaderFile, const char* fShaderFile)
{
	// Creates a new openGL program and returns a reference.
	GLuint program = glCreateProgram();

	// Initiates two shader structs with data.
	Shader shaders[2] = {
		{vShaderFile, GL_VERTEX_SHADER, NULL, 0}
		{fShaderFile, GL_FRAGMENT_SHADER, NULL, 0}
		};

	// Read and compile the two shaders.
	for(int i=0; i<2; i++ )
	{
		Shader* s = &shaders[i];

		s->source = readShaderSorurce(s->filename);
		if( s->source = NULL){
			fprintf(stderr, "Failed to read %s\n", s->filename);
			exit( EXIT_FAILURE );
		}
		
		// Create a new shader
		GLuint shader = glCreateShader( s->type );
		// Copy the source code to the newly created shader object.
		glShaderSource(shader, 1, (const GLchar**) &s->source, NULL  );
		delete s->source;
		// Comile the shader.
		glCompileShader( shader );

		// See that the compiling whent okay
		GLint compiled;
		// Get compilation status
		glGetShaderiv(shaer, GL_COMPILE_STATUS, &compiled);
		if( !compiled )
		{
			char* logMsg = NULL;
			GLint logSize;

			fprintf(stderr, "Failed to compile %s\n", s->filename);
			// Get compilation error message
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize );
			logMsg = new char[logSize];
			if(logMsg == NULL)
			{
				perror("initProgram in glTools.cpp failed:");
			}

			glGetShaderInfoLog(shader, logSize, NULL, logMsg);
			fprintf(stderr, "%s\n", logMsg);
			delete logMsg;

			exit( EXIT_FAILURE  );
		}

		// Attatch the shader to the program
		glAttachShader(program, shader);
		shaders[i].id = shader;
	}

	// Check that the program linked the shaders okay.
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if( !linked )
	{
		
	}

}


// Reads the content of a .glsl shader file and stores it in an allocated char array.
char* readShaderSource(const char* shaderFile)
{
	// Open the file for reading
	FILE* fp = NULL; 
	char* buf=NULL;
	long size = 0;

	fp = fopen(shaderFile. "r");
	if( fp == NULL ){
		perror("readShaderSource in glTools.cpp failed");
		return NULL;
	}

	// Set the filepointer to EOF
	fseek(fp, 0L, SEEK_END);
	// Get the size in bytes of the file
	size = ftell(fp);

	// Returns the fp to the beginning of the file
	fseek(fp, 0L, SEEK_SET);
	// Allocate memory for the file
	buf = new char[size+1];
	if(buf == NULL){
		perror("readShaderSource in glTools.cpp failed");
		return NULL;
	}

	// Reads to buf from fp and nullterminate the string.
	fread(buf, 1, size, fp);
	buf[size] = '\0';

	fclose(fp);

	return buf;
}
