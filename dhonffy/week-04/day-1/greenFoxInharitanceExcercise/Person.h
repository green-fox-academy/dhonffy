#ifndef GREENFOXINHARITANCEEXCERCISE_PERSON_H
#define GREENFOXINHARITANCEEXCERCISE_PERSON_H

#include <string>
//    Person
//    Create a Person class with the following members:
//    name: the name of the person
//    age: the age of the person (whole number)
//    gender: the gender of the person (male / female)
//    And the following member functions:
//    introduce(): prints out "Hi, I'm name, a age year old gender."
//    getGoal(): prints out "My goal is: Live for the moment!"
//    And the following constructors:
//    Person(name, age, gender)
//    Person(): sets name to Jane Doe, age to 30, gender to female

enum Gender
{
    MALE,
    FEMALE
};

class Person
{
public:

    Person(const std::string &name, int age, Gender gender);
    Person();
    void introduce();
    void getGoal();
    Gender getGender();

protected:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GREENFOXINHARITANCEEXCERCISE_PERSON_H
