#include "HUD_Element.h"


HUD_Element::HUD_Element(std::string _text, unsigned short textSize, sf::Color color)
{
	text.UpdateText(_text, textSize, color);
}

HUD_Element::~HUD_Element()
{

}

Text HUD_Element::GetText()
{
	return text;
}

void HUD_Element::UpdateText(std::string _text, unsigned short textSize, sf::Color color)
{
	text.UpdateText(_text, textSize, color);
}