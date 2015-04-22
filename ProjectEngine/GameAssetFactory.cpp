#include "GameAssetFactory.h"

static GameAssetFactory* instance = nullptr;

GameAssetFactory::GameAssetFactory(){



}


GameAssetFactory::~GameAssetFactory(){

	delete instance;

}


GameAssetFactory GameAssetFactory::Instance(){

	if (instance == nullptr)
		instance = new GameAssetFactory();

	return *instance;
}


GameObject* GameAssetFactory::CreateNew(unsigned short ID){

	GameObject* obj = nullptr;

	switch (ID){
		case OBJ_ID::CHAR::PLAYER:
			obj = new Player(ID);
			break;
		case OBJ_ID::CHAR::SML_NPC:
		case OBJ_ID::CHAR::MED_NPC:
		case OBJ_ID::CHAR::LRG_NPC:
			obj = new NPC(ID);
			break;
		case OBJ_ID::OBJ::SML_STATIC:
		case OBJ_ID::OBJ::MED_STATIC:
		case OBJ_ID::OBJ::LRG_STATIC:
			obj = new StaticObject(ID);
			break;
		case OBJ_ID::OBJ::TERRAIN:
			/// TODO: Create a terrain object.
			break;
		default:
			obj = nullptr;
	}

	return obj;
}