#include "Student.h"
#include <iostream>
Student::Student(const std::string &name, int age, Gender gender, const std::string &previousOrganization,
                 int numberOfSkippedDays) : Person(name, age, gender), _previousOrganization(previousOrganization),
                                            _skippedDays(0)
{}

Student::Student()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

int Student::skipDays(int numberOfSkippedDays)
{
    return _skippedDays += numberOfSkippedDays;
}

void Student::introduce(){
    std::cout << "Hi, I'm " << _name <<" a " << _age << " old " << Student::getGender() << " from "
    << _previousOrganization << " who skipped " << _skippedDays << " days from the yourse already" << std::endl;
}
