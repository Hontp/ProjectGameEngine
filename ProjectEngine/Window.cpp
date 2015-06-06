#include "Window.h"
#include "Timing.h"


Window::Window()
{
	width = 800;
	height = 600;
	windowName = "My Game";
	BPP = 32;
}


Window::Window(std::string name, int w, int h, int bp)
{
	windowName = name;
	height = h;
	width = w;
	BPP = bp;

	window.CreateMainWindow(window.SetVideoMode(height, width, BPP), windowName, window.SetStyle("Default"), window.SetContextSettings());
}

Window::~Window()
{
}

void Window::Initialize(std::string name, int h, int w, int bp)
{
	windowName = name;
	height = h;
	width = w;
	BPP = bp;

	window.CreateMainWindow(window.SetVideoMode(height, width, BPP), windowName, window.SetStyle("Default"), window.SetContextSettings());
}
