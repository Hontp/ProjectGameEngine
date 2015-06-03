#pragma once

// Standard libraries.
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

#include "gl_core_4_3.hpp"

class JVShader
{
public:
	JVShader();
	~JVShader();

	bool LoadFiles(std::string vertFile, std::string fragFile);

	void Activate();
	void Deactivate();

	void Destroy();

	GLuint Program();

private:
	// Used in LoadFiles() function. Seperates out each individual step for better readability.
	bool ReadFile(std::string shaderFile, std::string& codeString);
	void CompileShader(GLuint& shaderID, std::string codeString);
	void CheckShaderCompile(GLuint& shaderID);
	void LinkProgram();
	void CheckProgram();

	GLuint vertShaderID;    // ID used to bind the vertex shader to the ProgramID variable.
	GLuint fragShaderID;    // ID used to bind the fragment shader to the ProgramID variable.
	GLuint ProgramID;       // Program ID for GPU to use when rendering.

	// Debugging variables.
	GLint Result;
	int InfoLogLength;
};

