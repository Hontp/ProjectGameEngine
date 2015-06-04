#pragma once

// Standard Libraries.
#include <iostream>
#include <gtc/matrix_transform.hpp>

// Local headers. (Must be declared before glfw to avoid compilation error).
#include "Camera.h"
#include "SJWindow.h"
#include "InputManager.h"
#include "Timing.h"

// 3D Graphics Libraries.
#include <SFML\Graphics.hpp>

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
		CameraController(SJWindow* _window, InputManager* _manager, Camera* _camera, float _speed, Timing* clock);
        ~CameraController(void) {};     // Destructor.

		/** @brief: Update function for all inputs that affect the CameraController object.

			Description:    User input is read by this function every frame.
			The camera's various matrices are then recalculated to reflect any changes that the user applies to the camera's position or rotation.

			@pre: CameraController object should be initialised.

			@post: CameraController behaviour and display is now updated based on any key input detection.
		*/
        void Update();

		/** @brief: Walking mode position of the camera.

			@return: the vector containing the position co-ordinates of the camera when it is not in fly mode.

			@pre: CameraController object should be initialised.

			@post: NONE.
		*/
        glm::vec3 WalkingPos(); // Get the co-ordinates of the camera when it is not flying.

		/** @brief: Access the bound camera.

			@return: A pointer to the internal camera being manipulated.

			@pre: CameraController object should be initialised.

			@post: NONE.
		*/
        Camera* GetCamera();

    private:

        Camera* camera;				// Camera that is being controlled by the CameraController.

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

		InputManager* manager;		// Local handle for the engine's input manager.
		Timing* timer;				// Timer object used for smooth movement.
		SJWindow* window;			// Local handle for the window that the Camera is drawing to.

        KeyState oldToggles;		// Used for toggle controls.

        glm::vec3 walkingPos;       // The CameraController object's position when it is not in FLY mode.
};