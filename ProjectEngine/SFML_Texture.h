#pragma once

#include "Material.h"

#include <SFML/Graphics/Texture.hpp>
#include <iostream>

/**	@class: SFML_Texture.

	@Author: Joshua Voysey
	@Date: 14th May 2015
	@Version: 1.2

	Description: This class holds the image data for a model.
*/
class SFML_Texture : public Material{

	public:

		/**	@brief: Constructor.

			@param: NONE

			Description: Function for creating a new Texture object.

			@return: A new Texture object.
		*/
		SFML_Texture();

		/**	@brief: Destructor.

			@param: NONE.

			Description: Destroy this specific Texture object.

			@return: NONE.
		*/
		~SFML_Texture();

		/**	@brief: Initialise the Texture object.

			@param: 

			Description: Initialisation function for loading relevant texture data into the Texture class.

			@return: NONE.
		*/
		void Init(std::string &imgFile);

		/**	@brief: Activate this texture.

			@param: NONE.

			Description: Activate the current texture as the active texture. Used when drawing to specify the correct texture to draw on the model.

			@return: NONE.
		*/
		void Activate();

		/**	@brief: Deactivate this texture.

			@param: NONE.

			Description: Deactivate the current texture. Used wafter drawing to change the texture for the next model.

			@return: NONE.
		*/
		void Deactivate();

	private:

		sf::Texture texture;
		
};

