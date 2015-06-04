#pragma once

// 3D Graphics libraries.
#include "OpenGL.h"
#include "JVShader.h"
#include "GLM.h"

///****************************************   IMPORTANT

/** @class: Camera.

	@author: Joshua Voysey.
	@date: 31st May 2015.
	@version: 1.1

    Description:    The Camera class is a basic projection class that alters the 2D screen co-ordinates of 3D vertices to simulate a first-person perspective.
                    Intended to be bound to a CameraController object for an FPS-style world interface.
*/
class Camera{

    public:
		Camera() { ModelMatrix = glm::mat4(1.0f); };      // Constructor.
        ~Camera(void) {};                                   // Destructor.

		/** @brief: Initialise a Camera object.

			@param: _pos (glm::vec3) - Position of the camera's origin.
			@param: _lookAt (glm::vec3) - Position of the target that the camera is pointing at.
			@param: _fov (GLfloat) - Peripheral vision camera can see around the lookAt direction.
			@param: _nearPlane (GLfloat) - minimum distance from camera's position before clipping occurs.
			@param: _farPlane (GLfloat) - maximum distance from camera's position before clipping occurs.

			Description:    Basic variable definitions occur here. Matrices are calculated after variables are changed.

			@pre: NONE.

			@post: Camera object is now fully functional.
		*/
        void Init(glm::vec3 _pos, glm::vec3 _lookAt, GLfloat _fov, GLfloat _nearPlane, GLfloat _farPlane);

		/** @brief: Update the camera's position to the inputted co-ordinates.

			@param: _newPos (glm::vec3) - Camera's new co-ordinates.

			Description: Setter for the camera's position.

			@pre: Camera object should be initialised.

			@post: The Camera's position has been altered.
		*/
        void MoveTo(glm::vec3 _newPos);

		/** @brief: Update the camera's target to the inputted co-ordinates.

			@param: _newTarget (glm::vec3) - Camera target's new co-ordinates.

			Description: Setter for the camera's look-at target.

			@pre: Camera object should be initalised.

			@post: The camera's directional target has been altered.
		*/
        void SetLookAt(glm::vec3 _newTarget);

		/** @brief: Set the camera's near clipping plane to a new value.

			@param: _newNear (GLfloat) - Camera's new minimum clipping distance.

			Description: Setter for the camera's near clipping plane.

			@pre: Camera object should be intialised.

			@post: NONE.
		*/
        void SetNearPlane(GLfloat _newNear);

		/** @brief: Set the camera's far clipping plane to a new value.

			@param: _newFar (GLfloat) - Camera's new maximum clipping distance.

			Description: Setter for the camera's far clipping plane.

			@pre: Camera object should be initialised.

			@post: NONE.
		*/
        void SetFarPlane(GLfloat _newFar);

		/** @brief: Set the display mode for the camera.

			Description: Change the display settings for any geometry that has been drawn on screen.

			@param: ping (boolean) - Flag that dictates the render mode of the camera.

			@return: Onscreen mesh display is set to either wireframes (if TRUE) or filled polygons (if FALSE);

			@pre: OpenGL should be initialised in some form.

			@post: OpenGL's rendering mode has been set to either wireframe or filled polygon display.
		*/
        void SetWireFrameMode(bool ping);

		/** @brief: Link the camera's MVP matrix to the specified shader.

			Description: Link any transformations in the camera's MVP matrix to the specified shader's geometry calculations.

			@param: shaderProgram (JVShader) - Shader that is being linked to.

			@return: NONE.

			@pre: The vertex shader should have a matrix parameter called MVP, which represents the shader's Model-View-Projection matrix.

			@post: The camera is now linked to the vertex shader.
		*/
		void BindToShader(JVShader shaderProgram) { matrixID = gl::GetUniformLocation(shaderProgram.Program(), "MVP"); }

		/** @brief: Calculate the camera's Projection Matrix.

			Description: If any of the camera's values are altered, call this function.

			@pre: Camera object should be initialised.

			@post: The Camera's projection matrix has been updated.
		*/
        void RecalcProjMatrix();

		/** @brief: Calculate the camera's View Matrix.

			Description: If any of the camera's values are altered, call this function.

			@pre: Camera object should be initialised.

			@post: The Camera's view matrix has been updated.
		*/
        void RecalcViewMatrix();

		/** @brief: Calculate the camera's Model-View-Projection Matrix.

			Description: If any of the camera's values are altered, call this function.

			@pre: Camera object should be initialised.

			@post: The Camera's MVP matrix has been altered to reflect changes in any of the other matrices.
		*/
        void RecalcMVPMatrix();

		// Access certain internal variables.
		GLuint MatrixID() const { return matrixID; };
		glm::mat4 MVP_Matrix() const  { return MVP; };
		glm::mat4 View_Matrix() const { return ViewMatrix; };
		glm::mat4 Proj_Matrix() const { return ProjMatrix; };
		glm::vec3 GetPosition() const;
		glm::vec3 GetUpVector() const;

        void SetViewMatrix(glm::mat4 newView);
        void SetPosition(glm::vec3 newPosition);

    private:

        GLfloat FoV;            // Camera's field of view (in degrees).
        GLfloat nearPlane;      // Camera's minimum draw distance.
        GLfloat farPlane;       // Camera's maximum draw distance.
        GLuint matrixID;        // Handle for MVP uniform.

        glm::vec3 Position;     // Camera's position.
        glm::vec3 LookAt;       // Position of Camera's target.
        glm::vec3 Up;           // Camera's up vector.

        glm::mat4 ProjMatrix;   // Camera's projection matrix.
        glm::mat4 ViewMatrix;   // Camera's view matrix.
        glm::mat4 ModelMatrix;  // An identity matrix.

        glm::mat4 MVP;          // Camera's ModelViewProjection combined matrix.
};

