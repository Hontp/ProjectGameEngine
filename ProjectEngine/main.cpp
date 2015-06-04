#include "GraphicsCore.h"
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
#include "HUD.h"
#include <iostream>

GLuint vArrayID;
GLuint vBuffer;

void main()
{
	//std::cout << "HELLO!!!!";

	SJWindow *window = new SJWindow();
	
	InputManager manager = InputManager();
	Timing clock;

	HUD hud = HUD();

	//Game *game = new Game();

	//game->Initialize();

	manager.InitKeys();

	// create window
	window->CreateMainWindow(window->SetVideoMode(800, 600, 32), "OpenGL Window",
		window->SetStyle("Default"), window->SetContextSettings());


	// Interfaced OpenGL initialization checking.
	if (!GraphicsCore::Init(GraphicsCore::API::OPENGL))
		return;

	// initialize hud component
	hud.HUDInit(window->GetWindow());

	// set font
	hud.SetFont("UI/Fonts/DejaVuSans.ttf");

	// create a box
	hud.CreateHUDBox(*hud.GetGUI(), "UI/Background/background.png", glm::vec2(200, 200), glm::vec2(600, 0));

	// create a button widget
	hud.CreateButton(*hud.GetGUI(), "UI/widgets/BabyBlue.conf", glm::vec2(100, 100), glm::vec2(0, 0), "Test Button");

	// create an text box
	hud.CreateInputBox(*hud.GetGUI(), "TextBox", "UI/widgets/Black.conf", glm::vec2(150, 50), glm::vec2(300, 0));


	GLenum ENUM = gl::VERTEX_SHADER;
	Shader vertexTest(ENUM);
	ENUM = gl::FRAGMENT_SHADER;
	Shader fragmentTest(ENUM);

	JVShader joshTest;

	ShaderProgram testShader;

	// Interfaced VAO generation and binding.
	OpenGL::VAO_Gen(vArrayID);

	/////---- test triangle
	float triangle[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	///----

	// Interfaced VBO generation and populating.
	GLuint vBufferID;
	OpenGL::VBO_Gen(vBufferID, sizeof(triangle), triangle);

	bool running = true;

	///////////////////////////   SHADER READER TEST HERE   /////////////////////////////////

	joshTest.LoadFiles("Shaders/vertex.shader", "Shaders/fragment.shader");

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   CAMERA TEST HERE   /////////////////////////////////

	Camera* camera = new Camera();
	camera->Init(glm::vec3(0, 3, 1), glm::vec3(0, 0, 0), 45.0f, 0.1f, 1500.0f);

	CameraController controller(window, &manager, camera, 1.0f, &clock);

	camera->BindToShader(joshTest, "MVP");

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   ASSET FACTORY TEST HERE   /////////////////////////////////

	std::ofstream ofile("OUTPUT.txt");

	Player* p = (Player*)GameAssetFactory::CreateNew(OBJ_ID::PLAYER);

	ofile << p->Describe();

	NPC* n = (NPC*)GameAssetFactory::CreateNew(OBJ_ID::NPC);

	ofile << n->Describe();

	StaticObject* o = (StaticObject*)GameAssetFactory::CreateNew(OBJ_ID::STATIC);

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

	TerrainFactory tFactory;
	Terrain* terrain;

	tFactory.SetScaleFactor(1.0f, 1.0f, 1.0f);
	tFactory.Init("HeightMap.raw", 128, "");

	terrain = tFactory.BuildAt(glm::vec3(3, 0, 3));

	///////////////////////////////////////////////////////////////////////////////////////

	gl::Enable(gl::DEPTH_TEST);
	gl::DepthFunc(gl::LESS);

	while (running)
	{

		IEvent event;
		while (window->GetEvent(event))
		{
			hud.HUDEvent(event);

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
					
				}

				break;

			default:
				break;
			};
		}

		controller.Update();
		OpenGL::clearBuffers();
		joshTest.Activate();

		gl::UniformMatrix4fv(camera->MatrixID(), 1, gl::FALSE_, &(camera->MVP_Matrix())[0][0]);

		terrain->Render();
		
		// Interfaced draw functions.
		OpenGL::enableVertexAttributes(OpenGL::VERT_ATTRIBUTE::POSITION);
		OpenGL::BindBuffer(OpenGL::VERT_ATTRIBUTE::POSITION, vBufferID);

		OpenGL::DrawAsTriangles(sizeof(triangle));

		OpenGL::disableVertexAttributes(true);

		// unbind array buffers	
		gl::BindBuffer(gl::ARRAY_BUFFER, 0);
		gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, 0);


		joshTest.Deactivate();

		window->PushState();
		//window.Draw(text);
		hud.Draw();
		window->PopState();


		window->Display();
		
	}
	
	terrain->Destroy();
}