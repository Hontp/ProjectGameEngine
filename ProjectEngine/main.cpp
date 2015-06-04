#include "OpenGL.h"
#include "SJWindow.h"
#include "TerrainFactory.h"
#include "Game.h"
#include "InputManager.h"

#include "Shader.h"
#include "ShaderProgram.h"
#include "ShaderReader.h"
#include "GameAssetFactory.h"
#include "CameraController.h"
#include "Timing.h"
#include <iostream>

GLuint vArrayID;
GLuint vBuffer;

void main()
{
	SJWindow window;

	// Interfaced OpenGL initialisation checking.
	if (!_OPENGL::getInstance()->Init())
		return;

	InputManager manager = InputManager();
	Timing clock;

	//Game *game = new Game();

	//game->Initialize();

	manager.InitKeys();

	// create window
	window.CreateMainWindow(window.SetVideoMode(800, 600, 32), "OpenGL Window", 
		window.SetStyle("Default") , window.SetContextSettings());

	///////////////////////////   GL_MODEL LOADING TEST HERE   /////////////////////////////////

	/////---- test triangle
	float triangle[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	float triangle_GREEN[] =
	{
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
	///----

	GL_Model TRI;
	TRI.InitData(triangle, sizeof(triangle), triangle_GREEN, sizeof(triangle_GREEN), nullptr, 0);

	///////////////////////////////////////////////////////////////////////////////////////

	bool running = true;

	///////////////////////////   SHADER LOADING TEST HERE   /////////////////////////////////

	JVShader joshTest;
	joshTest.LoadFiles("Shaders/vertex.shader", "Shaders/fragment.shader");

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   CAMERA TEST HERE   /////////////////////////////////

	Camera* camera = new Camera();
	camera->Init(glm::vec3(0, 3, 1), glm::vec3(0, 0, 0), 45.0f, 0.1f, 1500.0f);

	CameraController controller(&window, &manager, camera, 1.0f, &clock);

	camera->BindToShader(joshTest);

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   ASSET FACTORY TEST HERE   /////////////////////////////////

	std::ofstream ofile("OUTPUT.txt");

	Player* p = (Player*)GameAssetFactory::CreateNew(OBJ_ID::PLAYER, glm::vec3(0,0,0));

	ofile << p->Describe();

	NPC* n = (NPC*)GameAssetFactory::CreateNew(OBJ_ID::NPC, glm::vec3(0, 0, 0));

	ofile << n->Describe();

	StaticObject* o = (StaticObject*)GameAssetFactory::CreateNew(OBJ_ID::STATIC, glm::vec3(0, 0, 0));

	ofile << o->Describe();

	///////////////////////////////////////////////////////////////////////////////////////

	ofile << "\n\n";

	GLenum err;
	while ((err = gl::GetError()) != gl::NO_ERROR_) {
		ofile << err;
	}

	ofile.close();

	///////////////////////////   HUD DRAWING TEST HERE   /////////////////////////////////

	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf")){
		std::cout << "Error: could not find file: '" << "Fonts/arial.ttf" << "'." << std::endl;
	}
	sf::Text text("GameName", font, 50);
	text.setColor(sf::Color(255, 0, 0, 255));
	text.setPosition(sf::Vector2f(0, 0));

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   TERRAIN GENERATION TEST HERE   //////////////////////////

	TerrainFactory* tFactory = new TerrainFactory();
	Terrain* terrain;

	tFactory->SetScaleFactor(1.0f, 0.1f, 1.0f);
	tFactory->Init("HeightMap.raw", 128, "");

	GameAssetFactory::Init(tFactory);
	terrain = (Terrain*)GameAssetFactory::CreateNew(OBJ_ID::TERRAIN, glm::vec3(3, 0, 3));

	///////////////////////////////////////////////////////////////////////////////////////

	gl::Enable(gl::DEPTH_TEST);
	gl::DepthFunc(gl::LESS);

	while (running)
	{

		IEvent event;
		while (window.GetEvent(event))
		{
			switch (event.type)
			{

			case IEvent::Closed:
				running = false;
				break;

			case IEvent::KeyPressed:				
				if (manager.isKeyPressed("W") == true){}
					//std::cout << "W is Pressed" << "\n";

				if (manager.isKeyPressed("A") == true){}
				//std::cout << "A is Pressed" << "\n";

				if (manager.isKeyPressed("S") == true){}
				//std::cout << "S is Pressed" << "\n";

				if (manager.isKeyPressed("D") == true){}
				//std::cout << "D is Pressed" << "\n";

				if (manager.isKeyPressed("X") == true)
				{
					exit(0);
				}

				break;

			default:
				break;
			};
		}

		controller.Update();

		_OPENGL::getInstance()->ClearBuffers();
		window.GetWindow()->clear(sf::Color::Black);

		joshTest.Activate();

		_OPENGL::getInstance()->BindMatrixToShader(camera->MatrixID(), camera->MVP_Matrix());

		terrain->Render();
		TRI.Render();

		joshTest.Deactivate();

		//window.PushState();
		//window.Draw(text);
		//window.PopState();


		window.Display();
		
	}
	
	terrain->Destroy();
}