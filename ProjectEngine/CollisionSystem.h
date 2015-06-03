#pragma once

#include <iostream>
#include <vector>

#include "Singleton.h"
#include "BPlane.h"

/**	@class: CollisionSystem
	@base: Singleton < CollisionSystem >

	@author: Joshua Voysey
	@date: 3rd June 2015
	@version: 1.0

	Description: The CollisionSystem class handles all collision behaviour between various CollisionEntity child classes.

					Currently supports:
						* BPlane
						* 
*/
class CollisionSystem : public Singleton<CollisionSystem>
{
	public:

		/**	@brief: Collide a BPlane with another (single) BPlane,

			@param: entity1 (BPlane&) - The entity that is testing for collisions.
			@param: entity2 (BPlane&) - The entity that is BEING tested for collision.

			@return: NONE. If there is a collision then entity1 may enact some sort of coded response.
		*/
		void collide(BPlane &entity1, BPlane &entity2);

		/**	@brief: Collide a BPlane with a list of multiple BPlanes.

			@param: entity1 (BPlane&) - The entity that is testing for collisions.
			@param: entity2 (std::vector < BPlane& >) - A list of entities that are BEING tested for collision.

			@return: NONE. If there is a collision then entity1 may enact some sort of coded response.
		*/
		void collide(BPlane &entity, std::vector<BPlane> &entityList);

	private:


};

