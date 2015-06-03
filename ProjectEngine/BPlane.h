#pragma once

#include "CollisionEntity.h"

/**	@class: BPlane
	@base: CollisionEntity

	@author: Joshua Voysey
	@date: 3rd June 2015
	@version: 1.0

	Description: The BPlane class represents a 2D plane in 3D space. It can be used to detect collisions with other BPlane objects and can be dynamically moved and resized.

*/
class BPlane : public CollisionEntity
{
	public:
		/**	@brief:		Constructor.
		
			@param:		position (glm::vec3) - Position of the origin point of the bounding plane.
			@param:		dimensions (glm::vec2) - Width and height of the bounding plane.

			@return:	A new BPlane object.
		*/
		BPlane(glm::vec3 position, glm::vec2 dimensions);

		/**	@brief:		Destructor.

			@param:		NONE.

			@return:	NONE. This BPlane object is destroyed.
		*/
		~BPlane();

		/**	@brief:		Check if this BPlane intersects another BPlane.

			@param:		plane (BPlane&) - Another BPlane object to test for intersection.

			@return:	TRUE if the two BPlanes intersect, else FALSE.
		*/
		bool intersects(BPlane &plane);

		/**	@brief:		Get the size of the BPlane object.

			@param:		NONE.

			@return:	(glm::vec2) - Width and Height of the BPlane object.
		*/
		glm::vec2 Size() const;

		/**	@brief:		Change the size of the BPlane object.

			@param:		_size (glm::vec2) - The new width and height of the BPlane object.

			@return:	NONE.
		*/
		void UpdateSize(glm::vec2 _size);

		/**	@brief:		Get the Y-co-ordinate of the BACK edge of the BPlane object.

			@param:		NONE.

			@return:	(float) - Y-co-ordinate of the BPlane's back edge.
		*/
		float back() const;

		/**	@brief:		Get the X-co-ordinate of the LEFT edge of the BPlane object.

			@param:		NONE.

			@return:	(float) - X-co-ordinate of the BPlane's left edge.
		*/
		float left() const;

		/**	@brief:		Get the X-co-ordinate of the RIGHT edge of the BPlane object.

			@param:		NONE.

			@return:	(float) - X-co-ordinate of the BPlane's right edge.
		*/
		float right() const;

		/**	@brief:		Get the Y-co-ordinate of the FRONT edge of the BPlane object.

			@param:		NONE.

			@return:	(float) - Y-co-ordinate of the BPlane's front edge.
		*/
		float front() const;

	private:

		glm::vec2 size;		// Width & height of the bounding plane.
};

