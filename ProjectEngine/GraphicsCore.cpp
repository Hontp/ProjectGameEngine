#include "GraphicsCore.h"

/*static unsigned short _API = NULL;
ImageLoader* GraphicsCore::imgLoader = new ImageLoader();
GLenum GraphicsCore::GL_tex_layers[] = { OpenGL::TEX_LAYERS::LAYER1, OpenGL::TEX_LAYERS::LAYER2, OpenGL::TEX_LAYERS::LAYER3 };

bool GraphicsCore::Init(unsigned short API_ID){

	_API = API_ID;
	bool ping;

	switch (_API){
		case API::OPENGL:
			ping = OpenGL::Init();
			break;
		default:
			ping = false;
			break;
	}

	return ping;
}

unsigned short GraphicsCore::GetActiveAPI(){
	return _API;
}

GLuint GraphicsCore::Create_GLTexture(){
	GLuint GL_handle;
	OpenGL::Tex_Gen(GL_handle);
	return GL_handle;
}

GLuint* GraphicsCore::Create_GLMultiTexture(unsigned short _layers){

	GLuint* GL_handles = new GLuint[_layers];

	for (unsigned short i = 0; i < _layers; i++)
		OpenGL::Tex_Gen(GL_handles[i]);

	return GL_handles;
}

void GraphicsCore::Delete_GLTexture(GLuint handle){
	OpenGL::Tex_Del(handle);
}

void GraphicsCore::Texture_SetFiltering(GLuint textureHandle, GLuint filteringType){

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:

			switch (filteringType){

				case gl::NEAREST:

					OpenGL::Tex_SetFilteringToNearest(textureHandle);
					break;

				case gl::LINEAR:

					OpenGL::Tex_SetFilteringToLinear(textureHandle);
					break;

				default:

					break;
			}

			break;

		default:

			break;
	}

}

void GraphicsCore::Texture_SetWrapping(GLuint textureHandle, GLuint wrappingType){

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:

			switch (wrappingType){

				case gl::REPEAT:

					OpenGL::Tex_SetWrapToRepeating(textureHandle);
					break;

				case gl::CLAMP_TO_EDGE:

					OpenGL::Tex_SetWrapToClamping(textureHandle);
					break;

				default:

					break;
			}

			break;

		default:

			break;
	}

}

void GraphicsCore::Texture_LoadFile(GLuint textureHandle, const char* fileName){

	imgLoader->LoadImageFile(fileName);

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:
			OpenGL::Tex_SetAsActive(textureHandle);
			OpenGL::Tex_2D(textureHandle, 0, imgLoader->GetDimension().x, imgLoader->GetDimension().y, imgLoader->GetImage().getPixelsPtr());
			break;

		default:

			break;
	}

}

void GraphicsCore::Texture_FocusOn(GLuint textureHandle){

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:

			OpenGL::Tex_SetAsActive(textureHandle);
			break;

		default:

			break;
	}

}

void GraphicsCore::Texture_GenMipMaps(GLuint textureHandle, GLuint mipMapBehaviour){
	OpenGL::Tex_GenMipMaps(textureHandle);
	OpenGL::Tex_SetMipMapBehaviour(textureHandle, mipMapBehaviour);
}

void GraphicsCore::MultiTexture_SetActiveLayer(unsigned short layer){

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:

			if (layer < OpenGL::MAX_TEX_LAYER)
				OpenGL::Tex_SetAsActive(GL_tex_layers[layer]);
			break;

		default: 

			break;
	}

}

unsigned short GraphicsCore::MultiTexture_ValidateLayerCount(unsigned short layerCount){

	switch (GraphicsCore::GetActiveAPI()){

	case GraphicsCore::API::OPENGL:

		if (layerCount > OpenGL::MAX_TEX_LAYER)
			layerCount = OpenGL::MAX_TEX_LAYER;

		return layerCount;

	default:

		return 0;

	}

}

void GraphicsCore::ClearBuffers(){

	switch (GraphicsCore::GetActiveAPI()){

		case GraphicsCore::API::OPENGL:

			OpenGL::clearBuffers();
			break;

		default:

		break;
	}

}*/