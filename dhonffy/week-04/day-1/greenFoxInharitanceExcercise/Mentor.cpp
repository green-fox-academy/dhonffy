#include <string>
#include <iostream>
#include "Mentor.h"

Mentor::Mentor(const std::string &name, int age, Gender gender, Level level) : Person(name, age, gender), _level(level)
{}

Mentor::Mentor()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _level = Level::INTERMEDIATE;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << _name << " a " << _age << " old " << Mentor::getGender() << Mentor::_level << " mentor."
              << std::endl;
}
