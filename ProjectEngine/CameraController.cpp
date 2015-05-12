#include "CameraController.h"

/** @brief: Update function for all inputs that affect the CameraController object.

    Description:    User input is read by this function every frame. 
                    The camera's various matrices are then recalculated to reflect any changes that the user applies to the camera's position or rotation.
                    
    @pre: CameraController object should be initialised.

    @post: CameraController behaviour and display is now updated based on any key input detection.
*/
void CameraController::Update(){

    //static double lastTime = glfwGetTime();

    KeyState newToggles;    // Create a new input status struct.

    // If any toggle keys are active, update the input status struct.
    /*if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS){
        newToggles.F = true;
    }

    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS){
        newToggles.C = true;
    }

    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS){
        newToggles.K = true;
    }

    if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS){
        newToggles.M = true;
    }*/

    // Find the time since the last frame.
    /*currentTime = glfwGetTime();
    deltaTime = float(currentTime - lastTime);*/

    // Toggle whether or not the mouse is clamped to the program or if it can move around.
    if(newToggles.C != oldToggles.C){

        if(newToggles.C && !oldToggles.C){
            if(!MouseClamp)
                MouseClamp = true;
            else
                MouseClamp = false;
        }
    }

	/*
    if(MouseClamp){

        // Get current mouse position.
        glfwGetCursorPos(window, &mouseX, &mouseY);

        // Clamp current mouse position to centre of window.
        glfwSetCursorPos(window, 1024/2, 768/2);
    }
    else{
        mouseX = float(1024 / 2);
        mouseY = float(768 / 2);
    }*/

    // Adjust the container values for rotation according to the mouse movement.
    horizontalAngle += mouseSpeed * float(1024/2 - mouseX);
    verticalAngle += mouseSpeed * float(768/2 - mouseY);

    // Lock vertical looking angle to a certain range. Prevents player disorientation by ensuring intuitive head-movement behaviour.
    if(verticalAngle > 1.2f)
        verticalAngle = 1.2f;
    if(verticalAngle < -1.2f)
        verticalAngle = -1.2f;

    // 'direction' and 'right' are rotation matrices.
    glm::vec3 direction(    cos(verticalAngle) * sin(horizontalAngle),
                            sin(verticalAngle),
                            cos(verticalAngle) * cos(horizontalAngle)   );

    glm::vec3 right(        sin(horizontalAngle - 3.14f / 2.0f),
                            0,
                            cos(horizontalAngle - 3.14f / 2.0f)         );

    // Update the up vector by crossing the direction and right vectors.
    camera->GetUpVector() = GLM::CrossVectors(right, direction);

    float tempY = walkingPos.y;        // Use this variable to stop the player from flying when they move and look up or down.

    // Move forwards with 'W' key.
    /*if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        tempY = camera->GetPosition().y;
        //camera->GetPosition() += direction * deltaTime * speed;
        camera->MoveTo(camera->GetPosition() + direction * deltaTime * speed);
        walkingPos.x = camera->GetPosition().x;
        walkingPos.z = camera->GetPosition().z;
    }

    // Move backwards with 'S' key.
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        tempY = camera->GetPosition().y;
        //camera->GetPosition() -= direction * deltaTime * speed;
        camera->MoveTo(camera->GetPosition() - direction * deltaTime * speed);
        walkingPos.x = camera->GetPosition().x;
        walkingPos.z = camera->GetPosition().z;
    }

    // Move right with 'D' key.
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        tempY = camera->GetPosition().y;
        //camera->GetPosition() += right * deltaTime * speed;
        camera->MoveTo(camera->GetPosition() + right * deltaTime * speed); 
        walkingPos.x = camera->GetPosition().x;
        walkingPos.z = camera->GetPosition().z;
    }

    // Move left with 'A' key.
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        tempY = camera->GetPosition().y;
        //camera->GetPosition() -= right * deltaTime * speed;
        camera->MoveTo(camera->GetPosition() - right * deltaTime * speed);
        walkingPos.x = camera->GetPosition().x;
        walkingPos.z = camera->GetPosition().z;
    }*/

    // Toggle whether or not the camera can fly around or not.
    if(newToggles.F != oldToggles.F){

        if(newToggles.F && !oldToggles.F){
            if(!FlyMode)
                FlyMode = true;
            else
                FlyMode = false;
        }
    }

    /*if(FlyMode){
        // Move down with 'Left Shift' key.
        if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
            //camera->GetPosition().y - 0.5f * deltaTime * speed;
            camera->MoveTo(glm::vec3(0, camera->GetPosition().y - 0.5f * deltaTime * speed, 0));
        }

        // Move down with 'Space' key.
        if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
            //camera->GetPosition().y + 0.5f * deltaTime * speed;
            camera->MoveTo(glm::vec3(0, camera->GetPosition().y + 0.5f * deltaTime * speed, 0));
        }
    }
    else
        //camera->GetPosition().y = tempY;
        camera->MoveTo(glm::vec3(camera->GetPosition().x, tempY, camera->GetPosition().z));*/

    // Toggle whether or not the models are rendered solid or in wireframes.
    if(newToggles.K != oldToggles.K){

        if(newToggles.K && !oldToggles.K){
            if(!WireframeRequest)
                WireframeRequest = true;
            else
                WireframeRequest = false;
        }
    }

    // Call the Camera class's wireframe toggle method.
    camera->SetWireFrameMode(WireframeRequest);

    // Adjust the view matrix.
    camera->SetViewMatrix(GLM::CreateLookAtMatrix(camera->GetPosition(), camera->GetPosition() + direction, camera->GetUpVector()));

    // Recalculate the Camera's ModelViewProjection matrix.
    camera->RecalcMVPMatrix();

    // Update the frame time tracking.
    //lastTime = currentTime;

    // Update input status history.
    oldToggles.F = newToggles.F;
    oldToggles.C = newToggles.C;
    oldToggles.K = newToggles.K;
    oldToggles.M = newToggles.M;
}

/** @brief: Walking mode position of the camera.
    
    @return: the vector containing the position co-ordinates of the camera when it is not in fly mode.

    @pre: CameraController object should be initialised.

    @post: NONE.
*/
glm::vec3 CameraController::WalkingPos(){
    return walkingPos;
}

Camera* CameraController::GetCamera(){
    return camera;
}