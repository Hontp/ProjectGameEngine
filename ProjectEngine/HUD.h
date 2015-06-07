#pragma once

#include <TGUI/TGUI.hpp>
#include <string>
#include <glm.hpp>
#include "IEvents.h"

typedef tgui::Callback Callback;

class HUD
{
private:
	tgui::Gui *Igui;
	
public:
	HUD();
	~HUD();

	tgui::Gui* GetGUI();
	
	void HUDInit(sf::RenderWindow* target);
	void SetFont(std::string fontPath);
	
	void HUDEvent(IEvent events);
	tgui::Widget::Ptr GetWidget(std::string wName, bool recursive = false) const;
	
	void Draw();

	tgui::Picture::Ptr CreateHUDBox(tgui::Gui& gui, std::string wName, std::string image, glm::vec2 size, glm::vec2 position, unsigned id);
	tgui::Label::Ptr CreateLabel(tgui::Gui& gui, std::string wName, std::string text, glm::vec2 position, unsigned id);
	tgui::EditBox::Ptr CreateInputBox(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position, unsigned id);
	tgui::Button::Ptr CreateButton(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position, std::string text, unsigned id);
};
