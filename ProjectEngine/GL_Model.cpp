#include "GL_Model.h"

//_OPENGL* GL_Model::GL = nullptr;

GL_Model::GL_Model()
{
	
}

GL_Model::~GL_Model()
{

}

void GL_Model::InitData(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBuffSize, GLfloat UVdata[], GLint uvBuffSize)
{
	// Generate a VAO object.
	vertexArrayID = _OPENGL::getInstance()->MakevertexArray();

	////////////////////   BEGIN LOAD VERTEX DATA    ////////////////////////////

	modelData = verts;
	vBufferLength = vertBuffSize;

	// Generate a VBO object.
	vertexBufferID = _OPENGL::getInstance()->MakeVertexBuffer(modelData, vBufferLength);

	////////////////////   END LOAD VERTEX DATA      ////////////////////////////

	////////////////////   BEGIN LOAD COLOR DATA     ////////////////////////////

	colorData = colors;
	cBufferLength = colorBuffSize;

	// Generate another buffer object for color information.
	colorBufferID = _OPENGL::getInstance()->MakeVertexBuffer(colorData, cBufferLength);

	////////////////////   END LOAD COLOR DATA       ////////////////////////////

	////////////////////   BEGIN LOAD UV DATA     ////////////////////////////

	uvData = UVdata;
	uBufferLength = uvBuffSize;

	if (uvData != nullptr)
	{
		uvBufferID = _OPENGL::getInstance()->MakeVertexBuffer(uvData, uBufferLength);
	}

	////////////////////   END LOAD UV DATA     ////////////////////////////
}

void GL_Model::Render()
{
	////////////////////   BEGIN ENABLE VERTEX DATA    ////////////////////////////

	_OPENGL::getInstance()->ActivateVertexData(vertexBufferID, VERTEX);

	////////////////////   END ENABLE VERTEX DATA      ////////////////////////////


	////////////////////   BEGIN ENABLE COLOR DATA     ////////////////////////////

	_OPENGL::getInstance()->ActivateVertexData(colorBufferID, COLOR);

	////////////////////   END ENABLE COLOR DATA       ////////////////////////////


	////////////////////   BEGIN ENABLE UV DATA   ////////////////////////////
	if (uvData != nullptr){

		_OPENGL::getInstance()->ActivateVertexData(uvBufferID, UV);
	}

	////////////////////   END ENABLE UV DATA     ////////////////////////////


	////////////////////   BEGIN ACTUAL DRAWING   ////////////////////////////

	// Draw the model array.
	_OPENGL::getInstance()->DrawModelVertices(vBufferLength);


	////////////////////   END ACTUAL DRAWING   ////////////////////////////


	////////////////////   BEGIN DISABLE ALL DATA   ////////////////////////////

	_OPENGL::getInstance()->DeactivateVertexData(VERTEX);
	_OPENGL::getInstance()->DeactivateVertexData(COLOR);

	if (uvData != nullptr)
		_OPENGL::getInstance()->DeactivateVertexData(UV);

	////////////////////   END DISABLE UV DATA     ////////////////////////////
}

void GL_Model::Destroy()
{
	_OPENGL::getInstance()->DeleteVertexObject(_OPENGL::BUFFER, vertexBufferID);
	_OPENGL::getInstance()->DeleteVertexObject(_OPENGL::BUFFER, colorBufferID);

	if (uvData != nullptr)
		_OPENGL::getInstance()->DeleteVertexObject(_OPENGL::BUFFER, uvBufferID);

	_OPENGL::getInstance()->DeleteVertexObject(_OPENGL::ARRAY, vertexArrayID);
}

void GL_Model::Translate(glm::vec3 speedVector, float speed, float deltaTime)
{

}

void GL_Model::Rotate(float y_Rot)
{

}