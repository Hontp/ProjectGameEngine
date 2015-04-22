#include"gl_core_4_3.hpp"
#include"SJWindow.h"



// instead of using glew an external libary to access OpenGL functions
// GL Load Generator was used to generate an extension class
// that is added directly into the project eliminating the need
// for an external (dlls), furthur more the extension class
// enforces OpenGL 4.3 standards so deprecated functions can no longer
// be accessed.


void main()
{
	SJWindow window;
	
	// create window
	window.CreateMainWindow(window.SetVideoMode(800, 600, 32), "OpenGL Window", 
		window.SetStyle("Default") , window.SetContextSettings());
	
	// this is the equivalent to glewInit()
	gl::exts::LoadTest loaded = gl::sys::LoadFunctions();
	if (!loaded)
		return;

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