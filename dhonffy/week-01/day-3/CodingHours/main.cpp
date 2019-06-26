#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    int dailyHours = 6;
    int weaklyDays = 5;
    int weeks =17;

    int codingHours = dailyHours * weaklyDays * weeks;

    std::cout << "Coding hours are: " << codingHours << std::endl;

    int averageWeekly = 52;
    int allHours = averageWeekly * weeks;

    float percentage = (float) codingHours * 100 / allHours;

    std::cout << "The percentage is: " << percentage << "%" << std::endl;

    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    return 0;
}