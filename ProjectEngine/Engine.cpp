#include "Engine.h"
#include <iostream>


Engine::Engine()
{
	RendererFactory rFactory;

	window = new Window();

	renderer = rFactory.CreateRenderer("OpenGL");
	aManager = Singleton<ResourceManager>::getInstance();
	
	run = true;


}


Engine::~Engine()
{
	if (window != nullptr)
	{
		delete window;
	}
	if (renderer != nullptr)
	{
		delete renderer;
	}
}

void Engine::Initialize()
{
	window->Initialize("Le Game", 800, 600, 32);
}

void Engine::Update(float dt)
{

}

void Engine::Draw(float dt)
{

}

void Engine::Run()
{

}

void Engine::Stop()
{
	run = false;
}

IRenderer * Engine::getRenderer()
{
	return renderer;
}

ResourceManager * Engine::getResourceManager()
{
	return aManager;
}

Window *Engine::getWindowDevice()
{
	return window;
}
