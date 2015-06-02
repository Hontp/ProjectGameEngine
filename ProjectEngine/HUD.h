#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "HUD_Element.h"
#include "SJWindow.h"

class HUD
{
	public:
		HUD(SJWindow* _window);
		~HUD();

		void Add(std::string keyIndex, HUD_Element* element);
		void AddSupportedFont(std::string keyIndex, std::string fontFile);

		void Remove(std::string keyIndex);
		void RemoveSupportedFont(std::string keyIndex);

		HUD_Element* Get(std::string keyIndex);
		std::string GetSupportedFont(std::string keyIndex);

		void Draw();

	private:

		SJWindow* window;
		std::map<std::string, HUD_Element*> Elements;
		std::vector<std::string> elementReferences;

		std::map<std::string, std::string> Fonts;
};

