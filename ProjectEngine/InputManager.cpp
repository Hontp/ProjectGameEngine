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
	// W, A, S, D
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

	// bind fly mode keys
	// F, L_SHIFT, SPACE
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::F;
	handler.BindAction("F", keyEvent);

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::LShift;
	handler.BindAction("L_SHIFT", keyEvent);

	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::Space;
	handler.BindAction("SPACE", keyEvent);

	// bind mouse lock toggle
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::C;
	handler.BindAction("C", keyEvent);

	// bind wireframe mode toggle
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::K;
	handler.BindAction("K", keyEvent);

	// bind manual key
	keyEvent.eventType = (EventTypes)handler.InputEvents.KeyPressed;
	keyEvent.keyCode = SJKeyboard::M;
	handler.BindAction("M", keyEvent);
}

bool InputManager::isKeyPressed(std::string action)
{
	if (SJKeyboard::isKeyPressed(handler.GetKey(action)))
		return true;

	return false;
}
