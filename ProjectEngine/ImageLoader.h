#ifndef IMAGE_H
#define IMAGE_H

#include <SFML\Graphics.hpp>
#include<string>

class ImageLoader
{
private:
	// image object
	sf::Image image;

public:

	bool LoadImageFile(const std::string& filename);
	sf::Image GetImage();
	sf::Vector2u GetDimension();

};


#endif