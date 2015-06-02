#pragma once

#include <iostream>
#include <map>

#include "Shader.h"


class ShaderProgram
{
private:
	GLuint programId;   // The unique ID/handle for the shader program
	GLuint shaderCount; // How many shaders are attached to the shader program

	// Map of attributes and their binding locations
	std::map<std::string, int> attributeLocList;

	// Map of uniforms and their binding locations
	std::map<std::string, int> uniformLocList;

public:

	// Constructor
	ShaderProgram();

	// Destructor
	~ShaderProgram();

	// Method to attach a shader to the shader program
	void attachShader(Shader shader);

	// Method to link the shader program and display the link status
	void linkProgram();

	// Method to enable the shader program
	void use();

	// Method to disable the shader program
	void disable();

	// Returns the bound location of a named attribute
	GLuint attribute(const std::string &attribute);


	// Method to returns the bound location of a named uniform
	GLuint uniform(const std::string &uniform);

	// Method to add an attrbute to the shader and return the bound location
	int addAttribute(const std::string &attributeName);

	// Method to add a uniform to the shader and return the bound location
	int addUniform(const std::string &uniformName);
};

