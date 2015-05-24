#include "MultiTexture.h"

MultiTexture::MultiTexture(unsigned short _layers){

	layerCount = GraphicsCore::MultiTexture_ValidateLayerCount(_layers);
	GL_layers = nullptr;

	switch (GraphicsCore::GetActiveAPI()){

		case (unsigned short)GraphicsCore::API::OPENGL:

			GL_layers = GraphicsCore::Create_GLMultiTexture(layerCount);
			break;

		default:
			break;
	}
}

MultiTexture::~MultiTexture(){

	for (unsigned short i = 0; i < layerCount; i++)

		switch (GraphicsCore::GetActiveAPI()){

			case (unsigned short)GraphicsCore::API::OPENGL:
				GraphicsCore::Delete_GLTexture(GL_layers[i]);
				break;

			default:
				break;
		}

}

void MultiTexture::InitLayer(unsigned short layer, const std::string& filename, bool mipMaps, GLuint mipMapBehaviour){

	if (layer < layerCount)
		GraphicsCore::Texture_LoadFile(GL_layers[layer], filename.c_str());

	if (mipMaps)
		GraphicsCore::Texture_GenMipMaps(GL_layers[layer], mipMapBehaviour);

}