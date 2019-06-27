#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int currSecSpent = currentHours * 3600 + currentMinutes * 60 + currentSeconds;
    int allSecs = 24*3600;
    int remainingSecs = allSecs - currSecSpent;
    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables
    std::cout << remainingSecs << " s is remaining from the day." << std::endl;

    return 0;
}