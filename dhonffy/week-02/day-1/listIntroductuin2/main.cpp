#include <iostream>
#include <string>
#include <vector>

int main()
{

//    Create a list ('List A') which contains the following values
//    Apple, Avocado, Blueberries, Durian, Lychee
    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

//    Create a new list ('List B') with the values of List A
    std::vector<std::string> listB = listA;

//    Print out whether List A contains Durian or not
    int contains = 0;
    for (int i = 0; i < listA.size(); ++i) {
        if ((listA[i]) == "Durian") {
            contains++;
        }
    }
    if (contains >= 1) {
        std::cout << "It contains Durian." << std::endl;
    } else {
        std::cout << "It does not contain Durian." << std::endl;
    }
//    Remove Durian from List B
    listB.erase(listB.begin() + 3);
//    Add Kiwifruit to List A after the 4th element
    listA.insert(listA.begin() + 3, "Kiwifruit");

//    Compare the size of List A and List B
    if (listA.size() == listB.size()) {
        std::cout << "The two lists have the same size." << std::endl;
    } else {
        std::cout << "The two lists have different sizes." << std::endl;
    }
//    Get the index of Avocado from List A
    for (int i = 0; i < listA.size(); ++i) {
        if ((listA[i]) == "Avocado") {
            std::cout << "Element number of avocado: " << (i + 1) << std::endl;
        }
    }

//    Get the index of Durian from List B
    for (int i = 0; i < listB.size(); ++i) {
        if ((listB[i]) == "Durian") {
            std::cout << "Element number of furian: " << (i + 1) << std::endl;
        }
    }

//    Add Passion Fruit and Pomelo to List B in a single statement
    listB.insert(listB.end(), {"Pomelo", "Paasion fruit"});
//    Print out the 3rd element from List A
    std::cout << listA[2] << std::endl;

    return 0;
}