#include <iostream>
#include <vector>
#include <string>

void search(std::vector<std::string>, std::string);

int main()
{
//    Shopping list
//    We are going to represent a shopping list in a list containing strings.
//    Create a list with the following items.
//    Eggs, milk, fish, apples, bread and chicken
//    Create an application which solves the following problems.
//    Do we have milk on the list?
//    Do we have bananas on the list?
    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};
    search(shoppingList, "milk");
    search(shoppingList, "bananas");
    return 0;
}

void search(std::vector<std::string> shoppingList, std::string searched)
{
    bool valid =0;
    for (int i = 0; i < shoppingList.size(); ++i) {
        if (shoppingList[i] == searched) {
            valid = 1;
        }
    }
    if (valid == 1){
        std::cout << "Yes, it contains " << searched << std::endl;
    } else {
        std::cout << "No, it does not contain " << searched << std::endl;
    }
}