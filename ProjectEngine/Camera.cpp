#include "Camera.h"


void Camera::Init(glm::vec3 _pos, glm::vec3 _lookAt, GLfloat _fov, GLfloat _nearPlane, GLfloat _farPlane)
{

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

void Camera::MoveTo(glm::vec3 _newPos)
{

    Position = _newPos;     // Update the camera's position.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

void Camera::SetLookAt(glm::vec3 _newTarget)
{

    LookAt = _newTarget;    // Update the camera's LookAt target.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

void Camera::SetNearPlane(GLfloat _newNear)
{

    nearPlane = _newNear;   // Update the camera's near plane.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

void Camera::SetFarPlane(GLfloat _newFar)
{

    farPlane = _newFar;     // Update the camera's far plane.

    RecalcProjMatrix();     // Recalculate Projection Matrix.
    RecalcViewMatrix();     // Recalculate View Matrix.
    RecalcMVPMatrix();      // Recalculate Model-View-Projection Matrix.
}

void Camera::RecalcProjMatrix(){
    ProjMatrix = GLM::CreatePerspectiveMatrix(FoV, 4.0f / 3.0f, nearPlane, farPlane);
}

void Camera::RecalcViewMatrix()
{
    ViewMatrix = GLM::CreateLookAtMatrix(Position, LookAt, Up);
}

void Camera::RecalcMVPMatrix()
{
    MVP = ProjMatrix * ViewMatrix * ModelMatrix;
}

void Camera::SetWireFrameMode(bool ping)
{

    if(ping){
		OpenGL::DisplayAs_WireFrame();
    }
    else{
		OpenGL::DisplayAs_Fill();
    }

}

glm::vec3 Camera::GetPosition()
{
    return Position;
}

glm::vec3 Camera::GetUpVector()
{
    return Up;
}

void Camera::SetViewMatrix(glm::mat4 newView)
{
    ViewMatrix = newView;
}

void Camera::SetPosition(glm::vec3 newPosition)
{
    Position = newPosition;
}