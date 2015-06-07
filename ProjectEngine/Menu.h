#ifndef MENU_H
#define MENU_H

#include "SJWindow.h"
#include "HUD.h"

class Menu
{
private:
	HUD hud = HUD();

	tgui::Picture::Ptr manual;
	tgui::Button::Ptr exit;

public:
	Menu();
	~Menu();

	tgui::Picture::Ptr Manual();
	tgui::Button::Ptr Exit();

	void InitMenu(SJTarget *window);
	void MenuEventHandler(IEvent events);
	void Load(SJTarget *window);
	void Draw();
	unsigned Listener();
};

#endif