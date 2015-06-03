#include "ShaderProgram.h"


ShaderProgram::ShaderProgram()
{
	// Generate a unique Id/handle for the shader program
	programId = gl::CreateProgram();

	shaderCount = 0;
}


ShaderProgram::~ShaderProgram()
{
	// Delete the shader program from the graphics card memory.
	gl::DeleteProgram(programId);
}

void ShaderProgram::attachShader(Shader shader)
{
	// Attach the shader to the program
	// Note: We identify the shader by its unique Id value
	gl::AttachShader(programId, shader.getID());

	// Increment the number of shaders we have associated with the program
	shaderCount++;
}

void ShaderProgram::linkProgram()
{
	// If we have at least two shaders (like a vertex shader and a fragment shader)
	if (shaderCount >= 2)
	{
		// Perform the linking process
		gl::LinkProgram(programId);

		// Check the status
		GLint linkStatus;
		gl::GetProgramiv(programId, gl::LINK_STATUS, &linkStatus);

		// Get the information of the linkage status.
		int infoLength;
		gl::GetProgramiv(programId, gl::INFO_LOG_LENGTH, &infoLength);

		if (linkStatus == gl::FALSE_)
		{
			std::vector<char> ProgramErrorMessage(infoLength + 1);
			std::cout << "Shader program linking failed." << std::endl;
			gl::GetProgramInfoLog(programId, infoLength, NULL, &ProgramErrorMessage[0]);
			printf("%s\n", &ProgramErrorMessage[0]);
			ProgramErrorMessage.clear();
		}
		else
		{
			std::cout << "Shader program linking OK." << std::endl;
		}
	}
	else
	{
		std::cout << "Cannot link shaders, you require at least 2 attached shaders" << std::endl;
	}
}

void ShaderProgram::use()
{
	gl::UseProgram(programId);
}

void ShaderProgram::disable()
{
	gl::UseProgram(0);
}

GLuint ShaderProgram::attribute(const std::string &attribute)
{
	// Create an iterator to look through our attribute map and try to find the named attribute
	std::map<std::string, int>::iterator it = attributeLocList.find(attribute);

	// Found it? Great -return the bound location! Didn't find it? Alert user and halt.
	if (it != attributeLocList.end())
	{
		return attributeLocList[attribute];
	}
	else
	{
		std::cout << "Could not find attribute in shader program: " << attribute << std::endl;
		exit(-1);
	}
}

GLuint ShaderProgram::uniform(const std::string &uniform)
{
	// Create an iterator to look through our uniform map and try to find the named uniform
	std::map<std::string, int>::iterator it = uniformLocList.find(uniform);

	// Found it? Great - pass it back! Didn't find it? Alert user and halt.
	if (it != uniformLocList.end())
	{
		return uniformLocList[uniform];
	}
	else
	{
		std::cout << "Could not find uniform in shader program: " << uniform << std::endl;
		exit(-1);
	}
}


// Method to add an attrbute to the shader and return the bound location
int ShaderProgram::addAttribute(const std::string &attributeName)
{
	attributeLocList[attributeName] = gl::GetAttribLocation(programId, attributeName.c_str());

	// Check to ensure that the shader contains an attribute with this name
	if (attributeLocList[attributeName] == -1)
	{
		std::cout << "Could not add attribute: " << attributeName << " - location returned -1!" << std::endl;
		exit(-1);
	}
	else
	{
		std::cout << "Attribute " << attributeName << " bound to location: " << attributeLocList[attributeName] << std::endl;
	}

	return attributeLocList[attributeName];
}


// Method to add a uniform to the shader and return the bound location
int ShaderProgram::addUniform(const std::string &uniformName)
{
	uniformLocList[uniformName] = gl::GetUniformLocation(programId, uniformName.c_str());

	// Check to ensure that the shader contains a uniform with this name
	if (uniformLocList[uniformName] == -1)
	{
		std::cout << "Could not add uniform: " << uniformName << " - location returned -1!" << std::endl;
		exit(-1);
	}
	else
	{
		std::cout << "Uniform " << uniformName << " bound to location: " << uniformLocList[uniformName] << std::endl;
	}

	return uniformLocList[uniformName];
}
