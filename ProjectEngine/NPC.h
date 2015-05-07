#pragma once

#include "DynamicObject.h"

class NPC : public DynamicObject{

	public:

		NPC();
		~NPC();

		std::string Describe();

		void Init();

		void Update();

		void Draw();

	private:


};

