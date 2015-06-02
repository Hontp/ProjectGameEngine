#pragma once

#include "Text.h"

class HUD_Element
{
	public:
		HUD_Element(std::string text, unsigned short textSize, sf::Color color = sf::Color::White);
		~HUD_Element();

		Text GetText();
		void UpdateText(std::string _text, unsigned short textSize, sf::Color color = sf::Color::White);

	private:
		Text text;
};

