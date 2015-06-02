#include "InputHandler.h"

void InputHandler::BindAction(std::string action, Action keyCode)
{
	KeyBindings[action] = keyCode;
}