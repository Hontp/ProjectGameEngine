#include "GameAssetFactory.h"

/**	@brief: Create a new GameObject object.

	@param: ID (unsigned short) - Specify the type of object that is being created.

	Description: Factory method for creating any / all types of game assets. This method is STATIC.

	@return: A GameObject object pointer.

	NOTE:	Cast the pointer to a pointer of the desired child class when this method is called.
			E.G. Player* p = (Player*)GameAssetFactory::CreateNew(OBJ_ID::PLAYER);
*/
GameObject* GameAssetFactory::CreateNew(unsigned short ID){

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
			break;
		default:
			obj = nullptr;
	}

	return obj;
}