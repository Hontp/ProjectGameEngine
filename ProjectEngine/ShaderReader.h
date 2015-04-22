#pragma once

#include <string>
#include <fstream>
#include <iostream>

/**	@brief:			Read in shader files.

	Description:	The file reader is where all shader files are loaded.
					All functions here should be static as multiple instances should not be loaded, because this class holds no data, it only reads in data and passes it on.
*/
class ShaderReader
{
	public:

		static std::string ReadShaderFile(std::string sourceFile);

	private:

		ShaderReader() {};
		~ShaderReader() {};
};

