#include "HUD.h"


HUD::HUD()
{
	Igui = new tgui::Gui();
}

tgui::Gui* HUD::GetGUI()
{
	return Igui;
}

void HUD::HUDInit(sf::RenderWindow* target)
{
	Igui->setWindow(*target);
}

void HUD::HUDEvent(IEvent event)
{
	Igui->handleEvent(event);
}

tgui::Widget::Ptr HUD::GetWidget(std::string wName, bool recursive) const
{
	return Igui->get(wName, recursive);
}

void HUD::SetFont(std::string fontPath)
{
	Igui->setGlobalFont(fontPath);
}

void HUD::Draw()
{
	Igui->draw();
}


tgui::Picture::Ptr HUD::CreateHUDBox(tgui::Gui& gui, std::string wName ,std::string image, 
	glm::vec2 size, glm::vec2 position, unsigned id)	
{
	tgui::Picture::Ptr background(*Igui, wName);
	background->load(image);
	background->setSize(size.r, size.g);
	background->setPosition(position.r, position.g);
	background->setCallbackId(id);

	return background;
}

tgui::Label::Ptr HUD::CreateLabel(tgui::Gui& gui, std::string wName, std::string text, glm::vec2 position, unsigned id)
{
	tgui::Label::Ptr label(*Igui, wName);
	label->setText(text);
	label->setPosition(position.r, position.g);
	label->setCallbackId(id);

	return label;
}

tgui::EditBox::Ptr HUD::CreateInputBox(tgui::Gui& gui, std::string wName, std::string wConfig,
	glm::vec2 size, glm::vec2 position, unsigned id)
{
	tgui::EditBox::Ptr textbox(*Igui, wName);
	textbox->load(wConfig);
	textbox->setSize(size.r, size.g);
	textbox->setPosition(position.r, position.g);
	textbox->setCallbackId(id);

	return textbox;
}

tgui::Button::Ptr HUD::CreateButton(tgui::Gui& gui, std::string wName, std::string wConfig, glm::vec2 size, glm::vec2 position,
	std::string text, unsigned id)
{
	tgui::Button::Ptr button(*Igui, wName);
	button->load(wConfig);
	button->setSize(size.r, size.g);
	button->setPosition(position.r, position.g);
	button->setText(text);
	button->bindCallback(tgui::Button::LeftMouseClicked);
	button->setCallbackId(id);

	return button;

}


HUD::~HUD()
{
	delete Igui;
}
