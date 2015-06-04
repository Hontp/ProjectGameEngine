#include "Texture.h"

Texture::Texture(){

	GL_handle = GraphicsCore::Create_GLTexture();

}

Texture::~Texture(){

	GraphicsCore::Delete_GLTexture(GL_handle);

}

void Texture::Init(const std::string& filename, bool mipMaps, GLuint mipMapBehaviour){

	GraphicsCore::Texture_LoadFile(GL_handle, filename.c_str());

	if (mipMaps){
		GraphicsCore::Texture_GenMipMaps(GL_handle, mipMapBehaviour);
	}
}