#pragma once

#include "GameObject.h"

/**	@class: StaticObject.

	@parent: GameObject.

	Description: The StaticObject class handles all game assets that do NOT use animations or AI.
*/
class StaticObject : public GameObject{

	public:

		StaticObject();
		~StaticObject();

		std::string Describe();

		void Init();

		void Update();

		void Draw();

	private:


};

