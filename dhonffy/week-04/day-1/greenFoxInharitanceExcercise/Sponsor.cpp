#include "Sponsor.h"
#include <iostream>

Sponsor::Sponsor(const std::string &name, int age, Gender gender, const std::string &company) : Person(name, age,
                                                                                                       gender),
                                                                                                _company(company)
{
        _hiredStudents = 0;
}

Sponsor::Sponsor()
{
    {
        _name = "Jane Doe";
        _age = 30;
        _gender = Gender::FEMALE;
        _company = "Google";
        _hiredStudents = 0;
    }
}

void Sponsor::introduce()
{
    std::string sponsor;
    switch (Sponsor::getGender()) {
        case 0:
            sponsor = "male";
            break;
        case 1:
            sponsor = "female";
            break;
        default:
            sponsor = "unknown";
    }
    std::cout << "Hi, I'm " << _name << " a " << _age << " old " << sponsor << " who represents "
              << _company << " and hired " << _hiredStudents << " students so far. " << std::endl;
}



void Sponsor::hire()
{
    _hiredStudents++;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}