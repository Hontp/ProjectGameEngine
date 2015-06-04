#include "SFML_Texture.h"

SFML_Texture::SFML_Texture()
{

}

SFML_Texture::~SFML_Texture()
{

}

void SFML_Texture::Init(std::string &imgFile)
{

	if (!texture.loadFromFile(imgFile))
	{
		std::cout << "Error: Could not load file: '" << imgFile.c_str() << "'." << std::endl;
	}
	
}

void SFML_Texture::Activate()
{
	sf::Texture::bind(&texture);
}

void SFML_Texture::Deactivate()
{
	sf::Texture::bind(NULL);
}