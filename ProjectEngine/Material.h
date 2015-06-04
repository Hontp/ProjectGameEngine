#pragma once

#include "GraphicsCore.h"

class Material{

	public:

		Material(){};

		/**	@brief: Activate the current material.

			@param: NONE.

			Description: Activate the current material as the active material. Used when drawing to specify the correct material to draw on the model.

			@return: NONE.
		*/
		void Activate();

		/**	@brief: Set the filtering behaviour for the material.

			@param: filteringType (GLuint) - Enumeration value specifying the desired filtering behaviour.

			Description: Set the magnification / minification filtering behaviour to the desired type.

			@return: NONE.
		*/
		void SetFiltering(GLuint filteringType);

		/**	@brief: Set the wrapping behaviour for the material.

			@param: wrappingType (GLuint) - Enumeration value specifying the desired wrapping behaviour.

			Description: Set the model wrapping behaviour of the material for UV co-ordinates outside of ( 0.0 <-> 1.0 ).

			@return: NONE.
		*/
		void SetWrapping(GLuint wrappingType);

	protected:

		GLuint GL_handle;	// A handle used for OpenGL function processing.
};