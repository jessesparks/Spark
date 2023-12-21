#pragma once
#include <glad/gl.h>

#ifdef SPARK_DEBUG
inline GLenum glCheckError_(const char* file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::string error;
		switch (errorCode)
		{
		case GL_INVALID_ENUM:					error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:					error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:				error = "INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW:					error = "STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW:				error = "STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY:					error = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:	error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		SPARK_CORE_ERROR("OpenGL ERROR({0})| file:{1}({2})", error, file, line);
	}
	return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__)
#else
#define glCheckError() do{} while(false)
#endif