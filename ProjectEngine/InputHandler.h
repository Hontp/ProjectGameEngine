#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include"IEvents.h"
#include<map>
#include<string>

class InputHandler
{

public:

	/** input event object
	*/
	IEvents InputEvents;

	/** device enumerations
	*/
	enum InputDevice
	{
		KeyboardInput,
		MouseInput
	};

	/** structure to hold the input device
	* an event type
	* the assoicated keys, buttons
	*/
	struct Action
	{
		InputDevice device;
		EventTypes eventType;
		Keys keyCode;
		MButtons mouseButton;
	};

	
	std::map<std::string, InputHandler::Action> KeyBindings;

	/** bind an action to an action name
	*/
	void BindAction(std::string action , Action keys);

};

#endif