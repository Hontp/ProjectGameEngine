#pragma once

#include "OpenGL.h"

static class GraphicsCore{

	public:

		static bool Init(unsigned short API_ID);

		/**	@class: API.

			Description: This class encapsulates all enueration values related to the GraphicsCore interface's valid third-party graphics libraries.
		*/
		class API{
			public: 
				static enum : unsigned short {OPENGL = 1};
		};

	private:

};

