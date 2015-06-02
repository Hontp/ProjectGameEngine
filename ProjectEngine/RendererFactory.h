#pragma once

#include "IRenderer.h"
#include "OpenGLRenderer.h"
#include "Singleton.h"

class RendererFactory
{

public:
	RendererFactory();
	~RendererFactory();

	IRenderer *CreateRenderer(const std::string &apiName);
};

