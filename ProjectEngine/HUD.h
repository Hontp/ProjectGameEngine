#pragma once

#include <TGUI/TGUI.hpp>
#include <string>
#include <glm.hpp>
#include "IEvents.h"

// call back handler
typedef tgui::Callback Callback;

class HUD
{
private:
	/**
	* Pointer to GUI object
	*
	*/
	tgui::Gui *Igui;
	
public:
	/**
	* default Constructor
	*/
	HUD();

	/**
	*
	* Destructor
	*/
	~HUD();

	/**
	* Public access function to
	* gui pointer object
	*/
	tgui::Gui* GetGUI();
	

	/**
	*
	* Initialize Hud Object
	*
	* @param *target pointer to current window context
	*
	*/
	void HUDInit(sf::RenderWindow* target);

	/**
	*
	* Set the Font used for the hud
	*
	* @param fontpath string to font directory
	*
	*/
	void SetFont(std::string fontPath);
	
	/**
	*
	* Register the HUD Event listener to the underlying
	* SFML polling event system
	*
	* @param events as IEvent - abstract of SFML events
	*
	*/
	void HUDEvent(IEvent events);

	/**
	*
	* public accessor function to the widget object 
	* 
	* @param wName the widget name
	* @param recursive boolean flag to call this funcion in recursive
	*
	* @return address of wigdet object
	*/
	tgui::Widget::Ptr GetWidget(std::string wName, bool recursive = false) const;
	

	/**
	*
	* Renders all HUD elements to the screen
	*
	*/
	void Draw();

	/**
	*
	* create new box widget from an image
	*
	* @param *gui pointer to gui object
	* @param wName widget name
	* @param image path to image file
	* @param size widget size as vector2
	* @param position as vector3
	* @param id widget ID as unsigned int
	*/
	tgui::Picture::Ptr CreateHUDBox(tgui::Gui& gui, std::string wName, std::string image, glm::vec2 size, glm::vec2 position, unsigned id);

	/**
	*
	* create new label widget
	*
	* @param *gui pointer to gui object
	* @param wName widget name
	* @param text specify a text to display
	* @param position as vector3
	* @param id widget ID as unsigned int
	*/
	tgui::Label::Ptr CreateLabel(tgui::Gui& gui, std::string wName, std::string text, glm::vec2 position, unsigned id);

	/**
	*
	* create new Text Box
	*
	* @param *gui pointer to gui object
	* @param wName widget name
	* @param wConfig widget configuration file
	* @param size widget size as vector2
	* @param position as vector3
	* @param id widget ID as unsigned int
	*/
	tgui::EditBox::Ptr CreateInputBox(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position, unsigned id);

	/**
	*
	* create new Button object
	*
	* @param *gui pointer to gui object
	* @param wName widget name
	* @param wConfig widget configuration file
	* @param size widget size as vector2
	* @param position as vector3
	* @param text button text
	* @param id widget ID as unsigned int
	*/
	tgui::Button::Ptr CreateButton(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position, std::string text, unsigned id);
};
