#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish
// to modify
// The word parameter should also be a string that will be written to the file as
// individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void writeStringToFile(std::string, std::string, int);

int main() {
    writeStringToFile("../myFile.txt", "test text", 55);
    return 0;
}

void writeStringToFile(std::string file, std::string text, int amount){
    std::ofstream repeater;
    try {
        repeater.open(file);
        for (int i = 0; i < amount; ++i) {
            repeater << text << std::endl;
        }
        repeater.close();
    } catch (std::ofstream::failure& e) {
        std::cout << e.what() << std::endl;
    }

}