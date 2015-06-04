#pragma once

#include "Material.h"

/**	@class: Texture.

	@Author: Joshua Voysey
	@Date: 14th May 2015
	@Version: 1.1

	Description: This class holds the image data for a model, as well as all filtering, wrapping, and mipmap functionality.
*/
class Texture : public Material{

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

	private:

		
};

