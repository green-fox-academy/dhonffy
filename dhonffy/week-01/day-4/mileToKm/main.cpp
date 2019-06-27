#include <iostream>
#define KM_MILE 1.609

int main(int argc, char* args[]) {

    // Write a program that asks for a double that is a distance in miles,
    // then it converts that value to kilometers and prints it
    double miles;

    std::cout << "Please write a distance in miles!" << std::endl;
    std::cin >> miles;
    std::cout << "The distance is " << (miles * KM_MILE) << " km";


    return 0;
}