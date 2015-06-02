#pragma once

#include "InputHandler.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void InitKeys();

	bool isKeyPressed(std::string key);

private:
	InputHandler handler;


};

