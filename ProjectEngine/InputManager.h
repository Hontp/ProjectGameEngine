#pragma once

#include "InputHandler.h"

class InputManager
{
public:

	/**
	* InputManager Constructor
	*
	*/
	InputManager();
	~InputManager();

	/**
	* Bind a key to an action
	*
	*/
	void InitKeys();


	/**
	* listen for a key press event
	*
	* @param action as string
	*/
	bool isKeyPressed(std::string action);

private:

	// input handler object
	InputHandler handler;


};


