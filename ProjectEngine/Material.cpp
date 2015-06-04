#include "Material.h"

void Material::Activate(){

	GraphicsCore::Texture_FocusOn(GL_handle);

}

void Material::SetFiltering(GLuint filteringType){

	GraphicsCore::Texture_SetFiltering(GL_handle, filteringType);

}

void Material::SetWrapping(GLuint wrappingType){

	GraphicsCore::Texture_SetWrapping(GL_handle, wrappingType);

}