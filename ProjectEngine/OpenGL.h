#pragma once
#include "gl_core_4_3.hpp"

class OpenGL{

	public:

		static class VERT_ATTRIBUTE{
			public:
				static enum { NULL_ = -1, POSITION = 0, COLOR = 1, UV = 2 };
		};

		static bool Init();

		static void VAO_Gen(GLuint& handle);
		static void VBO_Gen(GLuint& vBuffer, float data[], unsigned int size);

		static void clearBuffers();

		static void enableVertexAttributes(unsigned int enable);
		static void BindBuffer(unsigned int vertexAttribute, GLuint &VBO_handle);
		static void disableVertexAttributes(bool disableVertex, bool disableColor = false, bool disableUV = false);

		static void DrawAsTriangles(unsigned int size);

		static void DisplayAs_WireFrame();
		static void DisplayAs_Fill();

		static GLuint GetUniformLocation(GLuint ShaderProgram, const char* name);

	private:

		static bool vertexAttrib;
		static bool colorAttrib;
		static bool UVAttrib;

		static void VBO_Bind(GLuint vBuffer);
		static void VBO_Fill(float data[], unsigned int size);

};