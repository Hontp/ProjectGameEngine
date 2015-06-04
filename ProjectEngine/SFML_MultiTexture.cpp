#include "SFML_MultiTexture.h"

SFML_MultiTexture::SFML_MultiTexture(unsigned short _layers)
{
	
}

SFML_MultiTexture::~SFML_MultiTexture()
{
	while (!layers.empty())
	{
		delete layers.back();	// Deallocate the memory.
		layers.pop_back();		// Remove the now NULL pointer from the vector.
	}
}

void SFML_MultiTexture::InitLayer(unsigned short layer, std::string& fileName)
{
	if (layer < layers.size())
	{
		layers[layer]->Init(fileName);
	}
	else
	{
		SFML_Texture* tex = new SFML_Texture;

		tex->Init(fileName);

		layers.push_back(tex);
	}
}

void SFML_MultiTexture::Activate()
{
	layers[0]->Activate();
}

void SFML_MultiTexture::ActivateLayer(unsigned short layer)
{
	if (layer < layers.size())
		layers[layer]->Activate();
}

void SFML_MultiTexture::Deactivate()
{
	layers[0]->Deactivate();
}

void SFML_MultiTexture::DeactivateLayer(unsigned short layer)
{
	if (layer < layers.size())
		layers[layer]->Deactivate();
}