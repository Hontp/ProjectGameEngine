#pragma once

#include "GameObject.h"

class StaticObject : public GameObject{

	public:

		StaticObject(unsigned short ID);
		~StaticObject();

		std::string Describe();

	private:


};

