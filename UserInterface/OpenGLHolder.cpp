#include "OpenGLHolder.h"


#include <cstdio>

#ifndef BBB
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
#endif

#include <EGL/egl.h>

#ifndef BBB

bool OpenGLHolder::initGraphics()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    window = SDL_CreateWindow("UserInterface - W.I.P.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE_X, WINDOW_SIZE_Y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    openGLContext = SDL_GL_CreateContext(window);
	if(openGLContext == 0)
	{
		printf("ERROR: Something's wrong with the window & opengl /!\\ \n");
		return true;
	}
	
	return false;
}

void OpenGLHolder::beginFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

}

void OpenGLHolder::finishFrame()
{
//	glFlush();
	SDL_GL_SwapWindow(window);
}

#else

	

bool getRawData(unsigned char ** data, char * name)
{
	FILE * shaderFile;
	
	if((shaderFile = fopen(name,"rb")) == NULL)
	{
		error(name, "fopen");
		return true;
	}
	
	*data = (unsigned char *) malloc(1*1024*1024);
	
	if(*data == NULL)
	{
		return true;
	}
		
	*size = fread(*data, 1, *size, shaderFile);
	if(size <= 0)
	{
		return true;
	}
	

	fclose(shaderFile);

	return false;
}


	
int loadShader(int type, char * shaderCode)
{
    int length = strlen(shaderCode);

    int shader = glCreateShader(type);
    glShaderSource(shader, 1, (const char **) &shaderCode, NULL);
    glCompileShader(shader);

    return shader;
}
	
bool OpenGLHolder::initGraphics()
{
	EGLConfig    eGLConfig;
	EGLContext   eGLContext;
	NativeWindowType hWnd = 0;

	const EGLint config[] =
	{
		EGL_RED_SIZE,       8,
		EGL_GREEN_SIZE,     8,
		EGL_BLUE_SIZE,      8,
		EGL_ALPHA_SIZE,     0,
		EGL_DEPTH_SIZE,     24,
		EGL_STENCIL_SIZE,   0,
		EGL_SURFACE_TYPE,   EGL_WINDOW_BIT,
		EGL_SAMPLE_BUFFERS, 0,
		EGL_MIN_SWAP_INTERVAL, 0,
		EGL_NONE
	};

	EGLint configCount;
	EGLint majorVersion;
	EGLint minorVersion;

	eGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	if (eGLDisplay == EGL_NO_DISPLAY)
	{
		printf("eglGetDisplay() failed\n");
		return true;
	}

	if (!eglInitialize(eGLDisplay, &majorVersion, &minorVersion))
	{
		printf("eglInitialize() failed\n");
		return true;
	}
	if (!eglChooseConfig(eGLDisplay, config, &eGLConfig, 1, &configCount))
	{
		printf("eglSaneChooseConfigBRCM() failed\n");
		return true;
	}
	if (configCount == 0)
	{
		printf("Couldn't find suitable config!\n");
		return true;
	}

//	EGLint r, g, b, a, depth, stencil, samples, sample_buffers;
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_RED_SIZE, &r);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_GREEN_SIZE, &g);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_BLUE_SIZE, &b);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_ALPHA_SIZE, &a)
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_DEPTH_SIZE, &depth);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_STENCIL_SIZE, &stencil);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_SAMPLES, &samples);
	//eglGetConfigAttrib(eGLDisplay, eGLConfig, EGL_SAMPLE_BUFFERS, &sample_buffers);
//	printf("Chose EGL config %d: r=%d,g=%d,b=%d,a=%d, depth=%d,stencil=%d, samples=%d,sample_buffers=%d\n",	(int)config, r, g, b, a, depth, stencil, samples, sample_buffers);


	eGLContext = eglCreateContext(eGLDisplay, eGLConfig, NULL, NULL);
	if (eGLContext == EGL_NO_CONTEXT)
	{
		printf("eglCreateContext() failed\n");
		return true;
	}

	printf("Using native window %d\n", (int)hWnd);

	eGLSurface = eglCreateWindowSurface(eGLDisplay, eGLConfig, hWnd, NULL);
	if (eGLSurface == EGL_NO_SURFACE)
	{
		printf("eglCreateWindowSurface() failed\n");
		return true;
	}

	eglMakeCurrent(eGLDisplay, eGLSurface, eGLSurface, eGLContext);

	EGLint width, height;
	eglQuerySurface(eGLDisplay, eGLSurface, EGL_WIDTH, &width);
	eglQuerySurface(eGLDisplay, eGLSurface, EGL_HEIGHT, &height);

	// set swap interval
   if (eglSwapInterval(eGLDisplay, 10) == EGL_FALSE)
   {
	  printf("Could not set swap interval\n");
      return true;
   }
   
	char * vertexShader;
	char * pixelShader;
	
   
	getRawData(&vertexShader,"vertexShader");
	getRawData(&pixelShader,"pixelShader");
   
/*
	GLbyte vShaderStr[] =
      "attribute vec4 vPosition;   \n"
      "void main()                 \n"
      "{                           \n"
      "  gl_Position = vPosition;  \n"
      "}                           \n";

   GLbyte fShaderStr[] =
      "precision mediump float;                   \n"
      "void main()                                \n"
      "{                                          \n"
      "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n"
      "}                                          \n";
*/
   GLuint vertexShader;
   GLuint fragmentShader;
   GLint linked;

  // Load the vertex/fragment shaders
  vertexShader = LoadShader(GL_VERTEX_SHADER, (GLbyte)vertexShader);
  fragmentShader = LoadShader(GL_FRAGMENT_SHADER, (GLbyte)pixelShader);

  // Create the program object
  programObject = glCreateProgram();

  if(programObject == 0)
     return 0;

  glAttachShader(programObject, vertexShader);
  glAttachShader(programObject, fragmentShader);

  // Bind vPosition to attribute 0
  glBindAttribLocation(programObject, 0, "vPosition");

  // Link the program
  glLinkProgram(programObject);

  // Check the link status
  glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

  if(!linked)
  {
     GLint infoLen = 0;

     glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

     if(infoLen > 1)
     {
        char* infoLog = malloc(sizeof(char) * infoLen);

        glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
        printf("Error linking program:\n%s\n", infoLog);

        free(infoLog);
     }

     glDeleteProgram(programObject);
     return true;
  }


  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return false;
}

void OpenGLHolder::beginFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}

void OpenGLHolder::finishFrame()
{
	eglSwapBuffers(eGLDisplay, eGLSurface);
}

	
#endif
