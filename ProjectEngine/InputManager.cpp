#include "InputManager.h"


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

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::A;

	handler.BindAction("A", keyEvent);
}
