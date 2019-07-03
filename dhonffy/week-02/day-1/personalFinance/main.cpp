#include <iostream>
#include <vector>

int totalSpending(std::vector<int>);
int greatestSpending(std::vector<int>);
int cheapestSpending(std::vector<int>);
float averageSpending(int, int);

int main()
{
//    We are going to represent our expenses in a list containing integers.
//    Create a list with the following items.
//    500, 1000, 1250, 175, 800 and 120
    std::vector<int> expenses = {500, 1000, 1250, 175, 800, 120};
//    Create an application which solves the following problems.
//    1 How much did we spend?
    int total = totalSpending(expenses);
    std::cout << "We spent: " << total << std::endl;
//    2 Which was our greatest expense?
    std::cout << "The greatest spending was: " << greatestSpending(expenses) << std::endl;
//    3 Which was our cheapest spending?
    std::cout << "The cheapest spending was: " << cheapestSpending(expenses) << std::endl;
//    4 What was the average amount of our spendings?
    std::cout << "The average of the spendings was: " << averageSpending(total, expenses.size()) << std::endl;
    return 0;
}

float averageSpending(int total, int elements)
{
    return (static_cast<float>(total) / elements);
}

int cheapestSpending(std::vector<int> expense)
{
    int cheapest = 2147483647;
    for (int i = 0; i < expense.size(); ++i) {
        if (cheapest > expense[i]) {
            cheapest = expense[i];
        }
    }
    return cheapest;
}

int greatestSpending(std::vector<int> expense)
{
    int greatest = 0;
    for (int i = 0; i < expense.size(); ++i) {
        if (greatest < expense[i]) {
            greatest = expense[i];
        }
    }
    return greatest;

}

int totalSpending(std::vector<int> expense)
{
    int sum = 0;
    for (int i = 0; i < expense.size(); ++i) {
        sum += expense[i];
    }
    return sum;
}
