#pragma once

#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "StaticObject.h"

class GameAssetFactory{

	public:

		static GameAssetFactory Instance();

		static GameObject* CreateNew(unsigned short ID);			// TODO: Add a vector3 for position as a parameter.

	private:
		GameAssetFactory();
		~GameAssetFactory();

};

