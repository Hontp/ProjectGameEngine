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
	* the associated keys, buttons
	*/
	struct Action
	{
		InputDevice device;
		EventTypes eventType;
		Keys keyCode;
		MButtons mouseButton;
	};

	/**
	* A Map that stores a string name to an action
	* object
	*/	
	std::map<std::string, InputHandler::Action> KeyBindings;

	/** 
	* bind an action object to an action name
	* @param action
	* @param keys
	*/
	void BindAction(std::string action , Action keys);

	/**
	* Get the key associated to the action
	* @param actionName as string
	*/
	Keys GetKey(std::string actionName);


};

#endif