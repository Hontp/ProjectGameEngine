#pragma once

#include "GraphicsCore.h"

/**	@class: Texture.

	@Author: Joshua Voysey
	@Date: 14th May 2015
	@Version: 1.1

	Description: This class holds the image data for a model, as well as all filtering, wrapping, and mipmap functionality.
*/
class Texture{

	public:

		/**	@brief: Constructor.

			@param: NONE

			Description: Function for creating a new Texture object.

			@return: A new Texture object.
		*/
		Texture();

		/**	@brief: Destructor.

			@param: NONE.

			Description: Destroy this specific Texture object.

			@return: NONE.
		*/
		~Texture();

		/**	@brief: Initialise the Texture object.

			@param: filename (const std::string&) - file path of the texture image file.
			@param: mipMaps (boolean) - True if texture mipmaps generation is desired, otherwise FALSE.
			@param: mipMapBehaviour (GLuint) - Value only needs to be set if mipMaps is TRUE. Enumerations specifying a valid behaviour for automatic mipmap filtering.

			Description: Initialisation function for loading relevant texture data into the Texture class.

			@return: NONE.
		*/
		void Init(const std::string& filename, bool mipMaps, GLuint mipMapBehaviour = 0);

		/**	@brief: Activate the current texture.

			@param: NONE.

			Description: Activate the current texture as the active texture. Used when drawing to specify the correct texture to draw on the model.

			@return: NONE.
		*/
		void Activate();

		/**	@brief: Set the filtering behaviour for the texture.

			@param: filteringType (GLuint) - Enumeration value specifying the desired filtering behaviour.

			Description: Set the magnification / minification filtering behaviour to the desired type.

			@return: NONE.
		*/
		void SetFiltering(GLuint filteringType);

		/**	@brief: Set the wrapping behaviour for the texture.

			@param: wrappingType (GLuint) - Enumeration value specifying the desired wrapping behaviour.

			Description: Set the model wrapping behaviour of the texture for UV co-ordinates outside of ( 0.0 <-> 1.0 ).

			@return: NONE.
		*/
		void SetWrapping(GLuint wrappingType);

	private:

		GLuint GL_handle;	// A handle used for OpenGL function processing.
};

