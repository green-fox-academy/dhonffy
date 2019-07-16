#ifndef GREENFOXINHARITANCEEXCERCISE_MENTOR_H
#define GREENFOXINHARITANCEEXCERCISE_MENTOR_H

#include <string>
#include "Person.h"

//Mentor
//Create a Mentor class that has the same members and functions as the Person class, and has the following additional
//members:
//level: the level of the mentor (junior / intermediate / senior)
//functions:
//getGoal(): prints out "My goal is: Educate brilliant junior software developers."
//introduce(): "Hi, I'm name, a age year old gender level mentor."
//The Mentor class has the following constructors:
//Mentor(name, age, gender, level)
//Mentor(): sets name to Jane Doe, age to 30, gender to female, level to intermediate

enum Level
{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person
{
public:
    Mentor(const std::string &name, int age, Gender gender, Level level);
    Mentor();

    void getGoal() override;
    void introduce() override;
private:
    Level _level;
};


#endif //GREENFOXINHARITANCEEXCERCISE_MENTOR_H
