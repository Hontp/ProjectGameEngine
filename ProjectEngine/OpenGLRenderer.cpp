#include "OpenGLRenderer.h"

bool OpenGLRenderer::colorAttrib = false;
bool OpenGLRenderer::UVAttrib = false;
bool OpenGLRenderer::vertexAttrib = false;


OpenGLRenderer::OpenGLRenderer()
{

}

void OpenGLRenderer::Initialize()
{

}

void OpenGLRenderer::Rotate(float angle, float x, float y, float z)
{
	modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(x, y, z));
}

void OpenGLRenderer::Translate(float x, float y, float z)
{
	modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z)); 
}

void OpenGLRenderer::Scale(float x, float y, float z)
{
	modelMatrix = glm::scale(modelMatrix, glm::vec3(x, y, z));
}

void OpenGLRenderer::SetIdentity()
{
	modelMatrix = glm::mat4(1.0f);
}

void OpenGLRenderer::ClearColour(float r, float g, float b, float a)
{
	gl::ClearColor(r, g, b, a);
}

void OpenGLRenderer::ClearScreen()
{
	gl::Clear((gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT));
}

void OpenGLRenderer::EnableDepthTesting()
{
	gl::Enable(gl::DEPTH_TEST);
}

bool OpenGLRenderer::Init(){

	gl::exts::LoadTest test = gl::sys::LoadFunctions();

	if (!test) 
		return false;
	else 
		return true;
}

void OpenGLRenderer::VAO_Gen(GLuint &handle)
{

	gl::GenVertexArrays(1, &handle);
	gl::BindVertexArray(handle);
}

void OpenGLRenderer::VBO_Gen(GLuint& bufferHandle, GLsizei size, float data[]){

	gl::GenBuffers(1, &bufferHandle);
	VBO_Bind(bufferHandle);
	gl::BufferData(gl::ARRAY_BUFFER, size, data, gl::STATIC_DRAW);
}

void OpenGLRenderer::VBO_Bind(GLuint bufferHandle){

	gl::BindBuffer(gl::ARRAY_BUFFER, bufferHandle);
}

void OpenGLRenderer::VBO_Fill(GLuint bufferHandle, float data[], unsigned int size, GLsizei offset){

	VBO_Bind(bufferHandle);
	gl::BufferSubData(gl::ARRAY_BUFFER, offset, size * sizeof(data), data);
}

void OpenGLRenderer::clearBuffers(){

	gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT); 
}

void OpenGLRenderer::enableVertexAttributes(unsigned int enable){

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

void OpenGLRenderer::BindBuffer(unsigned int vertexAttribute, GLuint &VBO_handle)
{
	OpenGLRenderer::VBO_Bind(VBO_handle);

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

void OpenGLRenderer::disableVertexAttributes(bool enableVertex, bool enableColor, bool enableUV){
	
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

void OpenGLRenderer::DrawAsTriangles(unsigned int size){

	gl::DrawArrays(gl::TRIANGLES, 0, size / 3);
}

void OpenGLRenderer::DisplayAs_Fill(){

	gl::PolygonMode(gl::FRONT_AND_BACK, gl::FILL);
}

void OpenGLRenderer::DisplayAs_WireFrame(){

	gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE);
}

GLuint OpenGLRenderer::CreateLinkToShader(GLuint ShaderProgram, const char* name){

	GLuint locationValue = gl::GetUniformLocation(ShaderProgram, name);
	return locationValue;
}

GLuint OpenGLRenderer::LinkTexObjToShader(GLuint textureHandle, GLuint ShaderProgram, const char* name){

	Tex_SetAsActive(textureHandle);
	GLuint locationValue = gl::GetUniformLocation(ShaderProgram, name);
	gl::Uniform1i(locationValue, 0);
	return locationValue;
}

GLuint OpenGLRenderer::LinkDataToShaderParameter(GLuint VBO_Handle, GLuint ShaderProgram, const char* attributeName, GLfloat data[], GLuint valuesPerVertex){

	VBO_Bind(VBO_Handle);
	GLuint locationValue = gl::GetAttribLocation(ShaderProgram, attributeName);
	gl::EnableVertexAttribArray(locationValue);
	gl::VertexAttribPointer(locationValue, valuesPerVertex, gl::FLOAT, gl::FALSE_, 0, data);
	return locationValue;
}

void OpenGLRenderer::Tex_Gen(GLuint &textureHandle){

	gl::GenTextures(1, &textureHandle);
}

void OpenGLRenderer::Tex_Del(GLuint &textureHandle){

	gl::DeleteTextures(gl::TEXTURE_2D, &textureHandle);
}

void OpenGLRenderer::Tex_SetAsActive(GLuint &textureHandle){

	gl::BindTexture(gl::TEXTURE_2D, textureHandle);
}

void OpenGLRenderer::Tex_2D(GLuint textureHandle, GLint mipMapLevel, GLsizei width, GLsizei height, const sf::Uint8* pixelArray){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexImage2D(gl::TEXTURE_2D, mipMapLevel, gl::RGBA, width, height, 0, gl::RGBA, gl::UNSIGNED_BYTE, pixelArray);
}

void OpenGLRenderer::Tex_GenMipMaps(GLuint textureHandle){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::GenerateMipmap(gl::TEXTURE_2D);
}

void OpenGLRenderer::Tex_SetMipMapBehaviour(GLuint textureHandle, GLuint behaviourType){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, behaviourType);
}

void OpenGLRenderer::Tex_SetWrapToRepeating(GLuint textureHandle){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::REPEAT);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::REPEAT);
}

void OpenGLRenderer::Tex_SetWrapToClamping(GLuint textureHandle){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::CLAMP_TO_EDGE);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::CLAMP_TO_EDGE);
}

void OpenGLRenderer::Tex_SetFilteringToLinear(GLuint textureHandle){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::LINEAR);
}

void OpenGLRenderer::Tex_SetFilteringToNearest(GLuint textureHandle){

	OpenGLRenderer::Tex_SetAsActive(textureHandle);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::NEAREST);
	gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::NEAREST);
}