#pragma once

#include "Model.h"
#include "OpenGL.h"
#include "gl_core_4_3.hpp"

class GL_Model : public Model
{
	public:

		GL_Model();
		~GL_Model();

		void InitData(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBuffSize, GLfloat UVdata[], GLint uvBuffSize);

		void Render();

		void Destroy();

		void Translate(glm::vec3 speedVector, float speed, float deltaTime);

		void Rotate(float y_Rot);

	private: 

		GLint matrixID;

		GLuint vertexBufferID;              // VBO handle.
		GLuint colorBufferID;
		GLuint uvBufferID;
		GLuint vertexArrayID;               // VAO handle.

		float* modelData;					// Container for vertex position data.
		float* colorData;					// Container for vertex color data.
		float* uvData;						// Container for vertex texture co-ordinate data.

		GLint vBufferLength;                // Length of the 'modelData' variable when it is filled.
		GLint cBufferLength;				// Length of the 'colorData' variable when it is filled.
		GLint uBufferLength;				// Length of the 'uvData' variable when it is filled.
};

