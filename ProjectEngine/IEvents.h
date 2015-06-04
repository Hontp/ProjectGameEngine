#ifndef EVENT_INTERFACE_H
#define EVENT_INTERFACE_H

#include<SFML/Window.hpp>

typedef sf::Event IEvent;
typedef sf::Event::KeyEvent KeyCode;
typedef sf::Event::EventType EventTypes;
typedef sf::Keyboard::Key Keys;
typedef sf::Mouse::Button MButtons;

typedef sf::Keyboard SJKeyboard;
typedef sf::Mouse SJMouse;

class IEvents
{
public:

	enum EventType
	{
		KeyPressed = sf::Event::KeyPressed,
		KeyReleased = sf::Event::KeyReleased,
		MButtonPressed = sf::Event::MouseButtonPressed,
		MButtonReleased = sf ::Event::MouseButtonReleased,
		MWheelMoved = sf::Event::MouseWheelMoved
	};

};

#endif