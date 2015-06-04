#pragma once

#include "Material.h"
#include "SFML_Texture.h"

#include <iostream>
#include <vector>

class SFML_MultiTexture : public Material{

	public:

		SFML_MultiTexture(unsigned short layers);
		~SFML_MultiTexture();

		void InitLayer(unsigned short layer, std::string& fileName);

		void Activate();
		void ActivateLayer(unsigned short layer);

		void Deactivate();
		void DeactivateLayer(unsigned short layer);

	private:

		void Init(std::string& fileName){};

		std::vector<SFML_Texture*> layers;
		unsigned short layerCount;
};

