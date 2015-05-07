#pragma once

#include "DynamicObject.h"

class Player : public DynamicObject{

	public:

		Player();
		~Player();

		std::string Describe();

		void Init();

		void Update();

		void Draw();

	private:


};

