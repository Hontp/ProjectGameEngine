#pragma once

#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "StaticObject.h"

class GameAssetFactory{

	public:

		static GameObject* CreateNew(unsigned short ID);

	private:

};

