#version 330 core

// Input data from vertex shader.
in vec3 fragmentColor;

// Output data.
out vec3 color;

void main()
{

	// Output color = red 
	//color = vec3(1,0,0);
	color = fragmentColor;

}