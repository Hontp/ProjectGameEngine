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

bool HUD::GetCallbackEvent(tgui::Callback callback)
{
	return Igui->pollCallback(callback);
}

void HUD::SetFont(std::string fontPath)
{
	Igui->setGlobalFont(fontPath);
}

void HUD::Draw()
{
	Igui->draw();
}


void HUD::CreateHUDBox(tgui::Gui& gui, std::string image, glm::vec2 size, glm::vec2 position)	
{
	tgui::Picture::Ptr background(*Igui);
	background->load(image);
	background->setSize(size.r, size.g);
	background->setPosition(position.r, position.g);
}

void HUD::CreateLabel(tgui::Gui& gui, std::string text, glm::vec2 position)
{
	tgui::Label::Ptr label(*Igui);
	label->setText(text);
	label->setPosition(position.r, position.g);
}

void HUD::CreateInputBox(tgui::Gui& gui,std::string wName, std::string wConfig, 
	glm::vec2 size, glm::vec2 position)
{
	tgui::EditBox::Ptr textbox(*Igui, wName);
	textbox->load(wConfig);
	textbox->setSize(size.r, size.g);
	textbox->setPosition(position.r, position.g);
}

void HUD::CreateButton(tgui::Gui& gui, std::string wConfig, glm::vec2 size, glm::vec2 position,
	std::string text)
{
	tgui::Button::Ptr button(*Igui, "Button");
	button->load(wConfig);
	button->setSize(size.r, size.g);
	button->setPosition(position.r, position.g);
	button->setText(text);
	button->bindCallback(tgui::Button::LeftMouseClicked);
	button->setCallbackId(1);

}

void HUD::setLabelText(std::string text)
{
	tgui::EditBox::Ptr foo = Igui->get("TextBox");
	std::cout << "BLAH!" << std::endl;
	foo->setText(text);
}

HUD::~HUD()
{
	delete Igui;
}
