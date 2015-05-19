#pragma once

#include "OpenGL.h"
#include "ImageLoader.h"

/**	@class: GraphicsCore.

	@Author: Joshua Voysey
	@Date: 10th May 2015
	@Version: 1.1

	Description: Interface between Game engine and Third party graphics APIs.
*/
class GraphicsCore{

	public:

		/**	@brief: Initialise the GraphicsCore interface.

			@param: API_ID (unsigned short) - An value representing a valid ID number to load a third-party library interface.

			Desciption: Initialise the graphics interface to the desired third-party API.
			Currently supports:
			> OpenGL

			@return: TRUE if the API was successfully loaded, otherwise FALSE.
		*/
		static bool Init(unsigned short API_ID);

		/**	@brief: Get the current graphics API being used.
		
			@param: NONE.

			Description: This function returns a numerical value that corresponds to the value of an enumeration from the GraphicsCore::API class.

			@return: An unsigned short value.
		*/
		static unsigned short GetActiveAPI();

		/**	@brief: Create an OpenGL texture.

			@param: NONE.

			Description: Create an OpenGL texture object.

			@return: A handle to access the OpenGL texture object.
		*/
		static GLuint Create_GLTexture();

		/**	@brief: Delete an OpenGL texture.

			@param: handle (GLuint) - The OpenGL handle for accessing the texture object.

			Description: Delete the OpenGL texture object pointed to by 'handle'.

			@return: NONE.
		*/
		static void Delete_GLTexture(GLuint handle);

		/**	@brief: Set the filtering type that a texture will use.

			@param:	textureHandle (GLuint) - The OpenGL handle for accessing the texture object.
			@param: filteringType (GLuint) - The type of filtering that is desired.

			Description:	Set the filtering behaviour that the texture will use for magnification and minification purposes.

							For OpenGL:
								gl::NEAREST
								gl::LINEAR

			@return: NONE.
		*/
		static void Texture_SetFiltering(GLuint textureHandle, GLuint filteringType);

		/**	@brief: Set the wrapping type that a texture will use.

			@param: textureHandle (GLuint) - The OpenGL handle for accessing the texture object.
			@param: wrappingType (GLuint) - The type of wrapping that is desired.

			Description:	Set teh wrapping behaviour that the texture will use.

							For OpenGL:
								gl::REPEAT
								gl::CLAMP_TO_EDGE

			@return: NONE.
		*/
		static void Texture_SetWrapping(GLuint textureHandle, GLuint wrappingType);

		/**	@brief: Load data from an image file.

			@param: textureHandle (GLuint) - The OpenGL handle for accessing the texture object.
			@param: fileName (const char*) - The filepath of the texture object.

			Description: Load a texture object with all of the image data that it needs.

			@return: NONE.
		*/
		static void Texture_LoadFile(GLuint textureHandle, const char* fileName);

		/**	@brief: Set the focus of texture operations on a certain texture object.

			@param: textureHandle (GLuint) - The OpenGL handle for accessing the texture object.

			Description: Using a handle variable, set the owning texture object as the active texture object. Used for doing texture manipulation.

			@return: NONE.
		*/
		static void Texture_FocusOn(GLuint textureHandle);

		/**	@brief: Generate mipmaps for a texture, as well as its behaviours.

			@param: textureHandle (GLuint) - The OpenGL handle for accessing the texture object.
			@param: mipMapBehaviour (GLuint) - A value specifying the desired mipmap behaviour.

			Description:	Generate mipmaps for a texture, as well as its behaviours.

							For OpenGL:
								gl::NEAREST_MIPMAP_NEAREST
								gl::NEAREST_MIPMAP_LINEAR
								gl::LINEAR_MIPMAP_NEAREST
								gl::LINEAR_MIPMAP_LINEAR

			@return: NONE.
		*/
		static void Texture_GenMipMaps(GLuint textureHandle, GLuint mipMapBehaviour);

		/**	@brief: Clear the current frame buffer in preparation for drawing the NEXT frame buffer.
		
			@param: NONE.

			Description: Clear the current frame buffer in preparation for drawing the NEXT frame buffer.

			@return: NONE.
		*/
		static void ClearBuffers();

		/**	@class: API.

			Description: This class encapsulates all enueration values related to the GraphicsCore interface's valid third-party graphics libraries.
		*/
		class API{
			public: 
				static enum : unsigned short {OPENGL = 1};
		};

	private:

		static ImageLoader* imgLoader;		// Used for data loading from image files.

};

