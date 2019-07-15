#ifndef GREENFOXINHARITANCEEXCERCISE_SPONSOR_H
#define GREENFOXINHARITANCEEXCERCISE_SPONSOR_H
#include <string>
#include "Person.h"
//Sponsor
//Create a Sponsor class that has the same members and functions as the Person class, and has the following additional
//members:
//company: name of the company
//hiredStudents: number of students hired
//functions:
//introduce(): "Hi, I'm name, a age year old gender who represents company and hired hiredStudents students so far."
//hire(): increase hiredStudents by 1
//getGoal(): prints out "My goal is: Hire brilliant junior software developers."
//The Sponsor class has the following constructors:
//Sponsor(name, age, gender, company): beside the given parameters, it sets hiredStudents to 0
//Sponsor(): sets name to Jane Doe, age to 30, gender to female, company to Google and hiredStudents to 0

class Sponsor : public Person
{
public:
    Sponsor(const std::string &name, int age, Gender gender, const std::string &company);

    Sponsor();

    void introduce();
    void hire(int&);
    void getGoal();
private:
    std::string _company;
    int _hiredStudents;
};


#endif //GREENFOXINHARITANCEEXCERCISE_SPONSOR_H
