#include <iostream>
#include <map>

int main()
{
    // We are going to play with maps. Feel free to use the built-in methods where
    // possible.

    // Create an empty map where the keys are integers and the values are characters
    std::map<int, char> test;
    // Print out whether the map is empty or not
    std::cout << test.size() << std::endl;
    // Add the following key-value pairs to the map | Key | Value |
    // | :-- | :---- | | 97 | a | | 98 | b | | 99 | c | | 65 | A | | 66 | B | | 67 | C |
    std::map<int, char>::iterator it = test.begin();
    test.insert(it, std::pair<int, char>(97, 'a'));
    test.insert(it, std::pair<int, char>(98, 'b'));
    test.insert(it, std::pair<int, char>(99, 'c'));
    test.insert(it, std::pair<int, char>(65, 'A'));
    test.insert(it, std::pair<int, char>(66, 'B'));
    test.insert(it, std::pair<int, char>(67, 'C'));
    // Print all the keys
    for (it = test.begin(); it != test.end(); ++it) {
        std::cout << it->first
                  << std::endl;
    }
    // Print all the values
    for (it = test.begin(); it != test.end(); ++it) {
        std::cout << it->second
                  << std::endl;
    }
    // Add value D with the key 68
    test.insert(it, std::pair<int, char>(68, 'D'));
    // Print how many key-value pairs are in the map
    std::cout << "Number of key-value pairs: " << test.size() << std::endl;
    // Print the value that is associated with key 99
    for (it = test.begin(); it != test.end(); ++it) {
        if (it->first == 99) {
            std::cout << 99 << ": " << it->second << std::endl;
        }
    }
    // Remove the key-value pair where with key 97
    test.erase(97);
    // Print whether there is an associated value with key 100 or not
    int notFound = 0;
    for (it = test.begin(); it != test.end(); ++it) {
        if (it->first == 100) {
            std::cout << it->second << std::endl;
        } else {
            notFound++;
        }
    }
    if (notFound == test.size()) {
        std::cout << "Not found." << std::endl;
    }
    // Remove all the key-value pairs
    test.size();
    for (it = test.begin(); it != test.end(); ++it) {
        test.erase(it);
    }


    return 0;
}