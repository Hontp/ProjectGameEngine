#pragma once

#include <map>
#include <string>

#include "IAsset.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	template <class T>
	T *load(const std::string &filename)
	{
		rIt it = m_assets.find(filename);

		if (it != m_resources.end())
		{
			return static_cast<T*>(it->second);
		}
	}

	const std::string &getContentDirectory();

	void setContentDirectory(const std::string &directory);

private:
	typedef std::map<std::string, IAsset*> assets;
	typedef assets::iterator aIt;

	assets m_assets;
	std::string contentDir;


};

