#include "SJWindow.h"


SJWindow::SJWindow()
{	
	winStyle.insert({ "None", Style::None });
	winStyle.insert({ "Default", Style::Default });
	winStyle.insert({ "FullScreen", Style::FullScreen });
	winStyle.insert({ "Resizable", Style::Resizable });
	winStyle.insert({ "Titlebar", Style::Titlebar });
}

SJWindow::~SJWindow(){}

void SJWindow::CreateMainWindow(sf::VideoMode& Mode, const std::string& Title, UINT32 Style, sf::ContextSettings& settings)
{
	window.create(Mode, Title, Style, settings);
}

bool SJWindow::GetEvent(sf::Event& events)
{
	return window.pollEvent(events);
}

void SJWindow::Display()
{
	window.display();
}

sf::ContextSettings SJWindow::SetContextSettings(unsigned int depth, unsigned int stencil,
	unsigned int antialiasing, unsigned int major, unsigned int minor)
{
	setting.depthBits = depth;
	setting.stencilBits = stencil;
	setting.antialiasingLevel = antialiasing;
	setting.majorVersion = major;
	setting.minorVersion = minor;

	return setting;
}

sf::VideoMode SJWindow::SetVideoMode(unsigned Width, unsigned Height, unsigned BitPerPixel)
{
	videoMode.width = Width;
	videoMode.height = Height;
	videoMode.bitsPerPixel = BitPerPixel;

	return videoMode;
}

UINT32 SJWindow::SetStyle(std::string StyleName)
{
	UINT32 style;

	switch (winStyle.find(StyleName)->second)
	{
	case SJWindow::None:
		style = sf::Style::None;
		break;

	case SJWindow::Default:
		style = sf::Style::Default;
		break;

	case SJWindow::FullScreen:
		style = sf::Style::Fullscreen;
		break;

	case SJWindow::Resizable:
		style = sf::Style::Resize;
		break;

	case SJWindow::Titlebar:
		style = sf::Style::Titlebar;
		break;

	default:
		style = sf::Style::Default;
		break;
	}

	return style;
}