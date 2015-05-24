#pragma once

#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include "OpenGL.h"

class GLM
{

	public:

		/**	@brief: Create a LookAt target matrix. This documentation assumes camera creation.
			
			@param: Position glm::vec3) - World position of the camera.
			@param: Target (glm::vec3) - World position of the LookAt target.
			@param: UpVector (glm::vec3) - Up direction, for calculating the z rotation / direction of the camera.

			Description: Create a matrix that represents the direction that the camera is looking at.

			@return: A matrix representing the direction that the camera is looking at.
		*/
		static glm::mat4 CreateLookAtMatrix(glm::vec3 Position, glm::vec3 Target, glm::vec3 UpVector);

		/**	@brief: Create a perspective matrix. This documentation assumes camera creation.

			@param: FieldOfView (GLfloat) - The angle that represents the field of view limit for the camera (0 is straight ahead).
			@param: AspectRatio (GLfloat) - The aspect ration of the camera.
			@param: NearPlane (GLfloat) - The minimum distance from the camera's position that an object must be to be rendered onscreen.
			@param: FarPlane (GLfloat) - The maximum distance from the camera's position that an object must be to be rendered onscreen.

			Description: Create the distortion on the LookAt matrix that will simulate a human's vision.

			@return: A matrix representing the distortion matrix to simulate human vision.
		*/
		static glm::mat4 CreatePerspectiveMatrix(GLfloat FieldOfView, GLfloat AspectRatio, GLfloat NearPlane, GLfloat FarPlane);

		/**	@brief: Cross two vectors to get the UpVector

			@param: 

			Description: 

			@return: 
		*/
		static glm::vec3 CrossVectors(glm::vec3 X_Vector, glm::vec3 Y_Vector);

	private:

};

