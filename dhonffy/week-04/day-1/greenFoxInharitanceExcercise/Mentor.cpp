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
    std::string mentor;
    switch (Mentor::getGender()) {
        case 0:
            mentor = "male";
            break;
        case 1:
            mentor = "female";
            break;
        default:
            mentor = "unknown";
    }

    std::string mentorLevel;
    switch (Mentor::getGender()) {
        case 0:
            mentorLevel = "junior";
            break;
        case 1:
            mentorLevel = "intermediate";
            break;
        case 2:
            mentorLevel = "senior";
            break;
        default:
            mentorLevel = "unknown";
    }
    std::cout << "Hi, I'm " << _name << " a " << _age << " old " << mentor << " " << mentorLevel << " mentor."
              << std::endl;
}
