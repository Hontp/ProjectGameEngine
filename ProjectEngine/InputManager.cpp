#include "InputManager.h"
#include <iostream>


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::InitKeys()
{
	InputHandler::Action keyEvent;

	keyEvent.device = handler.KeyboardInput;


	// bind movement keys
	// WASD
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::W;
	handler.BindAction("W", keyEvent);

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::A;
	handler.BindAction("A", keyEvent);

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::S;
	handler.BindAction("S", keyEvent);

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::D;
	handler.BindAction("D", keyEvent);

	// bind exit key
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::X;
	handler.BindAction("X", keyEvent);
	
}

bool InputManager::isKeyPressed(std::string action)
{
	if (SJKeyboard::isKeyPressed(handler.GetKey(action)))
		return true;

	return false;
}
