#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory
    std::vector<std::string> linesRead;
    std::ifstream file("../my-file.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    return 0;
}