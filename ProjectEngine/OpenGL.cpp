#include "OpenGL.h"

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

void OpenGL::VBO_Gen(GLuint& vBuffer, float data[], unsigned int size){
	gl::GenBuffers(1, &vBuffer);
	VBO_Bind(vBuffer);
	VBO_Fill(data, size);
}

void OpenGL::VBO_Bind(GLuint vBuffer){
	gl::BindBuffer(gl::ARRAY_BUFFER, vBuffer);
}

void OpenGL::VBO_Fill(float data[], unsigned int size){
	gl::BufferData(gl::ARRAY_BUFFER, size * sizeof(data), data, gl::STATIC_DRAW);
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

	switch (vertexAttribute){

		case VERT_ATTRIBUTE::POSITION:
			
			gl::BindBuffer(gl::ARRAY_BUFFER, VBO_handle);
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
			gl::BindBuffer(gl::ARRAY_BUFFER, VBO_handle);
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
			gl::BindBuffer(gl::ARRAY_BUFFER, VBO_handle);
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

GLuint OpenGL::GetUniformLocation(GLuint ShaderProgram, const char* name){
	GLuint locationValue = OpenGL::GetUniformLocation(ShaderProgram, name);
	return locationValue;
}