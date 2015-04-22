#include "ShaderReader.h"


std::string ShaderReader::ReadShaderFile(std::string sourceFile){

	std::string sourceContainerString = "";						// Empty the data container.
	std::ifstream inputFile(sourceFile.c_str());	// Open a file stream from the source file.

	// Check that the sourceFile has been found before trying to read from it.
	if (!inputFile){
		std::cout << "Error: ' " << sourceFile << " ' was not found." << std::endl;
		return sourceContainerString;		// At this point, 'sourceContainer' should still be an empty string.
	}

	std::string Line = "";		// Container for each file line.

	while (!inputFile.eof()){
		getline(inputFile, Line);
		sourceContainerString += Line + "\n";
	}

	inputFile.close();

	return sourceContainerString;

}