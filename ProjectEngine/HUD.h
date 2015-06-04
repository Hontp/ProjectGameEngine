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
	
	bool GetCallbackEvent(tgui::Callback callback);

	void Draw();

	void CreateHUDBox(tgui::Gui& gui, std::string image, glm::vec2 size, glm::vec2 position);
	void CreateLabel(tgui::Gui& gui, std::string text, glm::vec2 position);
	void CreateInputBox(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position);
	void CreateButton(tgui::Gui& gui, std::string wConfig, glm::vec2 size, glm::vec2 position, std::string text);
};
