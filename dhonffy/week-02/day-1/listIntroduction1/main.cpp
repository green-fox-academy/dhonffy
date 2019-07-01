#include <iostream>
#include <vector>
int main()
{
    //We are going to play with lists. Feel free to use the built-in methods where possible.
    //        Create an empty list which will contain names (strings)
    std::vector<std::string> names;

    //Print out the number of elements in the list
    std::cout << names.size() << std::endl;
    //Add William to the list
    names.push_back("William");
    //Print out whether the list is empty or not
    std::cout << names.size() << std::endl;
    //        Add John to the list
    names.push_back("John");

    //Add Amanda to the list
    names.push_back("Amanda");

    //Print out the number of elements in the list
    std::cout << names.size() << std::endl;

    //Print out the 3rd element
    std::cout << names.at(2) << std::endl;

    //Iterate through the list and print out each name
    for (int i = 0; i < names.size(); ++i) {
        std::cout << names[i] << " ";
        }
    std::cout << std::endl;
    //William John Amanda

    //Iterate through the list and print

    //1. William
    //2. John
    //3. Amanda

    for (int i = 0; i < names.size(); ++i) {
        std::cout << i+1 << ". " << names[i] <<std::endl;
    }


    //Remove the 2nd element
    names.erase(names.begin() +1);

    //Iterate through the list in a reversed order and print out each name
    //Amanda          William
    for (int i = names.size()-1; i >= 0; --i) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;

    //Remove all elements
        while (names.size() != 0) {
            names.erase(names.begin());
        }

    return 0;
}