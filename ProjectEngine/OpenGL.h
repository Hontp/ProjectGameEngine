#pragma once

#include "gl_core_4_3.hpp"
#include <SFML\Graphics.hpp>

#include "GraphicsCore.h"
#include "Singleton.h"

#include "SFML_Texture.h"
#include "SFML_MultiTexture.h"

#include "GL_Model.h"


class _OPENGL : public GraphicsCore, public Singleton<_OPENGL>
{

	public:

		bool Init();

		void WireFrameMode(bool trueIfYes);

		void ActivateTexture(GLuint textureHandle);

		GLuint MakevertexArray();
		GLuint MakeVertexBuffer(float data[], GLuint dataSize);
		void DeleteVertexObject(GLuint objectType, GLuint objectHandle);

		void ActivateVertexData(GLuint bufferHandle, GLuint attribute);
		void DeactivateVertexData(GLuint attribute);

		void DrawModelVertices(GLuint size);

		void BindMatrixToShader(GLuint shaderAttribID, glm::mat4 matrix);

		void ClearBuffers();

		enum : unsigned short{ VERTEX = 0, COLOR = 1, UV = 2 };

		enum : unsigned int { ARRAY = 0, BUFFER = 1};

	private:

};