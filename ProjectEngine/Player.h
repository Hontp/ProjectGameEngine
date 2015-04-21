#pragma once

#include "GameObject.h"

class Player : public GameObject{

	public:

		Player(unsigned short ID);
		~Player();

		std::string Describe();

	private:


};

