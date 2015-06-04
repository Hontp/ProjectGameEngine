#pragma once

#include <glm.hpp>
#include <gtc/quaternion.hpp>

#include "Camera.h"

class Model
{
	public:

		virtual void InitData(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBuffSize, GLfloat UVdata[], GLint uvBuffSize) = 0;

		virtual void Render() = 0;

		virtual void Destroy() = 0;

		virtual void Translate(glm::vec3 speedVector, float speed, float deltaTime) = 0;

		virtual void Rotate(float y_Rot) = 0;

	protected:

		enum : unsigned short{ VERTEX = 0, COLOR = 1, UV = 2 };

		Model(){};
		~Model(){};

		glm::vec3 position;
		glm::vec3 scale;
		glm::quat Rotation;
};

