#version 330 core

// Input vertex and color data.
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

// Output data for fragment shader.
out vec3 fragmentColor;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

void main(){

    // Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition,1);

	fragmentColor = vertexColor;

}