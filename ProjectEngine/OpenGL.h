#pragma once

#include "gl_core_4_3.hpp"
#include <SFML\Graphics.hpp>

/**	@class: OpenGL.

	@Author: Joshua Voysey
	@Date: 5th May 2015
	@Version: 1.2

	Description: Wrapper class for in-game implemented OpenGL functions.
*/
class OpenGL{

	public:

		/**	@class: OpenGL.

			@Author: Joshua Voysey
			@Date: 5th May 2015
			@Version: 1.2

			Description: Storage class for OpenGL vertex attribute enumerations.
		*/
		class VERT_ATTRIBUTE{
			public:
				static enum { NULL_ = -1, POSITION = 0, COLOR = 1, UV = 2 };
		};

		/**	@brief: Initialisation function.

			@param: NONE.

			Desciption: Initialise the OpenGL library functions.

			@return: TRUE if initialisation was successful, else FALSE.
		*/
		static bool Init();

		/**	@brief: Generate a Vertex Array Object.

			@param: handle (GLUINT) - A handle variable that will be used to access the VAO.

			Desciption: Create a new Vertex Array Object.

			@return: NONE (handle passed via reference technically returned).
		*/
		static void VAO_Gen(GLuint& handle);

		/**	@brief: Generate a VBO.

			@param: bufferHandle (GLuint) - A handle variable that will be used to access the VBO.
			@param: size (GLsizei) - Size of the VBO array (should be a combination of vertex position / color / UV data array sizes).

			Desciption: Create a new Vertex Buffer Object.

			@return: NONE (handle passed via reference technically returned).
		*/
		static void VBO_Gen(GLuint& bufferHandle, GLsizei size, float data[]);

		/**	@brief: Bind (Access) the VBO object.

			@param: bufferHandle (GLuint) - Handle for a VBO.

			Desciption: Access a VBO to allow manipulation of inner parameters.

			@return: NONE.
		*/
		static void VBO_Bind(GLuint bufferHandle);

		/**	@brief: Fill a VBO with data (position, color, or UV). NOTE: CURRENTLY NON-FUNCTIONAL.

			@param: bufferHandle (GLuint) - Handle for a VBO.
			@param: data (float[]) - Data to be added to the VBO.
			@param: size (unsigned int) - Size of the data array being added.
			@param: offset (GLsizei) - Offset from the beginning of the VBO's buffer. Prevents overriding previously added data.

			Desciption: ADD a data array to the VBO.

			@return: NONE.
		*/
		static void VBO_Fill(GLuint bufferHandle, float data[], unsigned int size, GLsizei offset);

		/**	@brief: Reset the screen frame.

			@param: NONE.

			Desciption: Clear the screen frame in preparation for drawing the NEXT frame.

			@return: NONE.
		*/
		static void clearBuffers();

		/**	@brief: Enable a vertex attribute.

			@param: enable (unsigned int) - An enumeration value from the VERT_ATTRIBUTE class corresponding to a vertex attribute.

			Desciption: Enable a vertex attribute when drawing the VBO onscreen.

			@return: NONE.
		*/
		static void enableVertexAttributes(unsigned int enable);

		/**	@brief: Bind a buffer to a vertex attribute.

			@param: vertexAttribute (unsigned int) - An enumeration value from the VERT_ATTRIBUTE class corresponding to a vertex attribute.
			@param: VBO_handle (GLuint) - A handle for a VBO.

			Desciption: When drawing the VBO, the data array must be bound to the corrseponding attribute via this function.

			@return: NONE.
		*/
		static void BindBuffer(unsigned int vertexAttribute, GLuint &VBO_handle);

		/**	@brief: Disable a vertex attribute.

			@param: disableVertex (boolean) - TRUE to disable the POSITION vertex attribute.
			@param: disableColor (boolean) - TRUE to disable the COLOR vertex attribute.
			@param: disableUV (boolean) - TRUE to disable the UV vertex attribute.

			Desciption: After the VBO has been drawn, disable the activated vertex attributes.

			@return: NONE.
		*/
		static void disableVertexAttributes(bool disableVertex, bool disableColor = false, bool disableUV = false);

		/**	@brief: Draw the VBO.

			@param: size (unsigned int) - Size of the VBO's buffer.

			Desciption: Draw the VBO onscreen.

			@return: NONE.
		*/
		static void DrawAsTriangles(unsigned int size);

		/**	@brief: Toggle wireframe display mode ON.

			@param: NONE.

			Desciption: Set the display mode of OpenGL VBO drawing to wireframe models.

			@return: NONE.
		*/
		static void DisplayAs_WireFrame();

		/**	@brief: Toggle fill display mode ON.

			@param: NONE.

			Desciption: Set the display mode of OpenGL VBO drawing to filled models.

			@return: NONE.
		*/
		static void DisplayAs_Fill();

		/**	@brief: Get a link to a variable in a shader program.

			@param: ShaderProgram (GLuint) - Handle to access a shader program.
			@param: name (const char*) - The name of the variable in the shader program.

			Desciption: Create a handle to access a variable inside of a shader program.

			@return: (GLuint) - Address value of the variable 'name' inside the shader program.
		*/
		static GLuint CreateLinkToShader(GLuint ShaderProgram, const char* name);

		/**	@brief: Link a texture object to a shader program.

			@param: textureHandle (GLuint) - Handle to access a texture object.
			@param: ShaderProgram (GLuint) - Handle to access a shader program.
			@param: name (const char*) - The name of the variable in the shader program.

			Desciption: Link a texture object to a shader program.

			@return: (GLuint) - Address value of the variable 'name' inside the shader program.
		*/
		static GLuint LinkTexObjToShader(GLuint textureHandle, GLuint ShaderProgram, const char* name);

		/**	@brief: Link data to a shader program.

			@param: VBO_Handle (GLuint) - Handle to access a VBO.
			@param: ShaderProgram (GLuint) - Handle to access a shader program.
			@param: attributeName (const char*) - The name of the variable in the shader program.
			@param: data (GLfloat[]) - The data to link to the shader.
			@param: valuesPerVertex (GLuint) - The number of values that each vertex requires (I assume that it is 2 for UV data and 3 for COLOR / POSITION data).

			Desciption: Link data to a shader program.

			@return: (GLuint) - Address value of the variable 'attributeName' inside the shader program.
		*/
		static GLuint LinkDataToShaderParameter(GLuint VBO_Handle, GLuint ShaderProgram, const char* attributeName, GLfloat data[], GLuint valuesPerVertex);

		/**	@brief: Generate a new OpenGL Texture object.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Create a new OpenGL Texture object, bound to the textureHandle parameter.

			@return: NONE (textureHandle passed via reference technically returned).
		*/
		static void Tex_Gen(GLuint &textureHandle);

		/**	@brief: Delete an OpenGL texture object.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Delete the Texture specified by textureHandle.

			@return: NONE.
		*/
		static void Tex_Del(GLuint &textureHandle);

		/**	@brief: Open the texture accessed by 'textureHandle'.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Access the internals of the OpenGL texture pointed to by 'textureHandle'.

			@return: NONE.
		*/
		static void Tex_SetAsActive(GLuint &textureHandle);

		/**	@brief: Load data into an OpenGL texture object.

			@param: textureHandle (GLuint) - Handle to access a texture object.
			@param: mipMapLevel (GLint) - Mipmap level of the specified texture object.
			@param: width (GLsizei) - Width of the texture image.
			@param: height (GLsizei) - Height of the texture image.
			@param: pixelArray (const sf::Uint8*) - Pixel data of the texture image.

			Desciption: Load data into an OpenGL texture object.

			@return: NONE.
		*/
		static void Tex_2D(GLuint textureHandle, GLint mipMapLevel, GLsizei width, GLsizei height, const sf::Uint8* pixelArray);

		/**	@brief: Generate texture mipmaps.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Generate mipmaps for the specified texture object pointed to by 'textureHandle'.

			@return: NONE.
		*/
		static void Tex_GenMipMaps(GLuint textureHandle);

		/**	@brief: Set the mipmap behaviour of an OpenGL texture object.

			@param: textureHandle (GLuint) - Handle to access a texture object.
			@param: behaviourType (GLuint) - Enumeration value specifying the type of mipmap behaviour to implement.

			Desciption: Set the mipmap behaviour of an OpenGL texture object.

			@return: NONE.
		*/
		static void Tex_SetMipMapBehaviour(GLuint textureHandle, GLuint behaviourtype);

		/**	@brief: Set the texture wrapping behaviour to REPEATING.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Set the texture so that it is repeated over the model.

			@return: NONE.
		*/
		static void Tex_SetWrapToRepeating(GLuint textureHandle);

		/**	@brief: Set the texture wrapping behaviour to CLAMPING.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Set the texture so that it is stretched (distorted) over the entire model.

			@return: NONE.
		*/
		static void Tex_SetWrapToClamping(GLuint textureHandle);

		/**	@brief: Set the minification / magnification filtering to LINEAR.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Set texture to use linear interpolation filtering for minification / magnification.

			@return: NONE.
		*/
		static void Tex_SetFilteringToLinear(GLuint textureHandle);

		/**	@brief: Set the minification / magnification filtering to NEAREST.

			@param: textureHandle (GLuint) - Handle to access a texture object.

			Desciption: Set texture to use nearest point filtering for minification / magnification.

			@return: NONE.
		*/
		static void Tex_SetFilteringToNearest(GLuint textureHandle);

	private:

		static bool vertexAttrib;
		static bool colorAttrib;
		static bool UVAttrib;

};