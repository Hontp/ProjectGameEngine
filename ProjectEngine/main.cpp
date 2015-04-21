#include<glew.h>
#include"SJWindow.h"

#include "ShaderReader.h"
#include "GameAssetFactory.h"
#include <iostream>

void main()
{
	SJWindow window;
	
	// create window
	window.CreateMainWindow(window.SetVideoMode(800, 600, 32), "OpenGL Window", 
		window.SetStyle("Default") , window.SetContextSettings());
		
	// initialize opengl
	glewInit();

	// create vertex array object
	GLuint vArrayID;
	glGenVertexArrays(1, &vArrayID);
	glBindVertexArray(vArrayID);


	/////---- test triangle
	static const GLfloat triangle[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	///----

	// create vertex buffer object
	GLuint vBuffer;
	glGenBuffers(1, &vBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vBuffer);

	// store vertices in buffer object
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	bool running = true;

	std::ofstream ofile("OUTPUT.txt");

	///////////////////////////   SHADER READER TEST HERE   /////////////////////////////////

	std::string container;

	container = ShaderReader::ReadShaderFile("shaders/dummyShaderFile.txt");

	ofile << container;

	///////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////   ASSET FACTORY TEST HERE   /////////////////////////////////

	Player* p = (Player*)GameAssetFactory::CreateNew(OBJ_ID::CHAR::PLAYER);

	ofile << p->Describe();

	NPC* n = (NPC*)GameAssetFactory::CreateNew(OBJ_ID::CHAR::SML_NPC);

	ofile << n->Describe();

	StaticObject* o = (StaticObject*)GameAssetFactory::CreateNew(OBJ_ID::OBJ::SML_STATIC);

	ofile << o->Describe();

	///////////////////////////////////////////////////////////////////////////////////////

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

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		// draw
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
			);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);

		window.Display();
	}
	
}