#pragma once

#include "GameObject.h"

class NPC : public GameObject{

	public:

		NPC(unsigned short ID);
		~NPC();

		std::string Describe();

	private:


};

