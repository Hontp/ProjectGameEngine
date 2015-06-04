#pragma once

// Standard libraries.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>

// 3D graphics libraries.
#include "GLM.h"
#include "OpenGL.h"
#include "GameObject.h"
#include "GL_Model.h"
#include "SFML_Texture.h"

// Local headers.
#include "FileReader.h"

/** @class: Terrain.

    Description:    
*/
class Terrain : public GameObject
{
    public:
        Terrain(int _dimensions){dimensions = _dimensions;  };            // Constructor.
        ~Terrain(){Destroy();}; // Destructor.

		/** @brief: Initialise the terrain object.

			@param: verts (GLfloat[]) - Array of color values to be passed to the program's active vertex shader.
			@param: vertBufferSize (GLint) - Size of the verts array.
			@param: colors (GLfloat[]) - Array of color values to be passed to the program's active fragment shader.
			@param: colorBufferSize (GLint) - Size of teh colors array.

			Description: Pass the data into the Terrain object's internal Model object and run its initialisation.

			@pre: NONE.

			@post: Terrain's model mesh is now fully functional.
		*/
		void Init(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBufferSize, GLfloat UVdata[], GLint uvBufferSize, const std::string &fileName);

		/** @brief: Render the Terrain object onscreen.

			Description: Call the internal Model object's Render function.

			@pre: The Terrain object should be initialised.

			@post: The terrain has been drawn onscreen.
		*/
        void Render();

		/** @brief: Clear data from the Terrain object.

			Description: Call the internal Model object's Destroy function.

			@pre: The Terrain object should be initialised.

			@post: The Terrain object's internal Model object is now empty.
		*/
        void Destroy();

		/** @brief: Access the Terrain object's model.

			Description: Get a pointer to the internal model object.

			@pre: The Terrain object should be initialised.

			@post: NONE.
		*/
		GL_Model* AccessModel();

		/** @brief: Access the Terrain object's model.

			Description: Get a pointer to the internal texture object.

			@pre: The Terrain object should be initialised.

			@post: NONE.
		*/
		SFML_Texture* AccessTex();

    private:

		SFML_Texture texture;     // Texture object.
		GL_Model model;			// Model object.

        int dimensions;
};