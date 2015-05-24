#pragma once

#include "Material.h"

class MultiTexture : public Material{

	public:

		MultiTexture(unsigned short layers);
		~MultiTexture();

		void InitLayer(unsigned short layer, const std::string& filename, bool mipMaps, GLuint mipMapBehaviour = 0);

	private:

		GLuint* GL_layers;
		unsigned short layerCount;
};

