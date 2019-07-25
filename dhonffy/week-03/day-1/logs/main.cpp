#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> returnIP(std::string);
float returnRatio(std::string);

int main()
{
    returnIP("../log.txt");
    return 0;
}


std::vector<std::string> returnIP(std::string log)
{
    std::vector<std::string> addresses;
    std::ifstream logFile(log);
    std::string line;
    logFile.open(log);
    if(logFile.is_open()) {
        while (std::getline(logFile, line)) {
            std::istringstream ss(line);
            std::string address;
            for (int i = 0; i < 6; ++i) {
                std::getline(ss, address, ' ');
            }
            addresses.push_back(address);
        }
    }
}

float returnRatio(std::string log)
{

}