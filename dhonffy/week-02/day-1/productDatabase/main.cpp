#include <iostream>
#include <map>
#include <string>

int searchPrice(std::map<std::string, int>, std::string);
//std::string mostExpensive((std::map<std::string, int>);
int sum(std::map<std::string, int>);
float average(std::map<std::string, int>);
int searchCheapProducts(std::map<std::string, int>, int);
void searchExactPrice(std::map<std::string, int>, int);

int main()
{
//    We are going to represent our products in a map where the keys are strings
//    representing the product's name and the values are numbers representing the
//    product's price.
//    Create a map with the following key-value pairs.
//    Product name (key) 	Price (value)
//    Eggs              	200
//    Milk 	                200
//    Fish 	                400
//    Apples 	            150
//    Bread 	            50
//    Chicken 	            550
    std::map<std::string, int> productDatabase = {
            {"Eggs",    200},
            {"Milk",    200},
            {"Fish",    400},
            {"Apples",  150},
            {"Bread",   50},
            {"Chicken", 550}
    };
//    Create an application which solves the following problems.
//    How much is the fish?
    std::cout << "The fish costs: " << searchPrice(productDatabase, "Fish") << std::endl;
//    What is the most expensive product?
//    std::cout << mostExpensive(productDatabase) << "is the most expensive product." << std::endl;
//    What is the average price?
    std::cout << "The average price is: " << average(productDatabase) << std::endl;
//    How many products' price is below 300?
    std::cout << "There are " << searchCheapProducts(productDatabase, 300) << " products." << std::endl;
//    Is there anything we can buy for exactly 125?
    searchExactPrice(productDatabase, 125);
//    What is the cheapest product?

    return 0;
}

int searchPrice(std::map<std::string, int> productDatabase, std::string item)
{
    return productDatabase["Fish"];
}

//std::string mostExpensive(std::map<std::string, int> productDatabase)
//{
//    pair(std::string, int = 0) mostExpensive;
//    for (auto it = 0, it != productDatabase.end(), ++it) {
//        if (productDatabase[it] >= mostExpensive) {
//
//        }
//    }
//}

int sum(std::map<std::string, int> productDatabase)
{
    int sum = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end() ; ++it) {
        sum += it->second;
    }
    return sum;
}

float average(std::map<std::string, int> productDatabase)
{
    return static_cast<float> (sum(productDatabase)) / productDatabase.size();
}

int searchCheapProducts(std::map<std::string, int> productDatabase, int cheapPrice)
{
    int amount = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end() ; ++it) {
        if (it->second < cheapPrice) {
            amount++;
        }
    }
    return amount;

}

void searchExactPrice(std::map<std::string, int> productDatabase, int price)
{
    bool valid = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end() ; ++it) {
        if (it->second == price) {
            valid = 1;
        }
    }
    if (valid == 1) {
        std::cout << "There is." << std::endl;
    } else {
        std::cout << "There isn't." << std::endl;
    }
}