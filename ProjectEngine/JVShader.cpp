#include "JVShader.h"


JVShader::JVShader()
{
	Result = gl::FALSE_;
}


JVShader::~JVShader()
{
	Destroy();
}

/** @brief: Load the shader code into the Shader object.

@param: vertFile (std::string) - Filepath to the specified VERTEX SHADER.
@param: fragFile (std::string) - Filepath to the specified FRAGMENT SHADER.

Description: Load the vertex and fragment shaders into the Shader object.

@return: TRUE if both the vertex and fragment shader files were successfully loaded, compiled and linked; else FALSE if an error occured.

@pre: OpenGL should be initialised.

@post: Shader now has code loaded and compiled into it.
*/
bool JVShader::LoadFiles(std::string vertFile, std::string fragFile){

	// Create shaders from the Shader object's dedicated IDs.
	vertShaderID = gl::CreateShader(gl::VERTEX_SHADER);
	fragShaderID = gl::CreateShader(gl::FRAGMENT_SHADER);

	// Read the data from the vertex shader file.
	std::string vertFileData = "";
	if (!ReadFile(vertFile, vertFileData))
		return false;

	// Read the data from the fragment shader file.
	std::string fragFileData = "";
	if (!ReadFile(fragFile, fragFileData))
		return false;

	// Compile the vertex shader and LINK it to the vertShaderID variable, then check the compile for errors.
	printf("Compiling shader : ' %s '.\n", vertFile.c_str());
	CompileShader(vertShaderID, vertFileData);
	CheckShaderCompile(vertShaderID);

	// Compile the fragment shader and LINK it to the fragShaderID variable, then check the compile for errors.
	printf("Compiling shader : ' %s '.\n", fragFile.c_str());
	CompileShader(fragShaderID, fragFileData);
	CheckShaderCompile(fragShaderID);

	// Link the compiled shaders to the programID variable, then check the linkage for errors.
	LinkProgram();
	CheckProgram();

	// Delete the compiled shaders, because they have already been added to the shader program ('ProgramID' variable).
	gl::DeleteShader(vertShaderID);
	gl::DeleteShader(fragShaderID);

	return true;
}

/** @brief: Activate the shader.

Description: Set the active shader program to this shader program.

@pre: OpenGL should be initialised.

@post: The program will now use this shader to draw geometry.
*/
void JVShader::Activate(){
	gl::UseProgram(ProgramID);
}

/** @brief: Deactivate the shader.

Description: Reset the shader active shader program to the null value.

@pre: OpenGL should be initialised.

@post: The program no longer uses this shader to draw geometry.
*/
void JVShader::Deactivate(){
	gl::UseProgram(0);
}

/** @brief: Release data loaded by OpenGL.

Description: Anything compiled during run-time by OpenGL MUST be released. Call this during clean-up.

@pre: OpenGL should be initialised.

@post: The Shader object is empty.
*/
void JVShader::Destroy(){

	// If vertex shader ID is valid, free it.
	if (vertShaderID)
	{
		gl::DetachShader(ProgramID, vertShaderID);
		gl::DeleteShader(vertShaderID);
		vertShaderID = 0;
	}

	// If fragment shader ID is valid, free it.
	if (fragShaderID)
	{
		gl::DetachShader(ProgramID, fragShaderID);
		gl::DeleteShader(fragShaderID);
		fragShaderID = 0;
	}

	// If program ID is valid, free it.
	if (ProgramID)
	{
		gl::DeleteShader(ProgramID);
		ProgramID = 0;
	}
}

/** @brief: Get the Shader Porgram ID.

Description: Access the handle for the shader program contained in this Shader object.

@return: the ID of the Shader object's program.

@pre: OpenGL should be initialised.

@post: NONE.
*/
GLuint JVShader::Program(){
	return ProgramID;
}

/** @brief: Read ALL data from a shader file.

@param: shaderFile (std::string) - Filepath to the file that is being read (should contain shader code).
@param: codeString (std::string&) - external string that will contain the data from the specified shader file.

Description: Read the data from a shader file into a specified string.

@return: TRUE if file was successfully read, else FLASE if an error occcured.

@pre: NONE.

@post: codeString now contains all of the code from the shader file.
*/
bool JVShader::ReadFile(std::string shaderFile, std::string& codeString){

	// Create a new file stream.
	std::ifstream shaderFileStream(shaderFile.c_str(), std::ios::in);

	// Check file stream is valid.
	if (!shaderFileStream){
		fprintf(stderr, "Error: Cannot open file ' %s '.", shaderFile);
		return false;
	}

	// Prepare data containers.
	codeString = "";
	std::string Line = "";

	// Read data from shader file.
	while (!shaderFileStream.eof()){
		getline(shaderFileStream, Line);
		codeString += "\n" + Line;
	}

	// Close the shader file.
	shaderFileStream.close();

	return true;

}

/** @brief: Compile a specified shader-code-containing string, and link the code to a specified handle.

@param: shaderID (GLuint&) - Handle for the newly compiled shader code.
@param: codeString (std::string) - Container for the shader code.

Description: Compile the code contained in 'codeString'. Use 'shaderID' as a handle to reference the compiled code.

@pre: OpenGL should be initialised.

@post: Shader code has been compiled.
*/
void JVShader::CompileShader(GLuint& shaderID, std::string codeString){

	char const* code = codeString.c_str();
	gl::ShaderSource(shaderID, 1, &code, NULL);
	gl::CompileShader(shaderID);

}

/** @brief: Check the status of a compiled shader file.

@param: shaderID (GLuint&) - Handle used to reference a compiled shader file.

Description: Check the status of the compiled shader referenced by shaderID.

@pre: OpenGL should be initialised.

@post: Compile status of the shader code is visible.
*/
void JVShader::CheckShaderCompile(GLuint& shaderID){

	gl::GetShaderiv(shaderID, gl::COMPILE_STATUS, &Result);
	gl::GetShaderiv(shaderID, gl::INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0){
		std::vector<char> shaderErrorMessage(InfoLogLength + 1);
		gl::GetShaderInfoLog(shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
		printf("%s\n", &shaderErrorMessage[0]);
	}

}

/** @brief: Construct the Shader object's program.

	Description: Link the compiled vertex and fragment shader code to the shader program.

	@pre: ProgramID should not be initialised.
	@pre: vertShaderID and fragShaderID and OpenGL should be initialised.

	@post: Shader program has now been linked to the code pointed to by verthader and fragShader.
*/
void JVShader::LinkProgram(){

	printf("Linking Program.\n");
	ProgramID = gl::CreateProgram();
	gl::AttachShader(ProgramID, vertShaderID);
	gl::AttachShader(ProgramID, fragShaderID);
	gl::LinkProgram(ProgramID);

}

/** @brief: Check the status of the Shader's program.

	Description: Check the linkage status of the Shader object's program.

	@pre: ProgramID should be properly linked to a vertex and fragment shader.
	@pre:  OpenGL should be initialised.

	@post: The status of the program linkage is visible.
*/
void JVShader::CheckProgram(){

	gl::GetProgramiv(ProgramID, gl::LINK_STATUS, &Result);
	gl::GetProgramiv(ProgramID, gl::INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0){
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		gl::GetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

}