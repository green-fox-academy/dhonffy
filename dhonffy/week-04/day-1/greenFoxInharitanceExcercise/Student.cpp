#include "Student.h"

Student::Student(const std::string &name, int age, Gender gender, const std::string &previousOrganization,
                 int numberOfSkippedDays) : Person(name, age, gender), _previousOrganization(previousOrganization),
                                            _numberOfSkippedDays(0)
{}

Student::Student()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::female;
    _previousOrganization = "The School of Life";
    _numberOfSkippedDays = 0;
}
