#include "OpenGL.h"

/*
bool OpenGL::colorAttrib = false;
bool OpenGL::UVAttrib = false;
bool OpenGL::vertexAttrib = false;

bool OpenGL::Init(){

	gl::exts::LoadTest test = gl::sys::LoadFunctions();

	if (!test) 
		return false;
	else 
		return true;
}

void OpenGL::VAO_Gen(GLuint &handle){

	gl::GenVertexArrays(1, &handle);
	gl::BindVertexArray(handle);
}

void OpenGL::VBO_Gen(GLuint& bufferHandle, GLsizei size, float data[]){

	gl::GenBuffers(1, &bufferHandle);
	OpenGL::VBO_Bind(bufferHandle);
	gl::BufferData(gl::ARRAY_BUFFER, size, data, gl::STATIC_DRAW);
}

void OpenGL::VBO_Bind(GLuint bufferHandle){

	gl::BindBuffer(gl::ARRAY_BUFFER, bufferHandle);
}

void OpenGL::VBO_Fill(GLuint bufferHandle, float data[], unsigned int size, GLsizei offset){

	OpenGL::VBO_Bind(bufferHandle);
	gl::BufferSubData(gl::ARRAY_BUFFER, offset, size * sizeof(data), data);
}

void OpenGL::clearBuffers(){

	gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT); 
}

void OpenGL::enableVertexAttributes(unsigned int enable){

	switch (enable){

		case VERT_ATTRIBUTE::POSITION:
		case VERT_ATTRIBUTE::COLOR:
		case VERT_ATTRIBUTE::UV:
			gl::EnableVertexAttribArray(enable);
			break;

		default:
			break;
	}
}

void OpenGL::BindBuffer(unsigned int vertexAttribute, GLuint &VBO_handle){

	OpenGL::VBO_Bind(VBO_handle);

	switch (vertexAttribute){

		case VERT_ATTRIBUTE::POSITION:
			
			gl::VertexAttribPointer(
				0,
				3,
				gl::FLOAT,
				gl::FALSE_,
				0,
				(void*)0
				);
			break;

		case VERT_ATTRIBUTE::COLOR:
			gl::VertexAttribPointer(
				0,
				3,
				gl::FLOAT,
				gl::FALSE_,
				0,
				(void*)0
				);
			break;

		case VERT_ATTRIBUTE::UV:
			gl::VertexAttribPointer(
				0,
				2,
				gl::FLOAT,
				gl::FALSE_,
				0,
				(void*)0
				);
			break;

		default:
			break;
	}
}

void OpenGL::disableVertexAttributes(bool enableVertex, bool enableColor, bool enableUV){
	
	vertexAttrib = enableVertex;
	colorAttrib = enableColor;
	UVAttrib = enableUV;

	if (vertexAttrib){
		gl::DisableVertexAttribArray(VERT_ATTRIBUTE::POSITION);
	}

	if (colorAttrib){
		gl::DisableVertexAttribArray(VERT_ATTRIBUTE::COLOR);
	}

	if (UVAttrib){
		gl::DisableVertexAttribArray(VERT_ATTRIBUTE::UV);
	}

}

void OpenGL::DrawAsTriangles(unsigned int size){

	gl::DrawArrays(gl::TRIANGLES, 0, size / 3);
}

void OpenGL::DisplayAs_Fill(){

	gl::PolygonMode(gl::FRONT_AND_BACK, gl::FILL);
}

void OpenGL::DisplayAs_WireFrame(){

	gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE);
}

GLuint OpenGL::CreateLinkToShader(GLuint ShaderProgram, const char* name){

	GLuint locationValue = gl::GetUniformLocation(ShaderProgram, name);
	return locationValue;
}

GLuint OpenGL::LinkTexObjToShader(GLuint textureHandle, GLuint ShaderProgram, const char* name){

	OpenGL::Tex_SetAsActive(textureHandle);
	GLuint locationValue = gl::GetUniformLocation(ShaderProgram, name);
	gl::Uniform1i(locationValue, 0);
	return locationValue;
}

GLuint OpenGL::LinkDataToShaderParameter(GLuint VBO_Handle, GLuint ShaderProgram, const char* attributeName, GLfloat data[], GLuint valuesPerVertex){

	OpenGL::VBO_Bind(VBO_Handle);
	GLuint locationValue = gl::GetAttribLocation(ShaderProgram, attributeName);
	gl::EnableVertexAttribArray(locationValue);
	gl::VertexAttribPointer(locationValue, valuesPerVertex, gl::FLOAT, gl::FALSE_, 0, data);
	return locationValue;
}

void OpenGL::Tex_Gen(GLuint &textureHandle){

	gl::GenTextures(1, &textureHandle);
}

void OpenGL::Tex_Del(GLuint &textureHandle){

	gl::DeleteTextures(gl::TEXTURE_2D, &textureHandle);
}

void OpenGL::Tex_SetAsActive(GLuint &textureHandle){

	gl::BindTexture(gl::TEXTURE_2D, textureHandle);
}

void OpenGL::Tex_2D(GLuint textureHandle, GLint mipMapLevel, GLsizei width, GLsizei height, const sf::Uint8* pixelArray){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexImage2D(gl::TEXTURE_2D, mipMapLevel, gl::RGBA, width, height, 0, gl::RGBA, gl::UNSIGNED_BYTE, pixelArray);
}

void OpenGL::Tex_GenMipMaps(GLuint textureHandle){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::GenerateMipmap(gl::TEXTURE_2D);
}

void OpenGL::Tex_SetMipMapBehaviour(GLuint textureHandle, GLuint behaviourType){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, behaviourType);
}

void OpenGL::Tex_SetWrapToRepeating(GLuint textureHandle){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::REPEAT);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::REPEAT);
}

void OpenGL::Tex_SetWrapToClamping(GLuint textureHandle){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::CLAMP_TO_EDGE);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::CLAMP_TO_EDGE);
}

void OpenGL::Tex_SetFilteringToLinear(GLuint textureHandle){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::LINEAR);
}

void OpenGL::Tex_SetFilteringToNearest(GLuint textureHandle){

	OpenGL::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::NEAREST);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::NEAREST);
}
*/





bool _OPENGL::Init()
{
	gl::exts::LoadTest test = gl::sys::LoadFunctions();

	if (!test)
		return false;
	else
		return true;
}

void _OPENGL::WireFrameMode(bool trueIfYes)
{
	if (trueIfYes)
		gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE);
	else
		gl::PolygonMode(gl::FRONT_AND_BACK, gl::FILL);
}

void _OPENGL::ActivateTexture(GLuint textureHandle)
{
	gl::BindTexture(gl::TEXTURE_2D, textureHandle);
}

GLuint _OPENGL::MakevertexArray()
{
	GLuint vertexArrayID;

	gl::GenVertexArrays(1, &vertexArrayID);
	gl::BindVertexArray(vertexArrayID);

	return vertexArrayID;
}

GLuint _OPENGL::MakeVertexBuffer(float data[], GLuint dataSize)
{
	GLuint vertexBufferID;

	// Generate a VBO object.
	gl::GenBuffers(1, &vertexBufferID);
	gl::BindBuffer(gl::ARRAY_BUFFER, vertexBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, dataSize * sizeof(data), data, gl::STATIC_DRAW);

	return vertexBufferID;
}

void _OPENGL::DeleteVertexObject(GLuint objectType, GLuint objectHandle)
{
	switch (objectType){
		case ARRAY:
			gl::DeleteVertexArrays(1, &objectHandle);
			break;

		case BUFFER:
			gl::DeleteBuffers(1, &objectHandle);
			break;

		default:
			break;
	}
	
}

void _OPENGL::ActivateVertexData(GLuint bufferHandle, GLuint attribute)
{
	switch (attribute){

		case VERTEX:
		case COLOR:

			gl::EnableVertexAttribArray(attribute);
			gl::BindBuffer(gl::ARRAY_BUFFER, bufferHandle);
			gl::VertexAttribPointer(
				attribute,					// attribute 0 (vert) / 1 (color).
				3,							// size
				gl::FLOAT,					// type: GLfloat
				gl::FALSE_,					// normalized?
				0,							// stride
				(void*)0					// array buffer offset
			);
			break;

		case UV:

			gl::EnableVertexAttribArray(attribute);
			gl::BindBuffer(gl::ARRAY_BUFFER, bufferHandle);
			gl::VertexAttribPointer(
				attribute,					// attribute 2.
				2,                          // size
				gl::FLOAT,                  // type: GLfloat
				gl::FALSE_,                 // normalized?
				0,							// stride
				(void*)(0)					// array buffer offset
			);
			break;

		default:
			break;
	}
}

void _OPENGL::DeactivateVertexData(GLuint attribute)
{
	switch (attribute){

		case VERTEX:
		case COLOR:
		case UV:
			gl::DisableVertexAttribArray(attribute);
			break;

		default:
			break;
	}
}

void _OPENGL::DrawModelVertices(GLuint size)
{
	gl::DrawArrays(gl::TRIANGLES, 0, size / 3);
}

void _OPENGL::BindMatrixToShader(GLuint shaderAttribID, glm::mat4 matrix)
{
	gl::UniformMatrix4fv(shaderAttribID, 1, gl::FALSE_, &matrix[0][0]);
}

void _OPENGL::ClearBuffers()
{
	gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);
}