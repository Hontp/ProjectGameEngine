#include "Terrain.h"

void Terrain::Init(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBuffSize, GLfloat UVdata[], GLint uvBuffSize, const std::string &fileName)
{
	model.InitData(verts, vertBuffSize, colors, colorBuffSize, UVdata, uvBuffSize);
}

void Terrain::Render()
{
	model.Render();
}

void Terrain::Destroy()
{
	model.Destroy();
}

GL_Model* Terrain::AccessModel()
{
	return &model;
}

SFML_Texture* Terrain::AccessTex()
{
	return &texture;
}