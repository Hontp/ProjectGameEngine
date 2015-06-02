#include "Game.h"


Game::Game()
{
	sceneManager = new SceneManager();
	gameAssetFactory = new GameAssetFactory();
}


Game::~Game()
{
	if (sceneManager != nullptr)
	{
		delete sceneManager;
		delete gameAssetFactory;
	}
}

void Game::Initialize()
{

	sceneManager->Initialize();

	Engine::Initialize();
}

void Game::LoadResources()
{
	sceneManager->LoadResources();
}

void Game::UnloadResources()
{
	sceneManager->UnloadResources();
}

void Game::Update(float dt)
{
	sceneManager->Update(dt);
}

void Game::Draw(float dt)
{
	sceneManager->Draw(dt);
}
