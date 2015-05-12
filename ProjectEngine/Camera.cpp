#include "Camera.h"

/** @brief: Initilise a Camera object.

    @param: _pos (glm::vec3) - Position of the camera's origin.
    @param: _lookAt (glm::vec3) - Position of the target that the camera is pointing at.
    @param: _fov (GLfloat) - Perifieral vision camera can see around the lookAt direction.
    @param: _nearPlane (GLfloat) - minimum distance from camera's position before clipping occurs.
    @param: _farPlane (GLfloat) - maximum distance from camera's position before clipping occurs.

    Description:    Basic variable definitions occur here. Matrices are calculated after variables are changed.
    
    @pre: NONE.

    @post: Camera object is now fully functional.
*/
void Camera::Init(glm::vec3 _pos, glm::vec3 _lookAt, GLfloat _fov, GLfloat _nearPlane, GLfloat _farPlane){

    Position = _pos;
    LookAt = _lookAt;
    FoV = _fov;
    nearPlane = _nearPlane;
    farPlane = _farPlane;
    Up = glm::vec3(0,1,0);

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.

}

/** @brief: Update the camera's position to the inputted co-ordinates.
    
    @param: _newPos (glm::vec3) - Camera's new co-ordinates.

    Description: Setter for the camera's position.
    
    @pre: Camera object should be initialised.

    @post: The Camera's position has been altered.
*/
void Camera::MoveTo(glm::vec3 _newPos){

    Position = _newPos;     // Update the camera's position.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

/** @brief: Update the camera's target to the inputted co-ordinates.
    
    @param: _newTarget (glm::vec3) - Camera target's new co-ordinates.

    Description: Setter for the camera's look-at target.
    
    @pre: Camera object should be initalised.

    @post: The camera's directional target has been altred.
*/
void Camera::SetLookAt(glm::vec3 _newTarget){

    LookAt = _newTarget;    // Update the camera's LookAt target.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

/** @brief: Set the camera's near clipping plane to a new value.
    
    @param: _newNear (GLfloat) - Camera's new minimum clipping distance.

    Description: Setter for the camera's near clipping plane.
    
    @pre: Camera object should be intialised.

    @post: NONE.
*/
void Camera::SetNearPlane(GLfloat _newNear){

    nearPlane = _newNear;   // Update the camera's near plane.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

/** @brief: Set the camera's far clipping plane to a new value.
    
    @param: _newFar (GLfloat) - Camera's new maximum clipping distance.

    Description: Setter for the camera's far clipping plane.
    
    @pre: Camera object should be initialised.

    @post: NONE.
*/
void Camera::SetFarPlane(GLfloat _newFar){

    farPlane = _newFar;     // Update the camera's far plane.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

/** @brief: Calculate the camera's Projection Matrix.

    Description: If any of the camera's values are altered, call this function.
    
    @pre: Camera object should be initialised.

    @post: The Camera's projection matrix has been updated.
*/
void Camera::RecalcProjMatrix(){
    ProjMatrix = GLM::CreatePerspectiveMatrix(FoV, 4.0f / 3.0f, nearPlane, farPlane);
}

/** @brief: Calculate the camera's View Matrix.

    Description: If any of the camera's values are altered, call this function.
    
    @pre: Camera object should be initialised.

    @post: The Camera's view matrix has been updated.
*/
void Camera::RecalcViewMatrix(){
    ViewMatrix = GLM::CreateLookAtMatrix(Position, LookAt, glm::vec3(0,1,0));
}

/** @brief: Calculate the camera's Model-View-Projection Matrix.

    Description: If any of the camera's values are altered, call this function.
    
    @pre: Camera object should be initialised.

    @post: The Camera's MVP matrix has been altered to reflect changes in any of the other matrices.
*/
void Camera::RecalcMVPMatrix(){
    MVP = ProjMatrix * ViewMatrix * ModelMatrix;
}

/** @brief: Set the display mode for the camera.
    
    Description: Change the display settings for any geometry that has been drawn onscreen.

    @param: ping (boolean) - Flag that dictates the render mode of the camera.

    @return: Onscreen mesh display is set to either wireframes (if TRUE) or filled polygons (if FALSE);

    @pre: OpenGL should be initialised in some form.

    @post: OpenGL's rendering mode has been set to either wireframe or filled polygon display.
*/
void Camera::SetWireFrameMode(bool ping){

    if(ping){
		OpenGL::DisplayAs_WireFrame();
    }
    else{
		OpenGL::DisplayAs_Fill();
    }

}

glm::vec3 Camera::GetPosition(){
    return Position;
}

glm::vec3 Camera::GetUpVector(){
    return Up;
}

void Camera::SetViewMatrix(glm::mat4 newView){
    ViewMatrix = newView;
}

void Camera::SetPosition(glm::vec3 newPosition){
    Position = newPosition;
}