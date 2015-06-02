#include "RendererFactory.h"


RendererFactory::RendererFactory()
{
}


RendererFactory::~RendererFactory()
{
}

IRenderer *RendererFactory::CreateRenderer(const std::string &apiName)
{
	if (apiName == "OpenGL")
	{
		return new OpenGLRenderer();
	}
	else
	{
		return nullptr;
	}
}
