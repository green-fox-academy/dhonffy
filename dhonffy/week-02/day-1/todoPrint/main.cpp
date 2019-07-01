#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string todoText = " - Buy milk\n";
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo
    std::string toReplece(" - Buy");
    size_t pos=todoText.find(toReplece);
    todoText.replace(pos, toReplece.length(), "My todo:\n  - Buy");

    std::string toReplece2("milk\n");
    size_t pos2=todoText.find(toReplece2);
    todoText.replace(pos2, toReplece2.length(), "milk\n  - Download games \n     - Diablo");

    std::cout << todoText << std::endl;

    return 0;
}