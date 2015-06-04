#include "GameAssetFactory.h"

TerrainFactory* GameAssetFactory::factory = nullptr;

GameObject* GameAssetFactory::CreateNew(unsigned short ID, glm::vec3 position){

	GameObject* obj = nullptr;

	switch (ID){
		case OBJ_ID::PLAYER:
			obj = new Player();
			break;
		case OBJ_ID::NPC:
			obj = new NPC();
			break;
		case OBJ_ID::STATIC:
			obj = new StaticObject();
			break;
		case OBJ_ID::TERRAIN:
			/// TODO: Create a terrain object.
			obj = factory->BuildAt(position);
			break;
		default:
			obj = nullptr;
	}

	return obj;
}

void GameAssetFactory::Init(TerrainFactory* _factory)
{
	factory = _factory;
}