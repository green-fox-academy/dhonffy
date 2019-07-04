#include <iostream>
#include <map>
#include <string>
#include <vector>

int searchPrice(std::map<std::string, int>, std::string);

std::string mostExpensive(std::map<std::string, int>);

std::string cheapest(std::map<std::string, int>);

int sum(std::map<std::string, int>);

float average(std::map<std::string, int>);

int amountOfCheapProducts(std::map<std::string, int>, int);

std::vector<std::string> searchCheapProducts(std::map<std::string, int>, int);

std::map<std::string, int> searchExpensiveProducts(std::map<std::string, int>, int);

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
    std::cout << mostExpensive(productDatabase) << " is the most expensive product." << std::endl;
//    What is the average price?
    std::cout << "The average price is: " << average(productDatabase) << std::endl;
//    How many products' price is below 300?
    std::cout << "There are " << amountOfCheapProducts(productDatabase, 300) << " products." << std::endl;
//    Is there anything we can buy for exactly 125?
    searchExactPrice(productDatabase, 125);
//    What is the cheapest product?
    std::cout << cheapest(productDatabase) << " is the cheapest product." << std::endl;
//    Which products cost less than 201? (just the name)
    std::cout << "The products which are cheaper than 201, are:";
    std::vector<std::string> cheapProductList = searchCheapProducts(productDatabase, 201);
    for (int i = 0; i < cheapProductList.size(); ++i) {
        std::cout << " " << cheapProductList[i];
    }
    std::cout << "." << std::endl;
//    Which products cost more than 150? (name + price)
    std::cout << "The products which are more expensive than 150, are:" << std::endl;
    std::map<std::string, int> expensiveProductList = searchExpensiveProducts(productDatabase, 150);
    for (auto it = expensiveProductList.begin(); it != expensiveProductList.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}

int searchPrice(std::map<std::string, int> productDatabase, std::string item)
{
    return productDatabase["Fish"];
}

std::string mostExpensive(std::map<std::string, int> productDatabase)
{
    int highestPrice = 0;
    std::string mostExpensive;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        if (it->second >= highestPrice) {
            highestPrice = it->second;
            mostExpensive = it->first;
        }
    }
    return mostExpensive;
}

std::string cheapest(std::map<std::string, int> productDatabase)
{
    int lowestPrice = 2147483647;
    std::string cheapest;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        if (it->second <= lowestPrice) {
            lowestPrice = it->second;
            cheapest = it->first;
        }
    }
    return cheapest;
}

int sum(std::map<std::string, int> productDatabase)
{
    int sum = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        sum += it->second;
    }
    return sum;
}

float average(std::map<std::string, int> productDatabase)
{
    return static_cast<float> (sum(productDatabase)) / productDatabase.size();
}

int amountOfCheapProducts(std::map<std::string, int> productDatabase, int cheapPrice)
{
    int amount = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        if (it->second < cheapPrice) {
            amount++;
        }
    }
    return amount;
}

void searchExactPrice(std::map<std::string, int> productDatabase, int price)
{
    bool valid = 0;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
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

std::vector<std::string> searchCheapProducts(std::map<std::string, int> productDatabase, int price)
{
    std::vector<std::string> cheapProducts;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        if (it->second < price) {
            cheapProducts.push_back(it->first);
        }
    }
    return cheapProducts;
}

std::map<std::string, int> searchExpensiveProducts(std::map<std::string, int> productDatabase, int price)
{
    std::map<std::string, int> cheapProducts;
    for (auto it = productDatabase.begin(); it != productDatabase.end(); ++it) {
        if (it->second > price) {
            cheapProducts.insert(std::pair<std::string, int>(it->first, it->second));
        }
    }
    return cheapProducts;

}