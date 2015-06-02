#pragma once

#include "GameObject.h"
#include <vector>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Initialize();

	void LoadResources();
	void UnloadResources();

	void Update(float dt);

	void Draw(float dt);

private:

};

