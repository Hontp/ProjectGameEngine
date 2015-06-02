#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "gl_core_4_3.hpp"
class Shader
{
public:

	/// Default constructor
	Shader();

	Shader(GLenum &type);

	/// Get Shader ID.
	GLuint getID() { return id; }

	/// Get shader source code.
	std::string getSource() { return source; }

	void loadfromFile(const std::string &filename);
	void loadfromString(const std::string &sourceString);
	
	void compile();

	~Shader();

private:
	GLuint id;
	std::string typeString;
	std::string source;

};

