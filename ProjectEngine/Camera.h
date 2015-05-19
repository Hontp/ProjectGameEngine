#pragma once

// 3D Graphics libraries.
#include "OpenGL.h"
#include "GLM.h"

///****************************************   IMPORTANT

/** @class: Camera.

    Description:    The Camera class is a basic projection class that alters the 2D co-ordinates of onscreen vertices to simulate a first-person perspective.
                    This class is a static object. See CameraController child class for Camera with implemented movement and orientation controls.
*/
class Camera{

    public:
        Camera(void) {ModelMatrix = glm::mat4(1.0f);};      // Constructor.
        ~Camera(void) {};                                   // Destructor.

        // Initialise the camera's internal parameters.
        void Init(glm::vec3 _pos, glm::vec3 _lookAt, GLfloat _fov, GLfloat _nearPlane, GLfloat _farPlane);

        // Move the camera to the specified xyz co-ordinates.
        void MoveTo(glm::vec3 _newPos);

        // Set the internal variables of the Camera class.
        void SetLookAt(glm::vec3 _newTarget);
        void SetNearPlane(GLfloat _newNear);
        void SetFarPlane(GLfloat _newFar);

        void SetWireFrameMode(bool ping);

        // Bind the camera to the currently running shader.
		void BindToShader(GLuint shaderProgramID) { matrixID = OpenGL::CreateLinkToShader(shaderProgramID, "MVP"); }

        // Access certain internal variables.
        GLuint MatrixID() const {   return matrixID;    };
        glm::mat4 MVP_Matrix()  {   return MVP;         };

        void RecalcProjMatrix();    // Recalculate projection matrix after run-time changes occur.
        void RecalcViewMatrix();    // Recalculate view matrix after run-time changes occur.
        void RecalcMVPMatrix();     // Recalculate the MVP matrix if the View OR Projection matrices are altered.

        glm::vec3 GetPosition();
        glm::vec3 GetUpVector();
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

