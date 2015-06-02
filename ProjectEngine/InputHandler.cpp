#include "InputHandler.h"

void InputHandler::BindAction(std::string action, Action keyCode)
{
	KeyBindings[action] = keyCode;
}

Keys InputHandler::GetKey(std::string actionName)
{
	Keys tmp = Keys();

	if (actionName != "")
	{
		tmp = KeyBindings[actionName].keyCode;

		return tmp;
	}	
	
	return tmp;
}