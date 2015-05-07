#include "StaticObject.h"


StaticObject::StaticObject(){
}

StaticObject::~StaticObject(){
}

std::string StaticObject::Describe(){
	return "This is a static object.\n";
}

/**	@brief: Dynamic Object initialisation.

	Description: Initialise the static object's position, model data, and any behaviours.

	TODO: Add a model data object parameter.
	TODO: Add a vector parameter for 3D position data.
	TODO: Add a float parameter for rotation.
	TODO: Add some way of passing bahaviour data into this function.
*/
void StaticObject::Init(){

}

/**	@brief: Dynamic Object Rendering.

	Description: Update the static object's model.

	TODO: Add actual code LOL.
*/
void StaticObject::Update(){

}

/**	@brief: Dynamic Object Rendering.

	Description: Render the static object's model.

	TODO: Add actual code LOL.
*/
void StaticObject::Draw(){

}