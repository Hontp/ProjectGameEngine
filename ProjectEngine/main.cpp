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
#include <iostream>

GLuint vArrayID;
GLuint vBuffer;

void main()
{
	//std::cout << "HELLO!!!!";

	SJWindow window;

	// Interfaced OpenGL initialisation checking.
	if (!GraphicsCore::Init(GraphicsCore::API::OPENGL))
		return;

	GLenum ENUM = gl::VERTEX_SHADER;
	Shader vertexTest(ENUM);
	ENUM = gl::FRAGMENT_SHADER;
	Shader fragmentTest(ENUM);

	JVShader joshTest;

	ShaderProgram testShader;

	InputManager manager = InputManager();
	Timing clock;

	//Game *game = new Game();

	//game->Initialize();

	manager.InitKeys();

	// create window
	window.CreateMainWindow(window.SetVideoMode(800, 600, 32), "OpenGL Window", 
		window.SetStyle("Default") , window.SetContextSettings());

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

	CameraController controller(&window, &manager, camera, 1.0f, &clock);

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

		Events event;
		while (window.GetEvent(event))
		{
			switch (event.type)
			{

			case Events::Closed:
				running = false;
				break;

			case Events::KeyPressed:				
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

		window.Clear(sf::Color::Black);
		OpenGL::clearBuffers();

		joshTest.Activate();

		gl::UniformMatrix4fv(camera->MatrixID(), 1, gl::FALSE_, &(camera->MVP_Matrix())[0][0]);

		terrain->Render();
		
		//window.Begin();
		//window.Draw(text);		//<---------------  Uncommenting this will make the program stop rendering the triangle onscreen.
		//window.End();

		// Interfaced draw functions.
		OpenGL::enableVertexAttributes(OpenGL::VERT_ATTRIBUTE::POSITION);
		OpenGL::BindBuffer(OpenGL::VERT_ATTRIBUTE::POSITION, vBufferID);

		OpenGL::DrawAsTriangles(sizeof(triangle));

		OpenGL::disableVertexAttributes(true);

		joshTest.Deactivate();

		window.Display();
	}

	terrain->Destroy();
	
}