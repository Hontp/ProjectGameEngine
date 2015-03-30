#include<SFML/Graphics.hpp>
#include<glew.h>
#include<SFML/OpenGL.hpp>



void main()
{
	// create window
	sf::Window window(sf::VideoMode(800, 600, 32), "OpenGL Window", sf::Style::Default, sf::ContextSettings(32));
	//window.setVerticalSyncEnabled(true);
	
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

	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
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

		window.display();
	}
	
}