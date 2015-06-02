#pragma once

#include <iostream>

#include "IRenderer.h"
#include "ResourceManager.h"
#include "Singleton.h"
#include "RendererFactory.h"
#include "Window.h"

class Engine
{
public:
	Engine();
	~Engine();

	virtual void Initialize();

	virtual void LoadResources() = 0;

	virtual void UnloadResources() = 0;

	virtual void Update(float dt);

	virtual void Draw(float dt);

	void Run();
	void Stop();

	IRenderer *getRenderer();
	ResourceManager *getResourceManager();
	Window *getWindowDevice();

protected:

	ResourceManager *aManager;
	IRenderer *renderer;
	Window *window;

private:
	float previousElaspedTime;
	bool run;

};

