#pragma once

#include "SJWindow.h"


class Window
{
public:
	Window();

	Window(std::string name, int h, int w, int bp);

	~Window();

	void Initialize(std::string name, int h, int w, int bp);

	bool windowClosed();

	float getElaspedTime();



private:
	SJWindow window;

	std::string windowName;

	int height;
	int width;
	int BPP;

	bool windowed;


};

