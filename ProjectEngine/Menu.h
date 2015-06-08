#ifndef MENU_H
#define MENU_H

#include "SJWindow.h"
#include "HUD.h"

class Menu
{
private:

	// create a new hud object
	HUD hud = HUD();

	// pointer to the widget object for the manual
	tgui::Picture::Ptr manual;

	// pointer to the widget object forthe exit button
	tgui::Button::Ptr exit;

public:

	/**
	* Constructor for Menu Class
	*/
	Menu();

	/**
	* destructor for Menu Class
	*/
	~Menu();

	/**
	* Public Access function for
	* manual object pointer
	*/
	tgui::Picture::Ptr Manual();

	/**
	* Public Access function for
	* exit pointer
	*/
	tgui::Button::Ptr Exit();


	/**
	* Initialize menu system
	* manual pointer and sets
	* the font
	* @param window pointer to current window context
	*/
	void InitMenu(SJTarget *window);

	/**
	* Register Menu events to
	* SFML
	* @param event IEvents abstract event class of SFML
	*/
	void MenuEventHandler(IEvent events);

	/**
	* Load widgets created widgets for rendering
	* @param window pointer to current window context
	*/
	void Load(SJTarget *window);
	
	/**
	* Render Menu to Screen
	*/
	void Draw();

	/**
	* Listening for widget interaction
	* from the user
	*/
	unsigned Listener();
};

#endif
