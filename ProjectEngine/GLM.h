#pragma once

#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include "OpenGL.h"

class GLM
{

	public:
		static glm::mat4 CreateLookAtMatrix(glm::vec3 Position, glm::vec3 Target, glm::vec3 UpVector);
		static glm::mat4 CreatePerspectiveMatrix(GLfloat FieldOfView, GLfloat AspectRatio, GLfloat NearPlane, GLfloat FarPlane);
		static glm::vec3 CrossVectors(glm::vec3 X_Vector, glm::vec3 Y_Vector);

	private:

};

