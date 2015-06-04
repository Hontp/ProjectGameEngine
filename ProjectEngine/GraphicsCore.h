#pragma once

#include "ImageLoader.h"

/**	@class: GraphicsCore

	@author: Joshua Voysey
	@date: 4th June 2015
	@version: 1.1

	Description: The GraphicsCore is the facade that graphics APIs must implement to work in the game.
*/
class GraphicsCore
{

	public:

		virtual bool Init() = 0;

		virtual void WireFrameMode(bool trueIfYes) = 0;

		virtual void ActivateTexture(unsigned int textureHandle) = 0;

		virtual unsigned int MakevertexArray() = 0;
		virtual unsigned int MakeVertexBuffer(float data[], unsigned int dataSize) = 0;
		virtual void DeleteVertexObject(unsigned int objectType, unsigned int objectHandle) = 0;

		virtual void ActivateVertexData(unsigned int bufferHandle, unsigned int attribute) = 0;
		virtual void DeactivateVertexData(unsigned int attribute) = 0;

		virtual void DrawModelVertices(unsigned int size) = 0;

		virtual void ClearBuffers() = 0;

	protected: 

		GraphicsCore(){};

		ImageLoader* imgLoader;

};