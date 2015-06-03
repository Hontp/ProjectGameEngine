#pragma once

#include<glm.hpp>

/**	@class: CollisionEntity

	@author: Joshua Voysey
	@date: 3rd June 2015
	@version: 1.0

	Description: The CollisionEntity class is the base class for ALL objects used for collision detection.
*/
class CollisionEntity
{
	public:	

		// Enumerations for different tags, so when collisions occur they can have different behaviour depending on the tags.
		static enum : unsigned short {	DUMMY = 0,		WALL = 1,		TRIGGER = 2,		NPC = 3,		PLAYER = 4		};

	protected:

		///////////////////   METHODS   //////////////////////////

		/**	@brief:  
		
			@param: 

			@return: 
		*/
		CollisionEntity(){};

		/**	@brief:

			@param:

			@return:
		*/
		virtual bool intersects(CollisionEntity &entity) = 0;

		/**	@brief:

			@param:

			@return:
		*/
		glm::vec3 Origin() const		{	return origin;	};

		/**	@brief:

			@param:

			@return:
		*/
		void UpdatePos(glm::vec3 _pos)	{	origin = _pos;	};

		/**	@brief:

			@param:

			@return:
		*/
		unsigned short Tag() const		{	return tag;		};

		/////////////////////////////////////////////////////////

		///////////////////   ATTRIBUTES   //////////////////////

		glm::vec3 origin;			// Origin point of the CollisionEntity object.
		unsigned short tag = DUMMY;	// Description of the nature of the CollisionEntity.

};

