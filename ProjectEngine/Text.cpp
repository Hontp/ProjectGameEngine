#include "Text.h"


Text::Text()
{

}

Text::~Text()
{

}

void Text::setFont(sf::Font _font)
{
	text.setFont(_font);
}

void Text::setStyle(sf::Text::Style style)
{
	text.setStyle(style);
}

void Text::setAbsPosition(int screenPosX, int screenPosY)
{
	text.setPosition(screenPosX, screenPosY);
}

void Text::setRelPosition(int screenPosX, int screenPosY)
{
	text.move(screenPosX, screenPosY);
}

void Text::setAbsRotation(float _rot)
{
	text.setRotation(_rot);
}

void Text::setRelRotation(float _rot)
{
	text.rotate(_rot);
}

void Text::UpdateText(std::string UpdatedText, unsigned short textSize, sf::Color color)
{
	if (UpdatedText != "")
		text.setString(UpdatedText);

	if (textSize != 0)
		text.setCharacterSize(textSize);

	text.setColor(color);
}

std::string Text::getString() const
{
	return text.getString();
}

sf::Vector2f Text::Position() const{
	return position;
}

sf::Text Text::Get() const
{
	return text;
}