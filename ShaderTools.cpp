#include "CommonHeaders.h"
#include "ShaderTools.h"
// Reads the content of a .glsl shader file and saves its content into an allocated buffert.
char* readShaderSource(const char* shaderFile)
{
	// Open the file
	FILE* fp = fopen(shaderFile, "r");
	long size;
	char* buf;

	if( fp == NULL )
	{
		fprintf(stderr, "fopen failed in readShaderSource()");
		return NULL;
	}

	// Sett the filepointer to EOF
	fseek(fp, 0L, SEEK_END);
	// Gets size in bytes of the file
	size = ftell(fp);

	// Returns the fp to the beginning of file
	fseek(fp, 0L, SEEK_SET);
	// Allocate memory for the file
	errno = 0;
	buf = (char*)malloc((size+1));
	if(buf == NULL)
	{
		fprintf(stderr, "ERROR, malloc failed in readShaderSource()");
		if(errno!=0)
		{
			fprintf(stderr, " with errno message:\n %s", strerror(errno));
		}
		fprintf(stderr, "\n");
		return NULL;
	}

	// Reads to buf from fp which has 1*size data.
	fread(buf, 1, size, fp);
	
	// Null-terminate the string
	buf[size] = '\0';
	fclose(fp);

	return buf;
}

// Inits the GL program. Reads, compiles and links the shaders.
GLuint initProgram(const char* vShaderFile, const char* fShaderFile)
{
	GLuint program;

	// Fill an array of shaders structs with data
	Shader shaders[2] = {
		{ vShaderFile, GL_VERTEX_SHADER, NULL,0 },
		{ fShaderFile, GL_FRAGMENT_SHADER, NULL,0 }
	};
	
	// Creates an openGL program which can be refferenced
	program = glCreateProgram();

	// In this loop we read, copy and compile the shader files onto the saders
	// which we link to the program.
	for(int i = 0; i<2; i++)
	{
		Shader* s = &shaders[i];

		// Read the shader-file and copy its contents onto the struct
		s->source = readShaderSource( s->filename );
		if( s->source == NULL )
		{
			fprintf(stderr, "Failed to read %s\n", s->filename);
			exit( EXIT_FAILURE );
		}

		// Create a shader object of specified type
		GLuint shader = glCreateShader( s->type );
		// Copies the source-code in the provided shader file. 
		// The second arguments tells how many rows there are in the GLchar**
		// The third argument gives an array of code to be loaded into the shader.
		// The fourth argument spcifies an array of shader lengths.
		// Note: The source code is copied so we can free the memory on our end after this. (well do it later)
		glShaderSource(shader, 1, (const GLchar**) &s->source, NULL );
		glCompileShader( shader );
		free(s->source);

		// See if everything went a-ok and print the error log if not.
		GLint compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if( !compiled )
		{
			char* logMsg;
			GLint logSize;
			
			fprintf(stderr, "Failed to compile %s\n", s->filename);
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
			errno = 0;
			logMsg = (char*)malloc(logSize*sizeof(char*));
			if(logMsg == NULL)
			{
				fprintf(stderr, "Malloc failed to allocate memory for comilation error message.");
				if(errno!=0)
				{
					fprintf(stderr, " with errno message:\n %s", strerror(errno));
				}
				fprintf(stderr, "\n");
			}
			glGetShaderInfoLog(shader, logSize, NULL, logMsg);
			fprintf(stderr, "%s\n", logMsg);
			free(logMsg);

			exit( EXIT_FAILURE );
		}

		// Lastly we attach the shader to the program
		glAttachShader(program, shader);
		shaders[i].s = shader;
	}

	// Link the program (to what? the state? what does that mean?)
	glLinkProgram(program);
	
	// Check that the program loaded okay, or print any error messages.
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if( !linked )
	{
		char* logMsg;
		GLint logSize;
		
		fprintf(stderr, "Shader program failed to link.\n");

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
		errno = 0;
		logMsg = (char*)malloc(logSize*sizeof(char*));
		if(logMsg == NULL)
		{
			fprintf(stderr, "Malloc failed to allocate memory for comilation error message.");
			if(errno!=0)
			{
				fprintf(stderr, " with errno message:\n %s", strerror(errno));
			}
			fprintf(stderr, "\n");
		}
		glGetProgramInfoLog(program, logSize, NULL, logMsg);
		fprintf(stderr, "%s\n", logMsg);
 		free(logMsg);
		exit( EXIT_FAILURE );
	}

	glDeleteShader(shaders[0].s);
	glDeleteShader(shaders[1].s);	

	return program;
}
