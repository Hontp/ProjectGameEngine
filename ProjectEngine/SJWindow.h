#ifndef SJ_WINDOW_H
#define SJ_WINDOW_H

/**
 * @File: SJWindow.h
 * @version: 0.1v
 * @author: Thanh Hon
 *
 * @section DESCRIPTION
 *
 * Window Creation class
 * this class wraps the SFML libary
 * to create a new window 
 */


#include<SFML/Graphics.hpp>
#include<SFML/OpenGL.hpp>
#include<string>
#include<map>

class SJWindow
{
private:

	// underlying SFML window object
	sf::RenderWindow window;

	// SFML contextSettings object
	sf::ContextSettings setting;

	// SFML video settings
	sf::VideoMode videoMode;

	//enumeration for window style
	static enum Style
	{
		None,
		Default,
		FullScreen,
		Resizable,
		Titlebar
	};

	// map window styles enumeration to string value
	std::map<std::string, Style> winStyle;

public:

	/**
	 * Constructor
	 *
	 */
	SJWindow();
	~SJWindow();

	/**
	 * Create New Window
	 *
	 * @param VideoMode Screen size height and width as integer
	 * @param Title the window caption
	 * @param Style a window border style
	 * @param settings information about Depthbits, StencilBits, AntiAliasing
	 */
	void CreateMainWindow(sf::VideoMode& Mode, const std::string& Title, UINT32 Style , sf::ContextSettings& settings);

	/**
	 * Get Window Event
	 *
	 * @return true if a polled event fires
	 *
	 */
	bool GetEvent(sf::Event & events);

	/**
	* Display Window
	*
	*/
	void Display();

	/** @brief: Enable 2D rendering.
	
	
	*/
	void Begin();

	/**
	* Draw an element on the window.
	*
	*/
	void Draw(sf::Drawable &element);

	/** @brief: Disable 2D rendering.
	
	*/
	void End();

	/**
	* Clear rendered elements.
	*
	*/
	void Clear(sf::Color color = sf::Color::Blue);

	/**
	 * Set Window Border Style
	 *
	 * @param StyleName as a string value
	 *
	 * @return an integer that correspond to the Style Enumeration
	 *
	 */
	UINT32 SetStyle(std::string StyleName);

	/**
	 * Set Window Context information such as
	 * DepthBits, StencilBits, AntiAliasing and Opengl Version
	 *
	 * @param DepthBits
	 * @param StencilBits
	 * @param AntiAliasing
	 * @param Major
	 * @param Minor
	 *
	 * @return ContextSettings Object for use in underlying SFML libary
	 */
	sf::ContextSettings SetContextSettings(unsigned int depth = 0, unsigned int stencil = 0, 
						unsigned int antialiasing = 0, unsigned int major = 2, unsigned int minor = 0);

	/**
	 * Set the screen resolution size
	 * 
	 * @param Width as an unsigned integer
	 * @param Height as an unsigned integer
	 * @param BitPerPixel as an unsigned integer
	 */
	sf::VideoMode SetVideoMode(unsigned Width, unsigned Height, unsigned BitPerPixel = 32);

	float getElaspedTime();

	

};


#endif