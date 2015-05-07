#include "ImageLoader.h"

bool ImageLoader::LoadImageFile(const std::string& filename)
{
	if (image.loadFromFile(filename))
		return true;

	return false;
}

sf::Image ImageLoader::GetImage()
{
	return image;
}

sf::Vector2u ImageLoader::GetDimension()
{
	return image.getSize();
}