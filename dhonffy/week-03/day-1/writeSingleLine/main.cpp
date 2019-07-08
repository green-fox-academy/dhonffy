#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        myFile.open ("../my-file.txt");
        std::string name = "Daniel Honffy";
        myFile << name;
        myFile.close();
    } catch (std::ofstream::failure &exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}