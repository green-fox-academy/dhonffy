#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int countLines(std::string);

int main()
{
    std::string address= "../my-file.txt";
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    countLines(address);
    return 0;
}

int countLines(std::string count)
{
//    std::vector <std::string>linesRead;
    std::ifstream file(count);
    int numberOfLines = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            numberOfLines++;
        }
        file.close();
    }
    std::cout << numberOfLines;
}