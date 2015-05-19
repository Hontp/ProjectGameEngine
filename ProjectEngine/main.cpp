#include "GraphicsCore.h"
#include"SJWindow.h"

#include "ShaderReader.h"
#include "GameAssetFactory.h"
#include <iostream>

GLuint vArrayID;
GLuint vBuffer;

void main()
{
	SJWindow window;
	
	// create window
	window.CreateMainWindow(window.SetVideoMode(800, 600, 32), "OpenGL Window", 
		window.SetStyle("Default") , window.SetContextSettings());

	// Interfaced OpenGL initialisation checking.
	if (!GraphicsCore::Init(GraphicsCore::API::OPENGL))
		return;

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
	//OpenGL::VBO_Bind(vBufferID);
	//OpenGL::VBO_Fill(vBufferID, triangle, sizeof(triangle), 0);

	bool running = true;

	std::ofstream ofile("OUTPUT.txt");

	///////////////////////////   SHADER READER TEST HERE   /////////////////////////////////

	std::string container;

	container = ShaderReader::ReadShaderFile("shaders/dummyShaderFile.txt");

	ofile << container;

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   ASSET FACTORY TEST HERE   /////////////////////////////////

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

	while (running)
	{
		sf::Event event;
		while (window.GetEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;
			}		
		}

		OpenGL::clearBuffers();

		// Interfaced draw functions.
		OpenGL::enableVertexAttributes(OpenGL::VERT_ATTRIBUTE::POSITION);
		OpenGL::BindBuffer(OpenGL::VERT_ATTRIBUTE::POSITION, vBufferID);

		OpenGL::DrawAsTriangles(sizeof(triangle));

		OpenGL::disableVertexAttributes(true);

		window.Display();
	}
	
}