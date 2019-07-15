#include <iostream>
#include "Person.h"

Person::Person(const std::string &name, int age, Gender gender) : _name(name), _age(age), _gender(Gender::female)
{}

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::female;
}

Gender Person::getGender(){
    return _gender;
}

void Person::introduce(){
    std::cout << "Hi, I'm " << _name <<" a " << _age << " old " /*<< getGender() */<< std::endl;
}

void Person::getGoal(){
    std::cout << "My goal is: Live for the moment!" << std::endl;
}
