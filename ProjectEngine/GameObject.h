#pragma once

#include <iostream>
#include <string>

static class OBJ_ID{

	public:

		static enum : unsigned short{DUMMY = 0, PLAYER = 1, NPC = 2, STATIC = 3, TERRAIN = 4};

};

class GameObject{

	public:

		GameObject(){};
		~GameObject(){};

		virtual std::string Describe(){ return "This is a Game Object.\n"; };
		
		virtual void Init(){};

		virtual void Update(){};

		virtual void Draw(){};

	protected:

		float rotation;
		// TODO: Add a vector3 equivalent parameter for position.
};