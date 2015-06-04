#pragma once

#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "StaticObject.h"
#include "GLM.h"
#include "TerrainFactory.h"

class GameAssetFactory{

	public:

		/**	@brief: Create a new GameObject object.

			@param: ID (unsigned short) - Specify the type of object that is being created.
			@param: position (glm::vec3) - Position co-ordinates to spawn the GameObject.

			Description: Factory method for creating any / all types of game assets. This method is STATIC.

			@return: A GameObject object pointer.

			NOTE:	Cast the pointer to a pointer of the desired child class when this method is called.
			E.G. Player* p = (Player*)GameAssetFactory::CreateNew(OBJ_ID::PLAYER);
		*/
		static GameObject* CreateNew(unsigned short ID, glm::vec3 position);

		static void Init(TerrainFactory* _factory);

	private:

		static TerrainFactory* factory;
};

