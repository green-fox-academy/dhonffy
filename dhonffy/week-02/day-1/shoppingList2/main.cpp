#include <iostream>
#include <map>
#include <string>

float totalPrice(std::map<std::string, float>, std::map<std::string, int>);
int compareAmount(std::map<std::string, int>, std::map<std::string, int>, std::string);

int main()
{
//    Represent the following products with their prices
//    Product 	        Amount
//    Milk 	            1.07
//    Rice 	            1.59
//    Eggs 	            3.14
//    Cheese 	        12.60
//    Chicken Breasts 	9.40
//    Apples 	        2.31
//    Tomato 	        2.58
//    Potato 	        1.75
//    Onion 	        1.10
//
//    Represent Bob's shopping list
//    Product 	        Amount
//    Milk 	            3
//    Rice 	            2
//    Eggs 	            2
//    Cheese 	        1
//    Chicken Breasts 	4
//    Apples 	        1
//    Tomato 	        2
//    Potato 	        1
//
//    Represent Alice's shopping list
//    Product 	        Amount
//    Rice 	            1
//    Eggs 	            5
//    Chicken Breasts 	2
//    Apples 	        1
//    Tomato 	        10
//
    std::map<std::string, float> prices = {
            {"Milk",            1.07},
            {"Rice",            1.59},
            {"Eggs",            3.14},
            {"Cheese",          12.60},
            {"Chicken Breasts", 9.40},
            {"Apples",          2.31},
            {"Tomato",          2.58},
            {"Potato",          1.75},
            {"Onion",           1.10}
    };

    std::map<std::string, int> bobWhatToBuy = {
            {"Milk",            3},
            {"Rice",            2},
            {"Eggs",            2},
            {"Cheese",          1},
            {"Chicken Breasts", 4},
            {"Apples",          1},
            {"Tomato",          2},
            {"Potato",          1}
    };
    std::map<std::string, int> aliceWhatToBuy = {
            {"Rice",            1},
            {"Eggs",            5},
            {"Chicken Breasts", 2},
            {"Apples",          1},
            {"Tomato",          10}
    };

//    Create an application which solves the following problems.
//    How much does Bob pay?
    std::cout << "Bob pays: " << totalPrice(prices, bobWhatToBuy) << std::endl;
//    How much does Alice pay?
    std::cout << "Alice pays: " << totalPrice(prices, aliceWhatToBuy) << std::endl;
//    Who buys more Rice?
    int whoBuysMore = compareAmount(bobWhatToBuy, aliceWhatToBuy, "Rice");
    if (whoBuysMore == 1){
        std::cout << "Bob buys more rice.";
    } else if (whoBuysMore == 3){
        std::cout << "Alice buys more rice.";
    } else {
        std::cout << "They buy the same amount of rice.";
    }
//    Who buys more Potato?
    whoBuysMore = compareAmount(bobWhatToBuy, aliceWhatToBuy, "Potato");
    if (whoBuysMore == 1){
        std::cout << "Bob buys more potato.";
    } else if (whoBuysMore == 3){
        std::cout << "Alice buys more potato.";
    } else {
        std::cout << "They buy the same amount of potato.";
    }
//    Who buys more different products?
//    Who buys more products? (piece)
//

    //    How much does Bob pay?

    return 0;
}

float totalPrice(std::map<std::string, float> prices, std::map<std::string, int> items)
{
    float sum = 0;
    for (auto it = items.begin(); it != items.end() ; ++it) {
        sum = sum + prices[it->first] * it->second;
    }
    return sum;
}

int compareAmount(std::map<std::string, int>mapToCompare1, std::map<std::string, int>mapToCompare2,  std::string find)
{
    if (mapToCompare1[find] > mapToCompare2[find]){
        return 1;
    } else if (mapToCompare1[find] < mapToCompare2[find]){
        return 3;
    } else {
        return 2;
    }
    return 0;
}
