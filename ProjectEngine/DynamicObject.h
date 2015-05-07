#pragma once

#include "GameObject.h"
#include <string>

/**	@class: DynamicObject.

	@parent: GameObject.

	Description: The Dynamic Object class is the base class for all objects which utilise animation and AI.
*/
class DynamicObject : public GameObject{

	public:

		DynamicObject();
		~DynamicObject();

		std::string Describe();

		virtual void Init();

		virtual void Update();

		virtual void Draw();

	private:


};

