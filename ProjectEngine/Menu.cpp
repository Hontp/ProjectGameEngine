#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

tgui::Picture::Ptr Menu::Manual()
{
	if (manual != nullptr)
	return manual;
	
	return nullptr;
}

tgui::Button::Ptr Menu::Exit()
{
	if (exit != nullptr)
		return exit;

	return nullptr;
}

void Menu::InitMenu(SJTarget *window)
{
	hud.HUDInit(window);
	hud.SetFont("UI/Fonts/DejaVuSans.ttf");
}

void Menu::MenuEventHandler(IEvent events)
{
	hud.HUDEvent(events);
}

void Menu::Load(SJTarget *window)
{
	// create exit button
	exit = hud.CreateButton(*hud.GetGUI(),"btnExit" ,"UI/widgets/Black.conf", glm::vec2(100, 50), 
		glm::vec2(0, 550), "Exit",1);

	// create manual screen
	manual = hud.CreateHUDBox(*hud.GetGUI(), "bgManual", "UI/Background/manual.png", glm::vec2(500, 450), glm::vec2(window->getSize().x /4, 
		window->getSize().y/5), 2);
	manual->hide();

}

void Menu::Draw()
{
	hud.Draw();
}

unsigned Menu::Listener()
{
	Callback callback;
	while (hud.GetGUI()->pollCallback(callback))
	{
		// exit button id
		if (callback.id == 1)
		{
			return 1;
		}
	}

	return 0;
}

