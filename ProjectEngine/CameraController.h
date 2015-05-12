#pragma once

// Standard Libraries.
#include <iostream>

// Local headers. (Must be declared before glfw to avoid compilation error).
#include "Camera.h"

// 3D Graphics Libraries.
#include <glm.hpp>
//#include <GLFW/glfw3.h>
#include <SFML\Graphics.hpp>
#include "SJWindow.h"
#include <gtc/matrix_transform.hpp>

// External handle for the currently opened window.
//extern GLFWwindow* window;
extern SJWindow _window;

/** This container variable keeps track of whether or not a key is currently pressed.

    This struct is used to track keys that have toggle behaviour, and not continuous input tracking.
*/
struct KeyState{
    bool F;     // Press state of 'F' key.
    bool C;     // Press state of 'C' key.
    bool M;     // Press state of 'M' key.
    bool K;     // Press state of 'K' key.

    KeyState(){ F = C = M = K = false;}     // Constructor.
};

/** @class: CameraController.

    Description: This class expands on the Camera class to provide users with certain controls for the camera's direction and rotation in real-time.

    Current controls:   'W' - move forward.
                        'A' - move left.
                        'S' - move backward.
                        'D' - move right.

                        'F' - toggle fly mode.
                        'C' - toggle mouse rotation.
                        'K' - toggle wireframe render mode.
                        'SPACE' - move up (with fly mode enabled).
                        'LEFT SHIFT' - move down (with fly mode enabled).
                        'MOUSE' - rotate the camera. Vertical rotation limited to simulate physical limits of a human head.
*/
class CameraController{

    public:
        CameraController(Camera* _camera, float _speed) { camera = _camera; speed = _speed; mouseSpeed = 0.005f; FlyMode = false; walkingPos.y = 0.0f; };  // Constructor.
        ~CameraController(void) {};     // Destructor.

        void Update();      // Update the camera. Should be called each frame.

        glm::vec3 WalkingPos(); // Get the co-ordinates of the camera when it is not flying.

        Camera* GetCamera();

    private:

        Camera* camera;

        float speed, mouseSpeed;    // Used for controlling the movement and rotation speeds of the camera.

        float horizontalAngle, verticalAngle;       // Angles used to calculate camera's rotation matrix.

        double mouseX, mouseY;      // Mouse cursor positions (treat screen as a 2D plane).

        bool FlyMode;               // Toggle whether or not the camera is able to fly.
        bool MouseClamp;            // Toggle whether of not the mouse is clamped to the camera's rotation.
        bool MenuRequest;           // If TRUE, send a request to display a textured polygon with the game's help text on it.
        bool WireframeRequest;      // If TRUE, send a request to display all models as wireframes.

        // Used for smoothing the camera's movement and rotation according to the framerate.
        double currentTime;
        float deltaTime;

        // Used for toggle controls.
        KeyState oldToggles;

        glm::vec3 walkingPos;       // Set the CameraController object's height when it is not in fly mode.
};