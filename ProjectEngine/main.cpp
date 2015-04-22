#include "gl_core_4_3.hpp"
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
		
	
	gl::exts::LoadTest loaded = gl::sys::LoadFunctions();


	// create vertex array object
	GLuint vArrayID;
	gl::GenVertexArrays(1, &vArrayID);
	gl::BindVertexArray(vArrayID);


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
	gl::GenBuffers(1, &vBuffer);
	gl::BindBuffer(gl::ARRAY_BUFFER, vBuffer);

	// store vertices in buffer object
	gl::BufferData(gl::ARRAY_BUFFER, sizeof(triangle), triangle, gl::STATIC_DRAW);

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

		gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);
	
		// draw
		gl::EnableVertexAttribArray(0);
		gl::BindBuffer(gl::ARRAY_BUFFER, vBuffer);
		gl::VertexAttribPointer(
			0,
			3,
			gl::FLOAT,
			gl::FALSE_,
			0,
			(void*)0
			);

		gl::DrawArrays(gl::TRIANGLES, 0, 3);

		gl::DisableVertexAttribArray(0);

		window.Display();
	}
	
}