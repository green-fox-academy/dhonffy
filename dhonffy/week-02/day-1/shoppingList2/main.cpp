#include <iostream>
#include <map>
#include <string>

float totalPrice(std::map<std::string, float>, std::map<std::string, int>);

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
//    Who buys more Potato?
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

