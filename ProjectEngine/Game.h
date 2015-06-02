#pragma once

#include "Engine.h"
#include "GameAssetFactory.h"
#include "SceneManager.h"

class Game : public Engine
{
public:
	Game();
	~Game();

	virtual void Initialize();

	virtual void LoadResources();

	virtual void UnloadResources();

	virtual void Update(float dt);

	virtual void Draw(float dt);


private:
	SceneManager *sceneManager;

	GameAssetFactory *gameAssetFactory;


};

