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

    private:

		enum : unsigned short{ VERTEX = 0, COLOR = 1, UV = 2 };

		GLuint vertexBufferID;              // VBO handle.
		GLuint colorBufferID;
		GLuint uvBufferID;
		GLuint vertexArrayID;               // VAO handle.

		//Texture texture;                    // Texture object.

		float* modelData;					// Container for vertex position data.
		float* colorData;					// Container for vertex color data.
		float* uvData;						// Container for vertex texture co-ordinate data.

		GLint vBufferLength;                // Length of the 'modelData' variable when it is filled.
		GLint cBufferLength;				// Length of the 'colorData' variable when it is filled.
		GLint uBufferLength;				// Length of the 'uvData' variable when it is filled.

		bool isTextured;                    // Flag for if the model is textured or not.

        int dimensions;
};