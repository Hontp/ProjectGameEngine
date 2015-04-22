#include "StaticObject.h"


StaticObject::StaticObject(unsigned short ID){

	ID_val = ID;

}


StaticObject::~StaticObject(){



}


std::string StaticObject::Describe(){
	return "This is a static object.\n";
}