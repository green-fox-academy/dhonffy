#ifndef GREENFOXINHARITANCEEXCERCISE_STUDENT_H
#define GREENFOXINHARITANCEEXCERCISE_STUDENT_H

#include <string>
#include "Person.h"

// Student
//Create a Student class that has the same members and functions as the Person class, and has the following additional
//members:
//previousOrganization: the name of the student’s previous company / school
//skippedDays: the number of days skipped from the course
//functions:
//getGoal(): prints out "My goal is: Be a junior software developer."
//introduce(): "Hi, I'm name, a age year old gender from previousOrganization who skipped skippedDays days from
//the course already."
//skipDays(numberOfDays): increases skippedDays by numberOfDays
//The Student class has the following constructors:
//Student(name, age, gender, previousOrganization): beside the given parameters, it sets skippedDays to 0
//Student(): sets name to Jane Doe, age to 30, gender to female, previousOrganization to The School of Life,
//skippedDays to 0


class Student : public Person
{
public:
    Student(const std::string &name, int age, Gender gender, const std::string &previousOrganization,
            int numberOfSkippedDays);
    Student();

    void getGoal();
    void introduce();
    int skipDays(int numberOfSkippedDays);
private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //GREENFOXINHARITANCEEXCERCISE_STUDENT_H
