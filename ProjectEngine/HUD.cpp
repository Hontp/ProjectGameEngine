#include "HUD.h"


HUD::HUD(SJWindow* _window)
{
	window = _window;
}

HUD::~HUD()
{
	window = nullptr;
}

void HUD::Add(std::string keyIndex, HUD_Element* element)
{
	Elements.insert(std::pair<std::string, HUD_Element*>(keyIndex, element));
	elementReferences.push_back(keyIndex);
}

void HUD::AddSupportedFont(std::string keyIndex, std::string fontFile)
{
	Fonts.insert(std::pair<std::string, std::string>(keyIndex, fontFile));
}

void HUD::Remove(std::string keyIndex)
{
	Elements.erase(keyIndex);
}

void HUD::RemoveSupportedFont(std::string keyIndex)
{
	Fonts.erase(keyIndex);
}

HUD_Element* HUD::Get(std::string keyIndex)
{
	return Elements[keyIndex];
}

std::string HUD::GetSupportedFont(std::string keyIndex)
{
	return Fonts[keyIndex];
}

void HUD::Draw()
{
	for (unsigned int i = 0; i < Elements.size(); i++){
		window->Draw(Elements[elementReferences[i]]->GetText().Get());
	}
}