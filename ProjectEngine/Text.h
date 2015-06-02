#pragma once
#pragma once

#include <iostream>
#include <SFML\Graphics\Text.hpp>

class Text
{
	public:
		Text();
		~Text();

		void setFont(sf::Font _font);
		void setStyle(sf::Text::Style style);

		void setAbsPosition(int screenPosX, int screenPosY);
		void setRelPosition(int screenPosX, int screenPosY);

		void setAbsRotation(float _rot);
		void setRelRotation(float _rot);

		void UpdateText(std::string UpdatedText, unsigned short textSize, sf::Color color = sf::Color::White);
		std::string getString() const;
		sf::Vector2f Position() const;

		sf::Text Get() const;

	private:

		sf::Vector2f position;
		sf::Text text;
		unsigned short textSize;
};

