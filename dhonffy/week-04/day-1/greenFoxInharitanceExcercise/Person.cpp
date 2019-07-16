#include <iostream>
#include "Person.h"

Person::Person(const std::string &name, int age, Gender gender) : _name(name), _age(age), _gender(Gender::FEMALE)
{}

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}

Gender Person::getGender()
{
    return _gender;
}

void Person::introduce()
{
    std::string person;
    switch (Person::getGender()) {
        case 0:
            person = "male";
            break;
        case 1:
            person = "female";
            break;
        default:
            person = "unknown";
    }
    std::cout << "Hi, I'm " << _name <<" a " << _age << " old " << person << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}


