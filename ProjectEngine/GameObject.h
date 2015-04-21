#pragma once

#include <iostream>
#include <string>

class OBJ_ID{

	public:

		static class CHAR{

			private:
				static const char mod = 0;
			public:
				static enum : unsigned short { PLAYER = 0 + mod, SML_NPC = 1 + mod, MED_NPC = 2 + mod, LRG_NPC = 3 + mod };
		};

		static class OBJ{

			private:
				static const char mod = 5;
			public:
				static enum : unsigned short { SML_STATIC = 0 + mod, MED_STATIC = 1 + mod, LRG_STATIC = 2 + mod, TERRAIN = 3 + mod };
		};

		static class MISC{

			private:
				static const char mod = 10;
			public:
				static enum : unsigned short {  };
		};

};

class GameObject{

	public:

		GameObject(unsigned short _ID) { ID_val = _ID; };
		GameObject() { ID_val = OBJ_ID::CHAR::SML_NPC; }
		~GameObject(){};

		virtual std::string Describe(){ return "This is a Game Object.\n"; };

		unsigned short ID() const {	return ID_val;	};
		void SetID(unsigned short _ID) { ID_val = _ID; }

	protected:

		unsigned short ID_val;
		// TODO: Add a vector3 equivalent parameter for position, and also possibly rotation.
};