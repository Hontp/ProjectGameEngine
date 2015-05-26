#include "FileReader.h"

/** @brief: Read in the data from a .raw formatted file.

    @param: fileName (std::string) - filepath used by the program to find the data file.

    Description: Input data from a .raw file into the program.

    @return: A 1-dimensional character array containing the entire contants of a .raw file.
    
    @pre: A valid .raw file must be pointed to.

    @post: There must be memory space for a character array the same size as the .raw file.
*/
char* FileReader::ReadRAWFile(std::string fileName){

    std::ifstream infile(fileName.c_str(), std::ios::binary);
    char* container = nullptr;

    if(!infile){
        std::cout << "ERROR LOADING RAW: ' " << fileName << " '."<< std::endl;
        return nullptr;
    }

    if(container)
        delete[] container;

    infile.seekg(0, std::ios::end);
    int length = infile.tellg();
    infile.seekg(0, std::ios::beg);

    container = new char [length];

    infile.read(container, length);
    infile.close();

    return container;
}