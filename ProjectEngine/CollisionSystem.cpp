#include "CollisionSystem.h"

void CollisionSystem::collide(BPlane &entity1, BPlane &entity2)
{
	if (entity1.intersects(entity2)){
		std::cout << "Collision!" << std::endl;
	}
}

void CollisionSystem::collide(BPlane &entity1, std::vector<BPlane> &entityList)
{
	for (unsigned int i = 0; i < entityList.size(); i++){
		if (entity1.intersects(entityList[i])){
			std::cout << "Collision!" << std::endl;
		}
	}
}