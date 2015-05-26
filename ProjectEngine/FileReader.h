#pragma once

// Standard libraries.
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

/** @class: FileReader.

    Description:    The FileReader class is dedicated to the task of reading in the data from a valid file format and outputting said data in into a variable.
                    The data is formatted as a single-dimensional array.

                    Current valid file formats:
                        > .raw
*/
class FileReader{

    public:

        // Read a file that is in the .raw format.
        static char* ReadRAWFile(std::string fileName);

    private:

        // Since all functions are static, we dont need a constructor or destructor available to users.
        FileReader(void) {};
        ~FileReader(void) {};

};

