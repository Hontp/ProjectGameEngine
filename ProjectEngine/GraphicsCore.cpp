#include "GraphicsCore.h"

static unsigned short _API = NULL;

/**	@brief: Initialise the GraphicsCore interface.
	
	@param: API_ID (unsigned short) - An value representing a valid ID number to load a third-party library interface.

	Desciption: Initialise the graphics interface to the desired third-party API.
				Currently supports:
					> OpenGL

	@return: TRUE if the API was successfully loaded, otherwise FALSE.
*/
bool GraphicsCore::Init(unsigned short API_ID){

	_API = API_ID;
	bool ping;

	if (_API == API::OPENGL){
		ping = OpenGL::Init();
	}

	return ping;
}
