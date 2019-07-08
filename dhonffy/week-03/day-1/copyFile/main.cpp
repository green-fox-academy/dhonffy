#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other
// file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy(std::string, std::string);

int main()
{
    bool success;
    success = copy("../source.txt", "../destination.txt");
    std:: cout << success;
    return 0;
}

bool copy(std::string source, std::string destination)
{
    std::ifstream sourceFile;
    std::ofstream destinationFile;
    sourceFile.open(source);
    std::string line;
    bool success;
    try {
        if (sourceFile.is_open()) {
            destinationFile.open(destination);
            if (sourceFile.is_open()) {
                while (std::getline(sourceFile, line)){
                    destinationFile << line << std::endl;
                }
                success = 1;
                destinationFile.close();
            }
            sourceFile.close();
        }
    } catch (std::ofstream::failure &exception) {
        std::cout << exception.what() << std::endl;
        success = 0;
    }
    return success;
}
