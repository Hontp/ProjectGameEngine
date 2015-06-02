#include "Shader.h"
#include "gl_core_4_3.hpp"


Shader::Shader()
{
}

Shader::Shader(GLenum &type)
{
	// Get the type of the shader
	if (type == gl::VERTEX_SHADER)
	{
		typeString = "Vertex";
	}
	else if (type == gl::FRAGMENT_SHADER)
	{
		typeString = "Fragment";
	}
	else
	{
		typeString = "Geometry";
	}

	// Create the vertex shader id/handle
	id = gl::CreateShader(type);
}


Shader::~Shader()
{
}

void Shader::loadfromString(const std::string &sourceString)
{
	// Keep hold of a copy of the source
	source = sourceString;

	// Get the source as a pointer to an array of characters
	const char *sourceChars = source.c_str();

	// Associate the source with the shader id
	gl::ShaderSource(id, 1, &sourceChars, NULL);
}

void Shader::loadfromFile(const std::string &filename)
{
	std::ifstream file;

	file.open(filename.c_str());

	if (!file)
	{
		std::cout << "Failed to open file: " << filename << std::endl;
		exit(-1);
	}

	// Create a string stream
	std::stringstream stream;

	// Dump the contents of the file into it
	stream << file.rdbuf();

	// Close the file
	file.close();

	// Convert the StringStream into a string
	source = stream.str();

	// Get the source string as a pointer to an array of characters
	const char *sourceChars = source.c_str();

	// Associate the source with the shader id
	gl::ShaderSource(id, 1, &sourceChars, NULL);
}

void Shader::compile()
{
	// Compile the shader
	gl::CompileShader(id);

	// Check the compilation status and report any errors
	GLint shaderStatus;
	gl::GetShaderiv(id, gl::COMPILE_STATUS, &shaderStatus);

	// If the shader failed to compile, display the info log and quit out
	if (shaderStatus == gl::FALSE_)
	{
		GLint infoLogLength;
		gl::GetShaderiv(id, gl::INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		gl::GetShaderInfoLog(id, infoLogLength, NULL, strInfoLog);

		std::cout << typeString << " shader compilation failed: " << strInfoLog << std::endl;
		delete[] strInfoLog;
	}
}