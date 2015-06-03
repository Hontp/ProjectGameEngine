#include "Terrain.h"

/** @brief: Initialise the terrain object.
    
    @param: verts (GLfloat[]) - Array of color values to be passed to the program's active vertex shader.
    @param: vertBufferSize (GLint) - Size of the verts array.
    @param: colors (GLfloat[]) - Array of color values to be passed to the program's active fragment shader.
    @param: colorBufferSize (GLint) - Size of teh colors array.

    Description: Pass the data into the Terrain object's internal Model object and run its initialisation.

    @pre: NONE.

    @post: Terrain is now fully functional.
*/
void Terrain::Init(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBuffSize, GLfloat UVdata[], GLint uvBuffSize, const std::string &fileName){
	
	if (fileName != "")
		isTextured = true;

	// Generate a VAO object.
	gl::GenVertexArrays(1, &vertexArrayID);
	gl::BindVertexArray(vertexArrayID);

	////////////////////   BEGIN LOAD VERTEX DATA    ////////////////////////////

	modelData = verts;
	vBufferLength = vertBuffSize;
	// Generate a VBO object.
	gl::GenBuffers(1, &vertexBufferID);
	gl::BindBuffer(gl::ARRAY_BUFFER, vertexBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, vBufferLength * sizeof(modelData), modelData, gl::STATIC_DRAW);

	////////////////////   END LOAD VERTEX DATA      ////////////////////////////

	////////////////////   BEGIN LOAD COLOR DATA     ////////////////////////////

	colorData = colors;
	cBufferLength = colorBuffSize;

	// Generate another buffer object for color information.
	gl::GenBuffers(1, &colorBufferID);
	gl::BindBuffer(gl::ARRAY_BUFFER, colorBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, cBufferLength * sizeof(colorData), colorData, gl::STATIC_DRAW);
	////////////////////   END LOAD COLOR DATA       ////////////////////////////

	////////////////////   BEGIN LOAD UV DATA     ////////////////////////////

	if (isTextured){

		uvData = UVdata;
		uBufferLength = uvBuffSize;

		gl::GenBuffers(1, &uvBufferID);
		gl::BindBuffer(gl::ARRAY_BUFFER, uvBufferID);
		gl::BufferData(gl::ARRAY_BUFFER, uBufferLength * sizeof(uvData), uvData, gl::STATIC_DRAW);
	}
		
	////////////////////   END LOAD UV DATA     ////////////////////////////
	
	// Generate a texture (CURRENTLY NON-FUNCTIONAL).
	//texture.load(textureFile);

}

void Terrain::Render(){

	// First attribute buffer : vertices
	gl::EnableVertexAttribArray(VERTEX);
	gl::BindBuffer(gl::ARRAY_BUFFER, vertexBufferID);
	gl::VertexAttribPointer(
		VERTEX,						// attribute 0.
		3,							// size
		gl::FLOAT,					// type: GLfloat
		gl::FALSE_,					// normalized?
		0,							// stride
		(void*)0					// array buffer offset
	);

	////////////////////   END LOAD VERTEX DATA      ////////////////////////////


	////////////////////   BEGIN LOAD COLOR DATA     ////////////////////////////
	gl::EnableVertexAttribArray(COLOR);
	gl::BindBuffer(gl::ARRAY_BUFFER, colorBufferID);
	gl::VertexAttribPointer(
		COLOR,						// attribute 1.
		3,							// size
		gl::FLOAT,					// type: GLfloat
		gl::FALSE_,					// normalized?
		0,							// stride
		(void*)0					// array buffer offset
	);

	////////////////////   END LOAD COLOR DATA       ////////////////////////////


	////////////////////   BEGIN LOAD TEXTURE DATA   ////////////////////////////
	if (isTextured){

		gl::EnableVertexAttribArray(UV);
		gl::BindBuffer(gl::ARRAY_BUFFER, uvBufferID);
		gl::VertexAttribPointer(
			UV,							// attribute 2.
			2,                          // size
			gl::FLOAT,                  // type: GLfloat
			gl::FALSE_,                 // normalized?
			0,							// stride
			(void*)(0)					// array buffer offset
		);
	}

	////////////////////   END LOAD TEXTURE DATA     ////////////////////////////

	// Draw the model array.
	gl::DrawArrays(gl::TRIANGLES, 0, vBufferLength);

	gl::DisableVertexAttribArray(VERTEX);
	gl::DisableVertexAttribArray(COLOR);

	if (isTextured)
		gl::DisableVertexAttribArray(UV);
}

void Terrain::Destroy(){
	gl::DeleteBuffers(1, &vertexBufferID);
	gl::DeleteBuffers(1, &colorBufferID);

	if (isTextured)
		gl::DeleteBuffers(1, &uvBufferID);

	gl::DeleteVertexArrays(1, &vertexArrayID);
}