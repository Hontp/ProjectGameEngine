#pragma once

#include <glm.hpp>
#include <string>

class IRenderer
{
public:
	IRenderer();
	~IRenderer();

	virtual void Rotate(float angle, float x, float y, float z) = 0;
	virtual void Translate(float x, float y, float z) = 0;
	virtual void Scale(float x, float y, float z) = 0;

	//virtual void LoadMatrix(const glm::mat4 &mtrx) = 0;
	virtual void SetIdentity() = 0;

	virtual void ClearColour(float r, float g, float b, float a) = 0;
	virtual void ClearScreen() = 0;

	virtual void EnableDepthTesting() = 0;



};

